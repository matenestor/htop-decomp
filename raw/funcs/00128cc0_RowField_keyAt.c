/* RowField_keyAt @ 00128cc0 size 124 */

RowField RowField_keyAt(Settings_4 *settings,wchar_t at)

{
  int field;
  char *__s;
  size_t sVar1;
  wchar_t wVar2;
  int *piVar3;

  wVar2 = L'\0';
  piVar3 = settings->ss->fields;
                    /* Unresolved local var: wchar_t i@[???] */
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

