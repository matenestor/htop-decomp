/* ProcessTable_cleanupEntries @ 0012d160 size 151 */

void ProcessTable_cleanupEntries(Table_2 *super)

{
  Machine__2 *pMVar1;
  Settings__3 *settings;
  Process *this;
  wchar_t idx;
  wchar_t wVar2;
  Vector *this_00;
  long lVar3;

  pMVar1 = super->host;
                    /* Unresolved local var: wchar_t i@[???] */
  this_00 = super->rows;
  settings = pMVar1->settings;
  idx = this_00->items + L'\xffffffff';
  if (L'\xffffffff' < idx) {
    lVar3 = (long)idx << 3;
    do {
                    /* Unresolved local var: Process * p@[???] */
      this = *(Process **)((long)this_00->array + lVar3);
      Process_makeCommandStr(this,(Settings_5 *)settings);
      if (pMVar1->maxUserId < this->st_uid) {
        pMVar1->maxUserId = this->st_uid;
      }
      wVar2 = idx + L'\xffffffff';
      Table_cleanupRow(super,(Row_2 *)this,idx);
      lVar3 = lVar3 + -8;
      this_00 = super->rows;
      idx = wVar2;
    } while (wVar2 != L'\xffffffff');
  }
  Vector_compact(this_00);
  return;
}

