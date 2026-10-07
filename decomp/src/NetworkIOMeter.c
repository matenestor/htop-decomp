#include "htop.h"

/* NetworkIOMeter_display @ 0x1296f0 */

void NetworkIOMeter_display(Object *cast,RichString *out)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  long lVar1;
  int wVar2;
  char *data;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (status_15c060 == RATESTATUS_NODATA) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      wVar2 = CRT_colors[0x10];
      data = ((char *)(long)&s_no_data_001476cb /* "no data" */);
LAB_00129831:
      RichString_writeAscii(out,wVar2,data);
      return;
    }
  }
  else if (status_15c060 == RATESTATUS_STALE) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      wVar2 = CRT_colors[0x15];
      data = ((char *)(long)&s_stale_data_00147702 /* "stale data" */);
      goto LAB_00129831;
    }
  }
  else if (status_15c060 == RATESTATUS_INIT) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      wVar2 = CRT_colors[0xf];
      data = ((char *)(long)&s_initializing____001476f2 /* "initializing..." */);
      goto LAB_00129831;
    }
  }
  else {
    RichString_writeAscii(out,CRT_colors[0xe],((char *)(long)&DAT_001488c4 /* "rx: " */));
    RichString_appendAscii(out,CRT_colors[0x11],cached_rxb_diff_str);
    RichString_appendAscii(out,CRT_colors[0x11],((char *)(long)&DAT_00147715 /* "iB/s" */));
    RichString_appendAscii(out,CRT_colors[0xe],((char *)(long)&s_tx__001488c9 /* " tx: " */));
    RichString_appendAscii(out,CRT_colors[0x12],cached_txb_diff_str);
    RichString_appendAscii(out,CRT_colors[0x12],((char *)(long)&DAT_00147715 /* "iB/s" */));
    wVar2 = xSnprintf((*(char (*) [64])(__fp - 0x78)),0x40,((char *)(long)&s___u__u_pkts_s__001488cf /* " (%u/%u pkts/s) " */),cached_rxp_diff,cached_txp_diff);
    RichString_appendnAscii(out,CRT_colors[0xe],(*(char (*) [64])(__fp - 0x78)),wVar2);
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* NetworkIOMeter_updateValues @ 0x129fb0 */

/* DWARF original prototype: void NetworkIOMeter_updateValues(Meter * this) */

void NetworkIOMeter_updateValues(Meter *this)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  char *buf;
  Machine *pMVar1;
  long lVar2;
  double *pdVar3;
  MeterRateStatus MVar4;
  _Bool _Var5;
  ulong uVar6;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar7;
  double dVar8;
  double dVar9;

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
        xSnprintf(buf,0x100,((char *)(long)(__sec_rodata + 0x29bf) /* "init" */));
      }
      else if (MVar4 == RATESTATUS_STALE) {
        xSnprintf(buf,0x100,((char *)(long)&s_stale_001476d3 /* "stale" */));
      }
      else {
        xSnprintf(buf,0x100,((char *)(long)&s_rx__siB_s_tx__siB_s__u__upkts_s_0014c4f8 /* "rx:%siB/s tx:%siB/s %u/%upkts/s" */),cached_rxb_diff_str,
                  cached_txb_diff_str,cached_rxp_diff,cached_txp_diff);
      }
      goto LAB_0012a079;
    }
  }
  else {
    _Var5 = Platform_getNetworkIO(&(*(NetworkIOData (*))(__fp - 0x58)));
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
        if (cached_rxb_total < (*(NetworkIOData (*))(__fp - 0x58)).bytesReceived) {
          cached_rxb_diff = (double)(long)((((*(NetworkIOData (*))(__fp - 0x58)).bytesReceived - cached_rxb_total) * 1000) / uVar6)
          ;
          dVar9 = cached_rxb_diff * 0.0009765625;
        }
        else {
          dVar9 = 0.0;
          cached_rxb_diff = 0.0;
        }
        Meter_humanUnit(cached_rxb_diff_str,dVar9,6);
        cached_rxp_diff = 0;
        if (cached_rxp_total < (*(NetworkIOData (*))(__fp - 0x58)).packetsReceived) {
          cached_rxp_diff = (uint32_t)((((*(NetworkIOData (*))(__fp - 0x58)).packetsReceived - cached_rxp_total) * 1000) / uVar6);
        }
        if (cached_txb_total < (*(NetworkIOData (*))(__fp - 0x58)).bytesTransmitted) {
          cached_txb_diff =
               (double)(long)((((*(NetworkIOData (*))(__fp - 0x58)).bytesTransmitted - cached_txb_total) * 1000) / uVar6);
          dVar9 = cached_txb_diff * 0.0009765625;
        }
        else {
          dVar9 = 0.0;
          cached_txb_diff = 0.0;
        }
        Meter_humanUnit(cached_txb_diff_str,dVar9,6);
        if (cached_txp_total < (*(NetworkIOData (*))(__fp - 0x58)).packetsTransmitted) {
          cached_txp_diff =
               (uint32_t)((((*(NetworkIOData (*))(__fp - 0x58)).packetsTransmitted - cached_txp_total) * 1000) / uVar6);
        }
        else {
          cached_txp_diff = 0;
        }
      }
      cached_rxb_total = (*(NetworkIOData (*))(__fp - 0x58)).bytesReceived;
      cached_rxp_total = (*(NetworkIOData (*))(__fp - 0x58)).packetsReceived;
      cached_txb_total = (*(NetworkIOData (*))(__fp - 0x58)).bytesTransmitted;
      cached_txp_total = (*(NetworkIOData (*))(__fp - 0x58)).packetsTransmitted;
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
  xSnprintf(this->txtBuffer,0x100,((char *)(long)&s_no_data_001476cb /* "no (*(NetworkIOData (*))(__fp - 0x58))" */));
LAB_0012a079:
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

