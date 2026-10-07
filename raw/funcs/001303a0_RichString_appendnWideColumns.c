/* RichString_appendnWideColumns @ 001303a0 size 386 */

/* DWARF original prototype: wchar_t RichString_appendnWideColumns(RichString * this, wchar_t attrs,
   char * data_c, wchar_t len, wchar_t * columns) */

wchar_t RichString_appendnWideColumns
                  (RichString *this,wchar_t attrs,char *data_c,wchar_t len,wchar_t *columns)

{
  wchar_t __c;
  long lVar1;
  undefined1 *puVar2;
  int iVar3;
  wchar_t wVar4;
  wchar_t wVar5;
  ulong uVar6;
  undefined1 (*pauVar7) [16];
  undefined1 *puVar8;
  wchar_t *pwVar10;
  long lVar11;
  long in_FS_OFFSET;
  undefined1 auStack_68 [8];
  wchar_t local_60;
  wchar_t local_5c;
  wchar_t local_58;
  wchar_t local_54;
  RichString *local_50;
  long local_40;
  undefined1 *puVar9;

  puVar8 = auStack_68;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  uVar6 = (long)(len + L'\x01') * 4 + 0xf;
  puVar9 = auStack_68;
  puVar2 = auStack_68;
  while (puVar9 != auStack_68 + -(uVar6 & 0xfffffffffffff000)) {
    puVar8 = puVar2 + -0x1000;
    *(undefined8 *)(puVar2 + -8) = *(undefined8 *)(puVar2 + -8);
    puVar9 = puVar2 + -0x1000;
    puVar2 = puVar2 + -0x1000;
  }
  uVar6 = (ulong)((uint)uVar6 & 0xff0);
  lVar1 = -uVar6;
  pwVar10 = (wchar_t *)(puVar8 + lVar1);
  if (uVar6 != 0) {
    *(undefined8 *)(puVar8 + -8) = *(undefined8 *)(puVar8 + -8);
  }
  *(undefined8 *)(puVar8 + lVar1 + -8) = 0x130430;
  local_58 = attrs;
  local_50 = this;
  uVar6 = __mbstowcs_chk((int *)(puVar8 + lVar1),data_c,(long)len,
                         (long)(len + L'\x01') & 0x3fffffffffffffff);
  wVar5 = L'\0';
  if (0 < (int)uVar6) {
    wVar5 = local_50->chlen;
    local_5c = wVar5 + (int)uVar6;
    *(undefined8 *)(puVar8 + lVar1 + -8) = 0x130457;
    local_60 = wVar5;
    RichString_setLen(local_50,local_5c);
                    /* Unresolved local var: wchar_t j@[???] */
    local_54 = L'\0';
    lVar11 = (long)wVar5 * 0x1c;
    do {
      __c = *pwVar10;
      *(undefined8 *)(puVar8 + lVar1 + -8) = 0x1304cc;
      iVar3 = iswprint(__c);
      if (iVar3 == 0) {
        __c = L'�';
      }
      *(undefined8 *)(puVar8 + lVar1 + -8) = 0x1304df;
      wVar4 = wcwidth(__c);
      if (*columns < wVar4) break;
                    /* Unresolved local var: wchar_t c@[???]
                       Unresolved local var: wchar_t cwidth@[???] */
      local_54 = local_54 + wVar4;
      *columns = *columns - wVar4;
      wVar5 = wVar5 + L'\x01';
      pwVar10 = pwVar10 + 1;
      pauVar7 = (undefined1 (*) [16])((long)local_50->chptr->chars + lVar11 + -4);
      lVar11 = lVar11 + 0x1c;
      *pauVar7 = (undefined1  [16])0x0;
      *(wchar_t *)*pauVar7 = local_58 & 0xffffff;
      *(wchar_t *)(*pauVar7 + 4) = __c;
      *(undefined1 (*) [16])(*pauVar7 + 0xc) = (undefined1  [16])0x0;
    } while (wVar5 != local_5c);
    *(undefined8 *)(puVar8 + lVar1 + -8) = 0x1304f1;
    RichString_setLen(local_50,wVar5);
    *columns = local_54;
    wVar5 = wVar5 - local_60;
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(code **)(puVar8 + lVar1 + -8) = Row_printLeftAlignedField;
    __stack_chk_fail();
  }
  return wVar5;
}

