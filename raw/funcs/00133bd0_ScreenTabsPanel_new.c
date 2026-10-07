/* ScreenTabsPanel_new @ 00133bd0 size 676 */

/* WARNING: Removing unreachable block (ram,0x00133c94) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x00133cb1 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

ScreenTabsPanel * ScreenTabsPanel_new(Settings_3 *settings)

{
  wchar_t wVar1;
  Vector *pVVar2;
  Hashtable_2 *pHVar3;
  wchar_t *__s;
  wchar_t wVar4;
  int iVar5;
  ScreenTabsPanel *this;
  FunctionBar *fuBar;
  ScreenNamesPanel *pSVar6;
  size_t sVar7;
  undefined8 *puVar8;
  char *pcVar9;
  undefined1 *puVar10;
  wchar_t *pwVar11;
  cchar_t *pcVar12;
  ulong uVar13;
  long in_FS_OFFSET;
  wchar_t local_98 [8];
  undefined1 auStack_68 [8];
  Settings_3 *local_60;
  undefined1 *local_58;
  wchar_t *local_50;
  long local_40;

  puVar10 = auStack_68;
                    /* Unresolved local var: void * data@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_60 = settings;
  this = malloc(0x2700);
  if (this != (ScreenTabsPanel *)0x0) {
    (this->super).super.klass = &ScreenTabsPanel_class.super;
    fuBar = FunctionBar_new(ScreenTabsFunctions,(char **)0x0,(wchar_t *)0x0);
    Panel_init(&this->super,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
    this->settings = local_60;
    pSVar6 = ScreenNamesPanel_new(local_60);
    (this->super).cursorOn = false;
    this->names = pSVar6;
    this->cursor = L'\0';
                    /* Unresolved local var: wchar_t[47580] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_58 = auStack_68;
    wVar1 = CRT_colors[7];
    pwVar11 = local_98;
    local_58 = auStack_68;
    sVar7 = mbstowcs(local_98,((char *)0x14917a /* "Screen tabs" */),0xb);
    wVar4 = (wchar_t)sVar7;
    if (L'\0' < wVar4) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&(this->super).header,wVar4);
      local_50 = local_98 + (ulong)(uint)(wVar4 + L'\xffffffff') + 1;
      pcVar12 = (this->super).header.chptr;
      do {
        wVar4 = *pwVar11;
        iVar5 = iswprint(wVar4);
        pcVar12->attr = 0;
        pcVar12->chars[0] = L'\0';
        pcVar12->chars[1] = L'\0';
        pcVar12->chars[2] = L'\0';
        if (iVar5 == 0) {
          wVar4 = L'�';
        }
        pwVar11 = pwVar11 + 1;
        pcVar12->attr = wVar1 & 0xffffff;
        *(undefined1 (*) [16])(pcVar12->chars + 2) = (undefined1  [16])0x0;
        pcVar12->chars[0] = wVar4;
        pcVar12 = pcVar12 + 1;
      } while (pwVar11 != local_50);
    }
    puVar10 = local_58;
    (this->super).needsRedraw = true;
                    /* Unresolved local var: ScreenTabListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    *(undefined8 *)(local_58 + -8) = 0x133d4e;
    puVar8 = malloc(0x20);
    if (puVar8 != (undefined8 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      *puVar8 = &ScreenTabListItem_class;
      *(undefined8 *)(puVar10 + -8) = 0x133d71;
      pcVar9 = strdup(((char *)0x149186 /* "Processes" */));
      if (pcVar9 != (char *)0x0) {
        pVVar2 = (this->super).items;
        puVar8[1] = pcVar9;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
                    /* Unresolved local var: size_t i@[???] */
        uVar13 = 0;
        *(undefined4 *)(puVar8 + 2) = 0;
        *(undefined1 *)((long)puVar8 + 0x14) = 0;
        wVar1 = pVVar2->items;
        puVar8[3] = 0;
        *(undefined8 *)(puVar10 + -8) = 0x133da9;
        Vector_set(pVVar2,wVar1,puVar8);
        (this->super).needsRedraw = true;
        pHVar3 = local_60->dynamicScreens;
        if (pHVar3->size != 0) {
          do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
            pwVar11 = pHVar3->buckets[uVar13].value;
            if (pwVar11 != (wchar_t *)0x0) {
                    /* Unresolved local var: DynamicScreen * screen@[???]
                       Unresolved local var: Panel * super@[???]
                       Unresolved local var: char * name@[???] */
                    /* Unresolved local var: ScreenTabListItem * this@[???]
                       Unresolved local var: void * data@[???] */
              local_50 = *(wchar_t **)(pwVar11 + 8);
              if (*(wchar_t **)(pwVar11 + 8) == (wchar_t *)0x0) {
                local_50 = pwVar11;
              }
              *(undefined8 *)(puVar10 + -8) = 0x133dee;
              puVar8 = malloc(0x20);
              __s = local_50;
              if (puVar8 == (undefined8 *)0x0) goto LAB_00133e6a;
                    /* Unresolved local var: char * data@[???] */
              *puVar8 = &ScreenTabListItem_class;
              *(undefined8 *)(puVar10 + -8) = 0x133e0a;
              pcVar9 = strdup((char *)__s);
              if (pcVar9 == (char *)0x0) goto LAB_00133e6a;
              pVVar2 = (this->super).items;
              puVar8[1] = pcVar9;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
              *(undefined4 *)(puVar8 + 2) = 0;
              *(undefined1 *)((long)puVar8 + 0x14) = 0;
              wVar1 = pVVar2->items;
              puVar8[3] = pwVar11;
              *(undefined8 *)(puVar10 + -8) = 0x133e37;
              Vector_set(pVVar2,wVar1,puVar8);
              (this->super).needsRedraw = true;
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 < pHVar3->size);
        }
        if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
          *(undefined **)(puVar10 + -8) = &UNK_00133e74;
          __stack_chk_fail();
        }
        return this;
      }
    }
  }
LAB_00133e6a:
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar10 + -8) = 0x133e6f;
  fail();
}

