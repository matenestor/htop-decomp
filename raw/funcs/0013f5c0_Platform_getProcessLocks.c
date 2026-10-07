/* Platform_getProcessLocks @ 0013f5c0 size 1230 */

FileLocks_ProcessData * Platform_getProcessLocks(pid_t pid)

{
  char *p0;
  long lVar1;
  undefined1 auVar2 [16];
  int __fd;
  int iVar3;
  FileLocks_ProcessData *pFVar4;
  size_t sVar5;
  DIR_2 *__dirp;
  dirent *pdVar6;
  int *piVar7;
  ulong uVar8;
  FILE_2 *__stream;
  char *pcVar9;
  ulong uVar10;
  FileLocks_LockData_ *pFVar11;
  long in_FS_OFFSET;
  FileLocks_LockData_ **local_2550;
  uint min;
  uint maj;
  wchar_t _;
  char *end;
  FileLocks_Data data;
  char lock_end [25];
  char readwrite [32];
  char exclusive [32];
  char locktype [32];
  char buffer [1024];
  char path [4096];
  char link [4096];

                    /* Unresolved local var: void * data@[???] */
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pFVar4 = calloc(1,0x10);
  if (pFVar4 == (FileLocks_ProcessData *)0x0) {
LAB_0013fa8d:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  xSnprintf(path,0x1000,((char *)0x149bf5 /* "/proc/%d/fdinfo/" */),pid);
  sVar5 = strlen(path);
  if ((sVar5 < 0xffe) && (__dirp = opendir(path), __dirp != (DIR_2 *)0x0)) {
    __fd = dirfd(__dirp);
    local_2550 = &pFVar4->locks;
                    /* Unresolved local var: dirent * de@[???]
                       Unresolved local var: wchar_t file@[???]
                       Unresolved local var: wchar_t fd@[???]
                       Unresolved local var: FILE * f@[???] */
    if (__fd != -1) {
      while (pdVar6 = readdir(__dirp), pdVar6 != (dirent *)0x0) {
        p0 = pdVar6->d_name;
        if (((pdVar6->d_name[0] != '.') || (pdVar6->d_name[1] != '\0')) &&
           ((pdVar6->d_name[0] != '.' || ((pdVar6->d_name[1] != '.' || (pdVar6->d_name[2] != '\0')))
            ))) {
          piVar7 = __errno_location();
          *piVar7 = 0;
          end = p0;
          uVar8 = __isoc23_strtoull(p0,&end,10);
          if ((*piVar7 == 0) && ((*end == '\0' && (iVar3 = openat(__fd,p0,0x80000), iVar3 != -1))))
          {
            __stream = fdopen(iVar3,((char *)0x147760 /* "r" */));
            if (__stream == (FILE_2 *)0x0) {
              close(iVar3);
            }
            else {
                    /* Unresolved local var: size_t sz@[???] */
              while (pcVar9 = fgets(buffer,0x400,__stream), pcVar9 != (char *)0x0) {
                    /* Unresolved local var: ssize_t link_len@[???] */
                pcVar9 = strchr(buffer,10);
                if (((pcVar9 != (char *)0x0) && (buffer._0_4_ == 0x6b636f6c)) &&
                   (buffer._4_2_ == 0x93a)) {
                  data._36_12_ = SUB1612((undefined1  [16])0x0,4);
                  data.fd = (wchar_t)uVar8;
                  data.end = 0;
                  data.locktype = (char *)0x0;
                  data.exclusive = (char *)0x0;
                  data.readwrite = (char *)0x0;
                  data.filename = (char *)0x0;
                  data.inode = 0;
                  data.start = 0;
                  iVar3 = __isoc23_sscanf(buffer + 6,((char *)0x14cb58 /* "%d: %31s %31s %31s %d %x:%x:%lu %lu %24s" */),&_,
                                          locktype,exclusive,readwrite,&_,&maj,&min,&data.inode,
                                          &data.start,lock_end);
                  if (iVar3 == 10) {
                    /* Unresolved local var: char * data@[???] */
                    pcVar9 = strdup(locktype);
                    if (pcVar9 == (char *)0x0) goto LAB_0013fa8d;
                    /* Unresolved local var: char * data@[???] */
                    data.locktype = pcVar9;
                    pcVar9 = strdup(exclusive);
                    if (pcVar9 == (char *)0x0) goto LAB_0013fa8d;
                    /* Unresolved local var: char * data@[???] */
                    data.exclusive = pcVar9;
                    pcVar9 = strdup(readwrite);
                    if (pcVar9 == (char *)0x0) goto LAB_0013fa8d;
                    /* Unresolved local var: __dev_t __dev@[???] */
                    data.readwrite = pcVar9;
                    data.dev = ((ulong)min & 0xffffff00) << 0xc |
                               ((ulong)maj & 0xfffff000) << 0x20 | (ulong)((maj & 0xfff) << 8) |
                               (ulong)(byte)min;
                    uVar10 = 0xffffffffffffffff;
                    if (lock_end._0_4_ != 0x464f45) {
                      uVar10 = __isoc23_strtoull(lock_end,(char **)0x0,10);
                    }
                    data.end = uVar10;
                    xSnprintf(path,0x1000,((char *)0x149c11 /* "/proc/%d/fd/%s" */),pid,p0);
                    sVar5 = strlen(path);
                    if (sVar5 < 0xffe) {
                      sVar5 = readlink(path,link,0x1000);
                      if (sVar5 != 0xffffffffffffffff) {
                    /* Unresolved local var: char * data@[???] */
                        pcVar9 = strndup(link,sVar5);
                        if (pcVar9 == (char *)0x0) goto LAB_0013fa8d;
                        data.filename = pcVar9;
                      }
                    }
                    /* Unresolved local var: void * data@[???] */
                    pFVar11 = calloc(1,0x50);
                    auVar2 = (undefined1  [16])data._32_16_;
                    if (pFVar11 == (FileLocks_LockData_ *)0x0) goto LAB_0013fa8d;
                    *local_2550 = pFVar11;
                    local_2550 = &pFVar11->next;
                    (pFVar11->data).locktype = data.locktype;
                    (pFVar11->data).exclusive = data.exclusive;
                    (pFVar11->data).readwrite = data.readwrite;
                    (pFVar11->data).filename = data.filename;
                    (pFVar11->data).fd = data.fd;
                    (pFVar11->data).field_0x24 = data.field_0x24;
                    (pFVar11->data).field_0x25 = data.field_0x25;
                    (pFVar11->data).field_0x26 = data.field_0x26;
                    (pFVar11->data).field_0x27 = data.field_0x27;
                    (pFVar11->data).dev = data.dev;
                    (pFVar11->data).inode = data.inode;
                    (pFVar11->data).start = data.start;
                    (pFVar11->data).end = data.end;
                    data._32_16_ = auVar2;
                  }
                }
              }
              fclose(__stream);
            }
          }
        }
      }
      closedir(__dirp);
      goto LAB_0013f656;
    }
    closedir(__dirp);
  }
  pFVar4->error = true;
LAB_0013f656:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pFVar4;
}

