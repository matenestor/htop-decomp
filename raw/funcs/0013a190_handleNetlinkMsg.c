/* handleNetlinkMsg @ 0013a190 size 603 */

wchar_t handleNetlinkMsg(nl_msg *nlmsg,void *linuxProcess)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  wchar_t wVar4;
  void *pvVar5;
  undefined8 *puVar6;
  long lVar7;
  ulong uVar8;
  taskstats *ptVar9;
  long in_FS_OFFSET;
  byte bVar10;
  float fVar11;
  float fVar12;
  wchar_t rem;
  nlattr *nlattrs [7];
  taskstats stats;

  bVar10 = 0;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  pvVar5 = nlmsg_hdr(nlmsg);
  iVar3 = genlmsg_parse(pvVar5,0,nlattrs,6,(void *)0x0);
  wVar4 = L'\x01';
  if (iVar3 < 0) goto LAB_0013a28c;
  if ((nlattrs[4] != (nlattr *)0x0) || (nlattrs[4] = nlattrs[6], nlattrs[6] != (nlattr *)0x0)) {
                    /* Unresolved local var: ulonglong timeDelta@[???] */
    pvVar5 = nla_data(nlattrs[4]);
    pvVar5 = nla_next(pvVar5,&rem);
    puVar6 = nla_data(pvVar5);
    ptVar9 = &stats;
    for (lVar7 = 0x36; lVar7 != 0; lVar7 = lVar7 + -1) {
      uVar1 = *puVar6;
      ptVar9->version = (short)uVar1;
      ptVar9->field_0x2 = (char)((ulong)uVar1 >> 0x10);
      ptVar9->field_0x3 = (char)((ulong)uVar1 >> 0x18);
      ptVar9->ac_exitcode = (int)((ulong)uVar1 >> 0x20);
      puVar6 = puVar6 + (ulong)bVar10 * -2 + 1;
      ptVar9 = (taskstats *)((long)ptVar9 + (ulong)bVar10 * -0x10 + 8);
    }
    uVar8 = stats.ac_etime * 1000 - *(long *)((long)linuxProcess + 0x2e8);
    if (uVar8 == 0) {
      fVar12 = NAN;
      *(undefined8 *)((long)linuxProcess + 0x308) = 0x7fc000007fc00000;
    }
    else {
      if ((long)uVar8 < 0) {
        fVar12 = (float)uVar8;
        uVar8 = stats.cpu_delay_total - *(long *)((long)linuxProcess + 0x2f0);
        if ((long)uVar8 < 0) goto LAB_0013a399;
LAB_0013a2e6:
        fVar11 = (float)(long)uVar8;
      }
      else {
        fVar12 = (float)(long)uVar8;
        uVar8 = stats.cpu_delay_total - *(long *)((long)linuxProcess + 0x2f0);
        if (-1 < (long)uVar8) goto LAB_0013a2e6;
LAB_0013a399:
        fVar11 = (float)uVar8;
      }
      fVar11 = (fVar11 / fVar12) * 100.0;
      if (100.0 <= fVar11) {
        fVar11 = 100.0;
      }
      *(float *)((long)linuxProcess + 0x308) = fVar11;
      fVar11 = ((float)(stats.blkio_delay_total - *(long *)((long)linuxProcess + 0x2f8)) / fVar12) *
               100.0;
      if (100.0 <= fVar11) {
        fVar11 = 100.0;
      }
      *(float *)((long)linuxProcess + 0x30c) = fVar11;
      fVar12 = ((float)(stats.swapin_delay_total - *(long *)((long)linuxProcess + 0x300)) / fVar12)
               * 100.0;
      if (100.0 <= fVar12) {
        fVar12 = 100.0;
      }
    }
    *(__u64 *)((long)linuxProcess + 0x300) = stats.swapin_delay_total;
    *(__u64 *)((long)linuxProcess + 0x2f8) = stats.blkio_delay_total;
    *(__u64 *)((long)linuxProcess + 0x2f0) = stats.cpu_delay_total;
    *(__u64 *)((long)linuxProcess + 0x2e8) = stats.ac_etime * 1000;
    *(float *)((long)linuxProcess + 0x310) = fVar12;
  }
  wVar4 = L'\0';
LAB_0013a28c:
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return wVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

