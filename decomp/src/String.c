#include "htop.h"

/* String_freeArray @ 0x12e100 */

void String_freeArray(undefined8 *param_1)

{
  void *__ptr;
  undefined8 *puVar1;

  if (param_1 != (undefined8 *)0x0) {
    __ptr = (void *)*param_1;
    puVar1 = param_1;
    while (__ptr != (void *)0x0) {
      puVar1 = puVar1 + 1;
      free(__ptr);
      __ptr = (void *)*puVar1;
    }
    free(param_1);
    return;
  }
  return;
}


/* String_cat @ 0x135560 */

void * String_cat(char *param_1,char *param_2)

{
  size_t p2;
  size_t p2_00;
  void *p0;
  size_t __size;

  p2 = strlen(param_1);
  p2_00 = strlen(param_2);
  __size = p2 + p2_00 + 1;
  p0 = malloc(__size);
  if (p0 != (void *)0x0) {
    __memcpy_chk(p0,param_1,p2,__size);
    if (__size < p2) {
      __size = p2;
    }
    __memcpy_chk((void *)((long)p0 + p2),param_2,p2_00,__size - p2);
    *(undefined1 *)((long)p0 + p2 + p2_00) = 0;
    return p0;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* String_trim @ 0x135600 */

char * String_trim(char *param_1)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  size_t __n;

  cVar1 = *param_1;
  if (1 < (byte)(cVar1 - 9U)) goto LAB_00135630;
  do {
    do {
      cVar1 = param_1[1];
      param_1 = param_1 + 1;
    } while ((byte)(cVar1 - 9U) < 2);
LAB_00135630:
  } while (cVar1 == ' ');
  sVar2 = strlen(param_1);
  do {
    while( true ) {
      __n = sVar2;
      if (__n == 0) goto LAB_00135665;
      cVar1 = param_1[__n - 1];
      sVar2 = __n - 1;
      if (cVar1 < '\v') break;
      if (cVar1 != ' ') goto LAB_00135665;
    }
  } while ('\b' < cVar1);
LAB_00135665:
  pcVar3 = strndup(param_1,__n);
  if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  return pcVar3;
}


/* String_split @ 0x135680 */

char ** String_split(char *param_1,char param_2,long *param_3)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  void *__ptr;
  char *pcVar1;
  char *pcVar2;
  void *pvVar3;
  char **ppcVar4;
  long lVar5;

  __ptr = calloc(10,8);
  if (__ptr != (void *)0x0) {
    (*(long *)(__fp - 0x40)) = 10;
    lVar5 = 0;
    while (pcVar1 = strchr(param_1,(int)param_2), pcVar1 != (char *)0x0) {
      pcVar2 = strndup(param_1,(long)pcVar1 - (long)param_1);
      if (pcVar2 == (char *)0x0) goto LAB_001357a3;
      *(char **)((long)__ptr + lVar5 * 8) = pcVar2;
      lVar5 = lVar5 + 1;
      pvVar3 = __ptr;
      if ((*(long *)(__fp - 0x40)) == lVar5) {
        (*(long *)(__fp - 0x40)) = (*(long *)(__fp - 0x40)) + 10;
        pvVar3 = realloc(__ptr,(*(long *)(__fp - 0x40)) * 8);
        if (pvVar3 == (void *)0x0) goto LAB_0013579b;
      }
      param_1 = param_1 + ((long)pcVar1 - (long)param_1) + 1;
      __ptr = pvVar3;
    }
    if (*param_1 != '\0') {
      pcVar1 = strdup(param_1);
      if (pcVar1 == (char *)0x0) goto LAB_001357a3;
      *(char **)((long)__ptr + lVar5 * 8) = pcVar1;
      lVar5 = lVar5 + 1;
    }
    ppcVar4 = realloc(__ptr,lVar5 * 8 + 8);
    if (ppcVar4 != (char **)0x0) {
      ppcVar4[lVar5] = (char *)0x0;
      if (param_3 != (long *)0x0) {
        *param_3 = lVar5;
      }
      return ppcVar4;
    }
LAB_0013579b:
    free(__ptr);
  }
LAB_001357a3:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_001357b0 @ 0x1357b0 */

void FUN_001357b0(long param_1,char *param_2,uint param_3)

{
  char *__ptr;
  char **ppcVar1;
  ulong uVar2;

  __ptr = String_trim(param_2);
  ppcVar1 = String_split(__ptr,' ',(long *)0x0);
  free(__ptr);
  uVar2 = (ulong)param_3;
  if ((ulong)(byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] - 1 <= uVar2) {
    uVar2 = (ulong)((byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] - 1);
  }
  *(char ***)(*(long *)(param_1 + 0x10) + uVar2 * 0x18 + 8) = ppcVar1;
  return;
}


/* FUN_00135830 @ 0x135830 */

void FUN_00135830(long param_1,char *param_2,uint param_3)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  size_t sVar1;
  char *pcVar2;
  char **__ptr;
  size_t __nmemb;
  undefined4 *puVar3;
  long lVar4;
  ulong uVar5;
  undefined4 *puVar6;
  char **ppcVar7;

  pcVar2 = String_trim(param_2);
  __ptr = String_split(pcVar2,' ',(long *)0x0);
  free(pcVar2);
  uVar5 = (ulong)param_3;
  if (*__ptr == (char *)0x0) {
    puVar3 = (undefined4 *)0x0;
    if (uVar5 < (ulong)(byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] - 1) {
      (*(long *)(__fp - 0x48)) = uVar5 * 0x18;
      *(undefined8 *)(*(long *)(param_1 + 0x10) + (*(long *)(__fp - 0x48))) = 0;
    }
    else {
      (*(long *)(__fp - 0x48)) = (ulong)((byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] - 1) * 0x18;
      *(undefined8 *)(*(long *)(param_1 + 0x10) + (*(long *)(__fp - 0x48))) = 0;
    }
  }
  else {
    sVar1 = 1;
    do {
      __nmemb = sVar1;
      sVar1 = __nmemb + 1;
    } while (__ptr[__nmemb] != (char *)0x0);
    if ((ulong)(byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] - 1 <= uVar5) {
      uVar5 = (ulong)((byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] - 1);
    }
    (*(long *)(__fp - 0x48)) = uVar5 * 0x18;
    *(size_t *)(*(long *)(param_1 + 0x10) + (*(long *)(__fp - 0x48))) = __nmemb;
    puVar3 = calloc(__nmemb,4);
    if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    puVar6 = puVar3;
    ppcVar7 = __ptr;
    do {
      pcVar2 = *ppcVar7;
      ppcVar7 = ppcVar7 + 1;
      lVar4 = __isoc23_strtol(pcVar2,(char **)0x0,10);
      *puVar6 = (int)lVar4;
      puVar6 = puVar6 + 1;
    } while (ppcVar7 != __ptr + (int)__nmemb);
    pcVar2 = *__ptr;
    ppcVar7 = __ptr;
    while (pcVar2 != (char *)0x0) {
      ppcVar7 = ppcVar7 + 1;
      free(pcVar2);
      pcVar2 = *ppcVar7;
    }
  }
  free(__ptr);
  *(undefined4 **)(*(long *)(param_1 + 0x10) + 0x10 + (*(long *)(__fp - 0x48))) = puVar3;
  return;
}


/* FUN_00135a00 @ 0x135a00 */

void FUN_00135a00(long param_1,ulong *param_2,char *param_3)

{
  ulong uVar1;
  void *__ptr;
  int iVar2;
  char *pcVar3;
  char **__ptr_00;
  void *pvVar4;
  ulong uVar5;
  size_t __size;
  undefined8 *puVar6;
  char **ppcVar7;
  ulong uVar8;
  byte bVar9;

  bVar9 = 0;
  pcVar3 = String_trim(param_3);
  __ptr_00 = String_split(pcVar3,' ',(long *)0x0);
  free(pcVar3);
  puVar6 = *(undefined8 **)(param_1 + 0x18);
  *puVar6 = 0;
  puVar6[0x41] = 0;
  uVar5 = (ulong)(((int)puVar6 - (int)(undefined8 *)((ulong)(puVar6 + 1) & 0xfffffffffffffff8)) +
                  0x210U >> 3);
  puVar6 = (undefined8 *)((ulong)(puVar6 + 1) & 0xfffffffffffffff8);
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + (ulong)bVar9 * -2 + 1;
  }
  if (*__ptr_00 != (char *)0x0) {
    ppcVar7 = __ptr_00;
    uVar5 = 0;
    do {
      uVar8 = uVar5;
      if (uVar5 < 0x3fffffff) {
        if (0x83 < uVar5) {
          uVar1 = uVar5 * 4;
          __size = uVar1 + 4;
          __ptr = *(void **)(param_1 + 0x18);
          pvVar4 = realloc(__ptr,__size);
          if (pvVar4 == (void *)0x0) {
            free(__ptr);
                    /* WARNING: Subroutine does not return */
            fail();
          }
          *(void **)(param_1 + 0x18) = pvVar4;
          if (__size < uVar1) {
            __size = uVar1;
          }
          __memset_chk((void *)((long)pvVar4 + uVar1),0,4,__size + uVar5 * -4);
        }
        iVar2 = FUN_0012d610(param_2,*ppcVar7);
        if (-1 < iVar2) {
          uVar8 = uVar5 + 1;
          *(int *)(*(long *)(param_1 + 0x18) + uVar5 * 4) = iVar2;
          if (iVar2 - 1U < 0x83) {
            *(uint *)(param_1 + 0x20) =
                 *(uint *)(param_1 + 0x20) | *(uint *)(Process_fields + (long)iVar2 * 0x20 + 0x18);
          }
        }
      }
      ppcVar7 = ppcVar7 + 1;
      uVar5 = uVar8;
    } while (*ppcVar7 != (char *)0x0);
    pcVar3 = *__ptr_00;
    ppcVar7 = __ptr_00;
    while (pcVar3 != (char *)0x0) {
      ppcVar7 = ppcVar7 + 1;
      free(pcVar3);
      pcVar3 = *ppcVar7;
    }
  }
  free(__ptr_00);
  return;
}


/* FUN_00135b80 @ 0x135b80 */

long FUN_00135b80(long param_1,long param_2,char *param_3)

{
  uint uVar1;
  void *__ptr;
  void *pvVar2;

  FUN_00135a00(param_1,*(ulong **)(param_2 + 0x18),param_3);
  uVar1 = *(uint *)(param_2 + 0x38);
  __ptr = *(void **)(param_2 + 0x30);
  *(long *)((long)__ptr + (ulong)uVar1 * 8) = param_1;
  *(uint *)(param_2 + 0x38) = uVar1 + 1;
  pvVar2 = realloc(__ptr,(ulong)(uVar1 + 2) << 3);
  if (pvVar2 != (void *)0x0) {
    *(void **)(param_2 + 0x30) = pvVar2;
    *(undefined8 *)((long)pvVar2 + (ulong)*(uint *)(param_2 + 0x38) * 8) = 0;
    return param_1;
  }
  free(__ptr);
                    /* WARNING: Subroutine does not return */
  fail();
}


/* String_contains_i @ 0x1371c0 */

char String_contains_i(char *param_1,char *param_2,char param_3)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char *pcVar1;
  char **__ptr;
  long lVar2;
  char **ppcVar3;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_3 == '\0') || (pcVar1 = strchr(param_2,0x7c), pcVar1 == (char *)0x0)) {
    pcVar1 = strcasestr(param_1,param_2);
    param_3 = pcVar1 != (char *)0x0;
    goto LAB_00137291;
  }
  __ptr = String_split(param_2,'|',&(*(long *)(__fp - 0x48)));
  if ((*(long *)(__fp - 0x48)) == 0) {
    if (__ptr != (char **)0x0) goto LAB_001372b8;
  }
  else {
    lVar2 = 0;
    do {
      pcVar1 = strcasestr(param_1,__ptr[lVar2]);
      if (pcVar1 != (char *)0x0) {
        pcVar1 = *__ptr;
        ppcVar3 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar3 = ppcVar3 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar3;
        }
        free(__ptr);
        goto LAB_00137291;
      }
      lVar2 = lVar2 + 1;
    } while (lVar2 != (*(long *)(__fp - 0x48)));
LAB_001372b8:
    pcVar1 = *__ptr;
    ppcVar3 = __ptr;
    while (pcVar1 != (char *)0x0) {
      ppcVar3 = ppcVar3 + 1;
      free(pcVar1);
      pcVar1 = *ppcVar3;
    }
    free(__ptr);
  }
  param_3 = '\0';
LAB_00137291:
  if ((*(long *)(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* String_readLine @ 0x1372f0 */

char * String_readLine(FILE *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  ulong uVar5;
  char *__ptr;

  pcVar2 = malloc(0x401);
  if (pcVar2 != (char *)0x0) {
    uVar4 = 0x401;
    uVar5 = 0x400;
    __ptr = pcVar2;
    while( true ) {
      pcVar3 = __fgets_chk(pcVar2,uVar4,0x401,param_1);
      if (pcVar3 == (char *)0x0) {
        free(__ptr);
        return (char *)0x0;
      }
      pcVar2 = strrchr(pcVar2,10);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
        return __ptr;
      }
      iVar1 = feof(param_1);
      if (iVar1 != 0) {
        return __ptr;
      }
      uVar4 = uVar5 + 0x401;
      pcVar3 = realloc(__ptr,uVar4);
      if (pcVar3 == (char *)0x0) break;
      pcVar2 = pcVar3 + uVar5;
      if (uVar4 < uVar5) {
        uVar4 = uVar5;
      }
      uVar4 = uVar4 - uVar5;
      uVar5 = uVar5 + 0x400;
      __ptr = pcVar3;
    }
    free(__ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FUN_001373f0 @ 0x1373f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_001373f0(long param_1,char *param_2,uint param_3)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  byte *p0;
  long lVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  FILE *__stream;
  char *pcVar7;
  char **__ptr;
  long lVar8;
  ushort **ppuVar9;
  void *pvVar10;
  long *plVar11;
  void *pvVar12;
  ulong uVar13;
  long lVar14;
  undefined8 uVar15;
  char **ppcVar16;
  undefined *puVar17;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  __stream = fopen(param_2,((char *)(long)&DAT_00147760 /* "r" */));
  if (__stream == (FILE *)0x0) {
LAB_001376b2:
    uVar15 = 0;
    goto LAB_001376b4;
  }
  bVar2 = false;
  uVar15 = 0;
  pvVar12 = (void *)0x0;
  while (pcVar7 = String_readLine(__stream), pcVar7 != (char *)0x0) {
    __ptr = String_split(pcVar7,'=',(long *)&(*(ulong *)(__fp - 0x70)));
    free(pcVar7);
    if (1 < (*(ulong *)(__fp - 0x70))) {
      pcVar7 = *__ptr;
      iVar4 = strcmp(pcVar7,((char *)(long)&s_config_reader_min_version_001491c7 /* "config_reader_min_version" */));
      ppcVar16 = __ptr;
      if (iVar4 != 0) {
        iVar4 = strcmp(pcVar7,((char *)(long)&s_fields_001491e1 /* "fields" */));
        if ((iVar4 == 0) && (*(int *)(param_1 + 8) < 3)) {
          if (*(int *)(param_1 + 0x38) == 0) {
            Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
            Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
            pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
          }
          else {
            pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
          }
          FUN_00135a00((long)pvVar12,*(ulong **)(param_1 + 0x18),__ptr[1]);
LAB_001375c0:
          pcVar7 = *__ptr;
          if (pcVar7 == (char *)0x0) goto LAB_001375e2;
        }
        else {
          iVar4 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x1f2a) /* "sort_key" */));
          if ((iVar4 == 0) && (*(int *)(param_1 + 8) < 3)) {
            if (*(int *)(param_1 + 0x38) == 0) {
              Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
              Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
            else {
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(int *)((long)pvVar12 + 0x2c) = (int)lVar8 + 1;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x1f45) /* "tree_sort_key" */));
          if ((iVar4 == 0) && (*(int *)(param_1 + 8) < 3)) {
            if (*(int *)(param_1 + 0x38) == 0) {
              Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
              Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
            else {
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(int *)((long)pvVar12 + 0x30) = (int)lVar8 + 1;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24a3) /* "sort_direction" */));
          if ((iVar4 == 0) && (*(int *)(param_1 + 8) < 3)) {
            if (*(int *)(param_1 + 0x38) == 0) {
              Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
              Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
            else {
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
LAB_00137cb2:
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(int *)((long)pvVar12 + 0x24) = (int)lVar8;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24b3) /* "tree_sort_direction" */));
          if (iVar4 != 0) {
            iVar4 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24c8) /* "tree_view" */));
            if (iVar4 == 0) {
              if (2 < *(int *)(param_1 + 8)) goto LAB_00137537;
              if (*(int *)(param_1 + 0x38) == 0) {
                Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
                Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
                pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
              }
              else {
                pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
              }
LAB_00137774:
              lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
              *(bool *)((long)pvVar12 + 0x34) = (int)lVar8 != 0;
            }
            else {
              iVar4 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24d3) /* "tree_view_always_by_pid" */));
              if (iVar4 != 0) goto LAB_0013754e;
              if (2 < *(int *)(param_1 + 8)) goto LAB_00137790;
              if (*(int *)(param_1 + 0x38) == 0) {
                Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
                Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
                pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
              }
              else {
                pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
              }
LAB_00137c14:
              lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
              *(bool *)((long)pvVar12 + 0x35) = (int)lVar8 != 0;
            }
            goto LAB_001375c0;
          }
          if (*(int *)(param_1 + 8) < 3) {
            if (*(int *)(param_1 + 0x38) == 0) {
              Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
              Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
            else {
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
LAB_00137cfd:
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(int *)((long)pvVar12 + 0x28) = (int)lVar8;
            goto LAB_001375c0;
          }
LAB_00137537:
          iVar4 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24d3) /* "tree_view_always_by_pid" */));
          if (iVar4 != 0) {
LAB_0013754e:
            iVar4 = strcmp(pcVar7,((char *)(long)(__sec_rodata + 0x24ec) /* "all_branches_collapsed" */));
            if ((iVar4 != 0) || (2 < *(int *)(param_1 + 8))) goto LAB_00137790;
            if (*(int *)(param_1 + 0x38) == 0) {
              Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
              Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
            else {
              pvVar12 = (void *)**(undefined8 **)(param_1 + 0x30);
            }
LAB_001375a2:
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)((long)pvVar12 + 0x36) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
LAB_00137790:
          iVar4 = strcmp(pcVar7,((char *)(long)&s_hide_kernel_threads_001491e8 /* "hide_kernel_threads" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x59) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_hide_userland_threads_001491fc /* "hide_userland_threads" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x5b) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_hide_running_in_container_00149212 /* "hide_running_in_container" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x5a) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_shadow_other_users_0014922c /* "shadow_other_users" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x57) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_show_thread_names_0014923f /* "show_thread_names" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x58) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_show_program_path_00149251 /* "show_program_path" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x56) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_highlight_base_name_00149263 /* "highlight_base_name" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x5c) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_highlight_deleted_exe_00149277 /* "highlight_deleted_exe" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x5d) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_shadow_distribution_path_prefix_0014c928 /* "shadow_distribution_path_prefix" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x5e) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_highlight_megabytes_0014928d /* "highlight_megabytes" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x5f) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_highlight_threads_001492a1 /* "highlight_threads" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x60) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_highlight_changes_001492b3 /* "highlight_changes" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x61) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_highlight_changes_delay_secs_001492c5 /* "highlight_changes_delay_secs" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            uVar5 = 0x15180;
            if ((int)lVar8 < 0x15181) {
              lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
              uVar5 = 1;
              if (1 < (int)lVar8) {
                lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
                uVar5 = (undefined4)lVar8;
              }
            }
            *(undefined4 *)(param_1 + 100) = uVar5;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_find_comm_in_cmdline_001492e2 /* "find_comm_in_cmdline" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x68) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_strip_exe_from_cmdline_001492f7 /* "strip_exe_from_cmdline" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x69) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_show_merged_command_0014930e /* "show_merged_command" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x6a) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_header_margin_00149322 /* "header_margin" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x6d) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_screen_tabs_00149330 /* "screen_tabs" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x6e) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_expand_system_time_0014933c /* "expand_system_time" */));
          if ((iVar4 == 0) || (iVar4 = strcmp(pcVar7,((char *)(long)&s_detailed_cpu_time_0014934f /* "detailed_cpu_time" */)), iVar4 == 0)) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x51) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_cpu_count_from_one_00149361 /* "cpu_count_from_one" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x50) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_cpu_count_from_zero_00149374 /* "cpu_count_from_zero" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x50) = (int)lVar8 == 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_show_cpu_usage_00149388 /* "show_cpu_usage" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x52) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_show_cpu_frequency_00149397 /* "show_cpu_frequency" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x53) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_show_cpu_temperature_001493aa /* "show_cpu_temperature" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x54) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_degree_fahrenheit_001493bf /* "degree_fahrenheit" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x55) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_update_process_names_001493d1 /* "update_process_names" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x6b) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_account_guest_in_cpu_meter_001493e6 /* "account_guest_in_cpu_meter" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x6c) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_delay_001475a2 /* "delay" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            uVar5 = 0xff;
            if ((int)lVar8 < 0x100) {
              lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
              uVar5 = 1;
              if (1 < (int)lVar8) {
                lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
                uVar5 = (undefined4)lVar8;
              }
            }
            *(undefined4 *)(param_1 + 0x4c) = uVar5;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_color_scheme_00149401 /* "color_scheme" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            uVar6 = (uint)lVar8;
            if (6 < uVar6) {
              uVar6 = 0;
            }
            *(uint *)(param_1 + 0x48) = uVar6;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_enable_mouse_0014940e /* "enable_mouse" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(bool *)(param_1 + 0x6f) = (int)lVar8 != 0;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_header_layout_0014941b /* "header_layout" */));
          if (iVar4 == 0) {
            ppuVar9 = __ctype_b_loc();
            p0 = (byte *)__ptr[1];
            if ((*(byte *)((long)*ppuVar9 + (ulong)*p0 * 2 + 1) & 8) == 0) {
              puVar17 = &DAT_00155fa0;
              lVar8 = 0;
              do {
                iVar4 = strcmp(*(char **)(puVar17 + 8),(char *)p0);
                if (iVar4 == 0) {
                  (*(uint *)(__fp - 0x80)) = (uint)lVar8;
                  break;
                }
                lVar8 = lVar8 + 1;
                puVar17 = puVar17 + 0x18;
                (*(uint *)(__fp - 0x80)) = 0;
              } while (lVar8 != 0xc);
            }
            else {
              lVar8 = __isoc23_strtol((char *)p0,(char **)0x0,10);
              (*(uint *)(__fp - 0x80)) = (uint)lVar8;
              if (0xb < (uint)lVar8) {
                (*(uint *)(__fp - 0x80)) = 0;
              }
            }
            *(uint *)(param_1 + 0xc) = (*(uint *)(__fp - 0x80));
            free(*(void **)(param_1 + 0x10));
            pvVar10 = xCalloc((ulong)(byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18],
                              0x18);
            *(void **)(param_1 + 0x10) = pvVar10;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_left_meters_00149429 /* "left_meters" */));
          if (iVar4 == 0) {
            FUN_001357b0(param_1,__ptr[1],0);
            goto LAB_001381cd;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_right_meters_00149435 /* "right_meters" */));
          if (iVar4 == 0) {
            FUN_001357b0(param_1,__ptr[1],1);
            bVar2 = true;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_left_meter_modes_00149442 /* "left_meter_modes" */));
          if (iVar4 == 0) {
            FUN_00135830(param_1,__ptr[1],0);
LAB_001381cd:
            bVar2 = true;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_right_meter_modes_00149453 /* "right_meter_modes" */));
          if (iVar4 == 0) {
            FUN_00135830(param_1,__ptr[1],1);
            goto LAB_001381cd;
          }
          uVar15 = FUN_00116180(pcVar7,((char *)(long)&s_column_meters__00149465 /* "column_meters_" */));
          if ((char)uVar15 != '\0') {
            lVar8 = __isoc23_strtol(pcVar7 + 0xe,(char **)0x0,10);
            FUN_001357b0(param_1,__ptr[1],(uint)lVar8);
            goto LAB_001381cd;
          }
          uVar15 = FUN_00116180(pcVar7,((char *)(long)&s_column_meter_modes__00149474 /* "column_meter_modes_" */));
          if ((char)uVar15 != '\0') {
            lVar8 = __isoc23_strtol(pcVar7 + 0x13,(char **)0x0,10);
            FUN_00135830(param_1,__ptr[1],(uint)lVar8);
            goto LAB_001381cd;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s_hide_function_bar_00149488 /* "hide_function_bar" */));
          if (iVar4 == 0) {
            lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
            *(int *)(param_1 + 0x70) = (int)lVar8;
            goto LAB_001375c0;
          }
          iVar4 = strncmp(pcVar7,((char *)(long)&s_screen__0014949a /* "screen:" */),7);
          if (iVar4 == 0) {
            (*(char * *)(__fp - 0x68)) = pcVar7 + 7;
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x58)), (undefined16)0x0);
            (*(char * *)(__fp - 0x60)) = __ptr[1];
            pvVar12 = Settings_newScreen(param_1,&(*(char * *)(__fp - 0x68)));
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s__sort_key_00148f29 /* ".sort_key" */));
          if (iVar4 == 0) {
            if (pvVar12 != (void *)0x0) {
              iVar4 = FUN_0012d610(*(ulong **)(param_1 + 0x18),__ptr[1]);
              if (iVar4 < 1) {
                iVar4 = 1;
              }
              *(int *)((long)pvVar12 + 0x2c) = iVar4;
            }
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s__tree_sort_key_00148f44 /* ".tree_sort_key" */));
          if (iVar4 == 0) {
            if (pvVar12 != (void *)0x0) {
              iVar4 = FUN_0012d610(*(ulong **)(param_1 + 0x18),__ptr[1]);
              if (iVar4 < 1) {
                iVar4 = 1;
              }
              *(int *)((long)pvVar12 + 0x30) = iVar4;
            }
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s__sort_direction_001494a2 /* ".sort_direction" */));
          if (iVar4 == 0) {
            if (pvVar12 != (void *)0x0) goto LAB_00137cb2;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s__tree_sort_direction_001494b2 /* ".tree_sort_direction" */));
          if (iVar4 == 0) {
            if (pvVar12 != (void *)0x0) goto LAB_00137cfd;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s__tree_view_001494c7 /* ".tree_view" */));
          if (iVar4 == 0) {
            if (pvVar12 != (void *)0x0) goto LAB_00137774;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s__tree_view_always_by_pid_001494d2 /* ".tree_view_always_by_pid" */));
          if (iVar4 == 0) {
            if (pvVar12 != (void *)0x0) goto LAB_00137c14;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s__all_branches_collapsed_001494eb /* ".all_branches_collapsed" */));
          if (iVar4 == 0) {
            if (pvVar12 != (void *)0x0) goto LAB_001375a2;
            goto LAB_001375c0;
          }
          iVar4 = strcmp(pcVar7,((char *)(long)&s__dynamic_00149503 /* ".dynamic" */));
          if (iVar4 == 0) {
            if (pvVar12 != (void *)0x0) {
              free_and_xStrdup((undefined8 *)((long)pvVar12 + 8),__ptr[1]);
            }
            goto LAB_001375c0;
          }
          pcVar7 = *__ptr;
        }
        do {
          free(pcVar7);
          pcVar7 = ppcVar16[1];
          ppcVar16 = ppcVar16 + 1;
        } while (pcVar7 != (char *)0x0);
        goto LAB_001375e2;
      }
      lVar8 = __isoc23_strtol(__ptr[1],(char **)0x0,10);
      *(int *)(param_1 + 8) = (int)lVar8;
      if ((int)lVar8 < 4) goto LAB_001375c0;
      __fprintf_chk(_stderr,2,((char *)(long)&s_WARNING___s_specifies_configurat_0014c858 /* "WARNING: %s specifies configuration format\n" */),param_2);
      __fprintf_chk(_stderr,2,
                    ((char *)(long)&s_version_v_d__but_this__s_binary_o_0014c888 /* "         version v%d, but this %s binary only supports up to version v%d.\n" */),
                    *(int *)(param_1 + 8),((char *)(long)(__sec_rodata + 0x254a) /* "htop" */),3);
      __fprintf_chk(_stderr,2,
                    ((char *)(long)&s_The_configuration_file_will_be_d_0014c8d8 /* "         The configuration file will be downgraded to v%d when %s exits.\n" */),3,
                    ((char *)(long)(__sec_rodata + 0x254a) /* "htop" */));
      pcVar7 = *__ptr;
      while (pcVar7 != (char *)0x0) {
        ppcVar16 = ppcVar16 + 1;
        free(pcVar7);
        pcVar7 = *ppcVar16;
      }
      free(__ptr);
      fclose(__stream);
      goto LAB_001376b2;
    }
    if (__ptr != (char **)0x0) {
      pcVar7 = *__ptr;
      ppcVar16 = __ptr;
      while (pcVar7 != (char *)0x0) {
        ppcVar16 = ppcVar16 + 1;
        free(pcVar7);
        pcVar7 = *ppcVar16;
      }
LAB_001375e2:
      free(__ptr);
    }
    uVar15 = 1;
  }
  fclose(__stream);
  if ((bVar2) && ((ulong)(byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] != 0)) {
    plVar11 = *(long **)(param_1 + 0x10);
    bVar3 = false;
    uVar13 = 0;
    do {
      lVar8 = *plVar11;
      if (lVar8 != 0) {
        lVar1 = plVar11[1];
        if ((plVar11[2] == 0) || (lVar1 == 0)) goto LAB_00137f26;
        lVar14 = 0;
        do {
          if (*(long *)(lVar1 + lVar14 * 8) == 0) goto LAB_00137f26;
          lVar14 = lVar14 + 1;
        } while (lVar8 != lVar14);
        bVar3 = bVar2;
        if (*(long *)(lVar1 + lVar8 * 8) != 0) goto LAB_00137f26;
      }
      uVar13 = uVar13 + 1;
      plVar11 = plVar11 + 3;
    } while ((byte)(&DAT_00155fa0)[(long)*(int *)(param_1 + 0xc) * 0x18] != uVar13);
    if (!bVar3) goto LAB_00137f26;
  }
  else {
LAB_00137f26:
    FUN_00132480(param_1,param_3);
  }
  if (*(int *)(param_1 + 0x38) == 0) {
    Settings_newScreen(param_1,(undefined8 *)Platform_defaultScreens);
    Settings_newScreen(param_1,(undefined8 *)(Platform_defaultScreens + 0x20));
  }
LAB_001376b4:
  if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar15;
}


/* String_safeStrncpy @ 0x13a410 */

void String_safeStrncpy(undefined1 *param_1,long param_2,long param_3)

{
  long lVar1;

  lVar1 = 0;
  if (param_3 != 1) {
    do {
      if (*(char *)(param_2 + lVar1) == '\0') break;
      param_1[lVar1] = *(char *)(param_2 + lVar1);
      lVar1 = lVar1 + 1;
    } while (lVar1 != param_3 + -1);
    param_1 = param_1 + lVar1;
  }
  *param_1 = 0;
  return;
}


/* FUN_0013a450 @ 0x13a450 */

long FUN_0013a450(int param_1,undefined1 *param_2,ulong param_3)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long lVar1;
  int *piVar2;
  ulong uVar3;
  ulong uVar4;
  ulong p3;
  ulong p2;

  if (param_3 == 0) {
    close(param_1);
    (*(long *)(__fp - 0x40)) = -0x16;
  }
  else {
    p2 = param_3 - 1;
    (*(long *)(__fp - 0x40)) = 0;
    p3 = param_3;
    do {
      while (lVar1 = __read_chk(param_1,param_2,p2,p3), lVar1 != -1) {
        if (0 < lVar1) {
          uVar3 = p3;
          if (p3 <= param_3) {
            uVar3 = param_3;
          }
          uVar4 = (lVar1 + uVar3) - p3;
          if (uVar4 < uVar3) {
            uVar4 = uVar3;
          }
          (*(long *)(__fp - 0x40)) = (*(long *)(__fp - 0x40)) + lVar1;
          param_2 = param_2 + lVar1;
          p2 = p2 - lVar1;
          p3 = (p3 - (lVar1 + uVar3)) + uVar4;
        }
        if ((p2 == 0) || (lVar1 == 0)) {
          close(param_1);
          *param_2 = 0;
          return (*(long *)(__fp - 0x40));
        }
      }
      piVar2 = __errno_location();
    } while (*piVar2 == 4);
    close(param_1);
    *param_2 = 0;
    (*(long *)(__fp - 0x40)) = (long)-*piVar2;
  }
  return (*(long *)(__fp - 0x40));
}


/* FUN_0013a540 @ 0x13a540 */

undefined1 FUN_0013a540(void)

{
  undefined1 __frame[0x4b8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x478;
  int iVar1;
  int *piVar2;
  long lVar3;
  char *pcVar4;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 uVar5;

  (*(long *)(__fp - 0x20)) = *(long *)(in_FS_OFFSET + 0x28);
  pcVar4 = (*(char (*)[1032])(__fp - 0x428));
  for (lVar3 = 0x80; lVar3 != 0; lVar3 = lVar3 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4[4] = '\0';
    pcVar4[5] = '\0';
    pcVar4[6] = '\0';
    pcVar4[7] = '\0';
    pcVar4 = pcVar4 + 8;
  }
  iVar1 = open(((char *)(long)&s__proc_acpi_ac_adapter_AC_state_0014ca30 /* "/proc/acpi/ac_adapter/AC/state" */),0);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    if (-*piVar2 < 1) goto LAB_0013a5d0;
  }
  else {
    lVar3 = FUN_0013a450(iVar1,(*(char (*)[1032])(__fp - 0x428)),0x400);
    if (lVar3 < 1) {
LAB_0013a5d0:
      uVar5 = 2;
      goto LAB_0013a5aa;
    }
  }
  iVar1 = strcmp((*(char (*)[1032])(__fp - 0x428)),((char *)(long)&s_on_line_00149898 /* "on-line" */));
  uVar5 = iVar1 == 0;
LAB_0013a5aa:
  if ((*(long *)(__fp - 0x20)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FUN_0013a5e0 @ 0x13a5e0 */

void FUN_0013a5e0(double *param_1,int *param_2)

{
  undefined1 __frame[0x578] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x538;
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  DIR *__dirp;
  dirent *pdVar6;
  long lVar7;
  char *pcVar8;
  int *piVar9;
  ulong uVar10;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar11;

  (*(long *)(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  *param_1 = NAN;
  *param_2 = 2;
  __dirp = opendir(((char *)(long)&s__sys_class_power_supply_001498a0 /* "/sys/class/power_supply" */));
  if (__dirp == (DIR *)0x0) {
LAB_0013a8a4:
    if ((*(long *)(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  uVar10 = 0;
  (*(ulong *)(__fp - 0x4e8)) = 0;
  do {
    pdVar6 = readdir(__dirp);
    while( true ) {
      if (pdVar6 == (dirent *)0x0) {
        closedir(__dirp);
        dVar11 = NAN;
        if (uVar10 != 0) {
          dVar11 = ((double)(*(ulong *)(__fp - 0x4e8)) * 100.0) / (double)uVar10;
        }
        *param_1 = dVar11;
        goto LAB_0013a8a4;
      }
      iVar4 = dirfd(__dirp);
      iVar4 = openat(iVar4,pdVar6->d_name,0x210000);
      if (iVar4 < 0) break;
      if (((pdVar6->d_name[0] == 'B') && (pdVar6->d_name[1] == 'A')) && (pdVar6->d_name[2] == 'T'))
      {
LAB_0013a6a2:
        iVar5 = openat(iVar4,((char *)(long)&s_uevent_001498c3 /* "uevent" */),0);
        if (iVar5 < 0) {
          piVar9 = __errno_location();
          lVar7 = (long)-*piVar9;
        }
        else {
          lVar7 = FUN_0013a450(iVar5,(undefined1 *)&(*(int *)(__fp - 0x448)),0x400);
        }
        if (-1 < lVar7) {
          (*(int * *)(__fp - 0x4c0)) = &(*(int *)(__fp - 0x448));
          bVar2 = false;
          (*(double *)(__fp - 0x4d8)) = 0.0;
          (*(double *)(__fp - 0x4e0)) = NAN;
          bVar3 = false;
          while (pcVar8 = strsep((char **)&(*(int * *)(__fp - 0x4c0)),((char *)(long)&DAT_00147506 /* "\n" */)), pcVar8 != (char *)0x0) {
            (*(undefined4 *)(__fp - 0x458)) = 0;
            (*(int *)(__fp - 0x4c4)) = 0;
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x4b8)), (undefined16)0x0);
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x4a8)), (undefined16)0x0);
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x498)), (undefined16)0x0);
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x488)), (undefined16)0x0);
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x478)), (undefined16)0x0);
            ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x468)), (undefined16)0x0);
            iVar5 = __isoc23_sscanf(pcVar8,((char *)(long)&s_POWER_SUPPLY__99______d_001498ca /* "POWER_SUPPLY_%99[^=]=%d" */),(*(undefined1 (*)[16])(__fp - 0x4b8)),&(*(int *)(__fp - 0x4c4)));
            if (iVar5 == 2) {
              iVar5 = strcmp((*(undefined1 (*)[16])(__fp - 0x4b8)),((char *)(long)&s_CAPACITY_001498e2 /* "CAPACITY" */));
              if (iVar5 == 0) {
                (*(double *)(__fp - 0x4e0)) = (double)(*(int *)(__fp - 0x4c4)) / 100.0;
              }
              else {
                iVar5 = strcmp((*(undefined1 (*)[16])(__fp - 0x4b8)),((char *)(long)&s_ENERGY_FULL_001498eb /* "ENERGY_FULL" */));
                if ((iVar5 == 0) || (iVar5 = strcmp((*(undefined1 (*)[16])(__fp - 0x4b8)),((char *)(long)&s_CHARGE_FULL_001498f7 /* "CHARGE_FULL" */)), iVar5 == 0)) {
                  (*(double *)(__fp - 0x4d8)) = (double)(*(int *)(__fp - 0x4c4));
                  dVar11 = (double)uVar10 + (*(double *)(__fp - 0x4d8));
                  if (9.223372036854776e+18 <= dVar11) {
                    uVar10 = (long)(dVar11 - 9.223372036854776e+18) ^ 0x8000000000000000;
                  }
                  else {
                    uVar10 = (ulong)dVar11;
                  }
                  if (bVar2) goto LAB_0013a830;
                  bVar3 = true;
                }
                else {
                  iVar5 = strcmp((*(undefined1 (*)[16])(__fp - 0x4b8)),((char *)(long)&s_ENERGY_NOW_00149903 /* "ENERGY_NOW" */));
                  if ((iVar5 == 0) || (iVar5 = strcmp((*(undefined1 (*)[16])(__fp - 0x4b8)),((char *)(long)&s_CHARGE_NOW_0014990e /* "CHARGE_NOW" */)), iVar5 == 0)) {
                    (*(ulong *)(__fp - 0x4e8)) = (*(ulong *)(__fp - 0x4e8)) + (long)(*(int *)(__fp - 0x4c4));
                    if (bVar3) goto LAB_0013a830;
                    bVar2 = true;
                  }
                }
              }
            }
          }
          if (((!bVar2) && (bVar3)) && (0.0 <= (*(double *)(__fp - 0x4e0)))) {
            dVar11 = (*(double *)(__fp - 0x4d8)) * (*(double *)(__fp - 0x4e0)) + (double)(*(ulong *)(__fp - 0x4e8));
            if (9.223372036854776e+18 <= dVar11) {
              (*(ulong *)(__fp - 0x4e8)) = (long)(dVar11 - 9.223372036854776e+18) ^ 0x8000000000000000;
            }
            else {
              (*(ulong *)(__fp - 0x4e8)) = (ulong)dVar11;
            }
          }
        }
      }
      else if ((pdVar6->d_name[0] == 'A') && (pdVar6->d_name[1] == 'C')) {
LAB_0013a97b:
        if (*param_2 == 2) {
          iVar5 = openat(iVar4,((char *)(long)&s_online_00149919 /* "online" */),0);
          if (iVar5 < 0) {
            piVar9 = __errno_location();
            if (-*piVar9 < 1) goto LAB_0013ab14;
          }
          else {
            lVar7 = FUN_0013a450(iVar5,(undefined1 *)&(*(int *)(__fp - 0x448)),2);
            if (lVar7 < 1) {
LAB_0013ab14:
              *param_2 = 2;
              goto LAB_0013a830;
            }
          }
          if ((char)(*(int *)(__fp - 0x448)) == '0') {
            *param_2 = 0;
          }
          else if ((char)(*(int *)(__fp - 0x448)) == '1') {
            *param_2 = 1;
          }
        }
      }
      else {
        iVar5 = openat(iVar4,((char *)(long)&DAT_001498b8 /* "type" */),0);
        if (iVar5 < 0) {
          piVar9 = __errno_location();
          lVar7 = (long)-*piVar9;
        }
        else {
          lVar7 = FUN_0013a450(iVar5,(undefined1 *)&(*(int *)(__fp - 0x448)),0x20);
        }
        if (0 < lVar7) {
          pcVar8 = &(*(char *)(__fp - 0x449)) + lVar7;
          cVar1 = (&(*(char *)(__fp - 0x449)))[lVar7];
          while (cVar1 == '\n') {
            *pcVar8 = '\0';
            pcVar8 = pcVar8 + -1;
            cVar1 = *pcVar8;
          }
          if (CONCAT26((*(undefined2 *)(__fp - 0x442)),CONCAT24((*(short *)(__fp - 0x444)),(*(int *)(__fp - 0x448)))) == 0x79726574746142)
          goto LAB_0013a6a2;
          if (((*(int *)(__fp - 0x448)) == 0x6e69614d) && ((*(short *)(__fp - 0x444)) == 0x73)) goto LAB_0013a97b;
        }
      }
LAB_0013a830:
      close(iVar4);
      pdVar6 = readdir(__dirp);
    }
  } while( true );
}

