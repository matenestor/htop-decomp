/* Platform_init_13caa0 @ 0013caa0 size 87 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_Bool Platform_init_13caa0(void)

{
  _Bool _Var1;
  int iVar2;

  iVar2 = access(((char *)0x149a78 /* "/proc" */),4);
  if (iVar2 == 0) {
    _Var1 = Platform_init();
    return _Var1;
  }
  __fprintf_chk(_stderr,2,((char *)0x14b168 /* "Error: could not read procfs (compiled to look in %s).\n" */),((char *)0x149a78 /* "/proc" */));
  return false;
}

