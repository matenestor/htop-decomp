/* FunctionBar_newEnterEsc @ 00117fc0 size 88 */

FunctionBar * FunctionBar_newEnterEsc(char *enter,char *esc)

{
  long lVar1;
  FunctionBar *pFVar2;
  long in_FS_OFFSET;
  char *functions [3];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  functions[2] = (char *)0x0;
  functions[0] = enter;
  functions[1] = esc;
  pFVar2 = FunctionBar_new(functions,FunctionBar_EnterEscKeys,((char *)0x14d258 /* L"\r\x1b" */));
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pFVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

