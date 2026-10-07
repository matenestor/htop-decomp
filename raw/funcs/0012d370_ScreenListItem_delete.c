/* ScreenListItem_delete @ 0012d370 size 81 */

void ScreenListItem_delete(ScreenListItem_ *cast)

{
  ScreenSettings_4 *__ptr;

  __ptr = cast->ss;
  if (__ptr != (ScreenSettings_4 *)0x0) {
    free(__ptr->heading);
    free(__ptr->dynamic);
    free(__ptr->fields);
    free(__ptr);
  }
                    /* Unresolved local var: ListItem * this@[???] */
  free((cast->super).value);
  free(cast);
  return;
}

