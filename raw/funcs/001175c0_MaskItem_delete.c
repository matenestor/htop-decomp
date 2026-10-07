/* MaskItem_delete @ 001175c0 size 56 */

void MaskItem_delete(MaskItem_ *cast)

{
  free(cast->text);
  free(cast->indent);
  Vector_delete(cast->children);
  free(cast);
  return;
}

