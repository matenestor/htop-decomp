/* Row_compare @ 0012d200 size 25 */

wchar_t Row_compare(void *v1,void *v2)

{
  return (uint)(*(int *)((long)v2 + 0x10) < *(int *)((long)v1 + 0x10)) -
         (uint)(*(int *)((long)v1 + 0x10) < *(int *)((long)v2 + 0x10));
}

