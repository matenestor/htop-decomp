/* UptimeMeter_updateValues @ 0012fec0 size 487 */

/* DWARF original prototype: void UptimeMeter_updateValues(Meter * this) */

void UptimeMeter_updateValues(Meter *this)

{
  long lVar1;
  int va0;
  wchar_t wVar2;
  int iVar3;
  int iVar4;
  long in_FS_OFFSET;
  double dVar5;
  char daysbuf [32];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = Platform_getUptime();
  if (wVar2 < L'\x01') {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      xSnprintf(this->txtBuffer,0x100,((char *)0x149029 /* "(unknown)" */));
      return;
    }
    goto LAB_001300b7;
  }
  iVar4 = wVar2 >> 0x1f;
  iVar3 = wVar2 / 0x3c + iVar4;
  va0 = wVar2 / 0x15180;
  dVar5 = (double)va0;
  *this->values = dVar5;
  if (this->total <= dVar5 && dVar5 != this->total) {
    this->total = dVar5;
    if (L'\x0085277f' < wVar2) goto LAB_00130018;
LAB_0012ff9d:
    if (wVar2 < L'𪌀') {
      if (va0 == 1) {
        xSnprintf(daysbuf,0x20,((char *)0x14904a /* "1 day, " */));
      }
      else {
        daysbuf[0] = '\0';
      }
    }
    else {
      xSnprintf(daysbuf,0x20,((char *)0x149040 /* "%d days, " */),va0);
    }
  }
  else {
    if (wVar2 < L'\x00852780') goto LAB_0012ff9d;
LAB_00130018:
    xSnprintf(daysbuf,0x20,((char *)0x149033 /* "%d days(!), " */),va0);
  }
  xSnprintf(this->txtBuffer,0x100,((char *)0x149052 /* "%s%02d:%02d:%02d" */),daysbuf,(uint)(wVar2 / 0xe10) % 0x18,
            (uint)(iVar3 - iVar4) % 0x3c,wVar2 + (iVar3 - iVar4) * -0x3c);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_001300b7:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

