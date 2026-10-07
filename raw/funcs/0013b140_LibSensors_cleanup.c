/* LibSensors_cleanup @ 0013b140 size 50 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void LibSensors_cleanup(void)

{
  long in_RCX;
  long in_RDX;
  long in_RSI;
  long in_RDI;
  long in_R8;
  long in_R9;

  if (dlopenHandle != (void *)0x0) {
    (*sym_sensors_cleanup)(in_RDI,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
    dlclose(dlopenHandle);
    dlopenHandle = (void *)0x0;
    return;
  }
  return;
}

