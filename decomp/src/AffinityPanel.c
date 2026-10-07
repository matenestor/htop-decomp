#include "htop.h"

/* MaskItem_delete @ 0x1175c0 */

void MaskItem_delete(MaskItem_ *cast)

{
  free(cast->text);
  free(cast->indent);
  Vector_delete(cast->children);
  free(cast);
  return;
}


/* AffinityPanel_delete @ 0x117600 */

void AffinityPanel_delete(AffinityPanel_ *cast)

{
  free((cast->super).eventHandlerState);
  Vector_delete((cast->super).items);
  FunctionBar_delete((cast->super).defaultBar);
  if (350 < (cast->super).header.chlen) {
    free((cast->super).header.chptr);
    (cast->super).header.chptr = (cast->super).header.chstr;
  }
  Vector_delete(cast->cpuids);
  free(cast);
  return;
}


/* AffinityPanel_getAffinity @ 0x117bd0 */

Affinity * AffinityPanel_getAffinity(AffinityPanel_ *super,Machine_2 *host)

{
  uint uVar1;
  uint uVar2;
  Affinity *pAVar3;
  uint *puVar4;
  uint *puVar5;
  Vector *pVVar6;
  long lVar7;

                    /* Unresolved local var: Affinity * this@[???]
                       Unresolved local var: void * data@[???] */
  pAVar3 = calloc(1,0x18);
  if (pAVar3 != (Affinity *)0x0) {
    pAVar3->size = 8;
                    /* Unresolved local var: void * data@[???] */
    puVar4 = calloc(8,4);
    if (puVar4 != (uint *)0x0) {
                    /* Unresolved local var: int i@[???] */
      pVVar6 = super->cpuids;
      pAVar3->host = host;
      lVar7 = 0;
      pAVar3->cpus = puVar4;
      if (0 < pVVar6->items) {
        do {
                    /* Unresolved local var: MaskItem * item@[???] */
          while (*(int *)&pVVar6->array[lVar7][3].klass == 0) {
            lVar7 = lVar7 + 1;
            if (pVVar6->items <= (int)lVar7) {
              return pAVar3;
            }
          }
          uVar1 = *(uint *)&pVVar6->array[lVar7][5].klass;
          uVar2 = pAVar3->used;
          puVar4 = pAVar3->cpus;
          puVar5 = puVar4;
          if (uVar2 == pAVar3->size) {
                    /* Unresolved local var: void * data@[???] */
            pAVar3->size = uVar2 * 2;
            puVar5 = realloc(puVar4,(ulong)(uVar2 * 2) * 4);
            if (puVar5 == (uint *)0x0) {
              free(puVar4);
              goto LAB_00117cdd;
            }
            pAVar3->cpus = puVar5;
            pVVar6 = super->cpuids;
          }
          lVar7 = lVar7 + 1;
          puVar5[uVar2] = uVar1;
          pAVar3->used = uVar2 + 1;
        } while ((int)lVar7 < pVVar6->items);
      }
      return pAVar3;
    }
  }
LAB_00117cdd:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* MaskItem_display @ 0x11adf0 */

void MaskItem_display(MaskItem_ *cast,RichString *out)

{
  char *data;

  RichString_appendAscii(out,CRT_colors[0x41],((char *)(long)&DAT_0014703c /* "[" */));
  if (cast->value == 2) {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)(long)&DAT_00149f75 /* "x" */));
  }
  else if (cast->value == 1) {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)(long)&DAT_001488f9 /* "o" */));
  }
  else {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)(long)&DAT_001470dd /* " " */));
  }
  RichString_appendAscii(out,CRT_colors[0x41],((char *)(long)&DAT_00149a61 /* "]" */));
  RichString_appendAscii(out,CRT_colors[0x43],((char *)(long)&DAT_001470dd /* " " */));
  if (cast->indent != (char *)0x0) {
    RichString_appendWide(out,CRT_colors[0x22],cast->indent);
    if (cast->sub_tree == 2) {
      data = CRT_treeStr[4];
    }
    else {
      data = CRT_treeStr[5];
    }
    RichString_appendWide(out,CRT_colors[0x22],data);
    RichString_appendAscii(out,CRT_colors[0x43],((char *)(long)&DAT_001470dd /* " " */));
  }
  RichString_appendWide(out,CRT_colors[0x43],cast->text);
  return;
}


/* AffinityPanel_update @ 0x11af60 */

/* DWARF original prototype: void AffinityPanel_update(AffinityPanel * this, _Bool keepSelected) */

void AffinityPanel_update(AffinityPanel *this,_Bool keepSelected)

{
  int wVar1;
  int wVar2;
  Vector *from;
  code *pcVar3;
  long in_RCX;
  char *text;
  long in_R8;
  long in_R9;
  int wVar4;

                    /* Unresolved local var: Panel * super@[DW_OP_reg5(RDI)]
                       Unresolved local var: int oldSelected@[???] */
  text = ((char *)(long)&DAT_00149c0c /* "" */);
  if (this->topoView != false) {
    text = ((char *)(long)&s_Collapse_Expand_00147401 /* "Collapse/Expand" */);
  }
  FunctionBar_setLabel((this->super).currentBar,267,text);
  wVar4 = (this->super).selected;
  Vector_prune((this->super).items);
  (this->super).scrollV = 0;
  (this->super).selected = 0;
  (this->super).oldSelected = 0;
  from = this->cpuids;
  (this->super).needsRedraw = true;
  Vector_splice((this->super).items,from);
  (this->super).needsRedraw = true;
  if (keepSelected) {
                    /* Unresolved local var: int size@[???] */
    wVar2 = ((this->super).items)->items;
    wVar1 = wVar2 + -1;
    if (wVar2 <= wVar4) {
      wVar4 = wVar1;
    }
    if (wVar4 < 0) {
      wVar4 = 0;
    }
    pcVar3 = (this->super).super.klass[1].extends;
    (this->super).selected = wVar4;
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)((long)this,0xffffffff,(ulong)(uint)wVar1,in_RCX,in_R8,in_R9);
      (this->super).needsRedraw = true;
      return;
    }
  }
  (this->super).needsRedraw = true;
  return;
}


/* AffinityPanel_eventHandler @ 0x11b030 */

HandlerResult AffinityPanel_eventHandler(AffinityPanel_ *super,int ch)

{
  Vector *pVVar1;
  Object *pOVar2;

  pVVar1 = (super->super).items;
  pOVar2 = (Object *)0x0;
  if (0 < pVVar1->items) {
    pOVar2 = pVVar1->array[(super->super).selected];
  }
  if (ch != 296) {
    if (ch < 297) {
      if (ch == 13) {
        return BREAK_LOOP;
      }
      if (ch != ' ') {
        return (ch == 10) + 2 + (uint)(ch == 10);
      }
    }
    else {
      if (ch == 343) {
        return BREAK_LOOP;
      }
      if (ch != 409) {
        return IGNORED;
      }
    }
  }
  *(uint *)&pOVar2[3].klass = (uint)(*(int *)&pOVar2[3].klass == 0) * 2;
  AffinityPanel_update(super,true);
  return HANDLED;
}


/* AffinityPanel_new @ 0x11b410 */

/* WARNING: Removing unreachable block (ram,0x0011b4f3) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff70 : 0x0011b510 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * AffinityPanel_new(Machine_2 *host,Affinity *affinity,int *width)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  byte bVar1;
  int wVar2;
  long lVar3;
  char *pcVar4;
  int wVar5;
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
  int **ppwVar16;
  uint uVar17;
  int *pwVar18;
  long in_FS_OFFSET = (long)__fake_fs;
  ulong uVar14;

                    /* Unresolved local var: void * data@[???] */
  ppwVar16 = &(*(int *(*))(__fp - 0x88));
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  (*(int *(*))(__fp - 0x88)) = width;
  (*(Affinity *(*))(__fp - 0x80)) = affinity;
  this = malloc(0x2700);
  if (this != (AffinityPanel *)0x0) {
    (this->super).super.klass = &AffinityPanel_class.super;
    fuBar = FunctionBar_new(AffinityPanelFunctions,AffinityPanelKeys,((char *)(long)&AffinityPanelEvents /* L"\r\x1bĉĊċ" */));
    Panel_init(&this->super,1,1,1,1,&MaskItem_class,false,fuBar);
    this->host = host;
    this->width = 0xe;
    pVVar9 = Vector_new(&MaskItem_class,true,-1);
    this->topoView = false;
    this->cpuids = pVVar9;
                    /* Unresolved local var: int[63280] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(char *(*))(__fp - 0x68)) = (char *)&(*(int *(*))(__fp - 0x88));
    wVar2 = CRT_colors[7];
    pwVar18 = (*(int (*) [8])(__fp - 0xb8));
    (*(char *(*))(__fp - 0x68)) = (char *)&(*(int *(*))(__fp - 0x88));
    sVar10 = mbstowcs((*(int (*) [8])(__fp - 0xb8)),((char *)(long)&s_Use_CPUs__00147423 /* "Use CPUs:" */),9);
    wVar5 = (int)sVar10;
    if (0 < wVar5) {
      RichString_setLen(&(this->super).header,wVar5);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      (*(AffinityPanel *(*))(__fp - 0x70)) = this;
      (*(int *(*))(__fp - 0x60)) = (*(int (*) [8])(__fp - 0xb8)) + (ulong)(uint)(wVar5 + -1) + 1;
      (*(Machine_2 *(*))(__fp - 0x78)) = host;
      pcVar15 = (this->super).header.chptr;
      do {
        wVar5 = *pwVar18;
        iVar6 = iswprint(wVar5);
        pcVar15->attr = 0;
        pcVar15->chars[0] = 0;
        pcVar15->chars[1] = 0;
        pcVar15->chars[2] = 0;
        if (iVar6 == 0) {
          wVar5 = 65533;
        }
        pcVar15->attr = wVar2 & 0xffffff;
        pwVar18 = pwVar18 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar15->chars + 2)) = (undefined16)0x0;
        pcVar15->chars[0] = wVar5;
        this = (*(AffinityPanel *(*))(__fp - 0x70));
        pcVar15 = pcVar15 + 1;
        host = (*(Machine_2 *(*))(__fp - 0x78));
      } while ((*(int *(*))(__fp - 0x60)) != pwVar18);
    }
    ppwVar16 = (int **)(*(char *(*))(__fp - 0x68));
                    /* Unresolved local var: uint i@[???] */
    uVar8 = host->existingCPUs;
    (this->super).needsRedraw = true;
    uVar14 = 0;
                    /* Unresolved local var: uint cpu_width@[???]
                       Unresolved local var: _Bool isSet@[???]
                       Unresolved local var: MaskItem * cpuItem@[???] */
    pcVar4 = (*(char *(*))(__fp - 0x68));
    if (uVar8 != 0) {
      (*(Machine_2 *(*))(__fp - 0x78)) = (Machine_2 *)((ulong)(*(Machine_2 *(*))(__fp - 0x78)) & 0xffffffff00000000);
      (*(char *(*))(__fp - 0x68)) = (*(char (*) [16])(__fp - 0x58));
      do {
        pcVar11 = (*(char *(*))(__fp - 0x68));
        uVar8 = (uint)uVar14;
                    /* Unresolved local var: LinuxMachine * this@[???] */
        uVar7 = uVar8 + 1;
        uVar14 = (ulong)uVar7;
        (*(int *(*))(__fp - 0x60)) = (int *)CONCAT44((*(uint *)((char *)&(*(int *(*))(__fp - 0x60)) + 4)),uVar8);
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
          xSnprintf(pcVar11,9,((char *)(long)&s_CPU__d_0014742d /* "CPU %d" */),uVar8);
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
          if (((uint)(*(Machine_2 *(*))(__fp - 0x78)) < (*(Affinity *(*))(__fp - 0x80))->used) &&
             ((*(Affinity *(*))(__fp - 0x80))->cpus[(ulong)(*(Machine_2 *(*))(__fp - 0x78)) & 0xffffffff] == (uint)(*(int *(*))(__fp - 0x60)))) {
            (*(Machine_2 *(*))(__fp - 0x78)) = (Machine_2 *)CONCAT44((*(uint *)((char *)&(*(Machine_2 *(*))(__fp - 0x78)) + 4)),(uint)(*(Machine_2 *(*))(__fp - 0x78)) + 1);
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
          pcVar11 = (*(char *(*))(__fp - 0x68));
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
          (pAVar12->super).h = 10;
          (*(AffinityPanel *(*))(__fp - 0x70)) = pAVar12;
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
                       Unresolved local var: int i@[???] */
          *(uint *)(data_ + 3) = uVar17 * 2;
          ((*(AffinityPanel *(*))(__fp - 0x70))->super).super.klass = pOVar13;
          *(ObjectClass **)&((*(AffinityPanel *(*))(__fp - 0x70))->super).x = &MaskItem_class;
          ((*(AffinityPanel *(*))(__fp - 0x70))->super).w = 10;
          ((*(AffinityPanel *(*))(__fp - 0x70))->super).cursorX = 0;
          ((*(AffinityPanel *(*))(__fp - 0x70))->super).cursorY = -1;
          *(undefined1 *)((long)&((*(AffinityPanel *(*))(__fp - 0x70))->super).items + 4) = 1;
          wVar2 = pVVar9->items;
          *(undefined4 *)&((*(AffinityPanel *(*))(__fp - 0x70))->super).items = 0;
          data_[4] = (*(AffinityPanel *(*))(__fp - 0x70));
          *(uint *)(data_ + 5) = (uint)(*(int *(*))(__fp - 0x60));
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
    if ((*(int *(*))(__fp - 0x88)) != (int *)0x0) {
      *(*(int *(*))(__fp - 0x88)) = this->width;
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

