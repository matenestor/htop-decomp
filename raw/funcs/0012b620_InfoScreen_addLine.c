/* InfoScreen_addLine @ 0012b620 size 447 */

/* DWARF original prototype: void InfoScreen_addLine(InfoScreen * this, char * line) */

void InfoScreen_addLine(InfoScreen *this,char *line)

{
  IncMode *__s;
  Vector *this_00;
  undefined8 *data_;
  char *pcVar1;
  char **__ptr;
  size_t sVar2;
  char **ppcVar3;
  long in_FS_OFFSET;
  size_t nNeedles;
  long local_40;

                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  data_ = malloc(0x18);
  if (data_ == (undefined8 *)0x0) {
LAB_0012b7e3:
                    /* WARNING: Subroutine does not return */
    fail();
  }
                    /* Unresolved local var: char * data@[???] */
  *data_ = &ListItem_class;
  pcVar1 = strdup(line);
  if (pcVar1 == (char *)0x0) goto LAB_0012b7e3;
  this_00 = this->lines;
  data_[1] = pcVar1;
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
  *(undefined4 *)(data_ + 2) = 0;
  *(undefined1 *)((long)data_ + 0x14) = 0;
  Vector_set(this_00,this_00->items,data_);
  if (this->inc->filtering == false) {
LAB_0012b739:
                    /* Unresolved local var: char * incFilter@[???] */
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      Panel_add(this->display,this->lines->array[this->lines->items + L'\xffffffff']);
      return;
    }
  }
  else {
    __s = this->inc->modes + 1;
    pcVar1 = strchr(__s->buffer,0x7c);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strcasestr(line,__s->buffer);
      if (pcVar1 != (char *)0x0) goto LAB_0012b739;
    }
    else {
                    /* Unresolved local var: char * * needles@[???] */
      __ptr = String_split(__s->buffer,'|',&nNeedles);
                    /* Unresolved local var: size_t i@[???] */
      if (nNeedles != 0) {
        sVar2 = 0;
LAB_0012b6fd:
        pcVar1 = strcasestr(line,__ptr[sVar2]);
        if (pcVar1 == (char *)0x0) goto LAB_0012b6f0;
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar3 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar3 = ppcVar3 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar3;
        }
        free(__ptr);
        goto LAB_0012b739;
      }
      if (__ptr != (char **)0x0) {
LAB_0012b7b8:
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar3 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar3 = ppcVar3 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar3;
        }
        free(__ptr);
      }
    }
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0012b6f0:
  sVar2 = sVar2 + 1;
  if (nNeedles == sVar2) goto LAB_0012b7b8;
  goto LAB_0012b6fd;
}

