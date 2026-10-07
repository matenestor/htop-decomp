/* FunctionBar_drawExtra @ 00117060 size 517 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: wchar_t FunctionBar_drawExtra(FunctionBar * this, char * buffer,
   wchar_t attr, _Bool setCursor) */

wchar_t FunctionBar_drawExtra(FunctionBar *this,char *buffer,wchar_t attr,_Bool setCursor)

{
  int iVar1;
  size_t sVar2;
  int p2;
  wchar_t wVar3;
  long lVar4;
  long lVar5;
  wchar_t local_3c;

  wattrset(_stdscr,CRT_colors[2]);
  iVar1 = wmove(_stdscr,_LINES + -1,0);
  if (iVar1 != -1) {
    whline(_stdscr,0x20,_COLS);
  }
                    /* Unresolved local var: wchar_t i@[???] */
  if (this->size < L'\x01') {
    local_3c = L'\0';
  }
  else {
    local_3c = L'\0';
    lVar4 = 0;
    do {
      wattrset(_stdscr,CRT_colors[3]);
      iVar1 = wmove(_stdscr,_LINES + -1,local_3c);
      if (iVar1 != -1) {
        waddnstr(_stdscr,(this->keys).keys[lVar4],-1);
      }
      sVar2 = strlen((this->keys).keys[lVar4]);
      p2 = local_3c + (int)sVar2;
      wattrset(_stdscr,CRT_colors[2]);
      iVar1 = wmove(_stdscr,_LINES + -1,p2);
      if (iVar1 != -1) {
        waddnstr(_stdscr,this->functions[lVar4],-1);
      }
      lVar5 = lVar4 + 1;
      sVar2 = strlen(this->functions[lVar4]);
      local_3c = p2 + (int)sVar2;
      lVar4 = lVar5;
    } while ((wchar_t)lVar5 < this->size);
  }
  wVar3 = L'\0';
  if (buffer != (char *)0x0) {
    if (attr == L'\xffffffff') {
      wattrset(_stdscr,CRT_colors[2]);
    }
    else {
      wattrset(_stdscr,attr);
    }
    iVar1 = wmove(_stdscr,_LINES + -1,local_3c);
    if (iVar1 != -1) {
      waddnstr(_stdscr,buffer,-1);
    }
    sVar2 = strlen(buffer);
    wVar3 = local_3c + (int)sVar2;
    local_3c = wVar3;
  }
  wattrset(_stdscr,*CRT_colors);
  if (setCursor) {
    curs_set(1);
  }
  else {
    curs_set(0);
  }
  currentLen = local_3c;
  return wVar3;
}

