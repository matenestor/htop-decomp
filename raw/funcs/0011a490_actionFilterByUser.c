/* actionFilterByUser @ 0011a490 size 961 */

/* WARNING: Removing unreachable block (ram,0x0011a551) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011a56e */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Htop_Reaction actionFilterByUser(State_2 *st)

{
  wchar_t wVar1;
  long lVar2;
  Hashtable_2 *pHVar3;
  Vector *pVVar4;
  long *a0;
  code *pcVar5;
  void *__ptr;
  State_2 *st_00;
  int iVar6;
  FunctionBar *pFVar7;
  MainPanel_ *list;
  size_t sVar8;
  undefined8 *puVar9;
  char *pcVar10;
  Object **ptr;
  long *plVar11;
  Object *data_;
  ObjectClass *pOVar12;
  Object *pOVar13;
  passwd *ppVar14;
  long a3;
  wchar_t wVar15;
  long a2;
  wchar_t *pwVar16;
  MainPanel_ *pMVar17;
  long a4;
  MainPanel_ *pMVar18;
  wchar_t wVar19;
  cchar_t *pcVar20;
  ulong uVar21;
  Machine *pMVar22;
  long in_FS_OFFSET;
  wchar_t local_d8 [16];
  undefined1 auStack_88 [16];
  State_2 *local_78;
  wchar_t local_6c;
  MainPanel_ *local_68;
  MainPanel_ *local_60;
  char *functions [3];

  pMVar17 = (MainPanel_ *)auStack_88;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  functions[2] = (char *)0x0;
  functions[0] = ((char *)0x1473d6 /* "Show   " */);
  functions[1] = ((char *)0x147223 /* "Cancel " */);
  local_78 = st;
  pFVar7 = FunctionBar_new(functions,FunctionBar_EnterEscKeys,((char *)0x14d258 /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  list = malloc(0x26e0);
  if (list != (MainPanel_ *)0x0) {
    a4 = 0;
    (list->super).super.klass = &Panel_class.super;
    Panel_init(&list->super,L'\0',L'\0',L'\0',L'\0',&ListItem_class,true,pFVar7);
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[54854] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_60 = (MainPanel_ *)auStack_88;
    pwVar16 = local_d8;
    local_60 = (MainPanel_ *)auStack_88;
    sVar8 = mbstowcs(local_d8,((char *)0x1473de /* "Show processes of:" */),0x12);
    wVar15 = (wchar_t)sVar8;
    if (L'\0' < wVar15) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&(list->super).header,wVar15);
      local_68 = list;
      pcVar20 = (list->super).header.chptr;
      do {
        wVar19 = *pwVar16;
        iVar6 = iswprint(wVar19);
        pcVar20->attr = 0;
        pcVar20->chars[0] = L'\0';
        pcVar20->chars[1] = L'\0';
        pcVar20->chars[2] = L'\0';
        if (iVar6 == 0) {
          wVar19 = L'�';
        }
        pwVar16 = pwVar16 + 1;
        pcVar20->attr = wVar1 & 0xffffff;
        *(undefined1 (*) [16])(pcVar20->chars + 2) = (undefined1  [16])0x0;
        pcVar20->chars[0] = wVar19;
        list = local_68;
        pcVar20 = pcVar20 + 1;
      } while (local_d8 + (ulong)(uint)(wVar15 + L'\xffffffff') + 1 != pwVar16);
    }
    pMVar17 = local_60;
                    /* Unresolved local var: size_t i@[???] */
    uVar21 = 0;
    (list->super).needsRedraw = true;
    pMVar22 = local_78->host;
    pHVar3 = pMVar22->usersTable->users;
    if (pHVar3->size != 0) {
      do {
        auStack_88._8_8_ = pMVar22;
        pcVar10 = pHVar3->buckets[uVar21].value;
        if (pcVar10 != (char *)0x0) {
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
          local_60 = (MainPanel_ *)CONCAT44(local_60._4_4_,pHVar3->buckets[uVar21].key);
          pMVar17[-1].idSearch = 0x11a671;
          pMVar17[-1].field_0x270c = 0;
          pMVar17[-1].field_0x270d = 0;
          pMVar17[-1].field_0x270e = 0;
          pMVar17[-1].field_0x270f = 0;
          puVar9 = malloc(0x18);
          if (puVar9 == (undefined8 *)0x0) goto LAB_0011a84b;
                    /* Unresolved local var: char * data@[???] */
          *puVar9 = &ListItem_class;
          pMVar17[-1].idSearch = 0x11a68f;
          pMVar17[-1].field_0x270c = 0;
          pMVar17[-1].field_0x270d = 0;
          pMVar17[-1].field_0x270e = 0;
          pMVar17[-1].field_0x270f = 0;
          pcVar10 = strdup(pcVar10);
          if (pcVar10 == (char *)0x0) goto LAB_0011a84b;
          pVVar4 = (list->super).items;
          puVar9[1] = pcVar10;
          *(undefined1 *)((long)puVar9 + 0x14) = 0;
          wVar1 = pVVar4->items;
          wVar15 = pVVar4->arraySize;
          sVar8 = (size_t)wVar15;
          *(wchar_t *)(puVar9 + 2) = (wchar_t)local_60;
                    /* Unresolved local var: wchar_t oldSize@[???] */
          ptr = pVVar4->array;
          wVar19 = wVar1 + L'\x01';
                    /* Unresolved local var: Object * removed@[???] */
          pMVar18 = (MainPanel_ *)((long)wVar1 << 3);
          if (wVar15 < wVar19) {
            wVar15 = wVar19 + pVVar4->growthRate;
            a3 = 8;
            pVVar4->arraySize = wVar15;
            local_60 = (MainPanel_ *)CONCAT44(local_60._4_4_,wVar19);
            local_6c = wVar1;
            local_68 = (MainPanel_ *)((long)wVar1 << 3);
            pMVar17[-1].idSearch = 0x11a6f2;
            pMVar17[-1].field_0x270c = 0;
            pMVar17[-1].field_0x270d = 0;
            pMVar17[-1].field_0x270e = 0;
            pMVar17[-1].field_0x270f = 0;
            ptr = xReallocArrayZero(ptr,sVar8,(long)wVar15,8);
            pMVar18 = local_68;
            pVVar4->array = ptr;
            wVar19 = (wchar_t)local_60;
            if (pVVar4->items <= local_6c) goto LAB_0011a630;
            plVar11 = (long *)((long)ptr + (long)local_68);
            local_60 = local_68;
            if ((pVVar4->owner != false) && (a0 = (long *)*plVar11, a0 != (long *)0x0)) {
              pcVar5 = *(code **)(*a0 + 0x10);
              pMVar17[-1].idSearch = 0x11a72f;
              pMVar17[-1].field_0x270c = 0;
              pMVar17[-1].field_0x270d = 0;
              pMVar17[-1].field_0x270e = 0;
              pMVar17[-1].field_0x270f = 0;
              (*pcVar5)((long)a0,sVar8,a2,a3,a4,(long)pMVar18);
              plVar11 = (long *)((long)pVVar4->array +
                                (long)(&(local_60->super).header + -1) + 0x2618);
            }
          }
          else {
LAB_0011a630:
                    /* Unresolved local var: HashtableItem * walk@[???]
                       Unresolved local var: char * user@[???]
                       Unresolved local var: Panel * panel@[???]
                       Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
            pVVar4->items = wVar19;
            plVar11 = (long *)((long)ptr + (long)pMVar18);
          }
          *plVar11 = (long)puVar9;
          (list->super).needsRedraw = true;
        }
        uVar21 = uVar21 + 1;
        pMVar22 = (Machine *)auStack_88._8_8_;
      } while (uVar21 < pHVar3->size);
    }
    pVVar4 = (list->super).items;
    pMVar17[-1].idSearch = 0x11a74d;
    pMVar17[-1].field_0x270c = 0;
    pMVar17[-1].field_0x270d = 0;
    pMVar17[-1].field_0x270e = 0;
    pMVar17[-1].field_0x270f = 0;
    Vector_insertionSort(pVVar4);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    pMVar17[-1].idSearch = 0x11a757;
    pMVar17[-1].field_0x270c = 0;
    pMVar17[-1].field_0x270d = 0;
    pMVar17[-1].field_0x270e = 0;
    pMVar17[-1].field_0x270f = 0;
    data_ = malloc(0x18);
    if (data_ != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      data_->klass = &ListItem_class;
      pMVar17[-1].idSearch = 0x11a77a;
      pMVar17[-1].field_0x270c = 0;
      pMVar17[-1].field_0x270d = 0;
      pMVar17[-1].field_0x270e = 0;
      pMVar17[-1].field_0x270f = 0;
      pOVar12 = (ObjectClass *)strdup(((char *)0x1473f1 /* "All users" */));
      if (pOVar12 != (ObjectClass *)0x0) {
        data_[1].klass = pOVar12;
        pVVar4 = (list->super).items;
        *(undefined4 *)&data_[2].klass = 0xffffffff;
        *(undefined1 *)((long)&data_[2].klass + 4) = 0;
        pMVar17[-1].idSearch = 0x11a7a5;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        Vector_insert(pVVar4,L'\0',data_);
        st_00 = local_78;
        (list->super).needsRedraw = true;
        pMVar17[-1].idSearch = 0x11a7bc;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        pOVar13 = Action_pickFromVector(st_00,list,L'\x13',false);
        if (pOVar13 != (Object *)0x0) {
          if (pOVar13 != data_) {
                    /* Unresolved local var: passwd * user@[???] */
            pOVar12 = pOVar13[1].klass;
            pMVar17[-1].idSearch = 0x11a7cf;
            pMVar17[-1].field_0x270c = 0;
            pMVar17[-1].field_0x270d = 0;
            pMVar17[-1].field_0x270e = 0;
            pMVar17[-1].field_0x270f = 0;
            ppVar14 = getpwnam((char *)pOVar12);
            if (ppVar14 != (passwd *)0x0) {
              pMVar22->userId = ppVar14->pw_uid;
              goto LAB_0011a7de;
            }
          }
          pMVar22->userId = 0xffffffff;
        }
LAB_0011a7de:
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
        __ptr = (list->super).eventHandlerState;
        pMVar17[-1].idSearch = 0x11a7e7;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        free(__ptr);
        pVVar4 = (list->super).items;
        pMVar17[-1].idSearch = 0x11a7f0;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        Vector_delete(pVVar4);
        pFVar7 = (list->super).defaultBar;
        pMVar17[-1].idSearch = 0x11a7f9;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        FunctionBar_delete(pFVar7);
        if (L'Ş' < (list->super).header.chlen) {
          pcVar20 = (list->super).header.chptr;
          pMVar17[-1].idSearch = 0x11a849;
          pMVar17[-1].field_0x270c = 0;
          pMVar17[-1].field_0x270d = 0;
          pMVar17[-1].field_0x270e = 0;
          pMVar17[-1].field_0x270f = 0;
          free(pcVar20);
        }
        pMVar17[-1].idSearch = 0x11a80a;
        pMVar17[-1].field_0x270c = 0;
        pMVar17[-1].field_0x270d = 0;
        pMVar17[-1].field_0x270e = 0;
        pMVar17[-1].field_0x270f = 0;
        free(list);
        if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
          return 0x61;
        }
                    /* WARNING: Subroutine does not return */
        *(undefined **)&pMVar17[-1].idSearch = &UNK_0011a85d;
        __stack_chk_fail();
      }
    }
  }
LAB_0011a84b:
                    /* WARNING: Subroutine does not return */
  pMVar17[-1].idSearch = 0x11a850;
  pMVar17[-1].field_0x270c = 0;
  pMVar17[-1].field_0x270d = 0;
  pMVar17[-1].field_0x270e = 0;
  pMVar17[-1].field_0x270f = 0;
  fail();
}

