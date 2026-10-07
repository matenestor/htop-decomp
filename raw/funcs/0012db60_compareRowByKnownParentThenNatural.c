/* compareRowByKnownParentThenNatural @ 0012db60 size 23 */

wchar_t compareRowByKnownParentThenNatural(void *v1,void *v2)

{
  wchar_t wVar1;
  long lVar2;
  long in_RCX;
  long in_RDX;
  long in_R8;
  long in_R9;

  if (*(code **)(*(long *)v1 + 0x48) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0012db70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    lVar2 = (**(code **)(*(long *)v1 + 0x48))((long)v1,(long)v2,in_RDX,in_RCX,in_R8,in_R9);
    return (wchar_t)lVar2;
  }
  wVar1 = Row_compareByParent_Base(v1,v2);
  return wVar1;
}

