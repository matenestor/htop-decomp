#include "htop.h"

/* IOPriorityPanel_getIOPriority @ 0x13af30 */

/* DWARF original prototype: IOPriority IOPriorityPanel_getIOPriority(Panel * this) */

IOPriority IOPriorityPanel_getIOPriority(Panel *this)

{
  Object *pOVar1;
  IOPriority IVar2;

  IVar2 = 0;
  if ((0 < this->items->items) &&
     (pOVar1 = this->items->array[this->selected], IVar2 = 0, pOVar1 != (Object *)0x0)) {
    IVar2 = *(IOPriority *)&pOVar1[2].klass;
  }
  return IVar2;
}


/* IOPriorityPanel_new @ 0x140f60 */

/* WARNING: Removing unreachable block (ram,0x0014102f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff60 : 0x0014104c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * IOPriorityPanel_new(IOPriority currPrio)

{
  undefined1 __frame[0x168] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x128;
  int __wc;
  long lVar1;
  Vector *this;
  code *pcVar2;
  int len;
  int iVar3;
  int wVar4;
  FunctionBar *fuBar;
  Panel *this_00;
  size_t sVar5;
  Object *pOVar6;
  ObjectClass *pOVar7;
  undefined8 *puVar8;
  char *pcVar9;
  Panel *va0;
  long a2;
  int *pwVar10;
  char ***pppcVar11;
  long a4;
  ulong a4_00;
  ObjectClass *pOVar12;
  char *va2;
  uint uVar13;
  cchar_t *pcVar14;
  uint va1;
  char **buf;
  anon_struct_16_2_f5102bc2 *paVar15;
  long in_FS_OFFSET = (long)__fake_fs;

  pppcVar11 = &(*(char **(*))(__fp - 0x98));
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  (*(char *(*) [3])(__fp - 0x78))[2] = (char *)0x0;
  (*(char *(*) [3])(__fp - 0x78))[0] = ((char *)(long)&s_Set_00147e48 /* "Set    " */);
  (*(char *(*) [3])(__fp - 0x78))[1] = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  (*(uint (*))(__fp - 0x84)) = currPrio;
  fuBar = FunctionBar_new((*(char *(*) [3])(__fp - 0x78)),FunctionBar_EnterEscKeys,((char *)(long)&FunctionBar_EnterEscEvents /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  this_00 = malloc(0x26e0);
  if (this_00 != (Panel *)0x0) {
    pOVar12 = &ListItem_class;
    a4 = 1;
    (this_00->super).klass = &Panel_class.super;
    Panel_init(this_00,1,1,1,1,&ListItem_class,true,fuBar);
                    /* Unresolved local var: int[46913] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(undefined8 *(*))(__fp - 0x80)) = &(*(char **(*))(__fp - 0x98));
    wVar4 = CRT_colors[7];
    pwVar10 = (*(int (*) [12])(__fp - 0xd8));
    (*(undefined8 *(*))(__fp - 0x80)) = &(*(char **(*))(__fp - 0x98));
    sVar5 = mbstowcs((*(int (*) [12])(__fp - 0xd8)),((char *)(long)&s_IO_Priority__00149e22 /* "IO Priority:" */),0xc);
    len = (int)sVar5;
    buf = (*(char *(*) [3])(__fp - 0x78));
    if (0 < len) {
      RichString_setLen(&this_00->header,len);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      (*(char **(*))(__fp - 0x98)) = (*(char *(*) [3])(__fp - 0x78));
      fuBar = (FunctionBar *)(ulong)(uint)(wVar4 & 0xffffffU);
      (*(Panel *(*))(__fp - 0x90)) = this_00;
      pcVar14 = (this_00->header).chptr;
      do {
        __wc = *pwVar10;
        iVar3 = iswprint(__wc);
        pcVar14->attr = 0;
        pcVar14->chars[0] = 0;
        pcVar14->chars[1] = 0;
        pcVar14->chars[2] = 0;
        if (iVar3 == 0) {
          __wc = 65533;
        }
        pwVar10 = pwVar10 + 1;
        pcVar14->attr = wVar4 & 0xffffffU;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar14->chars + 2)) = (undefined16)0x0;
        pcVar14->chars[0] = __wc;
        this_00 = (*(Panel *(*))(__fp - 0x90));
        pcVar14 = pcVar14 + 1;
        buf = (*(char **(*))(__fp - 0x98));
      } while ((*(int (*) [12])(__fp - 0xd8)) + (ulong)(uint)(len + -1) + 1 != pwVar10);
    }
    pppcVar11 = (char ***)(*(undefined8 *(*))(__fp - 0x80));
    this_00->needsRedraw = true;
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    pOVar6 = malloc(0x18);
    if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      pOVar6->klass = &ListItem_class;
      pOVar7 = (ObjectClass *)strdup(((char *)(long)&s_None__based_on_nice__00149e2f /* "None (based on nice)" */));
      if (pOVar7 != (ObjectClass *)0x0) {
        pOVar6[1].klass = pOVar7;
        *(undefined4 *)&pOVar6[2].klass = 0;
        *(undefined1 *)((long)&pOVar6[2].klass + 4) = 0;
        Panel_add(this_00,pOVar6);
        if ((*(uint (*))(__fp - 0x84)) == 0) {
                    /* Unresolved local var: int size@[???] */
          pOVar7 = (this_00->super).klass;
          this_00->selected = 0;
          pcVar2 = pOVar7[1].extends;
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)((long)this_00,0xffffffff,a2,(long)fuBar,a4,(long)pOVar12);
          }
        }
                    /* Unresolved local var: int c@[???] */
        paVar15 = classes;
        pcVar9 = ((char *)(long)&s_Realtime_00149e19 /* "Realtime" */);
        do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: IOPriority ioprio@[???] */
          a4_00 = 0;
          va2 = ((char *)(long)&s__High__00149e12 /* "(High)" */);
          (*(Panel *(*))(__fp - 0x90)) = (Panel *)pcVar9;
          while( true ) {
            va0 = (*(Panel *(*))(__fp - 0x90));
            va1 = (uint)a4_00;
            xSnprintf((char *)buf,0x32,((char *)(long)&s__s__d__s_00149e44 /* "%s %d %s" */),va0,va1,va2);
            wVar4 = paVar15->klass;
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
            puVar8 = malloc(0x18);
            uVar13 = wVar4 << 0xd | va1;
            if (puVar8 == (undefined8 *)0x0) goto LAB_00141360;
                    /* Unresolved local var: char * data@[???] */
            *puVar8 = &ListItem_class;
            (*(undefined8 *(*))(__fp - 0x80)) = puVar8;
            pcVar9 = strdup((char *)buf);
            puVar8 = (*(undefined8 *(*))(__fp - 0x80));
            if (pcVar9 == (char *)0x0) goto LAB_00141360;
            this = this_00->items;
            (*(undefined8 *(*))(__fp - 0x80))[1] = pcVar9;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
            wVar4 = this->items;
            *(uint *)((*(undefined8 *(*))(__fp - 0x80)) + 2) = uVar13;
            *(undefined1 *)((long)(*(undefined8 *(*))(__fp - 0x80)) + 0x14) = 0;
            Vector_set(this,wVar4,puVar8);
            this_00->needsRedraw = true;
            if ((*(uint (*))(__fp - 0x84)) == uVar13) {
                    /* Unresolved local var: int size@[???] */
              wVar4 = this_00->items->items + -1;
              if (wVar4 < 0) {
                wVar4 = 0;
              }
              this_00->selected = wVar4;
              pcVar2 = (this_00->super).klass[1].extends;
              if (pcVar2 != (code *)0x0) {
                (*pcVar2)((long)this_00,0xffffffff,0,(long)va0,a4_00,(long)va2);
              }
            }
            if (va1 == 7) break;
            a4_00 = (ulong)(va1 + 1);
            va2 = ((char *)(long)&s__Low__00149e0c /* "(Low)" */);
            if (va1 + 1 != 7) {
              va2 = ((char *)(long)&DAT_00149c0c /* "" */);
            }
          }
          pcVar9 = paVar15[1].name;
          paVar15 = paVar15 + 1;
        } while ((Panel *)pcVar9 != (Panel *)0x0);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
        pOVar6 = malloc(0x18);
        if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
          pOVar6->klass = &ListItem_class;
          pOVar12 = (ObjectClass *)strdup(((char *)(long)&DAT_0014825a /* "Idle" */));
          if (pOVar12 != (ObjectClass *)0x0) {
            pOVar6[1].klass = pOVar12;
            *(undefined4 *)&pOVar6[2].klass = 0x6007;
            *(undefined1 *)((long)&pOVar6[2].klass + 4) = 0;
            Panel_add(this_00,pOVar6);
            if ((*(uint (*))(__fp - 0x84)) == 0x6007) {
                    /* Unresolved local var: int size@[???] */
              wVar4 = this_00->items->items + -1;
              if (wVar4 < 0) {
                wVar4 = 0;
              }
              this_00->selected = wVar4;
              pcVar2 = (this_00->super).klass[1].extends;
              if (pcVar2 != (code *)0x0) {
                (*pcVar2)((long)this_00,0xffffffff,0,(long)pcVar9,a4_00,(long)va2);
              }
            }
            if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
              return this_00;
            }
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
        }
      }
    }
  }
LAB_00141360:
                    /* WARNING: Subroutine does not return */
  fail();
}

