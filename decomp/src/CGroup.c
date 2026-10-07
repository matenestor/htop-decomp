#include "htop.h"

/* CGroup_filterName @ 0x13e0e0 */

void * CGroup_filterName(char *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                        long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  undefined8 uVar1;
  void *pvVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(void * *)(__fp - 0x48)) = (void *)0x0;
  ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x40)), (undefined16)0x0);
  uVar1 = FUN_001391c0(param_1,(long)&(*(void * *)(__fp - 0x48)),FUN_001388e0,param_rcx,param_r8,param_r9);
  if ((char)uVar1 != '\0') {
    uVar1 = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 8));
    pvVar2 = calloc((*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 8)) + 1,1);
    if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 8)) = 0;
    (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 0)) = uVar1;
    (*(void * *)(__fp - 0x48)) = pvVar2;
    uVar1 = FUN_001391c0(param_1,(long)&(*(void * *)(__fp - 0x48)),FUN_001388f0,param_rcx,param_r8,param_r9);
    if ((char)uVar1 != '\0') {
      *(undefined1 *)((long)(*(void * *)(__fp - 0x48)) + (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 0))) = 0;
      pvVar2 = (*(void * *)(__fp - 0x48));
      goto LAB_0013e177;
    }
    free((*(void * *)(__fp - 0x48)));
  }
  pvVar2 = (void *)0x0;
LAB_0013e177:
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return pvVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* CGroup_filterContainer @ 0x13e1c0 */

char * CGroup_filterContainer
                 (char *param_1,long param_rsi,long param_rdx,long param_rcx,long param_r8,
                 long param_r9)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  undefined8 uVar1;
  char *pcVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long *)(__fp - 0x30)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(char * *)(__fp - 0x48)) = (char *)0x0;
  ASSIGN_ARR((*(undefined1 (*)[16])(__fp - 0x40)), (undefined16)0x0);
  uVar1 = FUN_00139c70(param_1,&(*(char * *)(__fp - 0x48)),FUN_001388e0,param_rcx,param_r8,param_r9);
  if ((char)uVar1 != '\0') {
    uVar1 = (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 8));
    if ((*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 8)) == 0) {
      pcVar2 = strdup(((char *)(long)(__sec_rodata + 0x17c2) /* "/" */));
      if (pcVar2 == (char *)0x0) goto LAB_0013e291;
      goto LAB_0013e261;
    }
    pcVar2 = calloc((*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 8)) + 1,1);
    if (pcVar2 == (char *)0x0) {
LAB_0013e291:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 8)) = 0;
    (*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 0)) = uVar1;
    (*(char * *)(__fp - 0x48)) = pcVar2;
    uVar1 = FUN_00139c70(param_1,&(*(char * *)(__fp - 0x48)),FUN_001388f0,param_rcx,param_r8,param_r9);
    if ((char)uVar1 != '\0') {
      (*(char * *)(__fp - 0x48))[(*(ulong *)((char *)&(*(undefined1 (*)[16])(__fp - 0x40)) + 0))] = '\0';
      pcVar2 = (*(char * *)(__fp - 0x48));
      goto LAB_0013e261;
    }
    free((*(char * *)(__fp - 0x48)));
  }
  pcVar2 = (char *)0x0;
LAB_0013e261:
  if ((*(long *)(__fp - 0x30)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

