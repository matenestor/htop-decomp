/* Platform_actionHigherAutogroupPriority @ 0013dd80 size 336 */

Htop_Reaction Platform_actionHigherAutogroupPriority(State_2 *st)

{
  byte bVar1;
  long lVar2;
  MainPanel__2 *pMVar3;
  _Bool _Var4;
  wchar_t fd;
  Htop_Reaction HVar5;
  ssize_t sVar6;
  Vector *pVVar7;
  int *piVar8;
  long lVar9;
  byte bVar10;
  byte bVar11;
  long in_FS_OFFSET;
  char buf [16];

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  HVar5 = HTOP_OK;
  if (readonly) goto LAB_0013ddb1;
  pMVar3 = st->mainPanel;
                    /* Unresolved local var: _Bool changed@[???]
                       Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: wchar_t fd@[???] */
  fd = open(((char *)0x14c3b0 /* "/proc/sys/kernel/sched_autogroup_enabled" */),0);
  if (fd < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
    piVar8 = __errno_location();
    if (-1 < -*piVar8) goto LAB_0013de0b;
  }
  else {
    sVar6 = readfd_internal(fd,buf,0x10);
    if (-1 < sVar6) {
LAB_0013de0b:
      if (buf[0] == '1') {
                    /* Unresolved local var: _Bool anyTagged@[???]
                       Unresolved local var: _Bool ok@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: wchar_t i@[???] */
        pVVar7 = (pMVar3->super).items;
        if (pVVar7->items < L'\x01') {
          HVar5 = HTOP_OK;
        }
        else {
          lVar9 = 0;
          bVar11 = 1;
          bVar10 = 0;
          do {
                    /* Unresolved local var: Row * row@[???] */
            bVar1 = *(byte *)((long)&pVVar7->array[lVar9][3].klass + 5);
            if (bVar1 != 0) {
                    /* Unresolved local var: Process * p@[???] */
              _Var4 = LinuxProcess_changeAutogroupPriorityBy
                                ((Process_3 *)(ulong)*(uint *)&pVVar7->array[lVar9][2].klass,
                                 (Arg)0xffffffff);
              bVar11 = bVar11 & _Var4;
              pVVar7 = (pMVar3->super).items;
              bVar10 = bVar1;
            }
            lVar9 = lVar9 + 1;
          } while ((wchar_t)lVar9 < pVVar7->items);
                    /* Unresolved local var: Row * row@[???] */
          if (((bVar10 != 1) && (L'\0' < pVVar7->items)) &&
             (pVVar7->array[(pMVar3->super).selected] != (Object *)0x0)) {
                    /* Unresolved local var: Process * p@[???] */
            _Var4 = LinuxProcess_changeAutogroupPriorityBy
                              ((Process_3 *)
                               (ulong)*(uint *)&pVVar7->array[(pMVar3->super).selected][2].klass,
                               (Arg)0xffffffff);
            bVar11 = bVar11 & _Var4;
          }
          if (bVar11 == 0) {
            beep();
            HVar5 = (Htop_Reaction)bVar10;
          }
          else {
            HVar5 = (Htop_Reaction)bVar10;
          }
        }
        goto LAB_0013ddb1;
      }
    }
  }
  beep();
  HVar5 = HTOP_OK;
LAB_0013ddb1:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return HVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

