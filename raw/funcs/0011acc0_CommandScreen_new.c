/* CommandScreen_new @ 0011acc0 size 83 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CommandScreen * CommandScreen_new(Process *process)

{
  InfoScreen *this;
  InfoScreen_2 *pIVar1;

                    /* Unresolved local var: void * data@[???] */
  this = malloc(0x28);
  if (this != (InfoScreen *)0x0) {
    (this->super).klass = &CommandScreen_class.super;
    pIVar1 = InfoScreen_init(this,process,(FunctionBar *)0x0,_LINES + L'\xfffffffe',((char *)0x1470dd /* " " */));
    return (CommandScreen *)pIVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

