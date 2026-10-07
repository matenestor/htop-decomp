/* LinuxProcess_new @ 0013e8b0 size 89 */

Process_3 * LinuxProcess_new(Machine_3 *host)

{
  Process_3 *pPVar1;

                    /* Unresolved local var: void * data@[???] */
  pPVar1 = calloc(1,0x348);
  if (pPVar1 != (Process_3 *)0x0) {
    (pPVar1->super).host = host;
    (pPVar1->super).tag = false;
    (pPVar1->super).show = true;
    (pPVar1->super).wasShown = false;
    (pPVar1->super).showChildren = true;
    (pPVar1->super).super.klass = (ObjectClass *)&LinuxProcess_class;
    (pPVar1->super).updated = false;
    pPVar1->cmdlineBasenameEnd = L'\xffffffff';
    pPVar1->st_uid = 0xffffffff;
    return pPVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

