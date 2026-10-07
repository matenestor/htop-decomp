/* Machine_scanTables @ 001210a0 size 429 */

/* DWARF original prototype: void Machine_scanTables(Machine * this) */

void Machine_scanTables(Machine *this)

{
  wchar_t *pwVar1;
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
  long in_FS_OFFSET;
  double dVar13;
  timespec ts;

  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  if (firstScanDone) {
    in_RSI = (RichString *)&ts;
    uVar7 = clock_gettime(1,(timespec_2 *)in_RSI);
    in_RDX = (ulong)uVar7;
    uVar9 = 0;
    if (uVar7 == 0) {
      in_RDX = (ulong)ts.tv_nsec / 1000000;
      uVar9 = ts.tv_sec * 1000 + in_RDX;
    }
    this->monotonicMs = uVar9;
  }
  else {
    firstScanDone = true;
  }
  puVar11 = Row_fieldWidths;
  this->maxUserId = 0;
                    /* Unresolved local var: size_t i@[???] */
  ppcVar10 = &Process_fields[0].title;
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
                    /* Unresolved local var: wchar_t i@[???] */
          a2_00 = this_00->rows;
          pwVar1 = &a2_00->items;
          if (L'\0' < *pwVar1) {
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
          (*a3[1].extends)((long)this_00,(long)in_RSI,in_RDX,(long)a3,in_R8,in_R9);
          a3 = (this_00->super).klass;
          a2_00 = extraout_RDX_00;
        }
        (*a3[1].display)(&this_00->super,in_RSI,(long)a2_00,(long)a3,in_R8,in_R9);
        p_Var5 = (this_00->super).klass[1].delete;
        if (p_Var5 == (Object_Delete)0x0) break;
        (*p_Var5)(&this_00->super,(long)in_RSI,a2,(long)a3,in_R8,in_R9);
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
      Row_uidDigits = (int)dVar13 + L'\x01';
      goto LAB_001211ec;
    }
  }
  Row_uidDigits = L'\x05';
LAB_001211ec:
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

