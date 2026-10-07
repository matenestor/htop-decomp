/* AffinityPanel_new @ 0011b410 size 896 */

/* WARNING: Removing unreachable block (ram,0x0011b4f3) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011b510 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * AffinityPanel_new(Machine_2 *host,Affinity *affinity,wchar_t *width)

{
  byte bVar1;
  wchar_t wVar2;
  long lVar3;
  char *pcVar4;
  wchar_t wVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  AffinityPanel *this;
  FunctionBar *fuBar;
  Vector *pVVar9;
  size_t sVar10;
  undefined8 *data_;
  char *pcVar11;
  AffinityPanel *pAVar12;
  ObjectClass *pOVar13;
  cchar_t *pcVar15;
  wchar_t **ppwVar16;
  uint uVar17;
  wchar_t *pwVar18;
  long in_FS_OFFSET;
  wchar_t local_b8 [8];
  wchar_t *local_88;
  Affinity *local_80;
  Machine_2 *local_78;
  AffinityPanel *local_70;
  char *local_68;
  wchar_t *local_60;
  char number [16];
  ulong uVar14;

                    /* Unresolved local var: void * data@[???] */
  ppwVar16 = &local_88;
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  local_88 = width;
  local_80 = affinity;
  this = malloc(0x2700);
  if (this != (AffinityPanel *)0x0) {
    (this->super).super.klass = &AffinityPanel_class.super;
    fuBar = FunctionBar_new(AffinityPanelFunctions,AffinityPanelKeys,((char *)0x14d240 /* L"\r\x1bĉĊċ" */));
    Panel_init(&this->super,L'\x01',L'\x01',L'\x01',L'\x01',&MaskItem_class,false,fuBar);
    this->host = host;
    this->width = 0xe;
    pVVar9 = Vector_new(&MaskItem_class,true,L'\xffffffff');
    this->topoView = false;
    this->cpuids = pVVar9;
                    /* Unresolved local var: wchar_t[63280] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_68 = (char *)&local_88;
    wVar2 = CRT_colors[7];
    pwVar18 = local_b8;
    local_68 = (char *)&local_88;
    sVar10 = mbstowcs(local_b8,((char *)0x147423 /* "Use CPUs:" */),9);
    wVar5 = (wchar_t)sVar10;
    if (L'\0' < wVar5) {
      RichString_setLen(&(this->super).header,wVar5);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      local_70 = this;
      local_60 = local_b8 + (ulong)(uint)(wVar5 + L'\xffffffff') + 1;
      local_78 = host;
      pcVar15 = (this->super).header.chptr;
      do {
        wVar5 = *pwVar18;
        iVar6 = iswprint(wVar5);
        pcVar15->attr = 0;
        pcVar15->chars[0] = L'\0';
        pcVar15->chars[1] = L'\0';
        pcVar15->chars[2] = L'\0';
        if (iVar6 == 0) {
          wVar5 = L'�';
        }
        pcVar15->attr = wVar2 & 0xffffff;
        pwVar18 = pwVar18 + 1;
        *(undefined1 (*) [16])(pcVar15->chars + 2) = (undefined1  [16])0x0;
        pcVar15->chars[0] = wVar5;
        this = local_70;
        pcVar15 = pcVar15 + 1;
        host = local_78;
      } while (local_60 != pwVar18);
    }
    ppwVar16 = (wchar_t **)local_68;
                    /* Unresolved local var: uint i@[???] */
    uVar8 = host->existingCPUs;
    (this->super).needsRedraw = true;
    uVar14 = 0;
                    /* Unresolved local var: uint cpu_width@[???]
                       Unresolved local var: _Bool isSet@[???]
                       Unresolved local var: MaskItem * cpuItem@[???] */
    pcVar4 = local_68;
    if (uVar8 != 0) {
      local_78 = (Machine_2 *)((ulong)local_78 & 0xffffffff00000000);
      local_68 = number;
      do {
        pcVar11 = local_68;
        uVar8 = (uint)uVar14;
                    /* Unresolved local var: LinuxMachine * this@[???] */
        uVar7 = uVar8 + 1;
        uVar14 = (ulong)uVar7;
        local_60 = (wchar_t *)CONCAT44(local_60._4_4_,uVar8);
        bVar1 = *(byte *)(host[1].iterationsRemaining + uVar14 * 0xd8 + 0xd0);
        uVar17 = (uint)bVar1;
        if (bVar1 != 0) {
          if (host->settings->countCPUsFromOne != false) {
            uVar8 = uVar7;
          }
          pcVar4[-8] = '\n';
          pcVar4[-7] = -0x49;
          pcVar4[-6] = '\x11';
          pcVar4[-5] = '\0';
          pcVar4[-4] = '\0';
          pcVar4[-3] = '\0';
          pcVar4[-2] = '\0';
          pcVar4[-1] = '\0';
          xSnprintf(pcVar11,9,((char *)0x14742d /* "CPU %d" */),uVar8);
          pcVar4[-8] = '\x12';
          pcVar4[-7] = -0x49;
          pcVar4[-6] = '\x11';
          pcVar4[-5] = '\0';
          pcVar4[-4] = '\0';
          pcVar4[-3] = '\0';
          pcVar4[-2] = '\0';
          pcVar4[-1] = '\0';
          sVar10 = strlen(pcVar11);
          uVar8 = (int)sVar10 + 4;
          if (this->width < uVar8) {
            this->width = uVar8;
          }
          if (((uint)local_78 < local_80->used) &&
             (local_80->cpus[(ulong)local_78 & 0xffffffff] == (uint)local_60)) {
            local_78 = (Machine_2 *)CONCAT44(local_78._4_4_,(uint)local_78 + 1);
          }
          else {
            uVar17 = 0;
          }
                    /* Unresolved local var: MaskItem * this@[???]
                       Unresolved local var: void * data@[???] */
          pcVar4[-8] = -0x1b;
          pcVar4[-7] = -0x4b;
          pcVar4[-6] = '\x11';
          pcVar4[-5] = '\0';
          pcVar4[-4] = '\0';
          pcVar4[-3] = '\0';
          pcVar4[-2] = '\0';
          pcVar4[-1] = '\0';
          data_ = malloc(0x30);
          pcVar11 = local_68;
          if (data_ == (undefined8 *)0x0) goto LAB_0011b78e;
                    /* Unresolved local var: char * data@[???] */
          *data_ = &MaskItem_class;
          pcVar4[-8] = '\x05';
          pcVar4[-7] = -0x4a;
          pcVar4[-6] = '\x11';
          pcVar4[-5] = '\0';
          pcVar4[-4] = '\0';
          pcVar4[-3] = '\0';
          pcVar4[-2] = '\0';
          pcVar4[-1] = '\0';
          pcVar11 = strdup(pcVar11);
          if (pcVar11 == (char *)0x0) goto LAB_0011b78e;
          data_[1] = pcVar11;
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
          data_[2] = 0;
          *(undefined4 *)((long)data_ + 0x1c) = 0;
          pcVar4[-8] = ',';
          pcVar4[-7] = -0x4a;
          pcVar4[-6] = '\x11';
          pcVar4[-5] = '\0';
          pcVar4[-4] = '\0';
          pcVar4[-3] = '\0';
          pcVar4[-2] = '\0';
          pcVar4[-1] = '\0';
          pAVar12 = malloc(0x28);
          if (pAVar12 == (AffinityPanel *)0x0) goto LAB_0011b78e;
                    /* Unresolved local var: void * data@[???] */
          (pAVar12->super).h = L'\n';
          local_70 = pAVar12;
          pcVar4[-8] = 'O';
          pcVar4[-7] = -0x4a;
          pcVar4[-6] = '\x11';
          pcVar4[-5] = '\0';
          pcVar4[-4] = '\0';
          pcVar4[-3] = '\0';
          pcVar4[-2] = '\0';
          pcVar4[-1] = '\0';
          pOVar13 = calloc(10,8);
          if (pOVar13 == (ObjectClass *)0x0) goto LAB_0011b78e;
          pVVar9 = this->cpuids;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
          *(uint *)(data_ + 3) = uVar17 * 2;
          (local_70->super).super.klass = pOVar13;
          *(ObjectClass **)&(local_70->super).x = &MaskItem_class;
          (local_70->super).w = L'\n';
          (local_70->super).cursorX = L'\0';
          (local_70->super).cursorY = L'\xffffffff';
          *(undefined1 *)((long)&(local_70->super).items + 4) = 1;
          wVar2 = pVVar9->items;
          *(undefined4 *)&(local_70->super).items = 0;
          data_[4] = local_70;
          *(uint *)(data_ + 5) = (uint)local_60;
          pcVar4[-8] = -0x55;
          pcVar4[-7] = -0x4a;
          pcVar4[-6] = '\x11';
          pcVar4[-5] = '\0';
          pcVar4[-4] = '\0';
          pcVar4[-3] = '\0';
          pcVar4[-2] = '\0';
          pcVar4[-1] = '\0';
          Vector_set(pVVar9,wVar2,data_);
        }
      } while (uVar7 < host->existingCPUs);
    }
    if (local_88 != (wchar_t *)0x0) {
      *local_88 = this->width;
    }
    pcVar4[-8] = 'm';
    pcVar4[-7] = -0x49;
    pcVar4[-6] = '\x11';
    pcVar4[-5] = '\0';
    pcVar4[-4] = '\0';
    pcVar4[-3] = '\0';
    pcVar4[-2] = '\0';
    pcVar4[-1] = '\0';
    AffinityPanel_update(this,false);
    if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
      return &this->super;
    }
                    /* WARNING: Subroutine does not return */
    *(undefined **)((long)ppwVar16 + -8) = &UNK_0011b798;
    __stack_chk_fail();
  }
LAB_0011b78e:
                    /* WARNING: Subroutine does not return */
  *(char *)((long)ppwVar16 + -8) = -0x6d;
  *(char *)((long)ppwVar16 + -7) = -0x49;
  *(char *)((long)ppwVar16 + -6) = '\x11';
  *(char *)((long)ppwVar16 + -5) = '\0';
  *(char *)((long)ppwVar16 + -4) = '\0';
  *(char *)((long)ppwVar16 + -3) = '\0';
  *(char *)((long)ppwVar16 + -2) = '\0';
  *(char *)((long)ppwVar16 + -1) = '\0';
  fail();
}

