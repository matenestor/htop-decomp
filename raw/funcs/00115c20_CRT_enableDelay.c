/* CRT_enableDelay @ 00115c20 size 18 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CRT_enableDelay(void)

{
  halfdelay(*CRT_delay);
  return;
}

