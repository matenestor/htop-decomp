/* Panel_setHeader @ 00120880 size 315 */

/* DWARF original prototype: void Panel_setHeader(Panel * this, char * header) */

void Panel_setHeader(Panel *this,char *header)

{
  wchar_t wVar1;
  wchar_t __wc;
  long lVar2;
  undefined1 *puVar3;
  Panel *pPVar4;
  wchar_t len;
  int iVar5;
  size_t sVar6;
  ulong uVar7;
  ulong uVar8;
  cchar_t *pcVar9;
  undefined1 *puVar10;
  wchar_t *pwVar12;
  long in_FS_OFFSET;
  undefined1 auStack_58 [8];
  Panel *local_50;
  long local_40;
  undefined1 *puVar11;

  puVar10 = auStack_58;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  wVar1 = CRT_colors[7];
  local_50 = this;
  sVar6 = strlen(header);
                    /* Unresolved local var: wchar_t[6165] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  uVar8 = (ulong)((int)sVar6 + 1);
  uVar7 = uVar8 * 4 + 0xf;
  puVar11 = auStack_58;
  puVar3 = auStack_58;
  while (puVar11 != auStack_58 + -(uVar7 & 0xfffffffffffff000)) {
    puVar10 = puVar3 + -0x1000;
    *(undefined8 *)(puVar3 + -8) = *(undefined8 *)(puVar3 + -8);
    puVar11 = puVar3 + -0x1000;
    puVar3 = puVar3 + -0x1000;
  }
  uVar7 = (ulong)((uint)uVar7 & 0xff0);
  lVar2 = -uVar7;
  pwVar12 = (wchar_t *)(puVar10 + lVar2);
  if (uVar7 != 0) {
    *(undefined8 *)(puVar10 + -8) = *(undefined8 *)(puVar10 + -8);
  }
  *(undefined8 *)(puVar10 + lVar2 + -8) = 0x120922;
  uVar7 = __mbstowcs_chk((int *)(puVar10 + lVar2),header,(long)(int)sVar6,uVar8 & 0x3fffffffffffffff
                        );
  pPVar4 = local_50;
  len = (wchar_t)uVar7;
  if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    *(undefined8 *)(puVar10 + lVar2 + -8) = 0x12093f;
    RichString_setLen(&local_50->header,len);
    pcVar9 = (pPVar4->header).chptr;
    do {
      __wc = *pwVar12;
      *(undefined8 *)(puVar10 + lVar2 + -8) = 0x12095b;
      iVar5 = iswprint(__wc);
      pcVar9->attr = 0;
      pcVar9->chars[0] = L'\0';
      pcVar9->chars[1] = L'\0';
      pcVar9->chars[2] = L'\0';
      if (iVar5 == 0) {
        __wc = L'�';
      }
      pwVar12 = pwVar12 + 1;
      pcVar9->attr = wVar1 & 0xffffff;
      *(undefined1 (*) [16])(pcVar9->chars + 2) = (undefined1  [16])0x0;
      pcVar9->chars[0] = __wc;
      pcVar9 = pcVar9 + 1;
    } while (pwVar12 != (wchar_t *)(puVar10 + (ulong)(uint)(len + L'\xffffffff') * 4 + lVar2 + 4));
  }
  local_50->needsRedraw = true;
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(code **)(puVar10 + lVar2 + -8) = TextMeterMode_draw;
    __stack_chk_fail();
  }
  return;
}

