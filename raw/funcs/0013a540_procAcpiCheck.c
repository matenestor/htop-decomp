/* procAcpiCheck @ 0013a540 size 155 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ACPresence procAcpiCheck(void)

{
  long lVar1;
  wchar_t fd;
  int iVar2;
  ACPresence AVar3;
  ssize_t sVar4;
  int *piVar5;
  long lVar6;
  char *pcVar7;
  long in_FS_OFFSET;
  char buffer [1024];

                    /* Unresolved local var: wchar_t fd@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar7 = buffer;
                    /* Unresolved local var: ssize_t r@[???] */
  for (lVar6 = 0x80; lVar6 != 0; lVar6 = lVar6 + -1) {
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7[2] = '\0';
    pcVar7[3] = '\0';
    pcVar7[4] = '\0';
    pcVar7[5] = '\0';
    pcVar7[6] = '\0';
    pcVar7[7] = '\0';
    pcVar7 = pcVar7 + 8;
  }
  fd = open(((char *)0x14ca30 /* "/proc/acpi/ac_adapter/AC/state" */),0);
  if (fd < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
    piVar5 = __errno_location();
    if (-*piVar5 < 1) goto LAB_0013a5d0;
  }
  else {
    sVar4 = readfd_internal(fd,buffer,0x400);
    if (sVar4 < 1) {
LAB_0013a5d0:
      AVar3 = AC_ERROR;
      goto LAB_0013a5aa;
    }
  }
  iVar2 = strcmp(buffer,((char *)0x149898 /* "on-line" */));
  AVar3 = (ACPresence)(iVar2 == 0);
LAB_0013a5aa:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return AVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

