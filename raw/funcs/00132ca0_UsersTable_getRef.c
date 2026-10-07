/* UsersTable_getRef @ 00132ca0 size 184 */

/* DWARF original prototype: char * UsersTable_getRef(UsersTable * this, uint uid) */

char * UsersTable_getRef(UsersTable *this,uint uid)

{
  ulong uVar1;
  HashtableItem *pHVar2;
  passwd *ppVar3;
  char *pcVar4;
  HashtableItem *pHVar5;
  ulong uVar6;
  ulong uVar7;

                    /* Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
  uVar1 = this->users->size;
  pHVar2 = this->users->buckets;
  uVar6 = (ulong)uid % uVar1;
  pcVar4 = pHVar2[uVar6].value;
  if (pcVar4 != (char *)0x0) {
    uVar7 = 0;
    pHVar5 = pHVar2 + uVar6;
    do {
      while( true ) {
        if (uid == pHVar5->key) {
          return pcVar4;
        }
        if (pHVar5->probe < uVar7) goto LAB_00132d20;
        uVar6 = uVar6 + 1;
        if (uVar1 != uVar6) break;
        uVar6 = 0;
        uVar7 = uVar7 + 1;
        pcVar4 = pHVar2->value;
        pHVar5 = pHVar2;
        if (pcVar4 == (char *)0x0) goto LAB_00132d20;
      }
      uVar7 = uVar7 + 1;
      pHVar5 = pHVar2 + uVar6;
      pcVar4 = pHVar5->value;
    } while (pcVar4 != (char *)0x0);
  }
LAB_00132d20:
                    /* Unresolved local var: char * name@[???]
                       Unresolved local var: passwd * userData@[???] */
  ppVar3 = getpwuid(uid);
  pcVar4 = (char *)0x0;
  if (ppVar3 != (passwd *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = strdup(ppVar3->pw_name);
    if (pcVar4 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    Hashtable_put(this->users,uid,pcVar4);
  }
  return pcVar4;
}

