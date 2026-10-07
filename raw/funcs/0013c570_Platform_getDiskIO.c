/* Platform_getDiskIO @ 0013c570 size 493 */

_Bool Platform_getDiskIO(DiskIOData *data)

{
  char cVar1;
  long lVar2;
  _Bool _Var3;
  int iVar4;
  FILE_2 *__stream;
  char *pcVar5;
  size_t __n;
  long lVar6;
  uint64_t uVar7;
  long in_FS_OFFSET;
  long local_1b8;
  long local_1b0;
  ulonglong timeSpend_tmp;
  ulonglong write_tmp;
  ulonglong read_tmp;
  char lastTopDisk [32];
  char diskname [32];
  char lineBuffer [256];

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)0x149a15 /* "/proc/diskstats" */),((char *)0x147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
    _Var3 = false;
  }
  else {
    uVar7 = 0;
    lastTopDisk[0] = '\0';
    lastTopDisk[1] = '\0';
    lastTopDisk[2] = '\0';
    lastTopDisk[3] = '\0';
    lastTopDisk[4] = '\0';
    lastTopDisk[5] = '\0';
    lastTopDisk[6] = '\0';
    lastTopDisk[7] = '\0';
    lastTopDisk[8] = '\0';
    lastTopDisk[9] = '\0';
    lastTopDisk[10] = '\0';
    lastTopDisk[0xb] = '\0';
    lastTopDisk[0xc] = '\0';
    lastTopDisk[0xd] = '\0';
    lastTopDisk[0xe] = '\0';
    lastTopDisk[0xf] = '\0';
    local_1b8 = 0;
    local_1b0 = 0;
    lastTopDisk[0x10] = '\0';
    lastTopDisk[0x11] = '\0';
    lastTopDisk[0x12] = '\0';
    lastTopDisk[0x13] = '\0';
    lastTopDisk[0x14] = '\0';
    lastTopDisk[0x15] = '\0';
    lastTopDisk[0x16] = '\0';
    lastTopDisk[0x17] = '\0';
    lastTopDisk[0x18] = '\0';
    lastTopDisk[0x19] = '\0';
    lastTopDisk[0x1a] = '\0';
    lastTopDisk[0x1b] = '\0';
    lastTopDisk[0x1c] = '\0';
    lastTopDisk[0x1d] = '\0';
    lastTopDisk[0x1e] = '\0';
    lastTopDisk[0x1f] = '\0';
LAB_0013c600:
                    /* Unresolved local var: size_t sz@[???] */
    pcVar5 = fgets(lineBuffer,0x100,__stream);
    if (pcVar5 != (char *)0x0) {
      iVar4 = __isoc23_sscanf(lineBuffer,((char *)0x14ca50 /* "%*d %*d %31s %*u %*u %llu %*u %*u %*u %llu %*u %*u %llu" */),
                              diskname,&read_tmp,&write_tmp,&timeSpend_tmp);
      if ((iVar4 == 4) &&
         (((diskname._0_2_ != 0x6d64 || (diskname[2] != '-')) && (diskname._0_4_ != 0x6d61727a)))) {
        if (lastTopDisk[0] != '\0') {
          __n = strlen(lastTopDisk);
          iVar4 = strncmp(diskname,lastTopDisk,__n);
          if (iVar4 == 0) goto LAB_0013c600;
        }
        lVar6 = 0;
        do {
          cVar1 = diskname[lVar6];
          if (cVar1 == '\0') break;
                    /* Unresolved local var: size_t i@[???] */
          lastTopDisk[lVar6] = cVar1;
          lVar6 = lVar6 + 1;
        } while (lVar6 != 0x1f);
        lastTopDisk[lVar6] = '\0';
        local_1b0 = local_1b0 + read_tmp;
        uVar7 = uVar7 + timeSpend_tmp;
        local_1b8 = local_1b8 + write_tmp;
      }
      goto LAB_0013c600;
    }
    fclose(__stream);
    data->totalMsTimeSpend = uVar7;
    data->totalBytesRead = local_1b0 << 9;
    data->totalBytesWritten = local_1b8 << 9;
    _Var3 = true;
  }
  if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return _Var3;
}

