/* Row_setUidColumnWidth @ 00121260 size 65 */

void Row_setUidColumnWidth(uid_t maxUid)

{
  double dVar1;

  if (maxUid < 100000) {
    Row_uidDigits = L'\x05';
    return;
  }
  dVar1 = log10((double)maxUid);
  Row_uidDigits = (int)dVar1 + L'\x01';
  return;
}

