/* CommandScreen_scan @ 0011e100 size 534 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void CommandScreen_scan(InfoScreen * this) */

void CommandScreen_scan(InfoScreen *this)

{
  wchar_t wVar1;
  _Bool _Var2;
  wchar_t wVar3;
  Panel *a0;
  Process *pPVar4;
  Machine_ *pMVar5;
  code *pcVar6;
  long lVar7;
  ulong *puVar8;
  char cVar9;
  int iVar10;
  ulong uVar11;
  uint uVar12;
  ulong *puVar13;
  char *a4;
  long in_R9;
  wchar_t wVar15;
  long in_FS_OFFSET;
  ulong local_68;
  char *local_60;
  ulong local_58;
  char *local_50;
  long local_40;
  ulong *puVar14;

  puVar14 = &local_68;
  puVar13 = &local_68;
  a0 = this->display;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  wVar15 = a0->selected;
  if (wVar15 < L'\0') {
    wVar15 = L'\0';
  }
  Vector_prune(a0->items);
  pPVar4 = this->process;
  a0->needsRedraw = true;
  a0->scrollV = L'\0';
                    /* Unresolved local var: Settings * settings@[???] */
  pMVar5 = (pPVar4->super).host;
  _Var2 = pPVar4->isUserlandThread;
  a0->selected = L'\0';
  a0->oldSelected = L'\0';
  if (((_Var2 != false) && (pMVar5->settings->showThreadNames != false)) ||
     (a4 = (pPVar4->mergedCommand).str, a4 == (char *)0x0)) {
    a4 = pPVar4->cmdline;
  }
  local_68 = (ulong)(int)(_COLS + 1);
  puVar8 = &local_68;
  while (puVar14 != (ulong *)((long)&local_68 - (local_68 + 0xf & 0xfffffffffffff000))) {
    puVar13 = (ulong *)((long)puVar8 + -0x1000);
    *(undefined8 *)((long)puVar8 + -8) = *(undefined8 *)((long)puVar8 + -8);
    puVar14 = (ulong *)((long)puVar8 + -0x1000);
    puVar8 = (ulong *)((long)puVar8 + -0x1000);
  }
  uVar11 = (ulong)((uint)(local_68 + 0xf) & 0xff0);
  lVar7 = -uVar11;
  if (uVar11 != 0) {
    *(undefined8 *)((long)puVar13 + -8) = *(undefined8 *)((long)puVar13 + -8);
  }
  cVar9 = *a4;
  uVar11 = 0xffffffff;
  uVar12 = 0;
  if (cVar9 != '\0') {
    do {
      *(char *)((long)puVar13 + (int)uVar12 + lVar7) = cVar9;
      if (cVar9 == ' ') {
        uVar11 = (ulong)uVar12;
      }
      if (uVar12 == _COLS) {
        if ((int)uVar11 == -1) {
          uVar11 = (ulong)uVar12;
          local_58 = 1;
          uVar12 = 1;
          local_60 = a4;
        }
        else {
          iVar10 = uVar12 - (int)uVar11;
          uVar12 = iVar10 + 1;
          local_58 = (ulong)(int)uVar12;
          local_60 = a4 + -(long)iVar10;
        }
        *(undefined1 *)((long)puVar13 + (int)uVar11 + lVar7) = 0;
        *(undefined8 *)((long)puVar13 + lVar7 + -8) = 0x11e24d;
        local_50 = a4;
        InfoScreen_addLine(this,(char *)((long)puVar13 + lVar7));
        *(undefined8 *)((long)puVar13 + lVar7 + -8) = 0x11e261;
        __memcpy_chk((undefined1 *)((long)puVar13 + lVar7),local_60,local_58,local_68);
        uVar11 = 0xffffffff;
        cVar9 = local_50[1];
        a4 = local_50;
      }
      else {
        cVar9 = a4[1];
        uVar12 = uVar12 + 1;
      }
      a4 = a4 + 1;
    } while (cVar9 != '\0');
    if (0 < (int)uVar12) {
      *(undefined1 *)((long)puVar13 + (int)uVar12 + lVar7) = 0;
      *(undefined8 *)((long)puVar13 + lVar7 + -8) = 0x11e295;
      InfoScreen_addLine(this,(char *)((long)puVar13 + lVar7));
    }
  }
                    /* Unresolved local var: wchar_t size@[???] */
  wVar3 = a0->items->items;
  wVar1 = wVar3 + L'\xffffffff';
  if (wVar3 <= wVar15) {
    wVar15 = wVar1;
  }
  if (wVar15 < L'\0') {
    wVar15 = L'\0';
  }
  pcVar6 = (a0->super).klass[1].extends;
  a0->selected = wVar15;
  if (pcVar6 != (code *)0x0) {
    *(undefined8 *)((long)puVar13 + lVar7 + -8) = 0x11e2c9;
    (*pcVar6)((long)a0,0xffffffff,(ulong)(uint)wVar1,uVar11,(long)a4,in_R9);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)((long)puVar13 + lVar7 + -8) = &UNK_0011e328;
  __stack_chk_fail();
}

