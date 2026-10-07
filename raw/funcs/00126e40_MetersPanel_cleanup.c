/* MetersPanel_cleanup @ 00126e40 size 39 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void MetersPanel_cleanup(void)

{
  if (Meters_movingBar != (FunctionBar *)0x0) {
    FunctionBar_delete(Meters_movingBar);
    Meters_movingBar = (FunctionBar *)0x0;
    return;
  }
  return;
}

