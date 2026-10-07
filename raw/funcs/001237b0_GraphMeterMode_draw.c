/* GraphMeterMode_draw @ 001237b0 size 1254 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void GraphMeterMode_draw(Meter * this, wchar_t x, wchar_t y, wchar_t w)
    */

void GraphMeterMode_draw(Meter *this,wchar_t x,wchar_t y,wchar_t w)

{
  int iVar1;
  Object_Display p_Var2;
  Machine *pMVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *p1;
  long lVar8;
  double *pdVar9;
  ulong uVar10;
  double *pdVar11;
  undefined4 in_register_0000000c;
  long lVar12;
  char **ppcVar13;
  size_t __size;
  int iVar14;
  undefined4 in_register_00000014;
  ulong uVar15;
  undefined4 in_register_00000034;
  long in_R9;
  wchar_t wVar16;
  ulong uVar17;
  int iVar18;
  uint uVar19;
  double __x;
  double dVar20;
  ulong local_58;
  int local_40;

                    /* Unresolved local var: char * caption@[???]
                       Unresolved local var: wchar_t captionLen@[???]
                       Unresolved local var: GraphData * data@[???]
                       Unresolved local var: size_t nValues@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: char * * GraphMeterMode_dots@[???]
                       Unresolved local var: wchar_t GraphMeterMode_pixPerRow@[???]
                       Unresolved local var: size_t i@[???] */
  p_Var2 = (this->super).klass[2].display;
  if (p_Var2 == (Object_Display)0x0) {
    p1 = this->caption;
  }
  else {
    p1 = (char *)(*p_Var2)(&this->super,(RichString *)CONCAT44(in_register_00000034,x),
                           CONCAT44(in_register_00000014,y),CONCAT44(in_register_0000000c,w),
                           (long)this,in_R9);
  }
  wattrset(_stdscr,CRT_colors[0xe]);
  iVar4 = wmove(_stdscr,y,x);
  if (iVar4 != -1) {
    waddnstr(_stdscr,p1,3);
  }
  iVar4 = w + L'\xfffffffd';
  uVar17 = (this->drawData).nValues;
  if (((int)(uVar17 >> 1) < iVar4) && (uVar17 < 0x8000)) {
                    /* Unresolved local var: size_t oldNValues@[???] */
    uVar10 = (uVar17 >> 1) + uVar17;
    pdVar9 = (this->drawData).values;
    if (uVar10 <= (ulong)((long)iVar4 * 2)) {
      uVar10 = (long)iVar4 * 2;
    }
    if (0x8000 < uVar10) {
      uVar10 = 0x8000;
    }
    (this->drawData).nValues = uVar10;
    __size = uVar10 * 8;
                    /* Unresolved local var: void * data@[???] */
    pdVar11 = realloc(pdVar9,__size);
    if (pdVar11 == (double *)0x0) {
      free(pdVar9);
                    /* WARNING: Subroutine does not return */
      fail();
    }
    (this->drawData).values = pdVar11;
    lVar12 = (this->drawData).nValues - uVar17;
    if (__size <= (ulong)(lVar12 * 8)) {
      __size = lVar12 * 8;
    }
    __memmove_chk(pdVar11 + lVar12,pdVar11,uVar17 * 8,__size + lVar12 * -8);
    memset((this->drawData).values,0,((this->drawData).nValues - uVar17) * 8);
    uVar17 = (this->drawData).nValues;
  }
  if (uVar17 == 0) {
    return;
  }
  pMVar3 = this->host;
  lVar12 = (pMVar3->realtime).tv_sec;
  lVar8 = (this->drawData).time.tv_sec;
  if (lVar12 == lVar8) {
    lVar8 = (pMVar3->realtime).tv_usec;
    if (lVar8 < (this->drawData).time.tv_usec) goto LAB_0012392b;
  }
  else {
    if (lVar12 < lVar8) goto LAB_0012392b;
    lVar8 = (pMVar3->realtime).tv_usec;
  }
                    /* Unresolved local var: wchar_t globalDelay@[???]
                       Unresolved local var: timeval delay@[???] */
  wVar16 = pMVar3->settings->delay;
  lVar12 = wVar16 / 10 + lVar12;
  (this->drawData).time.tv_sec = lVar12;
  lVar8 = (long)(wVar16 % 10) * 100000 + lVar8;
  (this->drawData).time.tv_usec = lVar8;
  if (999999 < lVar8) {
    (this->drawData).time.tv_sec = lVar12 + 1;
    (this->drawData).time.tv_usec = lVar8 + -1000000;
  }
  pdVar9 = (this->drawData).values;
  memmove(pdVar9,pdVar9 + 1,uVar17 * 8 - 8);
  pdVar9 = this->values;
                    /* Unresolved local var: double sum@[???]
                       Unresolved local var: size_t i@[???] */
  if ((ulong)this->curItems == 0) {
    dVar20 = 0.0;
  }
  else {
    dVar20 = 0.0;
    pdVar11 = pdVar9 + this->curItems;
    do {
      if (0.0 < *pdVar9) {
        dVar20 = dVar20 + *pdVar9;
      }
      pdVar9 = pdVar9 + 1;
    } while (pdVar9 != pdVar11);
  }
  (this->drawData).values[uVar17 - 1] = dVar20;
LAB_0012392b:
  if (iVar4 < 1) {
    return;
  }
  local_40 = x + L'\x03';
  uVar15 = uVar17 >> 1;
  uVar10 = (long)iVar4;
  if (uVar15 < (ulong)(long)iVar4) {
    local_40 = (iVar4 + local_40) - (int)uVar15;
    uVar10 = uVar15;
  }
  ppcVar13 = GraphMeterMode_dotsAscii;
  uVar19 = -(uint)(CRT_utf8 == false) & 0xfffffffe;
  iVar4 = uVar19 + 4;
  if (CRT_utf8 != false) {
    ppcVar13 = GraphMeterMode_dotsUtf8;
  }
                    /* Unresolved local var: wchar_t col@[???] */
  local_58 = uVar17 + uVar10 * -2;
  if (local_58 < uVar17 - 1) {
                    /* Unresolved local var: wchar_t pix@[DW_OP_reg10(R10)]
                       Unresolved local var: double total@[???]
                       Unresolved local var: wchar_t v1@[???]
                       Unresolved local var: wchar_t v2@[???]
                       Unresolved local var: wchar_t colorIdx@[???] */
    iVar1 = iVar4 * 4;
                    /* Unresolved local var: wchar_t line@[???]
                       Unresolved local var: wchar_t line1@[???]
                       Unresolved local var: wchar_t line2@[???] */
    do {
      dVar20 = this->total;
      pdVar9 = (this->drawData).values;
      if (dVar20 <= 1.0) {
        dVar20 = 1.0;
      }
      __x = (pdVar9[local_58] / dVar20) * (double)iVar1;
      lVar12 = lround(__x);
      iVar7 = iVar1;
      if ((int)lVar12 <= iVar1) {
        lVar12 = lround(__x);
        iVar7 = 1;
        if (1 < (int)lVar12) {
          lVar12 = lround(__x);
          iVar7 = (int)lVar12;
        }
      }
      dVar20 = (pdVar9[local_58 + 1] / dVar20) * (double)iVar1;
      lVar12 = lround(dVar20);
      iVar6 = iVar1;
      if ((int)lVar12 <= iVar1) {
        lVar12 = lround(dVar20);
        iVar6 = 1;
        if (1 < (int)lVar12) {
          lVar12 = lround(dVar20);
          iVar6 = (int)lVar12;
        }
      }
      iVar18 = iVar7 + iVar4 * -3;
      lVar12 = 0x31;
      wVar16 = y;
      do {
        wattrset(_stdscr,CRT_colors[lVar12]);
        iVar5 = wmove(_stdscr,wVar16,local_40);
        if (iVar5 != -1) {
          iVar5 = 0;
          if (-1 < iVar18) {
            iVar5 = iVar18;
          }
          if (iVar4 < iVar5) {
            iVar5 = iVar4;
          }
          iVar14 = (iVar6 - iVar7) + iVar18;
          if (iVar14 < 0) {
            iVar14 = 0;
          }
          if (iVar4 < iVar14) {
            iVar14 = iVar4;
          }
          waddnstr(_stdscr,ppcVar13[(int)(iVar5 * (uVar19 + 5) + iVar14)],-1);
        }
        wVar16 = wVar16 + L'\x01';
        iVar18 = iVar18 + iVar4;
        lVar12 = 0x32;
      } while (wVar16 != y + L'\x04');
      local_58 = local_58 + 2;
      local_40 = local_40 + 1;
    } while (local_58 < uVar17 - 1);
  }
  wattrset(_stdscr,*CRT_colors);
  return;
}

