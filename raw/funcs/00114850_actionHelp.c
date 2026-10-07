/* actionHelp @ 00114850 size 3561 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Htop_Reaction actionHelp(State_2 *st)

{
  _Bool _Var1;
  wchar_t *pwVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  wchar_t wVar7;
  char *pcVar8;
  int iVar9;
  _Bool *p_Var10;

  iVar9 = 0;
  wclear(_stdscr);
  wattrset(_stdscr,CRT_colors[0x47]);
                    /* Unresolved local var: wchar_t i@[???] */
  if (1 < _LINES) {
    do {
      iVar3 = wmove(_stdscr,iVar9,0);
      if (iVar3 != -1) {
        whline(_stdscr,0x20,_COLS);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < _LINES + -1);
  }
  iVar9 = wmove(_stdscr,0,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)0x14a288 /* "htop 3.3.0 - (C) 2004-2019 Hisham Muhammad. (C) 2020-2024 htop dev team." */),-1);
  }
  iVar9 = wmove(_stdscr,1,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)0x14a2d8 /* "Released under the GNU GPLv2+. See \'man\' page for more info." */),-1);
  }
  wattrset(_stdscr,CRT_colors[1]);
  iVar9 = wmove(_stdscr,3,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)0x14702c /* "CPU usage bar: " */),-1);
  }
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)0x14703c /* "[" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x149c0c /* "" */),-1);
  wattrset(_stdscr,CRT_colors[0x4b]);
  waddnstr(_stdscr,((char *)0x147217 /* "low" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x4c]);
  waddnstr(_stdscr,((char *)0x14703e /* "normal" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x4d]);
  waddnstr(_stdscr,((char *)0x147045 /* "kernel" */),-1);
  if (st->host->settings->detailedCPUTime == false) {
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x52]);
    waddnstr(_stdscr,((char *)0x14705b /* "guest" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    pcVar8 = ((char *)0x1470cc /* "                  " */);
  }
  else {
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x4f]);
    waddnstr(_stdscr,((char *)0x147051 /* "irq" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x50]);
    waddnstr(_stdscr,((char *)0x14704c /* "soft-irq" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x51]);
    waddnstr(_stdscr,((char *)0x147055 /* "steal" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x52]);
    waddnstr(_stdscr,((char *)0x14705b /* "guest" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
    wattrset(_stdscr,CRT_colors[0x4e]);
    waddnstr(_stdscr,((char *)0x147061 /* "io-wait" */),-1);
    wattrset(_stdscr,CRT_colors[1]);
    pcVar8 = ((char *)0x1470dd /* " " */);
  }
  waddnstr(_stdscr,pcVar8,-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)0x147069 /* "used%" */),-1);
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)0x149a61 /* "]" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  iVar9 = wmove(_stdscr,4,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)0x14706f /* "Memory bar:    " */),-1);
  }
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)0x14703c /* "[" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x149c0c /* "" */),-1);
  wattrset(_stdscr,CRT_colors[0x33]);
  waddnstr(_stdscr,((char *)0x14707f /* "used" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x37]);
  waddnstr(_stdscr,((char *)0x147084 /* "shared" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x38]);
  waddnstr(_stdscr,((char *)0x14708b /* "compressed" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x35]);
  waddnstr(_stdscr,((char *)0x147096 /* "buffers" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x36]);
  waddnstr(_stdscr,((char *)0x14709e /* "cache" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1470d4 /* "          " */),-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)0x14707f /* "used" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)0x1470a4 /* "total" */),-1);
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)0x149a61 /* "]" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  iVar9 = wmove(_stdscr,5,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)0x1470aa /* "Swap bar:      " */),-1);
  }
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)0x14703c /* "[" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x149c0c /* "" */),-1);
  wattrset(_stdscr,CRT_colors[0x1a]);
  waddnstr(_stdscr,((char *)0x14707f /* "used" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x1b]);
  waddnstr(_stdscr,((char *)0x14709e /* "cache" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x1c]);
  waddnstr(_stdscr,((char *)0x1470ba /* "frontswap" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1470c4 /* "                          " */),-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)0x14707f /* "used" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1487c2 /* "/" */),-1);
  wattrset(_stdscr,CRT_colors[0x30]);
  waddnstr(_stdscr,((char *)0x1470a4 /* "total" */),-1);
  wattrset(_stdscr,CRT_colors[0x2f]);
  waddnstr(_stdscr,((char *)0x149a61 /* "]" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  iVar9 = wmove(_stdscr,7,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)0x14a318 /* "Type and layout of header meters are configurable in the setup screen." */),-1);
  }
  if ((CRT_colorScheme == COLORSCHEME_MONOCHROME) && (iVar9 = wmove(_stdscr,8,0), iVar9 != -1)) {
    waddnstr(_stdscr,((char *)0x14a360 /* "In monochrome, meters display as different chars, in order: |#*@$%&." */),-1);
  }
  iVar9 = wmove(_stdscr,9,0);
  if (iVar9 != -1) {
    waddnstr(_stdscr,((char *)0x1470df /* "Process state: " */),-1);
  }
  p_Var10 = &helpLeft[0].roInactive;
  iVar9 = 0;
  pcVar8 = ((char *)0x147018 /* "      #: " */);
  wattrset(_stdscr,CRT_colors[0x23]);
  waddnstr(_stdscr,((char *)0x1471ab /* "R" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1470ef /* ": running; " */),-1);
  wattrset(_stdscr,CRT_colors[0x1e]);
  waddnstr(_stdscr,((char *)0x14716d /* "S" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x1470fb /* ": sleeping; " */),-1);
  wattrset(_stdscr,CRT_colors[0x23]);
  waddnstr(_stdscr,((char *)0x149e7a /* "t" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x147108 /* ": traced/stopped; " */),-1);
  wattrset(_stdscr,CRT_colors[0x24]);
  waddnstr(_stdscr,((char *)0x149691 /* "Z" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x14711b /* ": zombie; " */),-1);
  wattrset(_stdscr,CRT_colors[0x24]);
  waddnstr(_stdscr,((char *)0x148783 /* "D" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  waddnstr(_stdscr,((char *)0x147126 /* ": disk sleep" */),-1);
  wattrset(_stdscr,CRT_colors[1]);
  _Var1 = readonly;
  do {
    iVar3 = iVar9 + 0xb;
    bVar6 = _Var1 & *p_Var10;
    if (bVar6 == 0) {
      wattrset(_stdscr,CRT_colors[1]);
      iVar4 = wmove(_stdscr,iVar3,10);
      if (iVar4 != -1) {
        waddnstr(_stdscr,*(char **)(p_Var10 + 8),-1);
      }
      wVar7 = CRT_colors[0x47];
    }
    else {
      wattrset(_stdscr,CRT_colors[0x48]);
      iVar4 = wmove(_stdscr,iVar3,10);
      if (iVar4 != -1) {
        waddnstr(_stdscr,*(char **)(p_Var10 + 8),-1);
      }
      wVar7 = CRT_colors[0x48];
    }
    wattrset(_stdscr,wVar7);
    iVar4 = wmove(_stdscr,iVar3,1);
    if (iVar4 != -1) {
      waddnstr(_stdscr,pcVar8,-1);
    }
    iVar4 = strcmp(pcVar8,((char *)0x147133 /* "      H: " */));
    pwVar2 = CRT_colors;
    if (iVar4 == 0) {
      if (bVar6 == 0) {
        wVar7 = CRT_colors[0x2a];
      }
      else {
        wVar7 = CRT_colors[0x48];
      }
      wattrset(_stdscr,wVar7);
      iVar3 = wmove(_stdscr,iVar3,0x21);
joined_r0x001152ab:
      if (iVar3 != -1) {
        waddnstr(_stdscr,((char *)0x1472b7 /* "threads" */),-1);
      }
    }
    else {
      iVar4 = strcmp(pcVar8,((char *)0x14713d /* "      K: " */));
      if (iVar4 == 0) {
        if (bVar6 == 0) {
          wVar7 = pwVar2[0x2a];
        }
        else {
          wVar7 = pwVar2[0x48];
        }
        wattrset(_stdscr,wVar7);
        iVar3 = wmove(_stdscr,iVar3,0x1b);
        goto joined_r0x001152ab;
      }
    }
    pcVar8 = *(char **)(p_Var10 + 0x10);
    p_Var10 = p_Var10 + 0x18;
    iVar9 = iVar9 + 1;
    if (pcVar8 == (char *)0x0) {
      p_Var10 = &helpRight[0].roInactive;
      pcVar8 = ((char *)0x147022 /* "  S-Tab: " */);
      iVar3 = 0;
      do {
        iVar4 = iVar3 + 0xb;
        if ((*p_Var10 == false) || (_Var1 == false)) {
          wattrset(_stdscr,CRT_colors[0x47]);
          iVar5 = wmove(_stdscr,iVar4,0x2b);
          if (iVar5 != -1) {
            waddnstr(_stdscr,pcVar8,-1);
          }
          wVar7 = CRT_colors[1];
        }
        else {
          wattrset(_stdscr,CRT_colors[0x48]);
          iVar5 = wmove(_stdscr,iVar4,0x2b);
          if (iVar5 != -1) {
            waddnstr(_stdscr,pcVar8,-1);
          }
          wVar7 = CRT_colors[0x48];
        }
        wattrset(_stdscr,wVar7);
        iVar4 = wmove(_stdscr,iVar4,0x34);
        if (iVar4 != -1) {
          waddnstr(_stdscr,*(char **)(p_Var10 + 8),-1);
        }
        pcVar8 = *(char **)(p_Var10 + 0x10);
        p_Var10 = p_Var10 + 0x18;
        iVar3 = iVar3 + 1;
      } while (pcVar8 != (char *)0x0);
      wattrset(_stdscr,CRT_colors[0x47]);
      if (iVar9 <= iVar3) {
        iVar9 = iVar3;
      }
      iVar9 = wmove(_stdscr,iVar9 + 0xc,0);
      if (iVar9 != -1) {
        waddnstr(_stdscr,((char *)0x147147 /* "Press any key to return." */),-1);
      }
      wattrset(_stdscr,CRT_colors[1]);
      wrefresh(_stdscr);
                    /* Unresolved local var: wchar_t ret@[???] */
      nocbreak();
      cbreak();
      nodelay(_stdscr,0);
      wgetch(_stdscr);
      halfdelay(*CRT_delay);
      wclear(_stdscr);
      return HTOP_REDRAW_BAR|HTOP_KEEP_FOLLOWING|HTOP_RECALCULATE;
    }
  } while( true );
}

