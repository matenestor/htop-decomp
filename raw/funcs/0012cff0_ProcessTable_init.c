/* ProcessTable_init @ 0012cff0 size 273 */

/* DWARF original prototype: void ProcessTable_init(ProcessTable * this, ObjectClass * klass,
   Machine * host, Hashtable * pidMatchList) */

void ProcessTable_init(ProcessTable *this,ObjectClass *klass,Machine_2 *host,
                      Hashtable_2 *pidMatchList)

{
  Vector *pVVar1;
  Object **ppOVar2;
  Hashtable *pHVar3;

                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
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
      (this->super).rows = pVVar1;
      pVVar1 = malloc(0x28);
      if (pVVar1 != (Vector *)0x0) {
                    /* Unresolved local var: void * data@[???] */
        pVVar1->growthRate = L'\n';
        ppOVar2 = calloc(10,8);
        if (ppOVar2 != (Object **)0x0) {
          pVVar1->type = klass;
          pVVar1->items = L'\0';
          pVVar1->dirty_index = L'\xffffffff';
          (this->super).displayList = pVVar1;
          pVVar1->array = ppOVar2;
          pVVar1->arraySize = L'\n';
          pVVar1->owner = false;
          pVVar1->dirty_count = L'\0';
          pHVar3 = Hashtable_new(200,false);
          (this->super).needsSort = true;
          (this->super).table = pHVar3;
          (this->super).following = L'\xffffffff';
          (this->super).host = (Machine__4 *)host;
          this->pidMatchList = pidMatchList;
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

