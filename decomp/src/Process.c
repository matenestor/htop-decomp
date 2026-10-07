#include "htop.h"

/* Process_rowGetSortKey @ 0x11fbd0 */

long Process_rowGetSortKey(long param_1)

{
  if (((*(char *)(param_1 + 0x4d) == '\0') || (*(char *)(**(long **)(param_1 + 8) + 0x58) == '\0'))
     && (*(long *)(param_1 + 0x118) != 0)) {
    return *(long *)(param_1 + 0x118);
  }
  return *(long *)(param_1 + 0x80);
}


/* Process_rowIsHighlighted @ 0x11fc00 */

uint Process_rowIsHighlighted(long param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;

  bVar1 = *(byte *)(**(long **)(param_1 + 8) + 0x57);
  uVar3 = (uint)bVar1;
  if (bVar1 != 0) {
    iVar2 = (int)(*(long **)(param_1 + 8))[0x11];
    uVar3 = CONCAT31((int3)((uint)iVar2 >> 8),*(int *)(param_1 + 0x60) != iVar2);
  }
  return uVar3;
}


/* Process_rowIsVisible @ 0x11fc20 */

byte Process_rowIsVisible(long param_1,long param_2)

{
  byte bVar1;

  bVar1 = 1;
  if ((*(char *)(**(long **)(param_2 + 0x20) + 0x5b) != '\0') &&
     (bVar1 = 0, *(char *)(param_1 + 0x4d) == '\0')) {
    return *(byte *)(param_1 + 0x4c) ^ 1;
  }
  return bVar1;
}


/* FUN_0011fc50 @ 0x11fc50 */

void FUN_0011fc50(long param_1)

{
  long *plVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;

  *(undefined16 *)(*(undefined1 (*) [16])(param_1 + 0x48)) = (undefined16)0x0;
  iVar3 = (int)(*(long **)(param_1 + 8))[3];
  if (0 < iVar3) {
    plVar5 = (long *)**(long **)(param_1 + 8);
    plVar1 = plVar5 + iVar3;
    do {
      lVar4 = *plVar5;
      plVar5 = plVar5 + 1;
      uVar2 = *(undefined1 *)(lVar4 + 0x1e);
      *(undefined1 *)(lVar4 + 0x21) = 0;
      *(undefined1 *)(lVar4 + 0x1e) = 1;
      *(undefined1 *)(lVar4 + 0x1f) = uVar2;
    } while (plVar1 != plVar5);
  }
  return;
}


/* Process_getCommand @ 0x121610 */

long Process_getCommand(long param_1)

{
  if (((*(char *)(param_1 + 0x4d) == '\0') || (*(char *)(**(long **)(param_1 + 8) + 0x58) == '\0'))
     && (*(long *)(param_1 + 0x118) != 0)) {
    return *(long *)(param_1 + 0x118);
  }
  return *(long *)(param_1 + 0x80);
}


/* Process_fillStarttimeBuffer @ 0x1224a0 */

void Process_fillStarttimeBuffer(long param_1)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  long lVar1;
  char *__format;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = *(long *)(*(long *)(param_1 + 8) + 8);
  localtime_r((time_t *)(param_1 + 0xd8),&(*(tm *)(__fp - 0x68)));
  __format = ((char *)(long)&DAT_0014876e /* "%R " */);
  if ((*(long *)(param_1 + 0xd8) < lVar1 + -0x1517f) &&
     (__format = ((char *)(long)&DAT_00148778 /* " %Y " */), lVar1 + -0x1dfe1ff <= *(long *)(param_1 + 0xd8))) {
    __format = ((char *)(long)&s__b_d_00148772 /* "%b%d " */);
  }
  strftime((char *)(param_1 + 0xe0),7,__format,&(*(tm *)(__fp - 0x68)));
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Process_writeCommand @ 0x122550 */

void Process_writeCommand(long param_1,uint param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  long lVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  ulong uVar17;
  char *pcVar18;
  ulong uVar19;
  int iVar20;
  long lVar21;
  int iVar22;

  iVar22 = *param_4;
  lVar6 = **(long **)(param_1 + 8);
  cVar3 = *(char *)(lVar6 + 0x5c);
  cVar4 = *(char *)(lVar6 + 0x5d);
  if (*(char **)(param_1 + 0x118) != (char *)0x0) {
    RichString_appendWide(param_4,param_2,*(char **)(param_1 + 0x118));
    uVar17 = *(ulong *)(param_1 + 0x120);
    uVar19 = 8;
    if (uVar17 < 9) {
      uVar19 = uVar17;
    }
    if (uVar17 == 0) {
      return;
    }
    piVar14 = (int *)(param_1 + 0x128);
    uVar17 = 0;
    do {
      if (((*(long *)(piVar14 + 2) != 0) &&
          ((uVar5 = piVar14[5], (uVar5 & 2) == 0 || (cVar3 != '\0')))) &&
         ((((uVar5 & 8) == 0 && ((uVar5 & 0x10) == 0)) || (cVar4 != '\0')))) {
        iVar15 = piVar14[4];
        iVar20 = *piVar14 + iVar22;
        iVar7 = (int)*(long *)(piVar14 + 2) + iVar20;
        iVar16 = 0;
        if (-1 < iVar7) {
          iVar16 = iVar7;
        }
        iVar13 = *param_4;
        if (iVar7 <= *param_4) {
          iVar13 = iVar16;
        }
        if (iVar20 < iVar13) {
          piVar8 = (int *)(*(long *)(param_4 + 2) + (long)iVar20 * 0x1c);
          piVar1 = (int *)(*(long *)(param_4 + 2) +
                          ((ulong)(uint)(iVar13 - iVar20) + (long)iVar20) * 0x1c);
          if (((int)piVar1 - (int)piVar8 & 4U) != 0) {
            *piVar8 = iVar15;
            piVar8 = piVar8 + 7;
            if (piVar8 == piVar1) goto LAB_00122670;
          }
          do {
            *piVar8 = iVar15;
            piVar9 = piVar8 + 0xe;
            piVar8[7] = iVar15;
            piVar8 = piVar9;
          } while (piVar9 != piVar1);
        }
      }
LAB_00122670:
      uVar17 = uVar17 + 1;
      piVar14 = piVar14 + 6;
      if (uVar19 <= uVar17) {
        return;
      }
    } while( true );
  }
  pcVar18 = *(char **)(param_1 + 0x80);
  if (cVar3 == '\0') {
    iVar16 = 0;
    if (*(char *)(lVar6 + 0x56) != '\0') goto LAB_0012270c;
    iVar15 = *(int *)(param_1 + 0x88);
    lVar21 = 0;
    if (0 < iVar15) goto LAB_001226be;
  }
  else {
    iVar15 = *(int *)(param_1 + 0x88);
    if (iVar15 < 1) {
      lVar21 = 0;
    }
    else {
LAB_001226be:
      lVar10 = 1;
      lVar21 = 0;
      while( true ) {
        iVar16 = (int)lVar10;
        if (pcVar18[lVar10 + -1] == '/') {
          lVar21 = (long)iVar16;
        }
        else if (pcVar18[lVar10 + -1] == ':') goto LAB_0012270c;
        if (lVar10 == iVar15) break;
        lVar10 = lVar10 + 1;
      }
      iVar15 = iVar15 - (int)lVar21;
    }
    if (*(char *)(lVar6 + 0x56) != '\0') {
      iVar22 = iVar22 + (int)lVar21;
      iVar16 = iVar15;
      goto LAB_0012270c;
    }
  }
  pcVar18 = pcVar18 + lVar21;
  iVar16 = iVar15;
LAB_0012270c:
  RichString_appendWide(param_4,param_2,pcVar18);
  if (*(char *)(lVar6 + 0x5c) != '\0') {
    iVar16 = iVar16 + iVar22;
    iVar15 = 0;
    if (-1 < iVar16) {
      iVar15 = iVar16;
    }
    iVar7 = *param_4;
    if (iVar16 <= *param_4) {
      iVar7 = iVar15;
    }
    if (iVar22 < iVar7) {
      puVar11 = (undefined4 *)(*(long *)(param_4 + 2) + (long)iVar22 * 0x1c);
      puVar2 = (undefined4 *)
               (*(long *)(param_4 + 2) + ((ulong)(uint)(iVar7 - iVar22) + (long)iVar22) * 0x1c);
      if (((int)puVar2 - (int)puVar11 & 4U) != 0) {
        *puVar11 = param_3;
        puVar11 = puVar11 + 7;
        if (puVar2 == puVar11) {
          return;
        }
      }
      do {
        *puVar11 = param_3;
        puVar11[7] = param_3;
        if (puVar2 == puVar11 + 0xe) {
          return;
        }
        puVar11[0xe] = param_3;
        puVar12 = puVar11 + 0x1c;
        puVar11[0x15] = param_3;
        puVar11 = puVar12;
      } while (puVar2 != puVar12);
    }
  }
  return;
}


/* Process_done @ 0x1227f0 */

void Process_done(long param_1)

{
  free(*(void **)(param_1 + 0x80));
  free(*(void **)(param_1 + 0x90));
  free(*(void **)(param_1 + 0x98));
  free(*(void **)(param_1 + 0xa0));
  free(*(void **)(param_1 + 0x118));
  free(*(void **)(param_1 + 0x58));
  return;
}


/* Process_init @ 0x122850 */

void Process_init(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0x1d) = 0x1000100;
  *(undefined1 *)(param_1 + 0x21) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
  return;
}


/* Process_rowSendSignal @ 0x1228a0 */

bool Process_rowSendSignal(long param_1,int param_2)

{
  int iVar1;

  iVar1 = kill(*(__pid_t *)(param_1 + 0x10),param_2);
  return iVar1 == 0;
}


/* Process_compareByKey_Base @ 0x1228c0 */

int Process_compareByKey_Base(long param_1,long param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;

  switch(param_3) {
  default:
    goto switchD_001228df_caseD_0;
  case 2:
    if ((((*(char *)(param_2 + 0x4d) != '\0') &&
         (*(char *)(**(long **)(param_2 + 8) + 0x58) != '\0')) ||
        (pcVar12 = *(char **)(param_2 + 0x118), pcVar12 == (char *)0x0)) &&
       (pcVar12 = *(char **)(param_2 + 0x80), pcVar12 == (char *)0x0)) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if ((((*(char *)(param_1 + 0x4d) != '\0') &&
         (*(char *)(**(long **)(param_1 + 8) + 0x58) != '\0')) ||
        (pcVar11 = *(char **)(param_1 + 0x118), pcVar11 == (char *)0x0)) &&
       (pcVar11 = *(char **)(param_1 + 0x80), pcVar11 == (char *)0x0)) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    goto LAB_001229cf;
  case 3:
    uVar9 = *(uint *)(param_1 + 0x108);
    uVar6 = *(uint *)(param_2 + 0x108);
    goto LAB_00122acc;
  case 4:
    iVar7 = *(int *)(param_2 + 0x18);
    iVar3 = *(int *)(param_1 + 0x18);
    bVar15 = SBORROW4(iVar3,iVar7);
    bVar14 = iVar3 - iVar7 < 0;
    bVar13 = iVar3 == iVar7;
    break;
  case 5:
    iVar7 = *(int *)(param_2 + 0x40);
    iVar3 = *(int *)(param_1 + 0x40);
    bVar15 = SBORROW4(iVar3,iVar7);
    bVar14 = iVar3 - iVar7 < 0;
    bVar13 = iVar3 == iVar7;
    break;
  case 6:
    iVar7 = *(int *)(param_2 + 0x44);
    iVar3 = *(int *)(param_1 + 0x44);
    bVar15 = SBORROW4(iVar3,iVar7);
    bVar14 = iVar3 - iVar7 < 0;
    bVar13 = iVar3 == iVar7;
    break;
  case 7:
    pcVar11 = *(char **)(param_2 + 0x58);
    pcVar12 = *(char **)(param_1 + 0x58);
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00148785 /* "\x7f" */);
    }
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00148785 /* "\x7f" */);
    }
    iVar7 = strcmp(pcVar12,pcVar11);
    return iVar7;
  case 8:
    iVar7 = *(int *)(param_2 + 0x48);
    iVar3 = *(int *)(param_1 + 0x48);
    bVar15 = SBORROW4(iVar3,iVar7);
    bVar14 = iVar3 - iVar7 < 0;
    bVar13 = iVar3 == iVar7;
    break;
  case 10:
    uVar10 = *(ulong *)(param_1 + 0xf8);
    uVar8 = *(ulong *)(param_2 + 0xf8);
    goto LAB_00122a6f;
  case 0xc:
    uVar10 = *(ulong *)(param_1 + 0x100);
    uVar8 = *(ulong *)(param_2 + 0x100);
    goto LAB_00122a6f;
  case 0x12:
    lVar4 = *(long *)(param_2 + 0xc0);
    lVar5 = *(long *)(param_1 + 0xc0);
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x13:
    lVar4 = *(long *)(param_2 + 200);
    lVar5 = *(long *)(param_1 + 200);
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x15:
    iVar7 = (uint)(*(long *)(param_2 + 0xd8) < *(long *)(param_1 + 0xd8)) -
            (uint)(*(long *)(param_1 + 0xd8) < *(long *)(param_2 + 0xd8));
    goto joined_r0x001228ff;
  case 0x26:
    iVar7 = *(int *)(param_2 + 0xb0);
    iVar3 = *(int *)(param_1 + 0xb0);
    bVar15 = SBORROW4(iVar3,iVar7);
    bVar14 = iVar3 - iVar7 < 0;
    bVar13 = iVar3 == iVar7;
    break;
  case 0x27:
    lVar4 = *(long *)(param_2 + 0xe8);
    lVar5 = *(long *)(param_1 + 0xe8);
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x28:
  case 0x30:
    lVar4 = *(long *)(param_2 + 0xf0);
    lVar5 = *(long *)(param_1 + 0xf0);
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x2e:
    uVar9 = *(uint *)(param_1 + 0x60);
    uVar6 = *(uint *)(param_2 + 0x60);
LAB_00122acc:
    return (uint)(uVar6 < uVar9) - (uint)(uVar9 < uVar6);
  case 0x2f:
  case 0x35:
    fVar1 = *(float *)(param_2 + 0xb4);
    fVar2 = *(float *)(param_1 + 0xb4);
    iVar7 = (uint)(fVar1 < fVar2) - (uint)(fVar2 < fVar1);
    if (iVar7 != 0) {
      return iVar7;
    }
    return (uint)!NAN(fVar2) - (uint)!NAN(fVar1);
  case 0x31:
    pcVar12 = *(char **)(param_2 + 0x68);
    pcVar11 = *(char **)(param_1 + 0x68);
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    goto LAB_001229cf;
  case 0x32:
    uVar10 = *(ulong *)(param_1 + 0x78);
    uVar8 = *(ulong *)(param_2 + 0x78);
LAB_00122a6f:
    return (uint)(uVar8 < uVar10) - (uint)(uVar10 < uVar8);
  case 0x33:
    lVar4 = *(long *)(param_2 + 0xd0);
    lVar5 = *(long *)(param_1 + 0xd0);
    bVar15 = SBORROW8(lVar5,lVar4);
    bVar14 = lVar5 - lVar4 < 0;
    bVar13 = lVar5 == lVar4;
    break;
  case 0x34:
    iVar7 = *(int *)(param_2 + 0x14);
    iVar3 = *(int *)(param_1 + 0x14);
    bVar15 = SBORROW4(iVar3,iVar7);
    bVar14 = iVar3 - iVar7 < 0;
    bVar13 = iVar3 == iVar7;
    break;
  case 0x36:
    iVar7 = (uint)(*(long *)(param_1 + 0xd8) < *(long *)(param_2 + 0xd8)) -
            (uint)(*(long *)(param_2 + 0xd8) < *(long *)(param_1 + 0xd8));
joined_r0x001228ff:
    if (iVar7 != 0) {
      return iVar7;
    }
switchD_001228df_caseD_0:
    iVar7 = *(int *)(param_2 + 0x10);
    iVar3 = *(int *)(param_1 + 0x10);
    bVar15 = SBORROW4(iVar3,iVar7);
    bVar14 = iVar3 - iVar7 < 0;
    bVar13 = iVar3 == iVar7;
    break;
  case 0x37:
    iVar7 = *(int *)(param_2 + 0x10c);
    iVar3 = *(int *)(param_1 + 0x10c);
    bVar15 = SBORROW4(iVar3,iVar7);
    bVar14 = iVar3 - iVar7 < 0;
    bVar13 = iVar3 == iVar7;
    break;
  case 0x7c:
    pcVar11 = *(char **)(param_1 + 0x90);
    if ((pcVar11 == (char *)0x0) && (pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */), *(char *)(param_1 + 0x4c) != '\0')) {
      pcVar11 = ((char *)(long)&s_KTHREAD_0014877d /* "KTHREAD" */);
    }
    pcVar12 = *(char **)(param_2 + 0x90);
    if (pcVar12 != (char *)0x0) goto LAB_001229cf;
    goto LAB_001229f0;
  case 0x7d:
    if (*(long *)(param_1 + 0x98) == 0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
      if (*(char *)(param_1 + 0x4c) != '\0') {
        pcVar11 = ((char *)(long)&s_KTHREAD_0014877d /* "KTHREAD" */);
      }
    }
    else {
      pcVar11 = (char *)(*(long *)(param_1 + 0x98) + (long)*(int *)(param_1 + 0xa8));
    }
    if (*(long *)(param_2 + 0x98) != 0) {
      pcVar12 = (char *)(*(long *)(param_2 + 0x98) + (long)*(int *)(param_2 + 0xa8));
      goto LAB_001229cf;
    }
LAB_001229f0:
    pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    if (*(char *)(param_2 + 0x4c) != '\0') {
      pcVar12 = ((char *)(long)&s_KTHREAD_0014877d /* "KTHREAD" */);
    }
LAB_001229cf:
    iVar7 = strcmp(pcVar11,pcVar12);
    return iVar7;
  case 0x7e:
    pcVar11 = *(char **)(param_2 + 0xa0);
    pcVar12 = *(char **)(param_1 + 0xa0);
    if (pcVar11 == (char *)0x0) {
      pcVar11 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    if (pcVar12 == (char *)0x0) {
      pcVar12 = ((char *)(long)&DAT_00149c0c /* "" */);
    }
    iVar7 = strcmp(pcVar12,pcVar11);
    return iVar7;
  }
  return (uint)(!bVar13 && bVar15 == bVar14) - (uint)(bVar15 != bVar14);
}


/* Process_compare @ 0x122c50 */

int Process_compare(long *param_1,long param_2,long param_rdx,long param_rcx,long param_r8,
                   long param_r9)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong a2;

  lVar1 = *(long *)(*(long *)param_1[1] + 0x40);
  if (*(char *)(lVar1 + 0x34) == '\0') {
    a2 = (ulong)*(uint *)(lVar1 + 0x2c);
  }
  else {
    a2 = 1;
    if (*(char *)(lVar1 + 0x35) == '\0') {
      a2 = (ulong)*(uint *)(lVar1 + 0x30);
    }
  }
  if (*(code **)(*param_1 + 0x50) == (code *)0x0) {
    iVar3 = Process_compareByKey_Base((long)param_1,param_2,(int)a2);
  }
  else {
    lVar4 = (**(code **)(*param_1 + 0x50))((long)param_1,param_2,a2,param_rcx,param_r8,param_r9);
    iVar3 = (int)lVar4;
  }
  if (iVar3 != 0) {
    iVar2 = *(int *)(lVar1 + 0x28);
    if (*(char *)(lVar1 + 0x34) == '\0') {
      iVar2 = *(int *)(lVar1 + 0x24);
    }
    if (iVar2 != 1) {
      iVar3 = -iVar3;
    }
    return iVar3;
  }
  return (uint)(*(int *)(param_2 + 0x10) < (int)param_1[2]) -
         (uint)((int)param_1[2] < *(int *)(param_2 + 0x10));
}


/* Process_compareByParent @ 0x122d10 */

void Process_compareByParent
               (long *param_1,long param_2,long param_rdx,long param_rcx,long param_r8,long param_r9
               )

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;

  bVar1 = *(byte *)(param_2 + 0x1c);
  uVar8 = (ulong)bVar1;
  if (*(char *)((long)param_1 + 0x1c) == '\0') {
    uVar7 = *(uint *)((long)param_1 + 0x14);
    param_r9 = (long)uVar7;
    uVar6 = uVar7;
    if (*(uint *)(param_1 + 2) == uVar7) {
      uVar6 = *(uint *)(param_1 + 3);
      uVar5 = (uint)(0 < (int)uVar6);
      param_rcx = 0;
      if (bVar1 == 0) goto LAB_00122d58;
    }
    else if (bVar1 == 0) {
LAB_00122d58:
      uVar2 = *(uint *)(param_2 + 0x14);
      param_rcx = (long)uVar2;
      uVar3 = *(uint *)(param_2 + 0x10);
      uVar8 = (ulong)uVar3;
      if (uVar2 == uVar3) {
        uVar5 = (uint)(*(int *)(param_2 + 0x18) < (int)uVar6);
        if (*(uint *)(param_1 + 2) == uVar7) goto LAB_00122d75;
LAB_00122d7d:
        uVar6 = *(uint *)(param_2 + 0x18);
        param_rcx = (long)uVar6;
        param_rdx = (long)((int)uVar7 < (int)uVar6);
        if (uVar5 != (int)uVar7 < (int)uVar6) {
          return;
        }
        goto LAB_00122d8c;
      }
      uVar5 = (uint)((int)uVar2 < (int)uVar6);
      uVar6 = uVar7;
      if (uVar7 == *(uint *)(param_1 + 2)) {
LAB_00122d75:
        uVar7 = *(uint *)(param_1 + 3);
        uVar6 = uVar7;
        if (uVar2 == uVar3) goto LAB_00122d7d;
      }
    }
    else {
      uVar5 = (uint)(0 < (int)uVar7);
      param_rcx = 0;
    }
  }
  else {
    if (bVar1 != 0) goto LAB_00122d8c;
    uVar5 = *(uint *)(param_2 + 0x14);
    if (uVar5 == *(uint *)(param_2 + 0x10)) {
      uVar5 = *(uint *)(param_2 + 0x18);
    }
    param_rcx = (long)uVar5;
    uVar5 = uVar5 >> 0x1f;
    uVar6 = 0;
  }
  bVar4 = (int)uVar6 < (int)param_rcx;
  param_rdx = (long)bVar4;
  if (uVar5 != bVar4) {
    return;
  }
LAB_00122d8c:
  Process_compare(param_1,param_2,param_rdx,param_rcx,uVar8,param_r9);
  return;
}


/* Process_updateCPUFieldWidths @ 0x122df0 */

void Process_updateCPUFieldWidths(float param_1)

{
  byte bVar1;
  byte bVar2;
  double dVar3;

  bVar1 = BYTE_0015d48f;
  if (param_1 < 99.9) {
    if (BYTE_0015d48f < 4) {
      BYTE_0015d48f = 4;
    }
    if (BYTE_0015d495 < 4) {
      BYTE_0015d495 = 4;
      return;
    }
  }
  else {
    dVar3 = log10((double)param_1 + 0.1);
    if (ABS(dVar3) < 4503599627370496.0) {
      dVar3 = __builtin_ceil(dVar3);
    }
    bVar2 = (byte)(int)(dVar3 + 2.0);
    if (bVar1 < bVar2) {
      BYTE_0015d48f = bVar2;
    }
    if ((uint)BYTE_0015d495 < ((int)(dVar3 + 2.0) & 0xffU)) {
      BYTE_0015d495 = bVar2;
    }
  }
  return;
}


/* Process_rowChangePriorityBy @ 0x122f80 */

bool Process_rowChangePriorityBy(long param_1,int param_2)

{
  bool bVar1;

  if (CHAR____0015c0d9 != '\0') {
    return false;
  }
  bVar1 = FUN_00122f10(param_1,param_2 + *(int *)(param_1 + 200));
  return bVar1;
}


/* Process_rowSetPriority @ 0x122fa0 */

bool Process_rowSetPriority(long param_1,int param_2)

{
  bool bVar1;

  if (CHAR____0015c0d9 != '\0') {
    return false;
  }
  bVar1 = FUN_00122f10(param_1,param_2);
  return bVar1;
}


/* Process_makeCommandStr @ 0x1243c0 */

void Process_makeCommandStr(long param_1,long param_2)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  long *plVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *__s;
  char cVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  size_t sVar15;
  char *pcVar16;
  char *pcVar17;
  size_t sVar18;
  char *pcVar19;
  undefined8 uVar20;
  ulong uVar21;
  byte bVar22;
  byte bVar23;
  long lVar24;
  long lVar25;
  char *pcVar26;
  long lVar27;
  undefined8 *puVar28;
  int iVar29;
  char *pcVar30;
  char *__s1;
  char *__s1_00;
  int iVar31;
  long lVar32;
  byte bVar33;
  bool bVar34;
  byte bVar35;

  bVar35 = 0;
  cVar7 = *(char *)(param_2 + 0x6a);
  bVar33 = *(byte *)(param_2 + 0x56);
  bVar2 = *(byte *)(param_2 + 0x68);
  bVar8 = *(byte *)(param_2 + 0x69);
  bVar22 = *(byte *)(param_2 + 0x58);
  cVar3 = *(char *)(param_2 + 0x5e);
  if (*(char *)(param_1 + 0x4c) != '\0') {
    return;
  }
  if (*(int *)(param_1 + 0x108) == 0xb) {
    if (*(long *)(param_1 + 0x118) == 0) {
      return;
    }
    uVar21 = *(ulong *)(param_1 + 0x110);
  }
  else {
    uVar21 = *(ulong *)(param_1 + 0x110);
  }
  if (*(ulong *)(param_2 + 0x78) <= uVar21) {
    return;
  }
  *(ulong *)(param_1 + 0x110) = *(ulong *)(param_2 + 0x78);
  pcVar26 = *(char **)CRT_treeStr;
  sVar15 = strlen(pcVar26);
  iVar14 = (int)sVar15;
  (*(size_t *)(__fp - 0x60)) = 8;
  if (*(char **)(param_1 + 0x80) != (char *)0x0) {
    (*(size_t *)(__fp - 0x60)) = strlen(*(char **)(param_1 + 0x80));
  }
  (*(size_t *)(__fp - 0x60)) = (long)(iVar14 * 2 + 1) + (*(size_t *)(__fp - 0x60));
  if (*(char **)(param_1 + 0x90) != (char *)0x0) {
    sVar15 = strlen(*(char **)(param_1 + 0x90));
    (*(size_t *)(__fp - 0x60)) = (*(size_t *)(__fp - 0x60)) + sVar15;
  }
  if (*(char **)(param_1 + 0x98) != (char *)0x0) {
    sVar15 = strlen(*(char **)(param_1 + 0x98));
    (*(size_t *)(__fp - 0x60)) = (*(size_t *)(__fp - 0x60)) + sVar15;
  }
  free(*(void **)(param_1 + 0x118));
  pcVar16 = calloc(1,(*(size_t *)(__fp - 0x60)));
  if (pcVar16 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  *(undefined8 *)(param_1 + 0x128) = 0;
  *(undefined8 *)(param_1 + 0x1e0) = 0;
  puVar28 = (undefined8 *)(param_1 + 0x130U & 0xfffffffffffffff8);
  *(char **)(param_1 + 0x118) = pcVar16;
  *(undefined8 *)(param_1 + 0x120) = 0;
  uVar21 = (ulong)(((int)param_1 - (int)puVar28) + 0x1e8U >> 3);
  for (; lVar25 = CRT_colors, uVar21 != 0; uVar21 = uVar21 - 1) {
    *puVar28 = 0;
    puVar28 = puVar28 + (ulong)bVar35 * -2 + 1;
  }
  bVar35 = *(byte *)(param_1 + 0x4d);
  if ((bVar35 == 0) && (*(char *)(param_1 + 0x4c) == '\0')) {
    uVar4 = *(undefined4 *)(CRT_colors + 0x94);
    (*(undefined4 *)(__fp - 0x94)) = *(undefined4 *)(CRT_colors + 0xb0);
  }
  else {
    uVar4 = *(undefined4 *)(CRT_colors + 0xac);
    (*(undefined4 *)(__fp - 0x94)) = *(undefined4 *)(CRT_colors + 0xb4);
  }
  __s1_00 = *(char **)(param_1 + 0x80);
  pcVar19 = *(char **)(param_1 + 0x98);
  iVar31 = *(int *)(param_1 + 0x8c);
  uVar5 = *(undefined4 *)(CRT_colors + 0x14);
  uVar6 = *(undefined4 *)(CRT_colors + 0x7c);
  iVar29 = *(int *)(param_1 + 0x88);
  __s = *(char **)(param_1 + 0x90);
  if (__s1_00 == (char *)0x0) {
    iVar29 = 0;
    iVar31 = 0;
    __s1_00 = ((char *)(long)&s__zombie__00148787 /* "(zombie)" */);
  }
  if (cVar7 != '\x01' || pcVar19 == (char *)0x0) {
    if ((((cVar7 == '\0') && ((bVar22 == 0 || (bVar35 == 0)))) || (__s == (char *)0x0)) ||
       (*__s == '\0')) {
LAB_001247b0:
      lVar32 = 0;
      pcVar26 = pcVar16;
    }
    else {
      sVar18 = strlen(__s);
      sVar15 = 0xf;
      if (sVar18 < 0x10) {
        sVar15 = sVar18;
      }
      iVar9 = strncmp(__s1_00 + iVar31,__s,sVar15);
      if (iVar9 == 0) goto LAB_001247b0;
      *(size_t *)(param_1 + 0x130) = sVar18;
      *(undefined4 *)(param_1 + 0x13c) = 4;
      *(undefined4 *)(param_1 + 0x138) = (*(undefined4 *)(__fp - 0x94));
      *(undefined8 *)(param_1 + 0x120) = 1;
      pcVar19 = __stpcpy_chk(pcVar16,__s,(*(size_t *)(__fp - 0x60)));
      if (cVar7 == '\0') {
        return;
      }
      *(undefined8 *)(param_1 + 0x148) = 1;
      *(long *)(param_1 + 0x140) = (long)pcVar19 - (long)pcVar16;
      uVar11 = *(undefined4 *)(lVar25 + 0x14);
      *(undefined4 *)(param_1 + 0x154) = 1;
      *(undefined8 *)(param_1 + 0x120) = 2;
      *(undefined4 *)(param_1 + 0x150) = uVar11;
      lVar32 = (long)(iVar14 + -1);
      pcVar26 = stpcpy(pcVar19,pcVar26);
    }
    if ((bVar33 == 0) || (cVar3 == '\0')) {
      if (iVar29 <= iVar31) goto LAB_00124840;
      uVar21 = *(ulong *)(param_1 + 0x120);
      if (uVar21 < 8) {
        pcVar19 = pcVar26 + -(long)pcVar16;
        if (bVar33 != 0) {
          pcVar19 = pcVar26 + -(long)pcVar16 + iVar31;
        }
        goto LAB_001247fc;
      }
LAB_00124a67:
      if (*(char *)(param_1 + 0xac) != '\0') goto LAB_001248b6;
    }
    else {
      if (*__s1_00 == '/') {
        cVar7 = __s1_00[1];
        if (cVar7 == 's') {
          iVar14 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x1807) /* "/sbin/" */),6);
          if (iVar14 == 0) {
            uVar21 = *(ulong *)(param_1 + 0x120);
            if (uVar21 < 8) {
              lVar24 = param_1 + uVar21 * 0x18;
              *(undefined8 *)(lVar24 + 0x130) = 6;
              lVar27 = (long)pcVar26 - (long)pcVar16;
              *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
              goto LAB_001252c4;
            }
            goto LAB_00125810;
          }
        }
        else if (cVar7 < 't') {
          if (cVar7 == 'b') {
            iVar14 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17e7) /* "/bin/" */),5);
            if (iVar14 == 0) {
LAB_00125739:
              uVar21 = *(ulong *)(param_1 + 0x120);
              if (uVar21 < 8) {
                lVar24 = param_1 + uVar21 * 0x18;
                *(undefined8 *)(lVar24 + 0x130) = 5;
                lVar27 = (long)pcVar26 - (long)pcVar16;
                *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
LAB_001252c4:
                uVar21 = uVar21 + 1;
                uVar11 = *(undefined4 *)(lVar25 + 0x78);
                *(undefined4 *)(lVar24 + 0x13c) = 0x10;
                *(undefined4 *)(lVar24 + 0x138) = uVar11;
                *(ulong *)(param_1 + 0x120) = uVar21;
                if (iVar31 < iVar29) {
                  if (uVar21 != 8) {
                    pcVar19 = (char *)(iVar31 + lVar27);
                    goto LAB_001247fc;
                  }
                  goto LAB_00124a67;
                }
                goto LAB_00124840;
              }
              goto LAB_00125810;
            }
          }
          else if (cVar7 == 'l') {
            iVar14 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17f7) /* "/lib/" */),5);
            if (iVar14 == 0) goto LAB_00125739;
            iVar14 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17bc) /* "/lib32/" */),7);
            if ((iVar14 == 0) || (iVar14 = strncmp(__s1_00,((char *)(long)&s__lib64__001487c8 /* "/lib64/" */),7), iVar14 == 0)) {
              uVar21 = *(ulong *)(param_1 + 0x120);
              if (uVar21 < 8) {
                lVar27 = (long)pcVar26 - (long)pcVar16;
                lVar24 = uVar21 * 0x18 + param_1;
                *(undefined8 *)(lVar24 + 0x130) = 7;
                *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
                goto LAB_001252c4;
              }
            }
            else {
              uVar20 = FUN_00116180(__s1_00,((char *)(long)(__sec_rodata + 0x17d4) /* "/libx32/" */));
              if ((char)uVar20 == '\0') goto LAB_001247d5;
              uVar21 = *(ulong *)(param_1 + 0x120);
              if (uVar21 < 8) {
                lVar27 = (long)pcVar26 - (long)pcVar16;
                lVar24 = uVar21 * 0x18 + param_1;
                *(undefined8 *)(lVar24 + 0x130) = 8;
                *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
                goto LAB_001252c4;
              }
            }
LAB_00125810:
            if (iVar29 <= iVar31) goto LAB_00124a67;
            goto LAB_00124840;
          }
        }
        else if ((cVar7 == 'u') && (iVar14 = strncmp(__s1_00,((char *)(long)&s__usr__00148790 /* "/usr/" */),5), iVar14 == 0)) {
          cVar7 = __s1_00[5];
          if (cVar7 == 'l') {
            uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_libexec__001487a0 /* "/usr/libexec/" */));
            if ((char)uVar20 == '\0') {
              uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_lib__001487ae /* "/usr/lib/" */));
              if ((char)uVar20 != '\0') goto LAB_0012566c;
              uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_lib32__001487b8 /* "/usr/lib32/" */));
              if (((char)uVar20 == '\0') &&
                 (uVar20 = FUN_00116180(__s1_00,((char *)(long)&DAT_001487c4 /* "/usr/lib64/" */)), (char)uVar20 == '\0')) {
                uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_libx32__001487d0 /* "/usr/libx32/" */));
                if ((char)uVar20 == '\0') {
                  uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_local_bin__001487dd /* "/usr/local/bin/" */));
                  if (((char)uVar20 == '\0') &&
                     (uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_local_lib__001487ed /* "/usr/local/lib/" */)), (char)uVar20 == '\0')) {
                    uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_local_sbin__001487fd /* "/usr/local/sbin/" */));
                    if ((char)uVar20 == '\0') goto LAB_001247d5;
                    uVar21 = *(ulong *)(param_1 + 0x120);
                    if (uVar21 < 8) {
                      lVar27 = (long)pcVar26 - (long)pcVar16;
                      lVar24 = uVar21 * 0x18 + param_1;
                      *(undefined8 *)(lVar24 + 0x130) = 0x10;
                      *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
                      goto LAB_001252c4;
                    }
                  }
                  else {
                    uVar21 = *(ulong *)(param_1 + 0x120);
                    if (uVar21 < 8) {
                      lVar27 = (long)pcVar26 - (long)pcVar16;
                      lVar24 = uVar21 * 0x18 + param_1;
                      *(undefined8 *)(lVar24 + 0x130) = 0xf;
                      *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
                      goto LAB_001252c4;
                    }
                  }
                }
                else {
                  uVar21 = *(ulong *)(param_1 + 0x120);
                  if (uVar21 < 8) {
                    lVar27 = (long)pcVar26 - (long)pcVar16;
                    lVar24 = uVar21 * 0x18 + param_1;
                    *(undefined8 *)(lVar24 + 0x130) = 0xc;
                    *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
                    goto LAB_001252c4;
                  }
                }
              }
              else {
                uVar21 = *(ulong *)(param_1 + 0x120);
                if (uVar21 < 8) {
                  lVar27 = (long)pcVar26 - (long)pcVar16;
                  lVar24 = uVar21 * 0x18 + param_1;
                  *(undefined8 *)(lVar24 + 0x130) = 0xb;
                  *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
                  goto LAB_001252c4;
                }
              }
            }
            else {
              uVar21 = *(ulong *)(param_1 + 0x120);
              if (uVar21 < 8) {
                lVar27 = (long)pcVar26 - (long)pcVar16;
                lVar24 = uVar21 * 0x18 + param_1;
                *(undefined8 *)(lVar24 + 0x130) = 0xd;
                *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
                goto LAB_001252c4;
              }
            }
            goto LAB_00125810;
          }
          if (cVar7 == 's') {
            uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_sbin__0014880e /* "/usr/sbin/" */));
            if ((char)uVar20 != '\0') {
              uVar21 = *(ulong *)(param_1 + 0x120);
              if (uVar21 < 8) {
                lVar27 = (long)pcVar26 - (long)pcVar16;
                lVar24 = uVar21 * 0x18 + param_1;
                *(undefined8 *)(lVar24 + 0x130) = 10;
                *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
                goto LAB_001252c4;
              }
              goto LAB_00125810;
            }
          }
          else if ((cVar7 == 'b') &&
                  (uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_bin__00148796 /* "/usr/bin/" */)), (char)uVar20 != '\0')) {
LAB_0012566c:
            uVar21 = *(ulong *)(param_1 + 0x120);
            if (uVar21 < 8) {
              lVar27 = (long)pcVar26 - (long)pcVar16;
              lVar24 = uVar21 * 0x18 + param_1;
              *(undefined8 *)(lVar24 + 0x130) = 9;
              *(long *)(lVar24 + 0x128) = lVar27 - lVar32;
              goto LAB_001252c4;
            }
            goto LAB_00125810;
          }
        }
      }
LAB_001247d5:
      if (iVar31 < iVar29) {
        uVar21 = *(ulong *)(param_1 + 0x120);
        if (7 < uVar21) goto LAB_00124a67;
        pcVar19 = pcVar26 + ((long)iVar31 - (long)pcVar16);
LAB_001247fc:
        lVar25 = param_1 + uVar21 * 0x18;
        *(long *)(lVar25 + 0x128) = (long)pcVar19 - lVar32;
        *(undefined4 *)(lVar25 + 0x138) = uVar4;
        *(undefined4 *)(lVar25 + 0x13c) = 2;
        *(long *)(lVar25 + 0x130) = (long)(iVar29 - iVar31);
        *(ulong *)(param_1 + 0x120) = uVar21 + 1;
      }
LAB_00124840:
      if (*(char *)(param_1 + 0xac) != '\0') {
        uVar21 = *(ulong *)(param_1 + 0x120);
        if (uVar21 < 8) {
          lVar25 = (long)pcVar26 - (long)pcVar16;
          if (bVar33 != 0) {
            lVar25 = (long)iVar31 + ((long)pcVar26 - (long)pcVar16);
          }
          lVar24 = param_1 + uVar21 * 0x18;
          *(undefined4 *)(lVar24 + 0x138) = uVar5;
          *(long *)(lVar24 + 0x128) = lVar25 - lVar32;
          *(long *)(lVar24 + 0x130) = (long)(iVar29 - iVar31);
          *(undefined4 *)(lVar24 + 0x13c) = 8;
          *(ulong *)(param_1 + 0x120) = uVar21 + 1;
        }
        goto LAB_001248b6;
      }
    }
    if ((*(char *)(param_1 + 0xad) != '\0') && (uVar21 = *(ulong *)(param_1 + 0x120), uVar21 < 8)) {
      lVar25 = (long)pcVar26 - (long)pcVar16;
      if (bVar33 != 0) {
        lVar25 = (long)iVar31 + ((long)pcVar26 - (long)pcVar16);
      }
      lVar24 = param_1 + uVar21 * 0x18;
      *(undefined4 *)(lVar24 + 0x138) = uVar6;
      *(long *)(lVar24 + 0x128) = lVar25 - lVar32;
      *(undefined4 *)(lVar24 + 0x13c) = 8;
      *(long *)(lVar24 + 0x130) = (long)(iVar29 - iVar31);
      *(ulong *)(param_1 + 0x120) = uVar21 + 1;
    }
LAB_001248b6:
    if (bVar33 == 0) {
      __s1_00 = __s1_00 + iVar31;
    }
    cVar7 = *__s1_00;
    if (cVar7 != '\0') {
      pcVar16 = pcVar26;
      do {
        if (cVar7 == '\n') {
          cVar7 = ' ';
        }
        __s1_00 = __s1_00 + 1;
        pcVar26 = pcVar16 + 1;
        *pcVar16 = cVar7;
        cVar7 = *__s1_00;
        pcVar16 = pcVar26;
      } while (cVar7 != '\0');
    }
    *pcVar26 = '\0';
    return;
  }
  if (__s == (char *)0x0) goto LAB_001247b0;
  sVar15 = strlen(pcVar19);
  iVar29 = *(int *)(param_1 + 0xa8);
  (*(int *)(__fp - 0xb8)) = (int)sVar15;
  iVar9 = (*(int *)(__fp - 0xb8)) - iVar29;
  bVar22 = bVar35 ^ 1 | bVar22;
  if (bVar22 == 0) {
    if (bVar33 == 0) {
      lVar24 = 0;
      pcVar17 = pcVar19 + iVar29;
      lVar32 = 1;
      goto LAB_00124b4d;
    }
    if ((cVar3 != '\0') && (*pcVar19 == '/')) {
      cVar7 = pcVar19[1];
      if (cVar7 == 'l') {
        bVar33 = false;
LAB_0012467a:
        iVar10 = strncmp(pcVar19,((char *)(long)(__sec_rodata + 0x17f7) /* "/lib/" */),5);
        if (iVar10 == 0) {
          *(undefined8 *)(param_1 + 0x130) = 5;
          uVar11 = *(undefined4 *)(lVar25 + 0x78);
        }
        else {
          iVar10 = strncmp(pcVar19,((char *)(long)(__sec_rodata + 0x17bc) /* "/lib32/" */),7);
          if ((iVar10 != 0) && (uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__lib64__001487c8 /* "/lib64/" */)), (char)uVar20 == '\0')) {
            uVar20 = FUN_00116180(pcVar19,((char *)(long)(__sec_rodata + 0x17d4) /* "/libx32/" */));
            (*(long *)(__fp - 0x58)) = 0;
            if ((char)uVar20 != '\0') {
              *(undefined8 *)(param_1 + 0x130) = 8;
              goto LAB_00125aa0;
            }
            goto LAB_001246cf;
          }
          *(undefined8 *)(param_1 + 0x130) = 7;
          uVar11 = *(undefined4 *)(lVar25 + 0x78);
        }
        goto LAB_001246a9;
      }
      if (cVar7 < 'm') {
        if ((cVar7 == 'b') && (iVar10 = strncmp(pcVar19,((char *)(long)(__sec_rodata + 0x17e7) /* "/bin/" */),5), iVar10 == 0)) {
          *(undefined8 *)(param_1 + 0x130) = 5;
          uVar11 = *(undefined4 *)(lVar25 + 0x78);
          *(undefined4 *)(param_1 + 0x13c) = 0x10;
          *(undefined4 *)(param_1 + 0x138) = uVar11;
LAB_001260f1:
          (*(long *)(__fp - 0x58)) = 1;
          bVar33 = false;
          goto LAB_001246df;
        }
      }
      else if (cVar7 == 's') {
        iVar10 = strncmp(pcVar19,((char *)(long)(__sec_rodata + 0x1807) /* "/sbin/" */),6);
        if (iVar10 == 0) {
          *(undefined8 *)(param_1 + 0x130) = 6;
          uVar11 = *(undefined4 *)(lVar25 + 0x78);
          *(undefined4 *)(param_1 + 0x13c) = 0x10;
          *(undefined4 *)(param_1 + 0x138) = uVar11;
          goto LAB_001260f1;
        }
      }
      else if (cVar7 == 'u') {
        bVar33 = false;
        goto LAB_00125922;
      }
      (*(long *)(__fp - 0x58)) = 0;
LAB_001246d7:
      bVar33 = false;
      goto LAB_001246df;
    }
    bVar33 = false;
    lVar32 = 1;
    (*(long *)(__fp - 0x58)) = 0;
LAB_001246ee:
    (*(size_t *)(__fp - 0x80)) = (size_t)iVar9;
    (*(long *)(__fp - 0x90)) = (long)iVar29;
    cVar7 = *(char *)(param_1 + 0xac);
    lVar24 = param_1 + (*(long *)(__fp - 0x58)) * 0x18;
    *(size_t *)(lVar24 + 0x130) = (*(size_t *)(__fp - 0x80));
    *(long *)(lVar24 + 0x128) = (*(long *)(__fp - 0x90));
    *(undefined4 *)(lVar24 + 0x138) = uVar4;
    *(undefined4 *)(lVar24 + 0x13c) = 2;
    *(long *)(param_1 + 0x120) = lVar32;
    if (cVar7 == '\0') {
      if (*(char *)(param_1 + 0xad) != '\0') {
        lVar24 = param_1 + lVar32 * 0x18;
        *(long *)(lVar24 + 0x128) = (*(long *)(__fp - 0x90));
        *(undefined4 *)(lVar24 + 0x13c) = 8;
        *(size_t *)(lVar24 + 0x130) = (*(size_t *)(__fp - 0x80));
        *(undefined4 *)(lVar24 + 0x138) = uVar6;
        *(long *)(param_1 + 0x120) = lVar32 + 1;
      }
    }
    else {
      plVar1 = (long *)(param_1 + 0x128 + lVar32 * 0x18);
      *plVar1 = (*(long *)(__fp - 0x90));
      plVar1[1] = (*(size_t *)(__fp - 0x80));
      lVar24 = lVar32 * 0x18 + param_1;
      *(undefined4 *)(lVar24 + 0x138) = uVar5;
      *(undefined4 *)(lVar24 + 0x13c) = 8;
      *(long *)(param_1 + 0x120) = lVar32 + 1;
    }
    pcVar17 = __stpcpy_chk(pcVar16,pcVar19,(*(size_t *)(__fp - 0x60)));
  }
  else {
    pcVar17 = pcVar19 + iVar29;
    iVar10 = strncmp(pcVar17,__s,0xf);
    if (bVar33 != 0) {
      bVar33 = iVar10 == 0;
      (*(long *)(__fp - 0x58)) = 0;
      if ((cVar3 == '\0') || (*pcVar19 != '/')) {
LAB_001246cf:
        (*(long *)(__fp - 0x90)) = (long)iVar29;
        if ((bool)bVar33 == false) goto LAB_001246d7;
        lVar32 = param_1 + (*(long *)(__fp - 0x58)) * 0x18;
        (*(long *)(__fp - 0x58)) = (*(long *)(__fp - 0x58)) + 1;
        *(long *)(lVar32 + 0x128) = (*(long *)(__fp - 0x90));
        *(long *)(lVar32 + 0x130) = (long)iVar9;
        *(undefined4 *)(lVar32 + 0x138) = (*(undefined4 *)(__fp - 0x94));
        *(undefined4 *)(lVar32 + 0x13c) = 4;
      }
      else {
        cVar7 = pcVar19[1];
        if (cVar7 == 's') {
          iVar10 = strncmp(pcVar19,((char *)(long)(__sec_rodata + 0x1807) /* "/sbin/" */),6);
          (*(long *)(__fp - 0x58)) = 0;
          if (iVar10 == 0) {
            *(undefined8 *)(param_1 + 0x130) = 6;
LAB_00125aa0:
            uVar11 = *(undefined4 *)(lVar25 + 0x78);
LAB_001246a9:
            *(undefined4 *)(param_1 + 0x138) = uVar11;
            (*(long *)(__fp - 0x58)) = 1;
            *(undefined4 *)(param_1 + 0x13c) = 0x10;
            *(undefined8 *)(param_1 + 0x120) = 1;
          }
          goto LAB_001246cf;
        }
        if (cVar7 < 't') {
          if (cVar7 == 'b') {
            (*(long *)(__fp - 0x58)) = 0;
            iVar10 = strncmp(pcVar19,((char *)(long)(__sec_rodata + 0x17e7) /* "/bin/" */),5);
            if (iVar10 == 0) {
              *(undefined8 *)(param_1 + 0x130) = 5;
              goto LAB_00125aa0;
            }
            goto LAB_001246cf;
          }
          if (cVar7 == 'l') goto LAB_0012467a;
        }
        else if (cVar7 == 'u') {
LAB_00125922:
          iVar10 = strncmp(pcVar19,((char *)(long)&s__usr__00148790 /* "/usr/" */),5);
          if (iVar10 == 0) {
            cVar7 = pcVar19[5];
            if (cVar7 == 'l') {
              uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_libexec__001487a0 /* "/usr/libexec/" */));
              if ((char)uVar20 == '\0') {
                uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_lib__001487ae /* "/usr/lib/" */));
                if ((char)uVar20 == '\0') {
                  uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_lib32__001487b8 /* "/usr/lib32/" */));
                  if (((char)uVar20 == '\0') &&
                     (uVar20 = FUN_00116180(pcVar19,((char *)(long)&DAT_001487c4 /* "/usr/lib64/" */)), (char)uVar20 == '\0')) {
                    uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_libx32__001487d0 /* "/usr/libx32/" */));
                    if ((char)uVar20 == '\0') {
                      uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_local_bin__001487dd /* "/usr/local/bin/" */));
                      if (((char)uVar20 == '\0') &&
                         (uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_local_lib__001487ed /* "/usr/local/lib/" */)), (char)uVar20 == '\0')) {
                        uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_local_sbin__001487fd /* "/usr/local/sbin/" */));
                        (*(long *)(__fp - 0x58)) = 0;
                        if ((char)uVar20 != '\0') {
                          *(undefined8 *)(param_1 + 0x130) = 0x10;
                          goto LAB_00125aa0;
                        }
                        goto LAB_001246cf;
                      }
                      *(undefined8 *)(param_1 + 0x130) = 0xf;
                      uVar11 = *(undefined4 *)(lVar25 + 0x78);
                    }
                    else {
                      *(undefined8 *)(param_1 + 0x130) = 0xc;
                      uVar11 = *(undefined4 *)(lVar25 + 0x78);
                    }
                  }
                  else {
                    *(undefined8 *)(param_1 + 0x130) = 0xb;
                    uVar11 = *(undefined4 *)(lVar25 + 0x78);
                  }
                }
                else {
LAB_00125975:
                  *(undefined8 *)(param_1 + 0x130) = 9;
                  uVar11 = *(undefined4 *)(lVar25 + 0x78);
                }
              }
              else {
                *(undefined8 *)(param_1 + 0x130) = 0xd;
                uVar11 = *(undefined4 *)(lVar25 + 0x78);
              }
              goto LAB_001246a9;
            }
            if (cVar7 == 's') {
              uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_sbin__0014880e /* "/usr/sbin/" */));
              (*(long *)(__fp - 0x58)) = 0;
              if ((char)uVar20 != '\0') {
                *(undefined8 *)(param_1 + 0x130) = 10;
                goto LAB_00125aa0;
              }
            }
            else {
              if (cVar7 != 'b') goto LAB_00125a1a;
              uVar20 = FUN_00116180(pcVar19,((char *)(long)&s__usr_bin__00148796 /* "/usr/bin/" */));
              (*(long *)(__fp - 0x58)) = 0;
              if ((char)uVar20 != '\0') goto LAB_00125975;
            }
          }
          else {
            (*(long *)(__fp - 0x58)) = 0;
          }
          goto LAB_001246cf;
        }
LAB_00125a1a:
        (*(long *)(__fp - 0x90)) = (long)iVar29;
        if ((bool)bVar33 == false) {
          (*(long *)(__fp - 0x58)) = 0;
          bVar33 = false;
        }
        else {
          (*(long *)(__fp - 0x58)) = 1;
          *(undefined4 *)(param_1 + 0x13c) = 4;
          *(long *)(param_1 + 0x128) = (*(long *)(__fp - 0x90));
          *(long *)(param_1 + 0x130) = (long)iVar9;
          *(undefined4 *)(param_1 + 0x138) = (*(undefined4 *)(__fp - 0x94));
        }
      }
LAB_001246df:
      lVar32 = (*(long *)(__fp - 0x58)) + 1;
      goto LAB_001246ee;
    }
    if (iVar10 == 0) {
      *(long *)(param_1 + 0x130) = (long)iVar9;
      lVar24 = 1;
      *(undefined4 *)(param_1 + 0x13c) = 4;
      *(undefined4 *)(param_1 + 0x138) = (*(undefined4 *)(__fp - 0x94));
      lVar32 = 2;
      bVar33 = bVar22;
    }
    else {
      lVar32 = 1;
      lVar24 = 0;
    }
LAB_00124b4d:
    (*(size_t *)(__fp - 0x80)) = (size_t)iVar9;
    cVar7 = *(char *)(param_1 + 0xac);
    lVar24 = param_1 + lVar24 * 0x18;
    *(undefined8 *)(lVar24 + 0x128) = 0;
    *(size_t *)(lVar24 + 0x130) = (*(size_t *)(__fp - 0x80));
    *(undefined4 *)(lVar24 + 0x138) = uVar4;
    *(undefined4 *)(lVar24 + 0x13c) = 2;
    *(long *)(param_1 + 0x120) = lVar32;
    if (cVar7 == '\0') {
      if (*(char *)(param_1 + 0xad) != '\0') {
        lVar24 = param_1 + lVar32 * 0x18;
        *(size_t *)(lVar24 + 0x130) = (*(size_t *)(__fp - 0x80));
        *(undefined8 *)(lVar24 + 0x128) = 0;
        *(undefined4 *)(lVar24 + 0x138) = uVar6;
        *(undefined4 *)(lVar24 + 0x13c) = 8;
        *(long *)(param_1 + 0x120) = lVar32 + 1;
      }
    }
    else {
      lVar24 = param_1 + lVar32 * 0x18;
      *(size_t *)(lVar24 + 0x130) = (*(size_t *)(__fp - 0x80));
      *(undefined8 *)(lVar24 + 0x128) = 0;
      *(undefined4 *)(lVar24 + 0x138) = uVar5;
      *(undefined4 *)(lVar24 + 0x13c) = 8;
      *(long *)(param_1 + 0x120) = lVar32 + 1;
    }
    pcVar17 = __stpcpy_chk(pcVar16,pcVar17,(*(size_t *)(__fp - 0x60)));
  }
  (*(size_t *)(__fp - 0x80)) = (size_t)iVar9;
  (*(long *)(__fp - 0x90)) = (long)iVar29;
  bVar35 = bVar33;
  if (bVar2 == 0) {
    bVar2 = 1;
LAB_00124d40:
    (*(int *)(__fp - 0x98)) = 0;
    iVar10 = 0;
  }
  else {
    if (bVar22 == 0) goto LAB_00124d40;
    if (-1 < iVar31) {
      sVar15 = strlen(__s);
      cVar7 = __s1_00[iVar31];
      pcVar30 = __s1_00 + iVar31;
LAB_00124c40:
      __s1 = pcVar30;
      if (cVar7 != '\0') {
        pcVar30 = __s1;
        if (cVar7 == '\n') {
          if (sVar15 == 0) {
LAB_0012515f:
            (*(int *)(__fp - 0x98)) = (int)__s1 - (int)__s1_00;
            iVar10 = (int)pcVar30 - (int)__s1_00;
            bVar35 = bVar22;
            bVar2 = bVar33;
            goto LAB_00124d54;
          }
LAB_00124ca6:
          do {
            cVar7 = __s1[1];
            pcVar30 = __s1 + 1;
            if (cVar7 != '\n') break;
            cVar7 = __s1[2];
            __s1 = __s1 + 2;
            pcVar30 = __s1;
          } while (cVar7 == '\n');
        }
        else {
          do {
            pcVar30 = pcVar30 + 1;
            bVar34 = cVar7 == '/';
            cVar7 = *pcVar30;
            if (bVar34) {
              __s1 = pcVar30;
            }
          } while ((cVar7 != '\n') && (cVar7 != '\0'));
          if (((sVar15 == (long)pcVar30 - (long)__s1) ||
              ((sVar15 < (ulong)((long)pcVar30 - (long)__s1) && (sVar15 == 0xf)))) &&
             (iVar10 = strncmp(__s1,__s,sVar15), iVar10 == 0)) goto LAB_0012515f;
          __s1 = pcVar30;
          if (cVar7 != '\0') goto LAB_00124ca6;
          cVar7 = *pcVar30;
        }
        goto LAB_00124c40;
      }
    }
    (*(int *)(__fp - 0x98)) = 0;
    iVar10 = 0;
    bVar2 = bVar22;
  }
LAB_00124d54:
  if (*__s1_00 != '/') {
    bVar33 = (byte)((uint)-iVar29 >> 0x1f);
LAB_00124da0:
    if (iVar29 <= iVar31) goto LAB_00124df0;
LAB_00124da6:
    iVar12 = strncmp(__s1_00 + iVar31,pcVar19 + (*(long *)(__fp - 0x90)),(*(size_t *)(__fp - 0x80)));
    if (iVar12 == 0) {
      (*(int *)(__fp - 0xb8)) = iVar31 + iVar9;
      if (((byte)__s1_00[(*(int *)(__fp - 0xb8))] < 0x21) &&
         ((0x100000401U >> ((ulong)(byte)__s1_00[(*(int *)(__fp - 0xb8))] & 0x3f) & 1) != 0)) {
        lVar32 = (long)(iVar29 + -1);
        iVar12 = iVar31 + -1;
        bVar23 = bVar33;
        if ((-iVar31 < 0) && (-iVar29 < 0)) {
          lVar24 = (long)(iVar29 + -2);
          do {
            if (__s1_00[lVar24 + 1 + (iVar31 - (*(long *)(__fp - 0x90)))] != pcVar19[lVar24 + 1]) goto LAB_00124df0;
            iVar13 = (int)lVar24;
            lVar32 = (long)iVar13;
            bVar23 = (byte)~(byte)((ulong)lVar24 >> 0x18) >> 7;
            iVar12 = iVar12 + -1;
            if (iVar12 < 0) goto LAB_001250ae;
            lVar24 = lVar24 + -1;
          } while (-1 < iVar13);
        }
        if (iVar12 < 0) {
LAB_001250ae:
          if ((bVar23 != 0) && (pcVar19[lVar32] == '/')) goto LAB_001250d7;
        }
      }
    }
LAB_00124df0:
    iVar31 = iVar31 + -2;
    if (0 < iVar31) goto code_r0x00124df9;
    goto LAB_00124e57;
  }
  iVar31 = strncmp(__s1_00,pcVar19,(long)(*(int *)(__fp - 0xb8)));
  if (((iVar31 == 0) && ((byte)__s1_00[(*(int *)(__fp - 0xb8))] < 0x21)) &&
     ((0x100000401U >> ((ulong)(byte)__s1_00[(*(int *)(__fp - 0xb8))] & 0x3f) & 1) != 0)) {
LAB_001250d7:
    bVar8 = (*(int *)(__fp - 0xb8)) != 0 & bVar8;
    bVar34 = bVar35 == 0;
    bVar35 = bVar8;
    if (bVar34) {
LAB_00124e72:
      bVar8 = bVar35;
      if (bVar22 != 0) goto LAB_00124e7c;
    }
    if (bVar8 == 0) {
LAB_00125124:
      lVar32 = 0;
      lVar24 = (long)(iVar14 + -1);
      goto LAB_00124f73;
    }
    lVar24 = 0;
    (*(int *)(__fp - 0x98)) = (*(int *)(__fp - 0x98)) - (*(int *)(__fp - 0xb8));
    iVar10 = iVar10 - (*(int *)(__fp - 0xb8));
    __s1_00 = __s1_00 + (*(int *)(__fp - 0xb8));
  }
  else {
    if ((bVar35 != 0) || ((*(int *)(__fp - 0xb8)) = 0, bVar22 == 0)) goto LAB_00125124;
LAB_00124e7c:
    uVar21 = *(ulong *)(param_1 + 0x120);
    if (uVar21 < 8) {
      lVar32 = param_1 + uVar21 * 0x18;
      *(undefined8 *)(lVar32 + 0x130) = 1;
      *(long *)(lVar32 + 0x128) = (long)pcVar17 - (long)pcVar16;
      uVar4 = *(undefined4 *)(lVar25 + 0x14);
      *(undefined4 *)(lVar32 + 0x13c) = 1;
      *(undefined4 *)(lVar32 + 0x138) = uVar4;
      *(ulong *)(param_1 + 0x120) = uVar21 + 1;
    }
    pcVar19 = stpcpy(pcVar17,pcVar26);
    uVar21 = *(ulong *)(param_1 + 0x120);
    lVar32 = (long)(iVar14 + -1);
    if (uVar21 < 8) {
      lVar24 = param_1 + uVar21 * 0x18;
      *(char **)(lVar24 + 0x128) = pcVar19 + (-lVar32 - (long)pcVar16);
      sVar15 = strlen(__s);
      *(size_t *)(lVar24 + 0x130) = sVar15;
      *(undefined4 *)(lVar24 + 0x13c) = 4;
      *(undefined4 *)(lVar24 + 0x138) = (*(undefined4 *)(__fp - 0x94));
      *(ulong *)(param_1 + 0x120) = uVar21 + 1;
    }
    pcVar17 = stpcpy(pcVar19,__s);
    if (bVar35 == 0) {
      lVar24 = lVar32 * 2;
      bVar2 = 1;
    }
    else {
      __s1_00 = __s1_00 + (*(int *)(__fp - 0xb8));
      if (*__s1_00 == '\0') {
        return;
      }
      (*(int *)(__fp - 0x98)) = (*(int *)(__fp - 0x98)) - (*(int *)(__fp - 0xb8));
      lVar24 = lVar32 * 2;
      iVar10 = iVar10 - (*(int *)(__fp - 0xb8));
      bVar2 = bVar35;
    }
LAB_00124f73:
    uVar21 = *(ulong *)(param_1 + 0x120);
    if (uVar21 < 8) {
      lVar27 = param_1 + uVar21 * 0x18;
      *(undefined8 *)(lVar27 + 0x130) = 1;
      *(char **)(lVar27 + 0x128) = pcVar17 + (-lVar32 - (long)pcVar16);
      uVar4 = *(undefined4 *)(lVar25 + 0x14);
      *(undefined4 *)(lVar27 + 0x13c) = 1;
      *(undefined4 *)(lVar27 + 0x138) = uVar4;
      *(ulong *)(param_1 + 0x120) = uVar21 + 1;
    }
    pcVar17 = stpcpy(pcVar17,pcVar26);
  }
  if ((cVar3 == '\0') || (*__s1_00 != '/')) {
LAB_00124fef:
    if (bVar2 == 0) goto LAB_00125356;
  }
  else {
    cVar7 = __s1_00[1];
    if (cVar7 == 's') {
      iVar14 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x1807) /* "/sbin/" */),6);
      if ((iVar14 != 0) || (uVar21 = *(ulong *)(param_1 + 0x120), 7 < uVar21)) goto LAB_0012534c;
      lVar32 = param_1 + uVar21 * 0x18;
      *(undefined8 *)(lVar32 + 0x130) = 6;
      *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
LAB_00125873:
      uVar4 = *(undefined4 *)(lVar25 + 0x78);
      *(undefined4 *)(lVar32 + 0x13c) = 0x10;
      *(undefined4 *)(lVar32 + 0x138) = uVar4;
      *(ulong *)(param_1 + 0x120) = uVar21 + 1;
      goto LAB_00124fef;
    }
    if (cVar7 < 't') {
      if (cVar7 == 'b') {
        iVar14 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17e7) /* "/bin/" */),5);
        if (iVar14 == 0) {
LAB_0012583a:
          uVar21 = *(ulong *)(param_1 + 0x120);
          if (uVar21 < 8) {
            lVar32 = param_1 + uVar21 * 0x18;
            *(undefined8 *)(lVar32 + 0x130) = 5;
            *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
            goto LAB_00125873;
          }
        }
      }
      else if (cVar7 == 'l') {
        iVar14 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17f7) /* "/lib/" */),5);
        if (iVar14 == 0) goto LAB_0012583a;
        iVar14 = strncmp(__s1_00,((char *)(long)(__sec_rodata + 0x17bc) /* "/lib32/" */),7);
        if ((iVar14 == 0) || (iVar14 = strncmp(__s1_00,((char *)(long)&s__lib64__001487c8 /* "/lib64/" */),7), iVar14 == 0)) {
          uVar21 = *(ulong *)(param_1 + 0x120);
          if (uVar21 < 8) {
            lVar32 = uVar21 * 0x18 + param_1;
            *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
            *(undefined8 *)(lVar32 + 0x130) = 7;
            goto LAB_00125531;
          }
        }
        else {
          uVar20 = FUN_00116180(__s1_00,((char *)(long)(__sec_rodata + 0x17d4) /* "/libx32/" */));
          if (((char)uVar20 != '\0') && (uVar21 = *(ulong *)(param_1 + 0x120), uVar21 < 8)) {
            lVar32 = uVar21 * 0x18 + param_1;
            *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
            *(undefined8 *)(lVar32 + 0x130) = 8;
LAB_00125531:
            uVar4 = *(undefined4 *)(lVar25 + 0x78);
            *(undefined4 *)(lVar32 + 0x13c) = 0x10;
            *(undefined4 *)(lVar32 + 0x138) = uVar4;
            *(ulong *)(param_1 + 0x120) = uVar21 + 1;
            goto LAB_00124fef;
          }
        }
      }
    }
    else if ((cVar7 == 'u') && (iVar14 = strncmp(__s1_00,((char *)(long)&s__usr__00148790 /* "/usr/" */),5), iVar14 == 0)) {
      cVar7 = __s1_00[5];
      if (cVar7 == 'l') {
        uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_libexec__001487a0 /* "/usr/libexec/" */));
        if ((char)uVar20 == '\0') {
          uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_lib__001487ae /* "/usr/lib/" */));
          if ((char)uVar20 != '\0') goto LAB_001257d2;
          uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_lib32__001487b8 /* "/usr/lib32/" */));
          if (((char)uVar20 == '\0') &&
             (uVar20 = FUN_00116180(__s1_00,((char *)(long)&DAT_001487c4 /* "/usr/lib64/" */)), (char)uVar20 == '\0')) {
            uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_libx32__001487d0 /* "/usr/libx32/" */));
            if ((char)uVar20 == '\0') {
              uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_local_bin__001487dd /* "/usr/local/bin/" */));
              if (((char)uVar20 == '\0') &&
                 (uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_local_lib__001487ed /* "/usr/local/lib/" */)), (char)uVar20 == '\0')) {
                uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_local_sbin__001487fd /* "/usr/local/sbin/" */));
                if (((char)uVar20 != '\0') && (uVar21 = *(ulong *)(param_1 + 0x120), uVar21 < 8)) {
                  lVar32 = uVar21 * 0x18 + param_1;
                  *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
                  *(undefined8 *)(lVar32 + 0x130) = 0x10;
                  goto LAB_00125531;
                }
              }
              else {
                uVar21 = *(ulong *)(param_1 + 0x120);
                if (uVar21 < 8) {
                  lVar32 = uVar21 * 0x18 + param_1;
                  *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
                  *(undefined8 *)(lVar32 + 0x130) = 0xf;
                  goto LAB_00125531;
                }
              }
            }
            else {
              uVar21 = *(ulong *)(param_1 + 0x120);
              if (uVar21 < 8) {
                lVar32 = uVar21 * 0x18 + param_1;
                *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
                *(undefined8 *)(lVar32 + 0x130) = 0xc;
                goto LAB_00125531;
              }
            }
          }
          else {
            uVar21 = *(ulong *)(param_1 + 0x120);
            if (uVar21 < 8) {
              lVar32 = uVar21 * 0x18 + param_1;
              *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
              *(undefined8 *)(lVar32 + 0x130) = 0xb;
              goto LAB_00125531;
            }
          }
        }
        else {
          uVar21 = *(ulong *)(param_1 + 0x120);
          if (uVar21 < 8) {
            lVar32 = uVar21 * 0x18 + param_1;
            *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
            *(undefined8 *)(lVar32 + 0x130) = 0xd;
            goto LAB_00125531;
          }
        }
      }
      else if (cVar7 == 's') {
        uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_sbin__0014880e /* "/usr/sbin/" */));
        if (((char)uVar20 != '\0') && (uVar21 = *(ulong *)(param_1 + 0x120), uVar21 < 8)) {
          lVar32 = uVar21 * 0x18 + param_1;
          *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
          *(undefined8 *)(lVar32 + 0x130) = 10;
          goto LAB_00125531;
        }
      }
      else if ((cVar7 == 'b') && (uVar20 = FUN_00116180(__s1_00,((char *)(long)&s__usr_bin__00148796 /* "/usr/bin/" */)), (char)uVar20 != '\0'))
      {
LAB_001257d2:
        uVar21 = *(ulong *)(param_1 + 0x120);
        if (uVar21 < 8) {
          lVar32 = uVar21 * 0x18 + param_1;
          *(char **)(lVar32 + 0x128) = pcVar17 + (-lVar24 - (long)pcVar16);
          *(undefined8 *)(lVar32 + 0x130) = 9;
          goto LAB_00125531;
        }
      }
    }
LAB_0012534c:
    cVar7 = '/';
    if (bVar2 != 0) goto LAB_00125007;
LAB_00125356:
    if ((bVar22 != 0) && (uVar21 = *(ulong *)(param_1 + 0x120), uVar21 < 8)) {
      lVar25 = param_1 + uVar21 * 0x18;
      *(undefined4 *)(lVar25 + 0x13c) = 4;
      *(char **)(lVar25 + 0x128) = pcVar17 + (((long)(*(int *)(__fp - 0x98)) - (long)pcVar16) - lVar24);
      *(long *)(lVar25 + 0x130) = (long)(iVar10 - (*(int *)(__fp - 0x98)));
      *(undefined4 *)(lVar25 + 0x138) = (*(undefined4 *)(__fp - 0x94));
      *(ulong *)(param_1 + 0x120) = uVar21 + 1;
    }
  }
  cVar7 = *__s1_00;
  if (cVar7 == '\0') {
    return;
  }
LAB_00125007:
  do {
    if (cVar7 == '\n') {
      cVar7 = ' ';
    }
    __s1_00 = __s1_00 + 1;
    pcVar26 = pcVar17 + 1;
    *pcVar17 = cVar7;
    cVar7 = *__s1_00;
    pcVar17 = pcVar26;
  } while (cVar7 != '\0');
  *pcVar26 = '\0';
  return;
code_r0x00124df9:
  pcVar30 = __s1_00 + iVar31;
  while( true ) {
    cVar7 = *pcVar30;
    pcVar30 = pcVar30 + -1;
    iVar31 = iVar31 + -1;
    if (iVar31 == 0) break;
    if (cVar7 == ' ' || cVar7 == '\n') goto LAB_00124e36;
  }
  if ((cVar7 != ' ' && cVar7 != '\n') || (iVar29 < 1)) {
LAB_00124e57:
    if (bVar35 != 0) goto LAB_00125124;
    (*(int *)(__fp - 0xb8)) = 0;
    goto LAB_00124e72;
  }
  goto LAB_00124da6;
  while( true ) {
    pcVar30 = pcVar30 + -1;
    iVar31 = iVar31 + -1;
    if (iVar31 == 0) break;
LAB_00124e36:
    if (pcVar30[-1] == '/') break;
  }
  goto LAB_00124da0;
}


/* Process_updateComm @ 0x126290 */

void Process_updateComm(long param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = *(char **)(param_1 + 0x90);
  if (pcVar2 == (char *)0x0) {
    if (param_2 == (char *)0x0) {
      return;
    }
  }
  else {
    if (param_2 == (char *)0x0) {
      free(pcVar2);
      pcVar2 = (char *)0x0;
      goto LAB_001262dc;
    }
    iVar1 = strcmp(pcVar2,param_2);
    if (iVar1 == 0) {
      return;
    }
    free(pcVar2);
  }
  pcVar2 = strdup(param_2);
  if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
LAB_001262dc:
  *(char **)(param_1 + 0x90) = pcVar2;
  *(undefined8 *)(param_1 + 0x110) = 0;
  return;
}


/* Process_updateCmdline @ 0x126320 */

void Process_updateCmdline(long param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;

  pcVar4 = *(char **)(param_1 + 0x80);
  if (pcVar4 == (char *)0x0) {
    if (param_2 == (char *)0x0) {
      return;
    }
LAB_00126372:
    pcVar4 = strdup(param_2);
    if (pcVar4 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    *(char **)(param_1 + 0x80) = pcVar4;
    if (*(char *)(param_1 + 0x4c) == '\0') {
      if (((param_3 == 0) && (*param_2 == '/')) && (1 < param_4)) {
        iVar3 = 2;
        do {
          cVar1 = param_2[1];
          if (cVar1 == '/') {
            if (param_2[2] != '\0') {
              param_3 = iVar3;
            }
          }
          else if (cVar1 == ' ') {
            if (*param_2 != '\\') break;
          }
          else if ((cVar1 == ':') && (param_2[2] == ' ')) break;
          param_2 = param_2 + 1;
          bVar2 = iVar3 < param_4;
          iVar3 = iVar3 + 1;
        } while (bVar2);
      }
      goto LAB_001263e0;
    }
  }
  else {
    if (param_2 != (char *)0x0) {
      iVar3 = strcmp(pcVar4,param_2);
      if (iVar3 == 0) {
        return;
      }
      free(pcVar4);
      goto LAB_00126372;
    }
    free(pcVar4);
    *(undefined8 *)(param_1 + 0x80) = 0;
    if (*(char *)(param_1 + 0x4c) == '\0') goto LAB_001263e0;
  }
  param_3 = 0;
  param_4 = 0;
LAB_001263e0:
  *(int *)(param_1 + 0x8c) = param_3;
  *(int *)(param_1 + 0x88) = param_4;
  *(undefined8 *)(param_1 + 0x110) = 0;
  return;
}


/* Process_updateExe @ 0x126480 */

void Process_updateExe(long param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = *(char **)(param_1 + 0x98);
  if (pcVar2 == (char *)0x0) {
    if (param_2 == (char *)0x0) {
      return;
    }
  }
  else {
    if (param_2 == (char *)0x0) {
      free(pcVar2);
      iVar1 = 0;
      *(undefined8 *)(param_1 + 0x98) = 0;
      goto LAB_00126515;
    }
    iVar1 = strcmp(pcVar2,param_2);
    if (iVar1 == 0) {
      return;
    }
    free(pcVar2);
  }
  pcVar2 = strdup(param_2);
  if (pcVar2 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  *(char **)(param_1 + 0x98) = pcVar2;
  pcVar2 = strrchr(param_2,0x2f);
  iVar1 = 0;
  if (pcVar2 != (char *)0x0) {
    if ((pcVar2[1] == '\0') || (param_2 == pcVar2)) {
      iVar1 = 0;
    }
    else {
      iVar1 = ((int)pcVar2 - (int)param_2) + 1;
    }
  }
LAB_00126515:
  *(int *)(param_1 + 0xa8) = iVar1;
  *(undefined8 *)(param_1 + 0x110) = 0;
  return;
}


/* Process_rowMatchesFilter @ 0x128410 */

undefined8 Process_rowMatchesFilter(long param_1,long param_2)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  int iVar1;
  long lVar2;
  ulong *puVar3;
  uint *puVar4;
  undefined8 uVar5;
  char *pcVar6;
  char **__ptr;
  char *pcVar7;
  uint *puVar8;
  ulong uVar9;
  ulong uVar10;
  char *__haystack;
  char **ppcVar11;
  long lVar12;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = *(long *)(param_2 + 0x20);
  iVar1 = *(int *)(lVar2 + 0x90);
  if ((iVar1 == -1) || (iVar1 == *(int *)(param_1 + 0x60))) {
    pcVar7 = *(char **)(param_2 + 0x28);
    if (pcVar7 == (char *)0x0) {
LAB_00128538:
      puVar3 = *(ulong **)(*(long *)(lVar2 + 0xa8) + 0x40);
      uVar5 = 0;
      if (puVar3 == (ulong *)0x0) goto LAB_00128452;
      puVar4 = (uint *)puVar3[1];
      uVar10 = (ulong)*(uint *)(param_1 + 0x14) % *puVar3;
      puVar8 = puVar4 + uVar10 * 6;
      if (*(long *)(puVar8 + 4) != 0) {
        uVar9 = 0;
        do {
          if (*(uint *)(param_1 + 0x14) == *puVar8) {
            uVar5 = 0;
            goto LAB_00128452;
          }
          if (*(ulong *)(puVar8 + 2) < uVar9) break;
          uVar10 = uVar10 + 1;
          if (*puVar3 == uVar10) {
            uVar10 = 0;
            puVar8 = puVar4;
          }
          else {
            puVar8 = puVar4 + uVar10 * 6;
          }
          uVar9 = uVar9 + 1;
        } while (*(long *)(puVar8 + 4) != 0);
      }
    }
    else {
      if (((*(char *)(param_1 + 0x4d) != '\0') &&
          (*(char *)(**(long **)(param_1 + 8) + 0x58) != '\0')) ||
         (__haystack = *(char **)(param_1 + 0x118), __haystack == (char *)0x0)) {
        __haystack = *(char **)(param_1 + 0x80);
      }
      pcVar6 = strchr(pcVar7,0x7c);
      if (pcVar6 == (char *)0x0) {
        pcVar7 = strcasestr(__haystack,pcVar7);
        if (pcVar7 != (char *)0x0) goto LAB_00128538;
      }
      else {
        __ptr = String_split(pcVar7,'|',&(*(long *)(__fp - 0x48)));
        if ((*(long *)(__fp - 0x48)) != 0) {
          lVar12 = 0;
LAB_001284f5:
          pcVar7 = strcasestr(__haystack,__ptr[lVar12]);
          if (pcVar7 == (char *)0x0) goto LAB_001284e8;
          pcVar7 = *__ptr;
          ppcVar11 = __ptr;
          while (pcVar7 != (char *)0x0) {
            ppcVar11 = ppcVar11 + 1;
            free(pcVar7);
            pcVar7 = *ppcVar11;
          }
          free(__ptr);
          goto LAB_00128538;
        }
        if (__ptr != (char **)0x0) {
LAB_00128608:
          pcVar7 = *__ptr;
          ppcVar11 = __ptr;
          while (pcVar7 != (char *)0x0) {
            ppcVar11 = ppcVar11 + 1;
            free(pcVar7);
            pcVar7 = *ppcVar11;
          }
          free(__ptr);
          uVar5 = 1;
          goto LAB_00128452;
        }
      }
    }
  }
  uVar5 = 1;
LAB_00128452:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
LAB_001284e8:
  lVar12 = lVar12 + 1;
  if (lVar12 == (*(long *)(__fp - 0x48))) goto LAB_00128608;
  goto LAB_001284f5;
}


/* Process_writeField @ 0x12c3e0 */

void Process_writeField(long param_1,int *param_2,undefined4 param_3)

{
  undefined1 __frame[0x1d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x198;
  char cVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  ulong uVar8;
  char *pcVar9;
  ulong uVar10;
  int va1;
  uint uVar11;
  void *va1_00;
  undefined4 uVar12;
  ulong uVar13;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar4 = CRT_colors;
  plVar2 = *(long **)(param_1 + 8);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = *plVar2;
  cVar1 = *(char *)(lVar3 + 0x5f);
  (*(undefined1 *)(__fp - 0x49)) = 0;
  uVar6 = *(uint *)(CRT_colors + 4);
  iVar5 = Row_pidDigits;
  (*(uint *)(__fp - 0x14c)) = uVar6;
  switch(param_3) {
  default:
    pcVar9 = ((char *)(long)&DAT_00147411 /* "- " */);
    goto LAB_0012c45e;
  case 1:
    va1 = *(int *)(param_1 + 0x10);
    goto LAB_0012c688;
  case 2:
    uVar12 = *(undefined4 *)(CRT_colors + 0x94);
    if ((*(char *)(lVar3 + 0x60) != '\0') &&
       ((*(char *)(param_1 + 0x4d) != '\0' || (*(char *)(param_1 + 0x4c) != '\0')))) {
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0xa8);
      uVar12 = *(undefined4 *)(CRT_colors + 0xac);
    }
    if ((*(char *)(*(long *)(lVar3 + 0x40) + 0x34) == '\0') ||
       (uVar6 = *(uint *)(param_1 + 0x24), uVar6 == 0)) {
      Process_writeCommand(param_1,(*(uint *)(__fp - 0x14c)),uVar12,param_2);
    }
    else {
      uVar10 = 0xff;
      uVar11 = -uVar6;
      if ((int)-uVar6 < 0) {
        uVar11 = uVar6;
      }
      pcVar9 = (*(char (*)[255])(__fp - 0x148));
      if (uVar11 != 1) {
        uVar13 = (ulong)uVar11;
        do {
          if ((uVar13 & 1) == 0) {
            iVar5 = xSnprintf(pcVar9,uVar10,((char *)(long)&DAT_001470db /* "   " */));
          }
          else {
            iVar5 = xSnprintf(pcVar9,uVar10,((char *)(long)&DAT_00148979 /* "%s  " */),*(void **)CRT_treeStr);
          }
          if ((iVar5 < 0) || (uVar8 = (ulong)iVar5, uVar10 <= uVar8)) {
            uVar8 = (ulong)(int)uVar10;
          }
          uVar13 = uVar13 >> 1;
          pcVar9 = pcVar9 + uVar8;
          uVar10 = uVar10 - uVar8;
        } while ((int)uVar13 != 1);
      }
      if (*(char *)(param_1 + 0x20) == '\0') {
        va1_00 = *(void **)(CRT_treeStr + 0x20);
      }
      else {
        va1_00 = *(void **)(CRT_treeStr + 0x28);
      }
      xSnprintf(pcVar9,uVar10,((char *)(long)&s__s_s_0014897e /* "%s%s " */),*(void **)(CRT_treeStr + (ulong)(uVar6 >> 0x1c & 8) + 8),
                va1_00);
      RichString_appendWide(param_2,*(uint *)(CRT_colors + 0x88),(*(char (*)[255])(__fp - 0x148)));
      Process_writeCommand(param_1,(*(uint *)(__fp - 0x14c)),uVar12,param_2);
    }
    goto LAB_0012c483;
  case 3:
    iVar5 = 0x21;
    uVar6 = *(int *)(param_1 + 0x108) - 1;
    if (uVar6 < 0xe) {
      iVar5 = (int)((char *)(long)&s__URQWDBPTtZXIS_0014db18 /* "?URQWDBPTtZXIS" */)[uVar6];
    }
    xSnprintf((*(char (*)[255])(__fp - 0x148)),0xff,((char *)(long)&DAT_00149088 /* "%c " */),iVar5);
    if (*(uint *)(param_1 + 0x108) < 0xf) {
      uVar10 = 1L << ((byte)*(uint *)(param_1 + 0x108) & 0x3f);
      if ((uVar10 & 0x1ac0) == 0) {
        if ((uVar10 & 0x6030) == 0) {
          if ((uVar10 & 0x40c) != 0) {
            (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x8c);
          }
        }
        else {
          (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x78);
        }
      }
      else {
        (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x90);
      }
    }
    break;
  case 4:
    va1 = *(int *)(param_1 + 0x18);
    goto LAB_0012c688;
  case 5:
    va1 = *(int *)(param_1 + 0x40);
    goto LAB_0012c688;
  case 6:
    va1 = *(int *)(param_1 + 0x44);
    goto LAB_0012c688;
  case 7:
    pcVar9 = *(char **)(param_1 + 0x58);
    if (pcVar9 != (char *)0x0) {
      iVar5 = strncmp(pcVar9,((char *)(long)&s__dev__001489c1 /* "/dev/" */),5);
      pcVar7 = ((char *)(long)&s___8s_001489c7 /* "%-8s " */);
      if (iVar5 == 0) {
        pcVar9 = pcVar9 + 5;
      }
      goto LAB_0012c5be;
    }
    (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x78);
    pcVar9 = ((char *)(long)&s__no_tty__001489b7 /* "(no tty) " */);
    goto LAB_0012c45e;
  case 8:
    va1 = *(int *)(param_1 + 0x48);
    goto LAB_0012c688;
  case 10:
    Row_printCount(param_2,*(ulong *)(param_1 + 0xf8),cVar1);
    goto LAB_0012c483;
  case 0xc:
    Row_printCount(param_2,*(ulong *)(param_1 + 0x100),cVar1);
    goto LAB_0012c483;
  case 0x12:
    pcVar9 = ((char *)(long)&DAT_001489a7 /* " RT " */);
    if (-100 < (long)*(char **)(param_1 + 0xc0)) {
      pcVar7 = ((char *)(long)&s__3ld_00148996 /* "%3ld " */);
      pcVar9 = *(char **)(param_1 + 0xc0);
      goto LAB_0012c5be;
    }
LAB_0012c45e:
    xSnprintf((*(char (*)[255])(__fp - 0x148)),0xff,pcVar9);
    break;
  case 0x13:
    xSnprintf((*(char (*)[255])(__fp - 0x148)),0xff,((char *)(long)&s__3ld_00148996 /* "%3ld " */),*(long *)(param_1 + 200));
    if (*(long *)(param_1 + 200) < 0) {
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x98);
    }
    else if (*(long *)(param_1 + 200) == 0) {
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x78);
    }
    else {
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x9c);
    }
    break;
  case 0x15:
    pcVar7 = ((char *)(long)(__sec_rodata + 0x626) /* "%s" */);
    pcVar9 = (char *)(param_1 + 0xe0);
    goto LAB_0012c5be;
  case 0x26:
    pcVar9 = ((char *)(long)&DAT_001489ac /* "%3d " */);
    iVar5 = (*(int *)(param_1 + 0xb0) + 1) - (uint)(*(char *)(lVar3 + 0x50) == '\0');
    goto LAB_0012c7f6;
  case 0x27:
    Row_printKBytes(param_2,*(ulong *)(param_1 + 0xe8),cVar1);
    goto LAB_0012c483;
  case 0x28:
    Row_printKBytes(param_2,*(ulong *)(param_1 + 0xf0),cVar1);
    goto LAB_0012c483;
  case 0x2e:
    va1 = *(int *)(param_1 + 0x60);
    iVar5 = Row_uidDigits;
    goto LAB_0012c688;
  case 0x2f:
    Row_printPercentage(*(float *)(param_1 + 0xb4),(*(char (*)[255])(__fp - 0x148)),0xff,BYTE_0015d48f,&(*(uint *)(__fp - 0x14c)));
    break;
  case 0x30:
    Row_printPercentage(*(float *)(param_1 + 0xb8),(*(char (*)[255])(__fp - 0x148)),0xff,4,&(*(uint *)(__fp - 0x14c)));
    break;
  case 0x31:
    if (*(char *)(param_1 + 0x70) == '\0') {
      if ((int)plVar2[0x11] != *(int *)(param_1 + 0x60)) {
        (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x78);
      }
    }
    else {
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0xb8);
    }
    if (*(char **)(param_1 + 0x68) != (char *)0x0) {
      Row_printLeftAlignedField(param_2,(*(uint *)(__fp - 0x14c)),*(char **)(param_1 + 0x68),10);
      goto LAB_0012c483;
    }
    iVar5 = *(int *)(param_1 + 0x60);
    pcVar9 = ((char *)(long)&s___10d_001489cd /* "%-10d " */);
LAB_0012c7f6:
    xSnprintf((*(char (*)[255])(__fp - 0x148)),0xff,pcVar9,iVar5);
    break;
  case 0x32:
    Row_printTime(param_2,*(ulong *)(param_1 + 0x78),cVar1);
    goto LAB_0012c483;
  case 0x33:
    if (*(char **)(param_1 + 0xd0) == (char *)0x1) {
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x78);
    }
    pcVar7 = ((char *)(long)&s__4ld_0014899c /* "%4ld " */);
    pcVar9 = *(char **)(param_1 + 0xd0);
    goto LAB_0012c5be;
  case 0x34:
    va1 = *(int *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x10) == va1) {
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x78);
    }
LAB_0012c688:
    xSnprintf((*(char (*)[255])(__fp - 0x148)),0xff,((char *)(long)&DAT_001489a2 /* "%*d " */),iVar5,va1);
    break;
  case 0x35:
    Row_printPercentage(*(float *)(param_1 + 0xb4) / (float)*(uint *)(plVar2 + 0xf),(*(char (*)[255])(__fp - 0x148)),0xff,
                        BYTE_0015d48f,&(*(uint *)(__fp - 0x14c)));
    break;
  case 0x36:
    uVar10 = 0;
    if ((ulong)(*(long *)(param_1 + 0xd8) * 1000) <= (ulong)plVar2[3]) {
      uVar10 = (ulong)(plVar2[3] + *(long *)(param_1 + 0xd8) * -1000) / 10;
    }
    Row_printTime(param_2,uVar10,cVar1);
    goto LAB_0012c483;
  case 0x37:
    pcVar9 = ((char *)(long)&DAT_001474de /* "N/A" */);
    if (-1 < (int)*(uint *)(param_1 + 0x10c)) {
      switch(*(uint *)(param_1 + 0x10c) & 0xbfffffff) {
      case 0:
        pcVar9 = ((char *)(long)&s_OTHER_0014895d /* "OTHER" */);
        break;
      case 1:
        pcVar9 = ((char *)(long)&DAT_00148958 /* "FIFO" */);
        break;
      case 2:
        pcVar9 = ((char *)(long)&DAT_00148976 /* "RR" */);
        break;
      case 3:
        pcVar9 = ((char *)(long)&s_BATCH_00148970 /* "BATCH" */);
        break;
      default:
        pcVar9 = ((char *)(long)&DAT_00148963 /* "???" */);
        break;
      case 5:
        pcVar9 = ((char *)(long)&DAT_0014896b /* "IDLE" */);
        break;
      case 6:
        pcVar9 = ((char *)(long)&DAT_00148967 /* "EDF" */);
      }
    }
    pcVar7 = ((char *)(long)&s___5s_001489b1 /* "%-5s " */);
LAB_0012c5be:
    xSnprintf((*(char (*)[255])(__fp - 0x148)),0xff,pcVar7,pcVar9);
    break;
  case 0x7c:
    pcVar9 = *(char **)(param_1 + 0x90);
    if (pcVar9 == (char *)0x0) {
LAB_0012cb10:
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x78);
      pcVar9 = ((char *)(long)&DAT_001474de /* "N/A" */);
      if (*(char *)(param_1 + 0x4c) != '\0') {
        pcVar9 = ((char *)(long)&s_KTHREAD_0014877d /* "KTHREAD" */);
      }
    }
    else {
      (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0xb4 +
                           (-(ulong)(*(char *)(param_1 + 0x4d) == '\0') & 0xfffffffffffffffc));
    }
    goto LAB_0012c55e;
  case 0x7d:
    if (*(long *)(param_1 + 0x98) == 0) goto LAB_0012cb10;
    (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0xac +
                         (-(ulong)(*(char *)(param_1 + 0x4d) == '\0') & 0xffffffffffffffe8));
    if (*(char *)(lVar3 + 0x5d) != '\0') {
      if (*(char *)(param_1 + 0xac) == '\0') {
        if (*(char *)(param_1 + 0xad) != '\0') {
          (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x7c);
        }
      }
      else {
        (*(uint *)(__fp - 0x14c)) = *(uint *)(CRT_colors + 0x14);
      }
    }
    pcVar9 = (char *)(*(long *)(param_1 + 0x98) + (long)*(int *)(param_1 + 0xa8));
LAB_0012c55e:
    Row_printLeftAlignedField(param_2,(*(uint *)(__fp - 0x14c)),pcVar9,0xf);
    goto LAB_0012c483;
  case 0x7e:
    pcVar9 = *(char **)(param_1 + 0xa0);
    if (pcVar9 == (char *)0x0) {
      uVar6 = *(uint *)(CRT_colors + 0x78);
      pcVar9 = ((char *)(long)&DAT_001474de /* "N/A" */);
      (*(uint *)(__fp - 0x14c)) = uVar6;
    }
    else {
      iVar5 = strncmp(pcVar9,((char *)(long)&s__proc__00148984 /* "/proc/" */),6);
      if ((iVar5 == 0) && (pcVar7 = strstr(pcVar9,((char *)(long)&s__deleted__0014898b /* " (deleted)" */)), pcVar7 != (char *)0x0)) {
        uVar6 = *(uint *)(lVar4 + 0x78);
        pcVar9 = ((char *)(long)&s_main_thread_terminated_00148941 /* "main thread terminated" */);
        (*(uint *)(__fp - 0x14c)) = uVar6;
      }
    }
    Row_printLeftAlignedField(param_2,uVar6,pcVar9,0x19);
    goto LAB_0012c483;
  }
  RichString_appendAscii(param_2,(*(uint *)(__fp - 0x14c)),(*(char (*)[255])(__fp - 0x148)));
LAB_0012c483:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0012cd60 @ 0x12cd60 */

void FUN_0012cd60(long param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0x2d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x298;
  uint uVar1;
  long *a0;
  undefined8 *puVar2;
  code *UNRECOVERED_JUMPTABLE;
  long lVar3;
  char *__ptr;
  char *va8;
  long extraout_RDX;
  long extraout_RDX_00;
  char *fmt;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long a2;
  int iVar4;
  undefined8 *__ptr_00;
  long in_FS_OFFSET = (long)__fake_fs;
  void *va3;
  long va4;
  long va5;
  long va6;
  char *pcVar5;

  a0 = *(long **)(param_1 + 0x10);
  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  lVar3 = a0[5];
  Vector_prune((long *)a0[4],param_rsi,param_rdx,param_rcx,param_r8,param_r9);
  a0[5] = 0;
  uVar1 = *(uint *)(param_1 + 0x28);
  *(undefined4 *)(a0 + 8) = 0;
  *(undefined1 *)(a0 + 9) = 1;
  __ptr = Platform_getProcessLocks(uVar1);
  if (__ptr == (char *)0x0) {
    pcVar5 = ((char *)(long)&s_This_feature_is_not_supported_on_0014c598 /* "This feature is not supported on your platform." */);
    InfoScreen_addLine(param_1,((char *)(long)&s_This_feature_is_not_supported_on_0014c598 /* "This feature is not supported on your platform." */),extraout_RDX,
                       param_rcx,param_r8,param_r9);
  }
  else if (*__ptr == '\0') {
    __ptr_00 = *(undefined8 **)(__ptr + 8);
    if (__ptr_00 == (undefined8 *)0x0) {
      pcVar5 = ((char *)(long)&s_No_locks_have_been_found_for_the_0014c5e8 /* "No locks have been found for the selected process." */);
      InfoScreen_addLine(param_1,((char *)(long)&s_No_locks_have_been_found_for_the_0014c5e8 /* "No locks have been found for the selected process." */),extraout_RDX,
                         param_rcx,param_r8,param_r9);
    }
    else {
      do {
        pcVar5 = (char *)__ptr_00[8];
        va8 = (char *)__ptr_00[3];
        if (pcVar5 == (char *)0xffffffffffffffff) {
          param_r9 = __ptr_00[1];
          param_r8 = *__ptr_00;
          if (va8 == (char *)0x0) {
            va8 = ((char *)(long)&s__N_A__001489d4 /* "<N/A>" */);
          }
          uVar1 = *(uint *)(__ptr_00 + 4);
          fmt = ((char *)(long)&s__5d___10s___10s___10s___6lx__10l_0014c620 /* "%5d %-10s %-10s %-10s %#6lx %10lu %19lu %19s  %s" */);
          pcVar5 = ((char *)(long)&s__END_OF_FILE__001489da /* "<END OF FILE>" */);
          va6 = __ptr_00[7];
          va5 = __ptr_00[6];
          va4 = __ptr_00[5];
          va3 = (void *)__ptr_00[2];
        }
        else {
          param_r9 = __ptr_00[1];
          param_r8 = *__ptr_00;
          if (va8 == (char *)0x0) {
            va8 = ((char *)(long)&s__N_A__001489d4 /* "<N/A>" */);
          }
          uVar1 = *(uint *)(__ptr_00 + 4);
          fmt = ((char *)(long)&s__5d___10s___10s___10s___6lx__10l_0014c658 /* "%5d %-10s %-10s %-10s %#6lx %10lu %19lu %19lu  %s" */);
          va6 = __ptr_00[7];
          va5 = __ptr_00[6];
          va4 = __ptr_00[5];
          va3 = (void *)__ptr_00[2];
        }
        param_rcx = (long)uVar1;
        xSnprintf((*(char (*)[520])(__fp - 0x248)),0x200,fmt,uVar1,(void *)param_r8,(void *)param_r9,va3,va4,va5,va6,
                  (long)pcVar5,va8);
        pcVar5 = (*(char (*)[520])(__fp - 0x248));
        InfoScreen_addLine(param_1,(*(char (*)[520])(__fp - 0x248)),extraout_RDX_00,param_rcx,param_r8,param_r9);
        free((void *)*__ptr_00);
        free((void *)__ptr_00[1]);
        free((void *)__ptr_00[2]);
        free((void *)__ptr_00[3]);
        puVar2 = (undefined8 *)__ptr_00[9];
        free(__ptr_00);
        __ptr_00 = puVar2;
      } while (puVar2 != (undefined8 *)0x0);
    }
  }
  else {
    pcVar5 = ((char *)(long)&s_Could_not_determine_file_locks__0014c5c8 /* "Could not determine file locks." */);
    InfoScreen_addLine(param_1,((char *)(long)&s_Could_not_determine_file_locks__0014c5c8 /* "Could not determine file locks." */),extraout_RDX,param_rcx,param_r8,
                       param_r9);
  }
  free(__ptr);
  Vector_insertionSort
            (*(long **)(param_1 + 0x20),(long)pcVar5,extraout_RDX_01,param_rcx,param_r8,param_r9);
  Vector_insertionSort((long *)a0[4],(long)pcVar5,extraout_RDX_02,param_rcx,param_r8,param_r9);
  iVar4 = (int)lVar3;
  if (*(int *)(a0[4] + 0x18) <= (int)lVar3) {
    iVar4 = *(int *)(a0[4] + 0x18) + -1;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*a0 + 0x20);
  *(int *)(a0 + 5) = iVar4;
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
  else if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Could not recover jumptable at 0x0012cf53. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)((long)a0,0xffffffff,a2,0,param_r8,param_r9);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Process_delete @ 0x138950 */

void Process_delete(void *param_1)

{
  free(*(void **)((long)param_1 + 0x80));
  free(*(void **)((long)param_1 + 0x90));
  free(*(void **)((long)param_1 + 0x98));
  free(*(void **)((long)param_1 + 0xa0));
  free(*(void **)((long)param_1 + 0x118));
  free(*(void **)((long)param_1 + 0x58));
  free(*(void **)((long)param_1 + 0x2d8));
  free(*(void **)((long)param_1 + 0x2d0));
  free(*(void **)((long)param_1 + 0x2c8));
  free(*(void **)((long)param_1 + 0x2b8));
  free(*(void **)((long)param_1 + 0x328));
  free(param_1);
  return;
}


/* FUN_001389f0 @ 0x1389f0 */

void FUN_001389f0(long *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  int iVar1;
  long a2;
  long *plVar2;
  char *a1;
  bool bVar3;

  a1 = ((char *)(long)&s_SystemdUser_001477b1 /* "SystemdUser" */);
  plVar2 = (long *)&DAT_0015d840;
  iVar1 = strcmp(*(char **)(*param_1 + 0x70),((char *)(long)&s_SystemdUser_001477b1 /* "SystemdUser" */));
  if (iVar1 == 0) {
    plVar2 = &DAT_0015d860;
  }
  free((void *)plVar2[1]);
  plVar2[1] = 0;
  if ((*plVar2 != 0) && (PTR_0015d830 != (void *)0x0)) {
    (*(code *)PTR_0015d828)(*plVar2,(long)a1,a2,param_rcx,param_r8,param_r9);
  }
  bVar3 = LONG_0015d848 == 0;
  *plVar2 = 0;
  if (((bVar3) && (LONG_0015d868 == 0)) && (PTR_0015d830 != (void *)0x0)) {
    dlclose(PTR_0015d830);
    PTR_0015d830 = (void *)0x0;
  }
  return;
}


/* FUN_00138a90 @ 0x138a90 */

void FUN_00138a90(long param_1)

{
  undefined1 __frame[0x10f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x10b8;
  long lVar1;
  int iVar2;
  FILE *__stream;
  char *pcVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(((char *)(long)&s__proc_cpuinfo_001496f6 /* "/proc/cpuinfo" */),((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream != (FILE *)0x0) {
    (*(uint *)(__fp - 0x1054)) = 0xffffffff;
    (*(double *)(__fp - 0x1060)) = 0.0;
    (*(int *)(__fp - 0x1064)) = 0;
LAB_00138b10:
    iVar2 = feof(__stream);
    if (iVar2 == 0) {
      while( true ) {
        pcVar3 = fgets((*(char (*)[4104])(__fp - 0x1048)),0x1000,__stream);
        if (pcVar3 == (char *)0x0) goto LAB_00138bc0;
        iVar2 = __isoc23_sscanf((*(char (*)[4104])(__fp - 0x1048)),((char *)(long)&s_processor____d_00149704 /* "processor : %d" */),&(*(uint *)(__fp - 0x1054)));
        if (iVar2 == 1) goto LAB_00138b10;
        iVar2 = __isoc23_sscanf((*(char (*)[4104])(__fp - 0x1048)),((char *)(long)&s_cpu_MHz____lf_00149713 /* "cpu MHz : %lf" */),&(*(double *)(__fp - 0x1050)));
        if ((iVar2 == 1) ||
           (iVar2 = __isoc23_sscanf((*(char (*)[4104])(__fp - 0x1048)),((char *)(long)&s_clock____lfMHz_00149721 /* "clock : %lfMHz" */),&(*(double *)(__fp - 0x1050))), iVar2 == 1)) break;
        if ((*(char (*)[4104])(__fp - 0x1048))[0] != '\n') goto LAB_00138b10;
        (*(uint *)(__fp - 0x1054)) = 0xffffffff;
        iVar2 = feof(__stream);
        if (iVar2 != 0) goto LAB_00138bc0;
      }
      if ((-1 < (int)(*(uint *)(__fp - 0x1054))) && ((*(uint *)(__fp - 0x1054)) <= *(int *)(param_1 + 0x7c) - 1U)) {
        lVar1 = *(long *)(param_1 + 0xe0) + ((long)(int)(*(uint *)(__fp - 0x1054)) * 3 + 3) * 0x48;
        if (*(double *)(lVar1 + 0xc0) < 0.0) {
          *(double *)(lVar1 + 0xc0) = (*(double *)(__fp - 0x1050));
        }
        (*(double *)(__fp - 0x1060)) = (*(double *)(__fp - 0x1050)) + (*(double *)(__fp - 0x1060));
        (*(int *)(__fp - 0x1064)) = (*(int *)(__fp - 0x1064)) + 1;
      }
      goto LAB_00138b10;
    }
LAB_00138bc0:
    fclose(__stream);
    if (0 < (*(int *)(__fp - 0x1064))) {
      *(double *)(*(long *)(param_1 + 0xe0) + 0xc0) = (*(double *)(__fp - 0x1060)) / (double)(*(int *)(__fp - 0x1064));
    }
  }
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* FUN_00138ca0 @ 0x138ca0 */

undefined8 FUN_00138ca0(long param_1,int param_2)

{
  undefined1 __frame[0x10f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x10b8;
  byte *pbVar1;
  ushort *puVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  FILE *__stream;
  char *pcVar6;
  ushort **ppuVar7;
  ulong uVar8;
  undefined8 uVar9;
  byte *pbVar10;
  long lVar11;
  long in_FS_OFFSET = (long)__fake_fs;
  bool bVar12;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined4 *)(param_1 + 0x2c4) = 0;
  iVar4 = openat(param_2,((char *)(long)&s_status_00149730 /* "status" */),0);
  if (-1 < iVar4) {
    __stream = fdopen(iVar4,((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream != (FILE *)0x0) {
      (*(ulong *)(__fp - 0x1068)) = 0;
LAB_00138d30:
      pcVar6 = fgets((char *)&(*(byte *)(__fp - 0x1048)),0x1001,__stream);
      bVar3 = (*(byte *)(__fp - 0x1048));
      if (pcVar6 != (char *)0x0) {
        if ((CONCAT13((*(undefined1 *)(__fp - 0x1045)),CONCAT21((*(undefined2 *)(__fp - 0x1047)),(*(byte *)(__fp - 0x1048)))) == 0x6970534e) &&
           (CONCAT11((*(undefined1 *)(__fp - 0x1043)),(*(char *)(__fp - 0x1044))) == 0x3a64)) {
          if (((*(byte *)(__fp - 0x1048)) != 0) && ((*(byte *)(__fp - 0x1048)) != 10)) {
            ppuVar7 = __ctype_b_loc();
            iVar4 = 0;
            puVar2 = *ppuVar7;
            pbVar10 = &(*(byte *)(__fp - 0x1048));
            while ((*(byte *)((long)puVar2 + (ulong)bVar3 * 2 + 1) & 8) == 0) {
              bVar3 = pbVar10[1];
              pbVar10 = pbVar10 + 1;
              if ((bVar3 == 0) || (bVar3 == 10)) goto LAB_00138d30;
            }
            bVar3 = *pbVar10;
            if ((bVar3 != 0) && (bVar3 != 10)) goto LAB_00138e80;
          }
        }
        else if ((CONCAT13((*(undefined1 *)(__fp - 0x1045)),CONCAT21((*(undefined2 *)(__fp - 0x1047)),(*(byte *)(__fp - 0x1048)))) == 0x50706143) &&
                (CONCAT13((*(undefined1 *)(__fp - 0x1042)),CONCAT12((*(undefined1 *)(__fp - 0x1043)),CONCAT11((*(char *)(__fp - 0x1044)),(*(undefined1 *)(__fp - 0x1045))))) ==
                 0x3a6d7250)) {
          if (((*(byte *)(__fp - 0x1041)) == 0x20) || ((*(byte *)(__fp - 0x1041)) == 9)) {
            pbVar10 = &(*(byte *)(__fp - 0x1041));
            do {
              do {
                pbVar1 = pbVar10 + 1;
                pbVar10 = pbVar10 + 1;
              } while (*pbVar1 == 0x20);
            } while (*pbVar1 == 9);
          }
          else {
            pbVar10 = &(*(byte *)(__fp - 0x1041));
          }
          pbVar1 = pbVar10 + 0x10;
          lVar11 = 0;
          do {
            bVar3 = *pbVar10;
            if ((((1 << (bVar3 & 0x1f) & 0x3ff007eU) == 0) || (bVar3 < 0x30)) ||
               (uVar5 = bVar3 & 0xffffffdf, 0x46 < uVar5)) break;
            pbVar10 = pbVar10 + 1;
            lVar11 = lVar11 * 0x10 + (ulong)(uVar5 - (-(uint)((bVar3 & 0x40) != 0) & 7) & 0xf);
          } while (pbVar10 != pbVar1);
          bVar12 = false;
          if (lVar11 != 0) {
            bVar12 = *(int *)(param_1 + 0x60) != 0;
          }
          *(bool *)(param_1 + 0x70) = bVar12;
        }
        else if ((CONCAT17((*(byte *)(__fp - 0x1041)),
                           CONCAT16((*(undefined1 *)(__fp - 0x1042)),
                                    CONCAT15((*(undefined1 *)(__fp - 0x1043)),
                                             CONCAT14((*(char *)(__fp - 0x1044)),
                                                      CONCAT13((*(undefined1 *)(__fp - 0x1045)),
                                                               CONCAT21((*(undefined2 *)(__fp - 0x1047)),(*(byte *)(__fp - 0x1048))))))))
                  == 0x7261746e756c6f76 && CONCAT53((*(undefined5 *)(__fp - 0x103d)),(*(undefined3 *)(__fp - 0x1040))) == 0x735f747874635f79)
                && (CONCAT53((*(undefined5 *)(__fp - 0x1035)),(*(undefined3 *)(__fp - 0x1038))) == 0x3a73656863746977)) {
          iVar4 = __isoc23_sscanf((char *)&(*(byte *)(__fp - 0x1048)),((char *)(long)&s_voluntary_ctxt_switches___lu_00149746 /* "voluntary_ctxt_switches:\t%lu" */),&(*(undefined4 *)(__fp - 0x1050)));
joined_r0x0013909e:
          if (0 < iVar4) {
            (*(ulong *)(__fp - 0x1068)) = (*(ulong *)(__fp - 0x1068)) + CONCAT44((*(undefined4 *)(__fp - 0x104c)),(*(undefined4 *)(__fp - 0x1050)));
          }
        }
        else {
          if ((CONCAT17((*(byte *)(__fp - 0x1041)),
                        CONCAT16((*(undefined1 *)(__fp - 0x1042)),
                                 CONCAT15((*(undefined1 *)(__fp - 0x1043)),
                                          CONCAT14((*(char *)(__fp - 0x1044)),
                                                   CONCAT13((*(undefined1 *)(__fp - 0x1045)),
                                                            CONCAT21((*(undefined2 *)(__fp - 0x1047)),(*(byte *)(__fp - 0x1048)))))))) ==
               0x6e756c6f766e6f6e && CONCAT53((*(undefined5 *)(__fp - 0x103d)),(*(undefined3 *)(__fp - 0x1040))) == 0x7874635f79726174) &&
             (CONCAT35((*(undefined3 *)(__fp - 0x1038)),(*(undefined5 *)(__fp - 0x103d))) == 0x735f747874635f79 &&
              CONCAT35((*(undefined3 *)(__fp - 0x1030)),(*(undefined5 *)(__fp - 0x1035))) == 0x3a73656863746977)) {
            iVar4 = __isoc23_sscanf((char *)&(*(byte *)(__fp - 0x1048)),((char *)(long)&s_nonvoluntary_ctxt_switches___lu_0014ca10 /* "nonvoluntary_ctxt_switches:\t%lu" */),
                                    &(*(undefined4 *)(__fp - 0x1050)));
            goto joined_r0x0013909e;
          }
          if (((CONCAT13((*(undefined1 *)(__fp - 0x1045)),CONCAT21((*(undefined2 *)(__fp - 0x1047)),(*(byte *)(__fp - 0x1048)))) == 0x44497856) &&
              ((*(char *)(__fp - 0x1044)) == ':')) &&
             (iVar4 = __isoc23_sscanf((char *)&(*(byte *)(__fp - 0x1048)),((char *)(long)&DAT_00149785 /* "VxID:\t%32d" */),&(*(undefined4 *)(__fp - 0x1050))), 0 < iVar4)) {
            *(undefined4 *)(param_1 + 0x2c4) = (*(undefined4 *)(__fp - 0x1050));
          }
        }
        goto LAB_00138d30;
      }
      fclose(__stream);
      uVar8 = *(ulong *)(param_1 + 0x318);
      *(ulong *)(param_1 + 0x318) = (*(ulong *)(__fp - 0x1068));
      lVar11 = (*(ulong *)(__fp - 0x1068)) - uVar8;
      if ((*(ulong *)(__fp - 0x1068)) <= uVar8) {
        lVar11 = 0;
      }
      *(long *)(param_1 + 800) = lVar11;
      uVar9 = 1;
      goto LAB_0013903e;
    }
    close(iVar4);
  }
  uVar9 = 0;
LAB_0013903e:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
  while( true ) {
    while ((*(byte *)((long)puVar2 + uVar8 * 2 + 1) & 8) == 0) {
      bVar3 = pbVar10[1];
      uVar8 = (ulong)bVar3;
      pbVar10 = pbVar10 + 1;
      if (bVar3 == 0) goto LAB_00138ec0;
joined_r0x00138ebd:
      if (bVar3 == 10) goto LAB_00138ec0;
    }
    bVar3 = *pbVar10;
    if ((bVar3 == 0) || (bVar3 == 10)) break;
LAB_00138e80:
    uVar8 = (ulong)bVar3;
    iVar4 = (iVar4 + 1) - (uint)((puVar2[(char)bVar3] & 0x800) == 0);
    if ((*(byte *)((long)puVar2 + uVar8 * 2 + 1) & 8) != 0) goto LAB_00138ea8;
  }
LAB_00138ec0:
  if (1 < iVar4) {
    *(undefined1 *)(param_1 + 0x4e) = 1;
  }
  goto LAB_00138d30;
LAB_00138ea8:
  do {
    bVar3 = pbVar10[1];
    uVar8 = (ulong)bVar3;
    pbVar10 = pbVar10 + 1;
  } while ((*(byte *)((long)puVar2 + uVar8 * 2 + 1) & 8) != 0);
  if (bVar3 != 0) goto joined_r0x00138ebd;
  goto LAB_00138ec0;
}


/* FUN_001390d0 @ 0x1390d0 */

void FUN_001390d0(long param_1,int param_2)

{
  undefined1 __frame[0x10c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1088;
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = openat(param_2,((char *)(long)&s_oom_score_00149790 /* "oom_score" */),0);
  if (-1 < iVar1) {
    __stream = fdopen(iVar1,((char *)(long)&DAT_00147760 /* "r" */));
    if (__stream == (FILE *)0x0) {
      if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
        close(iVar1);
        return;
      }
      goto LAB_00139192;
    }
    pcVar2 = fgets((*(char (*)[4104])(__fp - 0x1038)),0x1000,__stream);
    if (pcVar2 != (char *)0x0) {
      iVar1 = __isoc23_sscanf((*(char (*)[4104])(__fp - 0x1038)),((char *)(long)&DAT_001474a2 /* "%u" */),&(*(undefined4 *)(__fp - 0x103c)));
      if (0 < iVar1) {
        *(undefined4 *)(param_1 + 0x2e0) = (*(undefined4 *)(__fp - 0x103c));
      }
    }
    fclose(__stream);
  }
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_00139192:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_001391c0 @ 0x1391c0 */

/* WARNING: Type propagation algorithm not settling */

undefined8
FUN_001391c0(char *param_1,long param_2,undefined *param_3,long param_rcx,long param_r8,
            long param_r9)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  bool bVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char *__s1;
  long lVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  long extraout_RDX;
  long extraout_RDX_00;
  char *extraout_RDX_01;
  char *extraout_RDX_02;
  char *extraout_RDX_03;
  long extraout_RDX_04;
  long extraout_RDX_05;
  char *extraout_RDX_06;
  char *extraout_RDX_07;
  char *extraout_RDX_08;
  char *extraout_RDX_09;
  long extraout_RDX_10;
  long extraout_RDX_11;
  char *extraout_RDX_12;
  char *a2;
  long extraout_RDX_13;
  long extraout_RDX_14;
  char *pcVar9;
  char *extraout_RDX_15;
  char *extraout_RDX_16;
  long extraout_RDX_17;
  char *extraout_RDX_18;
  char *extraout_RDX_19;
  char *extraout_RDX_20;
  char *extraout_RDX_21;
  char *extraout_RDX_22;
  long extraout_RDX_23;
  char *extraout_RDX_24;
  long extraout_RDX_25;
  char *extraout_RDX_26;
  long extraout_RDX_27;
  char *extraout_RDX_28;
  long extraout_RDX_29;
  char *pcVar10;
  char *pcVar11;

  cVar3 = *param_1;
  pcVar9 = param_3;
  if (cVar3 == '\0') {
    return 1;
  }
LAB_001391e5:
  pcVar10 = param_1;
  if (cVar3 != '/') {
LAB_001391ed:
    __s1 = strchrnul(pcVar10,0x2f);
    pcVar11 = __s1 + -(long)pcVar10;
    pcVar8 = pcVar10;
    if (pcVar11 == (char *)0xc) {
      iVar4 = strncmp(pcVar10,((char *)(long)&s_system_slice_001497d4 /* "system.slice" */),0xc);
      if (iVar4 != 0) {
LAB_0013923d:
        (*(char * *)(__fp - 0x40)) = pcVar11 + -6;
        iVar4 = strncmp(pcVar10 + (long)(*(char * *)(__fp - 0x40)),((char *)(long)(__sec_rodata + 0x27f1) /* ".slice" */),6);
        lVar5 = extraout_RDX_00;
        if (iVar4 != 0) goto LAB_00139650;
LAB_00139262:
        lVar5 = (*(code *)param_3)(param_2,0x5b,lVar5,param_rcx,param_r8,param_r9);
        pcVar9 = extraout_RDX_01;
        if ((char)lVar5 == '\0') {
          return 0;
        }
        do {
          pcVar11 = pcVar8 + 1;
          lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar8,(long)pcVar9,param_rcx,
                                     param_r8,param_r9);
          if ((char)lVar5 == '\0') {
            return 0;
          }
          pcVar9 = extraout_RDX_02;
          pcVar8 = pcVar11;
        } while (pcVar10 + ((long)(*(char * *)(__fp - 0x40)) - (long)pcVar11) != (char *)0x0);
        goto LAB_00139590;
      }
      pcVar9 = ((char *)(long)&DAT_0014979a /* "[S]" */);
      lVar5 = extraout_RDX_04;
      while (cVar3 = *pcVar9, cVar3 != '\0') {
        pcVar9 = pcVar9 + 1;
        lVar6 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,lVar5,param_rcx,param_r8,param_r9
                                  );
        lVar5 = extraout_RDX_05;
        if ((char)lVar6 == '\0') {
          return 0;
        }
      }
      iVar4 = strncmp(__s1,((char *)(long)&s__system__001497e1 /* "/system-" */),8);
      pcVar9 = extraout_RDX_06;
      if (iVar4 != 0) goto LAB_001393a2;
      param_1 = strchrnul(__s1 + 1,0x2f);
      cVar3 = *param_1;
      pcVar9 = extraout_RDX_07;
      goto LAB_001392e0;
    }
    if (pcVar11 == (char *)0xd) {
      iVar4 = strncmp(pcVar10,((char *)(long)&s_machine_slice_001497ea /* "machine.slice" */),0xd);
      if (iVar4 == 0) {
        pcVar10 = ((char *)(long)&DAT_0014979e /* "[M]" */);
        pcVar9 = extraout_RDX_08;
        while (cVar3 = *pcVar10, cVar3 != '\0') {
          pcVar10 = pcVar10 + 1;
          lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,param_r8
                                     ,param_r9);
          pcVar9 = extraout_RDX_09;
          if ((char)lVar5 == '\0') {
            return 0;
          }
        }
        goto LAB_001393a2;
      }
      iVar4 = strncmp(pcVar10 + 7,((char *)(long)(__sec_rodata + 0x27f1) /* ".slice" */),6);
      if (iVar4 == 0) {
        (*(char * *)(__fp - 0x40)) = (char *)0x7;
        lVar5 = extraout_RDX_10;
        goto LAB_00139262;
      }
LAB_001393cd:
      iVar4 = strncmp(pcVar10,((char *)(long)&s_lxc_payload__0014980a /* "lxc.payload." */),0xc);
      if (iVar4 == 0) {
        pcVar9 = ((char *)(long)&DAT_001497a6 /* "[lxc:" */);
        while (cVar3 = *pcVar9, cVar3 != '\0') {
          pcVar9 = pcVar9 + 1;
          lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,param_r8
                                     ,param_r9);
          if ((char)lVar5 == '\0') {
            return 0;
          }
        }
        pcVar9 = pcVar10 + 0xc;
        do {
          cVar3 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,param_r8
                                     ,param_r9);
          if ((char)lVar5 == '\0') {
            return 0;
          }
        } while (pcVar10 + ((long)pcVar11 - (long)pcVar9) != (char *)0x0);
      }
      else {
        iVar4 = strncmp(pcVar10,((char *)(long)&s_lxc_monitor__00149817 /* "lxc.monitor." */),0xc);
        if (iVar4 != 0) goto LAB_00139650;
        pcVar9 = ((char *)(long)&DAT_001497ac /* "[LXC:" */);
        while (cVar3 = *pcVar9, cVar3 != '\0') {
          pcVar9 = pcVar9 + 1;
          lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,param_r8
                                     ,param_r9);
          if ((char)lVar5 == '\0') {
            return 0;
          }
        }
        pcVar9 = pcVar10 + 0xc;
        do {
          cVar3 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,param_r8
                                     ,param_r9);
          if ((char)lVar5 == '\0') {
            return 0;
          }
        } while (pcVar10 + ((long)pcVar11 - (long)pcVar9) != (char *)0x0);
      }
LAB_00139590:
      lVar5 = (*(code *)param_3)(param_2,0x5d,(long)pcVar9,param_rcx,param_r8,param_r9);
      if ((char)lVar5 == '\0') {
        return 0;
      }
      cVar3 = *__s1;
      pcVar9 = extraout_RDX_15;
      param_1 = __s1;
      goto LAB_001392e0;
    }
    if (pcVar11 == (char *)0xa) {
      iVar4 = strncmp(pcVar10,((char *)(long)&s_user_slice_001497f8 /* "user.slice" */),10);
      if (iVar4 != 0) goto LAB_0013923d;
      pcVar9 = ((char *)(long)&DAT_001497a2 /* "[U]" */);
      lVar5 = extraout_RDX;
      while (cVar3 = *pcVar9, cVar3 != '\0') {
        pcVar9 = pcVar9 + 1;
        lVar6 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,lVar5,param_rcx,param_r8,param_r9
                                  );
        lVar5 = extraout_RDX_11;
        if ((char)lVar6 == '\0') {
          return 0;
        }
      }
      iVar4 = strncmp(__s1,((char *)(long)&s__user__00149803 /* "/user-" */),6);
      pcVar9 = extraout_RDX_12;
      if (iVar4 != 0) goto LAB_001393a2;
      pcVar10 = __s1 + 6;
      param_1 = strchrnul(pcVar10,0x2f);
      param_rcx = (long)(param_1 + -6);
      iVar4 = strncmp((char *)param_rcx,((char *)(long)(__sec_rodata + 0x27f1) /* ".slice" */),6);
      pcVar9 = a2;
      if (iVar4 != 0) goto LAB_001393a2;
      pcVar8 = (char *)(param_rcx + -(long)pcVar10);
      *(long *)(param_2 + 0x10) = *(long *)(param_2 + 0x10) + -1;
      param_rcx = (long)pcVar8;
      lVar6 = (*(code *)param_3)(param_2,0x3a,(long)a2,(long)pcVar8,param_r8,param_r9);
      lVar5 = extraout_RDX_13;
      pcVar9 = pcVar8;
      if ((char)lVar6 == '\0') {
        return 0;
      }
      for (; pcVar9 != (char *)0x0; pcVar9 = __s1 + (6 - (long)pcVar9) + (long)pcVar8) {
        pcVar9 = pcVar10 + 1;
        lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar10,lVar5,param_rcx,param_r8,
                                   param_r9);
        if ((char)lVar5 == '\0') {
          return 0;
        }
        pcVar10 = pcVar9;
        lVar5 = extraout_RDX_14;
      }
      lVar5 = (*(code *)param_3)(param_2,0x5d,lVar5,param_rcx,param_r8,param_r9);
      cVar3 = (char)lVar5;
      pcVar9 = extraout_RDX_16;
      goto joined_r0x001395bd;
    }
    pcVar9 = pcVar10;
    pcVar7 = pcVar11;
    if (pcVar11 < (char *)0x7) goto joined_r0x00139460;
    (*(char * *)(__fp - 0x40)) = pcVar11 + -6;
    iVar4 = strncmp(pcVar10 + (long)(*(char * *)(__fp - 0x40)),((char *)(long)(__sec_rodata + 0x27f1) /* ".slice" */),6);
    lVar5 = extraout_RDX_27;
    if (iVar4 == 0) goto LAB_00139262;
    if ((char *)0xc < pcVar11) goto LAB_001393cd;
    if (pcVar11 == (char *)0xb) {
      iVar4 = strncmp(pcVar10,((char *)(long)&s_lxc_monitor_00149824 /* "lxc.monitor" */),0xb);
      if (iVar4 == 0) {
        bVar1 = true;
      }
      else {
        iVar4 = strncmp(pcVar10,((char *)(long)&s_lxc_payload_00149830 /* "lxc.payload" */),0xb);
        if (iVar4 != 0) goto LAB_00139650;
        bVar1 = false;
      }
      cVar3 = *__s1;
      pcVar9 = __s1;
      while (cVar3 == '/') {
        pcVar9 = pcVar9 + 1;
        cVar3 = *pcVar9;
      }
      param_1 = strchrnul(pcVar9,0x2f);
      if (0 < (long)param_1 - (long)pcVar9) {
        pcVar10 = ((char *)(long)&DAT_001497ac /* "[LXC:" */);
        if (!bVar1) {
          pcVar10 = ((char *)(long)&DAT_001497a6 /* "[lxc:" */);
        }
        while (cVar3 = *pcVar10, pcVar8 = pcVar9, cVar3 != '\0') {
          pcVar10 = pcVar10 + 1;
          lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,param_r8
                                     ,param_r9);
          if ((char)lVar5 == '\0') {
            return 0;
          }
        }
        do {
          pcVar10 = pcVar8 + 1;
          lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar8,(long)pcVar9,param_rcx,
                                     param_r8,param_r9);
          if ((char)lVar5 == '\0') {
            return 0;
          }
          pcVar8 = pcVar10;
        } while (pcVar9 + (((long)param_1 - (long)pcVar9) - (long)pcVar10) != (char *)0x0);
        lVar5 = (*(code *)param_3)(param_2,0x5d,(long)pcVar9,param_rcx,param_r8,param_r9);
        if ((char)lVar5 == '\0') {
          return 0;
        }
        cVar3 = *param_1;
        pcVar9 = extraout_RDX_28;
        goto LAB_001392e0;
      }
LAB_00139650:
      iVar4 = strncmp(pcVar10 + (long)(pcVar11 + -8),((char *)(long)&s__service_0014983c /* ".service" */),8);
      if (iVar4 != 0) {
        pcVar9 = pcVar11 + -6;
        pcVar7 = pcVar10 + (long)pcVar9;
        iVar4 = strncmp(pcVar7,((char *)(long)&s__scope_0014984b /* ".scope" */),6);
        if (iVar4 == 0) {
          if (pcVar9 < (char *)0x9) {
            lVar5 = extraout_RDX_17;
            if ((char *)0x5 < pcVar9) {
              iVar4 = strncmp(pcVar10,((char *)(long)&s_snap__00149870 /* "snap." */),5);
              if (iVar4 == 0) goto LAB_0013975c;
              lVar5 = extraout_RDX_23;
              if (pcVar9 == (char *)0x8) goto LAB_00139927;
            }
LAB_001398c4:
            lVar5 = (*(code *)param_3)(param_2,0x21,lVar5,param_rcx,param_r8,param_r9);
            pcVar9 = extraout_RDX_21;
            if ((char)lVar5 == '\0') {
              return 0;
            }
            do {
              pcVar7 = pcVar8 + 1;
              lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar8,(long)pcVar9,param_rcx,
                                         param_r8,param_r9);
              if ((char)lVar5 == '\0') {
                return 0;
              }
              pcVar9 = extraout_RDX_22;
              pcVar8 = pcVar7;
            } while (pcVar10 + (long)(pcVar11 + (-6 - (long)pcVar7)) != (char *)0x0);
          }
          else {
            iVar4 = strncmp(pcVar10,((char *)(long)&s_machine__00149852 /* "machine-" */),8);
            if (iVar4 == 0) {
              iVar4 = strncmp(__s1,((char *)(long)&s__supervisor_0014985b /* "/supervisor" */),0xb);
              pcVar9 = ((char *)(long)&s__SNC__001497b2 /* "[SNC:" */);
              if (iVar4 != 0) {
                pcVar9 = ((char *)(long)&DAT_001497b8 /* "[snc:" */);
              }
              while (cVar3 = *pcVar9, cVar3 != '\0') {
                pcVar9 = pcVar9 + 1;
                lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,
                                           param_r8,param_r9);
                if ((char)lVar5 == '\0') {
                  return 0;
                }
              }
              pcVar9 = pcVar10 + 8;
              do {
                cVar3 = *pcVar9;
                pcVar9 = pcVar9 + 1;
                lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,
                                           param_r8,param_r9);
                if ((char)lVar5 == '\0') {
                  return 0;
                }
              } while (pcVar10 + (long)(pcVar11 + (-6 - (long)pcVar9)) != (char *)0x0);
              lVar5 = (*(code *)param_3)(param_2,0x5d,(long)pcVar9,param_rcx,param_r8,param_r9);
              if ((char)lVar5 == '\0') {
                return 0;
              }
              iVar4 = strncmp(__s1,((char *)(long)&s__supervisor_0014985b /* "/supervisor" */),0xb);
              if (iVar4 == 0) {
                cVar3 = __s1[0xb];
                param_1 = __s1 + 0xb;
                pcVar9 = extraout_RDX_20;
              }
              else {
                iVar4 = strncmp(__s1,((char *)(long)&s__payload_00149867 /* "/payload" */),8);
                pcVar9 = extraout_RDX_26;
                if (iVar4 != 0) goto LAB_001393a2;
                cVar3 = __s1[8];
                param_1 = __s1 + 8;
              }
              goto LAB_001392e0;
            }
            iVar4 = strncmp(pcVar10,((char *)(long)&s_snap__00149870 /* "snap." */),5);
            if (iVar4 != 0) {
LAB_00139927:
              iVar4 = strncmp(pcVar10,((char *)(long)&s_libpod__00149876 /* "libpod-" */),7);
              if (iVar4 == 0) {
                pcVar8 = pcVar10 + 7;
                pcVar11 = strchrnul(pcVar8,0x2e);
                pcVar9 = ((char *)(long)&DAT_001497c5 /* "!pod:" */);
                while (cVar3 = *pcVar9, cVar3 != '\0') {
                  pcVar9 = pcVar9 + 1;
                  lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,
                                             param_r8,param_r9);
                  if ((char)lVar5 == '\0') {
                    return 0;
                  }
                }
                if (pcVar11 <= pcVar7) {
                  pcVar7 = pcVar11;
                }
                param_rcx = (long)(pcVar7 + -(long)pcVar8);
                pcVar11 = (char *)0xc;
                pcVar7 = (char *)0xc;
                if (param_rcx < 0xd) {
                  pcVar11 = (char *)param_rcx;
                  pcVar7 = (char *)param_rcx;
                }
                while (pcVar11 != (char *)0x0) {
                  pcVar11 = pcVar8 + 1;
                  lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar8,(long)pcVar9,
                                             param_rcx,param_r8,param_r9);
                  if ((char)lVar5 == '\0') {
                    return 0;
                  }
                  pcVar8 = pcVar11;
                  pcVar9 = extraout_RDX_24;
                  pcVar11 = pcVar10 + (7 - (long)pcVar11) + (long)pcVar7;
                }
              }
              else {
                iVar4 = strncmp(pcVar10,((char *)(long)&s_docker__0014987e /* "docker-" */),7);
                lVar5 = extraout_RDX_25;
                if (iVar4 != 0) goto LAB_001398c4;
                pcVar8 = pcVar10 + 7;
                pcVar9 = strchrnul(pcVar8,0x2e);
                pcVar11 = ((char *)(long)&s__docker__001497cb /* "!docker:" */);
                while (cVar3 = *pcVar11, cVar3 != '\0') {
                  pcVar11 = pcVar11 + 1;
                  lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar11,param_rcx
                                             ,param_r8,param_r9);
                  if ((char)lVar5 == '\0') {
                    return 0;
                  }
                }
                if (pcVar9 <= pcVar7) {
                  pcVar7 = pcVar9;
                }
                pcVar7 = pcVar7 + -(long)pcVar8;
                pcVar9 = pcVar7;
                if (0xc < (long)pcVar7) {
                  pcVar7 = (char *)0xc;
                  pcVar9 = pcVar7;
                }
                while (pcVar7 != (char *)0x0) {
                  lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar8,(long)pcVar9,
                                             param_rcx,param_r8,param_r9);
                  if ((char)lVar5 == '\0') {
                    return 0;
                  }
                  pcVar7 = pcVar10 + (7 - (long)(pcVar8 + 1)) + (long)pcVar9;
                  pcVar8 = pcVar8 + 1;
                }
              }
              goto LAB_001393a2;
            }
LAB_0013975c:
            pcVar8 = pcVar10 + 5;
            pcVar11 = strchrnul(pcVar8,0x2e);
            pcVar9 = ((char *)(long)&DAT_001497be /* "!snap:" */);
            while (cVar3 = *pcVar9, cVar3 != '\0') {
              pcVar9 = pcVar9 + 1;
              lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar3,(long)pcVar9,param_rcx,
                                         param_r8,param_r9);
              if ((char)lVar5 == '\0') {
                return 0;
              }
            }
            if (pcVar11 <= pcVar7) {
              pcVar7 = pcVar11;
            }
            pcVar2 = pcVar8;
            param_rcx = (long)pcVar11;
            pcVar11 = pcVar7 + -(long)pcVar8;
            while (pcVar11 != (char *)0x0) {
              lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar2,(long)pcVar9,param_rcx,
                                         param_r8,param_r9);
              if ((char)lVar5 == '\0') {
                return 0;
              }
              pcVar11 = pcVar10 + (long)(pcVar7 + -(long)pcVar8 + (5 - (long)(pcVar2 + 1)));
              pcVar2 = pcVar2 + 1;
              pcVar9 = extraout_RDX_19;
            }
          }
          goto LAB_001393a2;
        }
        goto LAB_00139563;
      }
      iVar4 = strncmp(pcVar10,((char *)(long)&s_user__00149845 /* "user@" */),5);
      if (iVar4 != 0) goto LAB_001396da;
      if (*__s1 != '/') goto LAB_00139ace;
      do {
        cVar3 = __s1[1];
        param_1 = __s1 + 1;
        pcVar9 = extraout_RDX_18;
        __s1 = param_1;
      } while (cVar3 == '/');
      goto LAB_001392e0;
    }
    if (pcVar11 == (char *)0x9) goto LAB_00139650;
    iVar4 = strncmp(pcVar10 + (long)(*(char * *)(__fp - 0x40)),((char *)(long)&s__scope_0014984b /* ".scope" */),6);
    lVar5 = extraout_RDX_29;
    if (iVar4 == 0) goto LAB_001398c4;
LAB_00139563:
    do {
      pcVar9 = pcVar8 + 1;
      lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar8,(long)pcVar9,param_rcx,param_r8,
                                 param_r9);
      if ((char)lVar5 == '\0') {
        return 0;
      }
      pcVar7 = pcVar10 + ((long)pcVar11 - (long)pcVar9);
joined_r0x00139460:
      pcVar8 = pcVar9;
    } while (pcVar7 != (char *)0x0);
    goto LAB_001393a2;
  }
  for (; *param_1 == '/'; param_1 = param_1 + 1) {
  }
  lVar5 = (*(code *)param_3)(param_2,0x2f,(long)pcVar9,param_rcx,param_r8,param_r9);
  cVar3 = (char)lVar5;
  pcVar9 = extraout_RDX_03;
joined_r0x001395bd:
  if (cVar3 == '\0') {
    return 0;
  }
  cVar3 = *param_1;
  goto LAB_001392e0;
LAB_001396da:
  do {
    pcVar9 = pcVar8 + 1;
    lVar5 = (*(code *)param_3)(param_2,(ulong)(uint)(int)*pcVar8,(long)pcVar9,param_rcx,param_r8,
                               param_r9);
    if ((char)lVar5 == '\0') {
      return 0;
    }
    pcVar8 = pcVar9;
  } while (pcVar10 + (long)(pcVar11 + (-8 - (long)pcVar9)) != (char *)0x0);
LAB_001393a2:
  cVar3 = *__s1;
  param_1 = __s1;
LAB_001392e0:
  if (cVar3 == '\0') {
    return 1;
  }
  goto LAB_001391e5;
LAB_00139ace:
  pcVar10 = __s1;
  if (*__s1 == '\0') {
    return 1;
  }
  goto LAB_001391ed;
}


/* FUN_00139c70 @ 0x139c70 */

undefined8
FUN_00139c70(char *param_1,long param_2,undefined *param_3,long param_rcx,long param_r8,
            long param_r9)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte *__s1;
  byte *pbVar5;
  byte *pbVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long extraout_RDX;
  char *pcVar10;
  char *extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  long extraout_RDX_04;
  long extraout_RDX_05;
  char *extraout_RDX_06;
  byte *pbVar11;
  byte *pbVar12;
  ulong uVar13;

  uVar9 = (ulong)(byte)*param_1;
  if (*param_1 == 0) {
    return 1;
  }
  do {
    if ((char)uVar9 == '/') {
      if (*param_1 != 0x2f) {
        if (*param_1 == 0) {
          return 1;
        }
        goto LAB_00139c9e;
      }
      do {
        pbVar6 = (byte *)(param_1 + 1);
        uVar9 = (ulong)*pbVar6;
        __s1 = (byte *)(param_1 + 1);
        param_1 = (char *)__s1;
      } while (*pbVar6 == 0x2f);
    }
    else {
LAB_00139c9e:
      __s1 = (byte *)strchrnul(param_1,0x2f);
      uVar13 = (long)__s1 - (long)param_1;
      if (uVar13 < 0xd) {
        bVar3 = *__s1;
        uVar9 = (ulong)bVar3;
        if (uVar13 == 0xb) {
          iVar4 = strncmp(param_1,((char *)(long)&s_lxc_payload_00149830 /* "lxc.payload" */),0xb);
          uVar9 = (ulong)bVar3;
          pbVar6 = __s1;
          bVar2 = bVar3;
          if (iVar4 == 0) {
            while (bVar2 == 0x2f) {
              pbVar6 = pbVar6 + 1;
              bVar2 = *pbVar6;
            }
            pbVar11 = (byte *)strchrnul((char *)pbVar6,0x2f);
            if (0 < (long)pbVar11 - (long)pbVar6) {
              pcVar10 = ((char *)(long)&DAT_00149886 /* "/lxc:" */);
              lVar7 = extraout_RDX_01;
              while (cVar1 = *pcVar10, pbVar5 = pbVar6, cVar1 != '\0') {
                pcVar10 = pcVar10 + 1;
                lVar8 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar1,lVar7,uVar9,param_r8,
                                           param_r9);
                lVar7 = extraout_RDX_04;
                if ((char)lVar8 == '\0') {
                  return 0;
                }
              }
              do {
                pbVar12 = pbVar5 + 1;
                lVar7 = (*(code *)param_3)(param_2,(ulong)(uint)(int)(char)*pbVar5,lVar7,uVar9,
                                           param_r8,param_r9);
                if ((char)lVar7 == '\0') {
                  return 0;
                }
                lVar7 = extraout_RDX_05;
                __s1 = pbVar11;
                pbVar5 = pbVar12;
              } while (pbVar6 + (((long)pbVar11 - (long)pbVar6) - (long)pbVar12) != (byte *)0x0);
              goto LAB_00139d0a;
            }
            uVar9 = (ulong)bVar3;
          }
        }
      }
      else {
        iVar4 = strncmp(param_1,((char *)(long)&s_lxc_payload__0014980a /* "lxc.payload." */),0xc);
        if (iVar4 == 0) {
          pcVar10 = ((char *)(long)&DAT_00149886 /* "/lxc:" */);
          lVar7 = extraout_RDX;
          while (cVar1 = *pcVar10, cVar1 != '\0') {
            pcVar10 = pcVar10 + 1;
            lVar8 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar1,lVar7,uVar9,param_r8,param_r9
                                      );
            lVar7 = extraout_RDX_02;
            if ((char)lVar8 == '\0') {
              return 0;
            }
          }
          pbVar6 = (byte *)(param_1 + 0xc);
          do {
            pbVar11 = pbVar6 + 1;
            lVar7 = (*(code *)param_3)(param_2,(ulong)(uint)(int)(char)*pbVar6,lVar7,uVar9,param_r8,
                                       param_r9);
            if ((char)lVar7 == '\0') {
              return 0;
            }
            lVar7 = extraout_RDX_03;
            pbVar6 = pbVar11;
          } while ((byte *)(param_1 + (uVar13 - (long)pbVar11)) != (byte *)0x0);
        }
        else {
          uVar9 = uVar13 - 6;
          pbVar6 = (byte *)(param_1 + uVar9);
          iVar4 = strncmp((char *)pbVar6,((char *)(long)&s__scope_0014984b /* ".scope" */),6);
          if (iVar4 == 0) {
            if (uVar9 < 9) {
              if (uVar9 != 8) goto LAB_00139d0a;
            }
            else {
              iVar4 = strncmp(param_1,((char *)(long)&s_machine__00149852 /* "machine-" */),8);
              if (iVar4 == 0) {
                iVar4 = strncmp((char *)__s1,((char *)(long)&s__supervisor_0014985b /* "/supervisor" */),0xb);
                if (iVar4 != 0) {
                  pcVar10 = ((char *)(long)&DAT_0014988c /* "/snc:" */);
                  while (cVar1 = *pcVar10, cVar1 != '\0') {
                    pcVar10 = pcVar10 + 1;
                    lVar7 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar1,(long)pcVar10,uVar9,
                                               param_r8,param_r9);
                    if ((char)lVar7 == '\0') {
                      return 0;
                    }
                  }
                  pbVar6 = (byte *)(param_1 + 8);
                  do {
                    bVar3 = *pbVar6;
                    pbVar6 = pbVar6 + 1;
                    lVar7 = (*(code *)param_3)(param_2,(ulong)(uint)(int)(char)bVar3,(long)pbVar6,
                                               uVar9,param_r8,param_r9);
                    if ((char)lVar7 == '\0') {
                      return 0;
                    }
                  } while ((byte *)(param_1 + uVar13 + (-6 - (long)pbVar6)) != (byte *)0x0);
                  iVar4 = strncmp((char *)__s1,((char *)(long)&s__supervisor_0014985b /* "/supervisor" */),0xb);
                  if (iVar4 != 0) {
                    iVar4 = strncmp((char *)__s1,((char *)(long)&s__payload_00149867 /* "/payload" */),8);
                    if (iVar4 == 0) {
                      uVar9 = (ulong)__s1[8];
                      __s1 = __s1 + 8;
                      goto LAB_00139d0d;
                    }
                    goto LAB_00139d0a;
                  }
                }
                uVar9 = (ulong)__s1[0xb];
                __s1 = __s1 + 0xb;
                goto LAB_00139d0d;
              }
            }
            iVar4 = strncmp(param_1,((char *)(long)&s_libpod__00149876 /* "libpod-" */),7);
            if (iVar4 == 0) {
              pbVar11 = (byte *)(param_1 + 7);
              pbVar5 = (byte *)strchrnul((char *)pbVar11,0x2e);
              pcVar10 = ((char *)(long)&DAT_00149892 /* "/pod:" */);
              while (cVar1 = *pcVar10, cVar1 != '\0') {
                pcVar10 = pcVar10 + 1;
                lVar7 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar1,(long)pcVar10,uVar9,
                                           param_r8,param_r9);
                if ((char)lVar7 == '\0') {
                  return 0;
                }
              }
              if (pbVar5 <= pbVar6) {
                pbVar6 = pbVar5;
              }
              pbVar6 = pbVar6 + -(long)pbVar11;
              pbVar5 = (byte *)0xc;
              pbVar12 = (byte *)0xc;
              if ((long)pbVar6 < 0xd) {
                pbVar5 = pbVar6;
                pbVar12 = pbVar6;
              }
              while (pbVar5 != (byte *)0x0) {
                pbVar5 = pbVar11 + 1;
                lVar7 = (*(code *)param_3)(param_2,(ulong)(uint)(int)(char)*pbVar11,(long)pcVar10,
                                           (long)pbVar6,param_r8,param_r9);
                if ((char)lVar7 == '\0') {
                  return 0;
                }
                pbVar11 = pbVar5;
                pcVar10 = extraout_RDX_06;
                pbVar5 = (byte *)(param_1 + (long)(pbVar12 + (7 - (long)pbVar5)));
              }
            }
            else {
              iVar4 = strncmp(param_1,((char *)(long)&s_docker__0014987e /* "docker-" */),7);
              if (iVar4 == 0) {
                pbVar11 = (byte *)(param_1 + 7);
                pbVar5 = (byte *)strchrnul((char *)pbVar11,0x2e);
                pcVar10 = ((char *)(long)&s__docker__001497cb /* "!docker:" */);
                while (cVar1 = *pcVar10, cVar1 != '\0') {
                  pcVar10 = pcVar10 + 1;
                  lVar7 = (*(code *)param_3)(param_2,(ulong)(uint)(int)cVar1,(long)pcVar10,uVar9,
                                             param_r8,param_r9);
                  if ((char)lVar7 == '\0') {
                    return 0;
                  }
                }
                if (pbVar5 <= pbVar6) {
                  pbVar6 = pbVar5;
                }
                pbVar6 = pbVar6 + -(long)pbVar11;
                pbVar5 = (byte *)0xc;
                pbVar12 = (byte *)0xc;
                if ((long)pbVar6 < 0xd) {
                  pbVar5 = pbVar6;
                  pbVar12 = pbVar6;
                }
                while (pbVar5 != (byte *)0x0) {
                  pbVar5 = pbVar11 + 1;
                  lVar7 = (*(code *)param_3)(param_2,(ulong)(uint)(int)(char)*pbVar11,(long)pcVar10,
                                             (long)pbVar6,param_r8,param_r9);
                  if ((char)lVar7 == '\0') {
                    return 0;
                  }
                  pbVar11 = pbVar5;
                  pcVar10 = extraout_RDX_00;
                  pbVar5 = (byte *)(param_1 + (long)(pbVar12 + (7 - (long)pbVar5)));
                }
              }
            }
          }
        }
LAB_00139d0a:
        uVar9 = (ulong)*__s1;
      }
    }
LAB_00139d0d:
    param_1 = (char *)__s1;
    if ((char)uVar9 == '\0') {
      return 1;
    }
  } while( true );
}


/* FUN_0013a190 @ 0x13a190 */

undefined8 FUN_0013a190(void *param_1,long param_2)

{
  undefined1 __frame[0x2a8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x268;
  int iVar1;
  void *pvVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long lVar5;
  ulong uVar6;
  undefined8 *puVar7;
  long in_FS_OFFSET = (long)__fake_fs;
  byte bVar8;
  float fVar9;
  float fVar10;

  bVar8 = 0;
  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  pvVar2 = nlmsg_hdr(param_1);
  iVar1 = genlmsg_parse(pvVar2,0,(*(void * (*)[4])(__fp - 0x218)),6,(void *)0x0);
  uVar3 = 1;
  if (iVar1 < 0) goto LAB_0013a28c;
  if (((*(void * *)(__fp - 0x1f8)) != (void *)0x0) || ((*(void * *)(__fp - 0x1f8)) = (*(void * *)(__fp - 0x1e8)), (*(void * *)(__fp - 0x1e8)) != (void *)0x0)) {
    pvVar2 = nla_data((*(void * *)(__fp - 0x1f8)));
    pvVar2 = nla_next(pvVar2,&(*(int *)(__fp - 0x21c)));
    puVar4 = nla_data(pvVar2);
    puVar7 = (*(undefined8 (*)[3])(__fp - 0x1d8));
    for (lVar5 = 0x36; lVar5 != 0; lVar5 = lVar5 + -1) {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + (ulong)bVar8 * -2 + 1;
      puVar7 = puVar7 + (ulong)bVar8 * -2 + 1;
    }
    uVar6 = (*(long *)(__fp - 0x148)) * 1000 - *(long *)(param_2 + 0x2e8);
    if (uVar6 == 0) {
      fVar10 = NAN;
      *(undefined8 *)(param_2 + 0x308) = 0x7fc000007fc00000;
    }
    else {
      if ((long)uVar6 < 0) {
        fVar10 = (float)uVar6;
        uVar6 = (*(long *)(__fp - 0x1c0)) - *(long *)(param_2 + 0x2f0);
        if ((long)uVar6 < 0) goto LAB_0013a399;
LAB_0013a2e6:
        fVar9 = (float)(long)uVar6;
      }
      else {
        fVar10 = (float)(long)uVar6;
        uVar6 = (*(long *)(__fp - 0x1c0)) - *(long *)(param_2 + 0x2f0);
        if (-1 < (long)uVar6) goto LAB_0013a2e6;
LAB_0013a399:
        fVar9 = (float)uVar6;
      }
      fVar9 = (fVar9 / fVar10) * 100.0;
      if (100.0 <= fVar9) {
        fVar9 = 100.0;
      }
      *(float *)(param_2 + 0x308) = fVar9;
      fVar9 = ((float)(ulong)((*(long *)(__fp - 0x1b0)) - *(long *)(param_2 + 0x2f8)) / fVar10) * 100.0;
      if (100.0 <= fVar9) {
        fVar9 = 100.0;
      }
      *(float *)(param_2 + 0x30c) = fVar9;
      fVar10 = ((float)(ulong)((*(long *)(__fp - 0x1a0)) - *(long *)(param_2 + 0x300)) / fVar10) * 100.0;
      if (100.0 <= fVar10) {
        fVar10 = 100.0;
      }
    }
    *(long *)(param_2 + 0x300) = (*(long *)(__fp - 0x1a0));
    *(long *)(param_2 + 0x2f8) = (*(long *)(__fp - 0x1b0));
    *(long *)(param_2 + 0x2f0) = (*(long *)(__fp - 0x1c0));
    *(long *)(param_2 + 0x2e8) = (*(long *)(__fp - 0x148)) * 1000;
    *(float *)(param_2 + 0x310) = fVar10;
  }
  uVar3 = 0;
LAB_0013a28c:
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

