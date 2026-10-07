/* fail @ 001300c0 size 18 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void fail(void)

{
  CRT_done();
                    /* WARNING: Subroutine does not return */
  abort();
}

