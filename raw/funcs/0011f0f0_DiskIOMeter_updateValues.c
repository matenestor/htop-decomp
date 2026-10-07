/* DiskIOMeter_updateValues @ 0011f0f0 size 748 */

/* DWARF original prototype: void DiskIOMeter_updateValues(Meter * this) */

void DiskIOMeter_updateValues(Meter *this)

{
  char *buf;
  Machine *pMVar1;
  long lVar2;
  MeterRateStatus MVar3;
  _Bool _Var4;
  ulong uVar5;
  long in_FS_OFFSET;
  bool bVar6;
  double dVar7;
  DiskIOData data;

  pMVar1 = this->host;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = pMVar1->realtimeMs - cached_last_update;
  if (uVar5 < 0x1f5) {
LAB_0011f139:
    dVar7 = cached_utilisation_diff;
    MVar3 = status;
    *this->values = cached_utilisation_diff;
    if (MVar3 != RATESTATUS_NODATA) {
      buf = this->txtBuffer;
      if (MVar3 == RATESTATUS_INIT) {
        xSnprintf(buf,0x100,((char *)0x1499bf /* "init" */));
      }
      else if (MVar3 == RATESTATUS_STALE) {
        xSnprintf(buf,0x100,((char *)0x1476d3 /* "stale" */));
      }
      else {
        xSnprintf(buf,0x100,((char *)0x1476d9 /* "r:%siB/s w:%siB/s %.1f%%" */),cached_read_diff_str,cached_write_diff_str,
                  dVar7);
      }
      goto LAB_0011f187;
    }
  }
  else {
    _Var4 = Platform_getDiskIO(&data);
    if (_Var4) {
      bVar6 = cached_last_update == 0;
      cached_last_update = pMVar1->realtimeMs;
      if (bVar6) {
        status = RATESTATUS_INIT;
      }
      else {
                    /* Unresolved local var: uint64_t diff@[???] */
        dVar7 = 0.0;
        status = ~-(uint)(uVar5 < 0x7531) & RATESTATUS_STALE;
        if (cached_read_total < data.totalBytesRead) {
          dVar7 = (double)(((data.totalBytesRead - cached_read_total) * 1000) / uVar5 >> 10);
        }
        Meter_humanUnit(cached_read_diff_str,dVar7,6);
        dVar7 = 0.0;
        if (cached_write_total < data.totalBytesWritten) {
          dVar7 = (double)(((data.totalBytesWritten - cached_write_total) * 1000) / uVar5 >> 10);
        }
        Meter_humanUnit(cached_write_diff_str,dVar7,6);
        if (cached_msTimeSpend_total < data.totalMsTimeSpend) {
          cached_utilisation_diff =
               ((double)(data.totalMsTimeSpend - cached_msTimeSpend_total) * 100.0) / (double)uVar5;
          if (100.0 <= cached_utilisation_diff) {
            cached_utilisation_diff = 100.0;
          }
        }
        else {
          cached_utilisation_diff = 0.0;
        }
      }
      cached_read_total = data.totalBytesRead;
      cached_write_total = data.totalBytesWritten;
      cached_msTimeSpend_total = data.totalMsTimeSpend;
      goto LAB_0011f139;
    }
    cached_last_update = pMVar1->realtimeMs;
    status = RATESTATUS_NODATA;
    *this->values = cached_utilisation_diff;
  }
  xSnprintf(this->txtBuffer,0x100,((char *)0x1476cb /* "no data" */));
LAB_0011f187:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

