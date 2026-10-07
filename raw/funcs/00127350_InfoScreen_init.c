/* InfoScreen_init @ 00127350 size 684 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: InfoScreen * InfoScreen_init(InfoScreen * this, Process * process,
   FunctionBar * bar, wchar_t height, char * panelHeader) */

InfoScreen_2 *
InfoScreen_init(InfoScreen *this,Process *process,FunctionBar *bar,wchar_t height,char *panelHeader)

{
  wchar_t wVar1;
  long lVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  wchar_t wVar5;
  int iVar6;
  Panel *pPVar7;
  Vector *pVVar8;
  IncSet_3 *pIVar9;
  size_t sVar10;
  ulong uVar11;
  ulong uVar12;
  undefined1 *puVar13;
  wchar_t *pwVar15;
  cchar_t *pcVar16;
  long in_FS_OFFSET;
  undefined1 auStack_68 [8];
  Panel *local_60;
  FunctionBar *local_58;
  FunctionBar *pFStack_50;
  long local_40;
  undefined1 *puVar14;

  puVar14 = auStack_68;
  puVar13 = auStack_68;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this->process = process;
  if (bar == (FunctionBar *)0x0) {
    local_58 = (FunctionBar *)CONCAT44(local_58._4_4_,height);
    bar = FunctionBar_new(InfoScreenFunctions,InfoScreenKeys,((char *)0x14dbb0 /* L"ċČč\x1b" */));
    height = (wchar_t)local_58;
  }
  uVar4 = _COLS;
  local_58 = bar;
  pFStack_50 = bar;
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  pPVar7 = malloc(0x26e0);
  if (pPVar7 == (Panel *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  pPVar7->w = uVar4;
  pPVar7->h = height;
  pPVar7->cursorX = L'\0';
  pPVar7->cursorY = L'\0';
  (pPVar7->super).klass = &Panel_class.super;
  pPVar7->eventHandlerState = (void *)0x0;
  pPVar7->x = L'\0';
  pPVar7->y = L'\x01';
  pVVar8 = Vector_new(&ListItem_class,false,L'\xffffffff');
  this->display = pPVar7;
  pPVar7->items = pVVar8;
  pPVar7->needsRedraw = true;
  pPVar7->cursorOn = false;
  (pPVar7->header).chptr = (pPVar7->header).chstr;
  pPVar7->scrollV = L'\0';
  pPVar7->scrollH = L'\0';
  pPVar7->selected = L'\0';
  pPVar7->oldSelected = L'\0';
  pPVar7->selectedLen = L'\0';
  pPVar7->wasFocus = false;
  (pPVar7->header).chlen = L'\0';
  *(undefined8 *)&(pPVar7->header).highlightAttr = 0x900000000;
  (pPVar7->header).chstr[0].attr = 0;
  (pPVar7->header).chstr[0].chars[0] = L'\0';
  (pPVar7->header).chstr[0].chars[1] = L'\0';
  (pPVar7->header).chstr[0].chars[2] = L'\0';
  pPVar7->currentBar = local_58;
  pPVar7->defaultBar = pFStack_50;
  *(undefined1 (*) [16])((pPVar7->header).chstr[0].chars + 2) = (undefined1  [16])0x0;
  pIVar9 = IncSet_new(bar);
  this->inc = (IncSet *)pIVar9;
  local_60 = this->display;
  pVVar8 = Vector_new(local_60->items->type,true,L'\xffffffff');
  this->lines = pVVar8;
  wVar1 = CRT_colors[7];
  sVar10 = strlen(panelHeader);
                    /* Unresolved local var: wchar_t[37790] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  uVar12 = (ulong)((int)sVar10 + 1);
  uVar11 = uVar12 * 4 + 0xf;
  puVar3 = auStack_68;
  while (puVar14 != auStack_68 + -(uVar11 & 0xfffffffffffff000)) {
    puVar13 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar14 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar11 = (ulong)((uint)uVar11 & 0xff0);
  lVar2 = -uVar11;
  pwVar15 = (wchar_t *)(puVar13 + lVar2);
  if (uVar11 != 0) {
    *(undefined8 *)(puVar13 + -8) = *(undefined8 *)(puVar13 + -8);
  }
  *(undefined8 *)(puVar13 + lVar2 + -8) = 0x127525;
  uVar11 = __mbstowcs_chk((int *)(puVar13 + lVar2),panelHeader,(long)(int)sVar10,
                          uVar12 & 0x3fffffffffffffff);
  pPVar7 = local_60;
  wVar5 = (wchar_t)uVar11;
  if (L'\0' < wVar5) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    *(undefined8 *)(puVar13 + lVar2 + -8) = 0x127542;
    RichString_setLen(&local_60->header,wVar5);
    local_58 = (FunctionBar *)(puVar13 + (ulong)(uint)(wVar5 + L'\xffffffff') * 4 + lVar2 + 4);
    pcVar16 = (pPVar7->header).chptr;
    do {
      wVar5 = *pwVar15;
      *(undefined8 *)(puVar13 + lVar2 + -8) = 0x127564;
      iVar6 = iswprint(wVar5);
      pcVar16->attr = 0;
      pcVar16->chars[0] = L'\0';
      pcVar16->chars[1] = L'\0';
      pcVar16->chars[2] = L'\0';
      if (iVar6 == 0) {
        wVar5 = L'�';
      }
      pwVar15 = pwVar15 + 1;
      pcVar16->attr = wVar1 & 0xffffff;
      *(undefined1 (*) [16])(pcVar16->chars + 2) = (undefined1  [16])0x0;
      pcVar16->chars[0] = wVar5;
      pcVar16 = pcVar16 + 1;
    } while ((FunctionBar *)pwVar15 != local_58);
  }
  local_60->needsRedraw = true;
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar13 + lVar2 + -8) = &UNK_00127604;
    __stack_chk_fail();
  }
  return (InfoScreen_2 *)this;
}

