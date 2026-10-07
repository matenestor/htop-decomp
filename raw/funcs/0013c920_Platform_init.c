/* Platform_init @ 0013c920 size 368 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_Bool Platform_init(void)

{
  long lVar1;
  ssize_t sVar2;
  FILE_2 *__stream;
  char *pcVar3;
  long in_FS_OFFSET;
  char lineBuffer [256];
  char target [4096];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  LibSensors_init();
  sVar2 = readlink(((char *)0x149a40 /* "/proc/self/ns/pid" */),target,0xfff);
  if ((sVar2 < 1) ||
     ((target[sVar2] = '\0',
      target._0_8_ == 0x3230345b3a646970 && target._8_8_ == 0x5d36333831333536 &&
      (target[0x10] == '\0')))) {
    __stream = fopen(((char *)0x149a63 /* "/proc/1/mounts" */),((char *)0x147760 /* "r" */));
    if (__stream != (FILE_2 *)0x0) {
      do {
                    /* Unresolved local var: size_t sz@[???] */
        pcVar3 = fgets(lineBuffer,0x100,__stream);
        if (pcVar3 == (char *)0x0) goto LAB_0013ca70;
        if ((CONCAT17(lineBuffer[7],lineBuffer._0_7_) == 0x702f20736663786c) &&
           (lineBuffer._7_4_ == 0x636f7270)) {
          Running_containerized = true;
          goto LAB_0013ca70;
        }
      } while ((CONCAT17(lineBuffer[7],lineBuffer._0_7_) != 0x2079616c7265766f ||
                CONCAT53(lineBuffer._11_5_,lineBuffer._8_3_) != 0x616c7265766f202f) ||
              (lineBuffer[0x10] != 'y'));
      Running_containerized = true;
LAB_0013ca70:
      fclose(__stream);
    }
  }
  else {
    Running_containerized = true;
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return true;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

