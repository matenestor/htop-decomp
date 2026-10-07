/* CRT_handleSIGSEGV @ 0011d160 size 430 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_handleSIGSEGV(wchar_t signal)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;

  CRT_done();
  __fprintf_chk(_stderr,2,
                ((char *)0x14a750 /* "\n\nFATAL PROGRAM ERROR DETECTED\n============================\nPlease check at https://htop.dev/issues whether this issue has already been reported.\nIf no similar issue has been reported before, please create a new issue with the following information:\n  - Your %s version: \'3.3.0\'\n  - Your OS and kernel version (uname -a)\n  - Your distribution and release (lsb_release -a)\n  - Likely steps to reproduce (How did it happen?)\n" */)
                ,program);
  __fprintf_chk(_stderr,2,((char *)0x14a8f8 /* "  - Backtrace of the issue (see below)\n" */));
  __fprintf_chk(_stderr,2,((char *)0x147506 /* "\n" */));
  pcVar2 = strsignal(signal);
  pcVar3 = ((char *)0x1474f6 /* "unknown reason" */);
  if (pcVar2 != (char *)0x0) {
    pcVar3 = pcVar2;
  }
  __fprintf_chk(_stderr,2,
                ((char *)0x14a920 /* "Error information:\n------------------\nA signal %d (%s) was received.\n\n" */),signal,
                pcVar3);
  __fprintf_chk(_stderr,2,((char *)0x14a968 /* "Setting information:\n--------------------\n" */));
  Settings_write(CRT_crashSettings,true);
  __fprintf_chk(_stderr,2,((char *)0x147505 /* "\n\n" */));
  __fprintf_chk(_stderr,2,((char *)0x14a998 /* "Backtrace information:\n----------------------\n" */));
  print_backtrace();
  __fprintf_chk(_stderr,2,
                ((char *)0x14a9c8 /* "\nTo make the above information more practical to work with, please also provide a disassembly of your %s binary. This can usually be done by running the following command:\n\n" */)
                ,program);
  __fprintf_chk(_stderr,2,((char *)0x14aa78 /* "   objdump -d -S -w `which %s` > ~/%s.objdump\n" */),program,program);
  __fprintf_chk(_stderr,2,((char *)0x14aaa8 /* "\nPlease include the generated file in your report.\n" */));
  __fprintf_chk(_stderr,2,
                ((char *)0x14aae0 /* "Running this program with debug symbols or inside a debugger may provide further insights.\n\nThank you for helping to improve %s!\n\n" */)
                ,program);
  iVar1 = sigaction(signal,(sigaction_2 *)(old_sig_handler + signal),(sigaction_2 *)0x0);
  pcVar3 = ((char *)0x14ab68 /* "!!! Chained handler could not be restored. Forcing exit.\n" */);
  if (-1 < iVar1) {
    raise(signal);
    pcVar3 = ((char *)0x14aba8 /* "!!! Chained handler did not exit. Forcing exit.\n" */);
  }
  __fprintf_chk(_stderr,2,pcVar3);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}

