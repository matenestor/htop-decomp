/* Platform_setCPUValues @ 0013b5e0 size 1080 */

/* DWARF original prototype: double Platform_setCPUValues(Meter * this, uint cpu) */

double Platform_setCPUValues(Meter *this,uint cpu)

{
  long lVar1;
  char cVar2;
  _Bool _Var3;
  _Bool _Var4;
  Settings__2 *pSVar5;
  double *pdVar6;
  ulong uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  ulong uVar10;
  double *pdVar11;
  ulong uVar12;
  ulong uVar13;
  double dVar14;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  double dVar19;
  double dVar20;

  dVar19 = 1.0;
  pSVar5 = this->host->settings;
  lVar1 = this->host[1].iterationsRemaining + (ulong)cpu * 0xd8;
  uVar12 = *(ulong *)(lVar1 + 0x60);
  if (uVar12 == 0) {
LAB_0013b623:
    cVar2 = *(char *)(lVar1 + 0xd0);
    pdVar6 = this->values;
  }
  else {
    if (-1 < (long)uVar12) {
      dVar19 = (double)(long)uVar12;
      goto LAB_0013b623;
    }
    cVar2 = *(char *)(lVar1 + 0xd0);
    pdVar6 = this->values;
    dVar19 = (double)uVar12;
  }
  if (cVar2 == '\0') {
    this->curItems = '\0';
    return NAN;
  }
  uVar12 = *(ulong *)(lVar1 + 0x90);
  if ((long)uVar12 < 0) {
    uVar10 = *(ulong *)(lVar1 + 0x68);
    dVar14 = (double)uVar12;
    if (-1 < (long)uVar10) goto LAB_0013b665;
LAB_0013b7be:
    dVar20 = (double)uVar10;
  }
  else {
    dVar14 = (double)(long)uVar12;
    uVar10 = *(ulong *)(lVar1 + 0x68);
    if ((long)uVar10 < 0) goto LAB_0013b7be;
LAB_0013b665:
    dVar20 = (double)(long)uVar10;
  }
  auVar15._8_8_ = dVar20;
  auVar15._0_8_ = dVar14;
  _Var3 = pSVar5->detailedCPUTime;
  auVar16._8_8_ = dVar19;
  auVar16._0_8_ = dVar19;
  auVar16 = divpd(auVar15,auVar16);
  uVar12 = *(ulong *)(lVar1 + 0xb0);
  uVar10 = *(ulong *)(lVar1 + 0xb8);
  *pdVar6 = auVar16._0_8_ * 100.0;
  pdVar6[1] = auVar16._8_8_ * 100.0;
  if (_Var3 == false) {
    uVar7 = *(ulong *)(lVar1 + 0x78);
    if ((long)uVar7 < 0) {
      dVar14 = (double)uVar7;
      if (-1 < (long)(uVar12 + uVar10)) goto LAB_0013b83f;
LAB_0013b8ea:
      dVar20 = (double)(uVar12 + uVar10);
    }
    else {
      dVar14 = (double)(long)uVar7;
      if ((long)(uVar12 + uVar10) < 0) goto LAB_0013b8ea;
LAB_0013b83f:
      dVar20 = (double)(long)(uVar12 + uVar10);
    }
    auVar18._8_8_ = dVar20;
    auVar18._0_8_ = dVar14;
    uVar12 = 4;
    auVar9._8_8_ = dVar19;
    auVar9._0_8_ = dVar19;
    auVar16 = divpd(auVar18,auVar9);
    pdVar6[2] = auVar16._0_8_ * 100.0;
    pdVar6[3] = auVar16._8_8_ * 100.0;
    this->curItems = '\x04';
LAB_0013b869:
                    /* Unresolved local var: double sum@[???] */
    dVar14 = 0.0;
                    /* Unresolved local var: size_t i@[???] */
    pdVar11 = pdVar6;
    do {
      if (0.0 < *pdVar11) {
        dVar14 = dVar14 + *pdVar11;
      }
      pdVar11 = pdVar11 + 1;
    } while (pdVar6 + uVar12 != pdVar11);
    if (100.0 <= dVar14) {
      dVar14 = 100.0;
    }
    if (_Var3 == false) goto LAB_0013b8a4;
  }
  else {
    uVar7 = *(ulong *)(lVar1 + 0x70);
    if ((long)uVar7 < 0) {
      uVar13 = *(ulong *)(lVar1 + 0xa0);
      dVar14 = (double)uVar7;
      if (-1 < (long)uVar13) goto LAB_0013b6cb;
LAB_0013b93a:
      dVar20 = (double)uVar13;
    }
    else {
      dVar14 = (double)(long)uVar7;
      uVar13 = *(ulong *)(lVar1 + 0xa0);
      if ((long)uVar13 < 0) goto LAB_0013b93a;
LAB_0013b6cb:
      dVar20 = (double)(long)uVar13;
    }
    auVar17._8_8_ = dVar20;
    auVar17._0_8_ = dVar14;
    uVar7 = *(ulong *)(lVar1 + 0xa8);
    auVar8._8_8_ = dVar19;
    auVar8._0_8_ = dVar19;
    auVar16 = divpd(auVar17,auVar8);
    pdVar6[2] = auVar16._0_8_ * 100.0;
    pdVar6[3] = auVar16._8_8_ * 100.0;
    pdVar6[4] = ((double)uVar7 / dVar19) * 100.0;
    this->curItems = '\x05';
    pdVar6[5] = ((double)uVar12 / dVar19) * 100.0;
    _Var4 = pSVar5->accountGuestInCPUMeter;
    pdVar6[6] = ((double)uVar10 / dVar19) * 100.0;
    if (_Var4 != false) {
      this->curItems = '\a';
      uVar12 = 7;
      pdVar6[7] = ((double)*(ulong *)(lVar1 + 0x98) / dVar19) * 100.0;
      goto LAB_0013b869;
    }
    uVar12 = (ulong)this->curItems;
    dVar14 = 0.0;
    pdVar6[7] = ((double)*(ulong *)(lVar1 + 0x98) / dVar19) * 100.0;
    if (uVar12 != 0) goto LAB_0013b869;
  }
  this->curItems = '\b';
LAB_0013b8a4:
  pdVar6[8] = *(double *)(lVar1 + 0xc0);
  pdVar6[9] = *(double *)(lVar1 + 200);
  return dVar14;
}

