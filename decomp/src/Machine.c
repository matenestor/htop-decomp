#include "htop.h"

/* Machine_done @ 0x121030 */

void Machine_done(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  (**(code **)(**(long **)(param_1 + 0xb0) + 0x10))
            ((long)*(long **)(param_1 + 0xb0),param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  free(*(void **)(param_1 + 0xa0));
  return;
}


/* Machine_setTablesPanel @ 0x121060 */

void Machine_setTablesPanel(long param_1,undefined8 param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;

  if (*(long *)(param_1 + 0x98) != 0) {
    plVar3 = *(long **)(param_1 + 0xa0);
    plVar1 = plVar3 + *(long *)(param_1 + 0x98);
    do {
      lVar2 = *plVar3;
      plVar3 = plVar3 + 1;
      *(undefined8 *)(lVar2 + 0x38) = param_2;
    } while (plVar3 != plVar1);
  }
  return;
}


/* Machine_scanTables @ 0x1210a0 */

void Machine_scanTables(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                       long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long *plVar1;
  byte bVar2;
  long *a0;
  long lVar3;
  uint uVar4;
  size_t sVar5;
  long lVar6;
  ulong extraout_RDX;
  long *extraout_RDX_00;
  long a2;
  ulong extraout_RDX_01;
  long *a2_00;
  ulong extraout_RDX_02;
  undefined **ppuVar7;
  undefined1 *puVar8;
  ulong uVar9;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar10;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  if (CHAR____0015d660 == '\0') {
    CHAR____0015d660 = '\x01';
  }
  else {
    param_rsi = (long)&(*(timespec *)(__fp - 0x48));
    uVar4 = clock_gettime(1,(timespec *)param_rsi);
    param_rdx = (long)uVar4;
    lVar6 = 0;
    if (uVar4 == 0) {
      param_rdx = (ulong)(*(timespec *)(__fp - 0x48)).tv_nsec / 1000000;
      lVar6 = (*(timespec *)(__fp - 0x48)).tv_sec * 1000 + param_rdx;
    }
    *(long *)(param_1 + 0x20) = lVar6;
  }
  puVar8 = &Row_fieldWidths;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  ppuVar7 = (undefined **)(Process_fields + 8);
  do {
    if (*(char *)((long)ppuVar7 + 0x16) != '\0') {
      sVar5 = strlen(*ppuVar7);
      *puVar8 = (char)sVar5;
      param_rdx = extraout_RDX;
    }
    ppuVar7 = ppuVar7 + 4;
    puVar8 = puVar8 + 1;
  } while (ppuVar7 != &PTR_s_Enter_00157668);
  uVar9 = 0;
  if (*(long *)(param_1 + 0x98) != 0) {
    do {
      while( true ) {
        a0 = *(long **)(*(long *)(param_1 + 0xa0) + uVar9 * 8);
        lVar6 = *a0;
        if (*(code **)(lVar6 + 0x20) == (code *)0x0) {
          a2_00 = (long *)a0[1];
          plVar1 = a2_00 + 3;
          if (0 < (int)*plVar1) {
            a2_00 = (long *)*a2_00;
            plVar1 = a2_00 + (int)*plVar1;
            do {
              lVar3 = *a2_00;
              a2_00 = a2_00 + 1;
              bVar2 = *(byte *)(lVar3 + 0x1e);
              param_rsi = (long)bVar2;
              *(undefined1 *)(lVar3 + 0x21) = 0;
              *(undefined1 *)(lVar3 + 0x1e) = 1;
              *(byte *)(lVar3 + 0x1f) = bVar2;
            } while (plVar1 != a2_00);
          }
        }
        else {
          (**(code **)(lVar6 + 0x20))((long)a0,param_rsi,param_rdx,lVar6,param_r8,param_r9);
          lVar6 = *a0;
          a2_00 = extraout_RDX_00;
        }
        (**(code **)(lVar6 + 0x28))((long)a0,param_rsi,(long)a2_00,lVar6,param_r8,param_r9);
        if (*(code **)(*a0 + 0x30) == (code *)0x0) break;
        (**(code **)(*a0 + 0x30))((long)a0,param_rsi,a2,lVar6,param_r8,param_r9);
        uVar9 = uVar9 + 1;
        param_rdx = extraout_RDX_01;
        if (*(ulong *)(param_1 + 0x98) <= uVar9) goto LAB_001211c2;
      }
      Table_cleanupEntries((long)a0,param_rsi,a2,lVar6,param_r8,param_r9);
      uVar9 = uVar9 + 1;
      param_rdx = extraout_RDX_02;
    } while (uVar9 < *(ulong *)(param_1 + 0x98));
LAB_001211c2:
    if (99999 < *(uint *)(param_1 + 0x8c)) {
      dVar10 = log10((double)*(uint *)(param_1 + 0x8c));
      Row_uidDigits = (int)dVar10 + 1;
      goto LAB_001211ec;
    }
  }
  Row_uidDigits = 5;
LAB_001211ec:
  if ((*(long *)(__fp - 0x30)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* Machine_populateTablesFromSettings @ 0x1233f0 */

void Machine_populateTablesFromSettings(long *param_1,long param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  void *__ptr;
  long lVar4;
  void *pvVar5;
  size_t __size;
  ulong uVar6;
  long lVar7;

  iVar1 = *(int *)(param_2 + 0x38);
  *param_1 = param_2;
  param_1[0x16] = param_3;
  if (iVar1 == 0) {
    return;
  }
  uVar6 = 0;
LAB_00123428:
  lVar3 = *(long *)(*(long *)(param_2 + 0x30) + uVar6 * 8);
  lVar7 = *(long *)(lVar3 + 0x10);
  if (lVar7 == 0) {
    *(long *)(lVar3 + 0x10) = param_3;
    lVar7 = param_3;
  }
  if (uVar6 == 0) {
    param_1[0x15] = lVar7;
  }
  __ptr = (void *)param_1[0x14];
  if (param_1[0x13] != 0) goto code_r0x00123460;
  __size = 8;
  goto LAB_001234b3;
code_r0x00123460:
  lVar3 = 0;
  do {
    lVar4 = lVar3;
    if (lVar7 == *(long *)((long)__ptr + lVar4 * 8)) {
      uVar6 = uVar6 + 1;
      if (*(uint *)(param_2 + 0x38) <= uVar6) {
        return;
      }
      goto LAB_00123428;
    }
    lVar3 = lVar4 + 1;
  } while (lVar4 + 1 != param_1[0x13]);
  if (lVar4 + 2 != 0x2000000000000000) {
    __size = (lVar4 + 2) * 8;
LAB_001234b3:
    pvVar5 = realloc(__ptr,__size);
    if (pvVar5 != (void *)0x0) {
      *(long *)((long)pvVar5 + (__size - 8)) = lVar7;
      uVar6 = uVar6 + 1;
      param_1[0x14] = (long)pvVar5;
      uVar2 = *(uint *)(param_2 + 0x38);
      param_1[0x13] = param_1[0x13] + 1;
      if (uVar2 <= uVar6) {
        return;
      }
      goto LAB_00123428;
    }
    free(__ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Machine_init @ 0x129090 */

void Machine_init(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  __uid_t _Var1;
  int iVar2;
  FILE *__stream;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar3;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(param_1 + 0x80) = param_2;
  *(undefined4 *)(param_1 + 0x90) = param_3;
  _Var1 = getuid();
  (*(int *)(__fp - 0x24)) = 0x3fffff;
  *(__uid_t *)(param_1 + 0x88) = _Var1;
  __stream = fopen(((char *)(long)&s__proc_sys_kernel_pid_max_00148869 /* "/proc/sys/kernel/pid_max" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE *)0x0) {
    __isoc23_fscanf(__stream,((char *)(long)&DAT_0014978b /* "%32d" */),&(*(int *)(__fp - 0x24)));
    fclose(__stream);
  }
  iVar2 = 5;
  if (99999 < (*(int *)(__fp - 0x24))) {
    dVar3 = log10((double)(*(int *)(__fp - 0x24)));
    iVar2 = (int)dVar3 + 1;
  }
  Row_pidDigits = iVar2;
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    Generic_gettime_realtime((undefined1 (*) [16])(param_1 + 8),(long *)(param_1 + 0x18));
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Machine_delete @ 0x13b1c0 */

void Machine_delete(void *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                   long param_r9)

{
  (**(code **)(**(long **)((long)param_1 + 0xb0) + 0x10))
            ((long)*(long **)((long)param_1 + 0xb0),param_rsi,param_rdx,param_rcx,param_r8,param_r9)
  ;
  free(*(void **)((long)param_1 + 0xa0));
  free(*(void **)((long)param_1 + 0xe0));
  free(param_1);
  return;
}


/* Machine_isCPUonline @ 0x13b210 */

undefined1 Machine_isCPUonline(long param_1,int param_2)

{
  return *(undefined1 *)(*(long *)(param_1 + 0xe0) + (ulong)(param_2 + 1) * 0xd8 + 0xd0);
}


/* Machine_scan @ 0x141bc0 */

void Machine_scan(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x218] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1d8;
  int iVar1;
  uint uVar2;
  int iVar3;
  FILE *pFVar4;
  char *pcVar5;
  DIR *__dirp;
  dirent *pdVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  char *pcVar11;
  FILE *__stream;
  timespec *ptVar12;
  int *piVar13;
  timespec *ptVar14;
  timespec *ptVar15;
  long extraout_RDX;
  long extraout_RDX_00;
  long lVar16;
  long extraout_RDX_01;
  uint uVar17;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  pFVar4 = fopen(((char *)(long)(__sec_rodata + 0x2e96) /* "/proc/meminfo" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (pFVar4 == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_open__proc_meminfo_00149e8a /* "Cannot open /proc/meminfo" */));
  }
  (*(char * *)(__fp - 0x168)) = (char *)0x0;
  (*(char * *)(__fp - 0x158)) = (char *)0x0;
  (*(char * *)(__fp - 0x190)) = (char *)0x0;
  (*(char * *)(__fp - 0x170)) = (char *)0x0;
  (*(char * *)(__fp - 0x188)) = (char *)0x0;
  (*(char * *)(__fp - 0x180)) = (char *)0x0;
  (*(char * *)(__fp - 0x178)) = (char *)0x0;
  (*(char * *)(__fp - 0x150)) = (char *)0x0;
  (*(char * *)(__fp - 0x148)) = (char *)0x0;
  (*(char * *)(__fp - 0x160)) = (char *)0x0;
  (*(char * *)(__fp - 0x140)) = (char *)0x0;
  pcVar11 = (char *)0x0;
  while (pcVar5 = fgets(&(*(char *)(__fp - 0xc8)),0x80,pFVar4), pcVar5 != (char *)0x0) {
    switch((*(char *)(__fp - 0xc8))) {
    case 'B':
      if ((CONCAT17((*(char *)(__fp - 0xc1)),
                    CONCAT16((*(char *)(__fp - 0xc2)),
                             CONCAT15((*(char *)(__fp - 0xc3)),
                                      CONCAT14((*(char *)(__fp - 0xc4)),
                                               CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                        CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                 CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8)))))))))
           == 0x3a73726566667542) &&
         (iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xc0)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118))), iVar1 == 1)) {
        (*(char * *)(__fp - 0x148)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
      }
      break;
    case 'C':
      if (((CONCAT13((*(undefined1 *)(__fp - 0xc5)),CONCAT12((*(undefined1 *)(__fp - 0xc6)),CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))) == 0x68636143) &&
          (CONCAT13((*(char *)(__fp - 0xc2)),CONCAT12((*(char *)(__fp - 0xc3)),CONCAT11((*(char *)(__fp - 0xc4)),(*(undefined1 *)(__fp - 0xc5))))) == 0x3a646568)) &&
         (iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xc1)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118))), iVar1 == 1)) {
        (*(char * *)(__fp - 0x150)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
      }
      break;
    case 'M':
      if ((CONCAT17((*(char *)(__fp - 0xc1)),
                    CONCAT16((*(char *)(__fp - 0xc2)),
                             CONCAT15((*(char *)(__fp - 0xc3)),
                                      CONCAT14((*(char *)(__fp - 0xc4)),
                                               CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                        CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                 CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8)))))))))
           == 0x6c696176416d654d) &&
         (CONCAT26((*(undefined2 *)(__fp - 0xbd)),
                   CONCAT15((*(char *)(__fp - 0xbe)),
                            CONCAT14((*(char *)(__fp - 0xbf)),
                                     CONCAT13((*(char *)(__fp - 0xc0)),
                                              CONCAT12((*(char *)(__fp - 0xc1)),CONCAT11((*(char *)(__fp - 0xc2)),(*(char *)(__fp - 0xc3))))))))
          == 0x3a656c62616c6961)) {
        iVar1 = __isoc23_sscanf((char *)&(*(undefined2 *)(__fp - 0xbb)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118)));
        if (iVar1 == 1) {
          (*(char * *)(__fp - 0x140)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
        }
      }
      else if (CONCAT17((*(char *)(__fp - 0xc1)),
                        CONCAT16((*(char *)(__fp - 0xc2)),
                                 CONCAT15((*(char *)(__fp - 0xc3)),
                                          CONCAT14((*(char *)(__fp - 0xc4)),
                                                   CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                            CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                     CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))))
                                         ))) == 0x3a656572466d654d) {
        iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xc0)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118)));
        if (iVar1 == 1) {
          (*(char * *)(__fp - 0x160)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
        }
      }
      else if (((CONCAT17((*(char *)(__fp - 0xc1)),
                          CONCAT16((*(char *)(__fp - 0xc2)),
                                   CONCAT15((*(char *)(__fp - 0xc3)),
                                            CONCAT14((*(char *)(__fp - 0xc4)),
                                                     CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                              CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                       CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))
                                                             ))))) == 0x6c61746f546d654d) &&
               ((*(char *)(__fp - 0xc0)) == ':')) &&
              (iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xbf)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118))), iVar1 == 1)) {
        pcVar11 = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
      }
      break;
    case 'S':
      if ((*(char *)(__fp - 0xc7)) == 'h') {
        if (((CONCAT13((*(undefined1 *)(__fp - 0xc5)),CONCAT12((*(undefined1 *)(__fp - 0xc6)),CONCAT11(0x68,(*(char *)(__fp - 0xc8))))) == 0x656d6853) &&
            (CONCAT11((*(char *)(__fp - 0xc3)),(*(char *)(__fp - 0xc4))) == 0x3a6d)) &&
           (iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xc2)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118))), iVar1 == 1)) {
          (*(char * *)(__fp - 0x178)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
        }
      }
      else if ((*(char *)(__fp - 0xc7)) == 'w') {
        if ((CONCAT17((*(char *)(__fp - 0xc1)),
                      CONCAT16((*(char *)(__fp - 0xc2)),
                               CONCAT15((*(char *)(__fp - 0xc3)),
                                        CONCAT14((*(char *)(__fp - 0xc4)),
                                                 CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                          CONCAT12((*(undefined1 *)(__fp - 0xc6)),CONCAT11(0x77,(*(char *)(__fp - 0xc8)))
                                                                  )))))) == 0x61746f5470617753) &&
           (CONCAT11((*(char *)(__fp - 0xbf)),(*(char *)(__fp - 0xc0))) == 0x3a6c)) {
          iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xbe)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118)));
          if (iVar1 == 1) {
            (*(char * *)(__fp - 0x180)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
          }
        }
        else if ((CONCAT17((*(char *)(__fp - 0xc1)),
                           CONCAT16((*(char *)(__fp - 0xc2)),
                                    CONCAT15((*(char *)(__fp - 0xc3)),
                                             CONCAT14((*(char *)(__fp - 0xc4)),
                                                      CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                               CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                        CONCAT11(0x77,(*(char *)(__fp - 0xc8))))))))
                          ) == 0x6863614370617753) &&
                (CONCAT13((*(char *)(__fp - 0xbe)),CONCAT12((*(char *)(__fp - 0xbf)),CONCAT11((*(char *)(__fp - 0xc0)),(*(char *)(__fp - 0xc1))))) == 0x3a646568
                )) {
          iVar1 = __isoc23_sscanf((char *)&(*(undefined2 *)(__fp - 0xbd)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118)));
          if (iVar1 == 1) {
            (*(char * *)(__fp - 0x188)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
          }
        }
        else if (((CONCAT17((*(char *)(__fp - 0xc1)),
                            CONCAT16((*(char *)(__fp - 0xc2)),
                                     CONCAT15((*(char *)(__fp - 0xc3)),
                                              CONCAT14((*(char *)(__fp - 0xc4)),
                                                       CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                                CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                         CONCAT11(0x77,(*(char *)(__fp - 0xc8)))))))
                                    )) == 0x6565724670617753) && ((*(char *)(__fp - 0xc0)) == ':')) &&
                (iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xbf)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118))), iVar1 == 1)) {
          (*(char * *)(__fp - 0x170)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
        }
      }
      else if (((((*(char *)(__fp - 0xc7)) == 'R') &&
                (CONCAT17((*(char *)(__fp - 0xc1)),
                          CONCAT16((*(char *)(__fp - 0xc2)),
                                   CONCAT15((*(char *)(__fp - 0xc3)),
                                            CONCAT14((*(char *)(__fp - 0xc4)),
                                                     CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                              CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                       CONCAT11(0x52,(*(char *)(__fp - 0xc8)))))))))
                 == 0x6d69616c63655253)) &&
               (CONCAT26((*(undefined2 *)(__fp - 0xbd)),
                         CONCAT15((*(char *)(__fp - 0xbe)),
                                  CONCAT14((*(char *)(__fp - 0xbf)),
                                           CONCAT13((*(char *)(__fp - 0xc0)),
                                                    CONCAT12((*(char *)(__fp - 0xc1)),CONCAT11((*(char *)(__fp - 0xc2)),(*(char *)(__fp - 0xc3)))
                                                            ))))) == 0x3a656c62616d6961)) &&
              (iVar1 = __isoc23_sscanf((char *)&(*(undefined2 *)(__fp - 0xbb)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118))), iVar1 == 1)) {
        (*(char * *)(__fp - 0x190)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
      }
      break;
    case 'Z':
      if ((CONCAT13((*(undefined1 *)(__fp - 0xc5)),CONCAT12((*(undefined1 *)(__fp - 0xc6)),CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))) == 0x6177735a) &&
         (CONCAT11((*(char *)(__fp - 0xc3)),(*(char *)(__fp - 0xc4))) == 0x3a70)) {
        iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xc2)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118)));
        if (iVar1 == 1) {
          (*(char * *)(__fp - 0x158)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
        }
      }
      else if ((CONCAT17((*(char *)(__fp - 0xc1)),
                         CONCAT16((*(char *)(__fp - 0xc2)),
                                  CONCAT15((*(char *)(__fp - 0xc3)),
                                           CONCAT14((*(char *)(__fp - 0xc4)),
                                                    CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                             CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                      CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8)))))
                                                   )))) == 0x646570706177735a) &&
              (((*(char *)(__fp - 0xc0)) == ':' &&
               (iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xbf)),((char *)(long)&s__llu_kB_00149eb2 /* "%llu kB" */),&(*(timespec *)(__fp - 0x118))), iVar1 == 1)))) {
        (*(char * *)(__fp - 0x168)) = (char *)(*(timespec *)(__fp - 0x118)).tv_sec;
      }
    }
  }
  fclose(pFVar4);
  param_1[6] = (long)pcVar11;
  *(undefined4 *)(param_1 + 0x1e) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0xf4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1f) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0xfc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x104) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x21) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x10c) = 0xffffffff;
  param_1[10] = (long)(*(char * *)(__fp - 0x178));
  param_1[8] = (long)(*(char * *)(__fp - 0x148));
  param_1[9] = (long)((*(char * *)(__fp - 0x150)) + (long)(*(char * *)(__fp - 0x190))) - (long)(*(char * *)(__fp - 0x178));
  *(undefined4 *)(param_1 + 0x22) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x114) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x23) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x11c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x124) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x25) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 300) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x26) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x134) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x27) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x13c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x144) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x29) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x14c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2a) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x154) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2b) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x15c) = 0xffffffff;
  pcVar5 = (*(char * *)(__fp - 0x160)) + (long)(*(char * *)(__fp - 0x148)) + (long)(*(char * *)(__fp - 0x150)) + (long)(*(char * *)(__fp - 0x190));
  if (pcVar11 < (*(char * *)(__fp - 0x160)) + (long)(*(char * *)(__fp - 0x148)) + (long)(*(char * *)(__fp - 0x150)) + (long)(*(char * *)(__fp - 0x190))) {
    pcVar5 = (*(char * *)(__fp - 0x160));
  }
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x164) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2d) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x16c) = 0xffffffff;
  param_1[0xe] = (long)(*(char * *)(__fp - 0x188));
  param_1[7] = (long)pcVar11 - (long)pcVar5;
  *(undefined4 *)(param_1 + 0x2e) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x174) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2f) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x17c) = 0xffffffff;
  param_1[0x1d] = 0;
  if ((*(char * *)(__fp - 0x140)) <= pcVar11) {
    pcVar11 = (*(char * *)(__fp - 0x140));
  }
  if ((*(char * *)(__fp - 0x140)) == (char *)0x0) {
    pcVar11 = (*(char * *)(__fp - 0x160));
  }
  param_1[0xc] = (long)(*(char * *)(__fp - 0x180));
  param_1[0xd] = (long)(*(char * *)(__fp - 0x180)) - (long)((*(char * *)(__fp - 0x170)) + (long)(*(char * *)(__fp - 0x188)));
  param_1[0xb] = (long)pcVar11;
  param_1[0x45] = (long)(*(char * *)(__fp - 0x158));
  param_1[0x46] = (long)(*(char * *)(__fp - 0x168));
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x184) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x31) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x18c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x32) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x194) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x33) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x19c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x1a4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x35) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x1ac) = 0xffffffff;
  __dirp = opendir(((char *)(long)&s__sys_kernel_mm_hugepages_00149f1d /* "/sys/kernel/mm/hugepages" */));
  if (__dirp != (DIR *)0x0) {
LAB_00142030:
    pdVar6 = readdir(__dirp);
    if (pdVar6 != (dirent *)0x0) {
      while ((pdVar6->d_type & 0xfb) == 0) {
        pcVar11 = pdVar6->d_name;
        iVar1 = strncmp(pcVar11,((char *)(long)&s_hugepages__00149f36 /* "hugepages-" */),10);
        if (((iVar1 != 0) ||
            (uVar7 = __isoc23_strtoul(pdVar6->d_name + 10,(char **)&(*(timespec *)(__fp - 0x118)),10),
            (char *)(*(timespec *)(__fp - 0x118)).tv_sec == (char *)0x0)) || (*(char *)(*(timespec *)(__fp - 0x118)).tv_sec != 'k')) break;
        xSnprintf(&(*(char *)(__fp - 0xc8)),0x80,((char *)(long)&s__sys_kernel_mm_hugepages__s_nr_h_0014cc50 /* "/sys/kernel/mm/hugepages/%s/nr_hugepages" */),pcVar11);
        iVar1 = open(&(*(char *)(__fp - 0xc8)),0);
        if (iVar1 < 0) {
          piVar13 = __errno_location();
          lVar8 = (long)-*piVar13;
        }
        else {
          lVar8 = FUN_0013a450(iVar1,(*(char (*)[64])(__fp - 0x108)),0x40);
        }
        if ((lVar8 < 1) || (uVar9 = __isoc23_strtoull((*(char (*)[64])(__fp - 0x108)),(char **)0x0,10), uVar9 == 0))
        break;
        xSnprintf(&(*(char *)(__fp - 0xc8)),0x80,((char *)(long)&s__sys_kernel_mm_hugepages__s_free_0014cc80 /* "/sys/kernel/mm/hugepages/%s/free_hugepages" */),pcVar11);
        iVar1 = open(&(*(char *)(__fp - 0xc8)),0);
        if (iVar1 < 0) {
          piVar13 = __errno_location();
          lVar8 = (long)-*piVar13;
        }
        else {
          lVar8 = FUN_0013a450(iVar1,(*(char (*)[64])(__fp - 0x108)),0x40);
        }
        param_r8 = uVar9;
        if (lVar8 < 1) break;
        uVar10 = __isoc23_strtoull((*(char (*)[64])(__fp - 0x108)),(char **)0x0,10);
        iVar1 = ffsl(uVar7);
        param_1[0x1d] = param_1[0x1d] + uVar7 * uVar9;
        param_r8 = (uVar9 - uVar10) * uVar7;
        param_1[(long)(iVar1 + -7) + 0x1e] = param_r8;
        pdVar6 = readdir(__dirp);
        if (pdVar6 == (dirent *)0x0) goto LAB_001421c0;
      }
      goto LAB_00142030;
    }
LAB_001421c0:
    closedir(__dirp);
  }
  (*(ulong *)(__fp - 0x130)) = 0;
  (*(timespec *)(__fp - 0x128)).tv_sec = 0;
  (*(timespec *)(__fp - 0x118)).tv_sec = 0;
  pFVar4 = fopen(((char *)(long)&s__proc_spl_kstat_zfs_arcstats_00149f41 /* "/proc/spl/kstat/zfs/arcstats" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (pFVar4 == (FILE *)0x0) {
    *(undefined4 *)(param_1 + 0x37) = 0;
  }
  else {
    while (pcVar11 = fgets(&(*(char *)(__fp - 0xc8)),0x80,pFVar4), pcVar11 != (char *)0x0) {
      switch((*(char *)(__fp - 0xc8))) {
      case 'a':
        if ((CONCAT17((*(char *)(__fp - 0xc1)),
                      CONCAT16((*(char *)(__fp - 0xc2)),
                               CONCAT15((*(char *)(__fp - 0xc3)),
                                        CONCAT14((*(char *)(__fp - 0xc4)),
                                                 CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                          CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                   CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))))))
                     ) == 0x7a69735f6e6f6e61) && ((*(char *)(__fp - 0xc0)) == 'e')) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xbf)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x3d);
        }
        break;
      case 'b':
        if ((CONCAT17((*(char *)(__fp - 0xc1)),
                      CONCAT16((*(char *)(__fp - 0xc2)),
                               CONCAT15((*(char *)(__fp - 0xc3)),
                                        CONCAT14((*(char *)(__fp - 0xc4)),
                                                 CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                          CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                   CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))))))
                     ) == 0x69735f73756e6f62) && (CONCAT11((*(char *)(__fp - 0xbf)),(*(char *)(__fp - 0xc0))) == 0x657a)) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xbe)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(*(timespec *)(__fp - 0x118)));
        }
        break;
      case 'c':
        if ((CONCAT13((*(undefined1 *)(__fp - 0xc5)),CONCAT12((*(undefined1 *)(__fp - 0xc6)),CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))) == 0x696d5f63) &&
           ((*(char *)(__fp - 0xc4)) == 'n')) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xc3)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x38);
        }
        else if ((CONCAT13((*(undefined1 *)(__fp - 0xc5)),CONCAT12((*(undefined1 *)(__fp - 0xc6)),CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))) == 0x616d5f63
                 ) && ((*(char *)(__fp - 0xc4)) == 'x')) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xc3)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x39);
        }
        else if ((CONCAT17((*(char *)(__fp - 0xc1)),
                           CONCAT16((*(char *)(__fp - 0xc2)),
                                    CONCAT15((*(char *)(__fp - 0xc3)),
                                             CONCAT14((*(char *)(__fp - 0xc4)),
                                                      CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                               CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                        CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8)))
                                                                       )))))) == 0x73736572706d6f63)
                && (CONCAT26((*(undefined2 *)(__fp - 0xbb)),
                             CONCAT24((*(undefined2 *)(__fp - 0xbd)),
                                      CONCAT13((*(char *)(__fp - 0xbe)),
                                               CONCAT12((*(char *)(__fp - 0xbf)),CONCAT11((*(char *)(__fp - 0xc0)),(*(char *)(__fp - 0xc1)))))))
                    == 0x657a69735f646573)) {
          iVar1 = __isoc23_sscanf(&(*(char *)(__fp - 0xb9)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x40);
          *(int *)((long)param_1 + 0x1bc) = iVar1;
        }
        break;
      case 'd':
        if ((CONCAT17((*(char *)(__fp - 0xc1)),
                      CONCAT16((*(char *)(__fp - 0xc2)),
                               CONCAT15((*(char *)(__fp - 0xc3)),
                                        CONCAT14((*(char *)(__fp - 0xc4)),
                                                 CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                          CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                   CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))))))
                     ) == 0x7a69735f66756264) && ((*(char *)(__fp - 0xc0)) == 'e')) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xbf)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(*(ulong *)(__fp - 0x130)));
        }
        else if ((CONCAT17((*(char *)(__fp - 0xc1)),
                           CONCAT16((*(char *)(__fp - 0xc2)),
                                    CONCAT15((*(char *)(__fp - 0xc3)),
                                             CONCAT14((*(char *)(__fp - 0xc4)),
                                                      CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                               CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                        CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8)))
                                                                       )))))) == 0x69735f65646f6e64)
                && (CONCAT11((*(char *)(__fp - 0xbf)),(*(char *)(__fp - 0xc0))) == 0x657a)) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xbe)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),&(*(timespec *)(__fp - 0x128)));
        }
        break;
      case 'h':
        if (CONCAT17((*(char *)(__fp - 0xc1)),
                     CONCAT16((*(char *)(__fp - 0xc2)),
                              CONCAT15((*(char *)(__fp - 0xc3)),
                                       CONCAT14((*(char *)(__fp - 0xc4)),
                                                CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                         CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                  CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8)))))))))
            == 0x657a69735f726468) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xc0)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x3e);
        }
        break;
      case 'm':
        if (CONCAT17((*(char *)(__fp - 0xc1)),
                     CONCAT16((*(char *)(__fp - 0xc2)),
                              CONCAT15((*(char *)(__fp - 0xc3)),
                                       CONCAT14((*(char *)(__fp - 0xc4)),
                                                CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                         CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                  CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8)))))))))
            == 0x657a69735f75666d) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xc0)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x3b);
        }
        else if (CONCAT17((*(char *)(__fp - 0xc1)),
                          CONCAT16((*(char *)(__fp - 0xc2)),
                                   CONCAT15((*(char *)(__fp - 0xc3)),
                                            CONCAT14((*(char *)(__fp - 0xc4)),
                                                     CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                              CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                       CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))
                                                             ))))) == 0x657a69735f75726d) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xc0)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x3c);
        }
        break;
      case 's':
        if (CONCAT13((*(undefined1 *)(__fp - 0xc5)),CONCAT12((*(undefined1 *)(__fp - 0xc6)),CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))) == 0x657a6973) {
          __isoc23_sscanf(&(*(char *)(__fp - 0xc4)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x3a);
        }
        break;
      case 'u':
        if ((CONCAT17((*(char *)(__fp - 0xc1)),
                      CONCAT16((*(char *)(__fp - 0xc2)),
                               CONCAT15((*(char *)(__fp - 0xc3)),
                                        CONCAT14((*(char *)(__fp - 0xc4)),
                                                 CONCAT13((*(undefined1 *)(__fp - 0xc5)),
                                                          CONCAT12((*(undefined1 *)(__fp - 0xc6)),
                                                                   CONCAT11((*(char *)(__fp - 0xc7)),(*(char *)(__fp - 0xc8))))))))
                     ) == 0x6572706d6f636e75 &&
             CONCAT17((*(char *)(__fp - 0xb9)),
                      CONCAT25((*(undefined2 *)(__fp - 0xbb)),
                               CONCAT23((*(undefined2 *)(__fp - 0xbd)),CONCAT12((*(char *)(__fp - 0xbe)),CONCAT11((*(char *)(__fp - 0xbf)),(*(char *)(__fp - 0xc0)))))
                              )) == 0x7a69735f64657373) && ((*(char *)(__fp - 0xb8)) == 'e')) {
          __isoc23_sscanf((*(char (*)[119])(__fp - 0xb7)),((char *)(long)&s___2u__32llu_00149f64 /* " %*2u %32llu" */),param_1 + 0x41);
        }
      }
    }
    fclose(pFVar4);
    param_1[0x3e] = (ulong)param_1[0x3e] >> 10;
    *(uint *)(param_1 + 0x37) = (uint)(param_1[0x3a] != 0);
    param_1[0x38] = (ulong)param_1[0x38] >> 10;
    param_1[0x39] = (ulong)param_1[0x39] >> 10;
    param_1[0x3a] = (ulong)param_1[0x3a] >> 10;
    param_1[0x3b] = (ulong)param_1[0x3b] >> 10;
    param_1[0x3c] = (ulong)param_1[0x3c] >> 10;
    param_1[0x3d] = (ulong)param_1[0x3d] >> 10;
    param_1[0x3f] = (*(timespec *)(__fp - 0x118)).tv_sec + (*(timespec *)(__fp - 0x128)).tv_sec + (*(ulong *)(__fp - 0x130)) >> 10;
    if (*(int *)((long)param_1 + 0x1bc) != 0) {
      param_1[0x40] = (ulong)param_1[0x40] >> 10;
      param_1[0x41] = (ulong)param_1[0x41] >> 10;
    }
  }
  uVar7 = 0;
  uVar9 = 0;
  (*(char * *)(__fp - 0x150)) = (char *)0x0;
  uVar17 = 0;
  while( true ) {
    xSnprintf((*(char (*)[64])(__fp - 0x108)),0x22,((char *)(long)&s__sys_block_zram_u_mm_stat_00149fce /* "/sys/block/zram%u/mm_stat" */),uVar17);
    ptVar15 = (timespec *)(ulong)uVar17;
    xSnprintf(&(*(char *)(__fp - 0xc8)),0x22,((char *)(long)&s__sys_block_zram_u_disksize_00149fe8 /* "/sys/block/zram%u/disksize" */),uVar17);
    pFVar4 = fopen(&(*(char *)(__fp - 0xc8)),((char *)(long)&DAT_00147760 /* "r" */));
    pcVar11 = ((char *)(long)&DAT_00147760 /* "r" */);
    __stream = fopen((*(char (*)[64])(__fp - 0x108)),((char *)(long)&DAT_00147760 /* "r" */));
    lVar8 = extraout_RDX;
    if (pFVar4 == (FILE *)0x0) break;
    if (__stream == (FILE *)0x0) {
      if (pFVar4 != (FILE *)0x0) {
        fclose(pFVar4);
        lVar8 = extraout_RDX_01;
      }
      break;
    }
    pcVar11 = ((char *)(long)&s__llu_0014a003 /* "%llu\n" */);
    (*(ulong *)(__fp - 0x130)) = 0;
    (*(timespec *)(__fp - 0x128)).tv_sec = 0;
    (*(timespec *)(__fp - 0x118)).tv_sec = 0;
    iVar1 = __isoc23_fscanf(pFVar4,((char *)(long)&s__llu_0014a003 /* "%llu\n" */),&(*(ulong *)(__fp - 0x130)));
    if (iVar1 == 0) {
LAB_0014268f:
      fclose(pFVar4);
      goto LAB_001426af;
    }
    pcVar11 = ((char *)(long)&s__llu__llu_0014a009 /* "    %llu       %llu" */);
    ptVar15 = &(*(timespec *)(__fp - 0x118));
    iVar1 = __isoc23_fscanf(__stream,((char *)(long)&s__llu__llu_0014a009 /* "    %llu       %llu" */),&(*(timespec *)(__fp - 0x128)),&(*(timespec *)(__fp - 0x118)));
    if (iVar1 == 0) goto LAB_0014268f;
    uVar9 = uVar9 + (*(ulong *)(__fp - 0x130));
    (*(char * *)(__fp - 0x150)) = (char *)((long)(*(char * *)(__fp - 0x150)) + (*(timespec *)(__fp - 0x118)).tv_sec);
    uVar7 = uVar7 + (*(timespec *)(__fp - 0x128)).tv_sec;
    fclose(pFVar4);
    fclose(__stream);
    uVar17 = uVar17 + 1;
  }
  if (__stream != (FILE *)0x0) {
LAB_001426af:
    fclose(__stream);
    lVar8 = extraout_RDX_00;
  }
  param_1[0x42] = uVar9 >> 10;
  uVar7 = uVar7 >> 10;
  param_1[0x44] = uVar7;
  uVar9 = (ulong)(*(char * *)(__fp - 0x150)) >> 10;
  if (uVar7 < (ulong)(*(char * *)(__fp - 0x150)) >> 10) {
    uVar9 = uVar7;
  }
  param_1[0x43] = uVar9;
  FUN_001415f0((long)param_1,(long)pcVar11,lVar8,(long)ptVar15,param_r8,param_r9);
  lVar8 = *param_1;
  if (*(char *)(lVar8 + 0x53) != '\0') {
    uVar17 = *(uint *)((long)param_1 + 0x7c);
    lVar16 = param_1[0x1c];
    uVar2 = 0;
    do {
      uVar7 = (ulong)uVar2;
      uVar2 = uVar2 + 1;
      ptVar15 = (timespec *)(uVar7 * 0x1b);
      *(undefined8 *)(lVar16 + 0xc0 + uVar7 * 0xd8) = 0x7ff8000000000000;
    } while (uVar2 <= uVar17);
    if (INT_0015d898 < 1) {
      param_r8 = 0;
      param_r9 = 0;
      if (uVar17 != 0) {
        (*(char * *)(__fp - 0x150)) = (char *)0x0;
        uVar17 = 0;
        ptVar14 = (timespec *)0x0;
        while( true ) {
          iVar1 = (int)ptVar14;
          ptVar12 = (timespec *)(ulong)(iVar1 + 1U);
          if (*(char *)(lVar16 + 0xd0 + (long)ptVar12 * 0xd8) != '\0') {
            xSnprintf(&(*(char *)(__fp - 0xc8)),0x40,((char *)(long)&s__sys_devices_system_cpu_cpu_u_cp_0014ccb0 /* "/sys/devices/system/cpu/cpu%u/cpufreq/scaling_cur_freq" */),iVar1)
            ;
            ptVar15 = ptVar14;
            if (iVar1 == 0) {
              clock_gettime(1,&(*(timespec *)(__fp - 0x128)));
              ptVar15 = ptVar14;
            }
            pFVar4 = fopen(&(*(char *)(__fp - 0xc8)),((char *)(long)&DAT_00147760 /* "r" */));
            if (pFVar4 == (FILE *)0x0) {
              piVar13 = __errno_location();
              if (*piVar13 == 0) goto LAB_00142705;
              goto LAB_00142b15;
            }
            iVar3 = __isoc23_fscanf(pFVar4,((char *)(long)(__sec_rodata + 0x275f) /* "%lu" */),&(*(ulong *)(__fp - 0x130)));
            if (iVar3 == 1) {
              uVar17 = uVar17 + 1;
              (*(ulong *)(__fp - 0x130)) = (*(ulong *)(__fp - 0x130)) / 1000;
              (*(char * *)(__fp - 0x150)) = (char *)((long)(*(char * *)(__fp - 0x150)) + (*(ulong *)(__fp - 0x130)));
              *(double *)(param_1[0x1c] + 0xc0 + (long)ptVar12 * 0xd8) = (double)(*(ulong *)(__fp - 0x130));
            }
            fclose(pFVar4);
            if (iVar1 == 0) {
              clock_gettime(1,&(*(timespec *)(__fp - 0x118)));
              ptVar15 = (timespec *)
                        (((*(timespec *)(__fp - 0x118)).tv_sec - (*(timespec *)(__fp - 0x128)).tv_sec) * 1000000 +
                        ((*(timespec *)(__fp - 0x118)).tv_nsec - (*(timespec *)(__fp - 0x128)).tv_nsec) / 1000);
              if (500 < (long)ptVar15) {
                INT_0015d898 = 0x1e;
                goto LAB_00142b15;
              }
            }
          }
          if (*(uint *)((long)param_1 + 0x7c) <= iVar1 + 1U) break;
          lVar16 = param_1[0x1c];
          ptVar14 = ptVar12;
        }
        param_r9 = (long)uVar17;
        param_r8 = (long)(*(char * *)(__fp - 0x150));
        if (0 < (int)uVar17) {
          if ((long)(*(char * *)(__fp - 0x150)) < 0) {
            param_r8 = (ulong)((uint)(*(char * *)(__fp - 0x150)) & 1);
          }
          *(double *)(param_1[0x1c] + 0xc0) = (double)(long)(*(char * *)(__fp - 0x150)) / (double)(int)uVar17;
        }
      }
    }
    else {
      INT_0015d898 = INT_0015d898 + -1;
LAB_00142b15:
      FUN_00138a90((long)param_1);
    }
  }
LAB_00142705:
  if (*(char *)(lVar8 + 0x54) == '\0') {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    LibSensors_getCPUTemperatures
              (param_1[0x1c],*(uint *)((long)param_1 + 0x7c),*(uint *)(param_1 + 0xf),(long)ptVar15,
               param_r8,param_r9);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Machine_new @ 0x142dd0 */

void * Machine_new(undefined8 param_1,undefined4 param_2,long param_rdx,long param_rcx,long param_r8
                  ,long param_r9)

{
  undefined1 __frame[0x10c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1088;
  int iVar1;
  void *pvVar2;
  long lVar3;
  FILE *__stream;
  char *pcVar4;
  long extraout_RDX;
  char *pcVar5;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  pvVar2 = calloc(1,0x238);
  if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  Machine_init((long)pvVar2,param_1,param_2);
  lVar3 = sysconf(0x1e);
  iVar1 = (int)lVar3;
  *(int *)((long)pvVar2 + 0xc0) = iVar1;
  if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_get_pagesize_by_sysconf___0014cce8 /* "Cannot get pagesize by sysconf(_SC_PAGESIZE)" */));
  }
  *(int *)((long)pvVar2 + 0xc4) = (int)((ulong)(long)iVar1 >> 10);
  lVar3 = sysconf(2);
  *(long *)((long)pvVar2 + 0xb8) = lVar3;
  if (lVar3 == -1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_get_clock_ticks_by_syscon_0014cd18 /* "Cannot get clock ticks by sysconf(_SC_CLK_TCK)" */));
  }
  __stream = fopen(((char *)(long)(__sec_rodata + 0x2e71) /* "/proc/stat" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Cannot_open__proc_stat_00149e65 /* "Cannot open /proc/stat" */));
  }
  *(undefined8 *)((long)pvVar2 + 0xd0) = 0xffffffffffffffff;
  do {
    pcVar5 = (char *)0x1001;
    pcVar4 = fgets((char *)&(*(int *)(__fp - 0x1038)),0x1001,__stream);
    if (pcVar4 == (char *)0x0) goto LAB_00142ee1;
  } while (((*(int *)(__fp - 0x1038)) != 0x6d697462) || ((*(short *)(__fp - 0x1034)) != 0x2065));
  pcVar5 = ((char *)(long)&s_btime__lld_0014a024 /* "btime %lld\n" */);
  iVar1 = __isoc23_sscanf((char *)&(*(int *)(__fp - 0x1038)),((char *)(long)&s_btime__lld_0014a024 /* "btime %lld\n" */),(void *)((long)pvVar2 + 0xd0));
  if (iVar1 != 1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_Failed_to_parse_btime_from__proc_0014cd48 /* "Failed to parse btime from /proc/stat" */));
  }
LAB_00142ee1:
  fclose(__stream);
  if (*(long *)((long)pvVar2 + 0xd0) == -1) {
                    /* WARNING: Subroutine does not return */
    CRT_fatalError(((char *)(long)&s_No_btime_in__proc_stat_0014a030 /* "No btime in /proc/stat" */));
  }
  FUN_00141370((long)pvVar2,(long)pcVar5,extraout_RDX,param_rcx,param_r8,param_r9);
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return pvVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_00142f70 @ 0x142f70 */

void FUN_00142f70(long param_1,int *param_2,undefined4 param_3)

{
  undefined1 __frame[0x1c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x188;
  double dVar1;
  char cVar2;
  long *plVar3;
  int iVar4;
  double dVar5;
  uint uVar6;
  char *pcVar7;
  undefined *puVar8;
  long in_FS_OFFSET = (long)__fake_fs;
  float fVar9;

  plVar3 = *(long **)(param_1 + 8);
  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  cVar2 = *(char *)(*plVar3 + 0x5f);
  (*(undefined1 *)(__fp - 0x39)) = 0;
  (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 4);
  switch(param_3) {
  case 0xb:
    Row_printCount(param_2,*(ulong *)(param_1 + 0x1f0),cVar2);
    break;
  default:
    Process_writeField(param_1,param_2,param_3);
    break;
  case 0xd:
    Row_printCount(param_2,*(ulong *)(param_1 + 0x1f8),cVar2);
    break;
  case 0xe:
    Row_printTime(param_2,*(ulong *)(param_1 + 0x200),cVar2);
    break;
  case 0xf:
    Row_printTime(param_2,*(ulong *)(param_1 + 0x208),cVar2);
    break;
  case 0x10:
    Row_printTime(param_2,*(ulong *)(param_1 + 0x210),cVar2);
    break;
  case 0x11:
    Row_printTime(param_2,*(ulong *)(param_1 + 0x218),cVar2);
    break;
  case 0x29:
    Row_printBytes(param_2,(long)(int)plVar3[0x18] * *(long *)(param_1 + 0x220),cVar2);
    break;
  case 0x2a:
    Row_printBytes(param_2,(long)(int)plVar3[0x18] * *(long *)(param_1 + 0x248),cVar2);
    break;
  case 0x2b:
    Row_printBytes(param_2,(long)(int)plVar3[0x18] * *(long *)(param_1 + 0x250),cVar2);
    break;
  case 0x2c:
    if (*(long *)(param_1 + 600) != 0) {
      Row_printBytes(param_2,(long)(int)plVar3[0x18] * *(long *)(param_1 + 600),cVar2);
      break;
    }
    (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 0x78);
    pcVar7 = ((char *)(long)&DAT_00149092 /* "  N/A " */);
    goto LAB_001432b8;
  case 100:
    puVar8 = *(undefined **)(param_1 + 0x2b8);
    pcVar7 = ((char *)(long)&s___8s_001489c7 /* "%-8s " */);
    if (puVar8 == (undefined *)0x0) {
      puVar8 = &DAT_00149c0c;
    }
    goto LAB_00143171;
  case 0x65:
    xSnprintf((*(char (*)[255])(__fp - 0x138)),0xff,((char *)(long)&DAT_001489a2 /* "%*d " */),Row_pidDigits,*(int *)(param_1 + 0x2c0));
    goto LAB_00143070;
  case 0x66:
    uVar6 = *(uint *)(param_1 + 0x2c4);
    pcVar7 = ((char *)(long)&DAT_00149063 /* "%5u " */);
    goto LAB_001432e6;
  case 0x67:
    Row_printBytes(param_2,*(ulong *)(param_1 + 0x268),cVar2);
    break;
  case 0x68:
    Row_printBytes(param_2,*(ulong *)(param_1 + 0x270),cVar2);
    break;
  case 0x69:
    Row_printCount(param_2,*(ulong *)(param_1 + 0x278),cVar2);
    break;
  case 0x6a:
    Row_printCount(param_2,*(ulong *)(param_1 + 0x280),cVar2);
    break;
  case 0x6b:
    Row_printBytes(param_2,*(ulong *)(param_1 + 0x288),cVar2);
    break;
  case 0x6c:
    Row_printBytes(param_2,*(ulong *)(param_1 + 0x290),cVar2);
    break;
  case 0x6d:
    Row_printBytes(param_2,*(ulong *)(param_1 + 0x298),cVar2);
    break;
  case 0x6e:
    Row_printRate(*(double *)(param_1 + 0x2a8),param_2,cVar2);
    break;
  case 0x6f:
    Row_printRate(*(double *)(param_1 + 0x2b0),param_2,cVar2);
    break;
  case 0x70:
    dVar5 = *(double *)(param_1 + 0x2a8);
    dVar1 = *(double *)(param_1 + 0x2b0);
    if (dVar5 < 0.0) {
      dVar5 = dVar1;
      if (dVar1 < 0.0) {
        dVar5 = NAN;
      }
    }
    else if (0.0 <= dVar1) {
      dVar5 = dVar5 + dVar1;
    }
    Row_printRate(dVar5,param_2,cVar2);
    break;
  case 0x71:
    puVar8 = *(undefined **)(param_1 + 0x2c8);
    if (puVar8 == (undefined *)0x0) {
      puVar8 = &DAT_001474de;
    }
    uVar6 = (uint)BYTE_0015d4d1;
    goto LAB_00143048;
  case 0x72:
    uVar6 = *(uint *)(param_1 + 0x2e0);
    pcVar7 = ((char *)(long)&DAT_0014a047 /* "%4u " */);
    goto LAB_001432e6;
  case 0x73:
    uVar6 = *(uint *)(param_1 + 0x1e8);
    iVar4 = (int)uVar6 >> 0xd;
    if (iVar4 == 0) {
      pcVar7 = ((char *)(long)&s_B_1d_0014a04c /* "B%1d " */);
      uVar6 = ((int)*(undefined8 *)(param_1 + 200) + 0x14) / 5;
    }
    else if (iVar4 == 2) {
      uVar6 = uVar6 & 0x1fff;
      pcVar7 = ((char *)(long)&s_B_1d_0014a04c /* "B%1d " */);
    }
    else {
      if (iVar4 != 1) {
        pcVar7 = ((char *)(long)&DAT_0014a05c /* "?? " */);
        if (iVar4 == 3) {
          (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 0x9c);
          pcVar7 = ((char *)(long)&DAT_0014a058 /* "id " */);
        }
        goto LAB_001432b8;
      }
      (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 0x98);
      uVar6 = uVar6 & 0x1fff;
      pcVar7 = ((char *)(long)&s_R_1d_0014a052 /* "R%1d " */);
    }
LAB_001432e6:
    xSnprintf((*(char (*)[255])(__fp - 0x138)),0xff,pcVar7,uVar6);
    goto LAB_00143070;
  case 0x74:
    fVar9 = *(float *)(param_1 + 0x308);
    goto LAB_00143217;
  case 0x75:
    fVar9 = *(float *)(param_1 + 0x30c);
    goto LAB_00143217;
  case 0x76:
    fVar9 = *(float *)(param_1 + 0x310);
LAB_00143217:
    Row_printPercentage(fVar9,(*(char (*)[255])(__fp - 0x138)),0xff,5,&(*(uint *)(__fp - 0x13c)));
    goto LAB_00143070;
  case 0x77:
    Row_printKBytes(param_2,*(ulong *)(param_1 + 0x230),cVar2);
    break;
  case 0x78:
    Row_printKBytes(param_2,*(ulong *)(param_1 + 0x238),cVar2);
    break;
  case 0x79:
    Row_printKBytes(param_2,*(ulong *)(param_1 + 0x240),cVar2);
    break;
  case 0x7a:
    puVar8 = *(undefined **)(param_1 + 800);
    if ((undefined *)0x3e8 < puVar8) {
      (*(uint *)(__fp - 0x13c)) = (*(uint *)(__fp - 0x13c)) | 0x200000;
    }
    pcVar7 = ((char *)(long)&s__5lu_0014a060 /* "%5lu " */);
LAB_00143171:
    xSnprintf((*(char (*)[255])(__fp - 0x138)),0xff,pcVar7,(long)puVar8);
    goto LAB_00143070;
  case 0x7b:
    puVar8 = *(undefined **)(param_1 + 0x328);
    if (puVar8 == (undefined *)0x0) {
      puVar8 = &DAT_001474de;
    }
    __snprintf_chk((*(char (*)[255])(__fp - 0x138)),0xff,2,0x100,((char *)(long)&s______s_0014884c /* "%-*.*s " */),(uint)BYTE_0015d4db,(uint)BYTE_0015d4db,puVar8);
    goto LAB_00143070;
  case 0x7f:
    puVar8 = *(undefined **)(param_1 + 0x338);
    if (puVar8 != (undefined *)0xffffffffffffffff) {
      pcVar7 = ((char *)(long)&s__4ld_0014899c /* "%4ld " */);
      goto LAB_00143171;
    }
    (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 0x78);
    pcVar7 = ((char *)(long)&DAT_00149093 /* " N/A " */);
LAB_001432b8:
    xSnprintf((*(char (*)[255])(__fp - 0x138)),0xff,pcVar7);
    goto LAB_00143070;
  case 0x80:
    if (*(long *)(param_1 + 0x338) == -1) {
      (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 0x78);
      pcVar7 = ((char *)(long)&DAT_00149094 /* "N/A " */);
      goto LAB_001432b8;
    }
    xSnprintf((*(char (*)[255])(__fp - 0x138)),0xff,((char *)(long)&DAT_001489ac /* "%3d " */),*(int *)(param_1 + 0x340));
    if (*(int *)(param_1 + 0x340) < 0) {
      (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 0x98);
    }
    else if (*(int *)(param_1 + 0x340) == 0) {
      (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 0x78);
    }
    else {
      (*(uint *)(__fp - 0x13c)) = *(uint *)(CRT_colors + 0x9c);
    }
    goto LAB_00143070;
  case 0x81:
    puVar8 = *(undefined **)(param_1 + 0x2d0);
    if ((puVar8 == (undefined *)0x0) &&
       (puVar8 = *(undefined **)(param_1 + 0x2c8), puVar8 == (undefined *)0x0)) {
      puVar8 = &DAT_001474de;
    }
    uVar6 = (uint)BYTE_0015d4e1;
    goto LAB_00143048;
  case 0x82:
    puVar8 = *(undefined **)(param_1 + 0x2d8);
    if (puVar8 == (undefined *)0x0) {
      puVar8 = &DAT_001474de;
    }
    uVar6 = (uint)BYTE_0015d4e2;
LAB_00143048:
    xSnprintf((*(char (*)[255])(__fp - 0x138)),0xff,((char *)(long)&s______s_0014884c /* "%-*.*s " */),uVar6,uVar6,puVar8);
LAB_00143070:
    RichString_appendAscii(param_2,(*(uint *)(__fp - 0x13c)),(*(char (*)[255])(__fp - 0x138)));
    break;
  case 0x83:
    Row_printKBytes(param_2,*(ulong *)(param_1 + 0x228),cVar2);
  }
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001436e0 @ 0x1436e0 */

int FUN_001436e0(long param_1,long param_2,undefined4 param_3)

{
  double dVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  double dVar15;
  double dVar16;

  switch(param_3) {
  case 0xe:
    uVar8 = *(ulong *)(param_1 + 0x200);
    uVar9 = *(ulong *)(param_2 + 0x200);
    break;
  case 0xf:
    uVar8 = *(ulong *)(param_1 + 0x208);
    uVar9 = *(ulong *)(param_2 + 0x208);
    break;
  case 0x10:
    uVar8 = *(ulong *)(param_1 + 0x210);
    uVar9 = *(ulong *)(param_2 + 0x210);
    break;
  case 0x11:
    uVar8 = *(ulong *)(param_1 + 0x218);
    uVar9 = *(ulong *)(param_2 + 0x218);
    break;
  default:
    iVar5 = Process_compareByKey_Base(param_1,param_2,param_3);
    return iVar5;
  case 0x29:
    lVar3 = *(long *)(param_2 + 0x220);
    lVar4 = *(long *)(param_1 + 0x220);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
    goto LAB_00143713;
  case 0x2a:
    lVar3 = *(long *)(param_2 + 0x248);
    lVar4 = *(long *)(param_1 + 0x248);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
    goto LAB_00143713;
  case 0x2b:
    lVar3 = *(long *)(param_2 + 0x250);
    lVar4 = *(long *)(param_1 + 0x250);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
    goto LAB_00143713;
  case 0x2c:
    lVar3 = *(long *)(param_2 + 600);
    lVar4 = *(long *)(param_1 + 600);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
    goto LAB_00143713;
  case 100:
    pcVar10 = *(char **)(param_2 + 0x2b8);
    pcVar11 = *(char **)(param_1 + 0x2b8);
    if (pcVar10 == (char *)0x0) {
      pcVar10 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    iVar5 = strcmp(pcVar11,pcVar10);
    return iVar5;
  case 0x65:
    iVar5 = *(int *)(param_2 + 0x2c0);
    iVar2 = *(int *)(param_1 + 0x2c0);
    bVar14 = SBORROW4(iVar2,iVar5);
    bVar13 = iVar2 - iVar5 < 0;
    bVar12 = iVar2 == iVar5;
    goto LAB_00143713;
  case 0x66:
    uVar7 = *(uint *)(param_1 + 0x2c4);
    uVar6 = *(uint *)(param_2 + 0x2c4);
    goto LAB_00143910;
  case 0x67:
    uVar8 = *(ulong *)(param_1 + 0x268);
    uVar9 = *(ulong *)(param_2 + 0x268);
    break;
  case 0x68:
    uVar8 = *(ulong *)(param_1 + 0x270);
    uVar9 = *(ulong *)(param_2 + 0x270);
    break;
  case 0x69:
    uVar8 = *(ulong *)(param_1 + 0x278);
    uVar9 = *(ulong *)(param_2 + 0x278);
    break;
  case 0x6a:
    uVar8 = *(ulong *)(param_1 + 0x280);
    uVar9 = *(ulong *)(param_2 + 0x280);
    break;
  case 0x6b:
    uVar8 = *(ulong *)(param_1 + 0x288);
    uVar9 = *(ulong *)(param_2 + 0x288);
    break;
  case 0x6c:
    uVar8 = *(ulong *)(param_1 + 0x290);
    uVar9 = *(ulong *)(param_2 + 0x290);
    break;
  case 0x6d:
    uVar8 = *(ulong *)(param_1 + 0x298);
    uVar9 = *(ulong *)(param_2 + 0x298);
    break;
  case 0x6e:
    dVar15 = *(double *)(param_2 + 0x2a8);
    dVar16 = *(double *)(param_1 + 0x2a8);
    goto LAB_00143826;
  case 0x6f:
    dVar15 = *(double *)(param_2 + 0x2b0);
    dVar16 = *(double *)(param_1 + 0x2b0);
    goto LAB_00143826;
  case 0x70:
    dVar15 = *(double *)(param_2 + 0x2a8);
    dVar16 = *(double *)(param_2 + 0x2b0);
    if (dVar15 < 0.0) {
      dVar15 = dVar16;
      if (dVar16 < 0.0) {
        dVar15 = NAN;
      }
    }
    else if (0.0 <= dVar16) {
      dVar15 = dVar15 + dVar16;
    }
    dVar16 = *(double *)(param_1 + 0x2a8);
    dVar1 = *(double *)(param_1 + 0x2b0);
    if (dVar16 < 0.0) {
      dVar16 = dVar1;
      if (dVar1 < 0.0) {
        uVar7 = 0;
        goto LAB_00143849;
      }
    }
    else if (0.0 <= dVar1) {
      dVar16 = dVar16 + dVar1;
    }
    iVar5 = (uint)(dVar15 < dVar16) - (uint)(dVar16 < dVar15);
    if (iVar5 != 0) {
      return iVar5;
    }
    uVar7 = 1;
    goto LAB_00143849;
  case 0x71:
    pcVar10 = *(char **)(param_2 + 0x2c8);
    pcVar11 = *(char **)(param_1 + 0x2c8);
    if (pcVar10 == (char *)0x0) {
      pcVar10 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    iVar5 = strcmp(pcVar11,pcVar10);
    return iVar5;
  case 0x72:
    uVar7 = *(uint *)(param_1 + 0x2e0);
    uVar6 = *(uint *)(param_2 + 0x2e0);
LAB_00143910:
    return (uint)(uVar6 < uVar7) - (uint)(uVar7 < uVar6);
  case 0x73:
    uVar7 = *(uint *)(param_1 + 0x1e8);
    if (uVar7 >> 0xd == 0) {
      uVar7 = (uint)((*(long *)(param_1 + 200) + 0x14) / 5) | 0x4000;
    }
    uVar6 = *(uint *)(param_2 + 0x1e8);
    if (uVar6 >> 0xd == 0) {
      uVar6 = (uint)((*(long *)(param_2 + 200) + 0x14) / 5) | 0x4000;
    }
    return (uint)((int)uVar6 < (int)uVar7) - (uint)((int)uVar7 < (int)uVar6);
  case 0x74:
    dVar15 = (double)*(float *)(param_2 + 0x308);
    dVar16 = (double)*(float *)(param_1 + 0x308);
    goto LAB_00143826;
  case 0x75:
    dVar15 = (double)*(float *)(param_2 + 0x30c);
    dVar16 = (double)*(float *)(param_1 + 0x30c);
    goto LAB_00143826;
  case 0x76:
    dVar15 = (double)*(float *)(param_2 + 0x310);
    dVar16 = (double)*(float *)(param_1 + 0x310);
LAB_00143826:
    iVar5 = (uint)(dVar15 < dVar16) - (uint)(dVar16 < dVar15);
    if (iVar5 != 0) {
      return iVar5;
    }
    uVar7 = (uint)!NAN(dVar16);
LAB_00143849:
    return uVar7 - (!NAN(dVar15) && !NAN(dVar15));
  case 0x77:
    lVar3 = *(long *)(param_2 + 0x230);
    lVar4 = *(long *)(param_1 + 0x230);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
    goto LAB_00143713;
  case 0x78:
    lVar3 = *(long *)(param_2 + 0x238);
    lVar4 = *(long *)(param_1 + 0x238);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
    goto LAB_00143713;
  case 0x79:
    lVar3 = *(long *)(param_2 + 0x240);
    lVar4 = *(long *)(param_1 + 0x240);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
    goto LAB_00143713;
  case 0x7a:
    uVar8 = *(ulong *)(param_1 + 800);
    uVar9 = *(ulong *)(param_2 + 800);
    break;
  case 0x7b:
    pcVar10 = *(char **)(param_2 + 0x328);
    pcVar11 = *(char **)(param_1 + 0x328);
    if (pcVar10 == (char *)0x0) {
      pcVar10 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    iVar5 = strcmp(pcVar11,pcVar10);
    return iVar5;
  case 0x7f:
    lVar3 = *(long *)(param_2 + 0x338);
    lVar4 = *(long *)(param_1 + 0x338);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
    goto LAB_00143713;
  case 0x80:
    iVar5 = *(int *)(param_2 + 0x340);
    iVar2 = *(int *)(param_1 + 0x340);
    bVar14 = SBORROW4(iVar2,iVar5);
    bVar13 = iVar2 - iVar5 < 0;
    bVar12 = iVar2 == iVar5;
    goto LAB_00143713;
  case 0x81:
    pcVar10 = *(char **)(param_2 + 0x2d0);
    pcVar11 = *(char **)(param_1 + 0x2d0);
    if (pcVar10 == (char *)0x0) {
      pcVar10 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    iVar5 = strcmp(pcVar11,pcVar10);
    return iVar5;
  case 0x82:
    pcVar10 = *(char **)(param_2 + 0x2d8);
    pcVar11 = *(char **)(param_1 + 0x2d8);
    if (pcVar10 == (char *)0x0) {
      pcVar10 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    iVar5 = strcmp(pcVar11,pcVar10);
    return iVar5;
  case 0x83:
    lVar3 = *(long *)(param_2 + 0x228);
    lVar4 = *(long *)(param_1 + 0x228);
    bVar14 = SBORROW8(lVar4,lVar3);
    bVar13 = lVar4 - lVar3 < 0;
    bVar12 = lVar4 == lVar3;
LAB_00143713:
    return (uint)(!bVar12 && bVar14 == bVar13) - (uint)(bVar14 != bVar13);
  }
  return (uint)(uVar9 < uVar8) - (uint)(uVar8 < uVar9);
}

