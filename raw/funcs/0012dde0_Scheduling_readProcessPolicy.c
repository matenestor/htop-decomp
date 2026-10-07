/* Scheduling_readProcessPolicy @ 0012dde0 size 36 */

void Scheduling_readProcessPolicy(Process *proc)

{
  wchar_t wVar1;

  wVar1 = sched_getscheduler((proc->super).id);
  proc->scheduling_policy = wVar1;
  return;
}

