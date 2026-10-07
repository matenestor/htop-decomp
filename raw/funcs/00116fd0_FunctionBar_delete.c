/* FunctionBar_delete @ 00116fd0 size 136 */

/* DWARF original prototype: void FunctionBar_delete(FunctionBar * this) */

void FunctionBar_delete(FunctionBar *this)

{
  char **ppcVar1;
  long lVar2;

                    /* Unresolved local var: wchar_t i@[???] */
  lVar2 = 0;
  do {
    ppcVar1 = this->functions;
    if (*(void **)((long)ppcVar1 + lVar2) == (void *)0x0) goto LAB_00117002;
    free(*(void **)((long)ppcVar1 + lVar2));
    lVar2 = lVar2 + 8;
  } while (lVar2 != 0x78);
  ppcVar1 = this->functions;
LAB_00117002:
  free(ppcVar1);
  if (this->staticData == false) {
                    /* Unresolved local var: wchar_t i@[???] */
    lVar2 = 0;
    if (L'\0' < this->size) {
      do {
        ppcVar1 = (this->keys).keys + lVar2;
        lVar2 = lVar2 + 1;
        free(*ppcVar1);
      } while ((wchar_t)lVar2 < this->size);
    }
    free((this->keys).keys);
    free(this->events);
  }
  free(this);
  return;
}

