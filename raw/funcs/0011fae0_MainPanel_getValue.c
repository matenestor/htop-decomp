/* MainPanel_getValue @ 0011fae0 size 40 */

/* DWARF original prototype: char * MainPanel_getValue(Panel * this, wchar_t i) */

char * MainPanel_getValue(Panel *this,wchar_t i)

{
  Object *a0;
  code *UNRECOVERED_JUMPTABLE;
  char *pcVar1;
  long in_RCX;
  long in_RDX;
  long in_R8;
  long in_R9;

  a0 = this->items->array[i];
  UNRECOVERED_JUMPTABLE = a0->klass[2].extends;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011fafe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (char *)(*UNRECOVERED_JUMPTABLE)((long)a0,(long)i,in_RDX,in_RCX,in_R8,in_R9);
    return pcVar1;
  }
  return ((char *)0x149c0c /* "" */);
}

