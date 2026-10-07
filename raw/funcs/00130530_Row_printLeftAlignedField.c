/* Row_printLeftAlignedField @ 00130530 size 221 */

void Row_printLeftAlignedField(RichString *str,wchar_t attr,char *content,uint width)

{
  uint uVar1;
  wchar_t wVar2;
  cchar_t *pcVar3;
  size_t sVar4;
  cchar_t *pcVar5;
  cchar_t *pcVar6;
  wchar_t len;
  long in_FS_OFFSET;
  wchar_t columns;
  long local_40;

  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  columns = width;
  sVar4 = strlen(content);
  RichString_appendnWideColumns(str,attr,content,(wchar_t)sVar4,&columns);
  uVar1 = (width - columns) + 1;
                    /* Unresolved local var: wchar_t from@[???]
                       Unresolved local var: wchar_t newLen@[???] */
  wVar2 = str->chlen;
  len = uVar1 + wVar2;
  RichString_setLen(str,len);
                    /* Unresolved local var: wchar_t i@[???] */
  if (wVar2 < len) {
    pcVar3 = str->chptr;
    pcVar5 = pcVar3 + wVar2;
    do {
      pcVar5->attr = 0;
      pcVar5->chars[0] = L'\0';
      pcVar5->chars[1] = L'\0';
      pcVar5->chars[2] = L'\0';
      pcVar6 = pcVar5 + 1;
      *(undefined1 (*) [16])(pcVar5->chars + 2) = (undefined1  [16])0x0;
      pcVar5->attr = attr;
      pcVar5->chars[0] = L' ';
      pcVar5 = pcVar6;
    } while (pcVar6 != pcVar3 + (ulong)uVar1 + (long)wVar2);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

