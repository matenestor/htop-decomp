#include "htop.h"

/* CRT_setMouse @ 0x115c00 */

void CRT_setMouse(char param_1)

{
  if (param_1 != '\0') {
    mousemask(0x210001,(ulong *)0x0);
    return;
  }
  mousemask(0,(ulong *)0x0);
  return;
}


/* CRT_enableDelay @ 0x115c20 */

void CRT_enableDelay(void)

{
  halfdelay(*PTR_0015c0d0);
  return;
}


/* CRT_readKey @ 0x115c40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CRT_readKey(void)

{
  int iVar1;

  nocbreak();
  cbreak();
  nodelay(_stdscr,0);
  iVar1 = wgetch(_stdscr);
  halfdelay(*PTR_0015c0d0);
  return iVar1;
}


/* CRT_resetSignalHandlers @ 0x1161c0 */

void CRT_resetSignalHandlers(void)

{
  sigaction(0xb,(struct sigaction *)&DAT_0015c7c8,(struct sigaction *)0x0);
  sigaction(8,(struct sigaction *)&DAT_0015c600,(struct sigaction *)0x0);
  sigaction(4,(struct sigaction *)&DAT_0015c3a0,(struct sigaction *)0x0);
  sigaction(7,(struct sigaction *)&DAT_0015c568,(struct sigaction *)0x0);
  sigaction(0xd,(struct sigaction *)&DAT_0015c8f8,(struct sigaction *)0x0);
  sigaction(0x1f,(struct sigaction *)&DAT_0015d3a8,(struct sigaction *)0x0);
  sigaction(6,(struct sigaction *)&DAT_0015c4d0,(struct sigaction *)0x0);
  signal(2,(__sighandler_t)0x0);
  signal(0xf,(__sighandler_t)0x0);
  signal(3,(__sighandler_t)0x0);
  return;
}


/* CRT_done @ 0x116280 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_done(void)

{
  int iVar1;
  uint p1;

  p1 = UINT_0015b260;
  if (CRT_colors != 0) {
    p1 = *(uint *)CRT_colors;
  }
  wattr_on(_stdscr,p1,(void *)0x0);
  iVar1 = wmove(_stdscr,_LINES + -1,0);
  if (iVar1 != -1) {
    whline(_stdscr,0x20,_COLS);
  }
  wattr_off(_stdscr,p1,(void *)0x0);
  wrefresh(_stdscr);
  if (CHAR____0015c138 != '\0') {
    mvcur(-1,-1,_LINES + -1,0);
  }
  curs_set(1);
  endwin();
  return;
}


/* FUN_00116360 @ 0x116360 */

void FUN_00116360(void)

{
  CRT_done();
                    /* WARNING: Subroutine does not return */
  _exit(0);
}


/* CRT_fatalError @ 0x116380 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_fatalError(void *param_1)

{
  int *piVar1;
  char *va1;

  piVar1 = __errno_location();
  va1 = strerror(*piVar1);
  CRT_done();
  __fprintf_chk(_stderr,2,((char *)(long)&s__s___s_0014716f /* "%s: %s\n" */),param_1,va1);
                    /* WARNING: Subroutine does not return */
  exit(2);
}


/* CRT_disableDelay @ 0x1163d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_disableDelay(void)

{
  nocbreak();
  cbreak();
  nodelay(_stdscr,1);
  return;
}


/* CRT_setColors @ 0x116400 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_setColors(int param_1)

{
  uint uVar1;
  ulong uVar2;
  short p2;
  int iVar3;
  int iVar4;

  iVar4 = 0;
  CRT_colorScheme = param_1;
  do {
    iVar3 = 0;
    uVar2 = (ulong)(iVar4 * -8 + 0x38);
LAB_00116440:
    do {
      uVar1 = (uint)uVar2;
      while ((0x2000000200000U >> (uVar2 & 0x3f) & 1) == 0) {
        p2 = (short)iVar3;
        if ((param_1 == 5) || (p2 != 0)) {
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
      init_pair(0x15,(ushort)(8 < _COLORS) * 8,-(ushort)(param_1 != 5));
      init_pair(0x31,7,-1);
      CRT_colors = (long)(&UINT_0015b260 + (long)param_1 * 0x6f);
      return;
    }
  } while( true );
}


/* FUN_00116530 @ 0x116530 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00116530(long param_1,ulong param_2)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  undefined1 *puVar4;
  long lVar5;
  int iVar6;

  iVar6 = (int)param_2;
  if (iVar6 != 0x128) {
    if (iVar6 < 0x129) {
      if (0x16 < iVar6 - 10U) {
        return 2;
      }
      if ((0x100002400U >> (param_2 & 0x3f) & 1) == 0) {
        return 2;
      }
    }
    else if ((iVar6 != 0x157) && (iVar6 != 0x199)) {
      return 2;
    }
  }
  iVar6 = *(int *)(param_1 + 0x28);
  lVar2 = **(long **)(param_1 + 0x20);
  lVar5 = 0;
  do {
    while( true ) {
      lVar3 = *(long *)(lVar2 + lVar5);
      puVar4 = *(undefined1 **)(lVar3 + 0x10);
      if (puVar4 != (undefined1 *)0x0) break;
      *(undefined1 *)(lVar3 + 0x18) = 0;
      plVar1 = (long *)((long)&PTR_s_Monochromatic_00155ea8 + lVar5);
      lVar5 = lVar5 + 8;
      if (*plVar1 == 0) goto LAB_001165b2;
    }
    *puVar4 = 0;
    plVar1 = (long *)((long)&PTR_s_Monochromatic_00155ea8 + lVar5);
    lVar5 = lVar5 + 8;
  } while (*plVar1 != 0);
LAB_001165b2:
  lVar2 = *(long *)(lVar2 + (long)iVar6 * 8);
  puVar4 = *(undefined1 **)(lVar2 + 0x10);
  if (puVar4 == (undefined1 *)0x0) {
    *(undefined1 *)(lVar2 + 0x18) = 1;
  }
  else {
    *puVar4 = 1;
  }
  lVar2 = *(long *)(param_1 + 0x26e0);
  *(long *)(lVar2 + 0x78) = *(long *)(lVar2 + 0x78) + 1;
  *(int *)(lVar2 + 0x48) = iVar6;
  *(undefined1 *)(lVar2 + 0x74) = 1;
  CRT_setColors(iVar6);
  wclear(_stdscr);
  return 0x11;
}


/* CRT_init @ 0x116630 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_init(long param_1,char param_2,char param_3)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  long lVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  char *pcVar6;
  undefined *puVar7;
  undefined **ppuVar8;
  int iVar9;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  initscr();
  if (param_3 != '\0') {
    CHAR____0015c138 = '\x01';
    wrefresh(_stdscr);
    tputs(*(char **)(*(long *)(_cur_term + 0x20) + 0x140),0,putchar);
    tputs(*(char **)(*(long *)(_cur_term + 0x20) + 0x28),0,putchar);
    fflush(_stdout);
    lVar1 = *(long *)(_cur_term + 0x20);
    *(undefined8 *)(lVar1 + 0xe0) = 0;
    *(undefined8 *)(lVar1 + 0x140) = 0;
  }
  noecho();
  CRT_colorScheme = *(int *)(param_1 + 0x48);
  PTR_0015c0d0 = (int *)(param_1 + 0x4c);
  CRT_colors = (long)(&UINT_0015b260 + (long)CRT_colorScheme * 0x6f);
  puVar4 = &UINT_0015b260;
  LONG_0015c130 = param_1;
  do {
    uVar2 = *puVar4;
    if (*puVar4 == 0x201500) {
      uVar2 = 0;
    }
    puVar5 = puVar4 + 1;
    puVar4[0x29a] = uVar2;
    puVar4 = puVar5;
  } while (puVar5 != (uint *)&DAT_0015b41c);
  halfdelay(*(int *)(param_1 + 0x4c));
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
      (*(ulong *)((char *)&(*(struct sigaction *)(__fp - 0xd8)).__sigaction_handler + 2)) = (*(ulong *)((char *)&(*(struct sigaction *)(__fp - 0xd8)).__sigaction_handler + 2)) & 0xffffffffff00;
      (*(ushort *)((char *)&(*(struct sigaction *)(__fp - 0xd8)).__sigaction_handler + 0)) = 0x611b;
      iVar3 = 0x12e;
      do {
        iVar9 = iVar3 + 1;
        (*(uchar *)((char *)&(*(struct sigaction *)(__fp - 0xd8)).__sigaction_handler + 1)) = (char)iVar3 + '3';
        define_key((char *)&(*(struct sigaction *)(__fp - 0xd8)),iVar3);
        iVar3 = iVar9;
      } while (iVar9 != 0x148);
    }
    iVar3 = strncmp(pcVar6,((char *)(long)&DAT_001471d9 /* "rxvt" */),4);
    if (iVar3 == 0) {
      define_key(((char *)(long)&DAT_001471d5 /* "\x1b[Z" */),0x129);
    }
  }
  sigemptyset(&(*(struct sigaction *)(__fp - 0xd8)).sa_mask);
  (*(struct sigaction *)(__fp - 0xd8)).sa_flags = -0x40000000;
  (*(struct sigaction *)(__fp - 0xd8)).__sigaction_handler.sa_handler = CRT_handleSIGSEGV;
  sigaction(0xb,&(*(struct sigaction *)(__fp - 0xd8)),(struct sigaction *)&DAT_0015c7c8);
  sigaction(8,&(*(struct sigaction *)(__fp - 0xd8)),(struct sigaction *)&DAT_0015c600);
  sigaction(4,&(*(struct sigaction *)(__fp - 0xd8)),(struct sigaction *)&DAT_0015c3a0);
  sigaction(7,&(*(struct sigaction *)(__fp - 0xd8)),(struct sigaction *)&DAT_0015c568);
  sigaction(0xd,&(*(struct sigaction *)(__fp - 0xd8)),(struct sigaction *)&DAT_0015c8f8);
  sigaction(0x1f,&(*(struct sigaction *)(__fp - 0xd8)),(struct sigaction *)&DAT_0015d3a8);
  sigaction(6,&(*(struct sigaction *)(__fp - 0xd8)),(struct sigaction *)&DAT_0015c4d0);
  signal(0x11,(__sighandler_t)0x0);
  signal(2,FUN_00116360);
  signal(0xf,FUN_00116360);
  signal(3,FUN_00116360);
  use_default_colors();
  iVar3 = has_colors();
  if ((char)iVar3 == '\0') {
    CRT_colorScheme = 1;
  }
  CRT_setColors(CRT_colorScheme);
  if (param_2 != '\0') {
    pcVar6 = nl_langinfo(0xe);
    iVar3 = strcmp(pcVar6,((char *)(long)&s_UTF_8_001471de /* "UTF-8" */));
    if (iVar3 == 0) {
      ppuVar8 = &PTR_DAT_00155d60;
      (*(char *)(__fp - 0xd9)) = param_2;
      goto LAB_00116a2c;
    }
  }
  (*(char *)(__fp - 0xd9)) = '\0';
  ppuVar8 = &PTR_DAT_00155d20;
LAB_00116a2c:
  CRT_utf8 = (*(char *)(__fp - 0xd9));
  CRT_treeStr = (undefined *)ppuVar8;
  if (*(char *)(param_1 + 0x6f) == '\0') {
    mousemask(0,(ulong *)0x0);
  }
  else {
    mousemask(0x210001,(ulong *)0x0);
  }
  puVar7 = &DAT_00147177;
  if (CRT_utf8 == '\0') {
    iVar3 = __snprintf_chk(&DAT_0015c128,4,2,4,((char *)(long)&DAT_001471e4 /* "%lc" */),0xb0);
    puVar7 = &DAT_00149c0c;
    if (0 < iVar3) {
      puVar7 = &DAT_0015c128;
    }
  }
  CRT_degreeSign = puVar7;
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* CRT_handleSIGSEGV @ 0x11d160 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_handleSIGSEGV(int param_1)

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
  pcVar2 = strsignal(param_1);
  pcVar3 = ((char *)(long)&s_unknown_reason_001474f6 /* "unknown reason" */);
  if (pcVar2 != (char *)0x0) {
    pcVar3 = pcVar2;
  }
  __fprintf_chk(_stderr,2,
                ((char *)(long)&s_Error_information________________0014a920 /* "Error information:\n------------------\nA signal %d (%s) was received.\n\n" */),param_1
                ,pcVar3);
  __fprintf_chk(_stderr,2,((char *)(long)&s_Setting_information______________0014a968 /* "Setting information:\n--------------------\n" */));
  Settings_write((undefined8 *)LONG_0015c130,'\x01');
  __fprintf_chk(_stderr,2,((char *)(long)&DAT_00147505 /* "\n\n" */));
  __fprintf_chk(_stderr,2,((char *)(long)&s_Backtrace_information____________0014a998 /* "Backtrace information:\n----------------------\n" */));
  FUN_001158a0();
  __fprintf_chk(_stderr,2,
                ((char *)(long)&s_To_make_the_above_information_mo_0014a9c8 /* "\nTo make the above information more practical to work with, please also provide a disassembly of your %s binary. This can usually be done by running the following command:\n\n" */)
                ,program);
  __fprintf_chk(_stderr,2,((char *)(long)&s_objdump__d__S__w__which__s_______0014aa78 /* "   objdump -d -S -w `which %s` > ~/%s.objdump\n" */),program,program);
  __fprintf_chk(_stderr,2,((char *)(long)&s_Please_include_the_generated_fil_0014aaa8 /* "\nPlease include the generated file in your report.\n" */));
  __fprintf_chk(_stderr,2,
                ((char *)(long)&s_Running_this_program_with_debug_s_0014aae0 /* "Running this program with debug symbols or inside a debugger may provide further insights.\n\nThank you for helping to improve %s!\n\n" */)
                ,program);
  iVar1 = sigaction(param_1,(struct sigaction *)(&DAT_0015c140 + (long)param_1 * 0x98),(struct sigaction *)0x0);
  pcVar3 = ((char *)(long)&s_____Chained_handler_could_not_be_0014ab68 /* "!!! Chained handler could not be restored. Forcing exit.\n" */);
  if (-1 < iVar1) {
    raise(param_1);
    pcVar3 = ((char *)(long)&s_____Chained_handler_did_not_exit_0014aba8 /* "!!! Chained handler did not exit. Forcing exit.\n" */);
  }
  __fprintf_chk(_stderr,2,pcVar3);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}

