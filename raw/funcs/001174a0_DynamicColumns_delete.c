/* DynamicColumns_delete @ 001174a0 size 49 */

void DynamicColumns_delete(Hashtable_2 *dynamics)

{
  if (dynamics != (Hashtable_2 *)0x0) {
    Hashtable_clear(dynamics);
    free(dynamics->buckets);
    free(dynamics);
    return;
  }
  return;
}

