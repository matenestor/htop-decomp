/* Panel_selectByTyping @ 001241a0 size 532 */

/* DWARF original prototype: HandlerResult Panel_selectByTyping(Panel * this, wchar_t ch) */

HandlerResult Panel_selectByTyping(Panel *this,wchar_t ch)

{
  char cVar1;
  wchar_t wVar2;
  wchar_t wVar3;
  Vector *pVVar4;
  Object **ppOVar5;
  code *pcVar6;
  int iVar7;
  ushort **ppuVar8;
  size_t sVar9;
  long lVar10;
  char *__s;
  wchar_t wVar11;
  char *pcVar12;
  ObjectClass *__s1;
  long in_R8;
  long in_R9;
  int local_50;

  wVar2 = this->items->items;
  if (ch == L'#') {
    return IGNORED;
  }
  __s = this->eventHandlerState;
  if (__s == (char *)0x0) {
                    /* Unresolved local var: void * data@[???] */
    __s = calloc(100,1);
    if (__s == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    this->eventHandlerState = __s;
  }
  if (0xfd < (uint)(ch + L'\xffffffff')) {
    if (ch == L'\xffffffff') {
      return IGNORED;
    }
    *__s = '\0';
    return IGNORED;
  }
  ppuVar8 = __ctype_b_loc();
  if (-1 < (short)(*ppuVar8)[ch]) {
    *__s = '\0';
    if (ch != L'\r') {
      return IGNORED;
    }
                    /* Unresolved local var: wchar_t len@[???] */
    return BREAK_LOOP;
  }
  sVar9 = strlen(__s);
  iVar7 = (int)sVar9;
  if (iVar7 == 0) {
    pcVar12 = __s;
    if (ch == L'/') {
      lVar10 = 1;
      ch = L'\x01';
    }
    else {
      if (ch == L'q') {
        return BREAK_LOOP;
      }
      lVar10 = 1;
    }
  }
  else if (iVar7 == 1) {
    pcVar12 = __s + (*__s != '\x01');
    lVar10 = (ulong)(*__s != '\x01') + 1;
  }
  else {
    if (0x62 < iVar7) goto LAB_00124276;
    pcVar12 = __s + iVar7;
    lVar10 = (long)iVar7 + 1;
  }
  *pcVar12 = (char)ch;
                    /* Unresolved local var: wchar_t try@[???] */
  __s[lVar10] = '\0';
  sVar9 = strlen(__s);
LAB_00124276:
  local_50 = 2;
  do {
                    /* Unresolved local var: wchar_t i@[???] */
    if (L'\0' < wVar2) {
                    /* Unresolved local var: char * cur@[???] */
      pVVar4 = this->items;
      lVar10 = 0;
      ppOVar5 = pVVar4->array;
      do {
        __s1 = ppOVar5[lVar10][1].klass;
        cVar1 = *(char *)&__s1->extends;
        while (cVar1 == ' ') {
          __s1 = (ObjectClass *)((long)&__s1->extends + 1);
          cVar1 = *(char *)&__s1->extends;
        }
        iVar7 = strncasecmp((char *)__s1,__s,(long)(int)sVar9);
        if (iVar7 == 0) {
                    /* Unresolved local var: wchar_t size@[???] */
          wVar3 = pVVar4->items;
          wVar2 = wVar3 + L'\xffffffff';
          wVar11 = wVar2;
          if ((wchar_t)lVar10 < wVar3) {
            wVar11 = (wchar_t)lVar10;
          }
          if (wVar11 < L'\0') {
            wVar11 = L'\0';
          }
          pcVar6 = (this->super).klass[1].extends;
          this->selected = wVar11;
          if (pcVar6 == (code *)0x0) {
            return HANDLED;
          }
          (*pcVar6)((long)this,0xffffffff,(ulong)(uint)wVar2,(ulong)(uint)wVar11,in_R8,in_R9);
          return HANDLED;
        }
        lVar10 = lVar10 + 1;
      } while (lVar10 != wVar2);
    }
    *__s = (char)ch;
    __s[1] = '\0';
    if (local_50 == 1) {
      return HANDLED;
    }
    sVar9 = strlen(__s);
    local_50 = 1;
  } while( true );
}

