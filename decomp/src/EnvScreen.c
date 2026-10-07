#include "htop.h"

/* EnvScreen_new @ 0x11ab90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

EnvScreen * EnvScreen_new(Process_2 *process)

{
  InfoScreen *this;
  InfoScreen_2 *pIVar1;

                    /* Unresolved local var: void * data@[???] */
  this = malloc(0x28);
  if (this != (InfoScreen *)0x0) {
    (this->super).klass = &EnvScreen_class.super;
    pIVar1 = InfoScreen_init(this,(Process *)process,(FunctionBar *)0x0,_LINES + -2,((char *)(long)&DAT_001470dd /* " " */));
    return (EnvScreen *)pIVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* EnvScreen_draw @ 0x11e380 */

/* DWARF original prototype: void EnvScreen_draw(InfoScreen * this) */

void EnvScreen_draw(InfoScreen *this)

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
  InfoScreen_drawTitled(this,((char *)(long)&s_Environment_of_process__d____s_0014b1c8 /* "Environment of process %d - %s" */),(pPVar1->super).id,va1);
  return;
}


/* EnvScreen_scan @ 0x11f7f0 */

/* DWARF original prototype: void EnvScreen_scan(InfoScreen * this) */

void EnvScreen_scan(InfoScreen *this)

{
  int wVar1;
  char *line;
  char cVar2;
  int wVar3;
  Panel *a0;
  Process *pPVar4;
  code *UNRECOVERED_JUMPTABLE;
  char *__ptr;
  size_t sVar5;
  long in_RCX;
  long in_R8;
  long in_R9;
  int wVar6;

  a0 = this->display;
  wVar6 = a0->selected;
  if (wVar6 < 0) {
    wVar6 = 0;
  }
  Vector_prune(a0->items);
  pPVar4 = this->process;
  a0->needsRedraw = true;
  a0->selected = 0;
  a0->oldSelected = 0;
  a0->scrollV = 0;
  __ptr = Platform_getProcessEnv((pPVar4->super).id);
  if (__ptr == (char *)0x0) {
    InfoScreen_addLine(this,((char *)(long)&s_Could_not_read_process_environme_0014b1e8 /* "Could not read process environment." */));
  }
  else {
                    /* Unresolved local var: char * p@[???] */
    cVar2 = *__ptr;
    line = __ptr;
    while (cVar2 != '\0') {
      InfoScreen_addLine(this,line);
      sVar5 = strlen(line);
      line = line + sVar5 + 1;
      cVar2 = *line;
    }
    free(__ptr);
  }
  Vector_insertionSort(this->lines);
  Vector_insertionSort(a0->items);
                    /* Unresolved local var: int size@[???] */
  wVar3 = a0->items->items;
  wVar1 = wVar3 + -1;
  if (wVar3 <= wVar6) {
    wVar6 = wVar1;
  }
  if (wVar6 < 0) {
    wVar6 = 0;
  }
  UNRECOVERED_JUMPTABLE = (a0->super).klass[1].extends;
  a0->selected = wVar6;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0011f8d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)((long)a0,0xffffffff,(ulong)(uint)wVar1,in_RCX,in_R8,in_R9);
    return;
  }
  return;
}

