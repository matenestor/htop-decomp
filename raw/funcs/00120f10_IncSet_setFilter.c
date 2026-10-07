/* IncSet_setFilter @ 00120f10 size 66 */

/* DWARF original prototype: void IncSet_setFilter(IncSet * this, char * filter) */

void IncSet_setFilter(IncSet *this,char *filter)

{
  long lVar1;
  wchar_t wVar2;

                    /* Unresolved local var: size_t i@[???] */
  lVar1 = 0;
  do {
    if (filter[lVar1] == '\0') {
      wVar2 = (wchar_t)lVar1;
      goto LAB_00120f3d;
    }
    this->modes[1].buffer[lVar1] = filter[lVar1];
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x80);
  wVar2 = L'\x80';
LAB_00120f3d:
  this->modes[1].buffer[lVar1] = '\0';
  this->modes[1].index = wVar2;
  this->filtering = true;
  return;
}

