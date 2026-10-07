#include "htop.h"

/* ListItem_delete @ 0x11fe00 */

void ListItem_delete(ListItem_ *cast)

{
  free(cast->value);
  free(cast);
  return;
}


/* ListItem_compare @ 0x11ff00 */

int ListItem_compare(void *cast1,void *cast2)

{
  int wVar1;

  wVar1 = strcmp(*(char **)((long)cast1 + 8),*(char **)((long)cast2 + 8));
  return wVar1;
}


/* ListItem_display @ 0x121640 */

void ListItem_display(ListItem_ *cast,RichString *out)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  int wVar1;
  long lVar2;
  RichString *this;
  int len;
  int iVar3;
  ulong uVar4;
  undefined1 **ppuVar5;
  undefined1 **ppuVar6;
  char *pcVar8;
  cchar_t *pcVar9;
  int *pwVar10;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 **ppuVar7;

  ppuVar6 = &(*(undefined1 *(*))(__fp - 0x68));
  ppuVar5 = &(*(undefined1 *(*))(__fp - 0x68));
  ppuVar7 = &(*(undefined1 *(*))(__fp - 0x68));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(RichString *(*))(__fp - 0x60)) = out;
  if (cast->moving != false) {
                    /* Unresolved local var: int[0] data@[???]
                       Unresolved local var: int newLen@[???] */
    pcVar8 = ((char *)(long)&DAT_0014837b /* "+ " */);
    if (CRT_utf8) {
      pcVar8 = &DAT_00148769;
    }
    uVar4 = (-(ulong)!CRT_utf8 & 0xfffffffffffffff8) + 0x23;
    wVar1 = CRT_colors[1];
    ppuVar5 = &(*(undefined1 *(*))(__fp - 0x68));
    while (ppuVar7 != (undefined1 **)((long)&(*(undefined1 *(*))(__fp - 0x68)) - (uVar4 & 0xfffffffffffff000))) {
      ppuVar6 = (undefined1 **)((long)ppuVar5 + -0x1000);
      *(undefined8 *)((long)ppuVar5 + -8) = *(undefined8 *)((long)ppuVar5 + -8);
      ppuVar7 = (undefined1 **)((long)ppuVar5 + -0x1000);
      ppuVar5 = (undefined1 **)((long)ppuVar5 + -0x1000);
    }
    uVar4 = (ulong)((uint)uVar4 & 0xff0);
    lVar2 = -uVar4;
    pwVar10 = (int *)((long)ppuVar6 + lVar2);
    if (uVar4 != 0) {
      *(undefined8 *)((long)ppuVar6 + -8) = *(undefined8 *)((long)ppuVar6 + -8);
    }
    (*(undefined1 *(*))(__fp - 0x68)) = (undefined1 *)&(*(undefined1 *(*))(__fp - 0x68));
    uVar4 = __mbstowcs_chk((int *)((long)ppuVar6 + lVar2),pcVar8,
                           (-(ulong)!CRT_utf8 & 0xfffffffffffffffe) + 4,
                           (-(ulong)!CRT_utf8 & 0xfffffffffffffffe) + 5);
    len = (int)uVar4;
    ppuVar5 = (undefined1 **)(*(undefined1 *(*))(__fp - 0x68));
    if (0 < len) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
      RichString_setLen((*(RichString *(*))(__fp - 0x60)),len);
      (*(int *(*))(__fp - 0x50)) = (int *)((long)ppuVar6 + (ulong)(uint)(len + -1) * 4 + lVar2 + 4);
      pcVar9 = (*(RichString *(*))(__fp - 0x60))->chptr;
      (*(uint (*))(__fp - 0x54)) = wVar1 & 0xffffff;
      do {
        wVar1 = *pwVar10;
        iVar3 = iswprint(wVar1);
        pcVar9->attr = 0;
        pcVar9->chars[0] = 0;
        pcVar9->chars[1] = 0;
        pcVar9->chars[2] = 0;
        if (iVar3 == 0) {
          wVar1 = 65533;
        }
        pwVar10 = pwVar10 + 1;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar9->chars + 2)) = (undefined16)0x0;
        pcVar9->attr = (*(uint (*))(__fp - 0x54));
        pcVar9->chars[0] = wVar1;
        ppuVar5 = (undefined1 **)(*(undefined1 *(*))(__fp - 0x68));
        pcVar9 = pcVar9 + 1;
      } while ((*(int *(*))(__fp - 0x50)) != pwVar10);
    }
  }
  this = (*(RichString *(*))(__fp - 0x60));
  pcVar8 = cast->value;
  wVar1 = CRT_colors[1];
  RichString_appendWide(this,wVar1,pcVar8);
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* ListItem_new @ 0x1232b0 */

ListItem * ListItem_new(char *value,int key)

{
  ListItem *pLVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pLVar1 = malloc(0x18);
  if (pLVar1 != (ListItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pLVar1->super).klass = &ListItem_class;
    pcVar2 = strdup(value);
    if (pcVar2 != (char *)0x0) {
      pLVar1->value = pcVar2;
      pLVar1->key = key;
      pLVar1->moving = false;
      return pLVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ListItem_init @ 0x123310 */

/* DWARF original prototype: void ListItem_init(ListItem * this, char * value, int key) */

void ListItem_init(ListItem *this,char *value,int key)

{
  char *pcVar1;

                    /* Unresolved local var: char * data@[???] */
  pcVar1 = strdup(value);
  if (pcVar1 != (char *)0x0) {
    this->value = pcVar1;
    this->key = key;
    this->moving = false;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* ListItem_append @ 0x123350 */

/* DWARF original prototype: void ListItem_append(ListItem * this, char * text) */

void ListItem_append(ListItem *this,char *text)

{
  char *__s;
  size_t sVar1;
  size_t p2;
  char *pcVar2;
  ulong __size;

  __s = this->value;
  sVar1 = strlen(__s);
  p2 = strlen(text);
                    /* Unresolved local var: void * data@[???] */
  __size = sVar1 + p2 + 1;
  pcVar2 = realloc(__s,__size);
  if (pcVar2 != (char *)0x0) {
    this->value = pcVar2;
    if (__size < sVar1) {
      __size = sVar1;
    }
    __memcpy_chk(pcVar2 + sVar1,text,p2,__size - sVar1);
    this->value[sVar1 + p2] = '\0';
    return;
  }
  free(__s);
                    /* WARNING: Subroutine does not return */
  fail();
}

