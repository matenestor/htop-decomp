/* String_safeStrncpy @ 0013a410 size 45 */

size_t String_safeStrncpy(char *dest,char *src,size_t size)

{
  size_t sVar1;

  sVar1 = 0;
  if (size != 1) {
    do {
      if (src[sVar1] == '\0') break;
      dest[sVar1] = src[sVar1];
      sVar1 = sVar1 + 1;
    } while (sVar1 != size - 1);
    dest = dest + sVar1;
  }
  *dest = '\0';
  return sVar1;
}

