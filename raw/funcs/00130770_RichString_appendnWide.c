/* RichString_appendnWide @ 00130770 size 327 */

/* DWARF original prototype: wchar_t RichString_appendnWide(RichString * this, wchar_t attrs, char *
   data, wchar_t len) */

wchar_t RichString_appendnWide(RichString *this,wchar_t attrs,char *data,wchar_t len)

{
  long lVar1;
  wchar_t wVar2;
  long lVar3;
  undefined1 *puVar4;
  int iVar5;
  ulong uVar6;
  undefined1 *puVar7;
  cchar_t *pcVar9;
  long lVar10;
  long in_FS_OFFSET;
  undefined1 auStack_58 [8];
  wchar_t local_50;
  wchar_t local_4c;
  long local_40;
  undefined1 *puVar8;

                    /* Unresolved local var: wchar_t[24357] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  puVar7 = auStack_58;
  wVar2 = this->chlen;
  lVar10 = (long)wVar2;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar6 = (long)(len + L'\x01') * 4 + 0xf;
  puVar8 = auStack_58;
  puVar4 = auStack_58;
  while (puVar8 != auStack_58 + -(uVar6 & 0xfffffffffffff000)) {
    puVar7 = puVar4 + -0x1000;
    *(undefined8 *)(puVar4 + -8) = *(undefined8 *)(puVar4 + -8);
    puVar8 = puVar4 + -0x1000;
    puVar4 = puVar4 + -0x1000;
  }
  uVar6 = (ulong)((uint)uVar6 & 0xff0);
  lVar3 = -uVar6;
  if (uVar6 != 0) {
    *(undefined8 *)(puVar7 + -8) = *(undefined8 *)(puVar7 + -8);
  }
  *(undefined8 *)(puVar7 + lVar3 + -8) = 0x1307fe;
  uVar6 = __mbstowcs_chk((int *)(puVar7 + lVar3),data,(long)len,
                         (long)(len + L'\x01') & 0x3fffffffffffffff);
  local_50 = (wchar_t)uVar6;
  if (local_50 < L'\x01') {
    local_50 = L'\0';
  }
  else {
    local_4c = wVar2 + local_50;
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    *(undefined8 *)(puVar7 + lVar3 + -8) = 0x130820;
    RichString_setLen(this,local_4c);
    lVar1 = lVar10 * -4;
    pcVar9 = this->chptr + lVar10;
    do {
      wVar2 = *(wchar_t *)(puVar7 + lVar10 * 4 + lVar1 + lVar3);
      *(undefined8 *)(puVar7 + lVar3 + -8) = 0x13084c;
      iVar5 = iswprint(wVar2);
      pcVar9->attr = 0;
      pcVar9->chars[0] = L'\0';
      pcVar9->chars[1] = L'\0';
      pcVar9->chars[2] = L'\0';
      if (iVar5 == 0) {
        wVar2 = L'�';
      }
      pcVar9->attr = attrs & 0xffffff;
      lVar10 = lVar10 + 1;
      *(undefined1 (*) [16])(pcVar9->chars + 2) = (undefined1  [16])0x0;
      pcVar9->chars[0] = wVar2;
      pcVar9 = pcVar9 + 1;
    } while ((wchar_t)lVar10 < local_4c);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(code **)(puVar7 + lVar3 + -8) = RichString_writeWide;
    __stack_chk_fail();
  }
  return local_50;
}

