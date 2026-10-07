/* DynamicColumns_new @ 00117dd0 size 88 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

Hashtable_2 * DynamicColumns_new(void)

{
  Hashtable_2 *pHVar1;
  HashtableItem *pHVar2;

                    /* Unresolved local var: Hashtable * this@[???]
                       Unresolved local var: void * data@[???] */
  pHVar1 = malloc(0x20);
  if (pHVar1 != (Hashtable_2 *)0x0) {
    pHVar1->items = 0;
                    /* Unresolved local var: void * data@[???] */
    pHVar1->size = 0xd;
    pHVar2 = calloc(0xd,0x18);
    if (pHVar2 != (HashtableItem *)0x0) {
      pHVar1->buckets = pHVar2;
      pHVar1->owner = true;
      return pHVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

