/* FunctionBar_append @ 00117290 size 174 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FunctionBar_append(char *buffer,wchar_t attr)

{
  int iVar1;
  size_t sVar2;

  if (attr == L'\xffffffff') {
    wattrset(_stdscr,CRT_colors[2]);
  }
  else {
    wattrset(_stdscr,attr);
  }
  iVar1 = wmove(_stdscr,_LINES + -1,currentLen + L'\x01');
  if (iVar1 != -1) {
    waddnstr(_stdscr,buffer,-1);
  }
  wattrset(_stdscr,*CRT_colors);
  sVar2 = strlen(buffer);
  currentLen = currentLen + L'\x01' + (int)sVar2;
  return;
}

