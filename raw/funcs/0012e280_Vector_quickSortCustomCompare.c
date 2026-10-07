/* Vector_quickSortCustomCompare @ 0012e280 size 23 */

/* DWARF original prototype: void Vector_quickSortCustomCompare(Vector * this, Object_Compare
   compare) */

void Vector_quickSortCustomCompare(Vector *this,Object_Compare compare)

{
  quickSort(this->array,L'\0',this->items + L'\xffffffff',compare);
  return;
}

