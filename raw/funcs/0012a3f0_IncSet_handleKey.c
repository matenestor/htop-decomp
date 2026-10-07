/* IncSet_handleKey @ 0012a3f0 size 2054 */

/* DWARF original prototype: _Bool IncSet_handleKey(IncSet * this, wchar_t ch, Panel * panel,
   IncMode_GetPanelValue getPanelValue, Vector * lines) */

_Bool IncSet_handleKey(IncSet *this,wchar_t ch,Panel *panel,IncMode_GetPanelValue_2 getPanelValue,
                      Vector *lines)

{
  wchar_t wVar1;
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
  wchar_t wVar16;
  wchar_t wVar17;
  char cVar18;
  char cVar19;
  size_t sVar20;
  long in_FS_OFFSET;
  wchar_t local_7c;
  Object *local_70;
  size_t nNeedles;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (ch != L'\xffffffff') {
    pIVar9 = this->active;
    wVar1 = panel->items->items;
    a2 = (ushort *)(ulong)(uint)wVar1;
    bVar11 = ch == L'ċ' || ch == L'ė';
    uVar12 = CONCAT71((int7)((ulong)getPanelValue >> 8),bVar11);
    if (ch != L'ċ' && ch != L'ė') {
      pVVar15 = lines;
      if ((uint)(ch + L'\xffffffff') < 0xfe) {
        ppuVar10 = __ctype_b_loc();
        uVar12 = (ulong)bVar11;
        a2 = *ppuVar10;
        if ((*(byte *)((long)a2 + (long)ch * 2 + 1) & 0x40) == 0) {
          if (ch != L'\x7f') {
            cVar18 = pIVar9->isFilter;
            if ((_Bool)cVar18 == false) {
              if (ch == L'\x1b') {
                pIVar9->index = L'\0';
                pIVar9->buffer[0] = '\0';
              }
              goto LAB_0012ab56;
            }
            if (ch == L'\x1b') {
              this->filtering = false;
              pIVar9->index = L'\0';
              pIVar9->buffer[0] = '\0';
            }
LAB_0012abb3:
            bVar11 = lines != (Vector *)0x0;
            goto LAB_0012ab5d;
          }
          goto LAB_0012aa7c;
        }
        wVar17 = pIVar9->index;
        if (wVar17 < L'\x80') {
          wVar16 = wVar17 + L'\x01';
          pIVar9->buffer[wVar17] = (char)ch;
          a2 = (ushort *)(long)wVar16;
          pIVar9->index = wVar16;
          pIVar9->buffer[(long)a2] = '\0';
          if (pIVar9->isFilter != false) {
            if (wVar16 == L'\x01') {
              this->filtering = true;
            }
            goto LAB_0012a9f7;
          }
        }
LAB_0012a702:
                    /* Unresolved local var: wchar_t size@[???]
                       Unresolved local var: wchar_t i@[???] */
        bVar11 = false;
        cVar19 = '\0';
        if (wVar1 < L'\x01') {
          this->found = false;
          goto LAB_0012a589;
        }
LAB_0012a714:
                    /* Unresolved local var: char * * needles@[???] */
        wVar17 = L'\0';
        a3 = uVar12;
        do {
          pIVar9 = this->active;
          pcVar6 = (*getPanelValue)(panel,wVar17,(long)a2,a3,(long)pVVar15,in_R9);
          pcVar7 = strchr(pIVar9->buffer,0x7c);
          cVar18 = cVar19;
          if (pcVar7 == (char *)0x0) {
            pcVar6 = strcasestr(pcVar6,pIVar9->buffer);
            a2 = extraout_RDX_03;
            if (pcVar6 != (char *)0x0) goto LAB_0012a7e9;
          }
          else {
            ppcVar8 = String_split(pIVar9->buffer,'|',&nNeedles);
            sVar5 = nNeedles;
                    /* Unresolved local var: size_t i@[???] */
            if (nNeedles != 0) {
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
          wVar17 = wVar17 + L'\x01';
        } while (wVar1 != wVar17);
        uVar12 = uVar12 & 0xff;
        goto LAB_0012a823;
      }
      if (ch == L'ć') {
LAB_0012aa7c:
        if (pIVar9->index < L'\x01') goto LAB_0012a589;
        wVar17 = pIVar9->index + L'\xffffffff';
        a2 = (ushort *)(long)wVar17;
        pIVar9->index = wVar17;
        pIVar9->buffer[(long)a2] = '\0';
        if (pIVar9->isFilter == false) goto LAB_0012a702;
        if (wVar17 == L'\0') {
          this->filtering = false;
          pIVar9->index = L'\0';
          pIVar9->buffer[0] = '\0';
        }
LAB_0012a9f7:
        bVar11 = lines != (Vector *)0x0;
        cVar18 = '\x01';
        cVar19 = '\x01';
        if (wVar1 < L'\x01') goto LAB_0012a823;
        goto LAB_0012a714;
      }
      if (ch == L'ƚ') {
        pVVar15 = (Vector *)(ulong)(uint)pIVar9->index;
        if (L'\0' < pIVar9->index) goto LAB_0012a702;
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
      FunctionBar_drawExtra(this_01,(char *)0x0,L'\xffffffff',false);
      goto LAB_0012a82d;
    }
    if (wVar1 != L'\0') {
                    /* Unresolved local var: wchar_t size@[???]
                       Unresolved local var: wchar_t here@[???]
                       Unresolved local var: wchar_t i@[???] */
      wVar17 = panel->selected;
      uVar12 = (ulong)(uint)wVar17;
      wVar16 = wVar17;
      do {
        while( true ) {
          wVar16 = wVar16 + ((ch == L'ċ') - 1) + (uint)(ch == L'ċ');
          if (wVar1 == wVar16) {
            wVar16 = L'\0';
          }
          else if (wVar16 == L'\xffffffff') {
            wVar16 = wVar1 + L'\xffffffff';
          }
          if (wVar16 == wVar17) goto LAB_0012a589;
          pcVar6 = (*getPanelValue)(panel,wVar16,(long)a2,uVar12,(long)lines,in_R9);
          pcVar7 = strchr(pIVar9->buffer,0x7c);
          if (pcVar7 == (char *)0x0) break;
                    /* Unresolved local var: char * * needles@[???] */
          ppcVar8 = String_split(pIVar9->buffer,'|',&nNeedles);
          sVar5 = nNeedles;
                    /* Unresolved local var: size_t i@[???] */
          if (nNeedles != 0) {
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
                    /* Unresolved local var: wchar_t size@[???] */
      wVar17 = panel->items->items;
      wVar1 = wVar17 + L'\xffffffff';
      if (wVar17 <= wVar16) {
        wVar16 = wVar1;
      }
      if (wVar16 < L'\0') {
        wVar16 = L'\0';
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
                    /* Unresolved local var: wchar_t size@[???] */
  wVar1 = panel->items->items;
  wVar16 = wVar1 + L'\xffffffff';
  if (wVar17 < wVar1) {
    wVar16 = wVar17;
  }
  if (wVar16 < L'\0') {
    wVar16 = L'\0';
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
  local_70 = (Object *)0x0;
  this_00 = panel->items;
  uVar12 = (ulong)(uint)this_00->items;
  if (L'\0' < this_00->items) {
    local_70 = this_00->array[panel->selected];
  }
  Vector_prune(this_00);
  panel->scrollV = L'\0';
  panel->selected = L'\0';
  panel->oldSelected = L'\0';
  panel->needsRedraw = true;
  if (this->filtering == false) {
                    /* Unresolved local var: wchar_t i@[???] */
    lVar14 = 0;
    if (L'\0' < lines->items) {
      do {
                    /* Unresolved local var: Object * line@[???] */
        pOVar3 = lines->array[lVar14];
        Panel_add(panel,pOVar3);
        if (pOVar3 == local_70) {
                    /* Unresolved local var: wchar_t size@[???] */
          wVar1 = panel->items->items;
          wVar17 = wVar1 + L'\xffffffff';
          if ((wchar_t)lVar14 < wVar1) {
            wVar17 = (wchar_t)lVar14;
          }
          if (wVar17 < L'\0') {
            wVar17 = L'\0';
          }
          panel->selected = wVar17;
          pcVar2 = (panel->super).klass[1].extends;
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)((long)panel,0xffffffff,0,uVar12,(long)pVVar15,in_R9);
          }
        }
        lVar14 = lVar14 + 1;
      } while ((wchar_t)lVar14 < lines->items);
    }
  }
  else {
                    /* Unresolved local var: Object * selected@[???]
                       Unresolved local var: wchar_t n@[???]
                       Unresolved local var: char * incFilter@[???] */
    pIVar9 = this->modes + 1;
                    /* Unresolved local var: wchar_t i@[???] */
    if (L'\0' < lines->items) {
                    /* Unresolved local var: ListItem * line@[???]
                       Unresolved local var: char * * needles@[???] */
      local_7c = L'\0';
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
            if (pOVar3 == local_70) {
                    /* Unresolved local var: wchar_t size@[???] */
              wVar1 = panel->items->items;
              wVar17 = wVar1 + L'\xffffffff';
              if (local_7c < wVar1) {
                wVar17 = local_7c;
              }
              if (wVar17 < L'\0') {
                wVar17 = L'\0';
              }
              panel->selected = wVar17;
              pcVar2 = (panel->super).klass[1].extends;
              if (pcVar2 != (code *)0x0) {
                (*pcVar2)((long)panel,0xffffffff,0,(long)panel,(long)pVVar15,in_R9);
              }
            }
            local_7c = local_7c + L'\x01';
          }
        }
        else {
          ppcVar8 = String_split(pIVar9->buffer,'|',&nNeedles);
          sVar5 = nNeedles;
                    /* Unresolved local var: size_t i@[???] */
          if (nNeedles != 0) {
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
      } while ((wchar_t)lVar14 < lines->items);
    }
  }
LAB_0012a698:
  cVar18 = '\x01';
LAB_0012a69e:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (_Bool)cVar18;
}

