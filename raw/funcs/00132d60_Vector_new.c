/* Vector_new @ 00132d60 size 166 */

Vector * Vector_new(ObjectClass *type,_Bool owner,wchar_t size)

{
  Vector *pVVar1;
  Object **ppOVar2;
  size_t __nmemb;

  if (size == L'\xffffffff') {
    pVVar1 = malloc(0x28);
    if (pVVar1 == (Vector *)0x0) goto LAB_00132e06;
    pVVar1->growthRate = L'\n';
    size = L'\n';
    __nmemb = 10;
  }
  else {
                    /* Unresolved local var: void * data@[???] */
    pVVar1 = malloc(0x28);
    if (pVVar1 == (Vector *)0x0) goto LAB_00132e06;
    __nmemb = (size_t)size;
    pVVar1->growthRate = size;
                    /* Unresolved local var: void * data@[???] */
    if (__nmemb >> 0x3d != 0) goto LAB_00132e06;
  }
  ppOVar2 = calloc(__nmemb,8);
  if (ppOVar2 != (Object **)0x0) {
    pVVar1->array = ppOVar2;
    pVVar1->arraySize = size;
    pVVar1->items = L'\0';
    pVVar1->dirty_index = L'\xffffffff';
    pVVar1->type = type;
    pVVar1->owner = owner;
    pVVar1->dirty_count = L'\0';
    return pVVar1;
  }
LAB_00132e06:
                    /* WARNING: Subroutine does not return */
  fail();
}

