/* LinuxProcessTable_initTtyDrivers @ 0013e910 size 798 */

/* DWARF original prototype: void LinuxProcessTable_initTtyDrivers(LinuxProcessTable * this) */

void LinuxProcessTable_initTtyDrivers(LinuxProcessTable *this)

{
  undefined8 *puVar1;
  char cVar2;
  long lVar3;
  undefined1 *puVar4;
  wchar_t fd;
  undefined4 uVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  long lVar9;
  TtyDriver *__base;
  void *pvVar10;
  int *piVar11;
  int iVar12;
  undefined1 *puVar13;
  size_t __size;
  char *pcVar14;
  long in_FS_OFFSET;
  void *local_4058;
  int local_4050;
  int local_404c;
  char buf [16384];

                    /* Unresolved local var: TtyDriver * ttyDrivers@[???]
                       Unresolved local var: ssize_t r@[???]
                       Unresolved local var: wchar_t numDrivers@[???]
                       Unresolved local var: wchar_t allocd@[???]
                       Unresolved local var: char * at@[???] */
  puVar4 = &stack0xffffffffffffffd0;
  do {
    puVar13 = puVar4;
    *(undefined8 *)(puVar13 + -0x1000) = *(undefined8 *)(puVar13 + -0x1000);
    puVar4 = puVar13 + -0x1000;
  } while (puVar13 + -0x1000 != buf + 0x18);
                    /* Unresolved local var: wchar_t fd@[???] */
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(puVar13 + -0x1040) = 0x13e95e;
  fd = open(((char *)0x149bba /* "/proc/tty/drivers" */),0);
  if (fd < L'\0') {
                    /* Unresolved local var: wchar_t fd@[???] */
    *(undefined8 *)(puVar13 + -0x1040) = 0x13ec17;
    piVar11 = __errno_location();
    lVar6 = (long)-*piVar11;
  }
  else {
    *(undefined8 *)(puVar13 + -0x1040) = 0x13e979;
    lVar6 = readfd_internal(fd,buf,0x4000);
  }
  if (lVar6 < 0) {
LAB_0013eba5:
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar13 + -0x1040) = &UNK_0013ec38;
    __stack_chk_fail();
  }
                    /* Unresolved local var: void * data@[???] */
  *(undefined8 *)(puVar13 + -0x1040) = 0x13e98c;
  local_4058 = malloc(0xf0);
  if (local_4058 != (void *)0x0) {
    iVar12 = 0;
    __size = 0x18;
    if (buf[0] != '\0') {
      local_4050 = 10;
      lVar6 = 0;
      pcVar7 = buf;
      local_404c = 0;
      iVar12 = local_404c;
      do {
                    /* Unresolved local var: char * token@[???] */
        local_404c = iVar12;
        *(undefined8 *)(puVar13 + -0x1040) = 0x13e9dd;
        pcVar7 = strchr(pcVar7,0x20);
        cVar2 = *pcVar7;
        while (cVar2 == ' ') {
          pcVar7 = pcVar7 + 1;
          cVar2 = *pcVar7;
        }
        *(undefined8 *)(puVar13 + -0x1040) = 0x13ea00;
        pcVar8 = strchr(pcVar7,0x20);
                    /* Unresolved local var: char * data@[???] */
        *pcVar8 = '\0';
        pcVar14 = pcVar8 + 1;
        puVar1 = (undefined8 *)((long)local_4058 + lVar6);
        *(undefined8 *)(puVar13 + -0x1040) = 0x13ea1d;
        pcVar7 = strdup(pcVar7);
        if (pcVar7 == (char *)0x0) goto LAB_0013ec2e;
        cVar2 = pcVar8[1];
        *puVar1 = pcVar7;
        while (cVar2 == ' ') {
          pcVar14 = pcVar14 + 1;
          cVar2 = *pcVar14;
        }
        *(undefined8 *)(puVar13 + -0x1040) = 0x13ea47;
        pcVar7 = strchr(pcVar14,0x20);
        *pcVar7 = '\0';
        *(undefined8 *)(puVar13 + -0x1040) = 0x13ea60;
        lVar9 = __isoc23_strtol(pcVar14,(char **)0x0,10);
        *(int *)(puVar1 + 1) = (int)lVar9;
        cVar2 = pcVar7[1];
        while (pcVar8 = pcVar7 + 1, pcVar14 = pcVar8, cVar2 == ' ') {
          cVar2 = pcVar7[2];
          pcVar7 = pcVar8;
        }
        while ((byte)(cVar2 - 0x30U) < 10) {
          cVar2 = pcVar14[1];
          pcVar14 = pcVar14 + 1;
        }
        *pcVar14 = '\0';
        pcVar14 = pcVar14 + 1;
        if (cVar2 == '-') {
          *(undefined8 *)(puVar13 + -0x1040) = 0x13eb15;
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          *(int *)((long)puVar1 + 0xc) = (int)lVar9;
          *(undefined8 *)(puVar13 + -0x1040) = 0x13eb25;
          pcVar7 = strchr(pcVar14,0x20);
          *pcVar7 = '\0';
          pcVar7 = pcVar7 + 1;
          *(undefined8 *)(puVar13 + -0x1040) = 0x13eb3e;
          lVar9 = __isoc23_strtol(pcVar14,(char **)0x0,10);
          uVar5 = (undefined4)lVar9;
        }
        else {
          *(undefined8 *)(puVar13 + -0x1040) = 0x13eabb;
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          *(int *)((long)puVar1 + 0xc) = (int)lVar9;
          *(undefined8 *)(puVar13 + -0x1040) = 0x13eacd;
          lVar9 = __isoc23_strtol(pcVar8,(char **)0x0,10);
          uVar5 = (undefined4)lVar9;
          pcVar7 = pcVar14;
        }
        *(undefined4 *)(puVar1 + 2) = uVar5;
        *(undefined8 *)(puVar13 + -0x1040) = 0x13eadd;
        pcVar14 = strchr(pcVar7,10);
        pcVar7 = pcVar14 + 1;
        iVar12 = local_404c + 1;
        pvVar10 = local_4058;
        if (iVar12 == local_4050) {
                    /* Unresolved local var: void * data@[???] */
          local_4050 = local_404c + 0xb;
          *(undefined8 *)(puVar13 + -0x1040) = 0x13ebfb;
          pvVar10 = realloc(local_4058,(long)local_4050 * 0x18);
          if (pvVar10 == (void *)0x0) goto LAB_0013ec22;
        }
        local_4058 = pvVar10;
        lVar6 = lVar6 + 0x18;
      } while (pcVar14[1] != '\0');
      __size = (long)(local_404c + 2) * 0x18;
    }
                    /* Unresolved local var: void * data@[???] */
    *(undefined8 *)(puVar13 + -0x1040) = 0x13eb68;
    __base = realloc(local_4058,__size);
    if (__base != (TtyDriver *)0x0) {
      *(undefined8 *)((long)&__base[-1].path + __size) = 0;
      *(undefined8 *)(puVar13 + -0x1040) = 0x13eb9a;
      qsort(__base,(long)iVar12,0x18,sortTtyDrivers);
      this->ttyDrivers = __base;
      goto LAB_0013eba5;
    }
LAB_0013ec22:
    *(undefined8 *)(puVar13 + -0x1040) = 0x13ec2e;
    free(local_4058);
  }
LAB_0013ec2e:
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar13 + -0x1040) = 0x13ec33;
  fail();
}

