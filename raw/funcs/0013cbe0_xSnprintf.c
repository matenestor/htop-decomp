/* xSnprintf @ 0013cbe0 size 214 */

wchar_t xSnprintf(char *buf,size_t len,char *fmt,...)

{
  long lVar1;
  char in_AL;
  wchar_t wVar2;
  undefined8 in_RCX;
  undefined8 in_R8;
  undefined8 in_R9;
  long in_FS_OFFSET;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  va_list vl;
  undefined1 local_c8 [24];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;

  if (in_AL != '\0') {
    local_98 = in_XMM0_Qa;
    local_88 = in_XMM1_Qa;
    local_78 = in_XMM2_Qa;
    local_68 = in_XMM3_Qa;
    local_58 = in_XMM4_Qa;
    local_48 = in_XMM5_Qa;
    local_38 = in_XMM6_Qa;
    local_28 = in_XMM7_Qa;
  }
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  vl[0].overflow_arg_area = &stack0x00000008;
  vl[0].reg_save_area = local_c8;
  vl[0].gp_offset = 0x18;
  vl[0].fp_offset = 0x30;
  local_b0 = in_RCX;
  local_a8 = in_R8;
  local_a0 = in_R9;
  wVar2 = __vsnprintf_chk(buf,len,2,len,fmt,vl);
  if ((L'\xffffffff' < wVar2) && ((ulong)(long)wVar2 < len)) {
    if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
      return wVar2;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

