#include "htop.h"

/* Machine_done @ 0x121030 */

/* DWARF original prototype: void Machine_done(Machine * this) */

void Machine_done(Machine *this)

{
  long in_RCX;
  long in_RDX;
  long in_RSI;
  long in_R8;
  long in_R9;

  (*(code *)(((this->processTable->super).klass)->delete))
            (&this->processTable->super,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
  free(this->tables);
  return;
}


/* Machine_setTablesPanel @ 0x121060 */

/* DWARF original prototype: void Machine_setTablesPanel(Machine * this, Panel * panel) */

void Machine_setTablesPanel(Machine *this,Panel *panel)

{
  Table **ppTVar1;
  Table *pTVar2;
  Table **ppTVar3;

                    /* Unresolved local var: size_t i@[???] */
  if (this->tableCount != 0) {
    ppTVar3 = this->tables;
    ppTVar1 = ppTVar3 + this->tableCount;
    do {
      pTVar2 = *ppTVar3;
      ppTVar3 = ppTVar3 + 1;
      pTVar2->panel = panel;
    } while (ppTVar3 != ppTVar1);
  }
  return;
}


/* Machine_scanTables @ 0x1210a0 */

/* DWARF original prototype: void Machine_scanTables(Machine * this) */

void Machine_scanTables(Machine *this)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  int *pwVar1;
  Object **ppOVar2;
  byte bVar3;
  long lVar4;
  Object_Delete p_Var5;
  Table *this_00;
  Object *pOVar6;
  uint uVar7;
  size_t sVar8;
  uint64_t uVar9;
  ObjectClass *a3;
  ulong in_RDX;
  ulong extraout_RDX;
  Vector *extraout_RDX_00;
  long a2;
  ulong extraout_RDX_01;
  Vector *a2_00;
  ulong extraout_RDX_02;
  char **ppcVar10;
  RichString *in_RSI;
  long in_R8;
  long in_R9;
  uint8_t *puVar11;
  ulong uVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar13;

  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  if (firstScanDone) {
    in_RSI = (RichString *)&(*(timespec (*))(__fp - 0x48));
    uVar7 = clock_gettime(1,(timespec_2 *)in_RSI);
    in_RDX = (ulong)uVar7;
    uVar9 = 0;
    if (uVar7 == 0) {
      in_RDX = (ulong)(*(timespec (*))(__fp - 0x48)).tv_nsec / 1000000;
      uVar9 = (*(timespec (*))(__fp - 0x48)).tv_sec * 1000 + in_RDX;
    }
    this->monotonicMs = uVar9;
  }
  else {
    firstScanDone = true;
  }
  puVar11 = Row_fieldWidths;
  this->maxUserId = 0;
                    /* Unresolved local var: size_t i@[???] */
  ppcVar10 = &Process_fields_0__title;
  do {
                    /* Unresolved local var: size_t len@[???] */
    if (*(_Bool *)((long)ppcVar10 + 0x16) != false) {
      sVar8 = strlen(*ppcVar10);
      *puVar11 = (uint8_t)sVar8;
      in_RDX = extraout_RDX;
    }
    ppcVar10 = ppcVar10 + 4;
    puVar11 = puVar11 + 1;
  } while (ppcVar10 != MetersMovingKeys + 1);
                    /* Unresolved local var: size_t i@[???] */
  uVar12 = 0;
  if (this->tableCount != 0) {
    do {
      while( true ) {
        this_00 = this->tables[uVar12];
        a3 = (this_00->super).klass;
        if (a3[1].extends == (code *)0x0) {
                    /* Unresolved local var: int i@[???] */
          a2_00 = this_00->rows;
          pwVar1 = &a2_00->items;
          if (0 < *pwVar1) {
            a2_00 = (Vector *)a2_00->array;
            ppOVar2 = (Object **)((long)a2_00 + (long)*pwVar1 * 8);
            do {
                    /* Unresolved local var: Row * row@[???] */
              pOVar6 = *(Object **)a2_00;
              a2_00 = (Vector *)((long)a2_00 + 8);
              bVar3 = *(byte *)((long)&pOVar6[3].klass + 6);
              in_RSI = (RichString *)(ulong)bVar3;
              *(undefined1 *)((long)&pOVar6[4].klass + 1) = 0;
              *(undefined1 *)((long)&pOVar6[3].klass + 6) = 1;
              *(byte *)((long)&pOVar6[3].klass + 7) = bVar3;
            } while ((Vector *)ppOVar2 != a2_00);
          }
        }
        else {
                    /* Unresolved local var: Table * table@[???] */
          (*(code *)(a3[1].extends))((long)this_00,(long)in_RSI,in_RDX,(long)a3,in_R8,in_R9);
          a3 = (this_00->super).klass;
          a2_00 = extraout_RDX_00;
        }
        (*(code *)(a3[1].display))(&this_00->super,in_RSI,(long)a2_00,(long)a3,in_R8,in_R9);
        p_Var5 = (this_00->super).klass[1].delete;
        if (p_Var5 == (Object_Delete)0x0) break;
        (*(code *)(p_Var5))(&this_00->super,(long)in_RSI,a2,(long)a3,in_R8,in_R9);
        uVar12 = uVar12 + 1;
        in_RDX = extraout_RDX_01;
        if (this->tableCount <= uVar12) goto LAB_001211c2;
      }
      Table_cleanupEntries(this_00);
      uVar12 = uVar12 + 1;
      in_RDX = extraout_RDX_02;
    } while (uVar12 < this->tableCount);
LAB_001211c2:
    if (99999 < this->maxUserId) {
      dVar13 = log10((double)this->maxUserId);
      Row_uidDigits = (int)dVar13 + 1;
      goto LAB_001211ec;
    }
  }
  Row_uidDigits = 5;
LAB_001211ec:
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Machine_populateTablesFromSettings @ 0x1233f0 */

/* DWARF original prototype: void Machine_populateTablesFromSettings(Machine * this, Settings *
   settings, Table * processTable) */

void Machine_populateTablesFromSettings(Machine *this,Settings_4 *settings,Table_2 *processTable)

{
  uint uVar1;
  Table **__ptr;
  size_t sVar2;
  Table **ppTVar3;
  size_t sVar4;
  ulong uVar5;
  Table_2 *pTVar6;

                    /* Unresolved local var: size_t i@[???] */
  uVar1 = settings->nScreens;
  this->settings = (Settings__2 *)settings;
  this->processTable = (Table *)processTable;
  if (uVar1 == 0) {
    return;
  }
  uVar5 = 0;
LAB_00123428:
                    /* Unresolved local var: ScreenSettings * ss@[???]
                       Unresolved local var: Table * table@[???] */
  pTVar6 = settings->screens[uVar5]->table;
  if (pTVar6 == (Table_2 *)0x0) {
    settings->screens[uVar5]->table = processTable;
    pTVar6 = processTable;
  }
  if (uVar5 == 0) {
    this->activeTable = (Table *)pTVar6;
  }
                    /* Unresolved local var: size_t nmemb@[???]
                       Unresolved local var: Table * * tables@[???]
                       Unresolved local var: size_t i@[???] */
  __ptr = this->tables;
  if (this->tableCount != 0) goto code_r0x00123460;
  sVar4 = 8;
  goto LAB_001234b3;
code_r0x00123460:
  sVar4 = 0;
  do {
    sVar2 = sVar4;
    if (pTVar6 == (Table_2 *)__ptr[sVar2]) {
      uVar5 = uVar5 + 1;
      if (settings->nScreens <= uVar5) {
        return;
      }
      goto LAB_00123428;
    }
    sVar4 = sVar2 + 1;
  } while (sVar2 + 1 != this->tableCount);
  if (sVar2 + 2 != 0x2000000000000000) {
    sVar4 = (sVar2 + 2) * 8;
LAB_001234b3:
                    /* Unresolved local var: void * data@[???] */
    ppTVar3 = realloc(__ptr,sVar4);
    if (ppTVar3 != (Table **)0x0) {
      *(Table_2 **)((long)ppTVar3 + (sVar4 - 8)) = pTVar6;
      uVar5 = uVar5 + 1;
      this->tables = ppTVar3;
      uVar1 = settings->nScreens;
      this->tableCount = this->tableCount + 1;
      if (uVar1 <= uVar5) {
        return;
      }
      goto LAB_00123428;
    }
    free(__ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Machine_init @ 0x129090 */

/* DWARF original prototype: void Machine_init(Machine * this, UsersTable * usersTable, uid_t
   userId) */

void Machine_init(Machine *this,UsersTable *usersTable,uid_t userId)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  __uid_t _Var1;
  int wVar2;
  FILE_2 *__stream;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar3;

  (*(long (*))(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  this->usersTable = usersTable;
  this->userId = userId;
  _Var1 = getuid();
                    /* Unresolved local var: FILE * file@[???]
                       Unresolved local var: int match@[???] */
  (*(pid_t (*))(__fp - 0x24)) = 0x3fffff;
  this->htopUserId = _Var1;
  __stream = fopen(((char *)(long)&s__proc_sys_kernel_pid_max_00148869 /* "/proc/sys/kernel/pid_max" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE_2 *)0x0) {
    __isoc23_fscanf(__stream,((char *)(long)&DAT_0014978b /* "%32d" */),&(*(pid_t (*))(__fp - 0x24)));
    fclose(__stream);
  }
  wVar2 = 5;
  if (99999 < (*(pid_t (*))(__fp - 0x24))) {
    dVar3 = log10((double)(*(pid_t (*))(__fp - 0x24)));
    wVar2 = (int)dVar3 + 1;
  }
  Row_pidDigits = wVar2;
  if ((*(long (*))(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    Generic_gettime_realtime(&this->realtime,&this->realtimeMs);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

