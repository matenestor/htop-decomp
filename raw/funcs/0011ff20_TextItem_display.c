/* TextItem_display @ 0011ff20 size 341 */

void TextItem_display(TextItem_ *cast,RichString *out)

{
  long lVar1;
  wchar_t wVar2;
  wchar_t wVar3;
  char *__s;
  long lVar4;
  undefined1 *puVar5;
  int iVar6;
  size_t sVar7;
  ulong uVar8;
  ulong uVar9;
  cchar_t *pcVar10;
  undefined1 *puVar11;
  long lVar13;
  long in_FS_OFFSET;
  undefined1 auStack_58 [12];
  wchar_t local_4c;
  long local_40;
  undefined1 *puVar12;

  puVar11 = auStack_58;
  __s = (cast->super).text;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = CRT_colors[0x47];
  sVar7 = strlen(__s);
                    /* Unresolved local var: wchar_t[2986] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  wVar3 = out->chlen;
  uVar9 = (ulong)((int)sVar7 + 1);
  uVar8 = uVar9 * 4 + 0xf;
  puVar12 = auStack_58;
  puVar5 = auStack_58;
  while (puVar12 != auStack_58 + -(uVar8 & 0xfffffffffffff000)) {
    puVar11 = puVar5 + -0x1000;
    *(undefined8 *)(puVar5 + -8) = *(undefined8 *)(puVar5 + -8);
    puVar12 = puVar5 + -0x1000;
    puVar5 = puVar5 + -0x1000;
  }
  uVar8 = (ulong)((uint)uVar8 & 0xff0);
  lVar4 = -uVar8;
  if (uVar8 != 0) {
    *(undefined8 *)(puVar11 + -8) = *(undefined8 *)(puVar11 + -8);
  }
  *(undefined8 *)(puVar11 + lVar4 + -8) = 0x11ffcc;
  uVar8 = __mbstowcs_chk((int *)(puVar11 + lVar4),__s,(long)(int)sVar7,uVar9 & 0x3fffffffffffffff);
  if (0 < (int)uVar8) {
    local_4c = wVar3 + (int)uVar8;
    lVar13 = (long)wVar3;
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
    *(undefined8 *)(puVar11 + lVar4 + -8) = 0x11ffeb;
    RichString_setLen(out,local_4c);
    lVar1 = lVar13 * -4;
    pcVar10 = out->chptr + lVar13;
    do {
      wVar3 = *(wchar_t *)(puVar11 + lVar13 * 4 + lVar1 + lVar4);
      *(undefined8 *)(puVar11 + lVar4 + -8) = 0x12001c;
      iVar6 = iswprint(wVar3);
      pcVar10->attr = 0;
      pcVar10->chars[0] = L'\0';
      pcVar10->chars[1] = L'\0';
      pcVar10->chars[2] = L'\0';
      if (iVar6 == 0) {
        wVar3 = L'�';
      }
      pcVar10->attr = wVar2 & 0xffffff;
      lVar13 = lVar13 + 1;
      *(undefined1 (*) [16])(pcVar10->chars + 2) = (undefined1  [16])0x0;
      pcVar10->chars[0] = wVar3;
      pcVar10 = pcVar10 + 1;
    } while ((wchar_t)lVar13 < local_4c);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar11 + lVar4 + -8) = &UNK_00120078;
    __stack_chk_fail();
  }
  return;
}

