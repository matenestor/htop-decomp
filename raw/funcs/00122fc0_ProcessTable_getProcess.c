/* ProcessTable_getProcess @ 00122fc0 size 152 */

/* DWARF original prototype: Process * ProcessTable_getProcess(ProcessTable * this, pid_t pid, _Bool
   * preExisting, Process_New constructor) */

Process_2 *
ProcessTable_getProcess(ProcessTable *this,pid_t pid,_Bool *preExisting,Process_New constructor)

{
  Hashtable_2 *pHVar1;
  ulong uVar2;
  HashtableItem *a4;
  Process_2 *pPVar3;
  HashtableItem *a3;
  ulong a2;
  undefined4 in_register_00000034;
  ulong a1;

                    /* Unresolved local var: Table * table@[???]
                       Unresolved local var: Process * proc@[???] */
  a1 = CONCAT44(in_register_00000034,pid);
                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  pHVar1 = (this->super).table;
  uVar2 = pHVar1->size;
  a4 = pHVar1->buckets;
  a2 = (ulong)(uint)pid % uVar2;
  a3 = a4 + a2;
  pPVar3 = a3->value;
  if (pPVar3 != (Process_2 *)0x0) {
    a1 = 0;
    do {
      while( true ) {
        if (pid == a3->key) {
          *preExisting = true;
          return pPVar3;
        }
        if (a3->probe < a1) goto LAB_0012303a;
        a2 = a2 + 1;
        if (uVar2 != a2) break;
        a2 = 0;
        a1 = a1 + 1;
        pPVar3 = a4->value;
        a3 = a4;
        if (pPVar3 == (Process_2 *)0x0) goto LAB_0012303a;
      }
      a1 = a1 + 1;
      a3 = a4 + a2;
      pPVar3 = a3->value;
    } while (pPVar3 != (Process_2 *)0x0);
  }
LAB_0012303a:
  *preExisting = false;
                    /* Unresolved local var: Table * table@[???]
                       Unresolved local var: Process * proc@[???] */
  pPVar3 = (*constructor)((Machine__2 *)(this->super).host,a1,a2,(long)a3,(long)a4,(long)this);
  (pPVar3->super).id = pid;
  return pPVar3;
}

