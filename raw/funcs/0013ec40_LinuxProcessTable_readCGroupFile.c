/* LinuxProcessTable_readCGroupFile @ 0013ec40 size 1499 */

void LinuxProcessTable_readCGroupFile(LinuxProcess *process,openat_arg_t procFd)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  FILE_2 *__stream;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  long in_FS_OFFSET;
  char output [4097];
  char buffer [4097];

                    /* Unresolved local var: FILE * file@[???]
                       Unresolved local var: char * at@[???]
                       Unresolved local var: wchar_t left@[???]
                       Unresolved local var: _Bool changed@[???]
                       Unresolved local var: char * cgroup_short@[???]
                       Unresolved local var: char * container_short@[???] */
                    /* Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * stream@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  iVar3 = openat(procFd,((char *)0x149bcc /* "cgroup" */),0);
  if (iVar3 < 0) {
LAB_0013f1ca:
    if (process->cgroup != (char *)0x0) {
      free(process->cgroup);
      process->cgroup = (char *)0x0;
    }
    if (process->cgroup_short != (char *)0x0) {
      free(process->cgroup_short);
      process->cgroup_short = (char *)0x0;
    }
    pcVar6 = process->container_short;
    if (pcVar6 == (char *)0x0) goto LAB_0013eedb;
  }
  else {
    __stream = fdopen(iVar3,((char *)0x147760 /* "r" */));
    if (__stream == (FILE_2 *)0x0) {
      close(iVar3);
      goto LAB_0013f1ca;
    }
    output[0] = '\0';
    iVar3 = 0x1000;
                    /* Unresolved local var: char * ok@[???]
                       Unresolved local var: char * group@[???]
                       Unresolved local var: char * eol@[???]
                       Unresolved local var: wchar_t wrote@[???]
                       Unresolved local var: size_t sz@[???] */
    while (((iVar4 = feof(__stream), 0 < iVar3 && (iVar4 == 0)) &&
           (pcVar6 = fgets(buffer,0x1000,__stream), pcVar6 != (char *)0x0))) {
                    /* Unresolved local var: size_t i@[???] */
      pcVar6 = strchrnul(buffer,0x3a);
      if (*pcVar6 != '\0') {
        pcVar6 = strchrnul(pcVar6 + 1,0x3a);
        pcVar6 = pcVar6 + (*pcVar6 != '\0');
      }
      pcVar7 = strchrnul(pcVar6,10);
      *pcVar7 = '\0';
      iVar4 = __snprintf_chk(output,(long)iVar3,2,0x1001,((char *)0x147626 /* "%s" */),pcVar6);
      iVar3 = iVar3 - iVar4;
    }
    fclose(__stream);
    pcVar6 = process->cgroup;
    if (pcVar6 == (char *)0x0) {
      sVar5 = strlen(output);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x71] < sVar5) {
          Row_fieldWidths[0x71] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x71] = 0xff;
      }
      goto LAB_0013efd7;
    }
    iVar3 = strcmp(pcVar6,output);
    sVar5 = strlen(output);
    if (iVar3 == 0) {
      bVar2 = false;
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x71] < sVar5) goto LAB_0013f0a7;
      }
      else {
        Row_fieldWidths[0x71] = 0xff;
        iVar3 = strcmp(pcVar6,output);
        if (iVar3 != 0) goto LAB_0013eff9;
      }
LAB_0013ef20:
      pcVar6 = process->cgroup_short;
      if (pcVar6 == (char *)0x0) {
        pcVar6 = process->cgroup;
      }
      sVar5 = strlen(pcVar6);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x81] < sVar5) {
          Row_fieldWidths[0x81] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x81] = 0xff;
      }
      if (process->container_short == (char *)0x0) {
        if (Row_fieldWidths[0x82] < 3) {
          Row_fieldWidths[0x82] = '\x03';
        }
      }
      else {
        sVar5 = strlen(process->container_short);
        if (sVar5 < 0x100) {
          if (Row_fieldWidths[0x82] < sVar5) {
            Row_fieldWidths[0x82] = (uint8_t)sVar5;
          }
        }
        else {
          Row_fieldWidths[0x82] = 0xff;
        }
      }
      goto LAB_0013eedb;
    }
    if (sVar5 < 0x100) {
      if (sVar5 <= Row_fieldWidths[0x71]) goto LAB_0013efd7;
      bVar2 = true;
LAB_0013f0a7:
      Row_fieldWidths[0x71] = (uint8_t)sVar5;
      iVar3 = strcmp(pcVar6,output);
      if (iVar3 != 0) goto LAB_0013eff9;
LAB_0013f020:
      if (!bVar2) goto LAB_0013ef20;
      pcVar6 = CGroup_filterName(process->cgroup);
      if (pcVar6 != (char *)0x0) goto LAB_0013ede0;
LAB_0013f04b:
      sVar5 = strlen(process->cgroup);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x81] < sVar5) {
          Row_fieldWidths[0x81] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x81] = 0xff;
      }
      free(process->cgroup_short);
      process->cgroup_short = (char *)0x0;
    }
    else {
      Row_fieldWidths[0x71] = 0xff;
      iVar3 = strcmp(pcVar6,output);
      if (iVar3 != 0) {
LAB_0013efd7:
        bVar2 = true;
LAB_0013eff9:
        free(pcVar6);
                    /* Unresolved local var: char * data@[???] */
        pcVar6 = strdup(output);
        if (pcVar6 == (char *)0x0) goto LAB_0013f1be;
        process->cgroup = pcVar6;
        goto LAB_0013f020;
      }
      pcVar6 = CGroup_filterName(pcVar6);
      if (pcVar6 == (char *)0x0) goto LAB_0013f04b;
LAB_0013ede0:
      sVar5 = strlen(pcVar6);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x81] < sVar5) {
          Row_fieldWidths[0x81] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x81] = 0xff;
      }
      pcVar7 = process->cgroup_short;
      if ((pcVar7 == (char *)0x0) || (iVar3 = strcmp(pcVar7,pcVar6), iVar3 != 0)) {
        free(pcVar7);
                    /* Unresolved local var: char * data@[???] */
        pcVar7 = strdup(pcVar6);
        if (pcVar7 == (char *)0x0) goto LAB_0013f1be;
        process->cgroup_short = pcVar7;
      }
      free(pcVar6);
    }
    pcVar6 = CGroup_filterContainer(process->cgroup);
    if (pcVar6 != (char *)0x0) {
      sVar5 = strlen(pcVar6);
      if (sVar5 < 0x100) {
        if (Row_fieldWidths[0x82] < sVar5) {
          Row_fieldWidths[0x82] = (uint8_t)sVar5;
        }
      }
      else {
        Row_fieldWidths[0x82] = 0xff;
      }
      pcVar7 = process->container_short;
      if ((pcVar7 == (char *)0x0) || (iVar3 = strcmp(pcVar7,pcVar6), iVar3 != 0)) {
        free(pcVar7);
                    /* Unresolved local var: char * data@[???] */
        pcVar7 = strdup(pcVar6);
        if (pcVar7 == (char *)0x0) {
LAB_0013f1be:
                    /* WARNING: Subroutine does not return */
          fail();
        }
        process->container_short = pcVar7;
      }
      free(pcVar6);
      goto LAB_0013eedb;
    }
    if (Row_fieldWidths[0x82] < 3) {
      Row_fieldWidths[0x82] = '\x03';
    }
    pcVar6 = process->container_short;
  }
  free(pcVar6);
  process->container_short = (char *)0x0;
LAB_0013eedb:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

