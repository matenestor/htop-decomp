/* EnvScreen_new @ 0011ab90 size 83 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

EnvScreen * EnvScreen_new(Process_2 *process)

{
  InfoScreen *this;
  InfoScreen_2 *pIVar1;

                    /* Unresolved local var: void * data@[???] */
  this = malloc(0x28);
  if (this != (InfoScreen *)0x0) {
    (this->super).klass = &EnvScreen_class.super;
    pIVar1 = InfoScreen_init(this,(Process *)process,(FunctionBar *)0x0,_LINES + L'\xfffffffe',((char *)0x1470dd /* " " */));
    return (EnvScreen *)pIVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

