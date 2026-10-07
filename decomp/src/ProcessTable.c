#include "htop.h"

/* ProcessTable_prepareEntries @ 0x11fc50 */

void ProcessTable_prepareEntries(ProcessTable_ *super)

{
  Object **ppOVar1;
  undefined1 uVar2;
  int wVar3;
  Vector *pVVar4;
  Object *pOVar5;
  Object **ppOVar6;

                    /* Unresolved local var: int i@[???] */
  pVVar4 = (super->super).rows;
  super->totalTasks = 0;
  super->runningTasks = 0;
  super->userlandThreads = 0;
  super->kernelThreads = 0;
  wVar3 = pVVar4->items;
  if (0 < wVar3) {
    ppOVar6 = pVVar4->array;
    ppOVar1 = ppOVar6 + wVar3;
    do {
                    /* Unresolved local var: Row * row@[???] */
      pOVar5 = *ppOVar6;
      ppOVar6 = ppOVar6 + 1;
      uVar2 = *(undefined1 *)((long)&pOVar5[3].klass + 6);
      *(undefined1 *)((long)&pOVar5[4].klass + 1) = 0;
      *(undefined1 *)((long)&pOVar5[3].klass + 6) = 1;
      *(undefined1 *)((long)&pOVar5[3].klass + 7) = uVar2;
    } while (ppOVar1 != ppOVar6);
  }
  return;
}


/* ProcessTable_iterateEntries @ 0x1200d0 */

void ProcessTable_iterateEntries(ProcessTable_ *super)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  LinuxMachine_2 *lhost;
  long lVar1;
  int fd;
  long lVar2;
  int *piVar3;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar4;

                    /* Unresolved local var: LinuxProcessTable * this@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: Settings * settings@[???]
                       Unresolved local var: LinuxMachine * lhost@[???]
                       Unresolved local var: openat_arg_t rootFd@[???] */
  bVar4 = false;
  lhost = (LinuxMachine_2 *)(super->super).host;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((((lhost->super).settings)->ss->flags & 0x80000) != 0) {
                    /* Unresolved local var: int fd@[???] */
    fd = open(((char *)(long)&s__proc_sys_kernel_sched_autogroup_0014c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
    if (fd < 0) {
                    /* Unresolved local var: int fd@[???] */
      piVar3 = __errno_location();
      lVar2 = (long)-*piVar3;
    }
    else {
      lVar2 = readfd_internal(fd,(*(char (*) [16])(__fp - 0x38)),0x10);
    }
    bVar4 = false;
    if (-1 < lVar2) {
      bVar4 = (*(char (*) [16])(__fp - 0x38))[0] == '1';
    }
  }
  *(bool *)((long)&super[1].super.rows + 1) = bVar4;
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    LinuxProcessTable_recurseProcTree
              ((LinuxProcessTable *)super,-100,lhost,((char *)(long)&s__proc_00149a78 /* "/proc" */),(Process_2 *)0x0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ProcessTable_getProcess @ 0x122fc0 */

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
  pPVar3 = (*(code *)(constructor))((Machine__2 *)(this->super).host,a1,a2,(long)a3,(long)a4,(long)this);
  (pPVar3->super).id = pid;
  return pPVar3;
}


/* ProcessTable_init @ 0x12cff0 */

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
    pVVar1->growthRate = 10;
                    /* Unresolved local var: void * data@[???] */
    ppOVar2 = calloc(10,8);
    if (ppOVar2 != (Object **)0x0) {
      pVVar1->array = ppOVar2;
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
      pVVar1->arraySize = 10;
      pVVar1->type = klass;
      pVVar1->owner = true;
      pVVar1->items = 0;
      pVVar1->dirty_index = -1;
      pVVar1->dirty_count = 0;
      (this->super).rows = pVVar1;
      pVVar1 = malloc(0x28);
      if (pVVar1 != (Vector *)0x0) {
                    /* Unresolved local var: void * data@[???] */
        pVVar1->growthRate = 10;
        ppOVar2 = calloc(10,8);
        if (ppOVar2 != (Object **)0x0) {
          pVVar1->type = klass;
          pVVar1->items = 0;
          pVVar1->dirty_index = -1;
          (this->super).displayList = pVVar1;
          pVVar1->array = ppOVar2;
          pVVar1->arraySize = 10;
          pVVar1->owner = false;
          pVVar1->dirty_count = 0;
          pHVar3 = Hashtable_new(200,false);
          (this->super).needsSort = true;
          (this->super).table = pHVar3;
          (this->super).following = -1;
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


/* ProcessTable_done @ 0x12d110 */

/* DWARF original prototype: void ProcessTable_done(ProcessTable * this) */

void ProcessTable_done(ProcessTable *this)

{
  Hashtable *this_00;

  this_00 = (this->super).table;
  Hashtable_clear(this_00);
  free(this_00->buckets);
  free(this_00);
  Vector_delete((this->super).displayList);
  Vector_delete((this->super).rows);
  return;
}


/* ProcessTable_cleanupEntries @ 0x12d160 */

void ProcessTable_cleanupEntries(Table_2 *super)

{
  Machine__2 *pMVar1;
  Settings__3 *settings;
  Process *this;
  int idx;
  int wVar2;
  Vector *this_00;
  long lVar3;

  pMVar1 = super->host;
                    /* Unresolved local var: int i@[???] */
  this_00 = super->rows;
  settings = pMVar1->settings;
  idx = this_00->items + -1;
  if (-1 < idx) {
    lVar3 = (long)idx << 3;
    do {
                    /* Unresolved local var: Process * p@[???] */
      this = *(Process **)((long)this_00->array + lVar3);
      Process_makeCommandStr(this,(Settings_5 *)settings);
      if (pMVar1->maxUserId < this->st_uid) {
        pMVar1->maxUserId = this->st_uid;
      }
      wVar2 = idx + -1;
      Table_cleanupRow(super,(Row_2 *)this,idx);
      lVar3 = lVar3 + -8;
      this_00 = super->rows;
      idx = wVar2;
    } while (wVar2 != -1);
  }
  Vector_compact(this_00);
  return;
}

