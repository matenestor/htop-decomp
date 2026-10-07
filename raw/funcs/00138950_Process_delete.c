/* Process_delete @ 00138950 size 158 */

void Process_delete(LinuxProcess_ *cast)

{
  free((cast->super).cmdline);
  free((cast->super).procComm);
  free((cast->super).procExe);
  free((cast->super).procCwd);
  free((cast->super).mergedCommand.str);
  free((cast->super).tty_name);
  free(cast->container_short);
  free(cast->cgroup_short);
  free(cast->cgroup);
  free(cast->ctid);
  free(cast->secattr);
  free(cast);
  return;
}

