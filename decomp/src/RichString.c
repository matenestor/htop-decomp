#include "htop.h"

/* RichString_setAttrn @ 0x12db80 */

/* DWARF original prototype: void RichString_setAttrn(RichString * this, int attrs, int
   start, int charcount) */

void RichString_setAttrn(RichString *this,int attrs,int start,int charcount)

{
  cchar_t *pcVar1;
  int wVar2;
  cchar_t *pcVar3;
  cchar_t *pcVar4;
  int wVar5;
  int wVar6;

  wVar5 = charcount + start;
  wVar2 = 0;
  if (-1 < wVar5) {
    wVar2 = wVar5;
  }
  wVar6 = this->chlen;
  if (wVar5 <= this->chlen) {
    wVar6 = wVar2;
  }
                    /* Unresolved local var: int i@[???] */
  if (start < wVar6) {
    pcVar4 = this->chptr + start;
    pcVar1 = this->chptr + (ulong)(uint)(wVar6 - start) + (long)start;
    pcVar3 = pcVar4;
    if (((int)pcVar1 - (int)pcVar4 & 4U) != 0) {
      pcVar4->attr = attrs;
      pcVar3 = pcVar4 + 1;
      if (pcVar4 + 1 == pcVar1) {
        return;
      }
    }
    do {
      pcVar3->attr = attrs;
      pcVar4 = pcVar3 + 2;
      pcVar3[1].attr = attrs;
      pcVar3 = pcVar4;
    } while (pcVar4 != pcVar1);
  }
  return;
}


/* RichString_findChar @ 0x12dbf0 */

/* DWARF original prototype: int RichString_findChar(RichString * this, char c, int start)
    */

int RichString_findChar(RichString *this,char c,int start)

{
  int wVar1;
  cchar_t *pcVar2;

  wVar1 = btowc((int)c);
  pcVar2 = this->chptr + start;
                    /* Unresolved local var: int i@[???] */
  if (start < this->chlen) {
    do {
      if (pcVar2->chars[0] == wVar1) {
        return start;
      }
      start = start + 1;
      pcVar2 = pcVar2 + 1;
    } while (start != this->chlen);
  }
  return -1;
}


/* RichString_delete @ 0x12dc60 */

/* DWARF original prototype: void RichString_delete(RichString * this) */

void RichString_delete(RichString *this)

{
  if (this->chlen < 351) {
    return;
  }
  free(this->chptr);
  this->chptr = this->chstr;
  return;
}


/* RichString_setAttr @ 0x12dca0 */

/* DWARF original prototype: void RichString_setAttr(RichString * this, int attrs) */

void RichString_setAttr(RichString *this,int attrs)

{
  int wVar1;
  int wVar2;
  cchar_t *pcVar3;

  wVar1 = this->chlen;
                    /* Unresolved local var: int end@[???] */
  wVar2 = 0;
  if (-1 < wVar1) {
    wVar2 = wVar1;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < wVar1) {
    pcVar3 = this->chptr;
    wVar1 = 0;
    do {
      wVar1 = wVar1 + 1;
      pcVar3->attr = attrs;
      pcVar3 = pcVar3 + 1;
    } while (wVar1 < wVar2);
  }
  return;
}


/* RichString_setLen @ 0x130130 */

/* DWARF original prototype: void RichString_setLen(RichString * this, int len) */

void RichString_setLen(RichString *this,int len)

{
  int wVar1;
  long lVar2;
  cchar_t *pcVar3;
  cchar_t *pcVar4;
  long lVar5;

  wVar1 = this->chlen;
  if (len < 350) {
    lVar5 = (long)len;
    pcVar3 = this->chptr;
    lVar2 = lVar5 * 0x1c;
    if (wVar1 < 350) {
      pcVar4 = pcVar3 + lVar5;
      pcVar4->attr = 0;
      pcVar4->chars[0] = 0;
      pcVar4->chars[1] = 0;
      pcVar4->chars[2] = 0;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar3[lVar5].chars + 2)) = (undefined16)0x0;
      goto LAB_00130187;
    }
    if (wVar1 != 350) goto LAB_00130248;
  }
  else {
    if (350 < wVar1) {
      pcVar3 = this->chptr;
      if (len != 350) {
                    /* Unresolved local var: void * data@[???] */
        lVar5 = (long)(len + 1);
        pcVar4 = realloc(pcVar3,lVar5 * 0x1c);
        if (pcVar4 == (cchar_t *)0x0) {
          free(pcVar3);
          goto LAB_001302f7;
        }
        this->chptr = pcVar4;
        pcVar3 = pcVar4 + lVar5 + -1;
        pcVar3->attr = 0;
        pcVar3->chars[0] = 0;
        pcVar3->chars[1] = 0;
        pcVar3->chars[2] = 0;
        *(undefined16 *)(*(undefined1 (*) [16])(pcVar4[lVar5 + -1].chars + 2)) = (undefined16)0x0;
        goto LAB_00130187;
      }
      lVar5 = 0x15e;
LAB_00130248:
      pcVar4 = this->chptr;
      pcVar3 = this->chstr;
      memcpy(pcVar3,pcVar4,lVar5 * 0x1c);
      free(pcVar4);
      this->chptr = pcVar3;
      pcVar3 = pcVar3 + lVar5;
      pcVar3->attr = 0;
      pcVar3->chars[0] = 0;
      pcVar3->chars[1] = 0;
      pcVar3->chars[2] = 0;
      *(undefined16 *)(*(undefined1 (*) [16])(this->chstr[lVar5].chars + 2)) = (undefined16)0x0;
      goto LAB_00130187;
    }
    if (len != 350) {
      lVar5 = (long)(len + 1);
                    /* Unresolved local var: void * data@[???] */
      pcVar3 = malloc(lVar5 * 0x1c);
      if (pcVar3 == (cchar_t *)0x0) {
LAB_001302f7:
                    /* WARNING: Subroutine does not return */
        fail();
      }
      this->chptr = pcVar3;
      __memcpy_chk(pcVar3,this->chstr,(long)wVar1 * 0x1c,lVar5 * 0x1c);
      pcVar4 = pcVar3 + lVar5 + -1;
      pcVar4->attr = 0;
      pcVar4->chars[0] = 0;
      pcVar4->chars[1] = 0;
      pcVar4->chars[2] = 0;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar3[lVar5 + -1].chars + 2)) = (undefined16)0x0;
      goto LAB_00130187;
    }
    pcVar3 = this->chptr;
    lVar2 = 0x2648;
  }
  *(undefined16 *)(*(undefined1 (*) [16])((long)pcVar3->chars + lVar2 + -4)) = (undefined16)0x0;
  *(undefined16 *)(*(undefined1 (*) [16])((long)pcVar3->chars + lVar2 + 8)) = (undefined16)0x0;
LAB_00130187:
  this->chlen = len;
  return;
}


/* RichString_appendChr @ 0x130300 */

/* DWARF original prototype: void RichString_appendChr(RichString * this, int attrs, char c,
   int count) */

void RichString_appendChr(RichString *this,int attrs,char c,int count)

{
  int wVar1;
  cchar_t *pcVar2;
  cchar_t *pcVar3;
  cchar_t *pcVar4;

  wVar1 = this->chlen;
  RichString_setLen(this,wVar1 + count);
                    /* Unresolved local var: int i@[???] */
  if (wVar1 < wVar1 + count) {
    pcVar2 = this->chptr;
    pcVar3 = pcVar2 + wVar1;
    do {
      pcVar3->attr = 0;
      pcVar3->chars[0] = 0;
      pcVar3->chars[1] = 0;
      pcVar3->chars[2] = 0;
      pcVar4 = pcVar3 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar3->chars + 2)) = (undefined16)0x0;
      pcVar3->attr = attrs;
      pcVar3->chars[0] = (int)c;
      pcVar3 = pcVar4;
    } while (pcVar4 != pcVar2 + (ulong)(uint)count + (long)wVar1);
  }
  return;
}


/* RichString_rewind @ 0x130390 */

/* DWARF original prototype: void RichString_rewind(RichString * this, int count) */

void RichString_rewind(RichString *this,int count)

{
  RichString_setLen(this,this->chlen - count);
  return;
}


/* RichString_appendnWideColumns @ 0x1303a0 */

/* DWARF original prototype: int RichString_appendnWideColumns(RichString * this, int attrs,
   char * data_c, int len, int * columns) */

int RichString_appendnWideColumns
                  (RichString *this,int attrs,char *data_c,int len,int *columns)

{
  undefined1 __frame[0x1000f8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000b8;
  int __c;
  long lVar1;
  undefined1 *puVar2;
  int iVar3;
  int wVar4;
  int wVar5;
  ulong uVar6;
  undefined1 (*pauVar7) [16];
  undefined1 *puVar8;
  int *pwVar10;
  long lVar11;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar9;

  puVar8 = (*(undefined1 (*) [8])(__fp - 0x68));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar6 = (long)(len + 1) * 4 + 0xf;
  puVar9 = (*(undefined1 (*) [8])(__fp - 0x68));
  puVar2 = (*(undefined1 (*) [8])(__fp - 0x68));
  while (puVar9 != (*(undefined1 (*) [8])(__fp - 0x68)) + -(uVar6 & 0xfffffffffffff000)) {
    puVar8 = puVar2 + -0x1000;
    *(undefined8 *)(puVar2 + -8) = *(undefined8 *)(puVar2 + -8);
    puVar9 = puVar2 + -0x1000;
    puVar2 = puVar2 + -0x1000;
  }
  uVar6 = (ulong)((uint)uVar6 & 0xff0);
  lVar1 = -uVar6;
  pwVar10 = (int *)(puVar8 + lVar1);
  if (uVar6 != 0) {
    *(undefined8 *)(puVar8 + -8) = *(undefined8 *)(puVar8 + -8);
  }
  (*(int (*))(__fp - 0x58)) = attrs;
  (*(RichString *(*))(__fp - 0x50)) = this;
  uVar6 = __mbstowcs_chk((int *)(puVar8 + lVar1),data_c,(long)len,
                         (long)(len + 1) & 0x3fffffffffffffff);
  wVar5 = 0;
  if (0 < (int)uVar6) {
    wVar5 = (*(RichString *(*))(__fp - 0x50))->chlen;
    (*(int (*))(__fp - 0x5c)) = wVar5 + (int)uVar6;
    (*(int (*))(__fp - 0x60)) = wVar5;
    RichString_setLen((*(RichString *(*))(__fp - 0x50)),(*(int (*))(__fp - 0x5c)));
                    /* Unresolved local var: int j@[???] */
    (*(int (*))(__fp - 0x54)) = 0;
    lVar11 = (long)wVar5 * 0x1c;
    do {
      __c = *pwVar10;
      iVar3 = iswprint(__c);
      if (iVar3 == 0) {
        __c = 65533;
      }
      wVar4 = wcwidth(__c);
      if (*columns < wVar4) break;
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int cwidth@[???] */
      (*(int (*))(__fp - 0x54)) = (*(int (*))(__fp - 0x54)) + wVar4;
      *columns = *columns - wVar4;
      wVar5 = wVar5 + 1;
      pwVar10 = pwVar10 + 1;
      pauVar7 = (undefined1 (*) [16])((long)(*(RichString *(*))(__fp - 0x50))->chptr->chars + lVar11 + -4);
      lVar11 = lVar11 + 0x1c;
      *(undefined16 *)(*pauVar7) = (undefined16)0x0;
      *(int *)*pauVar7 = (*(int (*))(__fp - 0x58)) & 0xffffff;
      *(int *)(*pauVar7 + 4) = __c;
      *(undefined16 *)(*(undefined1 (*) [16])(*pauVar7 + 0xc)) = (undefined16)0x0;
    } while (wVar5 != (*(int (*))(__fp - 0x5c)));
    RichString_setLen((*(RichString *(*))(__fp - 0x50)),wVar5);
    *columns = (*(int (*))(__fp - 0x54));
    wVar5 = wVar5 - (*(int (*))(__fp - 0x60));
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return wVar5;
}


/* RichString_appendWide @ 0x130610 */

/* DWARF original prototype: int RichString_appendWide(RichString * this, int attrs, char *
   data) */

int RichString_appendWide(RichString *this,int attrs,char *data)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  long lVar1;
  int wVar2;
  long lVar3;
  undefined1 *puVar4;
  int iVar5;
  size_t sVar6;
  ulong uVar7;
  ulong uVar8;
  undefined1 *puVar9;
  cchar_t *pcVar11;
  long lVar12;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar10;

  puVar9 = (*(undefined1 (*) [8])(__fp - 0x58));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  sVar6 = strlen(data);
                    /* Unresolved local var: int[23892] data@[???]
                       Unresolved local var: int newLen@[???] */
  wVar2 = this->chlen;
  lVar12 = (long)wVar2;
  uVar8 = (ulong)((int)sVar6 + 1);
  uVar7 = uVar8 * 4 + 0xf;
  puVar10 = (*(undefined1 (*) [8])(__fp - 0x58));
  puVar4 = (*(undefined1 (*) [8])(__fp - 0x58));
  while (puVar10 != (*(undefined1 (*) [8])(__fp - 0x58)) + -(uVar7 & 0xfffffffffffff000)) {
    puVar9 = puVar4 + -0x1000;
    *(undefined8 *)(puVar4 + -8) = *(undefined8 *)(puVar4 + -8);
    puVar10 = puVar4 + -0x1000;
    puVar4 = puVar4 + -0x1000;
  }
  uVar7 = (ulong)((uint)uVar7 & 0xff0);
  lVar3 = -uVar7;
  if (uVar7 != 0) {
    *(undefined8 *)(puVar9 + -8) = *(undefined8 *)(puVar9 + -8);
  }
  uVar7 = __mbstowcs_chk((int *)(puVar9 + lVar3),data,(long)(int)sVar6,uVar8 & 0x3fffffffffffffff);
  (*(int (*))(__fp - 0x50)) = (int)uVar7;
  if ((*(int (*))(__fp - 0x50)) < 1) {
    (*(int (*))(__fp - 0x50)) = 0;
  }
  else {
    (*(int (*))(__fp - 0x4c)) = wVar2 + (*(int (*))(__fp - 0x50));
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(this,(*(int (*))(__fp - 0x4c)));
    lVar1 = lVar12 * -4;
    pcVar11 = this->chptr + lVar12;
    do {
      wVar2 = *(int *)(puVar9 + lVar12 * 4 + lVar1 + lVar3);
      iVar5 = iswprint(wVar2);
      pcVar11->attr = 0;
      pcVar11->chars[0] = 0;
      pcVar11->chars[1] = 0;
      pcVar11->chars[2] = 0;
      if (iVar5 == 0) {
        wVar2 = 65533;
      }
      pcVar11->attr = attrs & 0xffffff;
      lVar12 = lVar12 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar11->chars + 2)) = (undefined16)0x0;
      pcVar11->chars[0] = wVar2;
      pcVar11 = pcVar11 + 1;
    } while ((int)lVar12 < (*(int (*))(__fp - 0x4c)));
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (*(int (*))(__fp - 0x50));
}


/* RichString_appendnWide @ 0x130770 */

/* DWARF original prototype: int RichString_appendnWide(RichString * this, int attrs, char *
   data, int len) */

int RichString_appendnWide(RichString *this,int attrs,char *data,int len)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  long lVar1;
  int wVar2;
  long lVar3;
  undefined1 *puVar4;
  int iVar5;
  ulong uVar6;
  undefined1 *puVar7;
  cchar_t *pcVar9;
  long lVar10;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar8;

                    /* Unresolved local var: int[24357] data@[???]
                       Unresolved local var: int newLen@[???] */
  puVar7 = (*(undefined1 (*) [8])(__fp - 0x58));
  wVar2 = this->chlen;
  lVar10 = (long)wVar2;
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  uVar6 = (long)(len + 1) * 4 + 0xf;
  puVar8 = (*(undefined1 (*) [8])(__fp - 0x58));
  puVar4 = (*(undefined1 (*) [8])(__fp - 0x58));
  while (puVar8 != (*(undefined1 (*) [8])(__fp - 0x58)) + -(uVar6 & 0xfffffffffffff000)) {
    puVar7 = puVar4 + -0x1000;
    *(undefined8 *)(puVar4 + -8) = *(undefined8 *)(puVar4 + -8);
    puVar8 = puVar4 + -0x1000;
    puVar4 = puVar4 + -0x1000;
  }
  uVar6 = (ulong)((uint)uVar6 & 0xff0);
  lVar3 = -uVar6;
  if (uVar6 != 0) {
    *(undefined8 *)(puVar7 + -8) = *(undefined8 *)(puVar7 + -8);
  }
  uVar6 = __mbstowcs_chk((int *)(puVar7 + lVar3),data,(long)len,
                         (long)(len + 1) & 0x3fffffffffffffff);
  (*(int (*))(__fp - 0x50)) = (int)uVar6;
  if ((*(int (*))(__fp - 0x50)) < 1) {
    (*(int (*))(__fp - 0x50)) = 0;
  }
  else {
    (*(int (*))(__fp - 0x4c)) = wVar2 + (*(int (*))(__fp - 0x50));
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(this,(*(int (*))(__fp - 0x4c)));
    lVar1 = lVar10 * -4;
    pcVar9 = this->chptr + lVar10;
    do {
      wVar2 = *(int *)(puVar7 + lVar10 * 4 + lVar1 + lVar3);
      iVar5 = iswprint(wVar2);
      pcVar9->attr = 0;
      pcVar9->chars[0] = 0;
      pcVar9->chars[1] = 0;
      pcVar9->chars[2] = 0;
      if (iVar5 == 0) {
        wVar2 = 65533;
      }
      pcVar9->attr = attrs & 0xffffff;
      lVar10 = lVar10 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar9->chars + 2)) = (undefined16)0x0;
      pcVar9->chars[0] = wVar2;
      pcVar9 = pcVar9 + 1;
    } while ((int)lVar10 < (*(int (*))(__fp - 0x4c)));
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (*(int (*))(__fp - 0x50));
}


/* RichString_writeWide @ 0x1308c0 */

/* DWARF original prototype: int RichString_writeWide(RichString * this, int attrs, char *
   data) */

int RichString_writeWide(RichString *this,int attrs,char *data)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  int __wc;
  long lVar1;
  undefined1 *puVar2;
  int len;
  int iVar3;
  size_t sVar4;
  ulong uVar5;
  ulong uVar6;
  cchar_t *pcVar7;
  undefined1 *puVar8;
  int *pwVar10;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar9;

  puVar8 = (*(undefined1 (*) [12])(__fp - 0x58));
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  sVar4 = strlen(data);
                    /* Unresolved local var: int[24761] data@[???]
                       Unresolved local var: int newLen@[???] */
  uVar6 = (ulong)((int)sVar4 + 1);
  uVar5 = uVar6 * 4 + 0xf;
  puVar9 = (*(undefined1 (*) [12])(__fp - 0x58));
  puVar2 = (*(undefined1 (*) [12])(__fp - 0x58));
  while (puVar9 != (*(undefined1 (*) [12])(__fp - 0x58)) + -(uVar5 & 0xfffffffffffff000)) {
    puVar8 = puVar2 + -0x1000;
    *(undefined8 *)(puVar2 + -8) = *(undefined8 *)(puVar2 + -8);
    puVar9 = puVar2 + -0x1000;
    puVar2 = puVar2 + -0x1000;
  }
  uVar5 = (ulong)((uint)uVar5 & 0xff0);
  lVar1 = -uVar5;
  pwVar10 = (int *)(puVar8 + lVar1);
  if (uVar5 != 0) {
    *(undefined8 *)(puVar8 + -8) = *(undefined8 *)(puVar8 + -8);
  }
  uVar5 = __mbstowcs_chk((int *)(puVar8 + lVar1),data,(long)(int)sVar4,uVar6 & 0x3fffffffffffffff);
  len = (int)uVar5;
  if (len < 1) {
    (*(int (*))(__fp - 0x4c)) = 0;
  }
  else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    (*(int (*))(__fp - 0x4c)) = len;
    RichString_setLen(this,len);
    pcVar7 = this->chptr;
    do {
      __wc = *pwVar10;
      iVar3 = iswprint(__wc);
      pcVar7->attr = 0;
      pcVar7->chars[0] = 0;
      pcVar7->chars[1] = 0;
      pcVar7->chars[2] = 0;
      if (iVar3 == 0) {
        __wc = 65533;
      }
      pwVar10 = pwVar10 + 1;
      pcVar7->attr = attrs & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar7->chars + 2)) = (undefined16)0x0;
      pcVar7->chars[0] = __wc;
      pcVar7 = pcVar7 + 1;
    } while ((int *)(puVar8 + (ulong)(uint)(len + -1) * 4 + lVar1 + 4) != pwVar10);
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (*(int (*))(__fp - 0x4c));
}


/* RichString_appendAscii @ 0x130a00 */

/* DWARF original prototype: int RichString_appendAscii(RichString * this, int attrs, char *
   data) */

int RichString_appendAscii(RichString *this,int attrs,char *data)

{
  char cVar1;
  byte bVar2;
  ushort *puVar3;
  int len;
  int wVar4;
  size_t sVar5;
  ushort **ppuVar6;
  cchar_t *pcVar7;
  char *pcVar8;

  sVar5 = strlen(data);
  wVar4 = this->chlen;
                    /* Unresolved local var: int newLen@[???] */
  len = (int)sVar5 + wVar4;
  RichString_setLen(this,len);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (wVar4 < len) {
    ppuVar6 = __ctype_b_loc();
    puVar3 = *ppuVar6;
    pcVar8 = data + (sVar5 & 0xffffffff);
    pcVar7 = this->chptr + wVar4;
    do {
      cVar1 = *data;
      bVar2 = *(byte *)((long)puVar3 + (long)cVar1 * 2 + 1);
      pcVar7->attr = 0;
      pcVar7->chars[0] = 0;
      pcVar7->chars[1] = 0;
      pcVar7->chars[2] = 0;
      wVar4 = (int)cVar1;
      if ((bVar2 & 0x40) == 0) {
        wVar4 = 65533;
      }
      data = data + 1;
      pcVar7->attr = attrs & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar7->chars + 2)) = (undefined16)0x0;
      pcVar7->chars[0] = wVar4;
      pcVar7 = pcVar7 + 1;
    } while (data != pcVar8);
  }
  return (int)sVar5;
}


/* RichString_appendnAscii @ 0x130ac0 */

/* DWARF original prototype: int RichString_appendnAscii(RichString * this, int attrs, char
   * data, int len) */

int RichString_appendnAscii(RichString *this,int attrs,char *data,int len)

{
  char cVar1;
  byte bVar2;
  ushort *puVar3;
  int wVar4;
  ushort **ppuVar5;
  cchar_t *pcVar6;
  char *pcVar7;

  wVar4 = this->chlen;
                    /* Unresolved local var: int newLen@[???] */
  RichString_setLen(this,wVar4 + len);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (wVar4 < wVar4 + len) {
    ppuVar5 = __ctype_b_loc();
    puVar3 = *ppuVar5;
    pcVar7 = data + (uint)len;
    pcVar6 = this->chptr + wVar4;
    do {
      cVar1 = *data;
      bVar2 = *(byte *)((long)puVar3 + (long)cVar1 * 2 + 1);
      pcVar6->attr = 0;
      pcVar6->chars[0] = 0;
      pcVar6->chars[1] = 0;
      pcVar6->chars[2] = 0;
      wVar4 = (int)cVar1;
      if ((bVar2 & 0x40) == 0) {
        wVar4 = 65533;
      }
      data = data + 1;
      pcVar6->attr = attrs & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar6->chars + 2)) = (undefined16)0x0;
      pcVar6->chars[0] = wVar4;
      pcVar6 = pcVar6 + 1;
    } while (data != pcVar7);
  }
  return len;
}


/* RichString_writeAscii @ 0x131b20 */

/* DWARF original prototype: int RichString_writeAscii(RichString * this, int attrs, char *
   data) */

int RichString_writeAscii(RichString *this,int attrs,char *data)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  ushort *puVar4;
  int len;
  int wVar5;
  size_t sVar6;
  ushort **ppuVar7;
  cchar_t *pcVar8;

  sVar6 = strlen(data);
                    /* Unresolved local var: int newLen@[???] */
  len = (int)sVar6;
  RichString_setLen(this,len);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  if (0 < len) {
    ppuVar7 = __ctype_b_loc();
    puVar4 = *ppuVar7;
    pcVar1 = data + (ulong)(uint)(len + -1) + 1;
    pcVar8 = this->chptr;
    do {
      cVar2 = *data;
      bVar3 = *(byte *)((long)puVar4 + (long)cVar2 * 2 + 1);
      pcVar8->attr = 0;
      pcVar8->chars[0] = 0;
      pcVar8->chars[1] = 0;
      pcVar8->chars[2] = 0;
      wVar5 = (int)cVar2;
      if ((bVar3 & 0x40) == 0) {
        wVar5 = 65533;
      }
      data = data + 1;
      pcVar8->attr = attrs & 0xffffff;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar8->chars + 2)) = (undefined16)0x0;
      pcVar8->chars[0] = wVar5;
      pcVar8 = pcVar8 + 1;
    } while (data != pcVar1);
  }
  return len;
}

