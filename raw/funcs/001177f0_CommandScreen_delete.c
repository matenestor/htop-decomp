/* CommandScreen_delete @ 001177f0 size 138 */

/* DWARF original prototype: void CommandScreen_delete(Object * this) */

void CommandScreen_delete(Object *this)

{
  ObjectClass *pOVar1;

  pOVar1 = this[2].klass;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
  free(pOVar1[1].compare);
  Vector_delete(pOVar1[1].extends);
  FunctionBar_delete((FunctionBar *)pOVar1[2].compare);
  if (0x15e < *(int *)&pOVar1[3].extends) {
    free(pOVar1[3].display);
  }
  free(pOVar1);
  pOVar1 = this[3].klass;
  FunctionBar_delete((FunctionBar *)pOVar1[4].display);
  FunctionBar_delete(pOVar1[9].extends);
  free(pOVar1);
  Vector_delete((Vector *)this[4].klass);
  free(this);
  return;
}

