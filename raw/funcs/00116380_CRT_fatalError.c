/* CRT_fatalError @ 00116380 size 79 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CRT_fatalError(char *note)

{
  int *piVar1;
  char *va1;

  piVar1 = __errno_location();
  va1 = strerror(*piVar1);
  CRT_done();
  __fprintf_chk(_stderr,2,((char *)0x14716f /* "%s: %s\n" */),note,va1);
                    /* WARNING: Subroutine does not return */
  exit(2);
}

