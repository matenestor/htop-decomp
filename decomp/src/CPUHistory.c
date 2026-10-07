#include "htop.h"
#include "CPUHistory.h"

/* Per-core CPU usage of the last minute as one line graph: a coloured line per core, time runs
   left to right, the right edge is the latest scan. Samples are taken in
   AllCPUsMeter_updateValues (once per scan); drawn in braille dots (2x4 per cell) with UTF-8,
   one '*' per cell without. */

extern int COLOR_PAIRS;
int pair_content(short pair, short *f, short *b);

#define LABEL_W 5       /* "100% " */
#define MAX_COLS 512
#define MAX_CORES 256
#define PAIR_BASE 200   /* own colour pairs; htop uses the pairs below 64 */
#define ATTR_BOLD 0x200000
#define ATTR_PAIR(n) (((n) << 8) & 0xff00)

/* 256-colour palette: 16 hues that stay apart on dark and light backgrounds */
static const short palette256[16] = {196, 46, 33, 226, 201, 51, 208, 129, 118, 39, 160, 214, 99, 49, 205, 250};
/* 8 colours: red green yellow blue magenta cyan white, plain then bold */
static const short palette8[7] = {1, 2, 3, 4, 5, 6, 7};

static CPUHistory *shared;

CPUHistory *CPUHistory_acquire(uint cores)
{
  if (shared == (CPUHistory *)0x0) {
    shared = calloc(1,sizeof(CPUHistory));
    if (shared == (CPUHistory *)0x0) {
      fail();
    }
    shared->cores = cores ? cores : 1;
    shared->rings = calloc(shared->cores,sizeof(CPUHistoryRing));
    if (shared->rings == (CPUHistoryRing *)0x0) {
      fail();
    }
  }
  shared->users = shared->users + 1;
  return shared;
}

void CPUHistory_release(CPUHistory *this)
{
  if (this == (CPUHistory *)0x0) {
    return;
  }
  this->users = this->users - 1;
  if (this->users <= 0) {
    free(this->rings);
    free(this);
    if (shared == this) {
      shared = (CPUHistory *)0x0;
    }
  }
}

double CPUHistory_meterPercent(const Meter *core)
{
  double sum = 0.0;

  if ((strcmp((char *)core->txtBuffer,"offline") == 0) || (strcmp((char *)core->txtBuffer,"absent") == 0)) {
    return -1.0;
  }
  for (int i = 0; i < core->curItems; i++) {
    if (core->values[i] > 0.0) {
      sum = sum + core->values[i];
    }
  }
  return sum > 100.0 ? 100.0 : sum;
}

void CPUHistory_record(CPUHistory *this, uint core, uint64_t nowMs, double pct)
{
  CPUHistoryRing *ring;
  CPUHistorySample *last;

  if ((this == (CPUHistory *)0x0) || (this->cores <= core)) {
    return;
  }
  ring = &this->rings[core];
  if (ring->count != 0) {
    last = &ring->samples[(ring->head + ring->count - 1) % CPUHISTORY_CAPACITY];
    if (last->ms == nowMs) {  /* updated twice in one scan: keep the newer value */
      last->pct = pct;
      return;
    }
  }
  if (ring->count == CPUHISTORY_CAPACITY) {
    ring->head = (ring->head + 1) % CPUHISTORY_CAPACITY;
    ring->count = ring->count - 1;
  }
  ring->samples[(ring->head + ring->count) % CPUHISTORY_CAPACITY].ms = nowMs;
  ring->samples[(ring->head + ring->count) % CPUHISTORY_CAPACITY].pct = pct;
  ring->count = ring->count + 1;
}

/* curses attribute of core i's line */
static int coreAttr(uint i)
{
  static short pairsBg = -2;   /* background the own pairs were made for */
  short f;
  short b = -1;
  int pair;

  if ((CRT_colorScheme == COLORSCHEME_MONOCHROME) || !has_colors()) {
    return CRT_colors[RESET_COLOR];
  }
  if ((COLORS >= 256) && (COLOR_PAIRS >= PAIR_BASE + 16)) {
    pair = (CRT_colors[RESET_COLOR] & 0xff00) >> 8;
    if (pair != 0) {
      pair_content((short)pair,&f,&b);
    }
    if (b != pairsBg) {
      for (int k = 0; k < 16; k++) {
        init_pair((short)(PAIR_BASE + k),palette256[k],b);
      }
      pairsBg = b;
    }
    return ATTR_PAIR(PAIR_BASE + (int)(i % 16));
  }
  /* htop's own pairs: (7 - fg) * 8 + bg, background "black" stands for the terminal's */
  i = i % 14;
  return ATTR_PAIR((7 - palette8[i % 7]) * 8) | (i >= 7 ? ATTR_BOLD : 0);
}

/* the dot column (0..cols-1) a time falls in, -1 before the window, cols after it */
static int dotColumn(uint64_t t, uint64_t start, int cols)
{
  if (t < start) {
    return -1;
  }
  long c = (long)((t - start) * (uint64_t)cols / CPUHISTORY_SPAN_MS);
  return c < cols ? (int)c : cols;
}

/* usage per dot column for one core: a sample covers the time since the previous sample;
   -1 where there is no data or the core was offline */
static void coreValues(const CPUHistoryRing *ring, uint64_t start, int cols, double *v)
{
  uint64_t prevMs = 0;

  for (int c = 0; c < cols; c++) {
    v[c] = -1.0;
  }
  for (uint i = 0; i < ring->count; i++) {
    const CPUHistorySample *s = &ring->samples[(ring->head + i) % CPUHISTORY_CAPACITY];
    int from = i == 0 ? dotColumn(s->ms,start,cols) : dotColumn(prevMs + 1,start,cols);
    int to = dotColumn(s->ms,start,cols);
    prevMs = s->ms;
    if (to < 0) {
      continue;
    }
    if (from < 0) {
      from = 0;
    }
    if (to >= cols) {
      to = cols - 1;
    }
    for (int c = from; c <= to; c++) {
      if (s->pct > v[c]) {
        v[c] = s->pct;
      }
    }
  }
}

void CPUHistory_drawGraph(const CPUHistory *this, const Machine *host, int x, int y, int w)
{
  static const uchar brailleBit[4][2] = {{0x01, 0x08}, {0x02, 0x10}, {0x04, 0x20}, {0x40, 0x80}};
  static uchar bits[CPUHISTORY_PLOT_ROWS][MAX_COLS];
  static short owner[CPUHISTORY_PLOT_ROWS][MAX_COLS];      /* core drawn in that cell */
  static uchar ownerDots[CPUHISTORY_PLOT_ROWS][MAX_COLS];  /* how many of its dots are there */
  static uchar coreDots[CPUHISTORY_PLOT_ROWS][MAX_COLS];
  static double v[MAX_COLS * 2];
  int utf8 = CRT_utf8;
  int cols = w - LABEL_W;
  int dx = utf8 ? 2 : 1;          /* dots per cell */
  int dy = utf8 ? 4 : 1;
  int dotsW;
  int dotsH = CPUHISTORY_PLOT_ROWS * dy;
  uint64_t now = host->monotonicMs;
  uint64_t start = now > CPUHISTORY_SPAN_MS ? now - CPUHISTORY_SPAN_MS : 0;
  uint cores;

  /* y axis */
  wattrset(stdscr,CRT_colors[METER_TEXT]);
  for (int r = 0; r < CPUHISTORY_PLOT_ROWS; r++) {
    char *label = r == 0 ? "100% " : r == CPUHISTORY_PLOT_ROWS / 2 ? " 50% " :
                  r == CPUHISTORY_PLOT_ROWS - 1 ? "  0% " : "     ";
    if (wmove(stdscr,y + r,x) != -1) {
      waddnstr(stdscr,label,w < LABEL_W ? w : LABEL_W);
    }
  }
  if ((this == (CPUHistory *)0x0) || (cols <= 0)) {
    wattrset(stdscr,CRT_colors[RESET_COLOR]);
    return;
  }
  if (cols > MAX_COLS) {
    cols = MAX_COLS;
  }
  dotsW = cols * dx;
  cores = this->cores < MAX_CORES ? this->cores : MAX_CORES;

  for (int r = 0; r < CPUHISTORY_PLOT_ROWS; r++) {
    for (int c = 0; c < cols; c++) {
      bits[r][c] = 0;
      owner[r][c] = -1;
      ownerDots[r][c] = 0;
    }
  }

  /* each core: a line through its values, joined vertically between neighbouring columns */
  for (uint i = 0; i < cores; i++) {
    int prev = -1;
    coreValues(&this->rings[i],start,dotsW,v);
    for (int r = 0; r < CPUHISTORY_PLOT_ROWS; r++) {
      for (int c = 0; c < cols; c++) {
        coreDots[r][c] = 0;
      }
    }
    for (int px = 0; px < dotsW; px++) {
      if (v[px] < 0.0) {
        prev = -1;
        continue;
      }
      /* dot row counted from the top */
      int py = dotsH - 1 - (int)(v[px] * (dotsH - 1) / 100.0 + 0.5);
      int lo = prev < 0 ? py : (prev < py ? prev : py);
      int hi = prev < 0 ? py : (prev < py ? py : prev);
      for (int qy = lo; qy <= hi; qy++) {
        int r = qy / dy;
        int c = px / dx;
        bits[r][c] = bits[r][c] | (utf8 ? brailleBit[qy % 4][px % 2] : 1);
        coreDots[r][c] = coreDots[r][c] + 1;
      }
      prev = py;
    }
    /* a cell shows the colour of the core with most dots in it (later cores win ties) */
    for (int r = 0; r < CPUHISTORY_PLOT_ROWS; r++) {
      for (int c = 0; c < cols; c++) {
        if ((coreDots[r][c] != 0) && (coreDots[r][c] >= ownerDots[r][c])) {
          owner[r][c] = (short)i;
          ownerDots[r][c] = coreDots[r][c];
        }
      }
    }
  }

  for (int r = 0; r < CPUHISTORY_PLOT_ROWS; r++) {
    for (int c = 0; c < cols; c++) {
      char glyph[4] = {' ', '\0', '\0', '\0'};
      if (bits[r][c] != 0) {
        if (utf8) {  /* U+2800 + dot bits */
          glyph[0] = (char)0xe2;
          glyph[1] = (char)(0xa0 | (bits[r][c] >> 6));
          glyph[2] = (char)(0x80 | (bits[r][c] & 0x3f));
        }
        else {
          glyph[0] = '*';
        }
        wattrset(stdscr,coreAttr((uint)owner[r][c]));
      }
      else {
        wattrset(stdscr,CRT_colors[RESET_COLOR]);
      }
      if (wmove(stdscr,y + r,x + LABEL_W + c) != -1) {
        waddnstr(stdscr,glyph,-1);
      }
    }
  }

  /* legend: a coloured line mark and the core number */
  int lx = x + LABEL_W;
  int lend = x + w;
  int first = host->settings->countCPUsFromOne ? 1 : 0;
  for (uint i = 0; i < cores; i++) {
    char num[12];
    int len = xSnprintf(num,sizeof(num),"%u ",i + first);
    if (lx + 1 + len > lend) {
      break;
    }
    wattrset(stdscr,coreAttr(i));
    if (wmove(stdscr,y + CPUHISTORY_PLOT_ROWS,lx) != -1) {
      waddnstr(stdscr,utf8 ? "━" : "-",-1);
    }
    wattrset(stdscr,CRT_colors[METER_TEXT]);
    if (wmove(stdscr,y + CPUHISTORY_PLOT_ROWS,lx + 1) != -1) {
      waddnstr(stdscr,num,-1);
    }
    lx = lx + 1 + len;
  }
  wattrset(stdscr,CRT_colors[RESET_COLOR]);
}
