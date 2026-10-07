#include "htop.h"

/* UsersTable_foreach @ 0x12e2e0 */

/* DWARF original prototype: void UsersTable_foreach(UsersTable * this, Hashtable_PairFunction f,
   void * userData) */

void UsersTable_foreach(UsersTable *this,Hashtable_PairFunction f,void *userData)

{
  Hashtable_2 *pHVar1;
  void *pvVar2;
  long in_RCX;
  ulong uVar3;
  long in_R8;
  long in_R9;

  pHVar1 = this->users;
                    /* Unresolved local var: size_t i@[???] */
  if (pHVar1->size != 0) {
    uVar3 = 0;
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
      pvVar2 = pHVar1->buckets[uVar3].value;
      if (pvVar2 != (void *)0x0) {
        (*(code *)(f))(pHVar1->buckets[uVar3].key,pvVar2,userData,in_RCX,in_R8,in_R9);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < pHVar1->size);
  }
  return;
}


/* UsersTable_delete @ 0x12f9d0 */

/* DWARF original prototype: void UsersTable_delete(UsersTable * this) */

void UsersTable_delete(UsersTable *this)

{
  Hashtable *this_00;

  this_00 = this->users;
  Hashtable_clear(this_00);
  free(this_00->buckets);
  free(this_00);
  free(this);
  return;
}


/* UsersTable_new @ 0x132c60 */

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


/* UsersTable_getRef @ 0x132ca0 */

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

