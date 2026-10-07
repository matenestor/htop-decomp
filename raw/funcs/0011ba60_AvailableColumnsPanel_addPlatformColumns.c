/* AvailableColumnsPanel_addPlatformColumns @ 0011ba60 size 265 */

/* DWARF original prototype: void AvailableColumnsPanel_addPlatformColumns(AvailableColumnsPanel *
   this) */

void AvailableColumnsPanel_addPlatformColumns(AvailableColumnsPanel *this)

{
  long lVar1;
  Vector *this_00;
  undefined8 *data_;
  char *pcVar2;
  int iVar3;
  ProcessFieldData *pPVar4;
  long in_FS_OFFSET;
  char description [256];

                    /* Unresolved local var: wchar_t i@[???] */
  iVar3 = 1;
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  pPVar4 = Process_fields;
  do {
    pPVar4 = pPVar4 + 1;
    if (iVar3 == 2) {
      pPVar4 = pPVar4 + 1;
      iVar3 = 3;
    }
    if (pPVar4->description != (char *)0x0) {
      xSnprintf(description,0x100,((char *)0x147434 /* "%s - %s" */),pPVar4->name,pPVar4->description);
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      data_ = malloc(0x18);
      if (data_ == (undefined8 *)0x0) {
LAB_0011bb69:
                    /* WARNING: Subroutine does not return */
        fail();
      }
                    /* Unresolved local var: char * data@[???] */
      *data_ = &ListItem_class;
      pcVar2 = strdup(description);
      if (pcVar2 == (char *)0x0) goto LAB_0011bb69;
      this_00 = (this->super).items;
      data_[1] = pcVar2;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
      *(int *)(data_ + 2) = iVar3;
      *(undefined1 *)((long)data_ + 0x14) = 0;
      Vector_set(this_00,this_00->items,data_);
      (this->super).needsRedraw = true;
    }
    iVar3 = iVar3 + 1;
    if (iVar3 == 0x84) {
      if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}

