#include "htop.h"

/* print_backtrace @ 0x1158a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void print_backtrace(void)

{
  undefined1 __frame[0x8b8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x878;
  long lVar1;
  int p1;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: size_t size@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  p1 = backtrace((*(void *(*) [256])(__fp - 0x828)),0x100);
  backtrace_symbols_fd((*(void *(*) [256])(__fp - 0x828)),p1,2);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* CRT_setMouse @ 0x115c00 */

void CRT_setMouse(_Bool enabled)

{
  if (enabled) {
    mousemask(0x210001,(ulong *)0x0);
    return;
  }
  mousemask(0,(ulong *)0x0);
  return;
}


/* CRT_enableDelay @ 0x115c20 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRT_enableDelay(void)

{
  halfdelay(*CRT_delay);
  return;
}


/* CRT_readKey @ 0x115c40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRT_readKey(void)

{
  int wVar1;

  nocbreak();
  cbreak();
  nodelay(_stdscr,0);
  wVar1 = wgetch(_stdscr);
  halfdelay(*CRT_delay);
  return wVar1;
}


/* CRT_resetSignalHandlers @ 0x1161c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRT_resetSignalHandlers(void)

{
  sigaction(0xb,(sigaction_2 *)(old_sig_handler + 0xb),(sigaction_2 *)0x0);
  sigaction(8,(sigaction_2 *)(old_sig_handler + 8),(sigaction_2 *)0x0);
  sigaction(4,(sigaction_2 *)(old_sig_handler + 4),(sigaction_2 *)0x0);
  sigaction(7,(sigaction_2 *)(old_sig_handler + 7),(sigaction_2 *)0x0);
  sigaction(0xd,(sigaction_2 *)(old_sig_handler + 0xd),(sigaction_2 *)0x0);
  sigaction(0x1f,(sigaction_2 *)(old_sig_handler + 0x1f),(sigaction_2 *)0x0);
  sigaction(6,(sigaction_2 *)(old_sig_handler + 6),(sigaction_2 *)0x0);
  signal(2,(__sighandler_t_2)0x0);
  signal(0xf,(__sighandler_t_2)0x0);
  signal(3,(__sighandler_t_2)0x0);
  return;
}


/* CRT_done @ 0x116280 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRT_done(void)

{
  int iVar1;
  int p1;

  p1 = CRT_colorSchemes[0][0];
  if (CRT_colors != (int *)0x0) {
    p1 = *CRT_colors;
  }
  wattr_on(_stdscr,p1,(void *)0x0);
  iVar1 = wmove(_stdscr,_LINES + -1,0);
  if (iVar1 != -1) {
    whline(_stdscr,0x20,_COLS);
  }
  wattr_off(_stdscr,p1,(void *)0x0);
  wrefresh(_stdscr);
  if (CRT_retainScreenOnExit != false) {
    mvcur(-1,-1,_LINES + -1,0);
  }
  curs_set(1);
  endwin();
  return;
}


/* CRT_handleSIGTERM @ 0x116360 */

void CRT_handleSIGTERM(int sgn)

{
  CRT_done();
                    /* WARNING: Subroutine does not return */
  _exit(0);
}


/* CRT_fatalError @ 0x116380 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_fatalError(char *note)

{
  int *piVar1;
  char *va1;

  piVar1 = __errno_location();
  va1 = strerror(*piVar1);
  CRT_done();
  __fprintf_chk(_stderr,2,((char *)(long)&s__s___s_0014716f /* "%s: %s\n" */),note,va1);
                    /* WARNING: Subroutine does not return */
  exit(2);
}


/* CRT_disableDelay @ 0x1163d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRT_disableDelay(void)

{
  nocbreak();
  cbreak();
  nodelay(_stdscr,1);
  return;
}


/* CRT_setColors @ 0x116400 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_setColors(int colorScheme)

{
  uint uVar1;
  ulong uVar2;
  short p2;
  int iVar3;
  int iVar4;

  iVar4 = 0;
                    /* Unresolved local var: short i@[???]
                       Unresolved local var: short j@[???] */
  CRT_colorScheme = colorScheme;
  do {
    iVar3 = 0;
    uVar2 = (ulong)(iVar4 * -8 + 0x38);
LAB_00116440:
    do {
      uVar1 = (uint)uVar2;
      while ((0x2000000200000U >> (uVar2 & 0x3f) & 1) == 0) {
                    /* Unresolved local var: short bg@[???] */
        p2 = (short)iVar3;
        if ((colorScheme == 5) || (p2 != 0)) {
          iVar3 = iVar3 + 1;
          init_pair((short)uVar2,(short)iVar4,p2);
          uVar2 = (ulong)((int)uVar2 + 1);
          if (iVar3 == 8) goto LAB_00116486;
          goto LAB_00116440;
        }
        uVar1 = (int)uVar2 + 1;
        init_pair((short)uVar2,(short)iVar4,-1);
        iVar3 = 1;
        uVar2 = (ulong)uVar1;
      }
      iVar3 = iVar3 + 1;
      uVar2 = (ulong)(uVar1 + 1);
    } while (iVar3 != 8);
LAB_00116486:
    iVar4 = iVar4 + 1;
    if (iVar4 == 8) {
      init_pair(0x15,(ushort)(8 < _COLORS) * 8,-(ushort)(colorScheme != 5));
      init_pair(0x31,7,-1);
      CRT_colors = CRT_colorSchemes[colorScheme];
      return;
    }
  } while( true );
}


/* CRT_init @ 0x116630 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_init(Settings *settings,_Bool allowUnicode,_Bool retainScreenOnExit)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  long lVar1;
  int wVar2;
  int iVar3;
  int *pwVar4;
  int *pwVar5;
  char *pcVar6;
  int iVar7;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
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
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: uint color@[???] */
  CRT_colors = CRT_colorSchemes[(int)CRT_colorScheme];
  pwVar4 = CRT_colorSchemes[0];
  CRT_crashSettings = settings;
  do {
    wVar2 = *pwVar4;
    if (*pwVar4 == 2102528) {
      wVar2 = 0;
    }
    pwVar5 = pwVar4 + 1;
    (*(int (*) [111])(pwVar4 + 0x29a))[0] = wVar2;
    pwVar4 = pwVar5;
  } while ((int (*) [111])pwVar5 != CRT_colorSchemes + 1);
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
  pcVar6 = getenv(((char *)(long)(__sec_rodata + 0x261f) /* "TERM" */));
  if (pcVar6 == (char *)0x0) {
    CRT_scrollHAmount = 5;
  }
  else {
    iVar3 = strcmp(pcVar6,((char *)(long)(__sec_rodata + 0x2b47) /* "linux" */));
    CRT_scrollHAmount = (-(uint)(iVar3 == 0) & 0xf) + 5;
    iVar3 = strncmp(pcVar6,((char *)(long)&s_xterm_0014717a /* "xterm" */),5);
    if ((iVar3 == 0) || (iVar3 = strcmp(pcVar6,((char *)(long)&s_vt220_00147180 /* "vt220" */)), iVar3 == 0)) {
      define_key(((char *)(long)&DAT_00147186 /* "\x1b[H" */),0x106);
      define_key(((char *)(long)&DAT_0014718a /* "\x1b[F" */),0x168);
      define_key(((char *)(long)&DAT_0014718e /* "\x1b[7~" */),0x106);
      define_key(((char *)(long)&DAT_00147193 /* "\x1b[8~" */),0x168);
      define_key(((char *)(long)&DAT_00147198 /* "\x1bOP" */),0x109);
      define_key(((char *)(long)&DAT_0014719c /* "\x1bOQ" */),0x10a);
      define_key(((char *)(long)&DAT_001471a0 /* "\x1bOR" */),0x10b);
      define_key(((char *)(long)&DAT_001471a4 /* "\x1bOS" */),0x10c);
      define_key(((char *)(long)&DAT_001471a8 /* "\x1bO2R" */),0x117);
      define_key(((char *)(long)&DAT_001471ad /* "\x1b[11~" */),0x109);
      define_key(((char *)(long)&DAT_001471b3 /* "\x1b[12~" */),0x10a);
      define_key(((char *)(long)&DAT_001471b9 /* "\x1b[13~" */),0x10b);
      define_key(((char *)(long)&DAT_001471bf /* "\x1b[14~" */),0x10c);
      define_key(((char *)(long)&DAT_001471c5 /* "\x1b[14;2~" */),0x117);
      define_key(((char *)(long)&DAT_001471cd /* "\x1b[17;2~" */),0x11a);
      define_key(((char *)(long)&DAT_001471d5 /* "\x1b[Z" */),0x129);
      { ulong __v = SUB86((*(undefined8 (*))(__fp - 0xd8)),2) & 0xffffffffff00; __builtin_memcpy(__fp - 0xd6, &__v, 6); }
      (*(char (*) [3])(__fp - 0xd8))[0] = '\x1b';
      (*(char (*) [3])(__fp - 0xd8))[1] = 'a';
                    /* Unresolved local var: char c@[???] */
      iVar3 = 0x12e;
      do {
        iVar7 = iVar3 + 1;
        (*(char (*) [3])(__fp - 0xd8))[1] = (char)iVar3 + '3';
        define_key((*(char (*) [3])(__fp - 0xd8)),iVar3);
        iVar3 = iVar7;
      } while (iVar7 != 0x148);
    }
    iVar3 = strncmp(pcVar6,((char *)(long)&DAT_001471d9 /* "rxvt" */),4);
    if (iVar3 == 0) {
      define_key(((char *)(long)&DAT_001471d5 /* "\x1b[Z" */),0x129);
    }
  }
  sigemptyset(&(*(sigset_t (*))(__fp - 0xd0)));
  (*(int (*))(__fp - 0x50)) = -0x40000000;
  (*(undefined8 (*))(__fp - 0xd8)) = CRT_handleSIGSEGV;
  sigaction(0xb,(sigaction_2 *)(*(char (*) [3])(__fp - 0xd8)),(sigaction_2 *)(old_sig_handler + 0xb));
  sigaction(8,(sigaction_2 *)(*(char (*) [3])(__fp - 0xd8)),(sigaction_2 *)(old_sig_handler + 8));
  sigaction(4,(sigaction_2 *)(*(char (*) [3])(__fp - 0xd8)),(sigaction_2 *)(old_sig_handler + 4));
  sigaction(7,(sigaction_2 *)(*(char (*) [3])(__fp - 0xd8)),(sigaction_2 *)(old_sig_handler + 7));
  sigaction(0xd,(sigaction_2 *)(*(char (*) [3])(__fp - 0xd8)),(sigaction_2 *)(old_sig_handler + 0xd));
  sigaction(0x1f,(sigaction_2 *)(*(char (*) [3])(__fp - 0xd8)),(sigaction_2 *)(old_sig_handler + 0x1f));
  sigaction(6,(sigaction_2 *)(*(char (*) [3])(__fp - 0xd8)),(sigaction_2 *)(old_sig_handler + 6));
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
    iVar3 = strcmp(pcVar6,((char *)(long)&s_UTF_8_001471de /* "UTF-8" */));
    if (iVar3 == 0) {
      CRT_treeStr = CRT_treeStrUtf8;
      (*(_Bool (*))(__fp - 0xd9)) = true;
      goto LAB_00116a2c;
    }
  }
  (*(_Bool (*))(__fp - 0xd9)) = false;
  CRT_treeStr = CRT_treeStrAscii;
LAB_00116a2c:
  CRT_utf8 = (*(_Bool (*))(__fp - 0xd9));
  if (settings->enableMouse == false) {
    mousemask(0,(ulong *)0x0);
  }
  else {
    mousemask(0x210001,(ulong *)0x0);
  }
                    /* Unresolved local var: int r@[???] */
  pcVar6 = &DAT_00147177;
  if (CRT_utf8 == false) {
    iVar3 = __snprintf_chk((char *)&buffer_0,4,2,4,((char *)(long)&DAT_001471e4 /* "%lc" */),0xb0);
    pcVar6 = ((char *)(long)&DAT_00149c0c /* "" */);
    if (0 < iVar3) {
      pcVar6 = (char *)&buffer_0;
    }
  }
  CRT_degreeSign = pcVar6;
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* CRT_handleSIGSEGV @ 0x11d160 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_handleSIGSEGV(int signal)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;

  CRT_done();
  __fprintf_chk(_stderr,2,
                ((char *)(long)&s_FATAL_PROGRAM_ERROR_DETECTED_____0014a750 /* "\n\nFATAL PROGRAM ERROR DETECTED\n============================\nPlease check at https://htop.dev/issues whether this issue has already been reported.\nIf no similar issue has been reported before, please create a new issue with the following information:\n  - Your %s version: \'3.3.0\'\n  - Your OS and kernel version (uname -a)\n  - Your distribution and release (lsb_release -a)\n  - Likely steps to reproduce (How did it happen?)\n" */)
                ,program);
  __fprintf_chk(_stderr,2,((char *)(long)&s___Backtrace_of_the_issue__see_be_0014a8f8 /* "  - Backtrace of the issue (see below)\n" */));
  __fprintf_chk(_stderr,2,((char *)(long)&DAT_00147506 /* "\n" */));
  pcVar2 = strsignal(signal);
  pcVar3 = ((char *)(long)&s_unknown_reason_001474f6 /* "unknown reason" */);
  if (pcVar2 != (char *)0x0) {
    pcVar3 = pcVar2;
  }
  __fprintf_chk(_stderr,2,
                ((char *)(long)&s_Error_information________________0014a920 /* "Error information:\n------------------\nA signal %d (%s) was received.\n\n" */),signal,
                pcVar3);
  __fprintf_chk(_stderr,2,((char *)(long)&s_Setting_information______________0014a968 /* "Setting information:\n--------------------\n" */));
  Settings_write(CRT_crashSettings,true);
  __fprintf_chk(_stderr,2,((char *)(long)&DAT_00147505 /* "\n\n" */));
  __fprintf_chk(_stderr,2,((char *)(long)&s_Backtrace_information____________0014a998 /* "Backtrace information:\n----------------------\n" */));
  print_backtrace();
  __fprintf_chk(_stderr,2,
                ((char *)(long)&s_To_make_the_above_information_mo_0014a9c8 /* "\nTo make the above information more practical to work with, please also provide a disassembly of your %s binary. This can usually be done by running the following command:\n\n" */)
                ,program);
  __fprintf_chk(_stderr,2,((char *)(long)&s_objdump__d__S__w__which__s_______0014aa78 /* "   objdump -d -S -w `which %s` > ~/%s.objdump\n" */),program,program);
  __fprintf_chk(_stderr,2,((char *)(long)&s_Please_include_the_generated_fil_0014aaa8 /* "\nPlease include the generated file in your report.\n" */));
  __fprintf_chk(_stderr,2,
                ((char *)(long)&s_Running_this_program_with_debug_s_0014aae0 /* "Running this program with debug symbols or inside a debugger may provide further insights.\n\nThank you for helping to improve %s!\n\n" */)
                ,program);
  iVar1 = sigaction(signal,(sigaction_2 *)(old_sig_handler + signal),(sigaction_2 *)0x0);
  pcVar3 = ((char *)(long)&s_____Chained_handler_could_not_be_0014ab68 /* "!!! Chained handler could not be restored. Forcing exit.\n" */);
  if (-1 < iVar1) {
    raise(signal);
    pcVar3 = ((char *)(long)&s_____Chained_handler_did_not_exit_0014aba8 /* "!!! Chained handler did not exit. Forcing exit.\n" */);
  }
  __fprintf_chk(_stderr,2,pcVar3);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}

