/* Scheduling_newPriorityPanel @ 00133430 size 728 */

/* WARNING: Removing unreachable block (ram,0x0013354d) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0013356a */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * Scheduling_newPriorityPanel(wchar_t policy,wchar_t preSelectedPriority)

{
  wchar_t wVar1;
  long lVar2;
  Vector *this;
  code *pcVar3;
  wchar_t va0;
  int iVar4;
  wchar_t wVar5;
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
  long in_FS_OFFSET;
  wchar_t local_b8 [8];
  undefined1 auStack_88 [8];
  undefined1 *local_80;
  wchar_t *local_78;
  FunctionBar *local_70;
  FunctionBar *local_68;
  wchar_t local_60;
  wchar_t local_5c;
  char *functions [3];

  puVar9 = auStack_88;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  if (((((uint)policy < 6) && (policies[policy].name != (char *)0x0)) &&
      (policies[policy].prioritySupport != false)) &&
     ((va0 = sched_get_priority_min(policy), L'\xffffffff' < va0 &&
      (local_5c = sched_get_priority_max(policy), L'\xffffffff' < local_5c)))) {
    functions[2] = (char *)0x0;
    functions[0] = ((char *)0x149166 /* "Select " */);
    functions[1] = ((char *)0x147223 /* "Cancel " */);
    local_68 = FunctionBar_new(functions,FunctionBar_EnterEscKeys,((char *)0x14d258 /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
    this_00 = malloc(0x26e0);
    puVar9 = auStack_88;
    if (this_00 == (Panel *)0x0) {
LAB_00133704:
                    /* WARNING: Subroutine does not return */
      *(undefined8 *)(puVar9 + -8) = 0x133709;
      fail();
    }
    a4 = 0;
    a5 = &ListItem_class;
    (this_00->super).klass = &Panel_class.super;
    Panel_init(this_00,L'\0',L'\0',L'\0',L'\0',&ListItem_class,true,local_68);
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[43692] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_80 = auStack_88;
    local_70 = (FunctionBar *)local_b8;
    local_80 = auStack_88;
    sVar6 = mbstowcs(local_b8,((char *)0x149e25 /* "Priority:" */),9);
    if (L'\0' < (wchar_t)sVar6) {
      local_68 = (FunctionBar *)sVar6;
      RichString_setLen(&this_00->header,(wchar_t)sVar6);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      pFVar8 = (FunctionBar *)(this_00->header).chptr;
      local_60 = wVar1 & 0xffffff;
      local_78 = (wchar_t *)((long)&local_70->field_0x4 + (ulong)((int)local_68 - 1) * 4);
      pFVar10 = local_70;
      do {
        wVar1 = pFVar10->size;
        local_70 = pFVar8;
        local_68 = pFVar10;
        iVar4 = iswprint(wVar1);
        if (iVar4 == 0) {
          wVar1 = L'�';
        }
        local_70->size = L'\0';
        local_70->field_0x4 = 0;
        local_70->field_0x5 = 0;
        local_70->field_0x6 = 0;
        local_70->field_0x7 = 0;
        local_70->functions = (char **)0x0;
        pFVar10 = (FunctionBar *)&local_68->field_0x4;
        *(undefined1 (*) [16])((long)&local_70->functions + 4) = (undefined1  [16])0x0;
        pFVar8 = (FunctionBar *)((long)&local_70->events + 4);
        local_70->size = local_60;
        *(wchar_t *)&local_70->field_0x4 = wVar1;
      } while ((FunctionBar *)local_78 != pFVar10);
    }
                    /* Unresolved local var: wchar_t i@[???] */
    puVar9 = local_80;
    this_00->needsRedraw = true;
    if (va0 <= local_5c) {
      do {
        a3 = (ulong)(uint)va0;
        *(undefined8 *)(puVar9 + -8) = 0x133644;
        xSnprintf((char *)functions,0x10,((char *)0x149710 /* "%d" */),va0);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
        *(undefined8 *)(puVar9 + -8) = 0x13364e;
        data_ = malloc(0x18);
        if (data_ == (undefined8 *)0x0) goto LAB_00133704;
                    /* Unresolved local var: char * data@[???] */
        *data_ = &ListItem_class;
        *(undefined8 *)(puVar9 + -8) = 0x13366c;
        pcVar7 = strdup((char *)functions);
        if (pcVar7 == (char *)0x0) goto LAB_00133704;
        this = this_00->items;
        data_[1] = pcVar7;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
        *(wchar_t *)(data_ + 2) = va0;
        *(undefined1 *)((long)data_ + 0x14) = 0;
        wVar1 = this->items;
        *(undefined8 *)(puVar9 + -8) = 0x133692;
        Vector_set(this,wVar1,data_);
        this_00->needsRedraw = true;
        if (preSelectedPriority == va0) {
                    /* Unresolved local var: wchar_t size@[???] */
          wVar1 = this_00->items->items;
          wVar5 = wVar1 + L'\xffffffff';
          if (preSelectedPriority < wVar1) {
            wVar5 = preSelectedPriority;
          }
          if (wVar5 < L'\0') {
            wVar5 = L'\0';
          }
          this_00->selected = wVar5;
          pcVar3 = (this_00->super).klass[1].extends;
          if (pcVar3 != (code *)0x0) {
            *(undefined8 *)(puVar9 + -8) = 0x1336d6;
            (*pcVar3)((long)this_00,0xffffffff,0,a3,a4,(long)a5);
          }
        }
        va0 = va0 + L'\x01';
      } while (va0 <= local_5c);
    }
  }
  else {
    this_00 = (Panel *)0x0;
  }
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this_00;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(puVar9 + -8) = &UNK_0013370e;
  __stack_chk_fail();
}

