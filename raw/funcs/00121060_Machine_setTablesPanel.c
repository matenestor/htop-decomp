/* Machine_setTablesPanel @ 00121060 size 49 */

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

