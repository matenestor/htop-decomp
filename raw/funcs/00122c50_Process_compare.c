/* Process_compare @ 00122c50 size 170 */

wchar_t Process_compare(void *v1,void *v2)

{
  long lVar1;
  int iVar2;
  wchar_t wVar3;
  long lVar4;
  long in_RCX;
  ulong a2;
  long in_R8;
  long in_R9;

  lVar1 = *(long *)(**(long **)((long)v1 + 8) + 0x40);
  if (*(char *)(lVar1 + 0x34) == '\0') {
    a2 = (ulong)*(uint *)(lVar1 + 0x2c);
  }
  else {
    a2 = 1;
    if (*(char *)(lVar1 + 0x35) == '\0') {
      a2 = (ulong)*(uint *)(lVar1 + 0x30);
    }
  }
  if (*(code **)(*(long *)v1 + 0x50) == (code *)0x0) {
    wVar3 = Process_compareByKey_Base(v1,v2,(ProcessField)a2);
  }
  else {
    lVar4 = (**(code **)(*(long *)v1 + 0x50))((long)v1,(long)v2,a2,in_RCX,in_R8,in_R9);
    wVar3 = (wchar_t)lVar4;
  }
  if (wVar3 != L'\0') {
    iVar2 = *(int *)(lVar1 + 0x28);
    if (*(char *)(lVar1 + 0x34) == '\0') {
      iVar2 = *(int *)(lVar1 + 0x24);
    }
    if (iVar2 != 1) {
      wVar3 = -wVar3;
    }
    return wVar3;
  }
  return (uint)(*(int *)((long)v2 + 0x10) < *(int *)((long)v1 + 0x10)) -
         (uint)(*(int *)((long)v1 + 0x10) < *(int *)((long)v2 + 0x10));
}

