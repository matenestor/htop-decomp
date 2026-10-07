/* OptionItem_delete @ 0011fed0 size 38 */

void OptionItem_delete(OptionItem_ *cast)

{
  free(cast->text);
  free(cast);
  return;
}

