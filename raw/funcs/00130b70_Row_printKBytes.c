/* Row_printKBytes @ 00130b70 size 980 */

void Row_printKBytes(RichString *str,ulonglong number,_Bool coloring)

{
  char cVar1;
  long lVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  wchar_t wVar5;
  int iVar6;
  char *pcVar7;
  long lVar8;
  ulong uVar9;
  int va0;
  long in_FS_OFFSET;
  wchar_t colors [4];
  char buffer [16];

  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  wVar4 = CRT_colors[0x1d];
  colors[0] = wVar4;
  colors[1] = CRT_colors[0x20];
  colors[2] = CRT_colors[0x21];
  colors[3] = CRT_colors[0xc];
  if (number == 0xffffffffffffffff) {
    if (coloring) {
      wVar4 = CRT_colors[0x1e];
    }
    if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
      RichString_appendAscii(str,wVar4,((char *)0x149092 /* "  N/A " */));
      return;
    }
  }
  else {
    wVar5 = CRT_colors[0x20];
    if (!coloring) {
      wVar5 = wVar4;
    }
    if (number < 1000) {
      wVar5 = xSnprintf(buffer,0x10,((char *)0x149063 /* "%5u " */),(int)number);
      RichString_appendnAscii(str,wVar4,buffer,wVar5);
    }
    else if (number < 100000) {
      iVar6 = (int)(number / 1000);
      wVar3 = xSnprintf(buffer,0x10,((char *)0x149068 /* "%2u" */),iVar6);
      RichString_appendnAscii(str,wVar5,buffer,wVar3);
      wVar5 = xSnprintf(buffer,0x10,((char *)0x14906c /* "%03u " */),(int)number + iVar6 * -1000);
      RichString_appendnAscii(str,wVar4,buffer,wVar5);
    }
    else {
      lVar8 = 1;
      uVar9 = ((number & 0xff) * 0x19 >> 8) + (number >> 8) * 0x19;
      while( true ) {
        wVar3 = wVar5;
        if ((coloring) && (lVar8 + 1U < 4)) {
          wVar3 = colors[lVar8 + 1];
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
          wVar3 = xSnprintf(buffer,0x10,((char *)0x149079 /* "%1u" */),9);
          RichString_appendnAscii(str,wVar5,buffer,wVar3);
          pcVar7 = ((char *)0x149072 /* ".%02u" */);
        }
        else {
          wVar3 = xSnprintf(buffer,0x10,((char *)0x149068 /* "%2u" */),iVar6);
          RichString_appendnAscii(str,wVar5,buffer,wVar3);
          pcVar7 = ((char *)0x149078 /* ".%1u" */);
          va0 = (int)((uVar9 % 100) / 10);
        }
        wVar3 = xSnprintf(buffer,0x10,pcVar7,va0);
        RichString_appendnAscii(str,wVar4,buffer,wVar3);
        wVar4 = xSnprintf(buffer,0x10,((char *)0x149088 /* "%c " */),(int)((char *)0x14db98 /* "KMGTPEZYRQ" */)[lVar8]);
      }
      else {
        if (uVar9 < 100000) {
          cVar1 = ((char *)0x14db98 /* "KMGTPEZYRQ" */)[lVar8];
          pcVar7 = ((char *)0x14907d /* "%4u%c " */);
        }
        else {
          uVar9 = uVar9 / 100 & 0xffffffff;
          wVar4 = xSnprintf(buffer,0x10,((char *)0x149079 /* "%1u" */),(int)(uVar9 / 1000));
          RichString_appendnAscii(str,wVar3,buffer,wVar4);
          pcVar7 = ((char *)0x149084 /* "%03u%c " */);
          cVar1 = ((char *)0x14db98 /* "KMGTPEZYRQ" */)[lVar8];
          iVar6 = iVar6 + (int)(uVar9 / 1000) * -1000;
        }
        wVar4 = xSnprintf(buffer,0x10,pcVar7,iVar6,(int)cVar1);
      }
      RichString_appendnAscii(str,wVar5,buffer,wVar4);
    }
    if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

