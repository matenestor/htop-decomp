/* AvailableColumnsPanel_addDynamicColumn @ 0011b960 size 246 */

void AvailableColumnsPanel_addDynamicColumn(ht_key_t key,void *value,void *data)

{
  long lVar1;
  Object *o;
  ObjectClass *pOVar2;
  void *va0;
  void *va1;
  long in_FS_OFFSET;
  char description [256];

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(long *)((long)value + 0x40) != 0) {
LAB_0011b98c:
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???]
                       Unresolved local var: char * title@[???]
                       Unresolved local var: char * text@[???] */
  va1 = *(void **)((long)value + 0x30);
  va0 = *(void **)((long)value + 0x20);
  if (*(void **)((long)value + 0x20) == (void *)0x0) {
    va0 = value;
  }
  if ((va1 == (void *)0x0) && (va1 = *(void **)((long)value + 0x28), va1 == (void *)0x0)) {
    xSnprintf(description,0x100,((char *)0x147626 /* "%s" */),va0);
  }
  else {
    xSnprintf(description,0x100,((char *)0x147434 /* "%s - %s" */),va0,va1);
  }
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
  o = malloc(0x18);
  if (o != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    o->klass = &ListItem_class;
    pOVar2 = (ObjectClass *)strdup(description);
    if (pOVar2 != (ObjectClass *)0x0) {
      o[1].klass = pOVar2;
      *(ht_key_t *)&o[2].klass = key;
      *(undefined1 *)((long)&o[2].klass + 4) = 0;
      Panel_add(data,o);
      goto LAB_0011b98c;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

