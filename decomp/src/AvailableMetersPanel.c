#include "htop.h"

/* AvailableMetersPanel_delete @ 0x117670 */

void AvailableMetersPanel_delete(AvailableMetersPanel_ *object)

{
  free((object->super).eventHandlerState);
  Vector_delete((object->super).items);
  FunctionBar_delete((object->super).defaultBar);
  if (350 < (object->super).header.chlen) {
    free((object->super).header.chptr);
  }
  free(object->meterPanels);
  free(object);
  return;
}


/* AvailableMetersPanel_new @ 0x11be10 */

/* WARNING: Removing unreachable block (ram,0x0011bf1b) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff50 : 0x0011bf38 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

AvailableMetersPanel *
AvailableMetersPanel_new
          (Machine_4 *host,Header_3 *header,size_t columns,MetersPanel **meterPanels,
          ScreenManager_2 *scr)

{
  undefined1 __frame[0x188] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x148;
  _Bool _Var1;
  int wVar2;
  long lVar3;
  Hashtable_2 *pHVar4;
  Vector *pVVar5;
  char **ppcVar6;
  Machine_4 *pMVar7;
  int wVar8;
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
  int *pwVar20;
  long in_FS_OFFSET = (long)__fake_fs;

  pppcVar16 = &(*(char **(*))(__fp - 0xa8));
                    /* Unresolved local var: void * data@[???] */
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  (*(Machine_4 *(*))(__fp - 0xa0)) = host;
  this = malloc(0x2708);
  if (this != (AvailableMetersPanel *)0x0) {
    (*(char **(*))(__fp - 0xa8)) = (*(char *(*) [3])(__fp - 0x78));
    (this->super).super.klass = &AvailableMetersPanel_class.super;
    (*(char *(*) [3])(__fp - 0x78))[2] = (char *)0x0;
    (*(char *(*) [3])(__fp - 0x78))[0] = ((char *)(long)&s_Add_0014744e /* "Add   " */);
    (*(char *(*) [3])(__fp - 0x78))[1] = ((char *)(long)&s_Done_00147455 /* "Done   " */);
    fuBar = FunctionBar_new((*(char **(*))(__fp - 0xa8)),FunctionBar_EnterEscKeys,((char *)(long)&FunctionBar_EnterEscEvents /* L"\r\x1b" */));
    Panel_init(&this->super,1,1,1,1,&ListItem_class,true,fuBar);
    this->header = header;
    this->columns = columns;
    this->host = (*(Machine_4 *(*))(__fp - 0xa0));
    this->meterPanels = meterPanels;
    pwVar20 = CRT_colors;
    this->scr = scr;
                    /* Unresolved local var: int[69118] data@[???]
                       Unresolved local var: int newLen@[???] */
    (*(char *(*))(__fp - 0x88)) = (char *)&(*(char **(*))(__fp - 0xa8));
    wVar2 = pwVar20[7];
    pwVar20 = (*(int (*) [16])(__fp - 0xf8));
    (*(char *(*))(__fp - 0x88)) = (char *)&(*(char **(*))(__fp - 0xa8));
    sVar10 = mbstowcs((*(int (*) [16])(__fp - 0xf8)),((char *)(long)&s_Available_meters_0014745d /* "Available meters" */),0x10);
    wVar8 = (int)sVar10;
    if (0 < wVar8) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen(&(this->super).header,wVar8);
      (*(int *(*))(__fp - 0x80)) = (*(int (*) [16])(__fp - 0xf8)) + (ulong)(uint)(wVar8 + -1) + 1;
      pcVar18 = (this->super).header.chptr;
      do {
        wVar8 = *pwVar20;
        iVar9 = iswprint(wVar8);
        pcVar18->attr = 0;
        pcVar18->chars[0] = 0;
        pcVar18->chars[1] = 0;
        pcVar18->chars[2] = 0;
        if (iVar9 == 0) {
          wVar8 = 65533;
        }
        pwVar20 = pwVar20 + 1;
        pcVar18->attr = wVar2 & 0xffffff;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar18->chars + 2)) = (undefined16)0x0;
        pcVar18->chars[0] = wVar8;
        pcVar18 = pcVar18 + 1;
      } while (pwVar20 != (*(int *(*))(__fp - 0x80)));
    }
    pppcVar16 = (char ***)(*(char *(*))(__fp - 0x88));
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
        pHVar4 = (*(Machine_4 *(*))(__fp - 0xa0))->settings->dynamicColumns;
        (*(uint (*))(__fp - 0x94)) = iVar9 << 0x10;
        if (pHVar4->size != 0) {
          do {
            pcVar15 = pHVar4->buckets[uVar19].value;
            if (pcVar15 != (char *)0x0) {
              (*(int *(*))(__fp - 0x80)) = (int *)CONCAT44((*(uint *)((char *)&(*(int *(*))(__fp - 0x80)) + 4)),(*(uint (*))(__fp - 0x94)) | uVar17);
              (*(char *(*))(__fp - 0x88)) = *(char **)(pcVar15 + 0x28);
              if ((*(char **)(pcVar15 + 0x28) == (char *)0x0) &&
                 ((*(char *(*))(__fp - 0x88)) = *(char **)(pcVar15 + 0x20), *(char **)(pcVar15 + 0x20) == (char *)0x0))
              {
                (*(char *(*))(__fp - 0x88)) = pcVar15;
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
              pcVar15 = (*(char *(*))(__fp - 0x88));
              if (puVar14 == (undefined8 *)0x0) goto LAB_0011c2ea;
                    /* Unresolved local var: char * data@[???] */
              *puVar14 = &ListItem_class;
              (*(undefined8 *(*))(__fp - 0x90)) = puVar14;
              *(char *)((long)pppcVar16 + -8) = -0x2c;
              *(char *)((long)pppcVar16 + -7) = -0x40;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              pcVar15 = strdup(pcVar15);
              puVar14 = (*(undefined8 *(*))(__fp - 0x90));
              if (pcVar15 == (char *)0x0) goto LAB_0011c2ea;
              pVVar5 = (this->super).items;
              uVar17 = uVar17 + 1;
              (*(undefined8 *(*))(__fp - 0x90))[1] = pcVar15;
              *(undefined1 *)((long)(*(undefined8 *(*))(__fp - 0x90)) + 0x14) = 0;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
              wVar2 = pVVar5->items;
              *(undefined4 *)((*(undefined8 *(*))(__fp - 0x90)) + 2) = (*(uint *)((char *)&(*(int *(*))(__fp - 0x80)) + 0));
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
                       Unresolved local var: int i@[???] */
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
      pMVar7 = (*(Machine_4 *(*))(__fp - 0xa0));
      uVar19 = (ulong)(iVar9 + 1);
      pMVar11 = (MeterClass_3 *)Platform_meterTypes[uVar19];
    } while (pMVar11 != (MeterClass_3 *)0x0);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    if ((*(Machine_4 *(*))(__fp - 0xa0))->existingCPUs < 2) {
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
        pOVar13 = (ObjectClass *)strdup(((char *)(long)(__sec_rodata + 0x826) /* "CPU" */));
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
        pOVar13 = (ObjectClass *)strdup(((char *)(long)&s_CPU_average_0014746e /* "CPU average" */));
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
              ppcVar6 = (*(char **(*))(__fp - 0xa8));
              _Var1 = (*(Machine_4 *(*))(__fp - 0xa0))->settings->countCPUsFromOne;
              *(char *)((long)pppcVar16 + -8) = '\x0e';
              *(char *)((long)pppcVar16 + -7) = -0x3e;
              *(char *)((long)pppcVar16 + -6) = '\x11';
              *(char *)((long)pppcVar16 + -5) = '\0';
              *(char *)((long)pppcVar16 + -4) = '\0';
              *(char *)((long)pppcVar16 + -3) = '\0';
              *(char *)((long)pppcVar16 + -2) = '\0';
              *(char *)((long)pppcVar16 + -1) = '\0';
              xSnprintf((char *)ppcVar6,0x32,((char *)(long)&s__s__d_0014747a /* "%s %d" */),((char *)(long)(__sec_rodata + 0x826) /* "CPU" */),uVar17 - (_Var1 == false));
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
              ppcVar6 = (*(char **(*))(__fp - 0xa8));
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
                       Unresolved local var: int i@[???] */
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
            } while (uVar17 <= (*(Machine_4 *(*))(__fp - 0xa0))->existingCPUs);
          }
LAB_0011c278:
          if (lVar3 == *(long *)(in_FS_OFFSET + 0x28)) {
            return this;
          }
                    /* WARNING: Subroutine does not return */
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


/* AvailableMetersPanel_eventHandler @ 0x11c630 */

HandlerResult AvailableMetersPanel_eventHandler(AvailableMetersPanel_ *super,int ch)

{
  uint64_t *puVar1;
  uint uVar2;
  Header_3 *this;
  Object *pOVar3;
  MetersPanel *pMVar4;
  code *pcVar5;
  Settings__4 *pSVar6;
  FunctionBar *pFVar7;
  int iVar8;
  int wVar9;
  Meter_3 *pMVar10;
  ListItem *pLVar11;
  uint param;
  int wVar12;
  Vector *pVVar13;
  long in_R8;
  long in_R9;
  HandlerResult HVar14;

  pVVar13 = (super->super).items;
  this = super->header;
  if (pVVar13->items < 1) {
    return IGNORED;
  }
  pOVar3 = pVVar13->array[(super->super).selected];
  if (pOVar3 == (Object *)0x0) {
    return IGNORED;
  }
  uVar2 = *(uint *)&pOVar3[2].klass;
  param = uVar2 & 0xffff;
  iVar8 = (int)uVar2 >> 0x10;
  if (ch == 'l') {
LAB_0011c7b8:
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: Vector * meters@[???] */
    pMVar4 = *super->meterPanels;
    pVVar13 = *this->columns;
    pMVar10 = Meter_new((Machine_2 *)this->host,param,(MeterClass_3 *)Platform_meterTypes[iVar8]);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
    Vector_set(pVVar13,pVVar13->items,pMVar10);
    pLVar11 = Meter_toListItem((Meter *)pMVar10,false);
    Panel_add(&pMVar4->super,&pLVar11->super);
    pVVar13 = (pMVar4->super).items;
                    /* Unresolved local var: int size@[???] */
    wVar12 = pVVar13->items;
    wVar9 = wVar12 + -1;
    if (wVar9 < 0) {
      wVar9 = 0;
    }
    (pMVar4->super).selected = wVar9;
    pcVar5 = (pMVar4->super).super.klass[1].extends;
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)((long)pMVar4,0xffffffff,(long)pVVar13,(ulong)(uint)wVar12,in_R8,in_R9);
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
      pVVar13 = (pMVar4->super).items;
      wVar12 = pVVar13->items;
    }
    pMVar4->moving = true;
    if ((0 < wVar12) && (pVVar13->array[(pMVar4->super).selected] != (Object *)0x0)) {
      *(undefined1 *)((long)&pVVar13->array[(pMVar4->super).selected][2].klass + 4) = 1;
    }
    pFVar7 = Meters_movingBar;
    (pMVar4->super).selectionColorId = PANEL_SELECTION_FOLLOW;
    (pMVar4->super).currentBar = pFVar7;
    HVar14 = HANDLED;
  }
  else {
    if (ch < 'm') {
      if (ch == 'L') goto LAB_0011c7b8;
      if (ch < 'M') {
        if ((ch != 10) && (ch != 13)) {
          return IGNORED;
        }
      }
      else if (ch != 'R') {
        return IGNORED;
      }
    }
    else {
      if (ch == 269) goto LAB_0011c7b8;
      if (ch < 270) {
        if (ch != 'r') {
          return IGNORED;
        }
      }
      else if ((ch != 270) && (ch != 343)) {
        return IGNORED;
      }
    }
                    /* Unresolved local var: Meter * meter@[???]
                       Unresolved local var: Vector * meters@[???] */
    pMVar4 = super->meterPanels[super->columns - 1];
    pVVar13 = this->columns[(int)super->columns - 1];
    pMVar10 = Meter_new((Machine_2 *)this->host,param,(MeterClass_3 *)Platform_meterTypes[iVar8]);
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
    Vector_set(pVVar13,pVVar13->items,pMVar10);
    pLVar11 = Meter_toListItem((Meter *)pMVar10,false);
    Panel_add(&pMVar4->super,&pLVar11->super);
    pVVar13 = (pMVar4->super).items;
                    /* Unresolved local var: int size@[???] */
    wVar12 = pVVar13->items;
    wVar9 = wVar12 + -1;
    if (wVar9 < 0) {
      wVar9 = 0;
    }
    (pMVar4->super).selected = wVar9;
    pcVar5 = (pMVar4->super).super.klass[1].extends;
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)((long)pMVar4,0xffffffff,(long)pVVar13,(ulong)(uint)wVar12,in_R8,in_R9);
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: ListItem * selected@[???] */
      pVVar13 = (pMVar4->super).items;
      wVar12 = pVVar13->items;
    }
    pMVar4->moving = true;
    if ((0 < wVar12) && (pVVar13->array[(pMVar4->super).selected] != (Object *)0x0)) {
      *(undefined1 *)((long)&pVVar13->array[(pMVar4->super).selected][2].klass + 4) = 1;
    }
    pFVar7 = Meters_movingBar;
    (pMVar4->super).selectionColorId = PANEL_SELECTION_FOLLOW;
    (pMVar4->super).currentBar = pFVar7;
    HVar14 = 0x1040080;
  }
                    /* Unresolved local var: Settings * settings@[???] */
  pSVar6 = super->host->settings;
  puVar1 = &pSVar6->lastUpdate;
  *puVar1 = *puVar1 + 1;
  pSVar6->changed = true;
  Header_calculateHeight((Header *)this);
  Header_updateData((Header *)this);
  Header_draw((Header *)this);
  ScreenManager_resize((ScreenManager *)super->scr);
  return HVar14;
}

