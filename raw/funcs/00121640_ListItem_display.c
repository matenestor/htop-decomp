/* ListItem_display @ 00121640 size 412 */

void ListItem_display(ListItem_ *cast,RichString *out)

{
  wchar_t wVar1;
  long lVar2;
  RichString *this;
  wchar_t len;
  int iVar3;
  ulong uVar4;
  undefined1 **ppuVar5;
  undefined1 **ppuVar6;
  char *pcVar8;
  cchar_t *pcVar9;
  wchar_t *pwVar10;
  long in_FS_OFFSET;
  undefined1 *local_68;
  RichString *local_60;
  uint local_54;
  wchar_t *local_50;
  long local_40;
  undefined1 **ppuVar7;

  ppuVar6 = &local_68;
  ppuVar5 = &local_68;
  ppuVar7 = &local_68;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_60 = out;
  if (cast->moving != false) {
                    /* Unresolved local var: wchar_t[0] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    pcVar8 = ((char *)0x14837b /* "+ " */);
    if (CRT_utf8) {
      pcVar8 = &DAT_00148769;
    }
    uVar4 = (-(ulong)!CRT_utf8 & 0xfffffffffffffff8) + 0x23;
    wVar1 = CRT_colors[1];
    ppuVar5 = &local_68;
    while (ppuVar7 != (undefined1 **)((long)&local_68 - (uVar4 & 0xfffffffffffff000))) {
      ppuVar6 = (undefined1 **)((long)ppuVar5 + -0x1000);
      *(undefined8 *)((long)ppuVar5 + -8) = *(undefined8 *)((long)ppuVar5 + -8);
      ppuVar7 = (undefined1 **)((long)ppuVar5 + -0x1000);
      ppuVar5 = (undefined1 **)((long)ppuVar5 + -0x1000);
    }
    uVar4 = (ulong)((uint)uVar4 & 0xff0);
    lVar2 = -uVar4;
    pwVar10 = (wchar_t *)((long)ppuVar6 + lVar2);
    if (uVar4 != 0) {
      *(undefined8 *)((long)ppuVar6 + -8) = *(undefined8 *)((long)ppuVar6 + -8);
    }
    *(undefined8 *)((long)ppuVar6 + lVar2 + -8) = 0x121754;
    local_68 = (undefined1 *)&local_68;
    uVar4 = __mbstowcs_chk((int *)((long)ppuVar6 + lVar2),pcVar8,
                           (-(ulong)!CRT_utf8 & 0xfffffffffffffffe) + 4,
                           (-(ulong)!CRT_utf8 & 0xfffffffffffffffe) + 5);
    len = (wchar_t)uVar4;
    ppuVar5 = (undefined1 **)local_68;
    if (L'\0' < len) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      *(undefined8 *)((long)ppuVar6 + lVar2 + -8) = 0x12176d;
      RichString_setLen(local_60,len);
      local_50 = (wchar_t *)((long)ppuVar6 + (ulong)(uint)(len + L'\xffffffff') * 4 + lVar2 + 4);
      pcVar9 = local_60->chptr;
      local_54 = wVar1 & 0xffffff;
      do {
        wVar1 = *pwVar10;
        *(undefined8 *)((long)ppuVar6 + lVar2 + -8) = 0x12179c;
        iVar3 = iswprint(wVar1);
        pcVar9->attr = 0;
        pcVar9->chars[0] = L'\0';
        pcVar9->chars[1] = L'\0';
        pcVar9->chars[2] = L'\0';
        if (iVar3 == 0) {
          wVar1 = L'�';
        }
        pwVar10 = pwVar10 + 1;
        *(undefined1 (*) [16])(pcVar9->chars + 2) = (undefined1  [16])0x0;
        pcVar9->attr = local_54;
        pcVar9->chars[0] = wVar1;
        ppuVar5 = (undefined1 **)local_68;
        pcVar9 = pcVar9 + 1;
      } while (local_50 != pwVar10);
    }
  }
  this = local_60;
  pcVar8 = cast->value;
  wVar1 = CRT_colors[1];
  *(undefined8 *)((long)ppuVar5 + -8) = 0x12168b;
  RichString_appendWide(this,wVar1,pcVar8);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)((long)ppuVar5 + -8) = &UNK_001217df;
  __stack_chk_fail();
}

