/* CRT_handleSIGTERM @ 00116360 size 20 */

void CRT_handleSIGTERM(wchar_t sgn)

{
  CRT_done();
                    /* WARNING: Subroutine does not return */
  _exit(0);
}

