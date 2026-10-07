#include "htop.h"
#include "CPUHistory.h"

/* Per-core CPU usage of the last minute as heatmap rows: time runs left to right, the right
   edge is the latest scan. Samples are taken in AllCPUsMeter_updateValues (once per scan). */

static char *const levelsUtf8[8] = {"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█"};
static const char levelsAscii[] = ".:-=+*#@";

#define HOT_PERCENT 70.0

CPUHistory *CPUHistory_new(uint cores)
{
  CPUHistory *this = calloc(1,sizeof(CPUHistory));
  if (this == (CPUHistory *)0x0) {
    fail();
  }
  this->cores = cores;
  this->rings = calloc(cores ? cores : 1,sizeof(CPUHistoryRing));
  if (this->rings == (CPUHistoryRing *)0x0) {
    fail();
  }
  return this;
}

void CPUHistory_delete(CPUHistory *this)
{
  if (this == (CPUHistory *)0x0) {
    return;
  }
  free(this->rings);
  free(this);
}

double CPUHistory_meterPercent(const Meter *core)
{
  double sum = 0.0;

  if ((strcmp(core->txtBuffer,"offline") == 0) || (strcmp(core->txtBuffer,"absent") == 0)) {
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

/* screen column (0..cols-1) of a time in the window, or -1 / cols when outside */
static int column(uint64_t t, uint64_t start, int cols)
{
  if (t < start) {
    return -1;
  }
  long c = (long)((t - start) * (uint64_t)cols / CPUHISTORY_SPAN_MS);
  return c < cols ? (int)c : cols;
}

void CPUHistory_drawRow(const CPUHistory *this, uint core, const Meter *meter, uint64_t nowMs,
                        int x, int y, int w)
{
  const CPUHistoryRing *ring;
  const CPUHistorySample *s;
  uint64_t start;
  uint64_t prevMs;
  int cols = w - 3;
  double cell[512];
  int from;
  int to;

  /* caption, 3 columns, as the bars had */
  wattrset(stdscr,CRT_colors[METER_TEXT]);
  if (wmove(stdscr,y,x) != -1) {
    waddnstr(stdscr,meter->caption ? meter->caption : "",3);
  }
  if ((this == (CPUHistory *)0x0) || (this->cores <= core) || (cols <= 0)) {
    wattrset(stdscr,CRT_colors[RESET_COLOR]);
    return;
  }
  if (cols > 512) {
    cols = 512;
  }
  ring = &this->rings[core];

  /* a sample covers the time since the previous one: mark those columns with the busiest value */
  for (int c = 0; c < cols; c++) {
    cell[c] = -2.0;  /* no data */
  }
  start = nowMs > CPUHISTORY_SPAN_MS ? nowMs - CPUHISTORY_SPAN_MS : 0;
  prevMs = 0;
  for (uint i = 0; i < ring->count; i++) {
    s = &ring->samples[(ring->head + i) % CPUHISTORY_CAPACITY];
    from = i == 0 ? column(s->ms,start,cols) : column(prevMs + 1,start,cols);
    to = column(s->ms,start,cols);
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
      if (s->pct > cell[c]) {
        cell[c] = s->pct;
      }
    }
  }

  /* latest sample offline: say so instead of drawing */
  if ((ring->count != 0) &&
      (ring->samples[(ring->head + ring->count - 1) % CPUHISTORY_CAPACITY].pct < 0.0)) {
    wattrset(stdscr,CRT_colors[METER_SHADOW]);
    if (wmove(stdscr,y,x + 3) != -1) {
      waddnstr(stdscr,(char *)meter->txtBuffer,cols);
    }
    wattrset(stdscr,CRT_colors[RESET_COLOR]);
    return;
  }

  for (int c = 0; c < cols; c++) {
    double v = cell[c];
    char ascii[2] = {' ', '\0'};
    char *glyph = ascii;
    int attr = CRT_colors[RESET_COLOR];
    if (v >= 0.0) {
      int level = (int)(v * 8.0 / 100.0);
      if (level > 7) {
        level = 7;
      }
      if (CRT_utf8) {
        glyph = levelsUtf8[level];
      }
      else {
        ascii[0] = levelsAscii[level];
      }
      if (v < 0.5) {
        attr = CRT_colors[METER_SHADOW];
      }
      else if (v < HOT_PERCENT) {
        attr = CRT_colors[CPU_NORMAL];
      }
      else {
        attr = CRT_colors[CPU_SYSTEM];
      }
    }
    wattrset(stdscr,attr);
    if (wmove(stdscr,y,x + 3 + c) != -1) {
      waddnstr(stdscr,glyph,-1);
    }
  }
  wattrset(stdscr,CRT_colors[RESET_COLOR]);
}
