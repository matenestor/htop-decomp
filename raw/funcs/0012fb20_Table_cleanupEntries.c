/* Table_cleanupEntries @ 0012fb20 size 215 */

/* DWARF original prototype: void Table_cleanupEntries(Table * this) */

void Table_cleanupEntries(Table *this)

{
  wchar_t key;
  Machine_ *pMVar1;
  long lVar2;
  wchar_t idx;
  Vector *this_00;
  long lVar3;

                    /* Unresolved local var: wchar_t i@[???] */
  this_00 = this->rows;
  idx = this_00->items + L'\xffffffff';
  if (L'\xffffffff' < idx) {
    lVar3 = (long)idx << 3;
LAB_0012fb62:
    do {
      pMVar1 = this->host;
      lVar2 = *(long *)((long)this_00->array + lVar3);
      if (*(ulong *)(lVar2 + 0x38) == 0) {
        if (*(char *)(lVar2 + 0x21) == '\0') {
          if ((pMVar1->settings->highlightChanges != false) && (*(char *)(lVar2 + 0x1f) != '\0')) {
            idx = idx + L'\xffffffff';
            lVar3 = lVar3 + -8;
            *(uint64_t *)(lVar2 + 0x38) =
                 (long)(pMVar1->settings->highlightDelaySecs * 1000) + pMVar1->monotonicMs;
            if (idx == L'\xffffffff') break;
            goto LAB_0012fb62;
          }
LAB_0012fbc0:
                    /* Unresolved local var: wchar_t rowid@[???] */
          key = *(wchar_t *)(lVar2 + 0x10);
          Hashtable_remove(this->table,key);
          Vector_softRemove(this->rows,idx);
          if ((key == this->following) && (this->following != L'\xffffffff')) {
            this->following = L'\xffffffff';
            this->panel->selectionColorId = PANEL_SELECTION_FOCUS;
          }
                    /* Unresolved local var: wchar_t rowid@[???] */
          this_00 = this->rows;
        }
      }
      else {
                    /* Unresolved local var: Row * row@[???]
                       Unresolved local var: Machine * host@[???]
                       Unresolved local var: Settings * settings@[???] */
        if (*(ulong *)(lVar2 + 0x38) <= pMVar1->monotonicMs) goto LAB_0012fbc0;
      }
      idx = idx + L'\xffffffff';
      lVar3 = lVar3 + -8;
    } while (idx != L'\xffffffff');
  }
  Vector_compact(this_00);
  return;
}

