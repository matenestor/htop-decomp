/* IOPriorityPanel_new @ 00140f60 size 1018 */

/* WARNING: Removing unreachable block (ram,0x0014102f) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff60 : 0x0014104c */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * IOPriorityPanel_new(IOPriority currPrio)

{
  wchar_t __wc;
  long lVar1;
  Vector *this;
  code *pcVar2;
  wchar_t len;
  int iVar3;
  wchar_t wVar4;
  FunctionBar *fuBar;
  Panel *this_00;
  size_t sVar5;
  Object *pOVar6;
  ObjectClass *pOVar7;
  undefined8 *puVar8;
  char *pcVar9;
  Panel *va0;
  long a2;
  wchar_t *pwVar10;
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
  long in_FS_OFFSET;
  wchar_t local_d8 [12];
  char **local_98;
  Panel *local_90;
  uint local_84;
  undefined8 *local_80;
  char *functions [3];

  pppcVar11 = &local_98;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  functions[2] = (char *)0x0;
  functions[0] = ((char *)0x147e48 /* "Set    " */);
  functions[1] = ((char *)0x147223 /* "Cancel " */);
  local_84 = currPrio;
  fuBar = FunctionBar_new(functions,FunctionBar_EnterEscKeys,((char *)0x14d258 /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  this_00 = malloc(0x26e0);
  if (this_00 != (Panel *)0x0) {
    pOVar12 = &ListItem_class;
    a4 = 1;
    (this_00->super).klass = &Panel_class.super;
    Panel_init(this_00,L'\x01',L'\x01',L'\x01',L'\x01',&ListItem_class,true,fuBar);
                    /* Unresolved local var: wchar_t[46913] data@[???]
                       Unresolved local var: wchar_t newLen@[???] */
    local_80 = &local_98;
    wVar4 = CRT_colors[7];
    pwVar10 = local_d8;
    local_80 = &local_98;
    sVar5 = mbstowcs(local_d8,((char *)0x149e22 /* "IO Priority:" */),0xc);
    len = (wchar_t)sVar5;
    buf = functions;
    if (L'\0' < len) {
      RichString_setLen(&this_00->header,len);
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: wchar_t j@[???] */
      local_98 = functions;
      fuBar = (FunctionBar *)(ulong)(uint)(wVar4 & 0xffffffU);
      local_90 = this_00;
      pcVar14 = (this_00->header).chptr;
      do {
        __wc = *pwVar10;
        iVar3 = iswprint(__wc);
        pcVar14->attr = 0;
        pcVar14->chars[0] = L'\0';
        pcVar14->chars[1] = L'\0';
        pcVar14->chars[2] = L'\0';
        if (iVar3 == 0) {
          __wc = L'�';
        }
        pwVar10 = pwVar10 + 1;
        pcVar14->attr = wVar4 & 0xffffffU;
        *(undefined1 (*) [16])(pcVar14->chars + 2) = (undefined1  [16])0x0;
        pcVar14->chars[0] = __wc;
        this_00 = local_90;
        pcVar14 = pcVar14 + 1;
        buf = local_98;
      } while (local_d8 + (ulong)(uint)(len + L'\xffffffff') + 1 != pwVar10);
    }
    pppcVar11 = (char ***)local_80;
    this_00->needsRedraw = true;
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    local_80[-1] = 0x141103;
    pOVar6 = malloc(0x18);
    if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      pOVar6->klass = &ListItem_class;
      pppcVar11[-1] = (char **)0x141126;
      pOVar7 = (ObjectClass *)strdup(((char *)0x149e2f /* "None (based on nice)" */));
      if (pOVar7 != (ObjectClass *)0x0) {
        pOVar6[1].klass = pOVar7;
        *(undefined4 *)&pOVar6[2].klass = 0;
        *(undefined1 *)((long)&pOVar6[2].klass + 4) = 0;
        pppcVar11[-1] = (char **)0x14114e;
        Panel_add(this_00,pOVar6);
        if (local_84 == 0) {
                    /* Unresolved local var: wchar_t size@[???] */
          pOVar7 = (this_00->super).klass;
          this_00->selected = L'\0';
          pcVar2 = pOVar7[1].extends;
          if (pcVar2 != (code *)0x0) {
            pppcVar11[-1] = (char **)0x141321;
            (*pcVar2)((long)this_00,0xffffffff,a2,(long)fuBar,a4,(long)pOVar12);
          }
        }
                    /* Unresolved local var: wchar_t c@[???] */
        paVar15 = classes;
        pcVar9 = ((char *)0x149e19 /* "Realtime" */);
        do {
                    /* Unresolved local var: wchar_t i@[???]
                       Unresolved local var: IOPriority ioprio@[???] */
          a4_00 = 0;
          va2 = ((char *)0x149e12 /* "(High)" */);
          local_90 = (Panel *)pcVar9;
          while( true ) {
            va0 = local_90;
            va1 = (uint)a4_00;
            pppcVar11[-1] = (char **)0x1411c4;
            xSnprintf((char *)buf,0x32,((char *)0x149e44 /* "%s %d %s" */),va0,va1,va2);
            wVar4 = paVar15->klass;
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
            pppcVar11[-1] = (char **)0x1411d1;
            puVar8 = malloc(0x18);
            uVar13 = wVar4 << 0xd | va1;
            if (puVar8 == (undefined8 *)0x0) goto LAB_00141360;
                    /* Unresolved local var: char * data@[???] */
            *puVar8 = &ListItem_class;
            local_80 = puVar8;
            pppcVar11[-1] = (char **)0x1411fa;
            pcVar9 = strdup((char *)buf);
            puVar8 = local_80;
            if (pcVar9 == (char *)0x0) goto LAB_00141360;
            this = this_00->items;
            local_80[1] = pcVar9;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
            wVar4 = this->items;
            *(uint *)(local_80 + 2) = uVar13;
            *(undefined1 *)((long)local_80 + 0x14) = 0;
            pppcVar11[-1] = (char **)0x14121f;
            Vector_set(this,wVar4,puVar8);
            this_00->needsRedraw = true;
            if (local_84 == uVar13) {
                    /* Unresolved local var: wchar_t size@[???] */
              wVar4 = this_00->items->items + L'\xffffffff';
              if (wVar4 < L'\0') {
                wVar4 = L'\0';
              }
              this_00->selected = wVar4;
              pcVar2 = (this_00->super).klass[1].extends;
              if (pcVar2 != (code *)0x0) {
                pppcVar11[-1] = (char **)0x141260;
                (*pcVar2)((long)this_00,0xffffffff,0,(long)va0,a4_00,(long)va2);
              }
            }
            if (va1 == 7) break;
            a4_00 = (ulong)(va1 + 1);
            va2 = ((char *)0x149e0c /* "(Low)" */);
            if (va1 + 1 != 7) {
              va2 = ((char *)0x149c0c /* "" */);
            }
          }
          pcVar9 = paVar15[1].name;
          paVar15 = paVar15 + 1;
        } while ((Panel *)pcVar9 != (Panel *)0x0);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
        pppcVar11[-1] = (char **)0x14128b;
        pOVar6 = malloc(0x18);
        if (pOVar6 != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
          pOVar6->klass = &ListItem_class;
          pppcVar11[-1] = (char **)0x1412ae;
          pOVar12 = (ObjectClass *)strdup(((char *)0x14825a /* "Idle" */));
          if (pOVar12 != (ObjectClass *)0x0) {
            pOVar6[1].klass = pOVar12;
            *(undefined4 *)&pOVar6[2].klass = 0x6007;
            *(undefined1 *)((long)&pOVar6[2].klass + 4) = 0;
            pppcVar11[-1] = (char **)0x1412d6;
            Panel_add(this_00,pOVar6);
            if (local_84 == 0x6007) {
                    /* Unresolved local var: wchar_t size@[???] */
              wVar4 = this_00->items->items + L'\xffffffff';
              if (wVar4 < L'\0') {
                wVar4 = L'\0';
              }
              this_00->selected = wVar4;
              pcVar2 = (this_00->super).klass[1].extends;
              if (pcVar2 != (code *)0x0) {
                pppcVar11[-1] = (char **)0x14135b;
                (*pcVar2)((long)this_00,0xffffffff,0,(long)pcVar9,a4_00,(long)va2);
              }
            }
            if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
              return this_00;
            }
                    /* WARNING: Subroutine does not return */
            pppcVar11[-1] = (char **)&UNK_0014136a;
            __stack_chk_fail();
          }
        }
      }
    }
  }
LAB_00141360:
                    /* WARNING: Subroutine does not return */
  pppcVar11[-1] = (char **)0x141365;
  fail();
}

