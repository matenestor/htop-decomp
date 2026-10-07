/* Row_printTime @ 00131250 size 985 */

void Row_printTime(RichString *str,ulonglong totalHundredths,_Bool coloring)

{
  long lVar1;
  wchar_t wVar2;
  wchar_t wVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  int va1;
  int va0;
  wchar_t attrs;
  wchar_t attrs_00;
  long in_FS_OFFSET;
  char buffer [10];

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
    wVar3 = xSnprintf(buffer,10,((char *)0x1490a1 /* "%2u:%02u.%02u " */),iVar4,va1,(int)totalHundredths + (int)uVar7 * -100)
    ;
    RichString_appendnAscii(str,wVar2,buffer,wVar3);
  }
  else if (totalHundredths < 0x83d600) {
    wVar3 = xSnprintf(buffer,10,((char *)0x1490b0 /* "%2uh" */),iVar5);
    RichString_appendnAscii(str,attrs,buffer,wVar3);
    wVar3 = xSnprintf(buffer,10,((char *)0x1490b5 /* "%02u:%02u " */),va0,va1);
    RichString_appendnAscii(str,wVar2,buffer,wVar3);
  }
  else {
    iVar4 = (int)(uVar6 / 0x18);
    iVar5 = iVar5 + iVar4 * -0x18;
    if (totalHundredths < 86400000) {
      wVar3 = xSnprintf(buffer,10,((char *)0x1490c0 /* "%1ud" */),iVar4);
      RichString_appendnAscii(str,attrs_00,buffer,wVar3);
      wVar3 = xSnprintf(buffer,10,((char *)0x1490c5 /* "%02uh" */),iVar5);
      RichString_appendnAscii(str,attrs,buffer,wVar3);
      wVar3 = xSnprintf(buffer,10,((char *)0x1490cb /* "%02um " */),va0);
      RichString_appendnAscii(str,wVar2,buffer,wVar3);
    }
    else if (totalHundredths < 0xbbf81e00) {
      wVar2 = xSnprintf(buffer,10,((char *)0x1490d2 /* "%4ud" */),iVar4);
      RichString_appendnAscii(str,attrs_00,buffer,wVar2);
      wVar2 = xSnprintf(buffer,10,((char *)0x1490d7 /* "%02uh " */),iVar5);
      RichString_appendnAscii(str,attrs,buffer,wVar2);
    }
    else {
      uVar6 = (uVar6 / 0x18) / 0x16d;
      if (totalHundredths < 0x2de41353000) {
        iVar5 = (int)uVar6;
        wVar2 = xSnprintf(buffer,10,((char *)0x1490de /* "%3uy" */),iVar5);
        RichString_appendnAscii(str,wVar3,buffer,wVar2);
        wVar2 = xSnprintf(buffer,10,((char *)0x1490e3 /* "%03ud " */),iVar4 + iVar5 * -0x16d);
        RichString_appendnAscii(str,attrs_00,buffer,wVar2);
      }
      else {
        if (0x7009d32da2ffff < totalHundredths) {
          if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
            RichString_appendAscii(str,wVar3,((char *)0x1490f1 /* "eternity " */));
            return;
          }
          goto LAB_00131646;
        }
        wVar2 = xSnprintf(buffer,10,((char *)0x1490ea /* "%7luy " */),uVar6);
        RichString_appendnAscii(str,wVar3,buffer,wVar2);
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

