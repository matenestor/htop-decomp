#include "htop.h"

/* ProcessLocksScreen_new @ 0x127680 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ProcessLocksScreen * ProcessLocksScreen_new(Process_2 *process)

{
  _Bool _Var1;
  int wVar2;
  InfoScreen *this;
  ProcessLocksScreen *pPVar3;

                    /* Unresolved local var: void * data@[???] */
  this = malloc(0x30);
  if (this != (InfoScreen *)0x0) {
    _Var1 = process->isUserlandThread;
    (this->super).klass = &ProcessLocksScreen_class.super;
    if ((_Var1 == false) && (process->isKernelThread == false)) {
      wVar2 = (process->super).id;
    }
    else {
      wVar2 = (process->super).group;
    }
    *(int *)&this[1].super.klass = wVar2;
    pPVar3 = (ProcessLocksScreen *)
             InfoScreen_init(this,(Process *)process,(FunctionBar *)0x0,_LINES + -2,
                             ((char *)(long)&s_FD_TYPE_EXCLUSION_READ_WRITE_DEV_0014c428 /* "   FD TYPE       EXCLUSION  READ/WRITE DEVICE       NODE               START                 END  FILENAME" */)
                            );
    return pPVar3;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ProcessLocksScreen_draw @ 0x1283c0 */

/* DWARF original prototype: void ProcessLocksScreen_draw(InfoScreen * this) */

void ProcessLocksScreen_draw(InfoScreen *this)

{
  Process *pPVar1;
  char *va1;

  pPVar1 = this->process;
                    /* Unresolved local var: Settings * settings@[???] */
  if (((pPVar1->isUserlandThread != false) &&
      (((pPVar1->super).host)->settings->showThreadNames != false)) ||
     (va1 = (pPVar1->mergedCommand).str, va1 == (char *)0x0)) {
    va1 = pPVar1->cmdline;
  }
  InfoScreen_drawTitled
            (this,((char *)(long)&s_Snapshot_of_file_locks_of_proces_0014c4c8 /* "Snapshot of file locks of process %d - %s" */),*(int *)&this[1].super.klass,va1);
  return;
}


/* ProcessLocksScreen_scan @ 0x12cd60 */

/* DWARF original prototype: void ProcessLocksScreen_scan(InfoScreen * this) */

void ProcessLocksScreen_scan(InfoScreen *this)

{
  undefined1 __frame[0x318] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x2d8;
  pid_t pid;
  Panel *a0;
  long lVar1;
  FileLocks_LockData_ *pFVar2;
  code *UNRECOVERED_JUMPTABLE;
  FileLocks_ProcessData *__ptr;
  char *va8;
  int wVar3;
  char *fmt;
  long a2;
  char *in_R8;
  char *in_R9;
  int wVar4;
  FileLocks_LockData_ *__ptr_00;
  long in_FS_OFFSET = (long)__fake_fs;

  a0 = this->display;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar4 = a0->selected;
  Vector_prune(a0->items);
  a0->selected = 0;
  a0->oldSelected = 0;
  pid = *(pid_t *)&this[1].super.klass;
  a0->scrollV = 0;
  a0->needsRedraw = true;
  __ptr = Platform_getProcessLocks(pid);
  if (__ptr == (FileLocks_ProcessData *)0x0) {
    InfoScreen_addLine(this,((char *)(long)&s_This_feature_is_not_supported_on_0014c598 /* "This feature is not supported on your platform." */));
  }
  else if (__ptr->error == false) {
                    /* Unresolved local var: FileLocks_LockData * ldata@[???] */
    __ptr_00 = __ptr->locks;
    if (__ptr_00 == (FileLocks_LockData_ *)0x0) {
      InfoScreen_addLine(this,((char *)(long)&s_No_locks_have_been_found_for_the_0014c5e8 /* "No locks have been found for the selected process." */));
    }
    else {
      do {
        (*(char *(*))(__fp - 0x268)) = (char *)(__ptr_00->data).end;
        va8 = (__ptr_00->data).filename;
        if ((*(char *(*))(__fp - 0x268)) == (char *)0xffffffffffffffff) {
          in_R9 = (__ptr_00->data).exclusive;
          in_R8 = (__ptr_00->data).locktype;
          if (va8 == (char *)0x0) {
            va8 = ((char *)(long)&s__N_A__001489d4 /* "<N/A>" */);
          }
          wVar3 = (__ptr_00->data).fd;
          fmt = ((char *)(long)&s__5d___10s___10s___10s___6lx__10l_0014c620 /* "%5d %-10s %-10s %-10s %#6lx %10lu %19lu %19s  %s" */);
          (*(char *(*))(__fp - 0x268)) = ((char *)(long)&s__END_OF_FILE__001489da /* "<END OF FILE>" */);
          (*(uint64_t (*))(__fp - 0x270)) = (__ptr_00->data).start;
          (*(uint64_t (*))(__fp - 0x278)) = (__ptr_00->data).inode;
          (*(dev_t (*))(__fp - 0x280)) = (__ptr_00->data).dev;
          (*(char *(*))(__fp - 0x288)) = (__ptr_00->data).readwrite;
        }
        else {
                    /* Unresolved local var: FileLocks_Data * data@[???]
                       Unresolved local var: FileLocks_LockData * old@[???] */
          in_R9 = (__ptr_00->data).exclusive;
          in_R8 = (__ptr_00->data).locktype;
          if (va8 == (char *)0x0) {
            va8 = ((char *)(long)&s__N_A__001489d4 /* "<N/A>" */);
          }
          wVar3 = (__ptr_00->data).fd;
          fmt = ((char *)(long)&s__5d___10s___10s___10s___6lx__10l_0014c658 /* "%5d %-10s %-10s %-10s %#6lx %10lu %19lu %19lu  %s" */);
          (*(uint64_t (*))(__fp - 0x270)) = (__ptr_00->data).start;
          (*(uint64_t (*))(__fp - 0x278)) = (__ptr_00->data).inode;
          (*(dev_t (*))(__fp - 0x280)) = (__ptr_00->data).dev;
          (*(char *(*))(__fp - 0x288)) = (__ptr_00->data).readwrite;
        }
        xSnprintf((*(char (*) [512])(__fp - 0x248)),0x200,fmt,wVar3,in_R8,in_R9,(*(char *(*))(__fp - 0x288)),(*(dev_t (*))(__fp - 0x280)),(*(uint64_t (*))(__fp - 0x278)),(*(uint64_t (*))(__fp - 0x270)),(long)(*(char *(*))(__fp - 0x268)),va8);
        InfoScreen_addLine(this,(*(char (*) [512])(__fp - 0x248)));
        free((__ptr_00->data).locktype);
        free((__ptr_00->data).exclusive);
        free((__ptr_00->data).readwrite);
        free((__ptr_00->data).filename);
        pFVar2 = __ptr_00->next;
        free(__ptr_00);
        __ptr_00 = pFVar2;
      } while (pFVar2 != (FileLocks_LockData_ *)0x0);
    }
  }
  else {
    InfoScreen_addLine(this,((char *)(long)&s_Could_not_determine_file_locks__0014c5c8 /* "Could not determine file locks." */));
  }
  free(__ptr);
  Vector_insertionSort(this->lines);
  Vector_insertionSort(a0->items);
                    /* Unresolved local var: int size@[???] */
  wVar3 = a0->items->items;
  if (wVar3 <= wVar4) {
    wVar4 = wVar3 + -1;
  }
  if (wVar4 < 0) {
    wVar4 = 0;
  }
  UNRECOVERED_JUMPTABLE = (a0->super).klass[1].extends;
  a0->selected = wVar4;
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Could not recover jumptable at 0x0012cf53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)((long)a0,0xffffffff,a2,0,(long)in_R8,(long)in_R9);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

