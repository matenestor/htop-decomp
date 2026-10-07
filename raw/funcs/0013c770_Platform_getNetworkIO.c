/* Platform_getNetworkIO @ 0013c770 size 318 */

_Bool Platform_getNetworkIO(NetworkIOData *data)

{
  long lVar1;
  _Bool _Var2;
  int iVar3;
  FILE_2 *__stream;
  char *pcVar4;
  long in_FS_OFFSET;
  ulonglong packetsTransmitted;
  ulonglong bytesTransmitted;
  ulonglong packetsReceived;
  ulonglong bytesReceived;
  char interfaceName [32];
  char lineBuffer [512];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)0x149a2e /* "/proc/net/dev" */),((char *)0x147760 /* "r" */));
  if (__stream == (FILE_2 *)0x0) {
    _Var2 = false;
  }
  else {
    data->bytesReceived = 0;
    data->packetsReceived = 0;
    data->bytesTransmitted = 0;
    data->packetsTransmitted = 0;
    while( true ) {
                    /* Unresolved local var: size_t sz@[???] */
      pcVar4 = fgets(lineBuffer,0x200,__stream);
      if (pcVar4 == (char *)0x0) break;
      iVar3 = __isoc23_sscanf(lineBuffer,((char *)0x14ca88 /* "%31s %llu %llu %*u %*u %*u %*u %*u %*u %llu %llu" */),
                              interfaceName,&bytesReceived,&packetsReceived,&bytesTransmitted,
                              &packetsTransmitted);
      if ((iVar3 == 5) && (interfaceName._0_4_ != 0x3a6f6c)) {
        data->bytesTransmitted = bytesTransmitted + data->bytesTransmitted;
        data->packetsTransmitted = packetsTransmitted + data->packetsTransmitted;
        data->bytesReceived = bytesReceived + data->bytesReceived;
        data->packetsReceived = packetsReceived + data->packetsReceived;
      }
    }
    fclose(__stream);
    _Var2 = true;
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return _Var2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

