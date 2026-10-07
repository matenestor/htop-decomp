/* Scheduling_newPolicyPanel @ 00133160 size 709 */

/* WARNING: Removing unreachable block (ram,0x0013321f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff80 : 0x0013323c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * Scheduling_newPolicyPanel(wchar_t preSelectedPolicy)

{
  wchar_t wVar1;
  long lVar2;
  Vector *pVVar3;
  code *pcVar4;
  wchar_t *__s;
  int iVar5;
  wchar_t wVar6;
  FunctionBar *fuBar;
  Panel *this;
  size_t sVar7;
  undefined8 *puVar8;
  wchar_t *pwVar9;
  SchedulingPolicy *pSVar10;
  undefined1 *puVar11;
  long a4;
  ObjectClass *a5;
  wchar_t wVar12;
  char *pcVar13;
  cchar_t *pcVar14;
  long in_FS_OFFSET;
  wchar_t local_a8 [8];
  undefined1 auStack_78 [8];
  undefined1 *local_70;
  wchar_t local_64;
  wchar_t *local_60;
  char *functions [3];

  puVar11 = auStack_78;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  functions[2] = (char *)0x0;
  functions[0] = ((char *)0x149166 /* "Select " */);
  functions[1] = ((char *)0x147223 /* "Cancel " */);
  local_64 = preSelectedPolicy;
  fuBar = FunctionBar_new(functions,FunctionBar_EnterEscKeys,((char *)0x14d258 /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  this = malloc(0x26e0);
  if (this != (Panel *)0x0) {
    a4 = 0;
    a5 = &ListItem_class;
    (this->super).klass = &Panel_class.super;
    Panel_init(this,L'\0',L'\0',L'\0',L'\0',&ListItem_class,true,fuBar);
    wVar1 = CRT_colors[7];
                    /* Unresolved local var: wchar_t[41750] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_70 = auStack_78;
    pwVar9 = local_a8;
    local_70 = auStack_78;
    sVar7 = mbstowcs(local_a8,((char *)0x14916e /* "New policy:" */),0xb);
    wVar12 = (wchar_t)sVar7;
    if (L'\0' < wVar12) {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      RichString_setLen(&this->header,wVar12);
      local_60 = local_a8 + (ulong)(uint)(wVar12 + L'\xffffffff') + 1;
      pcVar14 = (this->header).chptr;
      do {
        wVar12 = *pwVar9;
        iVar5 = iswprint(wVar12);
        pcVar14->attr = 0;
        pcVar14->chars[0] = L'\0';
        pcVar14->chars[1] = L'\0';
        pcVar14->chars[2] = L'\0';
        if (iVar5 == 0) {
          wVar12 = L'�';
        }
        pcVar14->attr = wVar1 & 0xffffff;
        pwVar9 = pwVar9 + 1;
        *(undefined1 (*) [16])(pcVar14->chars + 2) = (undefined1  [16])0x0;
        pcVar14->chars[0] = wVar12;
        pcVar14 = pcVar14 + 1;
      } while (local_60 != pwVar9);
    }
    puVar11 = local_70;
    this->needsRedraw = true;
    pcVar13 = ((char *)0x1473b8 /* "Reset on fork: off" */);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    if (reset_on_fork != false) {
      pcVar13 = ((char *)0x1473a6 /* "Reset on fork: on" */);
    }
    *(undefined8 *)(local_70 + -8) = 0x1332ee;
    puVar8 = malloc(0x18);
    if (puVar8 != (undefined8 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      *puVar8 = &ListItem_class;
      *(undefined8 *)(puVar11 + -8) = 0x13330c;
      pcVar13 = strdup(pcVar13);
      if (pcVar13 != (char *)0x0) {
        pVVar3 = this->items;
        puVar8[1] = pcVar13;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
                    /* Unresolved local var: uint i@[???] */
        wVar12 = L'\0';
        *(undefined4 *)(puVar8 + 2) = 0xffffffff;
        *(undefined1 *)((long)puVar8 + 0x14) = 0;
        wVar1 = pVVar3->items;
        pSVar10 = policies;
        *(undefined8 *)(puVar11 + -8) = 0x13333e;
        Vector_set(pVVar3,wVar1,puVar8);
        this->needsRedraw = true;
        do {
          pwVar9 = (wchar_t *)pSVar10->name;
          local_60 = pwVar9;
          if (pwVar9 != (wchar_t *)0x0) {
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
            wVar1 = pSVar10->id;
            *(undefined8 *)(puVar11 + -8) = 0x133362;
            puVar8 = malloc(0x18);
            __s = local_60;
            if (puVar8 == (undefined8 *)0x0) break;
                    /* Unresolved local var: char * data@[???] */
            *puVar8 = &ListItem_class;
            *(undefined8 *)(puVar11 + -8) = 0x133381;
            pcVar13 = strdup((char *)__s);
            if (pcVar13 == (char *)0x0) break;
            pVVar3 = this->items;
            puVar8[1] = pcVar13;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
            *(wchar_t *)(puVar8 + 2) = wVar1;
            *(undefined1 *)((long)puVar8 + 0x14) = 0;
            wVar6 = pVVar3->items;
            *(undefined8 *)(puVar11 + -8) = 0x1333a7;
            Vector_set(pVVar3,wVar6,puVar8);
            this->needsRedraw = true;
            if (wVar1 == local_64) {
                    /* Unresolved local var: wchar_t size@[???] */
              wVar1 = this->items->items;
              wVar6 = wVar1 + L'\xffffffff';
              if (wVar12 < wVar1) {
                wVar6 = wVar12;
              }
              if (wVar6 < L'\0') {
                wVar6 = L'\0';
              }
              this->selected = wVar6;
              pcVar4 = (this->super).klass[1].extends;
              if (pcVar4 != (code *)0x0) {
                *(undefined8 *)(puVar11 + -8) = 0x13341d;
                (*pcVar4)((long)this,0xffffffff,0,(long)pwVar9,a4,(long)a5);
              }
            }
          }
          wVar12 = wVar12 + L'\x01';
          pSVar10 = pSVar10 + 1;
          if (wVar12 == L'\x06') {
            if (lVar2 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
              *(undefined **)(puVar11 + -8) = &UNK_00133429;
              __stack_chk_fail();
            }
            return this;
          }
        } while( true );
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  *(undefined8 *)(puVar11 + -8) = 0x133424;
  fail();
}

