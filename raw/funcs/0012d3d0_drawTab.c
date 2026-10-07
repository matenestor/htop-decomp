/* drawTab @ 0012d3d0 size 376 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool drawTab(wchar_t *y,wchar_t *x,wchar_t l,char *name,_Bool cur)

{
  int iVar1;
  int iVar2;
  wchar_t wVar3;
  size_t sVar4;
  long lVar5;

                    /* Unresolved local var: wchar_t nameLen@[???]
                       Unresolved local var: wchar_t n@[???] */
  lVar5 = (-(ulong)!cur & 0xfffffffffffffff8) + 0x158;
  wattrset(_stdscr,*(int *)((long)CRT_colors + lVar5));
  iVar1 = wmove(_stdscr,*y,*x);
  if (iVar1 != -1) {
    waddch(_stdscr,0x5b);
  }
  wVar3 = *x + L'\x01';
  *x = wVar3;
  if (wVar3 < l) {
    sVar4 = strlen(name);
    iVar1 = (int)sVar4;
    if (l - wVar3 <= (int)sVar4) {
      iVar1 = l - wVar3;
    }
    wattrset(_stdscr,*(int *)((long)CRT_colors + (-(ulong)!cur & 0xfffffffffffffff8) + 0x15c));
    iVar2 = wmove(_stdscr,*y,*x);
    if (iVar2 == -1) {
      wVar3 = iVar1 + *x;
      *x = wVar3;
    }
    else {
      waddnstr(_stdscr,name,iVar1);
      wVar3 = iVar1 + *x;
      *x = wVar3;
    }
    if (wVar3 < l) {
      wattrset(_stdscr,*(int *)((long)CRT_colors + lVar5));
      iVar1 = wmove(_stdscr,*y,*x);
      if (iVar1 == -1) {
        wVar3 = *x + L'\x02';
        *x = wVar3;
      }
      else {
        waddch(_stdscr,0x5d);
        wVar3 = *x + L'\x02';
        *x = wVar3;
      }
      return wVar3 < l;
    }
  }
  return false;
}

