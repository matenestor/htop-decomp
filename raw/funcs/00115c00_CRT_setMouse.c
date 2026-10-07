/* CRT_setMouse @ 00115c00 size 28 */

void CRT_setMouse(_Bool enabled)

{
  if (enabled) {
    mousemask(0x210001,(ulong *)0x0);
    return;
  }
  mousemask(0,(ulong *)0x0);
  return;
}

