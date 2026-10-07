/* Table_cleanupRow @ 0012fac0 size 71 */

void Table_cleanupRow(Table_2 *table,Row_2 *row,wchar_t idx)

{
  Machine__2 *pMVar1;

  pMVar1 = table->host;
  if (row->tombStampMs == 0) {
    if (row->updated == false) {
      if ((pMVar1->settings->highlightChanges != false) && (row->wasShown != false)) {
        row->tombStampMs = (long)(pMVar1->settings->highlightDelaySecs * 1000) + pMVar1->monotonicMs
        ;
        return;
      }
      goto LAB_0012fb10;
    }
  }
  else if (row->tombStampMs <= pMVar1->monotonicMs) {
LAB_0012fb10:
    Table_removeIndex((Table *)table,row,idx);
    return;
  }
  return;
}

