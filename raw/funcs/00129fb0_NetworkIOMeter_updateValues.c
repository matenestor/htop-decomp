/* NetworkIOMeter_updateValues @ 00129fb0 size 838 */

/* DWARF original prototype: void NetworkIOMeter_updateValues(Meter * this) */

void NetworkIOMeter_updateValues(Meter *this)

{
  char *buf;
  Machine *pMVar1;
  long lVar2;
  double *pdVar3;
  MeterRateStatus MVar4;
  _Bool _Var5;
  ulong uVar6;
  long in_FS_OFFSET;
  bool bVar7;
  double dVar8;
  double dVar9;
  NetworkIOData data;

  pMVar1 = this->host;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  uVar6 = pMVar1->realtimeMs - cached_last_update_15d650;
  if (uVar6 < 0x1f5) {
LAB_00129ff5:
    dVar9 = cached_txb_diff;
    MVar4 = status_15c060;
    pdVar3 = this->values;
    dVar8 = cached_rxb_diff + cached_txb_diff;
    *pdVar3 = cached_rxb_diff;
    pdVar3[1] = dVar9;
    if (this->total <= dVar8 && dVar8 != this->total) {
      this->total = dVar8;
    }
    if (MVar4 != RATESTATUS_NODATA) {
      buf = this->txtBuffer;
      if (MVar4 == RATESTATUS_INIT) {
        xSnprintf(buf,0x100,((char *)0x1499bf /* "init" */));
      }
      else if (MVar4 == RATESTATUS_STALE) {
        xSnprintf(buf,0x100,((char *)0x1476d3 /* "stale" */));
      }
      else {
        xSnprintf(buf,0x100,((char *)0x14c4f8 /* "rx:%siB/s tx:%siB/s %u/%upkts/s" */),cached_rxb_diff_str,
                  cached_txb_diff_str,cached_rxp_diff,cached_txp_diff);
      }
      goto LAB_0012a079;
    }
  }
  else {
    _Var5 = Platform_getNetworkIO(&data);
    dVar9 = cached_txb_diff;
    if (_Var5) {
      bVar7 = cached_last_update_15d650 == 0;
      cached_last_update_15d650 = pMVar1->realtimeMs;
      if (bVar7) {
        status_15c060 = RATESTATUS_INIT;
      }
      else {
                    /* Unresolved local var: uint64_t diff@[???] */
        status_15c060 = ~-(uint)(uVar6 < 0x7531) & RATESTATUS_STALE;
        if (cached_rxb_total < data.bytesReceived) {
          cached_rxb_diff = (double)(long)(((data.bytesReceived - cached_rxb_total) * 1000) / uVar6)
          ;
          dVar9 = cached_rxb_diff * 0.0009765625;
        }
        else {
          dVar9 = 0.0;
          cached_rxb_diff = 0.0;
        }
        Meter_humanUnit(cached_rxb_diff_str,dVar9,6);
        cached_rxp_diff = 0;
        if (cached_rxp_total < data.packetsReceived) {
          cached_rxp_diff = (uint32_t)(((data.packetsReceived - cached_rxp_total) * 1000) / uVar6);
        }
        if (cached_txb_total < data.bytesTransmitted) {
          cached_txb_diff =
               (double)(long)(((data.bytesTransmitted - cached_txb_total) * 1000) / uVar6);
          dVar9 = cached_txb_diff * 0.0009765625;
        }
        else {
          dVar9 = 0.0;
          cached_txb_diff = 0.0;
        }
        Meter_humanUnit(cached_txb_diff_str,dVar9,6);
        if (cached_txp_total < data.packetsTransmitted) {
          cached_txp_diff =
               (uint32_t)(((data.packetsTransmitted - cached_txp_total) * 1000) / uVar6);
        }
        else {
          cached_txp_diff = 0;
        }
      }
      cached_rxb_total = data.bytesReceived;
      cached_rxp_total = data.packetsReceived;
      cached_txb_total = data.bytesTransmitted;
      cached_txp_total = data.packetsTransmitted;
      goto LAB_00129ff5;
    }
    cached_last_update_15d650 = pMVar1->realtimeMs;
    status_15c060 = RATESTATUS_NODATA;
    pdVar3 = this->values;
    dVar8 = cached_txb_diff + cached_rxb_diff;
    *pdVar3 = cached_rxb_diff;
    pdVar3[1] = dVar9;
    if (this->total <= dVar8 && dVar8 != this->total) {
      this->total = dVar8;
    }
  }
  xSnprintf(this->txtBuffer,0x100,((char *)0x1476cb /* "no data" */));
LAB_0012a079:
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

