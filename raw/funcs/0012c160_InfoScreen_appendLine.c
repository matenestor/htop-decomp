/* InfoScreen_appendLine @ 0012c160 size 420 */

/* DWARF original prototype: void InfoScreen_appendLine(InfoScreen * this, char * line) */

void InfoScreen_appendLine(InfoScreen *this,char *line)

{
  IncMode *__s;
  ListItem *this_00;
  char *pcVar1;
  char **__ptr;
  char **ppcVar2;
  size_t sVar3;
  Panel *this_01;
  long in_FS_OFFSET;
  size_t nNeedles;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (ListItem *)this->lines->array[this->lines->items + L'\xffffffff'];
  ListItem_append(this_00,line);
  if ((this->inc->filtering != false) &&
     (this_01 = this->display,
     this_00 != (ListItem *)this_01->items->array[this_01->items->items + L'\xffffffff'])) {
    __s = this->inc->modes + 1;
    pcVar1 = strchr(__s->buffer,0x7c);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strcasestr(line,__s->buffer);
      if (pcVar1 != (char *)0x0) {
LAB_0012c26e:
        if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
          Panel_add(this_01,(Object *)this_00);
          return;
        }
        goto LAB_0012c305;
      }
    }
    else {
                    /* Unresolved local var: char * * needles@[???] */
      __ptr = String_split(__s->buffer,'|',&nNeedles);
                    /* Unresolved local var: size_t i@[???] */
      if (nNeedles != 0) {
        sVar3 = 0;
LAB_0012c22a:
        pcVar1 = strcasestr(line,__ptr[sVar3]);
        if (pcVar1 == (char *)0x0) goto LAB_0012c220;
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar2 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar2 = ppcVar2 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar2;
        }
        free(__ptr);
        this_01 = this->display;
        goto LAB_0012c26e;
      }
      if (__ptr != (char **)0x0) {
LAB_0012c2a0:
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar2 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar2 = ppcVar2 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar2;
        }
        free(__ptr);
      }
    }
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_0012c305:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0012c220:
  sVar3 = sVar3 + 1;
  if (nNeedles == sVar3) goto LAB_0012c2a0;
  goto LAB_0012c22a;
}

