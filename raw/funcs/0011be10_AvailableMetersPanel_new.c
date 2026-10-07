/* AvailableMetersPanel_new @ 0011be10 size 1235 */

/* WARNING: Removing unreachable block (ram,0x0011bf1b) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff50 : 0x0011bf38 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

AvailableMetersPanel *
AvailableMetersPanel_new
          (Machine_4 *host,Header_3 *header,size_t columns,MetersPanel **meterPanels,
          ScreenManager_2 *scr)

{
  _Bool _Var1;
  wchar_t wVar2;
  long lVar3;
  Hashtable_2 *pHVar4;
  Vector *pVVar5;
  char **ppcVar6;
  Machine_4 *pMVar7;
  wchar_t wVar8;
  int iVar9;
  AvailableMetersPanel *this;
  FunctionBar *fuBar;
  size_t sVar10;
  MeterClass_3 *pMVar11;
  Object *pOVar12;
  ObjectClass *pOVar13;
  undefined8 *puVar14;
  char *pcVar15;
  char ***pppcVar16;
  uint uVar17;
  cchar_t *pcVar18;
  ulong uVar19;
  wchar_t *pwVar20;
  long in_FS_OFFSET;
  wchar_t local_f8 [16];
  char **local_a8;
  Machine_4 *local_a0;
  uint local_94;
  undefined8 *local_90;
  char *local_88;
  wchar_t *local_80;
  char *functions [3];

  pppcVar16 = &local_a8;
                    /* Unresolved local var: void * data@[???] */
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  local_a0 = host;
  this = malloc(0x2708);
  if (this != (AvailableMetersPanel *)0x0) {
    local_a8 = functions;
    (this->super).super.klass = &AvailableMetersPanel_class.super;
    functions[2] = (char *)0x0;
    functions[0] = ((char *)0x14744e /* "Add   " */);
    functions[1] = ((char *)0x147455 /* "Done   " */);
    fuBar = FunctionBar_new(local_a8,FunctionBar_EnterEscKeys,((char *)0x14d258 /* L"\r\x1b" */));
    Panel_init(&this->super,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
    this->header = header;
    this->columns = columns;
    this->host = local_a0;
    this->meterPanels = meterPanels;
    pwVar20 = CRT_colors;
    this->scr = scr;
                    /* Unresolved local var: wchar_t[69118] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_88 = (char *)&local_a8;
    wVar2 = pwVar20[7];
    pwVar20 = local_f8;
    local_88 = (char *)&local_a8;
    sVar10 = mbstowcs(local_f8,((char *)0x14745d /* "Available meters" */),0x10);
    wVar8 = (wchar_t)sVar10;
    if (L'\0' < wVar8) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&(this->super).header,wVar8);
      local_80 = local_f8 + (ulong)(uint)(wVar8 + L'\xffffffff') + 1;
      pcVar18 = (this->super).header.chptr;
      do {
        wVar8 = *pwVar20;
        iVar9 = iswprint(wVar8);
        pcVar18->attr = 0;
        pcVar18->chars[0] = L'\0';
        pcVar18->chars[1] = L'\0';
        pcVar18->chars[2] = L'\0';
        if (iVar9 == 0) {
          wVar8 = L'�';
        }
        pwVar20 = pwVar20 + 1;
        pcVar18->attr = wVar2 & 0xffffff;
        *(undefined1 (*) [16])(pcVar18->chars + 2) = (undefined1  [16])0x0;
        pcVar18->chars[0] = wVar8;
        pcVar18 = pcVar18 + 1;
      } while (pwVar20 != local_80);
    }
    pppcVar16 = (char ***)local_88;
                    /* Unresolved local var: uint i@[???] */
    uVar19 = 1;
    (this->super).needsRedraw = true;
    pMVar11 = &ClockMeter_class;
    do {
      iVar9 = (int)uVar19;
      if (pMVar11 == &DynamicMeter_class) {
                    /* Unresolved local var: DynamicIterator iter@[???]
                       Unresolved local var: Hashtable * dynamicMeters@[???]
                       Unresolved local var: size_t i@[???] */
        uVar19 = 0;
        uVar17 = 1;
        pHVar4 = local_a0->settings->dynamicColumns;
        local_94 = iVar9 << 0x10;
        if (pHVar4->size != 0) {
          do {
            pcVar15 = pHVar4->buckets[uVar19].value;
            if (pcVar15 != (char *)0x0) {
              local_80 = (wchar_t *)CONCAT44(local_80._4_4_,local_94 | uVar17);
              local_88 = *(char **)(pcVar15 + 0x28);
              if ((*(char **)(pcVar15 + 0x28) == (char *)0x0) &&
                 (local_88 = *(char **)(pcVar15 + 0x20), *(char **)(pcVar15 + 0x20) == (char *)0x0))
              {
                local_88 = pcVar15;
              }
                    /* Unresolved local var: HashtableItem * walk@[???]
                       Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: DynamicIterator * iter@[???]
                       Unresolved local var: uint identifier@[???]
                       Unresolved local var: char * label@[???]
                       Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
              *(char *)((long)pppcVar16 + -8) = -0x52;
              *(char *)((long)pppcVar16 + -7) = -0x40;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              puVar14 = malloc(0x18);
              pcVar15 = local_88;
              if (puVar14 == (undefined8 *)0x0) goto LAB_0011c2ea;
                    /* Unresolved local var: char * data@[???] */
              *puVar14 = &ListItem_class;
              local_90 = puVar14;
              *(char *)((long)pppcVar16 + -8) = -0x2c;
              *(char *)((long)pppcVar16 + -7) = -0x40;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              pcVar15 = strdup(pcVar15);
              puVar14 = local_90;
              if (pcVar15 == (char *)0x0) goto LAB_0011c2ea;
              pVVar5 = (this->super).items;
              uVar17 = uVar17 + 1;
              local_90[1] = pcVar15;
              *(undefined1 *)((long)local_90 + 0x14) = 0;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
              wVar2 = pVVar5->items;
              *(undefined4 *)(local_90 + 2) = local_80._0_4_;
              *(char *)((long)pppcVar16 + -8) = '\x02';
              *(char *)((long)pppcVar16 + -7) = -0x3f;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              Vector_set(pVVar5,wVar2,puVar14);
              (this->super).needsRedraw = true;
            }
            uVar19 = uVar19 + 1;
          } while (uVar19 < pHVar4->size);
        }
      }
      else {
                    /* Unresolved local var: MeterClass * type@[???] */
                    /* Unresolved local var: char * label@[???]
                       Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
        pcVar15 = pMVar11->description;
        if (pMVar11->description == (char *)0x0) {
          pcVar15 = pMVar11->uiName;
        }
        *(char *)((long)pppcVar16 + -8) = '\0';
        *(char *)((long)pppcVar16 + -7) = -0x40;
        *(char *)((long)pppcVar16 + -6) = '\x11';
        *(char *)((long)pppcVar16 + -5) = '\0';
        *(char *)((long)pppcVar16 + -4) = '\0';
        *(char *)((long)pppcVar16 + -3) = '\0';
        *(char *)((long)pppcVar16 + -2) = '\0';
        *(char *)((long)pppcVar16 + -1) = '\0';
        puVar14 = malloc(0x18);
        if (puVar14 == (undefined8 *)0x0) goto LAB_0011c2ea;
                    /* Unresolved local var: char * data@[???] */
        *puVar14 = &ListItem_class;
        *(char *)((long)pppcVar16 + -8) = '\x1f';
        *(char *)((long)pppcVar16 + -7) = -0x40;
        *(char *)((long)pppcVar16 + -6) = '\x11';
        *(char *)((long)pppcVar16 + -5) = '\0';
        *(char *)((long)pppcVar16 + -4) = '\0';
        *(char *)((long)pppcVar16 + -3) = '\0';
        *(char *)((long)pppcVar16 + -2) = '\0';
        *(char *)((long)pppcVar16 + -1) = '\0';
        pcVar15 = strdup(pcVar15);
        if (pcVar15 == (char *)0x0) goto LAB_0011c2ea;
        pVVar5 = (this->super).items;
        puVar14[1] = pcVar15;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
        *(int *)(puVar14 + 2) = iVar9 << 0x10;
        *(undefined1 *)((long)puVar14 + 0x14) = 0;
        wVar2 = pVVar5->items;
        *(char *)((long)pppcVar16 + -8) = 'D';
        *(char *)((long)pppcVar16 + -7) = -0x40;
        *(char *)((long)pppcVar16 + -6) = '\x11';
        *(char *)((long)pppcVar16 + -5) = '\0';
        *(char *)((long)pppcVar16 + -4) = '\0';
        *(char *)((long)pppcVar16 + -3) = '\0';
        *(char *)((long)pppcVar16 + -2) = '\0';
        *(char *)((long)pppcVar16 + -1) = '\0';
        Vector_set(pVVar5,wVar2,puVar14);
        (this->super).needsRedraw = true;
      }
      pMVar7 = local_a0;
      uVar19 = (ulong)(iVar9 + 1);
      pMVar11 = (MeterClass_3 *)Platform_meterTypes[uVar19];
    } while (pMVar11 != (MeterClass_3 *)0x0);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    if (local_a0->existingCPUs < 2) {
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      *(char *)((long)pppcVar16 + -8) = -0x5b;
      *(char *)((long)pppcVar16 + -7) = -0x3e;
      *(char *)((long)pppcVar16 + -6) = '\x11';
      *(char *)((long)pppcVar16 + -5) = '\0';
      *(char *)((long)pppcVar16 + -4) = '\0';
      *(char *)((long)pppcVar16 + -3) = '\0';
      *(char *)((long)pppcVar16 + -2) = '\0';
      *(char *)((long)pppcVar16 + -1) = '\0';
      pOVar12 = malloc(0x18);
      if (pOVar12 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
        pOVar12->klass = &ListItem_class;
        *(char *)((long)pppcVar16 + -8) = -0x3c;
        *(char *)((long)pppcVar16 + -7) = -0x3e;
        *(char *)((long)pppcVar16 + -6) = '\x11';
        *(char *)((long)pppcVar16 + -5) = '\0';
        *(char *)((long)pppcVar16 + -4) = '\0';
        *(char *)((long)pppcVar16 + -3) = '\0';
        *(char *)((long)pppcVar16 + -2) = '\0';
        *(char *)((long)pppcVar16 + -1) = '\0';
        pOVar13 = (ObjectClass *)strdup(((char *)0x147826 /* "CPU" */));
        if (pOVar13 != (ObjectClass *)0x0) {
          pOVar12[1].klass = pOVar13;
          *(undefined4 *)&pOVar12[2].klass = 1;
          *(undefined1 *)((long)&pOVar12[2].klass + 4) = 0;
          *(char *)((long)pppcVar16 + -8) = -0x18;
          *(char *)((long)pppcVar16 + -7) = -0x3e;
          *(char *)((long)pppcVar16 + -6) = '\x11';
          *(char *)((long)pppcVar16 + -5) = '\0';
          *(char *)((long)pppcVar16 + -4) = '\0';
          *(char *)((long)pppcVar16 + -3) = '\0';
          *(char *)((long)pppcVar16 + -2) = '\0';
          *(char *)((long)pppcVar16 + -1) = '\0';
          Panel_add(&this->super,pOVar12);
          goto LAB_0011c278;
        }
      }
    }
    else {
      *(char *)((long)pppcVar16 + -8) = 't';
      *(char *)((long)pppcVar16 + -7) = -0x3f;
      *(char *)((long)pppcVar16 + -6) = '\x11';
      *(char *)((long)pppcVar16 + -5) = '\0';
      *(char *)((long)pppcVar16 + -4) = '\0';
      *(char *)((long)pppcVar16 + -3) = '\0';
      *(char *)((long)pppcVar16 + -2) = '\0';
      *(char *)((long)pppcVar16 + -1) = '\0';
      pOVar12 = malloc(0x18);
      if (pOVar12 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
        pOVar12->klass = &ListItem_class;
        *(char *)((long)pppcVar16 + -8) = -0x69;
        *(char *)((long)pppcVar16 + -7) = -0x3f;
        *(char *)((long)pppcVar16 + -6) = '\x11';
        *(char *)((long)pppcVar16 + -5) = '\0';
        *(char *)((long)pppcVar16 + -4) = '\0';
        *(char *)((long)pppcVar16 + -3) = '\0';
        *(char *)((long)pppcVar16 + -2) = '\0';
        *(char *)((long)pppcVar16 + -1) = '\0';
        pOVar13 = (ObjectClass *)strdup(((char *)0x14746e /* "CPU average" */));
        if (pOVar13 != (ObjectClass *)0x0) {
          pOVar12[1].klass = pOVar13;
          *(undefined4 *)&pOVar12[2].klass = 0;
          *(undefined1 *)((long)&pOVar12[2].klass + 4) = 0;
                    /* Unresolved local var: uint i@[???] */
          uVar17 = 1;
          *(char *)((long)pppcVar16 + -8) = -0x2d;
          *(char *)((long)pppcVar16 + -7) = -0x3f;
          *(char *)((long)pppcVar16 + -6) = '\x11';
          *(char *)((long)pppcVar16 + -5) = '\0';
          *(char *)((long)pppcVar16 + -4) = '\0';
          *(char *)((long)pppcVar16 + -3) = '\0';
          *(char *)((long)pppcVar16 + -2) = '\0';
          *(char *)((long)pppcVar16 + -1) = '\0';
          Panel_add(&this->super,pOVar12);
          if (pMVar7->existingCPUs != 0) {
            do {
              ppcVar6 = local_a8;
              _Var1 = local_a0->settings->countCPUsFromOne;
              *(char *)((long)pppcVar16 + -8) = '\x0e';
              *(char *)((long)pppcVar16 + -7) = -0x3e;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              xSnprintf((char *)ppcVar6,0x32,((char *)0x14747a /* "%s %d" */),((char *)0x147826 /* "CPU" */),uVar17 - (_Var1 == false));
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
              *(char *)((long)pppcVar16 + -8) = '\x18';
              *(char *)((long)pppcVar16 + -7) = -0x3e;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              puVar14 = malloc(0x18);
              ppcVar6 = local_a8;
              if (puVar14 == (undefined8 *)0x0) goto LAB_0011c2ea;
                    /* Unresolved local var: char * data@[???] */
              *puVar14 = &ListItem_class;
              *(char *)((long)pppcVar16 + -8) = ':';
              *(char *)((long)pppcVar16 + -7) = -0x3e;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              pcVar15 = strdup((char *)ppcVar6);
              if (pcVar15 == (char *)0x0) goto LAB_0011c2ea;
              pVVar5 = (this->super).items;
              puVar14[1] = pcVar15;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
              *(uint *)(puVar14 + 2) = uVar17;
              uVar17 = uVar17 + 1;
              *(undefined1 *)((long)puVar14 + 0x14) = 0;
              wVar2 = pVVar5->items;
              *(char *)((long)pppcVar16 + -8) = 'c';
              *(char *)((long)pppcVar16 + -7) = -0x3e;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              Vector_set(pVVar5,wVar2,puVar14);
              (this->super).needsRedraw = true;
            } while (uVar17 <= local_a0->existingCPUs);
          }
LAB_0011c278:
          if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
            return this;
          }
                    /* WARNING: Subroutine does not return */
          *(undefined **)((long)pppcVar16 + -8) = &UNK_0011c2f4;
          __stack_chk_fail();
        }
      }
    }
  }
LAB_0011c2ea:
                    /* WARNING: Subroutine does not return */
  *(char *)((long)pppcVar16 + -8) = -0x11;
  *(char *)((long)pppcVar16 + -7) = -0x3e;
  *(char *)((long)pppcVar16 + -6) = '\x11';
  *(char *)((long)pppcVar16 + -5) = '\0';
  *(char *)((long)pppcVar16 + -4) = '\0';
  *(char *)((long)pppcVar16 + -3) = '\0';
  *(char *)((long)pppcVar16 + -2) = '\0';
  *(char *)((long)pppcVar16 + -1) = '\0';
  fail();
}

