/* EnvScreen_scan @ 0011f7f0 size 269 */

/* DWARF original prototype: void EnvScreen_scan(InfoScreen * this) */

void EnvScreen_scan(InfoScreen *this)

{
  wchar_t wVar1;
  char *line;
  char cVar2;
  wchar_t wVar3;
  Panel *a0;
  Process *pPVar4;
  code *UNRECOVERED_JUMPTABLE;
  char *__ptr;
  size_t sVar5;
  long in_RCX;
  long in_R8;
  long in_R9;
  wchar_t wVar6;

  a0 = this->display;
  wVar6 = a0->selected;
  if (wVar6 < L'\0') {
    wVar6 = L'\0';
  }
  Vector_prune(a0->items);
  pPVar4 = this->process;
  a0->needsRedraw = true;
  a0->selected = L'\0';
  a0->oldSelected = L'\0';
  a0->scrollV = L'\0';
  __ptr = Platform_getProcessEnv((pPVar4->super).id);
  if (__ptr == (char *)0x0) {
    InfoScreen_addLine(this,((char *)0x14b1e8 /* "Could not read process environment." */));
  }
  else {
                    /* Unresolved local var: char * p@[???] */
    cVar2 = *__ptr;
    line = __ptr;
    while (cVar2 != '\0') {
      InfoScreen_addLine(this,line);
      sVar5 = strlen(line);
      line = line + sVar5 + 1;
      cVar2 = *line;
    }
    free(__ptr);
  }
  Vector_insertionSort(this->lines);
  Vector_insertionSort(a0->items);
                    /* Unresolved local var: wchar_t size@[???] */
  wVar3 = a0->items->items;
  wVar1 = wVar3 + L'\xffffffff';
  if (wVar3 <= wVar6) {
    wVar6 = wVar1;
  }
  if (wVar6 < L'\0') {
    wVar6 = L'\0';
  }
  UNRECOVERED_JUMPTABLE = (a0->super).klass[1].extends;
  a0->selected = wVar6;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011f8d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)((long)a0,0xffffffff,(ulong)(uint)wVar1,in_RCX,in_R8,in_R9);
    return;
  }
  return;
}

