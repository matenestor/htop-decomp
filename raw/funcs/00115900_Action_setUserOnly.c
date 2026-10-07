/* Action_setUserOnly @ 00115900 size 57 */

_Bool Action_setUserOnly(char *userName,uid_t *userId)

{
  passwd *ppVar1;

  ppVar1 = getpwnam(userName);
  if (ppVar1 != (passwd *)0x0) {
    *userId = ppVar1->pw_uid;
    return true;
  }
  *userId = 0xffffffff;
  return false;
}

