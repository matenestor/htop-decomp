/* ListItem_compare @ 0011ff00 size 17 */

wchar_t ListItem_compare(void *cast1,void *cast2)

{
  wchar_t wVar1;

  wVar1 = strcmp(*(char **)((long)cast1 + 8),*(char **)((long)cast2 + 8));
  return wVar1;
}

