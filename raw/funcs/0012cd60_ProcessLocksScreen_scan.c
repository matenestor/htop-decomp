/* ProcessLocksScreen_scan @ 0012cd60 size 624 */

/* DWARF original prototype: void ProcessLocksScreen_scan(InfoScreen * this) */

void ProcessLocksScreen_scan(InfoScreen *this)

{
  pid_t pid;
  Panel *a0;
  long lVar1;
  FileLocks_LockData_ *pFVar2;
  code *UNRECOVERED_JUMPTABLE;
  FileLocks_ProcessData *__ptr;
  char *va8;
  wchar_t wVar3;
  char *fmt;
  long a2;
  char *in_R8;
  char *in_R9;
  wchar_t wVar4;
  FileLocks_LockData_ *__ptr_00;
  long in_FS_OFFSET;
  char *va3;
  dev_t va4;
  uint64_t va5;
  uint64_t va6;
  char *va7;
  char entry [512];

  a0 = this->display;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar4 = a0->selected;
  Vector_prune(a0->items);
  a0->selected = L'\0';
  a0->oldSelected = L'\0';
  pid = *(pid_t *)&this[1].super.klass;
  a0->scrollV = L'\0';
  a0->needsRedraw = true;
  __ptr = Platform_getProcessLocks(pid);
  if (__ptr == (FileLocks_ProcessData *)0x0) {
    InfoScreen_addLine(this,((char *)0x14c598 /* "This feature is not supported on your platform." */));
  }
  else if (__ptr->error == false) {
                    /* Unresolved local var: FileLocks_LockData * ldata@[???] */
    __ptr_00 = __ptr->locks;
    if (__ptr_00 == (FileLocks_LockData_ *)0x0) {
      InfoScreen_addLine(this,((char *)0x14c5e8 /* "No locks have been found for the selected process." */));
    }
    else {
      do {
        va7 = (char *)(__ptr_00->data).end;
        va8 = (__ptr_00->data).filename;
        if (va7 == (char *)0xffffffffffffffff) {
          in_R9 = (__ptr_00->data).exclusive;
          in_R8 = (__ptr_00->data).locktype;
          if (va8 == (char *)0x0) {
            va8 = ((char *)0x1489d4 /* "<N/A>" */);
          }
          wVar3 = (__ptr_00->data).fd;
          fmt = ((char *)0x14c620 /* "%5d %-10s %-10s %-10s %#6lx %10lu %19lu %19s  %s" */);
          va7 = ((char *)0x1489da /* "<END OF FILE>" */);
          va6 = (__ptr_00->data).start;
          va5 = (__ptr_00->data).inode;
          va4 = (__ptr_00->data).dev;
          va3 = (__ptr_00->data).readwrite;
        }
        else {
                    /* Unresolved local var: FileLocks_Data * data@[???]
                       Unresolved local var: FileLocks_LockData * old@[???] */
          in_R9 = (__ptr_00->data).exclusive;
          in_R8 = (__ptr_00->data).locktype;
          if (va8 == (char *)0x0) {
            va8 = ((char *)0x1489d4 /* "<N/A>" */);
          }
          wVar3 = (__ptr_00->data).fd;
          fmt = ((char *)0x14c658 /* "%5d %-10s %-10s %-10s %#6lx %10lu %19lu %19lu  %s" */);
          va6 = (__ptr_00->data).start;
          va5 = (__ptr_00->data).inode;
          va4 = (__ptr_00->data).dev;
          va3 = (__ptr_00->data).readwrite;
        }
        xSnprintf(entry,0x200,fmt,wVar3,in_R8,in_R9,va3,va4,va5,va6,(long)va7,va8);
        InfoScreen_addLine(this,entry);
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
    InfoScreen_addLine(this,((char *)0x14c5c8 /* "Could not determine file locks." */));
  }
  free(__ptr);
  Vector_insertionSort(this->lines);
  Vector_insertionSort(a0->items);
                    /* Unresolved local var: wchar_t size@[???] */
  wVar3 = a0->items->items;
  if (wVar3 <= wVar4) {
    wVar4 = wVar3 + L'\xffffffff';
  }
  if (wVar4 < L'\0') {
    wVar4 = L'\0';
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

