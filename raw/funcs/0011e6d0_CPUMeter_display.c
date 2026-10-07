/* CPUMeter_display @ 0011e6d0 size 2136 */

void CPUMeter_display(Meter_ *cast,RichString *out)

{
  long lVar1;
  wint_t __wc;
  wchar_t wVar2;
  long lVar3;
  wchar_t wVar4;
  wchar_t wVar5;
  int iVar6;
  double *pdVar7;
  ulong uVar8;
  char *fmt;
  cchar_t *pcVar9;
  undefined1 **ppuVar10;
  undefined1 **ppuVar11;
  undefined1 **ppuVar12;
  undefined1 *puVar13;
  long lVar14;
  long lVar15;
  long in_FS_OFFSET;
  double va0;
  undefined1 *local_b8;
  uint local_ac;
  undefined1 *local_a8;
  undefined1 *local_a0;
  undefined1 *local_98;
  Settings__2 *local_90;
  char cpuFrequencyBuffer [10];
  char buffer [50];

  ppuVar10 = &local_b8;
  ppuVar12 = &local_b8;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  local_90 = cast->host->settings;
  if (cast->host->existingCPUs < cast->param) {
    RichString_appendAscii(out,CRT_colors[0xd],((char *)0x147648 /* " absent" */));
    ppuVar12 = &local_b8;
  }
  else if (cast->curItems == '\0') {
    RichString_appendAscii(out,CRT_colors[0xd],((char *)0x147650 /* " offline" */));
    ppuVar12 = &local_b8;
  }
  else {
    wVar4 = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),cast->values[1]);
    local_98._0_4_ = wVar4;
    RichString_appendAscii(out,CRT_colors[0xe],((char *)0x147583 /* ":" */));
    RichString_appendnAscii(out,CRT_colors[0x4c],buffer,(wchar_t)local_98);
    if (local_90->detailedCPUTime == false) {
      local_98._0_4_ = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),cast->values[2]);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14767e /* "sys:" */));
      RichString_appendnAscii(out,CRT_colors[0x4d],buffer,(wchar_t)local_98);
      wVar4 = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),*cast->values);
      local_98 = (undefined1 *)CONCAT44(local_98._4_4_,wVar4);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x147683 /* "low:" */));
      RichString_appendnAscii(out,CRT_colors[0x4b],buffer,(wchar_t)local_98);
      if (0.0 <= cast->values[3]) {
        wVar4 = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),cast->values[3]);
        RichString_appendAscii(out,CRT_colors[0xe],((char *)0x147688 /* "vir:" */));
        RichString_appendnAscii(out,CRT_colors[0x52],buffer,wVar4);
      }
    }
    else {
      local_98._0_4_ = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),cast->values[2]);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x147662 /* "sy:" */));
      RichString_appendnAscii(out,CRT_colors[0x4d],buffer,(wchar_t)local_98);
      local_98._0_4_ = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),*cast->values);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x147666 /* "ni:" */));
      RichString_appendnAscii(out,CRT_colors[0x4b],buffer,(wchar_t)local_98);
      local_98._0_4_ = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),cast->values[3]);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14766a /* "hi:" */));
      RichString_appendnAscii(out,CRT_colors[0x4f],buffer,(wchar_t)local_98);
      wVar4 = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),cast->values[4]);
      local_98 = (undefined1 *)CONCAT44(local_98._4_4_,wVar4);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14766e /* "si:" */));
      RichString_appendnAscii(out,CRT_colors[0x50],buffer,(wchar_t)local_98);
      pdVar7 = cast->values;
      if (0.0 <= pdVar7[5]) {
        wVar4 = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),pdVar7[5]);
        local_98 = (undefined1 *)CONCAT44(local_98._4_4_,wVar4);
        RichString_appendAscii(out,CRT_colors[0xe],((char *)0x147672 /* "st:" */));
        RichString_appendnAscii(out,CRT_colors[0x51],buffer,(wchar_t)local_98);
        pdVar7 = cast->values;
      }
      if (0.0 <= pdVar7[6]) {
        wVar4 = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),pdVar7[6]);
        local_98 = (undefined1 *)CONCAT44(local_98._4_4_,wVar4);
        RichString_appendAscii(out,CRT_colors[0xe],((char *)0x147676 /* "gu:" */));
        RichString_appendnAscii(out,CRT_colors[0x52],buffer,(wchar_t)local_98);
        pdVar7 = cast->values;
      }
      wVar4 = xSnprintf(buffer,0x32,((char *)0x147659 /* "%5.1f%% " */),pdVar7[7]);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14767a /* "wa:" */));
      RichString_appendnAscii(out,CRT_colors[0x4e],buffer,wVar4);
    }
    ppuVar11 = &local_b8;
    if (local_90->showCPUFrequency != false) {
                    /* Unresolved local var: double cpuFrequency@[???] */
      if (0.0 <= cast->values[8]) {
        wVar4 = xSnprintf(cpuFrequencyBuffer,10,((char *)0x14768d /* "%4uMHz " */),(int)(long)cast->values[8]);
      }
      else {
        wVar4 = xSnprintf(cpuFrequencyBuffer,10,((char *)0x147695 /* "N/A     " */));
      }
      local_98 = (undefined1 *)CONCAT44(local_98._4_4_,wVar4);
      RichString_appendAscii(out,CRT_colors[0xe],((char *)0x14769e /* "freq: " */));
                    /* Unresolved local var: wchar_t[88534] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
      wVar4 = out->chlen;
      local_b8 = (undefined1 *)&local_b8;
      iVar6 = (wchar_t)local_98 + 1;
      local_a8 = (undefined1 *)CONCAT44(local_a8._4_4_,CRT_colors[0xf]);
      uVar8 = (long)iVar6 * 4 + 0xf;
      ppuVar11 = &local_b8;
      while (ppuVar10 != (undefined1 **)((long)&local_b8 - (uVar8 & 0xfffffffffffff000))) {
        ppuVar12 = (undefined1 **)((long)ppuVar11 + -0x1000);
        *(undefined8 *)((long)ppuVar11 + -8) = *(undefined8 *)((long)ppuVar11 + -8);
        ppuVar10 = (undefined1 **)((long)ppuVar11 + -0x1000);
        ppuVar11 = (undefined1 **)((long)ppuVar11 + -0x1000);
      }
      uVar8 = (ulong)((uint)uVar8 & 0xff0);
      lVar14 = -uVar8;
      if (uVar8 != 0) {
        *(undefined8 *)((long)ppuVar12 + -8) = *(undefined8 *)((long)ppuVar12 + -8);
      }
      uVar8 = (ulong)(wchar_t)local_98;
      *(undefined8 *)((long)ppuVar12 + lVar14 + -8) = 0x11ea5d;
      local_98 = (undefined1 *)((long)ppuVar12 + lVar14);
      uVar8 = __mbstowcs_chk((int *)((long)ppuVar12 + lVar14),cpuFrequencyBuffer,uVar8,
                             (long)iVar6 & 0x3fffffffffffffff);
      ppuVar11 = (undefined1 **)local_b8;
      if (0 < (int)uVar8) {
        wVar5 = (int)uVar8 + wVar4;
        lVar15 = (long)wVar4;
        local_a0 = (undefined1 *)CONCAT44(local_a0._4_4_,wVar5);
        *(undefined8 *)((long)ppuVar12 + lVar14 + -8) = 0x11ea7b;
        RichString_setLen(out,wVar5);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
        local_ac = (uint)local_a8 & 0xffffff;
        local_a8 = local_98 + lVar15 * -4;
        pcVar9 = out->chptr + lVar15;
        do {
          __wc = *(wint_t *)(local_a8 + lVar15 * 4);
          local_98 = (undefined1 *)CONCAT44(local_98._4_4_,__wc);
          *(undefined8 *)((long)ppuVar12 + lVar14 + -8) = 0x11ead8;
          iVar6 = iswprint(__wc);
          pcVar9->attr = 0;
          pcVar9->chars[0] = L'\0';
          pcVar9->chars[1] = L'\0';
          pcVar9->chars[2] = L'\0';
          wVar4 = (wchar_t)local_98;
          if (iVar6 == 0) {
            wVar4 = L'�';
          }
          *(undefined1 (*) [16])(pcVar9->chars + 2) = (undefined1  [16])0x0;
          lVar15 = lVar15 + 1;
          pcVar9->chars[0] = wVar4;
          pcVar9->attr = local_ac;
          ppuVar11 = (undefined1 **)local_b8;
          pcVar9 = pcVar9 + 1;
        } while ((int)lVar15 < (int)local_a0);
      }
    }
    ppuVar12 = ppuVar11;
    if (local_90->showCPUTemperature != false) {
                    /* Unresolved local var: double cpuTemperature@[???] */
      va0 = cast->values[9];
      if (NAN(va0)) {
        *(undefined8 *)((long)ppuVar11 + -8) = 0x11ef55;
        wVar4 = xSnprintf(cpuFrequencyBuffer,10,((char *)0x1474de /* "N/A" */));
      }
      else {
        fmt = ((char *)0x1476ae /* "%5.1f%sC" */);
        if (local_90->degreeFahrenheit != false) {
          fmt = ((char *)0x1476a5 /* "%5.1f%sF" */);
          va0 = (va0 * 9.0) / 5.0 + 32.0;
        }
        *(undefined8 *)((long)ppuVar11 + -8) = 0x11eb7a;
        wVar4 = xSnprintf(cpuFrequencyBuffer,10,fmt,va0,CRT_degreeSign);
      }
      wVar5 = CRT_colors[0xe];
      *(undefined8 *)((long)ppuVar11 + -8) = 0x11eb93;
      RichString_appendAscii(out,wVar5,((char *)0x1476b7 /* "temp:" */));
                    /* Unresolved local var: wchar_t[89094] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
      local_98 = (undefined1 *)ppuVar11;
      wVar5 = out->chlen;
      lVar14 = (long)wVar5;
      wVar2 = CRT_colors[0xf];
      uVar8 = (long)(wVar4 + L'\x01') * 4 + 0xf;
      puVar13 = (undefined1 *)((long)ppuVar11 + -(uVar8 & 0xfffffffffffff000));
      for (; ppuVar11 != (undefined1 **)puVar13;
          ppuVar11 = (undefined1 **)((long)ppuVar11 + -0x1000)) {
        *(undefined8 *)((long)ppuVar11 + -8) = *(undefined8 *)((long)ppuVar11 + -8);
      }
      uVar8 = (ulong)((uint)uVar8 & 0xff0);
      lVar15 = -uVar8;
      if (uVar8 != 0) {
        *(undefined8 *)((long)ppuVar11 + -8) = *(undefined8 *)((long)ppuVar11 + -8);
      }
      local_a0 = (undefined1 *)((long)ppuVar11 + lVar15);
      *(undefined8 *)((long)ppuVar11 + lVar15 + -8) = 0x11ee8b;
      uVar8 = __mbstowcs_chk((int *)((long)ppuVar11 + lVar15),cpuFrequencyBuffer,(long)wVar4,
                             (long)(wVar4 + L'\x01') & 0x3fffffffffffffff);
      ppuVar12 = (undefined1 **)local_98;
      if (0 < (int)uVar8) {
        wVar5 = wVar5 + (int)uVar8;
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
        local_90 = (Settings__2 *)CONCAT44(local_90._4_4_,wVar5);
        *(undefined8 *)((long)ppuVar11 + lVar15 + -8) = 0x11eeab;
        RichString_setLen(out,wVar5);
        puVar13 = local_a0;
        lVar1 = lVar14 * -4;
        pcVar9 = out->chptr + lVar14;
        do {
          wVar4 = *(wchar_t *)(puVar13 + lVar14 * 4 + lVar1);
          *(undefined8 *)((long)ppuVar11 + lVar15 + -8) = 0x11eedc;
          iVar6 = iswprint(wVar4);
          pcVar9->attr = 0;
          pcVar9->chars[0] = L'\0';
          pcVar9->chars[1] = L'\0';
          pcVar9->chars[2] = L'\0';
          if (iVar6 == 0) {
            wVar4 = L'�';
          }
          pcVar9->attr = wVar2 & 0xffffff;
          lVar14 = lVar14 + 1;
          *(undefined1 (*) [16])(pcVar9->chars + 2) = (undefined1  [16])0x0;
          pcVar9->chars[0] = wVar4;
          pcVar9 = pcVar9 + 1;
          ppuVar12 = (undefined1 **)local_98;
        } while ((int)lVar14 < (int)local_90);
      }
    }
  }
  if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)((long)ppuVar12 + -8) = &UNK_0011ef62;
  __stack_chk_fail();
}

