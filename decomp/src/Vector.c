#include "htop.h"

/* quickSort @ 0x12d260 */

void quickSort(Object **array,int left,int right,Object_Compare compare)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  Object **ppOVar1;
  ObjectClass **ppOVar2;
  int wVar3;
  long lVar4;
  Object *pOVar5;
  ulong a2;
  ulong extraout_RDX;
  int wVar6;
  long in_R8;
  long in_R9;
  Object *pOVar7;
  Object **ppOVar8;

                    /* Unresolved local var: int pivotIndex@[???]
                       Unresolved local var: int pivotNewIndex@[???] */
  if (left < right) {
                    /* Unresolved local var: Object * pivotValue@[???]
                       Unresolved local var: int storeIndex@[???]
                       Unresolved local var: Object * tmp@[???] */
    ppOVar1 = array + right;
    (*(int (*))(__fp - 0x44)) = left;
    do {
      pOVar7 = array[(right + (*(int (*))(__fp - 0x44))) / 2];
      array[(right + (*(int (*))(__fp - 0x44))) / 2] = *ppOVar1;
                    /* Unresolved local var: int i@[???] */
      a2 = (ulong)(uint)right;
      *ppOVar1 = pOVar7;
      wVar6 = (*(int (*))(__fp - 0x44));
      if ((*(int (*))(__fp - 0x44)) < right) {
        pOVar5 = (Object *)(long)(*(int (*))(__fp - 0x44));
        ppOVar8 = array + (long)pOVar5;
        ppOVar2 = &pOVar5->klass;
        do {
          wVar3 = (*(code *)(compare))(*ppOVar8,pOVar7,a2,(long)pOVar5,in_R8,in_R9);
          if (wVar3 < 1) {
                    /* Unresolved local var: Object * tmp@[???] */
            lVar4 = (long)wVar6;
            pOVar5 = *ppOVar8;
            wVar6 = wVar6 + 1;
            *ppOVar8 = array[lVar4];
            array[lVar4] = pOVar5;
          }
          ppOVar8 = ppOVar8 + 1;
          a2 = extraout_RDX;
        } while (array + (long)ppOVar2 + (ulong)(uint)(right - (*(int (*))(__fp - 0x44))) != ppOVar8);
                    /* Unresolved local var: Object * tmp@[???] */
        pOVar7 = *ppOVar1;
      }
      pOVar5 = array[wVar6];
      array[wVar6] = pOVar7;
      *ppOVar1 = pOVar5;
      quickSort(array,(*(int (*))(__fp - 0x44)),wVar6 + -1,compare);
      (*(int (*))(__fp - 0x44)) = wVar6 + 1;
    } while ((*(int (*))(__fp - 0x44)) < right);
  }
  return;
}


/* Vector_remove @ 0x12de20 */

/* DWARF original prototype: Object * Vector_remove(Vector * this, int idx) */

Object * Vector_remove(Vector *this,int idx)

{
  _Bool _Var1;
  Object *pOVar2;
  Object **a3;
  int wVar3;
  undefined4 in_register_00000034;
  Object **__src;
  long in_R8;
  long in_R9;

                    /* Unresolved local var: Object * removed@[???] */
  __src = (Object **)CONCAT44(in_register_00000034,idx);
  a3 = this->array;
                    /* Unresolved local var: Object * removed@[???] */
  wVar3 = this->items + -1;
  pOVar2 = a3[idx];
  this->items = wVar3;
  if (idx < wVar3) {
    __src = a3 + (long)idx + 1;
    memmove(a3 + idx,__src,(long)(wVar3 - idx) << 3);
    a3 = this->array;
    wVar3 = this->items;
  }
  _Var1 = this->owner;
  a3[wVar3] = (Object *)0x0;
  if (_Var1 == false) {
    return pOVar2;
  }
  (*(code *)(pOVar2->klass->delete))(pOVar2,(long)__src,(long)wVar3,(long)a3,in_R8,in_R9);
  return (Object *)0x0;
}


/* Vector_moveUp @ 0x12dfa0 */

/* DWARF original prototype: void Vector_moveUp(Vector * this, int idx) */

void Vector_moveUp(Vector *this,int idx)

{
  Object **ppOVar1;
  Object **ppOVar2;
  Object *pOVar3;

  if (idx != 0) {
                    /* Unresolved local var: Object * temp@[???] */
    ppOVar1 = this->array + (long)idx + -1;
    pOVar3 = *ppOVar1;
    ppOVar2 = this->array + (long)idx + -1;
    *ppOVar2 = ppOVar1[1];
    ppOVar2[1] = pOVar3;
  }
  return;
}


/* Vector_softRemove @ 0x12e220 */

/* DWARF original prototype: Object * Vector_softRemove(Vector * this, int idx) */

Object * Vector_softRemove(Vector *this,int idx)

{
  Object *pOVar1;
  long in_RCX;
  undefined4 in_register_00000034;
  long in_R8;
  long in_R9;

  pOVar1 = this->array[idx];
  if (pOVar1 == (Object *)0x0) {
    return (Object *)0x0;
  }
  this->array[idx] = (Object *)0x0;
  this->dirty_count = this->dirty_count + 1;
  if ((idx < this->dirty_index) || (this->dirty_index < 0)) {
    this->dirty_index = idx;
  }
  if (this->owner == false) {
    return pOVar1;
  }
  (*(code *)(pOVar1->klass->delete))
            (pOVar1,CONCAT44(in_register_00000034,idx),(long)pOVar1->klass,in_RCX,in_R8,in_R9);
  return (Object *)0x0;
}


/* Vector_quickSortCustomCompare @ 0x12e280 */

/* DWARF original prototype: void Vector_quickSortCustomCompare(Vector * this, Object_Compare
   compare) */

void Vector_quickSortCustomCompare(Vector *this,Object_Compare compare)

{
  quickSort(this->array,0,this->items + -1,compare);
  return;
}


/* Vector_delete @ 0x12e330 */

/* DWARF original prototype: void Vector_delete(Vector * this) */

void Vector_delete(Vector *this)

{
  Object *pOVar1;
  Object **__ptr;
  long in_RCX;
  ulong a2;
  ulong extraout_RDX;
  long lVar2;
  long in_RSI;
  long in_R8;
  long in_R9;

  __ptr = this->array;
                    /* Unresolved local var: int i@[???] */
  if ((this->owner != false) && (a2 = (ulong)(uint)this->items, 0 < this->items)) {
    lVar2 = 0;
    do {
      pOVar1 = __ptr[lVar2];
      if (pOVar1 != (Object *)0x0) {
        (*(code *)(pOVar1->klass->delete))(pOVar1,in_RSI,a2,in_RCX,in_R8,in_R9);
        __ptr = this->array;
        a2 = extraout_RDX;
      }
      lVar2 = lVar2 + 1;
    } while ((int)lVar2 < this->items);
  }
  free(__ptr);
  free(this);
  return;
}


/* Vector_prune @ 0x12e3c0 */

/* DWARF original prototype: void Vector_prune(Vector * this) */

void Vector_prune(Vector *this)

{
  Object *pOVar1;
  Object **__s;
  long in_RCX;
  ulong a2;
  ulong extraout_RDX;
  long lVar2;
  long in_RSI;
  long in_R8;
  long in_R9;

  __s = this->array;
                    /* Unresolved local var: int i@[???] */
  if ((this->owner != false) && (a2 = (ulong)(uint)this->items, 0 < this->items)) {
    lVar2 = 0;
    do {
      pOVar1 = __s[lVar2];
      if (pOVar1 != (Object *)0x0) {
        (*(code *)(pOVar1->klass->delete))(pOVar1,in_RSI,a2,in_RCX,in_R8,in_R9);
        __s = this->array;
        a2 = extraout_RDX;
      }
      lVar2 = lVar2 + 1;
    } while ((int)lVar2 < this->items);
  }
  this->dirty_count = 0;
  this->items = 0;
  this->dirty_index = -1;
  memset(__s,0,(long)this->arraySize << 3);
  return;
}


/* Vector_insertionSort @ 0x12e430 */

/* DWARF original prototype: void Vector_insertionSort(Vector * this) */

void Vector_insertionSort(Vector *this)

{
  Object **ppOVar1;
  Object_Compare p_Var2;
  Object *pOVar3;
  int wVar4;
  Object **ppOVar5;
  long in_RCX;
  ulong uVar6;
  ulong uVar7;
  ulong extraout_RDX;
  ulong uVar8;
  long in_R8;
  long in_R9;
  ulong uVar9;

  ppOVar1 = this->array;
  p_Var2 = this->type->compare;
  uVar6 = (ulong)(uint)(this->items + -1);
                    /* Unresolved local var: int i@[???] */
  if (1 < this->items) {
    uVar9 = 0;
    uVar7 = uVar6;
    do {
                    /* Unresolved local var: Object * t@[???]
                       Unresolved local var: int j@[???] */
      pOVar3 = ppOVar1[uVar9 + 1];
      uVar8 = uVar9;
      do {
        wVar4 = (*(code *)(p_Var2))(ppOVar1[uVar8],pOVar3,uVar7,in_RCX,in_R8,in_R9);
        uVar7 = extraout_RDX;
        if (wVar4 < 1) {
          ppOVar5 = ppOVar1 + ((int)uVar8 + 1);
          break;
        }
        ppOVar1[uVar8 + 1] = ppOVar1[uVar8];
        uVar8 = uVar8 - 1;
        ppOVar5 = ppOVar1;
      } while ((int)uVar8 != -1);
      *ppOVar5 = pOVar3;
      uVar9 = uVar9 + 1;
    } while (uVar6 != uVar9);
  }
  return;
}


/* Vector_take @ 0x12e4d0 */

/* DWARF original prototype: Object * Vector_take(Vector * this, int idx) */

Object * Vector_take(Vector *this,int idx)

{
  Object *pOVar1;
  Object **ppOVar2;
  int wVar3;

  ppOVar2 = this->array;
  wVar3 = this->items + -1;
  pOVar1 = ppOVar2[idx];
  this->items = wVar3;
  if (idx < wVar3) {
    memmove(ppOVar2 + idx,ppOVar2 + (long)idx + 1,(long)(wVar3 - idx) << 3);
    ppOVar2 = this->array;
    wVar3 = this->items;
  }
  ppOVar2[wVar3] = (Object *)0x0;
  return pOVar1;
}


/* Vector_compact @ 0x12e5f0 */

/* DWARF original prototype: void Vector_compact(Vector * this) */

void Vector_compact(Vector *this)

{
  Object **ppOVar1;
  int wVar2;
  long lVar3;
  int wVar4;
  long lVar5;

  if (this->dirty_count < 1) {
    return;
  }
  wVar2 = this->items;
  wVar4 = this->dirty_index;
  ppOVar1 = this->array;
  if (this->dirty_count == 1) {
    memmove(ppOVar1 + wVar4,ppOVar1 + (long)wVar4 + 1,(long)((wVar2 - wVar4) + -1) << 3);
    wVar2 = this->items;
    this->array[(long)wVar2 + -1] = (Object *)0x0;
  }
  else {
                    /* Unresolved local var: int i@[???] */
    if (wVar4 + 1 < wVar2) {
      lVar3 = (long)(wVar4 + 1);
      do {
        if (ppOVar1[lVar3] != (Object *)0x0) {
          lVar5 = (long)wVar4;
          wVar4 = wVar4 + 1;
          ppOVar1[lVar5] = ppOVar1[lVar3];
        }
        lVar3 = lVar3 + 1;
      } while ((int)lVar3 < wVar2);
    }
    memset(ppOVar1 + wVar4,0,(long)(wVar2 - wVar4) << 3);
    wVar2 = this->items;
  }
  this->items = wVar2 - this->dirty_count;
  this->dirty_index = -1;
  this->dirty_count = 0;
  return;
}


/* Vector_moveDown @ 0x12e6c0 */

/* DWARF original prototype: void Vector_moveDown(Vector * this, int idx) */

void Vector_moveDown(Vector *this,int idx)

{
  Object **ppOVar1;
  Object *pOVar2;

  if (this->items + -1 != idx) {
    ppOVar1 = this->array + idx;
    pOVar2 = *ppOVar1;
    *ppOVar1 = ppOVar1[1];
    ppOVar1[1] = pOVar2;
  }
  return;
}


/* Vector_indexOf @ 0x12e6f0 */

/* DWARF original prototype: int Vector_indexOf(Vector * this, void * search_, Object_Compare
   compare) */

int Vector_indexOf(Vector *this,void *search_,Object_Compare compare)

{
  int wVar1;
  long in_RCX;
  Object_Compare a2;
  Object_Compare extraout_RDX;
  long lVar2;
  long in_R8;
  long in_R9;

                    /* Unresolved local var: int i@[???] */
  if (this->items < 1) {
    return -1;
  }
  lVar2 = 0;
  a2 = compare;
  do {
                    /* Unresolved local var: Object * o@[???] */
    wVar1 = (*(code *)(compare))(search_,this->array[lVar2],(long)a2,in_RCX,in_R8,in_R9);
    if (wVar1 == 0) {
      return (int)lVar2;
    }
    lVar2 = lVar2 + 1;
    a2 = extraout_RDX;
  } while ((int)lVar2 < this->items);
  return -1;
}


/* Vector_new @ 0x132d60 */

Vector * Vector_new(ObjectClass *type,_Bool owner,int size)

{
  Vector *pVVar1;
  Object **ppOVar2;
  size_t __nmemb;

  if (size == -1) {
    pVVar1 = malloc(0x28);
    if (pVVar1 == (Vector *)0x0) goto LAB_00132e06;
    pVVar1->growthRate = 10;
    size = 10;
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
    pVVar1->items = 0;
    pVVar1->dirty_index = -1;
    pVVar1->type = type;
    pVVar1->owner = owner;
    pVVar1->dirty_count = 0;
    return pVVar1;
  }
LAB_00132e06:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Vector_insert @ 0x132ee0 */

/* DWARF original prototype: void Vector_insert(Vector * this, int idx, void * data_) */

void Vector_insert(Vector *this,int idx,void *data_)

{
  int wVar1;
  Object **ptr;
  int wVar2;

  wVar2 = this->items;
  if (wVar2 <= idx) {
    idx = wVar2;
  }
  wVar1 = this->arraySize;
                    /* Unresolved local var: int oldSize@[???] */
  ptr = this->array;
  if (wVar1 < wVar2 + 1) {
    wVar2 = wVar2 + 1 + this->growthRate;
    this->arraySize = wVar2;
    ptr = xReallocArrayZero(ptr,(long)wVar1,(long)wVar2,8);
    this->array = ptr;
    wVar2 = this->items;
  }
  if (idx < wVar2) {
    memmove(ptr + (long)idx + 1,ptr + idx,(long)(wVar2 - idx) << 3);
    ptr = this->array;
    wVar2 = this->items;
  }
  ptr[idx] = data_;
  this->items = wVar2 + 1;
  return;
}


/* Vector_add @ 0x135420 */

/* DWARF original prototype: void Vector_add(Vector * this, void * data_) */

void Vector_add(Vector *this,void *data_)

{
  int wVar1;
  Object *pOVar2;
  Object **ppOVar3;
  long a3;
  int wVar4;
  size_t prevmemb;
  long in_R8;
  long in_R9;
  int wVar5;

  wVar1 = this->items;
                    /* Unresolved local var: Object * data@[???] */
  prevmemb = (size_t)this->arraySize;
                    /* Unresolved local var: int oldSize@[???] */
  ppOVar3 = this->array;
  wVar5 = wVar1 + 1;
                    /* Unresolved local var: Object * removed@[???] */
  if (this->arraySize < wVar5) {
    a3 = 8;
    wVar4 = this->growthRate + wVar5;
    this->arraySize = wVar4;
    ppOVar3 = xReallocArrayZero(ppOVar3,prevmemb,(long)wVar4,8);
    this->array = ppOVar3;
    if (wVar1 < this->items) {
      ppOVar3 = ppOVar3 + wVar1;
      if ((this->owner != false) && (pOVar2 = *ppOVar3, pOVar2 != (Object *)0x0)) {
        (*(code *)(pOVar2->klass->delete))(pOVar2,prevmemb,(long)pOVar2->klass,a3,in_R8,in_R9);
        ppOVar3 = this->array + wVar1;
      }
      goto LAB_0013545e;
    }
  }
  this->items = wVar5;
  ppOVar3 = ppOVar3 + wVar1;
LAB_0013545e:
  *ppOVar3 = data_;
  return;
}


/* Vector_splice @ 0x1354c0 */

/* DWARF original prototype: void Vector_splice(Vector * this, Vector * from) */

void Vector_splice(Vector *this,Vector *from)

{
  int wVar1;
  int wVar2;
  Object **ppOVar3;
  long lVar4;
  Object **ppOVar5;
  int wVar6;

  wVar1 = this->items;
  wVar2 = this->arraySize;
  wVar6 = from->items + wVar1;
  if (wVar2 < wVar6) {
                    /* Unresolved local var: int oldSize@[???] */
    wVar6 = wVar6 + this->growthRate;
    this->arraySize = wVar6;
    ppOVar5 = xReallocArrayZero(this->array,(long)wVar2,(long)wVar6,8);
    wVar6 = from->items + this->items;
    this->array = ppOVar5;
  }
  this->items = wVar6;
                    /* Unresolved local var: int j@[???] */
  wVar2 = from->items;
  if (0 < wVar2) {
    ppOVar5 = this->array;
    ppOVar3 = from->array;
    lVar4 = 0;
    do {
      *(undefined8 *)((long)ppOVar5 + lVar4 + (long)wVar1 * 8) =
           *(undefined8 *)((long)ppOVar3 + lVar4);
      lVar4 = lVar4 + 8;
    } while ((long)wVar2 * 8 != lVar4);
  }
  return;
}

