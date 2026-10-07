/* ProcessTable_new @ 00143ba0 size 348 */

ProcessTable_2 * ProcessTable_new(Machine_2 *host,Hashtable_2 *pidMatchList)

{
  int iVar1;
  LinuxProcessTable *this;
  Vector *pVVar2;
  Object **ppOVar3;
  Hashtable *pHVar4;

                    /* Unresolved local var: void * data@[???] */
  this = calloc(1,0x78);
  if (this != (LinuxProcessTable *)0x0) {
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
    (this->super).super.super.klass = &ProcessTable_class.super;
    pVVar2 = malloc(0x28);
    if (pVVar2 != (Vector *)0x0) {
      pVVar2->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
      ppOVar3 = calloc(10,8);
      if (ppOVar3 != (Object **)0x0) {
        pVVar2->array = ppOVar3;
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
        pVVar2->arraySize = L'\n';
        pVVar2->owner = true;
        pVVar2->type = (ObjectClass *)&LinuxProcess_class;
        pVVar2->items = L'\0';
        pVVar2->dirty_index = L'\xffffffff';
        pVVar2->dirty_count = L'\0';
        (this->super).super.rows = pVVar2;
        pVVar2 = malloc(0x28);
        if (pVVar2 != (Vector *)0x0) {
          pVVar2->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
          ppOVar3 = calloc(10,8);
          if (ppOVar3 != (Object **)0x0) {
            pVVar2->array = ppOVar3;
            pVVar2->items = L'\0';
            pVVar2->dirty_index = L'\xffffffff';
            (this->super).super.displayList = pVVar2;
            pVVar2->arraySize = L'\n';
            pVVar2->type = (ObjectClass *)&LinuxProcess_class;
            pVVar2->owner = false;
            pVVar2->dirty_count = L'\0';
            pHVar4 = Hashtable_new(200,false);
            (this->super).super.host = host;
            (this->super).super.table = pHVar4;
            (this->super).pidMatchList = pidMatchList;
            (this->super).super.needsSort = true;
            (this->super).super.following = L'\xffffffff';
            LinuxProcessTable_initTtyDrivers(this);
            iVar1 = access(((char *)0x14a066 /* "/proc/self/smaps_rollup" */),4);
            this->haveSmapsRollup = iVar1 == 0;
            return &this->super;
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

