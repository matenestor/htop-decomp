/* Scheduling_rowSetPolicy @ 0012dcd0 size 116 */

_Bool Scheduling_rowSetPolicy(Process_ *row,Arg arg)

{
  long lVar1;
  uint __policy;
  int iVar2;
  long in_FS_OFFSET;
  sched_param param;

                    /* Unresolved local var: SchedulingArg * sarg@[???]
                       Unresolved local var: wchar_t policy@[???]
                       Unresolved local var: wchar_t r@[???] */
  param.sched_priority = L'\0';
  __policy = *(uint *)arg.v;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (policies[(int)__policy].prioritySupport != false) {
    param.sched_priority = *(wchar_t *)((long)arg.v + 4);
  }
  if (reset_on_fork) {
    __policy = __policy & 0x40000000;
  }
  iVar2 = sched_setscheduler((row->super).id,__policy,(sched_param_2 *)&param);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2 != -1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

