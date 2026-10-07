/* RowField_alignedTitle @ 00128b40 size 350 */

char * RowField_alignedTitle(Settings_4 *settings,RowField field)

{
  ulong uVar1;
  HashtableItem *pHVar2;
  wchar_t wVar3;
  ulong uVar4;
  wchar_t va0;
  HashtableItem *pHVar5;
  ulong uVar6;
  wchar_t *pwVar7;
  void *pvVar8;
  char *va2;

  if (0x83 < field) {
                    /* Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: wchar_t width@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
    uVar1 = settings->dynamicColumns->size;
    pHVar2 = settings->dynamicColumns->buckets;
    uVar6 = (ulong)(long)field % uVar1;
                    /* Unresolved local var: char * title@[???] */
    pvVar8 = pHVar2[uVar6].value;
    if (pvVar8 == (void *)0x0) {
      return ((char *)0x147411 /* "- " */);
    }
    uVar4 = 0;
    pHVar5 = pHVar2 + uVar6;
    do {
      while( true ) {
        if (field == pHVar5->key) {
          va0 = *(wchar_t *)((long)pvVar8 + 0x38);
          if (va0 == L'\0') {
            va0 = L'\xfffffffb';
          }
          else {
            wVar3 = -va0;
            if (-va0 < L'\0') {
              wVar3 = va0;
            }
            if (L'@' < wVar3) {
              va0 = L'\xfffffffb';
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
    return ((char *)0x147411 /* "- " */);
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
      xSnprintf(titleBuffer,0x101,((char *)0x14884c /* "%-*.*s " */),(uint)Row_fieldWidths[field],
                (uint)Row_fieldWidths[field],va2);
      goto LAB_00128c17;
    }
    va0 = (wchar_t)Row_fieldWidths[0x2f];
  }
  else {
    pwVar7 = &Row_pidDigits;
LAB_00128c9f:
    va0 = *pwVar7;
  }
LAB_00128bfd:
  xSnprintf(titleBuffer,0x101,((char *)0x148847 /* "%*s " */),va0,va2);
LAB_00128c17:
  return titleBuffer;
}

