#include "htop.h"

/* Scheduling_rowSetPolicy @ 0x12dcd0 */

_Bool Scheduling_rowSetPolicy(Process_ *row,Arg arg)

{
  undefined1 __frame[0xa8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x68;
  long lVar1;
  uint __policy;
  int iVar2;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: SchedulingArg * sarg@[???]
                       Unresolved local var: int policy@[???]
                       Unresolved local var: int r@[???] */
  (*(sched_param (*))(__fp - 0x14)).sched_priority = 0;
  __policy = *(uint *)arg.v;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (policies[(int)__policy].prioritySupport != false) {
    (*(sched_param (*))(__fp - 0x14)).sched_priority = *(int *)((long)arg.v + 4);
  }
  if (reset_on_fork) {
    __policy = __policy & 0x40000000;
  }
  iVar2 = sched_setscheduler((row->super).id,__policy,(sched_param_2 *)&(*(sched_param (*))(__fp - 0x14)));
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return iVar2 != -1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Scheduling_formatPolicy @ 0x12dd50 */

char * Scheduling_formatPolicy(int policy)

{
  switch(policy & 0xbfffffff) {
  case 0:
    return ((char *)(long)&s_OTHER_0014895d /* "OTHER" */);
  case 1:
    return ((char *)(long)&DAT_00148958 /* "FIFO" */);
  case 2:
    return ((char *)(long)&DAT_00148976 /* "RR" */);
  case 3:
    return ((char *)(long)&s_BATCH_00148970 /* "BATCH" */);
  default:
    return ((char *)(long)&DAT_00148963 /* "???" */);
  case 5:
    return ((char *)(long)&DAT_0014896b /* "IDLE" */);
  case 6:
    return ((char *)(long)&DAT_00148967 /* "EDF" */);
  }
}


/* Scheduling_readProcessPolicy @ 0x12dde0 */

void Scheduling_readProcessPolicy(Process *proc)

{
  int wVar1;

  wVar1 = sched_getscheduler((proc->super).id);
  proc->scheduling_policy = wVar1;
  return;
}


/* Scheduling_togglePolicyPanelResetOnFork @ 0x1320d0 */

void Scheduling_togglePolicyPanelResetOnFork(Panel *schedPanel)

{
  Object *pOVar1;
  int iVar2;
  ObjectClass *pOVar3;
  bool bVar4;
  char *__s2;

  __s2 = ((char *)(long)&s_Reset_on_fork__off_001473b8 /* "Reset on fork: off" */);
  bVar4 = !reset_on_fork;
  if (!reset_on_fork) {
    __s2 = ((char *)(long)&s_Reset_on_fork__on_001473a6 /* "Reset on fork: on" */);
  }
  pOVar1 = *schedPanel->items->array;
  pOVar3 = pOVar1[1].klass;
  reset_on_fork = bVar4;
  if ((pOVar3 != (ObjectClass *)0x0) && (iVar2 = strcmp((char *)pOVar3,__s2), iVar2 == 0)) {
    return;
  }
  free(pOVar3);
                    /* Unresolved local var: char * data@[???] */
  pOVar3 = (ObjectClass *)strdup(__s2);
  if (pOVar3 != (ObjectClass *)0x0) {
    pOVar1[1].klass = pOVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Scheduling_newPolicyPanel @ 0x133160 */

/* WARNING: Removing unreachable block (ram,0x0013321f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff80 : 0x0013323c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * Scheduling_newPolicyPanel(int preSelectedPolicy)

{
  undefined1 __frame[0x138] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xf8;
  int wVar1;
  long lVar2;
  Vector *pVVar3;
  code *pcVar4;
  int *__s;
  int iVar5;
  int wVar6;
  FunctionBar *fuBar;
  Panel *this;
  size_t sVar7;
  undefined8 *puVar8;
  int *pwVar9;
  SchedulingPolicy *pSVar10;
  undefined1 *puVar11;
  long a4;
  ObjectClass *a5;
  int wVar12;
  char *pcVar13;
  cchar_t *pcVar14;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar11 = (*(undefined1 (*) [8])(__fp - 0x78));
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  (*(char *(*) [3])(__fp - 0x58))[2] = (char *)0x0;
  (*(char *(*) [3])(__fp - 0x58))[0] = ((char *)(long)&s_Select_00149166 /* "Select " */);
  (*(char *(*) [3])(__fp - 0x58))[1] = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  (*(int (*))(__fp - 0x64)) = preSelectedPolicy;
  fuBar = FunctionBar_new((*(char *(*) [3])(__fp - 0x58)),FunctionBar_EnterEscKeys,((char *)(long)&FunctionBar_EnterEscEvents /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  this = malloc(0x26e0);
  if (this != (Panel *)0x0) {
    a4 = 0;
    a5 = &ListItem_class;
    (this->super).klass = &Panel_class.super;
    Panel_init(this,0,0,0,0,&ListItem_class,true,fuBar);
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[41750] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(undefined1 *(*))(__fp - 0x70)) = (*(undefined1 (*) [8])(__fp - 0x78));
    pwVar9 = (*(int (*) [8])(__fp - 0xa8));
    (*(undefined1 *(*))(__fp - 0x70)) = (*(undefined1 (*) [8])(__fp - 0x78));
    sVar7 = mbstowcs((*(int (*) [8])(__fp - 0xa8)),((char *)(long)&s_New_policy__0014916e /* "New policy:" */),0xb);
    wVar12 = (int)sVar7;
    if (0 < wVar12) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&this->header,wVar12);
      (*(int *(*))(__fp - 0x60)) = (*(int (*) [8])(__fp - 0xa8)) + (ulong)(uint)(wVar12 + -1) + 1;
      pcVar14 = (this->header).chptr;
      do {
        wVar12 = *pwVar9;
        iVar5 = iswprint(wVar12);
        pcVar14->attr = 0;
        pcVar14->chars[0] = 0;
        pcVar14->chars[1] = 0;
        pcVar14->chars[2] = 0;
        if (iVar5 == 0) {
          wVar12 = 65533;
        }
        pcVar14->attr = wVar1 & 0xffffff;
        pwVar9 = pwVar9 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar14->chars + 2)) = (undefined16)0x0;
        pcVar14->chars[0] = wVar12;
        pcVar14 = pcVar14 + 1;
      } while ((*(int *(*))(__fp - 0x60)) != pwVar9);
    }
    puVar11 = (*(undefined1 *(*))(__fp - 0x70));
    this->needsRedraw = true;
    pcVar13 = ((char *)(long)&s_Reset_on_fork__off_001473b8 /* "Reset on fork: off" */);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    if (reset_on_fork != false) {
      pcVar13 = ((char *)(long)&s_Reset_on_fork__on_001473a6 /* "Reset on fork: on" */);
    }
    puVar8 = malloc(0x18);
    if (puVar8 != (undefined8 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      *puVar8 = &ListItem_class;
      pcVar13 = strdup(pcVar13);
      if (pcVar13 != (char *)0x0) {
        pVVar3 = this->items;
        puVar8[1] = pcVar13;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
                    /* Unresolved local var: uint i@[???] */
        wVar12 = 0;
        *(undefined4 *)(puVar8 + 2) = 0xffffffff;
        *(undefined1 *)((long)puVar8 + 0x14) = 0;
        wVar1 = pVVar3->items;
        pSVar10 = policies;
        Vector_set(pVVar3,wVar1,puVar8);
        this->needsRedraw = true;
        do {
          pwVar9 = (int *)pSVar10->name;
          (*(int *(*))(__fp - 0x60)) = pwVar9;
          if (pwVar9 != (int *)0x0) {
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
            wVar1 = pSVar10->id;
            puVar8 = malloc(0x18);
            __s = (*(int *(*))(__fp - 0x60));
            if (puVar8 == (undefined8 *)0x0) break;
                    /* Unresolved local var: char * data@[???] */
            *puVar8 = &ListItem_class;
            pcVar13 = strdup((char *)__s);
            if (pcVar13 == (char *)0x0) break;
            pVVar3 = this->items;
            puVar8[1] = pcVar13;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
            *(int *)(puVar8 + 2) = wVar1;
            *(undefined1 *)((long)puVar8 + 0x14) = 0;
            wVar6 = pVVar3->items;
            Vector_set(pVVar3,wVar6,puVar8);
            this->needsRedraw = true;
            if (wVar1 == (*(int (*))(__fp - 0x64))) {
                    /* Unresolved local var: int size@[???] */
              wVar1 = this->items->items;
              wVar6 = wVar1 + -1;
              if (wVar12 < wVar1) {
                wVar6 = wVar12;
              }
              if (wVar6 < 0) {
                wVar6 = 0;
              }
              this->selected = wVar6;
              pcVar4 = (this->super).klass[1].extends;
              if (pcVar4 != (code *)0x0) {
                (*pcVar4)((long)this,0xffffffff,0,(long)pwVar9,a4,(long)a5);
              }
            }
          }
          wVar12 = wVar12 + 1;
          pSVar10 = pSVar10 + 1;
          if (wVar12 == 6) {
            if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
              __stack_chk_fail();
            }
            return this;
          }
        } while( true );
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* Scheduling_newPriorityPanel @ 0x133430 */

/* WARNING: Removing unreachable block (ram,0x0013354d) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0013356a */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * Scheduling_newPriorityPanel(int policy,int preSelectedPriority)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  int wVar1;
  long lVar2;
  Vector *this;
  code *pcVar3;
  int va0;
  int iVar4;
  int wVar5;
  Panel *this_00;
  size_t sVar6;
  undefined8 *data_;
  char *pcVar7;
  ulong a3;
  FunctionBar *pFVar8;
  undefined1 *puVar9;
  FunctionBar *pFVar10;
  long a4;
  ObjectClass *a5;
  long in_FS_OFFSET = (long)__fake_fs;

  puVar9 = (*(undefined1 (*) [8])(__fp - 0x88));
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  if (((((uint)policy < 6) && (policies[policy].name != (char *)0x0)) &&
      (policies[policy].prioritySupport != false)) &&
     ((va0 = sched_get_priority_min(policy), -1 < va0 &&
      ((*(int (*))(__fp - 0x5c)) = sched_get_priority_max(policy), -1 < (*(int (*))(__fp - 0x5c)))))) {
    (*(char *(*) [3])(__fp - 0x58))[2] = (char *)0x0;
    (*(char *(*) [3])(__fp - 0x58))[0] = ((char *)(long)&s_Select_00149166 /* "Select " */);
    (*(char *(*) [3])(__fp - 0x58))[1] = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
    (*(FunctionBar *(*))(__fp - 0x68)) = FunctionBar_new((*(char *(*) [3])(__fp - 0x58)),FunctionBar_EnterEscKeys,((char *)(long)&FunctionBar_EnterEscEvents /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
    this_00 = malloc(0x26e0);
    puVar9 = (*(undefined1 (*) [8])(__fp - 0x88));
    if (this_00 == (Panel *)0x0) {
LAB_00133704:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    a4 = 0;
    a5 = &ListItem_class;
    (this_00->super).klass = &Panel_class.super;
    Panel_init(this_00,0,0,0,0,&ListItem_class,true,(*(FunctionBar *(*))(__fp - 0x68)));
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[43692] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(undefined1 *(*))(__fp - 0x80)) = (*(undefined1 (*) [8])(__fp - 0x88));
    (*(FunctionBar *(*))(__fp - 0x70)) = (FunctionBar *)(*(int (*) [8])(__fp - 0xb8));
    (*(undefined1 *(*))(__fp - 0x80)) = (*(undefined1 (*) [8])(__fp - 0x88));
    sVar6 = mbstowcs((*(int (*) [8])(__fp - 0xb8)),((char *)(long)(__sec_rodata + 0x2e25) /* "Priority:" */),9);
    if (0 < (int)sVar6) {
      (*(FunctionBar *(*))(__fp - 0x68)) = (FunctionBar *)sVar6;
      RichString_setLen(&this_00->header,(int)sVar6);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      pFVar8 = (FunctionBar *)(this_00->header).chptr;
      (*(int (*))(__fp - 0x60)) = wVar1 & 0xffffff;
      (*(int *(*))(__fp - 0x78)) = (int *)((long)&(*(FunctionBar *(*))(__fp - 0x70))->field_0x4 + (ulong)((int)(*(FunctionBar *(*))(__fp - 0x68)) - 1) * 4);
      pFVar10 = (*(FunctionBar *(*))(__fp - 0x70));
      do {
        wVar1 = pFVar10->size;
        (*(FunctionBar *(*))(__fp - 0x70)) = pFVar8;
        (*(FunctionBar *(*))(__fp - 0x68)) = pFVar10;
        iVar4 = iswprint(wVar1);
        if (iVar4 == 0) {
          wVar1 = 65533;
        }
        (*(FunctionBar *(*))(__fp - 0x70))->size = 0;
        (*(FunctionBar *(*))(__fp - 0x70))->field_0x4 = 0;
        (*(FunctionBar *(*))(__fp - 0x70))->field_0x5 = 0;
        (*(FunctionBar *(*))(__fp - 0x70))->field_0x6 = 0;
        (*(FunctionBar *(*))(__fp - 0x70))->field_0x7 = 0;
        (*(FunctionBar *(*))(__fp - 0x70))->functions = (char **)0x0;
        pFVar10 = (FunctionBar *)&(*(FunctionBar *(*))(__fp - 0x68))->field_0x4;
        *(undefined16 *)(*(undefined1 (*) [16])((long)&(*(FunctionBar *(*))(__fp - 0x70))->functions + 4)) = (undefined16)0x0;
        pFVar8 = (FunctionBar *)((long)&(*(FunctionBar *(*))(__fp - 0x70))->events + 4);
        (*(FunctionBar *(*))(__fp - 0x70))->size = (*(int (*))(__fp - 0x60));
        *(int *)&(*(FunctionBar *(*))(__fp - 0x70))->field_0x4 = wVar1;
      } while ((FunctionBar *)(*(int *(*))(__fp - 0x78)) != pFVar10);
    }
                    /* Unresolved local var: int i@[???] */
    puVar9 = (*(undefined1 *(*))(__fp - 0x80));
    this_00->needsRedraw = true;
    if (va0 <= (*(int (*))(__fp - 0x5c))) {
      do {
        a3 = (ulong)(uint)va0;
        xSnprintf((char *)(*(char *(*) [3])(__fp - 0x58)),0x10,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),va0);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
        data_ = malloc(0x18);
        if (data_ == (undefined8 *)0x0) goto LAB_00133704;
                    /* Unresolved local var: char * data@[???] */
        *data_ = &ListItem_class;
        pcVar7 = strdup((char *)(*(char *(*) [3])(__fp - 0x58)));
        if (pcVar7 == (char *)0x0) goto LAB_00133704;
        this = this_00->items;
        data_[1] = pcVar7;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
        *(int *)(data_ + 2) = va0;
        *(undefined1 *)((long)data_ + 0x14) = 0;
        wVar1 = this->items;
        Vector_set(this,wVar1,data_);
        this_00->needsRedraw = true;
        if (preSelectedPriority == va0) {
                    /* Unresolved local var: int size@[???] */
          wVar1 = this_00->items->items;
          wVar5 = wVar1 + -1;
          if (preSelectedPriority < wVar1) {
            wVar5 = preSelectedPriority;
          }
          if (wVar5 < 0) {
            wVar5 = 0;
          }
          this_00->selected = wVar5;
          pcVar3 = (this_00->super).klass[1].extends;
          if (pcVar3 != (code *)0x0) {
            (*pcVar3)((long)this_00,0xffffffff,0,a3,a4,(long)a5);
          }
        }
        va0 = va0 + 1;
      } while (va0 <= (*(int (*))(__fp - 0x5c)));
    }
  }
  else {
    this_00 = (Panel *)0x0;
  }
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this_00;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

