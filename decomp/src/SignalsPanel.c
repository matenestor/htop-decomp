#include "htop.h"

/* SignalsPanel_new @ 0x133e80 */

/* WARNING: Removing unreachable block (ram,0x00133fe5) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff80 : 0x00134002 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

Panel * SignalsPanel_new(int preSelectedSignal)

{
  undefined1 __frame[0x148] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x108;
  long lVar1;
  Vector *pVVar2;
  code *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int wVar7;
  uint va0;
  FunctionBar *fuBar;
  Panel *this;
  int *pwVar8;
  char *pcVar9;
  size_t sVar10;
  undefined8 *data_;
  ObjectClass *a3;
  int wVar11;
  uint va1;
  cchar_t *pcVar12;
  ulong a4;
  ObjectClass *a5;
  SignalItem *pSVar13;
  int wVar14;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(undefined1 *(*))(__fp - 0x70)) = (undefined1 *)CONCAT44((*(uint *)((char *)&(*(undefined1 *(*))(__fp - 0x70)) + 4)),preSelectedSignal);
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  (*(char *(*) [3])(__fp - 0x58))[2] = (char *)0x0;
  (*(char *(*) [3])(__fp - 0x58))[0] = ((char *)(long)&s_Send_00149190 /* "Send   " */);
  (*(char *(*) [3])(__fp - 0x58))[1] = ((char *)(long)&s_Cancel_00147223 /* "Cancel " */);
  fuBar = FunctionBar_new((*(char *(*) [3])(__fp - 0x58)),FunctionBar_EnterEscKeys,((char *)(long)&FunctionBar_EnterEscEvents /* L"\r\x1b" */));
                    /* Unresolved local var: Panel * this@[???]
                       Unresolved local var: void * data@[???] */
  this = malloc(0x26e0);
  if (this == (Panel *)0x0) {
LAB_0013419f:
                    /* WARNING: Subroutine does not return */
    fail();
  }
  a5 = &ListItem_class;
  a4 = 1;
  (this->super).klass = &Panel_class.super;
  wVar14 = 15;
  wVar11 = 0;
  Panel_init(this,1,1,1,1,&ListItem_class,true,fuBar);
  pSVar13 = Platform_signals;
  do {
    (*(undefined8 (*))(__fp - 0x60)) = pSVar13->name;
                    /* Unresolved local var: ListItem * this@[???]
                       Unresolved local var: void * data@[???] */
    wVar7 = pSVar13->number;
    pwVar8 = malloc(0x18);
    if (pwVar8 == (int *)0x0) goto LAB_0013419f;
    a3 = &ListItem_class;
                    /* Unresolved local var: char * data@[???] */
    *(ObjectClass **)pwVar8 = &ListItem_class;
    (*(int *(*))(__fp - 0x68)) = pwVar8;
    pcVar9 = strdup((*(undefined8 (*))(__fp - 0x60)));
    if (pcVar9 == (char *)0x0) goto LAB_0013419f;
    pVVar2 = this->items;
    *(char **)((*(int *(*))(__fp - 0x68)) + 2) = pcVar9;
    (*(int *(*))(__fp - 0x68))[4] = wVar7;
    *(undefined1 *)((*(int *(*))(__fp - 0x68)) + 5) = 0;
    Vector_set(pVVar2,wVar11,(*(int *(*))(__fp - 0x68)));
    if (wVar7 == (int)(*(undefined1 *(*))(__fp - 0x70))) {
      wVar14 = wVar11;
    }
    wVar11 = wVar11 + 1;
    pSVar13 = pSVar13 + 1;
  } while (wVar11 != 34);
  iVar5 = __libc_current_sigrtmax();
  iVar6 = __libc_current_sigrtmin();
  if (iVar5 - iVar6 < 0x65) {
                    /* Unresolved local var: int sig@[???] */
    va0 = __libc_current_sigrtmin();
                    /* Unresolved local var: int n@[???] */
    (*(undefined8 (*))(__fp - 0x60)) = (char *)CONCAT44((*(uint *)((char *)&(*(undefined8 (*))(__fp - 0x60)) + 4)),0x22 - va0);
    for (; iVar5 = __libc_current_sigrtmax(), (int)va0 <= iVar5; va0 = va0 + 1) {
      iVar5 = __libc_current_sigrtmin();
      a3 = (ObjectClass *)(ulong)va0;
      va1 = va0 - iVar5;
      a4 = (ulong)va1;
      xSnprintf(buf,0x10,((char *)(long)(__sec_rodata + 0x21a5) /* "%2d SIGRTMIN%-+3d" */),va0,va1);
      if (va1 == 0) {
        buf[0xb] = '\0';
      }
                    /* Unresolved local var: void * data@[???] */
      data_ = malloc(0x18);
      if (data_ == (undefined8 *)0x0) goto LAB_0013419f;
                    /* Unresolved local var: ListItem * this@[???] */
                    /* Unresolved local var: char * data@[???] */
      *data_ = &ListItem_class;
      pcVar9 = strdup(buf);
      if (pcVar9 == (char *)0x0) goto LAB_0013419f;
      data_[1] = pcVar9;
      *(uint *)(data_ + 2) = va0;
      pVVar2 = this->items;
      *(undefined1 *)((long)data_ + 0x14) = 0;
      Vector_set(pVVar2,(attr_t)(*(undefined8 (*))(__fp - 0x60)) + va0,data_);
    }
  }
                    /* Unresolved local var: int[49992] data@[???]
                       Unresolved local var: int newLen@[???] */
  (*(undefined1 *(*))(__fp - 0x70)) = (*(undefined1 (*) [8])(__fp - 0x78));
  wVar11 = CRT_colors[7];
  pwVar8 = (*(int (*) [12])(__fp - 0xb8));
  (*(undefined1 *(*))(__fp - 0x70)) = (*(undefined1 (*) [8])(__fp - 0x78));
  sVar10 = mbstowcs((*(int (*) [12])(__fp - 0xb8)),((char *)(long)&s_Send_signal__00149198 /* "Send signal:" */),0xc);
  wVar7 = (int)sVar10;
  if (0 < wVar7) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(&this->header,wVar7);
    (*(undefined8 (*))(__fp - 0x60)) = (char *)(CONCAT44((*(uint *)((char *)&(*(undefined8 (*))(__fp - 0x60)) + 4)),wVar11) & 0xffffffff00ffffff);
    (*(int *(*))(__fp - 0x68)) = (*(int (*) [12])(__fp - 0xb8)) + (ulong)(uint)(wVar7 + -1) + 1;
    pcVar12 = (this->header).chptr;
    do {
      wVar11 = *pwVar8;
      iVar5 = iswprint(wVar11);
      pcVar12->attr = 0;
      pcVar12->chars[0] = 0;
      pcVar12->chars[1] = 0;
      pcVar12->chars[2] = 0;
      if (iVar5 == 0) {
        wVar11 = 65533;
      }
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar12->chars + 2)) = (undefined16)0x0;
      pwVar8 = pwVar8 + 1;
      pcVar12->attr = (attr_t)(*(undefined8 (*))(__fp - 0x60));
      pcVar12->chars[0] = wVar11;
      pcVar12 = pcVar12 + 1;
    } while ((*(int *(*))(__fp - 0x68)) != pwVar8);
  }
  puVar4 = (*(undefined1 *(*))(__fp - 0x70));
                    /* Unresolved local var: int size@[???] */
  this->needsRedraw = true;
  wVar7 = this->items->items;
  wVar11 = wVar7 + -1;
  if (wVar7 <= wVar14) {
    wVar14 = wVar11;
  }
  wVar7 = 0;
  if (-1 < wVar14) {
    wVar7 = wVar14;
  }
  this->selected = wVar7;
  pcVar3 = (this->super).klass[1].extends;
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)((long)this,0xffffffff,(ulong)(uint)wVar11,(long)a3,a4,(long)a5);
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this;
}

