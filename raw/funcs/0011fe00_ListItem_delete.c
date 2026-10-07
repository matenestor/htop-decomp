/* ListItem_delete @ 0011fe00 size 38 */

void ListItem_delete(ListItem_ *cast)

{
  free(cast->value);
  free(cast);
  return;
}

