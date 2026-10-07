/* RichString_writeWide @ 001308c0 size 303 */

/* DWARF original prototype: wchar_t RichString_writeWide(RichString * this, wchar_t attrs, char *
   data) */

wchar_t RichString_writeWide(RichString *this,wchar_t attrs,char *data)

{
  wchar_t __wc;
  long lVar1;
  undefined1 *puVar2;
  wchar_t len;
  int iVar3;
  size_t sVar4;
  ulong uVar5;
  ulong uVar6;
  cchar_t *pcVar7;
  undefined1 *puVar8;
  wchar_t *pwVar10;
  long in_FS_OFFSET;
  undefined1 auStack_58 [12];
  wchar_t local_4c;
  long local_40;
  undefined1 *puVar9;

  puVar8 = auStack_58;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sVar4 = strlen(data);
                    /* Unresolved local var: wchar_t[24761] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  uVar6 = (ulong)((int)sVar4 + 1);
  uVar5 = uVar6 * 4 + 0xf;
  puVar9 = auStack_58;
  puVar2 = auStack_58;
  while (puVar9 != auStack_58 + -(uVar5 & 0xfffffffffffff000)) {
    puVar8 = puVar2 + -0x1000;
    *(undefined8 *)(puVar2 + -8) = *(undefined8 *)(puVar2 + -8);
    puVar9 = puVar2 + -0x1000;
    puVar2 = puVar2 + -0x1000;
  }
  uVar5 = (ulong)((uint)uVar5 & 0xff0);
  lVar1 = -uVar5;
  pwVar10 = (wchar_t *)(puVar8 + lVar1);
  if (uVar5 != 0) {
    *(undefined8 *)(puVar8 + -8) = *(undefined8 *)(puVar8 + -8);
  }
  *(undefined8 *)(puVar8 + lVar1 + -8) = 0x130958;
  uVar5 = __mbstowcs_chk((int *)(puVar8 + lVar1),data,(long)(int)sVar4,uVar6 & 0x3fffffffffffffff);
  len = (wchar_t)uVar5;
  if (len < L'\x01') {
    local_4c = L'\0';
  }
  else {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    *(undefined8 *)(puVar8 + lVar1 + -8) = 0x130973;
    local_4c = len;
    RichString_setLen(this,len);
    pcVar7 = this->chptr;
    do {
      __wc = *pwVar10;
      *(undefined8 *)(puVar8 + lVar1 + -8) = 0x13098b;
      iVar3 = iswprint(__wc);
      pcVar7->attr = 0;
      pcVar7->chars[0] = L'\0';
      pcVar7->chars[1] = L'\0';
      pcVar7->chars[2] = L'\0';
      if (iVar3 == 0) {
        __wc = L'�';
      }
      pwVar10 = pwVar10 + 1;
      pcVar7->attr = attrs & 0xffffff;
      *(undefined1 (*) [16])(pcVar7->chars + 2) = (undefined1  [16])0x0;
      pcVar7->chars[0] = __wc;
      pcVar7 = pcVar7 + 1;
    } while ((wchar_t *)(puVar8 + (ulong)(uint)(len + L'\xffffffff') * 4 + lVar1 + 4) != pwVar10);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(code **)(puVar8 + lVar1 + -8) = RichString_appendAscii;
    __stack_chk_fail();
  }
  return local_4c;
}

