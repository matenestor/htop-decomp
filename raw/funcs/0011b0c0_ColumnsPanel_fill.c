/* ColumnsPanel_fill @ 0011b0c0 size 409 */

/* DWARF original prototype: void ColumnsPanel_fill(ColumnsPanel * this, ScreenSettings * ss,
   Hashtable * columns) */

void ColumnsPanel_fill(ColumnsPanel *this,ScreenSettings *ss,Hashtable_2 *columns)

{
  uint uVar1;
  Vector *this_00;
  HashtableItem *pHVar2;
  undefined8 *data_;
  char *pcVar3;
  HashtableItem *pHVar4;
  ulong uVar5;
  ulong uVar6;
  uint *puVar7;
  char *pcVar8;

  Vector_prune((this->super).items);
                    /* Unresolved local var: RowField * fields@[???] */
  puVar7 = (uint *)ss->fields;
  (this->super).needsRedraw = true;
  (this->super).scrollV = L'\0';
  (this->super).selected = L'\0';
  (this->super).oldSelected = L'\0';
  uVar1 = *puVar7;
  do {
    if (uVar1 == 0) {
      this->ss = (ScreenSettings_3 *)ss;
      return;
    }
    if (uVar1 < 0x84) {
                    /* Unresolved local var: char * name@[???] */
      pcVar3 = Process_fields[uVar1].name;
      if (Process_fields[uVar1].name == (char *)0x0) {
        pcVar3 = ((char *)0x147411 /* "- " */);
      }
    }
    else {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
      pHVar2 = columns->buckets;
      uVar6 = (ulong)uVar1 % columns->size;
      pcVar8 = pHVar2[uVar6].value;
      pcVar3 = ((char *)0x147411 /* "- " */);
      if (pcVar8 != (char *)0x0) {
        uVar5 = 0;
        pHVar4 = pHVar2 + uVar6;
        do {
          while( true ) {
            if (uVar1 == pHVar4->key) {
              pcVar3 = *(char **)(pcVar8 + 0x20);
              if (*(char **)(pcVar8 + 0x20) == (char *)0x0) {
                pcVar3 = pcVar8;
              }
              goto LAB_0011b13f;
            }
            if (pHVar4->probe < uVar5) goto LAB_0011b228;
            uVar6 = uVar6 + 1;
            if (columns->size != uVar6) break;
            uVar6 = 0;
            uVar5 = uVar5 + 1;
            pcVar8 = pHVar2->value;
            pHVar4 = pHVar2;
            if (pcVar8 == (char *)0x0) goto LAB_0011b228;
          }
          uVar5 = uVar5 + 1;
          pHVar4 = pHVar2 + uVar6;
          pcVar8 = pHVar4->value;
        } while (pcVar8 != (char *)0x0);
LAB_0011b228:
        pcVar3 = ((char *)0x147411 /* "- " */);
      }
    }
LAB_0011b13f:
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    data_ = malloc(0x18);
    if (data_ == (undefined8 *)0x0) {
LAB_0011b26b:
                    /* WARNING: Subroutine does not return */
      fail();
    }
                    /* Unresolved local var: char * data@[???] */
    *data_ = &ListItem_class;
    pcVar3 = strdup(pcVar3);
    if (pcVar3 == (char *)0x0) goto LAB_0011b26b;
    this_00 = (this->super).items;
    *(uint *)(data_ + 2) = uVar1;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
    puVar7 = puVar7 + 1;
    data_[1] = pcVar3;
    *(undefined1 *)((long)data_ + 0x14) = 0;
    Vector_set(this_00,this_00->items,data_);
    uVar1 = *puVar7;
    (this->super).needsRedraw = true;
  } while( true );
}

