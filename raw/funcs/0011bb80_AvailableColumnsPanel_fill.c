/* AvailableColumnsPanel_fill @ 0011bb80 size 138 */

/* DWARF original prototype: void AvailableColumnsPanel_fill(AvailableColumnsPanel * this, char *
   dynamicScreen, Hashtable * dynamicColumns) */

void AvailableColumnsPanel_fill
               (AvailableColumnsPanel *this,char *dynamicScreen,Hashtable_2 *dynamicColumns)

{
  void *value;
  ulong uVar1;

  Vector_prune((this->super).items);
  (this->super).scrollV = L'\0';
  (this->super).selected = L'\0';
  (this->super).oldSelected = L'\0';
  (this->super).needsRedraw = true;
  if (dynamicScreen == (char *)0x0) {
                    /* Unresolved local var: Panel * super@[???] */
    AvailableColumnsPanel_addPlatformColumns(this);
                    /* Unresolved local var: size_t i@[???] */
    uVar1 = 0;
    if (dynamicColumns->size != 0) {
      do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
        value = dynamicColumns->buckets[uVar1].value;
        if (value != (void *)0x0) {
          AvailableColumnsPanel_addDynamicColumn(dynamicColumns->buckets[uVar1].key,value,this);
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < dynamicColumns->size);
      return;
    }
  }
  return;
}

