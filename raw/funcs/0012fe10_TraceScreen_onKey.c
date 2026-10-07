/* TraceScreen_onKey @ 0012fe10 size 164 */

_Bool TraceScreen_onKey(TraceScreen_ *super,wchar_t ch)

{
  _Bool *p_Var1;
  Panel *a0;
  code *pcVar2;
  _Bool _Var3;
  wchar_t wVar4;
  long in_RCX;
  char *text;
  long a2;
  RichString *pRVar5;
  long in_R8;
  long in_R9;

  if (ch == L'Đ') {
LAB_0012fe80:
    p_Var1 = &super->follow;
    *p_Var1 = (_Bool)(*p_Var1 ^ 1);
    if (*p_Var1 != false) {
      a0 = (super->super).display;
                    /* Unresolved local var: wchar_t size@[???] */
      wVar4 = a0->items->items + L'\xffffffff';
      if (wVar4 < L'\0') {
        wVar4 = L'\0';
      }
      a0->selected = wVar4;
      pcVar2 = (a0->super).klass[1].extends;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)((long)a0,0xffffffff,0,in_RCX,in_R8,in_R9);
      }
    }
LAB_0012fe79:
    _Var3 = true;
  }
  else {
    if (ch < L'đ') {
      if (ch == L'f') goto LAB_0012fe80;
      if (ch == L't') goto LAB_0012fe48;
    }
    else if (ch == L'đ') {
LAB_0012fe48:
      p_Var1 = &super->tracing;
      *p_Var1 = (_Bool)(*p_Var1 ^ 1);
      pRVar5 = (RichString *)0x111;
      text = ((char *)0x149019 /* "Resume Tracing " */);
      if (*p_Var1 != false) {
        text = ((char *)0x149009 /* "Stop Tracing   " */);
      }
      FunctionBar_setLabel(((super->super).display)->defaultBar,L'đ',text);
      (*(super->super).super.klass[1].display)((Object *)super,pRVar5,a2,in_RCX,in_R8,in_R9);
      goto LAB_0012fe79;
    }
    super->follow = false;
    _Var3 = false;
  }
  return _Var3;
}

