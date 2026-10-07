/* Row_compareByParent_Base @ 0012da80 size 194 */

wchar_t Row_compareByParent_Base(void *v1,void *v2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  wchar_t wVar5;
  uint uVar6;
  int iVar7;
  int iVar8;

  cVar1 = *(char *)((long)v2 + 0x1c);
  if (*(char *)((long)v1 + 0x1c) == '\0') {
    iVar8 = *(int *)((long)v1 + 0x14);
    iVar7 = iVar8;
    if (*(int *)((long)v1 + 0x10) == iVar8) {
      iVar7 = *(int *)((long)v1 + 0x18);
      uVar4 = (uint)(0 < iVar7);
      uVar6 = 0;
      if (cVar1 == '\0') goto LAB_0012dae0;
    }
    else if (cVar1 == '\0') {
LAB_0012dae0:
      uVar6 = *(uint *)((long)v2 + 0x14);
      if (uVar6 == *(uint *)((long)v2 + 0x10)) {
        bVar2 = *(int *)((long)v2 + 0x18) < iVar7;
        uVar4 = (uint)bVar2;
        uVar3 = (uint)bVar2;
        if (*(int *)((long)v1 + 0x10) == iVar8) {
LAB_0012dafd:
          uVar4 = uVar3;
          iVar8 = *(int *)((long)v1 + 0x18);
          iVar7 = iVar8;
          if (uVar6 != *(uint *)((long)v2 + 0x10)) goto LAB_0012daa7;
        }
        uVar6 = *(uint *)((long)v2 + 0x18);
        iVar7 = iVar8;
      }
      else {
        uVar4 = (uint)((int)uVar6 < iVar7);
        iVar7 = iVar8;
        uVar3 = uVar4;
        if (iVar8 == *(int *)((long)v1 + 0x10)) goto LAB_0012dafd;
      }
    }
    else {
      uVar4 = (uint)(0 < iVar8);
      uVar6 = 0;
    }
  }
  else {
    if (cVar1 != '\0') goto LAB_0012dab8;
    uVar6 = *(uint *)((long)v2 + 0x14);
    if (uVar6 == *(uint *)((long)v2 + 0x10)) {
      uVar6 = *(uint *)((long)v2 + 0x18);
    }
    uVar4 = uVar6 >> 0x1f;
    iVar7 = 0;
  }
LAB_0012daa7:
  wVar5 = uVar4 - (iVar7 < (int)uVar6);
  if (wVar5 != L'\0') {
    return wVar5;
  }
LAB_0012dab8:
                    /* Unresolved local var: Row * r1@[???]
                       Unresolved local var: Row * r2@[???] */
  return (uint)(*(int *)((long)v2 + 0x10) < *(int *)((long)v1 + 0x10)) -
         (uint)(*(int *)((long)v1 + 0x10) < *(int *)((long)v2 + 0x10));
}

