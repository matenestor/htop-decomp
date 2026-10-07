/* Process_compareByParent @ 00122d10 size 188 */

wchar_t Process_compareByParent(Row_3 *r1,Row_3 *r2)

{
  _Bool _Var1;
  uint uVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  wchar_t wVar5;

  _Var1 = r2->isRoot;
  if (r1->isRoot == false) {
    wVar3 = r1->group;
    wVar5 = wVar3;
    if (r1->id == wVar3) {
      wVar5 = r1->parent;
      uVar2 = (uint)(L'\0' < wVar5);
      wVar4 = L'\0';
      if (_Var1 == false) goto LAB_00122d58;
      goto LAB_00122d37;
    }
    if (_Var1 != false) {
      uVar2 = (uint)(L'\0' < wVar3);
      wVar4 = L'\0';
      goto LAB_00122d37;
    }
LAB_00122d58:
    wVar4 = r2->group;
    if (wVar4 != r2->id) {
      uVar2 = (uint)(wVar4 < wVar5);
      wVar5 = wVar3;
      if (wVar3 == r1->id) goto LAB_00122d75;
      goto LAB_00122d37;
    }
    uVar2 = (uint)(r2->parent < wVar5);
    if (r1->id == wVar3) {
LAB_00122d75:
      wVar3 = r1->parent;
      wVar5 = wVar3;
      if (wVar4 != r2->id) goto LAB_00122d37;
    }
    wVar3 = uVar2 - (wVar3 < r2->parent);
  }
  else {
    if (_Var1 != false) goto LAB_00122d8c;
    wVar4 = r2->group;
    if (wVar4 == r2->id) {
      wVar4 = r2->parent;
    }
    uVar2 = (uint)wVar4 >> 0x1f;
    wVar5 = L'\0';
LAB_00122d37:
    wVar3 = uVar2 - (wVar5 < wVar4);
  }
  if (wVar3 != L'\0') {
    return wVar3;
  }
LAB_00122d8c:
  wVar3 = Process_compare(r1,r2);
  return wVar3;
}

