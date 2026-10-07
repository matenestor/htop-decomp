/* Vector_indexOf @ 0012e6f0 size 95 */

/* DWARF original prototype: wchar_t Vector_indexOf(Vector * this, void * search_, Object_Compare
   compare) */

wchar_t Vector_indexOf(Vector *this,void *search_,Object_Compare compare)

{
  wchar_t wVar1;
  long in_RCX;
  Object_Compare a2;
  Object_Compare extraout_RDX;
  long lVar2;
  long in_R8;
  long in_R9;

                    /* Unresolved local var: wchar_t i@[???] */
  if (this->items < L'\x01') {
    return L'\xffffffff';
  }
  lVar2 = 0;
  a2 = compare;
  do {
                    /* Unresolved local var: Object * o@[???] */
    wVar1 = (*compare)(search_,this->array[lVar2],(long)a2,in_RCX,in_R8,in_R9);
    if (wVar1 == L'\0') {
      return (wchar_t)lVar2;
    }
    lVar2 = lVar2 + 1;
    a2 = extraout_RDX;
  } while ((wchar_t)lVar2 < this->items);
  return L'\xffffffff';
}

