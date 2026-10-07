/* LibSensors_reload @ 0013b180 size 51 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

wchar_t LibSensors_reload(void)

{
  wchar_t wVar1;
  int *piVar2;
  long in_RCX;
  long in_RDX;
  long a2;
  long in_RSI;
  long in_RDI;
  long in_R8;
  long in_R9;

  if (dlopenHandle != (void *)0x0) {
    (*sym_sensors_cleanup)(in_RDI,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
                    /* WARNING: Could not recover jumptable at 0x0013b19b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    wVar1 = (*sym_sensors_init)((FILE *)0x0,in_RSI,a2,in_RCX,in_R8,in_R9);
    return wVar1;
  }
  piVar2 = __errno_location();
  *piVar2 = 0x5f;
  return L'\xffffffff';
}

