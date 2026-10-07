#include "htop.h"

/* IncSet_getListItemValue @ 0x11fab0 */

char * IncSet_getListItemValue(Panel *panel,int i)

{
  Object *pOVar1;
  ObjectClass *pOVar2;

  pOVar1 = panel->items->array[i];
  pOVar2 = (ObjectClass *)&DAT_00149c0c;
  if (pOVar1 != (Object *)0x0) {
    pOVar2 = pOVar1[1].klass;
  }
  return (char *)pOVar2;
}


/* IncSet_reset @ 0x120ef0 */

/* DWARF original prototype: void IncSet_reset(IncSet * this, IncType type) */

void IncSet_reset(IncSet *this,IncType type)

{
  this->modes[type].index = 0;
  this->modes[type].buffer[0] = '\0';
  return;
}


/* IncSet_setFilter @ 0x120f10 */

/* DWARF original prototype: void IncSet_setFilter(IncSet * this, char * filter) */

void IncSet_setFilter(IncSet *this,char *filter)

{
  long lVar1;
  int wVar2;

                    /* Unresolved local var: size_t i@[???] */
  lVar1 = 0;
  do {
    if (filter[lVar1] == '\0') {
      wVar2 = (int)lVar1;
      goto LAB_00120f3d;
    }
    this->modes[1].buffer[lVar1] = filter[lVar1];
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x80);
  wVar2 = 128;
LAB_00120f3d:
  this->modes[1].buffer[lVar1] = '\0';
  this->modes[1].index = wVar2;
  this->filtering = true;
  return;
}


/* IncSet_delete @ 0x126cb0 */

/* DWARF original prototype: void IncSet_delete(IncSet * this) */

void IncSet_delete(IncSet *this)

{
  FunctionBar_delete(this->modes[0].bar);
  FunctionBar_delete(this->modes[1].bar);
  free(this);
  return;
}


/* IncSet_new @ 0x127280 */

IncSet_3 * IncSet_new(FunctionBar *bar)

{
  IncSet_3 *pIVar1;
  FunctionBar *pFVar2;
  long lVar3;
  IncSet_3 *pIVar4;
  IncMode *pIVar5;
  byte bVar6;

                    /* Unresolved local var: void * data@[???] */
  bVar6 = 0;
  pIVar1 = malloc(0x150);
  if (pIVar1 != (IncSet_3 *)0x0) {
    pIVar4 = pIVar1;
    for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
      pIVar4->modes[0].buffer[0] = '\0';
      pIVar4->modes[0].buffer[1] = '\0';
      pIVar4->modes[0].buffer[2] = '\0';
      pIVar4->modes[0].buffer[3] = '\0';
      pIVar4->modes[0].buffer[4] = '\0';
      pIVar4->modes[0].buffer[5] = '\0';
      pIVar4->modes[0].buffer[6] = '\0';
      pIVar4->modes[0].buffer[7] = '\0';
      pIVar4 = (IncSet_3 *)((long)pIVar4 + (ulong)bVar6 * -0x10 + 8);
    }
    pFVar2 = FunctionBar_new(searchFunctions,searchKeys,searchEvents);
    pIVar1->modes[0].isFilter = false;
    pIVar1->modes[0].bar = pFVar2;
    pIVar5 = pIVar1->modes + 1;
    for (lVar3 = 0x13; lVar3 != 0; lVar3 = lVar3 + -1) {
      pIVar5->buffer[0] = '\0';
      pIVar5->buffer[1] = '\0';
      pIVar5->buffer[2] = '\0';
      pIVar5->buffer[3] = '\0';
      pIVar5->buffer[4] = '\0';
      pIVar5->buffer[5] = '\0';
      pIVar5->buffer[6] = '\0';
      pIVar5->buffer[7] = '\0';
      pIVar5 = (IncMode *)((long)pIVar5 + (ulong)bVar6 * -0x10 + 8);
    }
    pFVar2 = FunctionBar_new(filterFunctions,filterKeys,filterEvents);
    pIVar1->modes[1].isFilter = true;
    pIVar1->modes[1].bar = pFVar2;
    pIVar1->filtering = false;
    pIVar1->found = false;
    pIVar1->active = (IncMode *)0x0;
    pIVar1->defaultBar = bar;
    return pIVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* IncSet_drawBar @ 0x1276f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void IncSet_drawBar(IncSet * this, int attr) */

void IncSet_drawBar(IncSet *this,int attr)

{
  IncMode *buffer;
  Panel *pPVar1;
  int wVar2;

  buffer = this->active;
  if (buffer != (IncMode *)0x0) {
                    /* Unresolved local var: int cursorX@[???] */
    if ((buffer->isFilter == false) && (this->found == false)) {
      attr = CRT_colors[4];
    }
    wVar2 = FunctionBar_drawExtra(buffer->bar,buffer->buffer,attr,true);
    pPVar1 = this->panel;
    pPVar1->cursorX = wVar2;
    pPVar1->cursorY = _LINES + -1;
    return;
  }
  FunctionBar_drawExtra(this->defaultBar,(char *)0x0,-1,false);
  return;
}


/* IncSet_activate @ 0x127780 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void IncSet_activate(IncSet * this, IncType type, Panel * panel) */

void IncSet_activate(IncSet *this,IncType type,Panel *panel)

{
  IncMode *buffer;
  FunctionBar *this_00;
  Panel *pPVar1;
  int *pwVar2;
  int wVar3;

  buffer = this->modes + type;
  this->active = buffer;
  this_00 = buffer->bar;
  panel->cursorOn = true;
  pwVar2 = CRT_colors;
  panel->currentBar = this_00;
  this->panel = panel;
                    /* Unresolved local var: int cursorX@[???] */
  wVar3 = pwVar2[2];
  if ((buffer->isFilter == false) && (this->found == false)) {
    wVar3 = pwVar2[4];
  }
  wVar3 = FunctionBar_drawExtra(this_00,buffer->buffer,wVar3,true);
  pPVar1 = this->panel;
  pPVar1->cursorX = wVar3;
  pPVar1->cursorY = _LINES + -1;
  return;
}


/* IncSet_synthesizeEvent @ 0x128660 */

/* DWARF original prototype: int IncSet_synthesizeEvent(IncSet * this, int x) */

int IncSet_synthesizeEvent(IncSet *this,int x)

{
  int wVar1;

  if (this->active != (IncMode *)0x0) {
    wVar1 = FunctionBar_synthesizeEvent(this->active->bar,x);
    return wVar1;
  }
  wVar1 = FunctionBar_synthesizeEvent(this->defaultBar,x);
  return wVar1;
}


/* IncSet_handleKey @ 0x12a3f0 */

/* DWARF original prototype: _Bool IncSet_handleKey(IncSet * this, int ch, Panel * panel,
   IncMode_GetPanelValue getPanelValue, Vector * lines) */

_Bool IncSet_handleKey(IncSet *this,int ch,Panel *panel,IncMode_GetPanelValue_2 getPanelValue,
                      Vector *lines)

{
  undefined1 __frame[0x108] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xc8;
  int wVar1;
  code *pcVar2;
  ObjectClass *__haystack;
  Vector *this_00;
  Object *pOVar3;
  FunctionBar *pFVar4;
  FunctionBar *this_01;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  char **ppcVar8;
  IncMode *pIVar9;
  ushort **ppuVar10;
  bool bVar11;
  ulong a3;
  ulong uVar12;
  ushort *extraout_RDX;
  ushort *extraout_RDX_00;
  ushort *extraout_RDX_01;
  ushort *extraout_RDX_02;
  ushort *extraout_RDX_03;
  ushort *extraout_RDX_04;
  ushort *a2;
  char **ppcVar13;
  long lVar14;
  Vector *pVVar15;
  long in_R9;
  int wVar16;
  int wVar17;
  char cVar18;
  char cVar19;
  size_t sVar20;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if (ch != -1) {
    pIVar9 = this->active;
    wVar1 = panel->items->items;
    a2 = (ushort *)(ulong)(uint)wVar1;
    bVar11 = ch == 267 || ch == 279;
    uVar12 = CONCAT71((int7)((ulong)getPanelValue >> 8),bVar11);
    if (ch != 267 && ch != 279) {
      pVVar15 = lines;
      if ((uint)(ch + -1) < 0xfe) {
        ppuVar10 = __ctype_b_loc();
        uVar12 = (ulong)bVar11;
        a2 = *ppuVar10;
        if ((*(byte *)((long)a2 + (long)ch * 2 + 1) & 0x40) == 0) {
          if (ch != 127) {
            cVar18 = pIVar9->isFilter;
            if ((_Bool)cVar18 == false) {
              if (ch == 27) {
                pIVar9->index = 0;
                pIVar9->buffer[0] = '\0';
              }
              goto LAB_0012ab56;
            }
            if (ch == 27) {
              this->filtering = false;
              pIVar9->index = 0;
              pIVar9->buffer[0] = '\0';
            }
LAB_0012abb3:
            bVar11 = lines != (Vector *)0x0;
            goto LAB_0012ab5d;
          }
          goto LAB_0012aa7c;
        }
        wVar17 = pIVar9->index;
        if (wVar17 < 128) {
          wVar16 = wVar17 + 1;
          pIVar9->buffer[wVar17] = (char)ch;
          a2 = (ushort *)(long)wVar16;
          pIVar9->index = wVar16;
          pIVar9->buffer[(long)a2] = '\0';
          if (pIVar9->isFilter != false) {
            if (wVar16 == 1) {
              this->filtering = true;
            }
            goto LAB_0012a9f7;
          }
        }
LAB_0012a702:
                    /* Unresolved local var: int size@[???]
                       Unresolved local var: int i@[???] */
        bVar11 = false;
        cVar19 = '\0';
        if (wVar1 < 1) {
          this->found = false;
          goto LAB_0012a589;
        }
LAB_0012a714:
                    /* Unresolved local var: char * * needles@[???] */
        wVar17 = 0;
        a3 = uVar12;
        do {
          pIVar9 = this->active;
          pcVar6 = (*(code *)(getPanelValue))(panel,wVar17,(long)a2,a3,(long)pVVar15,in_R9);
          pcVar7 = strchr(pIVar9->buffer,0x7c);
          cVar18 = cVar19;
          if (pcVar7 == (char *)0x0) {
            pcVar6 = strcasestr(pcVar6,pIVar9->buffer);
            a2 = extraout_RDX_03;
            if (pcVar6 != (char *)0x0) goto LAB_0012a7e9;
          }
          else {
            ppcVar8 = String_split(pIVar9->buffer,'|',&(*(size_t (*))(__fp - 0x48)));
            sVar5 = (*(size_t (*))(__fp - 0x48));
                    /* Unresolved local var: size_t i@[???] */
            if ((*(size_t (*))(__fp - 0x48)) != 0) {
              sVar20 = 0;
LAB_0012a79d:
              pcVar7 = strcasestr(pcVar6,ppcVar8[sVar20]);
              if (pcVar7 == (char *)0x0) goto LAB_0012a790;
                    /* Unresolved local var: size_t i@[???] */
              pcVar6 = *ppcVar8;
              ppcVar13 = ppcVar8;
              while (pcVar6 != (char *)0x0) {
                ppcVar13 = ppcVar13 + 1;
                free(pcVar6);
                pcVar6 = *ppcVar13;
              }
              free(ppcVar8);
              goto LAB_0012a7e9;
            }
            a2 = extraout_RDX_00;
            if (ppcVar8 != (char **)0x0) {
LAB_0012aa48:
                    /* Unresolved local var: size_t i@[???] */
              pcVar6 = *ppcVar8;
              ppcVar13 = ppcVar8;
              while (pcVar6 != (char *)0x0) {
                ppcVar13 = ppcVar13 + 1;
                free(pcVar6);
                pcVar6 = *ppcVar13;
              }
              free(ppcVar8);
              a2 = extraout_RDX_04;
            }
          }
          wVar17 = wVar17 + 1;
        } while (wVar1 != wVar17);
        uVar12 = uVar12 & 0xff;
        goto LAB_0012a823;
      }
      if (ch == 263) {
LAB_0012aa7c:
        if (pIVar9->index < 1) goto LAB_0012a589;
        wVar17 = pIVar9->index + -1;
        a2 = (ushort *)(long)wVar17;
        pIVar9->index = wVar17;
        pIVar9->buffer[(long)a2] = '\0';
        if (pIVar9->isFilter == false) goto LAB_0012a702;
        if (wVar17 == 0) {
          this->filtering = false;
          pIVar9->index = 0;
          pIVar9->buffer[0] = '\0';
        }
LAB_0012a9f7:
        bVar11 = lines != (Vector *)0x0;
        cVar18 = '\x01';
        cVar19 = '\x01';
        if (wVar1 < 1) goto LAB_0012a823;
        goto LAB_0012a714;
      }
      if (ch == 410) {
        pVVar15 = (Vector *)(ulong)(uint)pIVar9->index;
        if (0 < pIVar9->index) goto LAB_0012a702;
        goto LAB_0012a589;
      }
      cVar18 = pIVar9->isFilter;
      if ((_Bool)cVar18 != false) goto LAB_0012abb3;
LAB_0012ab56:
      bVar11 = false;
      cVar18 = '\0';
LAB_0012ab5d:
      pFVar4 = panel->defaultBar;
      this_01 = this->defaultBar;
      this->active = (IncMode *)0x0;
      panel->cursorOn = false;
      panel->currentBar = pFVar4;
      FunctionBar_drawExtra(this_01,(char *)0x0,-1,false);
      goto LAB_0012a82d;
    }
    if (wVar1 != 0) {
                    /* Unresolved local var: int size@[???]
                       Unresolved local var: int here@[???]
                       Unresolved local var: int i@[???] */
      wVar17 = panel->selected;
      uVar12 = (ulong)(uint)wVar17;
      wVar16 = wVar17;
      do {
        while( true ) {
          wVar16 = wVar16 + ((ch == 267) - 1) + (uint)(ch == 267);
          if (wVar1 == wVar16) {
            wVar16 = 0;
          }
          else if (wVar16 == -1) {
            wVar16 = wVar1 + -1;
          }
          if (wVar16 == wVar17) goto LAB_0012a589;
          pcVar6 = (*(code *)(getPanelValue))(panel,wVar16,(long)a2,uVar12,(long)lines,in_R9);
          pcVar7 = strchr(pIVar9->buffer,0x7c);
          if (pcVar7 == (char *)0x0) break;
                    /* Unresolved local var: char * * needles@[???] */
          ppcVar8 = String_split(pIVar9->buffer,'|',&(*(size_t (*))(__fp - 0x48)));
          sVar5 = (*(size_t (*))(__fp - 0x48));
                    /* Unresolved local var: size_t i@[???] */
          if ((*(size_t (*))(__fp - 0x48)) != 0) {
            sVar20 = 0;
LAB_0012a515:
            pcVar7 = strcasestr(pcVar6,ppcVar8[sVar20]);
            if (pcVar7 == (char *)0x0) goto LAB_0012a508;
                    /* Unresolved local var: size_t i@[???] */
            pcVar6 = *ppcVar8;
            ppcVar13 = ppcVar8;
            while (pcVar6 != (char *)0x0) {
              ppcVar13 = ppcVar13 + 1;
              free(pcVar6);
              pcVar6 = *ppcVar13;
            }
            free(ppcVar8);
            goto LAB_0012a551;
          }
          a2 = extraout_RDX;
          if (ppcVar8 != (char **)0x0) {
LAB_0012a950:
                    /* Unresolved local var: size_t i@[???] */
            pcVar6 = *ppcVar8;
            ppcVar13 = ppcVar8;
            while (pcVar6 != (char *)0x0) {
              ppcVar13 = ppcVar13 + 1;
              free(pcVar6);
              pcVar6 = *ppcVar13;
            }
            free(ppcVar8);
            a2 = extraout_RDX_02;
          }
        }
        pcVar6 = strcasestr(pcVar6,pIVar9->buffer);
        a2 = extraout_RDX_01;
      } while (pcVar6 == (char *)0x0);
LAB_0012a551:
                    /* Unresolved local var: int size@[???] */
      wVar17 = panel->items->items;
      wVar1 = wVar17 + -1;
      if (wVar17 <= wVar16) {
        wVar16 = wVar1;
      }
      if (wVar16 < 0) {
        wVar16 = 0;
      }
      pcVar2 = (panel->super).klass[1].extends;
      panel->selected = wVar16;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)((long)panel,0xffffffff,(ulong)(uint)wVar1,(long)panel,(long)lines,in_R9);
      }
LAB_0012a589:
      cVar18 = '\0';
      goto LAB_0012a69e;
    }
  }
  goto LAB_0012a698;
LAB_0012a790:
  sVar20 = sVar20 + 1;
  if (sVar20 == sVar5) goto LAB_0012aa48;
  goto LAB_0012a79d;
LAB_0012a618:
  sVar20 = sVar20 + 1;
  if (sVar20 == sVar5) goto LAB_0012ab00;
  goto LAB_0012a625;
LAB_0012a508:
  sVar20 = sVar20 + 1;
  if (sVar20 == sVar5) goto LAB_0012a950;
  goto LAB_0012a515;
LAB_0012a7e9:
                    /* Unresolved local var: int size@[???] */
  wVar1 = panel->items->items;
  wVar16 = wVar1 + -1;
  if (wVar17 < wVar1) {
    wVar16 = wVar17;
  }
  if (wVar16 < 0) {
    wVar16 = 0;
  }
  pcVar2 = (panel->super).klass[1].extends;
  panel->selected = wVar16;
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)((long)panel,0xffffffff,(ulong)(uint)wVar16,(long)panel,(long)pVVar15,in_R9);
  }
  uVar12 = 1;
LAB_0012a823:
  this->found = SUB81(uVar12,0);
LAB_0012a82d:
  if (!bVar11) goto LAB_0012a69e;
  (*(Object *(*))(__fp - 0x70)) = (Object *)0x0;
  this_00 = panel->items;
  uVar12 = (ulong)(uint)this_00->items;
  if (0 < this_00->items) {
    (*(Object *(*))(__fp - 0x70)) = this_00->array[panel->selected];
  }
  Vector_prune(this_00);
  panel->scrollV = 0;
  panel->selected = 0;
  panel->oldSelected = 0;
  panel->needsRedraw = true;
  if (this->filtering == false) {
                    /* Unresolved local var: int i@[???] */
    lVar14 = 0;
    if (0 < lines->items) {
      do {
                    /* Unresolved local var: Object * line@[???] */
        pOVar3 = lines->array[lVar14];
        Panel_add(panel,pOVar3);
        if (pOVar3 == (*(Object *(*))(__fp - 0x70))) {
                    /* Unresolved local var: int size@[???] */
          wVar1 = panel->items->items;
          wVar17 = wVar1 + -1;
          if ((int)lVar14 < wVar1) {
            wVar17 = (int)lVar14;
          }
          if (wVar17 < 0) {
            wVar17 = 0;
          }
          panel->selected = wVar17;
          pcVar2 = (panel->super).klass[1].extends;
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)((long)panel,0xffffffff,0,uVar12,(long)pVVar15,in_R9);
          }
        }
        lVar14 = lVar14 + 1;
      } while ((int)lVar14 < lines->items);
    }
  }
  else {
                    /* Unresolved local var: Object * selected@[???]
                       Unresolved local var: int n@[???]
                       Unresolved local var: char * incFilter@[???] */
    pIVar9 = this->modes + 1;
                    /* Unresolved local var: int i@[???] */
    if (0 < lines->items) {
                    /* Unresolved local var: ListItem * line@[???]
                       Unresolved local var: char * * needles@[???] */
      (*(int (*))(__fp - 0x7c)) = 0;
      lVar14 = 0;
      do {
        pOVar3 = lines->array[lVar14];
        __haystack = pOVar3[1].klass;
        pcVar6 = strchr(pIVar9->buffer,0x7c);
        if (pcVar6 == (char *)0x0) {
          pcVar6 = strcasestr((char *)__haystack,pIVar9->buffer);
          if (pcVar6 != (char *)0x0) {
LAB_0012a662:
            Panel_add(panel,pOVar3);
            if (pOVar3 == (*(Object *(*))(__fp - 0x70))) {
                    /* Unresolved local var: int size@[???] */
              wVar1 = panel->items->items;
              wVar17 = wVar1 + -1;
              if ((*(int (*))(__fp - 0x7c)) < wVar1) {
                wVar17 = (*(int (*))(__fp - 0x7c));
              }
              if (wVar17 < 0) {
                wVar17 = 0;
              }
              panel->selected = wVar17;
              pcVar2 = (panel->super).klass[1].extends;
              if (pcVar2 != (code *)0x0) {
                (*pcVar2)((long)panel,0xffffffff,0,(long)panel,(long)pVVar15,in_R9);
              }
            }
            (*(int (*))(__fp - 0x7c)) = (*(int (*))(__fp - 0x7c)) + 1;
          }
        }
        else {
          ppcVar8 = String_split(pIVar9->buffer,'|',&(*(size_t (*))(__fp - 0x48)));
          sVar5 = (*(size_t (*))(__fp - 0x48));
                    /* Unresolved local var: size_t i@[???] */
          if ((*(size_t (*))(__fp - 0x48)) != 0) {
            sVar20 = 0;
LAB_0012a625:
            pcVar6 = strcasestr((char *)__haystack,ppcVar8[sVar20]);
            if (pcVar6 == (char *)0x0) goto LAB_0012a618;
                    /* Unresolved local var: size_t i@[???] */
            pcVar6 = *ppcVar8;
            ppcVar13 = ppcVar8;
            while (pcVar6 != (char *)0x0) {
              ppcVar13 = ppcVar13 + 1;
              free(pcVar6);
              pcVar6 = *ppcVar13;
            }
            free(ppcVar8);
            goto LAB_0012a662;
          }
          if (ppcVar8 != (char **)0x0) {
LAB_0012ab00:
                    /* Unresolved local var: size_t i@[???] */
            pcVar6 = *ppcVar8;
            ppcVar13 = ppcVar8;
            while (pcVar6 != (char *)0x0) {
              ppcVar13 = ppcVar13 + 1;
              free(pcVar6);
              pcVar6 = *ppcVar13;
            }
            free(ppcVar8);
          }
        }
        lVar14 = lVar14 + 1;
      } while ((int)lVar14 < lines->items);
    }
  }
LAB_0012a698:
  cVar18 = '\x01';
LAB_0012a69e:
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (_Bool)cVar18;
}

