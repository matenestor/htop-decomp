/* sortTtyDrivers @ 00138920 size 45 */

wchar_t sortTtyDrivers(void *va,void *vb)

{
  wchar_t wVar1;

  wVar1 = (uint)(*(uint *)((long)vb + 8) < *(uint *)((long)va + 8)) -
          (uint)(*(uint *)((long)va + 8) < *(uint *)((long)vb + 8));
  if (wVar1 == L'\0') {
                    /* Unresolved local var: TtyDriver * a@[???]
                       Unresolved local var: TtyDriver * b@[???]
                       Unresolved local var: wchar_t r@[???] */
    wVar1 = (uint)(*(uint *)((long)vb + 0xc) < *(uint *)((long)va + 0xc)) -
            (uint)(*(uint *)((long)va + 0xc) < *(uint *)((long)vb + 0xc));
  }
  return wVar1;
}

