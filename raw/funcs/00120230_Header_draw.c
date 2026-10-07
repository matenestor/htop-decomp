/* Header_draw @ 00120230 size 844 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void Header_draw(Header * this) */

void Header_draw(Header *this)

{
  byte *pbVar1;
  byte bVar2;
  wchar_t wVar3;
  Vector *pVVar4;
  Object *a0;
  int iVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  wchar_t wVar9;
  long in_R8;
  long in_R9;
  wchar_t p1;
  uint uVar10;
  float fVar11;
  float fVar12;
  float local_54;
  ulong local_48;
  float local_3c;

  p1 = L'\0';
  wVar3 = this->height;
  wVar9 = this->pad;
  wattrset(_stdscr,*CRT_colors);
                    /* Unresolved local var: wchar_t y@[???] */
  if (L'\0' < wVar3) {
    do {
      iVar5 = wmove(_stdscr,p1,0);
      if (iVar5 != -1) {
        whline(_stdscr,0x20,_COLS);
      }
      p1 = p1 + L'\x01';
    } while (wVar3 != p1);
  }
  lVar6 = (long)this->headerLayout;
  bVar2 = HeaderLayout_layouts[lVar6].columns;
                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  if ((ulong)bVar2 != 0) {
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: float colWidth@[???]
                       Unresolved local var: wchar_t y@[???]
                       Unresolved local var: wchar_t i@[???] */
    local_48 = 0;
    local_54 = 0.0;
    uVar7 = wVar9 / 2;
    fVar12 = (float)((_COLS + wVar9 * -2) - (bVar2 - 1));
    while( true ) {
      pVVar4 = this->columns[local_48];
      local_3c = ((float)*(byte *)(local_48 + lVar6 * 0x18 + 0x155fa1) * fVar12) / 100.0;
      fVar11 = local_3c;
      if (ABS(local_3c) < 8388608.0) {
        fVar11 = (float)((uint)local_3c & 0x80000000 |
                        (uint)((float)(int)local_3c -
                              (float)(-(uint)(local_3c < (float)(int)local_3c) & 0x3f800000)));
      }
      local_54 = (local_3c - fVar11) + local_54;
      if (1.0 <= local_54) {
        local_54 = local_54 - 1.0;
        local_3c = local_3c + 1.0;
      }
      lVar6 = 0;
      uVar10 = uVar7;
      if (L'\0' < pVVar4->items) {
        do {
          a0 = pVVar4->array[lVar6];
          fVar11 = local_3c;
                    /* Unresolved local var: wchar_t j@[???] */
          if (((*(int *)&a0[4].klass == 2) && (*(char *)((long)&a0->klass[4].delete + 1) == '\0'))
             && (iVar5 = *(int *)((long)&a0[9].klass + 4), 1 < iVar5)) {
            lVar8 = 1;
            do {
              pbVar1 = (byte *)(local_48 + (long)this->headerLayout * 0x18 + 0x155fa1 + lVar8);
              lVar8 = lVar8 + 1;
              fVar11 = fVar11 + 1.0 + ((float)*pbVar1 * fVar12) / 100.0;
            } while ((int)lVar8 < iVar5);
          }
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: float actualWidth@[???] */
          if (ABS(fVar11) < 8388608.0) {
            fVar11 = (float)((uint)((float)(int)fVar11 -
                                   (float)(-(uint)(fVar11 < (float)(int)fVar11) & 0x3f800000)) |
                            (uint)fVar11 & 0x80000000);
          }
          (*(code *)a0[1].klass)
                    ((long)a0,(ulong)(uint)wVar9,(ulong)uVar10,(ulong)(uint)(int)fVar11,in_R8,in_R9)
          ;
          lVar6 = lVar6 + 1;
          uVar10 = uVar10 + *(int *)&a0[9].klass;
        } while ((wchar_t)lVar6 < pVVar4->items);
      }
      if (ABS(local_3c) < 8388608.0) {
        local_3c = (float)((uint)((float)(int)local_3c -
                                 (float)(-(uint)(local_3c < (float)(int)local_3c) & 0x3f800000)) |
                          (uint)local_3c & 0x80000000);
      }
      local_48 = local_48 + 1;
      wVar9 = (int)((float)wVar9 + local_3c) + L'\x01';
      if (bVar2 <= local_48) break;
      lVar6 = (long)this->headerLayout;
    }
  }
  return;
}

