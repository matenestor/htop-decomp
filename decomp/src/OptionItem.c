#include "htop.h"

/* OptionItem_delete @ 0x11fed0 */

void OptionItem_delete(OptionItem_ *cast)

{
  free(cast->text);
  free(cast);
  return;
}


/* TextItem_display @ 0x11ff20 */

void TextItem_display(TextItem_ *cast,RichString *out)

{
  undefined1 __frame[0x1000e8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x1000a8;
  long lVar1;
  int wVar2;
  int wVar3;
  char *__s;
  long lVar4;
  undefined1 *puVar5;
  int iVar6;
  size_t sVar7;
  ulong uVar8;
  ulong uVar9;
  cchar_t *pcVar10;
  undefined1 *puVar11;
  long lVar13;
  long in_FS_OFFSET = (long)__fake_fs;
  undefined1 *puVar12;

  puVar11 = (*(undefined1 (*) [12])(__fp - 0x58));
  __s = (cast->super).text;
  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = CRT_colors[0x47];
  sVar7 = strlen(__s);
                    /* Unresolved local var: int[2986] data@[???]
                       Unresolved local var: int newLen@[???] */
  wVar3 = out->chlen;
  uVar9 = (ulong)((int)sVar7 + 1);
  uVar8 = uVar9 * 4 + 0xf;
  puVar12 = (*(undefined1 (*) [12])(__fp - 0x58));
  puVar5 = (*(undefined1 (*) [12])(__fp - 0x58));
  while (puVar12 != (*(undefined1 (*) [12])(__fp - 0x58)) + -(uVar8 & 0xfffffffffffff000)) {
    puVar11 = puVar5 + -0x1000;
    *(undefined8 *)(puVar5 + -8) = *(undefined8 *)(puVar5 + -8);
    puVar12 = puVar5 + -0x1000;
    puVar5 = puVar5 + -0x1000;
  }
  uVar8 = (ulong)((uint)uVar8 & 0xff0);
  lVar4 = -uVar8;
  if (uVar8 != 0) {
    *(undefined8 *)(puVar11 + -8) = *(undefined8 *)(puVar11 + -8);
  }
  uVar8 = __mbstowcs_chk((int *)(puVar11 + lVar4),__s,(long)(int)sVar7,uVar9 & 0x3fffffffffffffff);
  if (0 < (int)uVar8) {
    (*(int (*))(__fp - 0x4c)) = wVar3 + (int)uVar8;
    lVar13 = (long)wVar3;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
    RichString_setLen(out,(*(int (*))(__fp - 0x4c)));
    lVar1 = lVar13 * -4;
    pcVar10 = out->chptr + lVar13;
    do {
      wVar3 = *(int *)(puVar11 + lVar13 * 4 + lVar1 + lVar4);
      iVar6 = iswprint(wVar3);
      pcVar10->attr = 0;
      pcVar10->chars[0] = 0;
      pcVar10->chars[1] = 0;
      pcVar10->chars[2] = 0;
      if (iVar6 == 0) {
        wVar3 = 65533;
      }
      pcVar10->attr = wVar2 & 0xffffff;
      lVar13 = lVar13 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar10->chars + 2)) = (undefined16)0x0;
      pcVar10->chars[0] = wVar3;
      pcVar10 = pcVar10 + 1;
    } while ((int)lVar13 < (*(int (*))(__fp - 0x4c)));
  }
  if ((*(long (*))(__fp - 0x40)) != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* CheckItem_set @ 0x120860 */

/* DWARF original prototype: void CheckItem_set(CheckItem * this, _Bool value) */

void CheckItem_set(CheckItem *this,_Bool value)

{
  if (this->ref != (_Bool *)0x0) {
    *this->ref = value;
    return;
  }
  this->value = value;
  return;
}


/* CheckItem_get @ 0x121f40 */

/* DWARF original prototype: _Bool CheckItem_get(CheckItem * this) */

_Bool CheckItem_get(CheckItem *this)

{
  if (this->ref != (_Bool *)0x0) {
    return *this->ref;
  }
  return this->value;
}


/* CheckItem_toggle @ 0x121f60 */

/* DWARF original prototype: void CheckItem_toggle(CheckItem * this) */

void CheckItem_toggle(CheckItem *this)

{
  _Bool *p_Var1;

  p_Var1 = this->ref;
  if (p_Var1 != (_Bool *)0x0) {
    *p_Var1 = (_Bool)(*p_Var1 ^ 1);
    return;
  }
  this->value = (_Bool)(this->value ^ 1);
  return;
}


/* NumberItem_get @ 0x121f80 */

/* DWARF original prototype: int NumberItem_get(NumberItem * this) */

int NumberItem_get(NumberItem *this)

{
  if (this->ref != (int *)0x0) {
    return *this->ref;
  }
  return this->value;
}


/* NumberItem_decrease @ 0x121fa0 */

/* DWARF original prototype: void NumberItem_decrease(NumberItem * this) */

void NumberItem_decrease(NumberItem *this)

{
  int wVar1;
  int *pwVar2;
  int wVar3;

  pwVar2 = this->ref;
  wVar3 = this->max;
  if (pwVar2 == (int *)0x0) {
    wVar1 = this->value + -1;
    if (wVar3 < wVar1) {
      this->value = wVar3;
      return;
    }
    wVar3 = this->min;
    if (this->min <= wVar1) {
      wVar3 = wVar1;
    }
    this->value = wVar3;
    return;
  }
  wVar1 = *pwVar2 + -1;
  if (wVar3 < wVar1) {
    *pwVar2 = wVar3;
    return;
  }
  wVar3 = this->min;
  if (this->min <= wVar1) {
    wVar3 = wVar1;
  }
  *pwVar2 = wVar3;
  return;
}


/* NumberItem_increase @ 0x121ff0 */

/* DWARF original prototype: void NumberItem_increase(NumberItem * this) */

void NumberItem_increase(NumberItem *this)

{
  int wVar1;
  int *pwVar2;
  int wVar3;

  pwVar2 = this->ref;
  wVar3 = this->max;
  if (pwVar2 == (int *)0x0) {
    wVar1 = this->value;
    if (wVar3 <= wVar1) {
      this->value = wVar3;
      return;
    }
    wVar3 = this->min;
    if (this->min <= wVar1) {
      wVar3 = wVar1 + 1;
    }
    this->value = wVar3;
    return;
  }
  wVar1 = *pwVar2;
  if (wVar3 <= wVar1) {
    *pwVar2 = wVar3;
    return;
  }
  wVar3 = this->min;
  if (this->min <= wVar1) {
    wVar3 = wVar1 + 1;
  }
  *pwVar2 = wVar3;
  return;
}


/* NumberItem_toggle @ 0x122040 */

/* DWARF original prototype: void NumberItem_toggle(NumberItem * this) */

void NumberItem_toggle(NumberItem *this)

{
  int *pwVar1;

  pwVar1 = this->ref;
  if (pwVar1 == (int *)0x0) {
    if (this->max <= this->value) {
      this->value = this->min;
      return;
    }
    this->value = this->value + 1;
    return;
  }
  if (this->max <= *pwVar1) {
    *pwVar1 = this->min;
    return;
  }
  *pwVar1 = *pwVar1 + 1;
  return;
}


/* TextItem_new @ 0x123cb0 */

TextItem * TextItem_new(char *text)

{
  TextItem *pTVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pTVar1 = malloc(0x18);
  if (pTVar1 != (TextItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pTVar1->super).super.klass = &TextItem_class.super;
    pcVar2 = strdup(text);
    if (pcVar2 != (char *)0x0) {
      (pTVar1->super).text = pcVar2;
      return pTVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* CheckItem_newByRef @ 0x123d00 */

CheckItem * CheckItem_newByRef(char *text,_Bool *ref)

{
  CheckItem *pCVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pCVar1 = malloc(0x20);
  if (pCVar1 != (CheckItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pCVar1->super).super.klass = &CheckItem_class.super;
    pcVar2 = strdup(text);
    if (pcVar2 != (char *)0x0) {
      (pCVar1->super).text = pcVar2;
      pCVar1->value = false;
      pCVar1->ref = ref;
      return pCVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* CheckItem_newByVal @ 0x123d60 */

CheckItem * CheckItem_newByVal(char *text,_Bool value)

{
  CheckItem *pCVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pCVar1 = malloc(0x20);
  if (pCVar1 != (CheckItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pCVar1->super).super.klass = &CheckItem_class.super;
    pcVar2 = strdup(text);
    if (pcVar2 != (char *)0x0) {
      (pCVar1->super).text = pcVar2;
      pCVar1->value = value;
      pCVar1->ref = (_Bool *)0x0;
      return pCVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* NumberItem_newByRef @ 0x123dd0 */

NumberItem * NumberItem_newByRef(char *text,int *ref,int scale,int min,int max)

{
  NumberItem *pNVar1;
  char *pcVar2;

                    /* Unresolved local var: void * data@[???] */
  pNVar1 = malloc(0x30);
  if (pNVar1 != (NumberItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pNVar1->super).super.klass = &NumberItem_class.super;
    pcVar2 = strdup(text);
    if (pcVar2 != (char *)0x0) {
      (pNVar1->super).text = pcVar2;
      pNVar1->value = 0;
      pNVar1->ref = ref;
      pNVar1->scale = scale;
      pNVar1->min = min;
      pNVar1->max = max;
      return pNVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* NumberItem_newByVal @ 0x123e60 */

NumberItem * NumberItem_newByVal(char *text,int value,int scale,int min,int max)

{
  int wVar1;
  NumberItem *pNVar2;
  char *pcVar3;

                    /* Unresolved local var: void * data@[???] */
  pNVar2 = malloc(0x30);
  if (pNVar2 != (NumberItem *)0x0) {
                    /* Unresolved local var: char * data@[???] */
    (pNVar2->super).super.klass = &NumberItem_class.super;
    pcVar3 = strdup(text);
    if (pcVar3 != (char *)0x0) {
      (pNVar2->super).text = pcVar3;
      wVar1 = min;
      if (min <= value) {
        wVar1 = value;
      }
      pNVar2->ref = (int *)0x0;
      if (max < value) {
        wVar1 = max;
      }
      pNVar2->value = wVar1;
      pNVar2->scale = scale;
      pNVar2->min = min;
      pNVar2->max = max;
      return pNVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* CheckItem_display @ 0x129890 */

void CheckItem_display(CheckItem_ *cast,RichString *out)

{
  char cVar1;

  RichString_writeAscii(out,CRT_colors[0x41],((char *)(long)&DAT_0014703c /* "[" */));
  if (cast->ref == (_Bool *)0x0) {
    cVar1 = cast->value;
  }
  else {
    cVar1 = *cast->ref;
  }
  if (cVar1 == '\0') {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)(long)&DAT_001470dd /* " " */));
  }
  else {
    RichString_appendAscii(out,CRT_colors[0x42],((char *)(long)&DAT_00149f75 /* "x" */));
  }
  RichString_appendAscii(out,CRT_colors[0x41],((char *)(long)&s___001488e0 /* "]    " */));
  RichString_appendWide(out,CRT_colors[0x43],(cast->super).text);
  return;
}


/* NumberItem_display @ 0x129950 */

void NumberItem_display(NumberItem_ *cast,RichString *out)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long lVar1;
  int wVar2;
  int wVar3;
  long in_FS_OFFSET = (long)__fake_fs;
  double dVar4;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  RichString_writeAscii(out,CRT_colors[0x41],((char *)(long)&DAT_0014703c /* "[" */));
  wVar2 = cast->scale;
  if (wVar2 < 0) {
    dVar4 = pow(10.0,(double)wVar2);
    if (cast->ref == (int *)0x0) {
      wVar3 = cast->value;
    }
    else {
      wVar3 = *cast->ref;
    }
    wVar2 = xSnprintf((*(char (*) [12])(__fp - 0x4c)),0xc,((char *)(long)&DAT_001488e6 /* "%.*f" */),-wVar2,(double)wVar3 * dVar4);
  }
  else {
    if (wVar2 == 0) {
      if (cast->ref == (int *)0x0) {
        wVar2 = cast->value;
      }
      else {
        wVar2 = *cast->ref;
      }
    }
    else {
      dVar4 = pow(10.0,(double)wVar2);
      if (cast->ref == (int *)0x0) {
        wVar2 = cast->value;
      }
      else {
        wVar2 = *cast->ref;
      }
      wVar2 = (int)((double)wVar2 * dVar4);
    }
    wVar2 = xSnprintf((*(char (*) [12])(__fp - 0x4c)),0xc,((char *)(long)(__sec_rodata + 0x2710) /* "%d" */),wVar2);
  }
  RichString_appendnAscii(out,CRT_colors[0x42],(*(char (*) [12])(__fp - 0x4c)),wVar2);
  RichString_appendAscii(out,CRT_colors[0x41],((char *)(long)&DAT_00149a61 /* "]" */));
                    /* Unresolved local var: int i@[???] */
  if (wVar2 < 5) {
    do {
      wVar2 = wVar2 + 1;
      RichString_appendAscii(out,CRT_colors[0x41],((char *)(long)&DAT_001470dd /* " " */));
    } while (wVar2 != 5);
  }
  RichString_appendWide(out,CRT_colors[0x43],(cast->super).text);
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

