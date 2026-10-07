/* CRT_setColors @ 00116400 size 288 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_setColors(wchar_t colorScheme)

{
  uint uVar1;
  ulong uVar2;
  short p2;
  int iVar3;
  int iVar4;

  iVar4 = 0;
                    /* Unresolved local var: short i@[???]
                       Unresolved local var: short j@[???] */
  CRT_colorScheme = colorScheme;
  do {
    iVar3 = 0;
    uVar2 = (ulong)(iVar4 * -8 + 0x38);
LAB_00116440:
    do {
      uVar1 = (uint)uVar2;
      while ((0x2000000200000U >> (uVar2 & 0x3f) & 1) == 0) {
                    /* Unresolved local var: short bg@[???] */
        p2 = (short)iVar3;
        if ((colorScheme == L'\x05') || (p2 != 0)) {
          iVar3 = iVar3 + 1;
          init_pair((short)uVar2,(short)iVar4,p2);
          uVar2 = (ulong)((int)uVar2 + 1);
          if (iVar3 == 8) goto LAB_00116486;
          goto LAB_00116440;
        }
        uVar1 = (int)uVar2 + 1;
        init_pair((short)uVar2,(short)iVar4,-1);
        iVar3 = 1;
        uVar2 = (ulong)uVar1;
      }
      iVar3 = iVar3 + 1;
      uVar2 = (ulong)(uVar1 + 1);
    } while (iVar3 != 8);
LAB_00116486:
    iVar4 = iVar4 + 1;
    if (iVar4 == 8) {
      init_pair(0x15,(ushort)(8 < _COLORS) * 8,-(ushort)(colorScheme != L'\x05'));
      init_pair(0x31,7,-1);
      CRT_colors = CRT_colorSchemes[colorScheme];
      return;
    }
  } while( true );
}

