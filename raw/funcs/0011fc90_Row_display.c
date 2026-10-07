/* Row_display @ 0011fc90 size 341 */

void Row_display(Row_ *cast,RichString *out)

{
  char cVar1;
  uint uVar2;
  wchar_t wVar3;
  Settings__2 *pSVar4;
  code *pcVar5;
  ulong uVar6;
  wchar_t wVar7;
  long lVar8;
  wchar_t wVar9;
  long in_RCX;
  cchar_t *pcVar10;
  uint *puVar11;
  RichString *a1;
  long in_R8;
  long in_R9;

  pSVar4 = cast->host->settings;
  puVar11 = (uint *)pSVar4->ss->fields;
                    /* Unresolved local var: wchar_t i@[???] */
  uVar2 = *puVar11;
  a1 = out;
  while (uVar2 != 0) {
    puVar11 = puVar11 + 1;
    a1 = out;
    (*(cast->super).klass[1].delete)(&cast->super,(long)out,(ulong)uVar2,in_RCX,in_R8,in_R9);
    uVar2 = *puVar11;
  }
  pcVar5 = (cast->super).klass[1].extends;
  if ((pcVar5 == (code *)0x0) ||
     (lVar8 = (*pcVar5)((long)cast,(long)a1,0,in_RCX,in_R8,in_R9), (char)lVar8 == '\0')) {
    cVar1 = cast->tag;
  }
  else {
                    /* Unresolved local var: wchar_t end@[???] */
    wVar3 = CRT_colors[0x1e];
    wVar7 = out->chlen;
    wVar9 = L'\0';
    if (L'\xffffffff' < wVar7) {
      wVar9 = wVar7;
    }
                    /* Unresolved local var: wchar_t i@[???] */
    if (wVar7 < L'\x01') goto LAB_0011fcfb;
    pcVar10 = out->chptr;
    wVar7 = L'\0';
    do {
      wVar7 = wVar7 + L'\x01';
      pcVar10->attr = wVar3;
      pcVar10 = pcVar10 + 1;
    } while (wVar7 < wVar9);
    cVar1 = cast->tag;
  }
  if (cVar1 != '\0') {
                    /* Unresolved local var: wchar_t end@[???] */
    wVar3 = CRT_colors[0x1f];
    wVar7 = out->chlen;
    wVar9 = L'\0';
    if (L'\xffffffff' < wVar7) {
      wVar9 = wVar7;
    }
                    /* Unresolved local var: wchar_t i@[???] */
    if (L'\0' < wVar7) {
      pcVar10 = out->chptr;
      wVar7 = L'\0';
      do {
        wVar7 = wVar7 + L'\x01';
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

