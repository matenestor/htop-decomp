/* Vector_compact @ 0012e5f0 size 184 */

/* DWARF original prototype: void Vector_compact(Vector * this) */

void Vector_compact(Vector *this)

{
  Object **ppOVar1;
  wchar_t wVar2;
  long lVar3;
  wchar_t wVar4;
  long lVar5;

  if (this->dirty_count < L'\x01') {
    return;
  }
  wVar2 = this->items;
  wVar4 = this->dirty_index;
  ppOVar1 = this->array;
  if (this->dirty_count == L'\x01') {
    memmove(ppOVar1 + wVar4,ppOVar1 + (long)wVar4 + 1,(long)((wVar2 - wVar4) + -1) << 3);
    wVar2 = this->items;
    this->array[(long)wVar2 + -1] = (Object *)0x0;
  }
  else {
                    /* Unresolved local var: wchar_t i@[???] */
    if (wVar4 + L'\x01' < wVar2) {
      lVar3 = (long)(wVar4 + L'\x01');
      do {
        if (ppOVar1[lVar3] != (Object *)0x0) {
          lVar5 = (long)wVar4;
          wVar4 = wVar4 + L'\x01';
          ppOVar1[lVar5] = ppOVar1[lVar3];
        }
        lVar3 = lVar3 + 1;
      } while ((wchar_t)lVar3 < wVar2);
    }
    memset(ppOVar1 + wVar4,0,(long)(wVar2 - wVar4) << 3);
    wVar2 = this->items;
  }
  this->items = wVar2 - this->dirty_count;
  this->dirty_index = L'\xffffffff';
  this->dirty_count = L'\0';
  return;
}

