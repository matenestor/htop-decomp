/* InfoScreen_drawTitled @ 00128160 size 526 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void InfoScreen_drawTitled(InfoScreen * this, char * fmt, ...) */

void InfoScreen_drawTitled(InfoScreen *this,char *fmt,...)

{
  wchar_t wVar1;
  long lVar2;
  Panel *this_00;
  IncSet *this_01;
  long lVar3;
  __va_list_tag *p_Var4;
  char in_AL;
  int iVar5;
  undefined8 in_RCX;
  undefined8 in_RDX;
  ulong p1;
  __va_list_tag *p_Var6;
  ulong uVar8;
  undefined8 in_R8;
  undefined8 in_R9;
  long in_FS_OFFSET;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  va_list ap;
  undefined1 local_e8 [16];
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  __va_list_tag *p_Var7;

  p_Var6 = ap;
  p_Var7 = ap;
  if (in_AL != '\0') {
    local_b8 = in_XMM0_Qa;
    local_a8 = in_XMM1_Qa;
    local_98 = in_XMM2_Qa;
    local_88 = in_XMM3_Qa;
    local_78 = in_XMM4_Qa;
    local_68 = in_XMM5_Qa;
    local_58 = in_XMM6_Qa;
    local_48 = in_XMM7_Qa;
  }
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  ap[0].overflow_arg_area = &stack0x00000008;
  ap[0].reg_save_area = local_e8;
  ap[0].gp_offset = 0x10;
  ap[0].fp_offset = 0x30;
  p1 = (ulong)(_COLS + 1);
  p_Var4 = ap;
  while (p_Var7 != (__va_list_tag *)((long)ap - (p1 + 0xf & 0xfffffffffffff000))) {
    p_Var6 = (__va_list_tag *)((long)p_Var4 + -0x1000);
    *(undefined8 *)((long)p_Var4 + -8) = *(undefined8 *)((long)p_Var4 + -8);
    p_Var7 = (__va_list_tag *)((long)p_Var4 + -0x1000);
    p_Var4 = (__va_list_tag *)((long)p_Var4 + -0x1000);
  }
  uVar8 = (ulong)((uint)(p1 + 0xf) & 0xff0);
  lVar3 = -uVar8;
  if (uVar8 != 0) {
    *(undefined8 *)((long)p_Var6 + -8) = *(undefined8 *)((long)p_Var6 + -8);
  }
  *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x128277;
  local_d8 = in_RDX;
  local_d0 = in_RCX;
  local_c8 = in_R8;
  local_c0 = in_R9;
  iVar5 = __vsnprintf_chk((char *)((long)p_Var6 + lVar3),p1,2,p1,fmt,ap);
  if (_COLS < iVar5) {
    uVar8 = (ulong)(_COLS + -3);
    if (p1 < uVar8) {
      p1 = uVar8;
    }
    *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x1282a4;
    __memset_chk((undefined1 *)((long)p_Var6 + uVar8 + lVar3),0x2e,3,p1 - uVar8);
  }
  wVar1 = CRT_colors[0xe];
  *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x1282c0;
  wattrset(_stdscr,wVar1);
  *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x1282cc;
  iVar5 = wmove(_stdscr,0,0);
  if (iVar5 != -1) {
    *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x1282e2;
    whline(_stdscr,0x20,_COLS);
  }
  *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x1282ee;
  iVar5 = wmove(_stdscr,0,0);
  if (iVar5 != -1) {
    *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x128303;
    waddnstr(_stdscr,(char *)((long)p_Var6 + lVar3),-1);
  }
  wVar1 = CRT_colors[1];
  *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x128311;
  wattrset(_stdscr,wVar1);
  this_00 = this->display;
  *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x12832d;
  Panel_draw(this_00,true,true,true,false);
  this_01 = this->inc;
  wVar1 = CRT_colors[2];
  *(undefined8 *)((long)p_Var6 + lVar3 + -8) = 0x12833d;
  IncSet_drawBar(this_01,wVar1);
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(code **)((long)p_Var6 + lVar3 + -8) = OpenFilesScreen_draw;
    __stack_chk_fail();
  }
  return;
}

