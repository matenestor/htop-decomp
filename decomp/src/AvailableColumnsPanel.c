#include "htop.h"

/* AvailableColumnsPanel_delete @ 0x117560 */

void AvailableColumnsPanel_delete(AvailableColumnsPanel_ *object)

{
  free((object->super).eventHandlerState);
  Vector_delete((object->super).items);
  FunctionBar_delete((object->super).defaultBar);
  if ((object->super).header.chlen < 351) {
    free(object);
    return;
  }
  free((object->super).header.chptr);
  free(object);
  return;
}


/* AvailableColumnsPanel_eventHandler @ 0x11a2f0 */

HandlerResult AvailableColumnsPanel_eventHandler(AvailableColumnsPanel_ *super,int ch)

{
  int wVar1;
  int iVar2;
  int wVar3;
  Vector *pVVar4;
  Object *pOVar5;
  Panel *pPVar6;
  code *pcVar7;
  int wVar8;
  HandlerResult HVar9;
  ushort **ppuVar10;
  undefined8 *data_;
  char *pcVar11;
  ColumnsPanel_ *super_00;
  long in_R8;
  long in_R9;

  if (((ch & 0xfffffeffU) == 0xd) || (ch == 343)) {
                    /* Unresolved local var: ListItem * selected@[???]
                       Unresolved local var: int at@[???] */
    pVVar4 = (super->super).items;
    if ((0 < pVVar4->items) &&
       (pOVar5 = pVVar4->array[(super->super).selected], pOVar5 != (Object *)0x0)) {
      iVar2 = *(int *)&pOVar5[2].klass;
                    /* Unresolved local var: char * name@[???] */
      pcVar11 = (char *)0x0;
      wVar8 = super->columns->selected;
      if (iVar2 < 0x84) {
        pcVar11 = Process_fields[iVar2].name;
      }
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
      data_ = malloc(0x18);
      if (data_ != (undefined8 *)0x0) {
                    /* Unresolved local var: char * data@[???] */
        *data_ = &ListItem_class;
        pcVar11 = strdup(pcVar11);
        if (pcVar11 != (char *)0x0) {
          *(int *)(data_ + 2) = iVar2;
          pPVar6 = super->columns;
          data_[1] = pcVar11;
          *(undefined1 *)((long)data_ + 0x14) = 0;
          Vector_insert(pPVar6->items,wVar8,data_);
          super_00 = (ColumnsPanel_ *)super->columns;
          wVar8 = wVar8 + 1;
          pPVar6->needsRedraw = true;
                    /* Unresolved local var: int size@[???] */
          wVar3 = ((super_00->super).items)->items;
          wVar1 = wVar3 + -1;
          if (wVar3 <= wVar8) {
            wVar8 = wVar1;
          }
          if (wVar8 < 0) {
            wVar8 = 0;
          }
          (super_00->super).selected = wVar8;
          pcVar7 = (super_00->super).super.klass[1].extends;
          if (pcVar7 != (code *)0x0) {
            (*pcVar7)((long)super_00,0xffffffff,0,(ulong)(uint)wVar1,in_R8,in_R9);
            super_00 = (ColumnsPanel_ *)super->columns;
          }
          ColumnsPanel_update(super_00);
          return HANDLED;
        }
      }
                    /* WARNING: Subroutine does not return */
      fail();
    }
  }
  else if ((uint)(ch + -1) < 0xfe) {
    ppuVar10 = __ctype_b_loc();
    if (-1 < (short)(*ppuVar10)[ch]) {
      return IGNORED;
    }
    HVar9 = Panel_selectByTyping(&super->super,ch);
    return HVar9;
  }
  return IGNORED;
}


/* AvailableColumnsPanel_addDynamicColumn @ 0x11b960 */

void AvailableColumnsPanel_addDynamicColumn(ht_key_t key,void *value,void *data)

{
  undefined1 __frame[0x1c8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x188;
  long lVar1;
  Object *o;
  ObjectClass *pOVar2;
  void *va0;
  void *va1;
  long in_FS_OFFSET = (long)__fake_fs;

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
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0x100,((char *)(long)(__sec_rodata + 0x626) /* "%s" */),va0);
  }
  else {
    xSnprintf((*(char (*) [256])(__fp - 0x138)),0x100,((char *)(long)&s__s____s_00147434 /* "%s - %s" */),va0,va1);
  }
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
  o = malloc(0x18);
  if (o != (Object *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    o->klass = &ListItem_class;
    pOVar2 = (ObjectClass *)strdup((*(char (*) [256])(__fp - 0x138)));
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


/* AvailableColumnsPanel_addPlatformColumns @ 0x11ba60 */

/* DWARF original prototype: void AvailableColumnsPanel_addPlatformColumns(AvailableColumnsPanel *
   this) */

void AvailableColumnsPanel_addPlatformColumns(AvailableColumnsPanel *this)

{
  undefined1 __frame[0x1d8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x198;
  long lVar1;
  Vector *this_00;
  undefined8 *data_;
  char *pcVar2;
  int iVar3;
  ProcessFieldData *pPVar4;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: int i@[???] */
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
      xSnprintf((*(char (*) [256])(__fp - 0x148)),0x100,((char *)(long)&s__s____s_00147434 /* "%s - %s" */),pPVar4->name,pPVar4->description);
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
      pcVar2 = strdup((*(char (*) [256])(__fp - 0x148)));
      if (pcVar2 == (char *)0x0) goto LAB_0011bb69;
      this_00 = (this->super).items;
      data_[1] = pcVar2;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: int i@[???] */
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


/* AvailableColumnsPanel_fill @ 0x11bb80 */

/* DWARF original prototype: void AvailableColumnsPanel_fill(AvailableColumnsPanel * this, char *
   dynamicScreen, Hashtable * dynamicColumns) */

void AvailableColumnsPanel_fill
               (AvailableColumnsPanel *this,char *dynamicScreen,Hashtable_2 *dynamicColumns)

{
  void *value;
  ulong uVar1;

  Vector_prune((this->super).items);
  (this->super).scrollV = 0;
  (this->super).selected = 0;
  (this->super).oldSelected = 0;
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


/* AvailableColumnsPanel_new @ 0x11bc20 */

/* WARNING: Removing unreachable block (ram,0x0011bcbf) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff90 : 0x0011bcdc */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

AvailableColumnsPanel * AvailableColumnsPanel_new(Panel *columns,Hashtable_2 *dynamicColumns)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  int wVar1;
  ht_key_t key;
  Vector *this;
  void *value;
  undefined1 *puVar2;
  int len;
  int iVar3;
  AvailableColumnsPanel *this_00;
  FunctionBar *fuBar;
  size_t sVar4;
  cchar_t *pcVar5;
  ulong uVar6;
  int *pwVar7;
  long in_FS_OFFSET = (long)__fake_fs;

                    /* Unresolved local var: void * data@[???] */
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(Panel *(*))(__fp - 0x68)) = columns;
  this_00 = malloc(0x26e8);
  if (this_00 == (AvailableColumnsPanel *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  (this_00->super).super.klass = &AvailableColumnsPanel_class.super;
  fuBar = FunctionBar_new(AvailableColumnsFunctions,(char **)0x0,(int *)0x0);
  Panel_init(&this_00->super,1,1,1,1,&ListItem_class,true,fuBar);
  wVar1 = CRT_colors[7];
                    /* Unresolved local var: int[67822] data@[???]
                       Unresolved local var: int newLen@[???] */
  (*(undefined1 *(*))(__fp - 0x60)) = (undefined1 *)&(*(Panel *(*))(__fp - 0x68));
  pwVar7 = (*(int (*) [16])(__fp - 0xb8));
  (*(undefined1 *(*))(__fp - 0x60)) = (undefined1 *)&(*(Panel *(*))(__fp - 0x68));
  sVar4 = mbstowcs((*(int (*) [16])(__fp - 0xb8)),((char *)(long)&s_Available_Columns_0014743c /* "Available Columns" */),0x11);
  len = (int)sVar4;
  if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(&(this_00->super).header,len);
    (*(attr_t (*))(__fp - 0x54)) = wVar1 & 0xffffff;
    (*(int *(*))(__fp - 0x50)) = (*(int (*) [16])(__fp - 0xb8)) + (ulong)(uint)(len + -1) + 1;
    pcVar5 = (this_00->super).header.chptr;
    do {
      wVar1 = *pwVar7;
      iVar3 = iswprint(wVar1);
      pcVar5->attr = 0;
      pcVar5->chars[0] = 0;
      pcVar5->chars[1] = 0;
      pcVar5->chars[2] = 0;
      if (iVar3 == 0) {
        wVar1 = 65533;
      }
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar5->chars + 2)) = (undefined16)0x0;
      pwVar7 = pwVar7 + 1;
      pcVar5->attr = (*(attr_t (*))(__fp - 0x54));
      pcVar5->chars[0] = wVar1;
      pcVar5 = pcVar5 + 1;
    } while ((*(int *(*))(__fp - 0x50)) != pwVar7);
  }
  puVar2 = (*(undefined1 *(*))(__fp - 0x60));
  (this_00->super).needsRedraw = true;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: size_t i@[???] */
  uVar6 = 0;
  this = (this_00->super).items;
  this_00->columns = (*(Panel *(*))(__fp - 0x68));
  Vector_prune(this);
  (this_00->super).scrollV = 0;
  (this_00->super).selected = 0;
  (this_00->super).oldSelected = 0;
  (this_00->super).needsRedraw = true;
  AvailableColumnsPanel_addPlatformColumns(this_00);
  if (dynamicColumns->size != 0) {
    do {
                    /* Unresolved local var: HashtableItem * walk@[???] */
      value = dynamicColumns->buckets[uVar6].value;
      if (value != (void *)0x0) {
        key = dynamicColumns->buckets[uVar6].key;
        AvailableColumnsPanel_addDynamicColumn(key,value,this_00);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < dynamicColumns->size);
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this_00;
}

