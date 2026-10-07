/* Hashtable_setSize_118260 @ 00118260 size 16 */

/* DWARF original prototype: void Hashtable_setSize(Hashtable * this, size_t size) */

void __thiscall Hashtable_setSize_118260(void *this,size_t size)

{
  if (size <= *(ulong *)((long)this + 0x10)) {
    return;
  }
  Hashtable_setSize(this,size);
  return;
}

