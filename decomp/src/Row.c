#include "htop.h"

/* Row_display @ 0x11fc90 */

void Row_display(Row_ *cast,RichString *out)

{
  char cVar1;
  uint uVar2;
  int wVar3;
  Settings__2 *pSVar4;
  code *pcVar5;
  ulong uVar6;
  int wVar7;
  long lVar8;
  int wVar9;
  long in_RCX;
  cchar_t *pcVar10;
  uint *puVar11;
  RichString *a1;
  long in_R8;
  long in_R9;

  pSVar4 = cast->host->settings;
  puVar11 = (uint *)pSVar4->ss->fields;
                    /* Unresolved local var: int i@[???] */
  uVar2 = *puVar11;
  a1 = out;
  while (uVar2 != 0) {
    puVar11 = puVar11 + 1;
    a1 = out;
    (*(code *)((cast->super).klass[1].delete))(&cast->super,(long)out,(ulong)uVar2,in_RCX,in_R8,in_R9);
    uVar2 = *puVar11;
  }
  pcVar5 = (cast->super).klass[1].extends;
  if ((pcVar5 == (code *)0x0) ||
     (lVar8 = (*pcVar5)((long)cast,(long)a1,0,in_RCX,in_R8,in_R9), (char)lVar8 == '\0')) {
    cVar1 = cast->tag;
  }
  else {
                    /* Unresolved local var: int end@[???] */
    wVar3 = CRT_colors[0x1e];
    wVar7 = out->chlen;
    wVar9 = 0;
    if (-1 < wVar7) {
      wVar9 = wVar7;
    }
                    /* Unresolved local var: int i@[???] */
    if (wVar7 < 1) goto LAB_0011fcfb;
    pcVar10 = out->chptr;
    wVar7 = 0;
    do {
      wVar7 = wVar7 + 1;
      pcVar10->attr = wVar3;
      pcVar10 = pcVar10 + 1;
    } while (wVar7 < wVar9);
    cVar1 = cast->tag;
  }
  if (cVar1 != '\0') {
                    /* Unresolved local var: int end@[???] */
    wVar3 = CRT_colors[0x1f];
    wVar7 = out->chlen;
    wVar9 = 0;
    if (-1 < wVar7) {
      wVar9 = wVar7;
    }
                    /* Unresolved local var: int i@[???] */
    if (0 < wVar7) {
      pcVar10 = out->chptr;
      wVar7 = 0;
      do {
        wVar7 = wVar7 + 1;
        pcVar10->attr = wVar3;
        pcVar10 = pcVar10 + 1;
      } while (wVar7 < wVar9);
    }
  }
LAB_0011fcfb:
  if (pSVar4->highlightChanges != false) {
    if (cast->tombStampMs == 0) {
                    /* Unresolved local var: Machine * host@[???]
                       Unresolved local var: Settings * settings@[???] */
      uVar6 = cast->host->monotonicMs;
      if ((cast->seenStampMs <= uVar6) &&
         (uVar6 - cast->seenStampMs <=
          (ulong)((long)cast->host->settings->highlightDelaySecs * 1000))) {
        out->highlightAttr = CRT_colors[0x28];
      }
    }
    else {
      out->highlightAttr = CRT_colors[0x29];
    }
  }
  return;
}


/* Row_setPidColumnWidth @ 0x120fe0 */

void Row_setPidColumnWidth(pid_t maxPid)

{
  double dVar1;

  if (maxPid < 100000) {
    Row_pidDigits = 5;
    return;
  }
  dVar1 = log10((double)maxPid);
  Row_pidDigits = (int)dVar1 + 1;
  return;
}


/* Row_setUidColumnWidth @ 0x121260 */

void Row_setUidColumnWidth(uid_t maxUid)

{
  double dVar1;

  if (maxUid < 100000) {
    Row_uidDigits = 5;
    return;
  }
  dVar1 = log10((double)maxUid);
  Row_uidDigits = (int)dVar1 + 1;
  return;
}


/* Row_resetFieldWidths @ 0x1212b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Row_resetFieldWidths(void)

{
  size_t sVar1;
  char **ppcVar2;
  uint8_t *puVar3;

                    /* Unresolved local var: size_t i@[???] */
  puVar3 = Row_fieldWidths;
  ppcVar2 = &Process_fields_0__title;
  do {
                    /* Unresolved local var: size_t len@[???] */
    if (*(_Bool *)((long)ppcVar2 + 0x16) != false) {
      sVar1 = strlen(*ppcVar2);
      *puVar3 = (uint8_t)sVar1;
    }
    ppcVar2 = ppcVar2 + 4;
    puVar3 = puVar3 + 1;
  } while (ppcVar2 != MetersMovingKeys + 1);
  return;
}


/* Row_init @ 0x122880 */

/* DWARF original prototype: void Row_init(Row * this, Machine * host) */

void Row_init(Row *this,Machine_2 *host)

{
  this->host = (Machine_ *)host;
  this->tag = false;
  this->show = true;
  this->wasShown = false;
  this->showChildren = true;
  this->updated = false;
  return;
}


/* Row_updateFieldWidth @ 0x122ed0 */

void Row_updateFieldWidth(RowField key,size_t width)

{
  if (0xff < width) {
    Row_fieldWidths[key] = 0xff;
    return;
  }
  if (Row_fieldWidths[key] < width) {
    Row_fieldWidths[key] = (uint8_t)width;
  }
  return;
}


/* Row_done @ 0x123060 */

void Row_done(void)

{
  return;
}


/* RowField_alignedTitle @ 0x128b40 */

char * RowField_alignedTitle(Settings_4 *settings,RowField field)

{
  ulong uVar1;
  HashtableItem *pHVar2;
  int wVar3;
  ulong uVar4;
  int va0;
  HashtableItem *pHVar5;
  ulong uVar6;
  int *pwVar7;
  void *pvVar8;
  char *va2;

  if (0x83 < field) {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
    uVar1 = settings->dynamicColumns->size;
    pHVar2 = settings->dynamicColumns->buckets;
    uVar6 = (ulong)(long)field % uVar1;
                    /* Unresolved local var: char * title@[???] */
    pvVar8 = pHVar2[uVar6].value;
    if (pvVar8 == (void *)0x0) {
      return ((char *)(long)&DAT_00147411 /* "- " */);
    }
    uVar4 = 0;
    pHVar5 = pHVar2 + uVar6;
    do {
      while( true ) {
        if (field == pHVar5->key) {
          va0 = *(int *)((long)pvVar8 + 0x38);
          if (va0 == 0) {
            va0 = -5;
          }
          else {
            wVar3 = -va0;
            if (-va0 < 0) {
              wVar3 = va0;
            }
            if ('@' < wVar3) {
              va0 = -5;
            }
          }
          va2 = *(char **)((long)pvVar8 + 0x20);
          goto LAB_00128bfd;
        }
        if (pHVar5->probe < uVar4) goto LAB_00128bd0;
        uVar6 = uVar6 + 1;
        if (uVar1 != uVar6) break;
        uVar6 = 0;
        uVar4 = uVar4 + 1;
        pvVar8 = pHVar2->value;
        pHVar5 = pHVar2;
        if (pvVar8 == (void *)0x0) goto LAB_00128bd0;
      }
      uVar4 = uVar4 + 1;
      pHVar5 = pHVar2 + uVar6;
      pvVar8 = pHVar5->value;
    } while (pvVar8 != (void *)0x0);
LAB_00128bd0:
    return ((char *)(long)&DAT_00147411 /* "- " */);
  }
  va2 = Process_fields[field].title;
  if (va2 == (char *)0x0) goto LAB_00128bd0;
  if (Process_fields[field].pidColumn == false) {
    if (field == 0x2e) {
      pwVar7 = &Row_uidDigits;
      goto LAB_00128c9f;
    }
    if (Process_fields[field].autoWidth == false) {
      return va2;
    }
    if (field != 0x2f) {
      xSnprintf(titleBuffer,0x101,((char *)(long)&s______s_0014884c /* "%-*.*s " */),(uint)Row_fieldWidths[field],
                (uint)Row_fieldWidths[field],va2);
      goto LAB_00128c17;
    }
    va0 = (int)Row_fieldWidths[0x2f];
  }
  else {
    pwVar7 = &Row_pidDigits;
LAB_00128c9f:
    va0 = *pwVar7;
  }
LAB_00128bfd:
  xSnprintf(titleBuffer,0x101,((char *)(long)&DAT_00148847 /* "%*s " */),va0,va2);
LAB_00128c17:
  return titleBuffer;
}


/* RowField_keyAt @ 0x128cc0 */

RowField RowField_keyAt(Settings_4 *settings,int at)

{
  int field;
  char *__s;
  size_t sVar1;
  int wVar2;
  int *piVar3;

  wVar2 = 0;
  piVar3 = settings->ss->fields;
                    /* Unresolved local var: int i@[???] */
  field = *piVar3;
  while( true ) {
    if (field == 0) {
      return 2;
    }
    piVar3 = piVar3 + 1;
    __s = RowField_alignedTitle(settings,field);
    sVar1 = strlen(__s);
    if ((wVar2 <= at) && (at <= wVar2 + (int)sVar1)) break;
    wVar2 = wVar2 + (int)sVar1;
    field = *piVar3;
  }
  return field;
}


/* Row_compare @ 0x12d200 */

int Row_compare(void *v1,void *v2)

{
  return (uint)(*(int *)((long)v2 + 0x10) < *(int *)((long)v1 + 0x10)) -
         (uint)(*(int *)((long)v1 + 0x10) < *(int *)((long)v2 + 0x10));
}


/* Row_toggleTag @ 0x12da70 */

/* DWARF original prototype: void Row_toggleTag(Row * this) */

void Row_toggleTag(Row *this)

{
  this->tag = (_Bool)(this->tag ^ 1);
  return;
}


/* Row_compareByParent_Base @ 0x12da80 */

int Row_compareByParent_Base(void *v1,void *v2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int wVar5;
  uint uVar6;
  int iVar7;
  int iVar8;

  cVar1 = *(char *)((long)v2 + 0x1c);
  if (*(char *)((long)v1 + 0x1c) == '\0') {
    iVar8 = *(int *)((long)v1 + 0x14);
    iVar7 = iVar8;
    if (*(int *)((long)v1 + 0x10) == iVar8) {
      iVar7 = *(int *)((long)v1 + 0x18);
      uVar4 = (uint)(0 < iVar7);
      uVar6 = 0;
      if (cVar1 == '\0') goto LAB_0012dae0;
    }
    else if (cVar1 == '\0') {
LAB_0012dae0:
      uVar6 = *(uint *)((long)v2 + 0x14);
      if (uVar6 == *(uint *)((long)v2 + 0x10)) {
        bVar2 = *(int *)((long)v2 + 0x18) < iVar7;
        uVar4 = (uint)bVar2;
        uVar3 = (uint)bVar2;
        if (*(int *)((long)v1 + 0x10) == iVar8) {
LAB_0012dafd:
          uVar4 = uVar3;
          iVar8 = *(int *)((long)v1 + 0x18);
          iVar7 = iVar8;
          if (uVar6 != *(uint *)((long)v2 + 0x10)) goto LAB_0012daa7;
        }
        uVar6 = *(uint *)((long)v2 + 0x18);
        iVar7 = iVar8;
      }
      else {
        uVar4 = (uint)((int)uVar6 < iVar7);
        iVar7 = iVar8;
        uVar3 = uVar4;
        if (iVar8 == *(int *)((long)v1 + 0x10)) goto LAB_0012dafd;
      }
    }
    else {
      uVar4 = (uint)(0 < iVar8);
      uVar6 = 0;
    }
  }
  else {
    if (cVar1 != '\0') goto LAB_0012dab8;
    uVar6 = *(uint *)((long)v2 + 0x14);
    if (uVar6 == *(uint *)((long)v2 + 0x10)) {
      uVar6 = *(uint *)((long)v2 + 0x18);
    }
    uVar4 = uVar6 >> 0x1f;
    iVar7 = 0;
  }
LAB_0012daa7:
  wVar5 = uVar4 - (iVar7 < (int)uVar6);
  if (wVar5 != 0) {
    return wVar5;
  }
LAB_0012dab8:
                    /* Unresolved local var: Row * r1@[???]
                       Unresolved local var: Row * r2@[???] */
  return (uint)(*(int *)((long)v2 + 0x10) < *(int *)((long)v1 + 0x10)) -
         (uint)(*(int *)((long)v1 + 0x10) < *(int *)((long)v2 + 0x10));
}


/* Row_printPercentage @ 0x12e760 */

int Row_printPercentage(float val,char *buffer,size_t n,uint8_t width,int *attr)

{
  uint va0;
  int wVar1;
  int va1;
  double va2;

  va0 = (uint)width;
                    /* Unresolved local var: int precision@[???] */
  if (val < 0.0) {
    *attr = CRT_colors[0x1e];
    wVar1 = xSnprintf(buffer,n,((char *)(long)&s_____s_00148c24 /* "%*.*s " */),va0,va0,&DAT_001474de);
    return wVar1;
  }
  if (0.05 <= val) {
    if ((99.9 <= val) && (*attr = CRT_colors[0x20], width == '\x04')) {
      va1 = 0;
      va2 = 100.0;
      if (99.9 < val) goto LAB_0012e79e;
    }
    va1 = 1;
    va2 = (double)val;
  }
  else {
    va1 = 1;
    va2 = (double)val;
    *attr = CRT_colors[0x1e];
  }
LAB_0012e79e:
  wVar1 = xSnprintf(buffer,n,((char *)(long)&s_____f_00148c1d /* "%*.*f " */),va0,va1,va2);
  return wVar1;
}


/* Row_printLeftAlignedField @ 0x130530 */

void Row_printLeftAlignedField(RichString *str,int attr,char *content,uint width)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  uint uVar1;
  int wVar2;
  cchar_t *pcVar3;
  size_t sVar4;
  cchar_t *pcVar5;
  cchar_t *pcVar6;
  int len;
  long in_FS_OFFSET = (long)__fake_fs;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  (*(int (*))(__fp - 0x44)) = width;
  sVar4 = strlen(content);
  RichString_appendnWideColumns(str,attr,content,(int)sVar4,&(*(int (*))(__fp - 0x44)));
  uVar1 = (width - (*(int (*))(__fp - 0x44))) + 1;
                    /* Unresolved local var: int from@[???]
                       Unresolved local var: int newLen@[???] */
  wVar2 = str->chlen;
  len = uVar1 + wVar2;
  RichString_setLen(str,len);
                    /* Unresolved local var: int i@[???] */
  if (wVar2 < len) {
    pcVar3 = str->chptr;
    pcVar5 = pcVar3 + wVar2;
    do {
      pcVar5->attr = 0;
      pcVar5->chars[0] = 0;
      pcVar5->chars[1] = 0;
      pcVar5->chars[2] = 0;
      pcVar6 = pcVar5 + 1;
      *(undefined16 *)(*(undefined1 (*) [16])(pcVar5->chars + 2)) = (undefined16)0x0;
      pcVar5->attr = attr;
      pcVar5->chars[0] = ' ';
      pcVar5 = pcVar6;
    } while (pcVar6 != pcVar3 + (ulong)uVar1 + (long)wVar2);
  }
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Row_printKBytes @ 0x130b70 */

void Row_printKBytes(RichString *str,ulonglong number,_Bool coloring)

{
  undefined1 __frame[0xf8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xb8;
  char cVar1;
  long lVar2;
  int wVar3;
  int wVar4;
  int wVar5;
  int iVar6;
  char *pcVar7;
  long lVar8;
  ulong uVar9;
  int va0;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  wVar4 = CRT_colors[0x1d];
  (*(int (*) [4])(__fp - 0x68))[0] = wVar4;
  (*(int (*) [4])(__fp - 0x68))[1] = CRT_colors[0x20];
  (*(int (*) [4])(__fp - 0x68))[2] = CRT_colors[0x21];
  (*(int (*) [4])(__fp - 0x68))[3] = CRT_colors[0xc];
  if (number == 0xffffffffffffffff) {
    if (coloring) {
      wVar4 = CRT_colors[0x1e];
    }
    if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(str,wVar4,((char *)(long)&DAT_00149092 /* "  N/A " */));
      return;
    }
  }
  else {
    wVar5 = CRT_colors[0x20];
    if (!coloring) {
      wVar5 = wVar4;
    }
    if (number < 1000) {
      wVar5 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149063 /* "%5u " */),(int)number);
      RichString_appendnAscii(str,wVar4,(*(char (*) [16])(__fp - 0x58)),wVar5);
    }
    else if (number < 100000) {
      iVar6 = (int)(number / 1000);
      wVar3 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149068 /* "%2u" */),iVar6);
      RichString_appendnAscii(str,wVar5,(*(char (*) [16])(__fp - 0x58)),wVar3);
      wVar5 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&s__03u_0014906c /* "%03u " */),(int)number + iVar6 * -1000);
      RichString_appendnAscii(str,wVar4,(*(char (*) [16])(__fp - 0x58)),wVar5);
    }
    else {
      lVar8 = 1;
      uVar9 = ((number & 0xff) * 0x19 >> 8) + (number >> 8) * 0x19;
      while( true ) {
        wVar3 = wVar5;
        if ((coloring) && (lVar8 + 1U < 4)) {
          wVar3 = (*(int (*) [4])(__fp - 0x68))[lVar8 + 1];
        }
        if (uVar9 < 1000000) break;
        uVar9 = uVar9 >> 10;
        lVar8 = lVar8 + 1;
        wVar4 = wVar5;
        wVar5 = wVar3;
      }
      iVar6 = (int)(uVar9 / 100);
      if (uVar9 < 10000) {
        va0 = (int)(uVar9 % 100);
        if (uVar9 < 1000) {
          wVar3 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149079 /* "%1u" */),9);
          RichString_appendnAscii(str,wVar5,(*(char (*) [16])(__fp - 0x58)),wVar3);
          pcVar7 = ((char *)(long)&s___02u_00149072 /* ".%02u" */);
        }
        else {
          wVar3 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149068 /* "%2u" */),iVar6);
          RichString_appendnAscii(str,wVar5,(*(char (*) [16])(__fp - 0x58)),wVar3);
          pcVar7 = ((char *)(long)&DAT_00149078 /* ".%1u" */);
          va0 = (int)((uVar9 % 100) / 10);
        }
        wVar3 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,pcVar7,va0);
        RichString_appendnAscii(str,wVar4,(*(char (*) [16])(__fp - 0x58)),wVar3);
        wVar4 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149088 /* "%c " */),(int)((char *)(long)&unitPrefixes /* "KMGTPEZYRQ" */)[lVar8]);
      }
      else {
        if (uVar9 < 100000) {
          cVar1 = ((char *)(long)&unitPrefixes /* "KMGTPEZYRQ" */)[lVar8];
          pcVar7 = ((char *)(long)&s__4u_c_0014907d /* "%4u%c " */);
        }
        else {
          uVar9 = uVar9 / 100 & 0xffffffff;
          wVar4 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,((char *)(long)&DAT_00149079 /* "%1u" */),(int)(uVar9 / 1000));
          RichString_appendnAscii(str,wVar3,(*(char (*) [16])(__fp - 0x58)),wVar4);
          pcVar7 = ((char *)(long)&DAT_00149084 /* "%03u%c " */);
          cVar1 = ((char *)(long)&unitPrefixes /* "KMGTPEZYRQ" */)[lVar8];
          iVar6 = iVar6 + (int)(uVar9 / 1000) * -1000;
        }
        wVar4 = xSnprintf((*(char (*) [16])(__fp - 0x58)),0x10,pcVar7,iVar6,(int)cVar1);
      }
      RichString_appendnAscii(str,wVar5,(*(char (*) [16])(__fp - 0x58)),wVar4);
    }
    if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Row_printBytes @ 0x130f70 */

void Row_printBytes(RichString *str,ulonglong number,_Bool coloring)

{
  int attrs;

  if (number != 0xffffffffffffffff) {
    Row_printKBytes(str,number >> 10,coloring);
    return;
  }
                    /* Unresolved local var: char[16] buffer@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int color@[???]
                       Unresolved local var: int nextUnitColor@[???]
                       Unresolved local var: int[4] colors@[???]
                       Unresolved local var: size_t maxUnitIndex@[???]
                       Unresolved local var: _Bool canOverflow@[???]
                       Unresolved local var: size_t i@[???]
                       Unresolved local var: int prevUnitColor@[???]
                       Unresolved local var: ulonglong hundredths@[???] */
  attrs = CRT_colors[0x1d];
  if (coloring) {
    attrs = CRT_colors[0x1e];
  }
  RichString_appendAscii(str,attrs,((char *)(long)&DAT_00149092 /* "  N/A " */));
  return;
}


/* Row_printCount @ 0x130fb0 */

void Row_printCount(RichString *str,ulonglong number,_Bool coloring)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  int attrs;
  long lVar1;
  int attrs_00;
  int attrs_01;
  int attrs_02;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  attrs = CRT_colors[0x1d];
  attrs_00 = attrs;
  attrs_01 = attrs;
  attrs_02 = attrs;
  if (coloring) {
    attrs_00 = CRT_colors[0xc];
    attrs_01 = CRT_colors[0x20];
    attrs_02 = CRT_colors[0x1e];
  }
  if (number == 0xffffffffffffffff) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(str,CRT_colors[0x1e],((char *)(long)&DAT_0014908c /* "        N/A " */));
      return;
    }
  }
  else {
    if (number < 100000000000000000) {
      if (number < 100000000000000) {
        if (number < 10000000000) {
          xSnprintf((*(char (*) [13])(__fp - 0x4d)),0xd,((char *)(long)&s__11llu_00149099 /* "%11llu " */),number);
          RichString_appendnAscii(str,attrs_00,(*(char (*) [13])(__fp - 0x4d)),2);
          RichString_appendnAscii(str,attrs_01,(*(char (*) [13])(__fp - 0x4d)) + 2,3);
          RichString_appendnAscii(str,attrs,(*(char (*) [13])(__fp - 0x4d)) + 5,3);
          RichString_appendnAscii(str,attrs_02,(*(char (*) [13])(__fp - 0x4d)) + 8,4);
        }
        else {
          xSnprintf((*(char (*) [13])(__fp - 0x4d)),0xd,((char *)(long)&s__11llu_00149099 /* "%11llu " */),number / 1000);
          RichString_appendnAscii(str,attrs_00,(*(char (*) [13])(__fp - 0x4d)),5);
          RichString_appendnAscii(str,attrs_01,(*(char (*) [13])(__fp - 0x4d)) + 5,3);
          RichString_appendnAscii(str,attrs,(*(char (*) [13])(__fp - 0x4d)) + 8,4);
        }
      }
      else {
        xSnprintf((*(char (*) [13])(__fp - 0x4d)),0xd,((char *)(long)&s__11llu_00149099 /* "%11llu " */),number / 1000000);
        RichString_appendnAscii(str,attrs_00,(*(char (*) [13])(__fp - 0x4d)),8);
        RichString_appendnAscii(str,attrs_01,(*(char (*) [13])(__fp - 0x4d)) + 8,4);
      }
    }
    else {
      xSnprintf((*(char (*) [13])(__fp - 0x4d)),0xd,((char *)(long)&s__11llu_00149099 /* "%11llu " */),number / 1000000000);
      RichString_appendnAscii(str,attrs_00,(*(char (*) [13])(__fp - 0x4d)),12);
    }
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Row_printTime @ 0x131250 */

void Row_printTime(RichString *str,ulonglong totalHundredths,_Bool coloring)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long lVar1;
  int wVar2;
  int wVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  int va1;
  int va0;
  int attrs;
  int attrs_00;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = CRT_colors[0x1d];
  wVar3 = wVar2;
  attrs_00 = wVar2;
  attrs = wVar2;
  if (coloring) {
    wVar3 = CRT_colors[0xc];
    attrs_00 = CRT_colors[0x21];
    attrs = CRT_colors[0x20];
  }
  uVar7 = totalHundredths / 100;
  iVar4 = (int)(uVar7 / 0x3c);
  uVar6 = (uVar7 / 0x3c) / 0x3c;
  iVar5 = (int)uVar6;
  va0 = iVar4 + ((int)(uVar6 << 4) - iVar5) * -4;
  va1 = (int)(uVar7 % 0x3c);
  if (totalHundredths < 360000) {
                    /* Unresolved local var: uint hundredths@[???] */
    wVar3 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&s__2u__02u__02u_001490a1 /* "%2u:%02u.%02u " */),iVar4,va1,(int)totalHundredths + (int)uVar7 * -100)
    ;
    RichString_appendnAscii(str,wVar2,(*(char (*) [10])(__fp - 0x4a)),wVar3);
  }
  else if (totalHundredths < 0x83d600) {
    wVar3 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&DAT_001490b0 /* "%2uh" */),iVar5);
    RichString_appendnAscii(str,attrs,(*(char (*) [10])(__fp - 0x4a)),wVar3);
    wVar3 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&s__02u__02u_001490b5 /* "%02u:%02u " */),va0,va1);
    RichString_appendnAscii(str,wVar2,(*(char (*) [10])(__fp - 0x4a)),wVar3);
  }
  else {
    iVar4 = (int)(uVar6 / 0x18);
    iVar5 = iVar5 + iVar4 * -0x18;
    if (totalHundredths < 86400000) {
      wVar3 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&DAT_001490c0 /* "%1ud" */),iVar4);
      RichString_appendnAscii(str,attrs_00,(*(char (*) [10])(__fp - 0x4a)),wVar3);
      wVar3 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&s__02uh_001490c5 /* "%02uh" */),iVar5);
      RichString_appendnAscii(str,attrs,(*(char (*) [10])(__fp - 0x4a)),wVar3);
      wVar3 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&s__02um_001490cb /* "%02um " */),va0);
      RichString_appendnAscii(str,wVar2,(*(char (*) [10])(__fp - 0x4a)),wVar3);
    }
    else if (totalHundredths < 0xbbf81e00) {
      wVar2 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&DAT_001490d2 /* "%4ud" */),iVar4);
      RichString_appendnAscii(str,attrs_00,(*(char (*) [10])(__fp - 0x4a)),wVar2);
      wVar2 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&s__02uh_001490d7 /* "%02uh " */),iVar5);
      RichString_appendnAscii(str,attrs,(*(char (*) [10])(__fp - 0x4a)),wVar2);
    }
    else {
      uVar6 = (uVar6 / 0x18) / 0x16d;
      if (totalHundredths < 0x2de41353000) {
        iVar5 = (int)uVar6;
        wVar2 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&DAT_001490de /* "%3uy" */),iVar5);
        RichString_appendnAscii(str,wVar3,(*(char (*) [10])(__fp - 0x4a)),wVar2);
        wVar2 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&s__03ud_001490e3 /* "%03ud " */),iVar4 + iVar5 * -0x16d);
        RichString_appendnAscii(str,attrs_00,(*(char (*) [10])(__fp - 0x4a)),wVar2);
      }
      else {
        if (0x7009d32da2ffff < totalHundredths) {
          if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
            RichString_appendAscii(str,wVar3,((char *)(long)&s_eternity_001490f1 /* "eternity " */));
            return;
          }
          goto LAB_00131646;
        }
        wVar2 = xSnprintf((*(char (*) [10])(__fp - 0x4a)),10,((char *)(long)&s__7luy_001490ea /* "%7luy " */),uVar6);
        RichString_appendnAscii(str,wVar3,(*(char (*) [10])(__fp - 0x4a)),wVar2);
      }
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_00131646:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* Row_printRate @ 0x131650 */

void Row_printRate(RichString *str,double rate,_Bool coloring)

{
  undefined1 __frame[0xe8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0xa8;
  long lVar1;
  int attrs;
  int attrs_00;
  int wVar2;
  int wVar3;
  char *pcVar4;
  long in_FS_OFFSET = (long)__fake_fs;
  double va0;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  wVar2 = CRT_colors[0x1d];
  wVar3 = CRT_colors[0x1e];
  attrs = wVar2;
  if (coloring) {
    attrs = CRT_colors[0x20];
  }
  attrs_00 = wVar2;
  if (coloring) {
    attrs_00 = CRT_colors[0xc];
  }
  if (rate < 0.0) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(str,wVar3,((char *)(long)&DAT_0014908c /* "        N/A " */));
      return;
    }
    goto LAB_001318c8;
  }
  if (rate < 0.005) {
                    /* Unresolved local var: int len@[???] */
    wVar2 = __snprintf_chk((*(char (*) [16])(__fp - 0x58)),0x10,2,0x10,((char *)(long)&s__7_2f_B_s_001490fb /* "%7.2f B/s " */),rate);
    RichString_appendnAscii(str,wVar3,(*(char (*) [16])(__fp - 0x58)),wVar2);
  }
  else {
    pcVar4 = ((char *)(long)&s__7_2f_B_s_001490fb /* "%7.2f B/s " */);
    if (1024.0 <= rate) {
      if (1048576.0 <= rate) {
        if (rate < 1073741824.0) {
                    /* Unresolved local var: int len@[???] */
          wVar2 = __snprintf_chk((*(char (*) [16])(__fp - 0x58)),0x10,2,0x10,((char *)(long)&s__7_2f_M_s_00149111 /* "%7.2f M/s " */),rate * 9.5367431640625e-07);
          RichString_appendnAscii(str,attrs,(*(char (*) [16])(__fp - 0x58)),wVar2);
        }
        else {
          if (rate < 1099511627776.0) {
                    /* Unresolved local var: int len@[???] */
            va0 = rate * 9.313225746154785e-10;
            pcVar4 = ((char *)(long)&s__7_2f_G_s_0014911c /* "%7.2f G/s " */);
          }
          else if (rate < 1125899906842624.0) {
                    /* Unresolved local var: int len@[???] */
            va0 = rate * 9.094947017729282e-13;
            pcVar4 = ((char *)(long)&s__7_2f_T_s_00149127 /* "%7.2f T/s " */);
          }
          else {
                    /* Unresolved local var: int len@[???] */
            va0 = rate * 8.881784197001252e-16;
            pcVar4 = ((char *)(long)&s__7_2f_P_s_00149132 /* "%7.2f P/s " */);
          }
          wVar2 = __snprintf_chk((*(char (*) [16])(__fp - 0x58)),0x10,2,0x10,pcVar4,va0);
          RichString_appendnAscii(str,attrs_00,(*(char (*) [16])(__fp - 0x58)),wVar2);
        }
        goto LAB_0013179f;
      }
                    /* Unresolved local var: int len@[???] */
      rate = rate * 0.0009765625;
      pcVar4 = ((char *)(long)&s__7_2f_K_s_00149106 /* "%7.2f K/s " */);
    }
                    /* Unresolved local var: int len@[???] */
    wVar3 = __snprintf_chk((*(char (*) [16])(__fp - 0x58)),0x10,2,0x10,pcVar4,rate);
    RichString_appendnAscii(str,wVar2,(*(char (*) [16])(__fp - 0x58)),wVar3);
  }
LAB_0013179f:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
LAB_001318c8:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

