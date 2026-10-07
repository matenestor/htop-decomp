/* CRT_init @ 00116630 size 1445 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_init(Settings *settings,_Bool allowUnicode,_Bool retainScreenOnExit)

{
  long lVar1;
  wchar_t wVar2;
  int iVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  int iVar7;
  long in_FS_OFFSET;
  _Bool local_d9;
  char sequence [3];
  sigset_t local_d0;
  int local_50;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  initscr();
  if (retainScreenOnExit) {
    CRT_retainScreenOnExit = true;
    wrefresh(_stdscr);
    tputs(*(char **)(*(long *)(_cur_term + 0x20) + 0x140),0,putchar);
    tputs(*(char **)(*(long *)(_cur_term + 0x20) + 0x28),0,putchar);
    fflush(_stdout);
    lVar1 = *(long *)(_cur_term + 0x20);
    *(undefined8 *)(lVar1 + 0xe0) = 0;
    *(undefined8 *)(lVar1 + 0x140) = 0;
  }
  noecho();
  CRT_colorScheme = settings->colorScheme;
  CRT_delay = &settings->delay;
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: uint color@[???] */
  CRT_colors = CRT_colorSchemes[(int)CRT_colorScheme];
  pwVar4 = CRT_colorSchemes[0];
  CRT_crashSettings = settings;
  do {
    wVar2 = *pwVar4;
    if (*pwVar4 == L'\x00201500') {
      wVar2 = L'\0';
    }
    pwVar5 = pwVar4 + 1;
    (*(wchar_t (*) [111])(pwVar4 + 0x29a))[0] = wVar2;
    pwVar4 = pwVar5;
  } while ((wchar_t (*) [111])pwVar5 != CRT_colorSchemes + 1);
  halfdelay(settings->delay);
  nonl();
  intrflush(_stdscr,0);
  keypad(_stdscr,1);
  mouseinterval(0);
  curs_set(0);
  iVar3 = has_colors();
  if ((char)iVar3 != '\0') {
    start_color();
  }
  pcVar6 = getenv(((char *)0x14961f /* "TERM" */));
  if (pcVar6 == (char *)0x0) {
    CRT_scrollHAmount = L'\x05';
  }
  else {
    iVar3 = strcmp(pcVar6,((char *)0x149b47 /* "linux" */));
    CRT_scrollHAmount = (-(uint)(iVar3 == 0) & 0xf) + L'\x05';
    iVar3 = strncmp(pcVar6,((char *)0x14717a /* "xterm" */),5);
    if ((iVar3 == 0) || (iVar3 = strcmp(pcVar6,((char *)0x147180 /* "vt220" */)), iVar3 == 0)) {
      define_key(((char *)0x147186 /* "\x1b[H" */),0x106);
      define_key(((char *)0x14718a /* "\x1b[F" */),0x168);
      define_key(((char *)0x14718e /* "\x1b[7~" */),0x106);
      define_key(((char *)0x147193 /* "\x1b[8~" */),0x168);
      define_key(((char *)0x147198 /* "\x1bOP" */),0x109);
      define_key(((char *)0x14719c /* "\x1bOQ" */),0x10a);
      define_key(((char *)0x1471a0 /* "\x1bOR" */),0x10b);
      define_key(((char *)0x1471a4 /* "\x1bOS" */),0x10c);
      define_key(((char *)0x1471a8 /* "\x1bO2R" */),0x117);
      define_key(((char *)0x1471ad /* "\x1b[11~" */),0x109);
      define_key(((char *)0x1471b3 /* "\x1b[12~" */),0x10a);
      define_key(((char *)0x1471b9 /* "\x1b[13~" */),0x10b);
      define_key(((char *)0x1471bf /* "\x1b[14~" */),0x10c);
      define_key(((char *)0x1471c5 /* "\x1b[14;2~" */),0x117);
      define_key(((char *)0x1471cd /* "\x1b[17;2~" */),0x11a);
      define_key(((char *)0x1471d5 /* "\x1b[Z" */),0x129);
      stack0xffffffffffffff2a = SUB86(_sequence,2) & 0xffffffffff00;
      sequence[0] = '\x1b';
      sequence[1] = 'a';
                    /* Unresolved local var: char c@[???] */
      iVar3 = 0x12e;
      do {
        iVar7 = iVar3 + 1;
        sequence[1] = (char)iVar3 + '3';
        define_key(sequence,iVar3);
        iVar3 = iVar7;
      } while (iVar7 != 0x148);
    }
    iVar3 = strncmp(pcVar6,((char *)0x1471d9 /* "rxvt" */),4);
    if (iVar3 == 0) {
      define_key(((char *)0x1471d5 /* "\x1b[Z" */),0x129);
    }
  }
  sigemptyset(&local_d0);
  local_50 = -0x40000000;
  _sequence = CRT_handleSIGSEGV;
  sigaction(0xb,(sigaction_2 *)sequence,(sigaction_2 *)(old_sig_handler + 0xb));
  sigaction(8,(sigaction_2 *)sequence,(sigaction_2 *)(old_sig_handler + 8));
  sigaction(4,(sigaction_2 *)sequence,(sigaction_2 *)(old_sig_handler + 4));
  sigaction(7,(sigaction_2 *)sequence,(sigaction_2 *)(old_sig_handler + 7));
  sigaction(0xd,(sigaction_2 *)sequence,(sigaction_2 *)(old_sig_handler + 0xd));
  sigaction(0x1f,(sigaction_2 *)sequence,(sigaction_2 *)(old_sig_handler + 0x1f));
  sigaction(6,(sigaction_2 *)sequence,(sigaction_2 *)(old_sig_handler + 6));
  signal(0x11,(__sighandler_t_2)0x0);
  signal(2,CRT_handleSIGTERM);
  signal(0xf,CRT_handleSIGTERM);
  signal(3,CRT_handleSIGTERM);
  use_default_colors();
  iVar3 = has_colors();
  if ((char)iVar3 == '\0') {
    CRT_colorScheme = COLORSCHEME_MONOCHROME;
  }
  CRT_setColors(CRT_colorScheme);
  if (allowUnicode) {
    pcVar6 = nl_langinfo(0xe);
    iVar3 = strcmp(pcVar6,((char *)0x1471de /* "UTF-8" */));
    if (iVar3 == 0) {
      CRT_treeStr = CRT_treeStrUtf8;
      local_d9 = true;
      goto LAB_00116a2c;
    }
  }
  local_d9 = false;
  CRT_treeStr = CRT_treeStrAscii;
LAB_00116a2c:
  CRT_utf8 = local_d9;
  if (settings->enableMouse == false) {
    mousemask(0,(ulong *)0x0);
  }
  else {
    mousemask(0x210001,(ulong *)0x0);
  }
                    /* Unresolved local var: wchar_t r@[???] */
  pcVar6 = &DAT_00147177;
  if (CRT_utf8 == false) {
    iVar3 = __snprintf_chk((char *)&buffer_0,4,2,4,((char *)0x1471e4 /* "%lc" */),0xb0);
    pcVar6 = ((char *)0x149c0c /* "" */);
    if (0 < iVar3) {
      pcVar6 = (char *)&buffer_0;
    }
  }
  CRT_degreeSign = pcVar6;
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

