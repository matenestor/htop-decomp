/* DynamicScreens_delete @ 00117520 size 49 */

void DynamicScreens_delete(Hashtable *param_1)

{
  if (param_1 != (Hashtable *)0x0) {
    Hashtable_clear(param_1);
    free(param_1->buckets);
    free(param_1);
    return;
  }
  return;
}

