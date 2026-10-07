/* RichString_appendWide @ 00130610 size 343 */

/* DWARF original prototype: wchar_t RichString_appendWide(RichString * this, wchar_t attrs, char *
   data) */

wchar_t RichString_appendWide(RichString *this,wchar_t attrs,char *data)

{
  long lVar1;
  wchar_t wVar2;
  long lVar3;
  undefined1 *puVar4;
  int iVar5;
  size_t sVar6;
  ulong uVar7;
  ulong uVar8;
  undefined1 *puVar9;
  cchar_t *pcVar11;
  long lVar12;
  long in_FS_OFFSET;
  undefined1 auStack_58 [8];
  wchar_t local_50;
  wchar_t local_4c;
  long local_40;
  undefined1 *puVar10;

  puVar9 = auStack_58;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sVar6 = strlen(data);
                    /* Unresolved local var: wchar_t[23892] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  wVar2 = this->chlen;
  lVar12 = (long)wVar2;
  uVar8 = (ulong)((int)sVar6 + 1);
  uVar7 = uVar8 * 4 + 0xf;
  puVar10 = auStack_58;
  puVar4 = auStack_58;
  while (puVar10 != auStack_58 + -(uVar7 & 0xfffffffffffff000)) {
    puVar9 = puVar4 + -0x1000;
    *(undefined8 *)(puVar4 + -8) = *(undefined8 *)(puVar4 + -8);
    puVar10 = puVar4 + -0x1000;
    puVar4 = puVar4 + -0x1000;
  }
  uVar7 = (ulong)((uint)uVar7 & 0xff0);
  lVar3 = -uVar7;
  if (uVar7 != 0) {
    *(undefined8 *)(puVar9 + -8) = *(undefined8 *)(puVar9 + -8);
  }
  *(undefined8 *)(puVar9 + lVar3 + -8) = 0x1306ac;
  uVar7 = __mbstowcs_chk((int *)(puVar9 + lVar3),data,(long)(int)sVar6,uVar8 & 0x3fffffffffffffff);
  local_50 = (wchar_t)uVar7;
  if (local_50 < L'\x01') {
    local_50 = L'\0';
  }
  else {
    local_4c = wVar2 + local_50;
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    *(undefined8 *)(puVar9 + lVar3 + -8) = 0x1306ce;
    RichString_setLen(this,local_4c);
    lVar1 = lVar12 * -4;
    pcVar11 = this->chptr + lVar12;
    do {
      wVar2 = *(wchar_t *)(puVar9 + lVar12 * 4 + lVar1 + lVar3);
      *(undefined8 *)(puVar9 + lVar3 + -8) = 0x1306fc;
      iVar5 = iswprint(wVar2);
      pcVar11->attr = 0;
      pcVar11->chars[0] = L'\0';
      pcVar11->chars[1] = L'\0';
      pcVar11->chars[2] = L'\0';
      if (iVar5 == 0) {
        wVar2 = L'�';
      }
      pcVar11->attr = attrs & 0xffffff;
      lVar12 = lVar12 + 1;
      *(undefined1 (*) [16])(pcVar11->chars + 2) = (undefined1  [16])0x0;
      pcVar11->chars[0] = wVar2;
      pcVar11 = pcVar11 + 1;
    } while ((wchar_t)lVar12 < local_4c);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(code **)(puVar9 + lVar3 + -8) = RichString_appendnWide;
    __stack_chk_fail();
  }
  return local_50;
}

