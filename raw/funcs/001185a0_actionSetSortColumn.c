/* actionSetSortColumn @ 001185a0 size 1040 */

/* WARNING: Removing unreachable block (ram,0x00118661) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011867e */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Htop_Reaction actionSetSortColumn(State_2 *st)

{
  _Bool _Var1;
  wchar_t wVar2;
  wchar_t __wc;
  ht_key_t hVar3;
  uint uVar4;
  long lVar5;
  ht_key_t *phVar6;
  Object_Delete p_Var7;
  Vector *this;
  code *pcVar8;
  ObjectClass **ppOVar9;
  Machine *pMVar10;
  Hashtable_2 *pHVar11;
  State_2 *st_00;
  wchar_t wVar12;
  int iVar13;
  FunctionBar *fuBar;
  MainPanel_ *list;
  size_t sVar14;
  Hashtable_2 *pHVar15;
  Object *pOVar16;
  undefined8 *puVar17;
  char *pcVar18;
  char *pcVar19;
  HashtableItem *pHVar20;
  uint uVar21;
  MainPanel_ *pMVar22;
  ScreenSettings_2 *extraout_RDX;
  ScreenSettings_2 *pSVar23;
  wchar_t *pwVar24;
  MainPanel_ *pMVar25;
  MainPanel_ *pMVar26;
  MainPanel_ *pMVar27;
  Hashtable_2 *a5;
  Htop_Reaction HVar28;
  cchar_t *pcVar29;
  long lVar30;
  long in_FS_OFFSET;
  wchar_t local_a8 [4];
  undefined8 uStack_88;
  Machine *local_80;
  State_2 *local_78;
  Hashtable_2 *local_70;
  MainPanel_ *local_68;
  MainPanel_ *local_60;
  char *functions [3];

  pMVar25 = (MainPanel_ *)&uStack_88;
  lVar5 = *(long *)(in_FS_OFFSET + 0x28);
  functions[2] = (char *)0x0;
  functions[0] = ((char *)0x14721b /* "Sort   " */);
  functions[1] = ((char *)0x147223 /* "Cancel " */);
  local_78 = st;
  fuBar = FunctionBar_new(functions,FunctionBar_EnterEscKeys,((char *)0x14d258 /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  list = malloc(0x26e0);
  if (list != (MainPanel_ *)0x0) {
    (list->super).super.klass = &Panel_class.super;
    Panel_init(&list->super,L'\0',L'\0',L'\0',L'\0',&ListItem_class,true,fuBar);
    wVar2 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[33847] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_60 = (MainPanel_ *)&uStack_88;
    pwVar24 = local_a8;
    local_60 = (MainPanel_ *)&uStack_88;
    sVar14 = mbstowcs(local_a8,((char *)0x14722b /* "Sort by" */),7);
    wVar12 = (wchar_t)sVar14;
    if (L'\0' < wVar12) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&(list->super).header,wVar12);
      local_68 = list;
      pcVar29 = (list->super).header.chptr;
      do {
        __wc = *pwVar24;
        iVar13 = iswprint(__wc);
        pcVar29->attr = 0;
        pcVar29->chars[0] = L'\0';
        pcVar29->chars[1] = L'\0';
        pcVar29->chars[2] = L'\0';
        if (iVar13 == 0) {
          __wc = L'�';
        }
        pwVar24 = pwVar24 + 1;
        pcVar29->attr = wVar2 & 0xffffff;
        *(undefined1 (*) [16])(pcVar29->chars + 2) = (undefined1  [16])0x0;
        pcVar29->chars[0] = __wc;
        list = local_68;
        pcVar29 = pcVar29 + 1;
      } while (pwVar24 != local_a8 + (ulong)(uint)(wVar12 + L'\xffffffff') + 1);
    }
    pMVar25 = local_60;
    (list->super).needsRedraw = true;
                    /* Unresolved local var: wchar_t i@[???] */
    lVar30 = 0;
    pMVar27 = (MainPanel_ *)local_78->host->settings;
    a5 = *(Hashtable_2 **)&(pMVar27->super).cursorX;
    phVar6 = (ht_key_t *)(*(ScreenSettings_2 **)&(pMVar27->super).scrollV)->fields;
    hVar3 = *phVar6;
    pMVar10 = local_78->host;
    pMVar22 = pMVar27;
    pHVar11 = a5;
    st_00 = local_78;
    pMVar26 = local_60;
    do {
      while( true ) {
        local_60 = pMVar22;
        local_78 = st_00;
        if (hVar3 == 0) {
          lVar30 = 0;
          HVar28 = 0x61;
          *(undefined8 *)((long)pMVar25 + -8) = 0x118805;
          pMVar26 = list;
          pOVar16 = Action_pickFromVector(st_00,list,L'\x0e',false);
          pMVar27 = local_60;
          pSVar23 = extraout_RDX;
          if (pOVar16 != (Object *)0x0) {
            iVar13 = *(int *)&pOVar16[2].klass;
            lVar30 = (long)iVar13;
            pSVar23 = *(ScreenSettings_2 **)&(local_60->super).scrollV;
            _Var1 = Process_fields[lVar30].defaultSortDesc;
            if ((pSVar23->treeViewAlwaysByPID == false) && (pSVar23->treeView != false)) {
              pSVar23->treeSortKey = iVar13;
              pSVar23->treeDirection = (-(uint)(_Var1 == false) & 2) + L'\xffffffff';
            }
            else {
              pSVar23->sortKey = iVar13;
              pSVar23->treeView = false;
              pSVar23->direction = (-(uint)(_Var1 == false) & 2) + L'\xffffffff';
            }
            HVar28 = 0x6d;
          }
          p_Var7 = ((list->super).super.klass)->delete;
          *(undefined8 *)((long)pMVar25 + -8) = 0x11885b;
          (*p_Var7)((Object *)list,(long)pMVar26,(long)pSVar23,lVar30,(long)pMVar27,(long)a5);
          pMVar10->activeTable->needsSort = true;
          if (lVar5 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
            *(undefined **)((long)pMVar25 + -8) = &UNK_001189c2;
            __stack_chk_fail();
          }
          return HVar28;
        }
                    /* Unresolved local var: char * name@[???] */
        local_80 = pMVar10;
        local_70 = pHVar11;
        local_68 = local_60;
        if ((int)hVar3 < 0x84) break;
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        pMVar27 = (MainPanel_ *)pHVar11->size;
        a5 = (Hashtable_2 *)pHVar11->buckets;
        pMVar22 = (MainPanel_ *)((ulong)(long)(int)hVar3 % (ulong)pMVar27);
        pcVar19 = (char *)((Hashtable_2 *)(&a5->size + (long)pMVar22 * 3))->items;
        if (pcVar19 != (char *)0x0) {
          pHVar20 = (HashtableItem *)0x0;
          pHVar15 = (Hashtable_2 *)(&a5->size + (long)pMVar22 * 3);
          do {
            while( true ) {
              if (hVar3 == (ht_key_t)pHVar15->size) {
                pcVar18 = *(char **)(pcVar19 + 0x28);
                if (*(char **)(pcVar19 + 0x28) == (char *)0x0) {
                  pcVar18 = pcVar19;
                }
                    /* Unresolved local var: char * data@[???] */
                local_60 = pMVar26;
                *(undefined8 *)((long)pMVar25 + -8) = 0x118993;
                pcVar19 = strdup(pcVar18);
                if (pcVar19 != (char *)0x0) goto LAB_001188a6;
                goto LAB_0011899f;
              }
              if (pHVar15->buckets < pHVar20) goto LAB_001187d0;
              ppOVar9 = &(pMVar22->super).super.klass;
              pMVar22 = (MainPanel_ *)((long)ppOVar9 + 1);
              if (pMVar27 != pMVar22) break;
              pMVar22 = (MainPanel_ *)0x0;
              pHVar20 = (HashtableItem *)((long)&pHVar20->key + 1);
              pcVar19 = (char *)a5->items;
              pHVar15 = a5;
              if (pcVar19 == (char *)0x0) goto LAB_001187d0;
            }
            pHVar20 = (HashtableItem *)((long)&pHVar20->key + 1);
            pHVar15 = (Hashtable_2 *)(&a5->owner + (long)ppOVar9 * 0x18);
            pcVar19 = (char *)pHVar15->items;
          } while (pcVar19 != (char *)0x0);
        }
LAB_001187d0:
        lVar30 = lVar30 + 1;
        hVar3 = phVar6[lVar30];
        pMVar22 = local_60;
      }
      pcVar19 = Process_fields[(int)hVar3].name;
      local_60 = pMVar26;
      *(undefined8 *)((long)pMVar25 + -8) = 0x1188a3;
      pcVar19 = String_trim(pcVar19);
LAB_001188a6:
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      hVar3 = phVar6[lVar30];
      *(undefined8 *)((long)pMVar25 + -8) = 0x1188b4;
      puVar17 = malloc(0x18);
      if (puVar17 == (undefined8 *)0x0) break;
                    /* Unresolved local var: char * data@[???] */
      *puVar17 = &ListItem_class;
      local_60 = (MainPanel_ *)puVar17;
      *(undefined8 *)((long)pMVar25 + -8) = 0x1188d6;
      pcVar18 = strdup(pcVar19);
      pMVar26 = local_60;
      if (pcVar18 == (char *)0x0) break;
      this = (list->super).items;
      *(char **)((long)local_60 + 8) = pcVar18;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
      wVar2 = this->items;
      *(ht_key_t *)((long)local_60 + 0x10) = hVar3;
      *(undefined1 *)((long)local_60 + 0x14) = 0;
      *(undefined8 *)((long)pMVar25 + -8) = 0x1188fb;
      Vector_set(this,wVar2,pMVar26);
      (list->super).needsRedraw = true;
      uVar4 = phVar6[lVar30];
      pSVar23 = *(ScreenSettings_2 **)&(local_68->super).scrollV;
      if (pSVar23->treeView == false) {
        uVar21 = pSVar23->sortKey;
      }
      else {
        uVar21 = 1;
        if (pSVar23->treeViewAlwaysByPID == false) {
          uVar21 = pSVar23->treeSortKey;
        }
      }
      if (uVar4 == uVar21) {
                    /* Unresolved local var: wchar_t size@[???] */
        wVar2 = ((list->super).items)->items;
        wVar12 = wVar2 + L'\xffffffff';
        if ((wchar_t)lVar30 < wVar2) {
          wVar12 = (wchar_t)lVar30;
        }
        if (wVar12 < L'\0') {
          wVar12 = L'\0';
        }
        (list->super).selected = wVar12;
        pcVar8 = (list->super).super.klass[1].extends;
        if (pcVar8 != (code *)0x0) {
          *(undefined8 *)((long)pMVar25 + -8) = 0x118978;
          (*pcVar8)((long)list,0xffffffff,0,(ulong)uVar4,(long)pMVar27,(long)a5);
        }
      }
      lVar30 = lVar30 + 1;
      *(undefined8 *)((long)pMVar25 + -8) = 0x11892f;
      free(pcVar19);
      hVar3 = phVar6[lVar30];
      pMVar10 = local_80;
      pMVar22 = local_68;
      pHVar11 = local_70;
      st_00 = local_78;
      pMVar26 = local_60;
    } while( true );
  }
LAB_0011899f:
                    /* WARNING: Subroutine does not return */
  *(undefined **)((long)pMVar25 + -8) = &UNK_001189a4;
  fail();
}

