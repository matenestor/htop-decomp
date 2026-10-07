/* Row_setPidColumnWidth @ 00120fe0 size 62 */

void Row_setPidColumnWidth(pid_t maxPid)

{
  double dVar1;

  if (maxPid < 100000) {
    Row_pidDigits = L'\x05';
    return;
  }
  dVar1 = log10((double)maxPid);
  Row_pidDigits = (int)dVar1 + L'\x01';
  return;
}

