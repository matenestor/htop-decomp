#include "htop.h"

/* CommandScreen_delete @ 0x1177f0 */

/* DWARF original prototype: void CommandScreen_delete(Object * this) */

void CommandScreen_delete(Object *this)

{
  ObjectClass *pOVar1;

  pOVar1 = this[2].klass;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
  free(pOVar1[1].compare);
  Vector_delete(pOVar1[1].extends);
  FunctionBar_delete((FunctionBar *)pOVar1[2].compare);
  if (0x15e < *(int *)&pOVar1[3].extends) {
    free(pOVar1[3].display);
  }
  free(pOVar1);
  pOVar1 = this[3].klass;
  FunctionBar_delete((FunctionBar *)pOVar1[4].display);
  FunctionBar_delete(pOVar1[9].extends);
  free(pOVar1);
  Vector_delete((Vector *)this[4].klass);
  free(this);
  return;
}


/* CommandScreen_new @ 0x11acc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CommandScreen * CommandScreen_new(Process *process)

{
  InfoScreen *this;
  InfoScreen_2 *pIVar1;

                    /* Unresolved local var: void * data@[???] */
  this = malloc(0x28);
  if (this != (InfoScreen *)0x0) {
    (this->super).klass = &CommandScreen_class.super;
    pIVar1 = InfoScreen_init(this,process,(FunctionBar *)0x0,_LINES + -2,((char *)(long)&DAT_001470dd /* " " */));
    return (CommandScreen *)pIVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* CommandScreen_scan @ 0x11e100 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void CommandScreen_scan(InfoScreen * this) */

void CommandScreen_scan(InfoScreen *this)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  int wVar1;
  _Bool _Var2;
  int wVar3;
  Panel *a0;
  Process *pPVar4;
  Machine_ *pMVar5;
  code *pcVar6;
  long lVar7;
  ulong *puVar8;
  char cVar9;
  int iVar10;
  ulong uVar11;
  uint uVar12;
  ulong *puVar13;
  char *a4;
  long in_R9;
  int wVar15;
  long in_FS_OFFSET = (long)__fake_fs;
  ulong *puVar14;

  puVar14 = &(*(ulong (*))(__fp - 0x68));
  puVar13 = &(*(ulong (*))(__fp - 0x68));
  a0 = this->display;
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  wVar15 = a0->selected;
  if (wVar15 < 0) {
    wVar15 = 0;
  }
  Vector_prune(a0->items);
  pPVar4 = this->process;
  a0->needsRedraw = true;
  a0->scrollV = 0;
                    /* Unresolved local var: Settings * settings@[???] */
  pMVar5 = (pPVar4->super).host;
  _Var2 = pPVar4->isUserlandThread;
  a0->selected = 0;
  a0->oldSelected = 0;
  if (((_Var2 != false) && (pMVar5->settings->showThreadNames != false)) ||
     (a4 = (pPVar4->mergedCommand).str, a4 == (char *)0x0)) {
    a4 = pPVar4->cmdline;
  }
  (*(ulong (*))(__fp - 0x68)) = (ulong)(int)(_COLS + 1);
  puVar8 = &(*(ulong (*))(__fp - 0x68));
  while (puVar14 != (ulong *)((long)&(*(ulong (*))(__fp - 0x68)) - ((*(ulong (*))(__fp - 0x68)) + 0xf & 0xfffffffffffff000))) {
    puVar13 = (ulong *)((long)puVar8 + -0x1000);
    *(undefined8 *)((long)puVar8 + -8) = *(undefined8 *)((long)puVar8 + -8);
    puVar14 = (ulong *)((long)puVar8 + -0x1000);
    puVar8 = (ulong *)((long)puVar8 + -0x1000);
  }
  uVar11 = (ulong)((uint)((*(ulong (*))(__fp - 0x68)) + 0xf) & 0xff0);
  lVar7 = -uVar11;
  if (uVar11 != 0) {
    *(undefined8 *)((long)puVar13 + -8) = *(undefined8 *)((long)puVar13 + -8);
  }
  cVar9 = *a4;
  uVar11 = 0xffffffff;
  uVar12 = 0;
  if (cVar9 != '\0') {
    do {
      *(char *)((long)puVar13 + (int)uVar12 + lVar7) = cVar9;
      if (cVar9 == ' ') {
        uVar11 = (ulong)uVar12;
      }
      if (uVar12 == _COLS) {
        if ((int)uVar11 == -1) {
          uVar11 = (ulong)uVar12;
          (*(ulong (*))(__fp - 0x58)) = 1;
          uVar12 = 1;
          (*(char *(*))(__fp - 0x60)) = a4;
        }
        else {
          iVar10 = uVar12 - (int)uVar11;
          uVar12 = iVar10 + 1;
          (*(ulong (*))(__fp - 0x58)) = (ulong)(int)uVar12;
          (*(char *(*))(__fp - 0x60)) = a4 + -(long)iVar10;
        }
        *(undefined1 *)((long)puVar13 + (int)uVar11 + lVar7) = 0;
        (*(char *(*))(__fp - 0x50)) = a4;
        InfoScreen_addLine(this,(char *)((long)puVar13 + lVar7));
        __memcpy_chk((undefined1 *)((long)puVar13 + lVar7),(*(char *(*))(__fp - 0x60)),(*(ulong (*))(__fp - 0x58)),(*(ulong (*))(__fp - 0x68)));
        uVar11 = 0xffffffff;
        cVar9 = (*(char *(*))(__fp - 0x50))[1];
        a4 = (*(char *(*))(__fp - 0x50));
      }
      else {
        cVar9 = a4[1];
        uVar12 = uVar12 + 1;
      }
      a4 = a4 + 1;
    } while (cVar9 != '\0');
    if (0 < (int)uVar12) {
      *(undefined1 *)((long)puVar13 + (int)uVar12 + lVar7) = 0;
      InfoScreen_addLine(this,(char *)((long)puVar13 + lVar7));
    }
  }
                    /* Unresolved local var: int size@[???] */
  wVar3 = a0->items->items;
  wVar1 = wVar3 + -1;
  if (wVar3 <= wVar15) {
    wVar15 = wVar1;
  }
  if (wVar15 < 0) {
    wVar15 = 0;
  }
  pcVar6 = (a0->super).klass[1].extends;
  a0->selected = wVar15;
  if (pcVar6 != (code *)0x0) {
    (*pcVar6)((long)a0,0xffffffff,(ulong)(uint)wVar1,uVar11,(long)a4,in_R9);
  }
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* CommandScreen_draw @ 0x11e330 */

/* DWARF original prototype: void CommandScreen_draw(InfoScreen * this) */

void CommandScreen_draw(InfoScreen *this)

{
  Process *pPVar1;
  char *va1;

  pPVar1 = this->process;
                    /* Unresolved local var: Settings * settings@[???] */
  if (((pPVar1->isUserlandThread != false) &&
      (((pPVar1->super).host)->settings->showThreadNames != false)) ||
     (va1 = (pPVar1->mergedCommand).str, va1 == (char *)0x0)) {
    va1 = pPVar1->cmdline;
  }
  InfoScreen_drawTitled(this,((char *)(long)&s_Command_of_process__d____s_0014760e /* "Command of process %d - %s" */),(pPVar1->super).id,va1);
  return;
}

