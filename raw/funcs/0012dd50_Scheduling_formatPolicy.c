/* Scheduling_formatPolicy @ 0012dd50 size 88 */

char * Scheduling_formatPolicy(wchar_t policy)

{
  switch(policy & 0xbfffffff) {
  case L'\0':
    return ((char *)0x14895d /* "OTHER" */);
  case L'\x01':
    return ((char *)0x148958 /* "FIFO" */);
  case L'\x02':
    return ((char *)0x148976 /* "RR" */);
  case L'\x03':
    return ((char *)0x148970 /* "BATCH" */);
  default:
    return ((char *)0x148963 /* "???" */);
  case L'\x05':
    return ((char *)0x14896b /* "IDLE" */);
  case L'\x06':
    return ((char *)0x148967 /* "EDF" */);
  }
}

