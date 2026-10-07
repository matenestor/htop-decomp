/* Table_init @ 00132aa0 size 263 */

/* DWARF original prototype: Table * Table_init(Table * this, ObjectClass * klass, Machine * host)
    */

Table_2 * Table_init(Table *this,ObjectClass *klass,Machine_2 *host)

{
  Vector *pVVar1;
  Object **ppOVar2;
  Hashtable *pHVar3;

                    /* Unresolved local var: Vector * this@[???] */
                    /* Unresolved local var: void * data@[???] */
  pVVar1 = malloc(0x28);
  if (pVVar1 != (Vector *)0x0) {
    pVVar1->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
    ppOVar2 = calloc(10,8);
    if (ppOVar2 != (Object **)0x0) {
      pVVar1->array = ppOVar2;
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
      pVVar1->arraySize = L'\n';
      pVVar1->type = klass;
      pVVar1->owner = true;
      pVVar1->items = L'\0';
      pVVar1->dirty_index = L'\xffffffff';
      pVVar1->dirty_count = L'\0';
      this->rows = pVVar1;
      pVVar1 = malloc(0x28);
      if (pVVar1 != (Vector *)0x0) {
        pVVar1->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
        ppOVar2 = calloc(10,8);
        if (ppOVar2 != (Object **)0x0) {
          pVVar1->type = klass;
          pVVar1->items = L'\0';
          pVVar1->dirty_index = L'\xffffffff';
          this->displayList = pVVar1;
          pVVar1->array = ppOVar2;
          pVVar1->arraySize = L'\n';
          pVVar1->owner = false;
          pVVar1->dirty_count = L'\0';
          pHVar3 = Hashtable_new(200,false);
          this->needsSort = true;
          this->table = pHVar3;
          this->following = L'\xffffffff';
          this->host = (Machine_ *)host;
          return (Table_2 *)this;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

