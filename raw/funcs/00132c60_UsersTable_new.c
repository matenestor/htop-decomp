/* UsersTable_new @ 00132c60 size 63 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

UsersTable * UsersTable_new(void)

{
  UsersTable *pUVar1;
  Hashtable *pHVar2;

                    /* Unresolved local var: void * data@[???] */
  pUVar1 = malloc(8);
  if (pUVar1 != (UsersTable *)0x0) {
    pHVar2 = Hashtable_new(10,true);
    pUVar1->users = pHVar2;
    return pUVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

