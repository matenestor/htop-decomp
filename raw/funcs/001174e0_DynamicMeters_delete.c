/* DynamicMeters_delete @ 001174e0 size 49 */

void DynamicMeters_delete(Hashtable *param_1)

{
  if (param_1 != (Hashtable *)0x0) {
    Hashtable_clear(param_1);
    free(param_1->buckets);
    free(param_1);
    return;
  }
  return;
}

