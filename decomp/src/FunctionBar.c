#include "htop.h"

/* FunctionBar_delete @ 0x116fd0 */

/* DWARF original prototype: void FunctionBar_delete(FunctionBar * this) */

void FunctionBar_delete(FunctionBar *this)

{
  char **ppcVar1;
  long lVar2;

                    /* Unresolved local var: int i@[???] */
  lVar2 = 0;
  do {
    ppcVar1 = this->functions;
    if (*(void **)((long)ppcVar1 + lVar2) == (void *)0x0) goto LAB_00117002;
    free(*(void **)((long)ppcVar1 + lVar2));
    lVar2 = lVar2 + 8;
  } while (lVar2 != 0x78);
  ppcVar1 = this->functions;
LAB_00117002:
  free(ppcVar1);
  if (this->staticData == false) {
                    /* Unresolved local var: int i@[???] */
    lVar2 = 0;
    if (0 < this->size) {
      do {
        ppcVar1 = (this->keys).keys + lVar2;
        lVar2 = lVar2 + 1;
        free(*ppcVar1);
      } while ((int)lVar2 < this->size);
    }
    free((this->keys).keys);
    free(this->events);
  }
  free(this);
  return;
}


/* FunctionBar_drawExtra @ 0x117060 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: int FunctionBar_drawExtra(FunctionBar * this, char * buffer,
   int attr, _Bool setCursor) */

int FunctionBar_drawExtra(FunctionBar *this,char *buffer,int attr,_Bool setCursor)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  int iVar1;
  size_t sVar2;
  int p2;
  int wVar3;
  long lVar4;
  long lVar5;

  wattrset(_stdscr,CRT_colors[2]);
  iVar1 = wmove(_stdscr,_LINES + -1,0);
  if (iVar1 != -1) {
    whline(_stdscr,0x20,_COLS);
  }
                    /* Unresolved local var: int i@[???] */
  if (this->size < 1) {
    (*(int (*))(__fp - 0x3c)) = 0;
  }
  else {
    (*(int (*))(__fp - 0x3c)) = 0;
    lVar4 = 0;
    do {
      wattrset(_stdscr,CRT_colors[3]);
      iVar1 = wmove(_stdscr,_LINES + -1,(*(int (*))(__fp - 0x3c)));
      if (iVar1 != -1) {
        waddnstr(_stdscr,(this->keys).keys[lVar4],-1);
      }
      sVar2 = strlen((this->keys).keys[lVar4]);
      p2 = (*(int (*))(__fp - 0x3c)) + (int)sVar2;
      wattrset(_stdscr,CRT_colors[2]);
      iVar1 = wmove(_stdscr,_LINES + -1,p2);
      if (iVar1 != -1) {
        waddnstr(_stdscr,this->functions[lVar4],-1);
      }
      lVar5 = lVar4 + 1;
      sVar2 = strlen(this->functions[lVar4]);
      (*(int (*))(__fp - 0x3c)) = p2 + (int)sVar2;
      lVar4 = lVar5;
    } while ((int)lVar5 < this->size);
  }
  wVar3 = 0;
  if (buffer != (char *)0x0) {
    if (attr == -1) {
      wattrset(_stdscr,CRT_colors[2]);
    }
    else {
      wattrset(_stdscr,attr);
    }
    iVar1 = wmove(_stdscr,_LINES + -1,(*(int (*))(__fp - 0x3c)));
    if (iVar1 != -1) {
      waddnstr(_stdscr,buffer,-1);
    }
    sVar2 = strlen(buffer);
    wVar3 = (*(int (*))(__fp - 0x3c)) + (int)sVar2;
    (*(int (*))(__fp - 0x3c)) = wVar3;
  }
  wattrset(_stdscr,*CRT_colors);
  if (setCursor) {
    curs_set(1);
  }
  else {
    curs_set(0);
  }
  currentLen = (*(int (*))(__fp - 0x3c));
  return wVar3;
}


/* FunctionBar_draw @ 0x117270 */

/* DWARF original prototype: int FunctionBar_draw(FunctionBar * this) */

int FunctionBar_draw(FunctionBar *this)

{
  int wVar1;

  wVar1 = FunctionBar_drawExtra(this,(char *)0x0,-1,false);
  return wVar1;
}


/* FunctionBar_append @ 0x117290 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FunctionBar_append(char *buffer,int attr)

{
  int iVar1;
  size_t sVar2;

  if (attr == -1) {
    wattrset(_stdscr,CRT_colors[2]);
  }
  else {
    wattrset(_stdscr,attr);
  }
  iVar1 = wmove(_stdscr,_LINES + -1,currentLen + 1);
  if (iVar1 != -1) {
    waddnstr(_stdscr,buffer,-1);
  }
  wattrset(_stdscr,*CRT_colors);
  sVar2 = strlen(buffer);
  currentLen = currentLen + 1 + (int)sVar2;
  return;
}


/* FunctionBar_synthesizeEvent @ 0x117350 */

/* DWARF original prototype: int FunctionBar_synthesizeEvent(FunctionBar * this, int pos) */

int FunctionBar_synthesizeEvent(FunctionBar *this,int pos)

{
  int wVar1;
  char **ppcVar2;
  char **ppcVar3;
  size_t sVar4;
  size_t sVar5;
  int wVar6;
  long lVar7;

                    /* Unresolved local var: int i@[???] */
  wVar1 = this->size;
  if (0 < wVar1) {
    ppcVar2 = (this->keys).keys;
    ppcVar3 = this->functions;
    lVar7 = 0;
    wVar6 = 0;
    do {
      sVar4 = strlen(ppcVar2[lVar7]);
      sVar5 = strlen(ppcVar3[lVar7]);
      wVar6 = wVar6 + (int)sVar4 + (int)sVar5;
      if (pos < wVar6) {
        return this->events[lVar7];
      }
      lVar7 = lVar7 + 1;
    } while (wVar1 != lVar7);
  }
  return -1;
}


/* FunctionBar_new @ 0x117e30 */

FunctionBar * FunctionBar_new(char **functions,char **keys,int *events)

{
  FunctionBar *pFVar1;
  char **ppcVar2;
  char *pcVar3;
  int *pwVar4;
  long lVar5;
  undefined8 *puVar6;

                    /* Unresolved local var: void * data@[???] */
  pFVar1 = calloc(1,0x28);
  if (pFVar1 != (FunctionBar *)0x0) {
                    /* Unresolved local var: void * data@[???] */
    ppcVar2 = calloc(0x10,8);
    if (ppcVar2 != (char **)0x0) {
      pFVar1->functions = ppcVar2;
      if (functions == (char **)0x0) {
        functions = FunctionBar_FLabels;
      }
                    /* Unresolved local var: int i@[???] */
      lVar5 = 0;
      do {
        if (*(char **)((long)functions + lVar5) == (char *)0x0) break;
        puVar6 = (undefined8 *)((long)pFVar1->functions + lVar5);
                    /* Unresolved local var: char * data@[???] */
        pcVar3 = strdup(*(char **)((long)functions + lVar5));
        if (pcVar3 == (char *)0x0) goto LAB_00117fb1;
        lVar5 = lVar5 + 8;
        *puVar6 = pcVar3;
      } while (lVar5 != 0x78);
      if ((keys == (char **)0x0) || (events == (int *)0x0)) {
        pFVar1->staticData = true;
        lVar5 = 10;
        (pFVar1->keys).keys = FunctionBar_FKeys;
        pFVar1->events = FunctionBar_FEvents;
LAB_00117f06:
                    /* Unresolved local var: int i@[???] */
        pFVar1->size = (int)lVar5;
        return pFVar1;
      }
      pFVar1->staticData = false;
                    /* Unresolved local var: void * data@[???] */
      ppcVar2 = calloc(0xf,8);
      if (ppcVar2 != (char **)0x0) {
        (pFVar1->keys).keys = ppcVar2;
                    /* Unresolved local var: void * data@[???] */
        pwVar4 = calloc(0xf,4);
        if (pwVar4 != (int *)0x0) {
          pFVar1->events = pwVar4;
          lVar5 = 0;
          do {
            if (functions[lVar5] == (char *)0x0) goto LAB_00117f06;
                    /* Unresolved local var: char * data@[???] */
            ppcVar2 = (pFVar1->keys).keys;
            pcVar3 = strdup(keys[lVar5]);
            if (pcVar3 == (char *)0x0) goto LAB_00117fb1;
            ppcVar2[lVar5] = pcVar3;
            pFVar1->events[lVar5] = events[lVar5];
            lVar5 = lVar5 + 1;
          } while (lVar5 != 0xf);
          lVar5 = 0xf;
          goto LAB_00117f06;
        }
      }
    }
  }
LAB_00117fb1:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* FunctionBar_newEnterEsc @ 0x117fc0 */

FunctionBar * FunctionBar_newEnterEsc(char *enter,char *esc)

{
  undefined1 __frame[0xb8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x78;
  long lVar1;
  FunctionBar *pFVar2;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  (*(char *(*) [3])(__fp - 0x28))[2] = (char *)0x0;
  (*(char *(*) [3])(__fp - 0x28))[0] = enter;
  (*(char *(*) [3])(__fp - 0x28))[1] = esc;
  pFVar2 = FunctionBar_new((*(char *(*) [3])(__fp - 0x28)),FunctionBar_EnterEscKeys,((char *)(long)&FunctionBar_EnterEscEvents /* L"\r\x1b" */));
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pFVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* FunctionBar_setLabel @ 0x118020 */

/* DWARF original prototype: void FunctionBar_setLabel(FunctionBar * this, int event, char *
   text) */

void FunctionBar_setLabel(FunctionBar *this,int event,char *text)

{
  char **ppcVar1;
  long lVar2;
  char *pcVar3;

                    /* Unresolved local var: int i@[???] */
  if (this->size < 1) {
    return;
  }
  lVar2 = 0;
  do {
    if (this->events[lVar2] == event) {
      free(this->functions[lVar2]);
                    /* Unresolved local var: char * data@[???] */
      ppcVar1 = this->functions;
      pcVar3 = strdup(text);
      if (pcVar3 != (char *)0x0) {
        ppcVar1[lVar2] = pcVar3;
        return;
      }
                    /* WARNING: Subroutine does not return */
      fail();
    }
    lVar2 = lVar2 + 1;
  } while (this->size != lVar2);
  return;
}

