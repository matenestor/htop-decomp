/* _SystemdMeter_display @ 001448c0 size 758 */

void _SystemdMeter_display(Object *cast,RichString *out,SystemdMeterContext_t *ctx)

{
  attr_t aVar1;
  long lVar2;
  int iVar3;
  wchar_t wVar4;
  wchar_t wVar5;
  long lVar6;
  cchar_t *__s1;
  long in_FS_OFFSET;
  char buffer [16];

                    /* Unresolved local var: wchar_t len@[???]
                       Unresolved local var: wchar_t color@[???] */
  __s1 = out->chptr;
  lVar2 = *(long *)(in_FS_OFFSET + 0x28);
  if (__s1 == (cchar_t *)0x0) {
    lVar6 = 0x40;
    __s1 = (cchar_t *)&DAT_001474de;
  }
  else {
    iVar3 = strcmp((char *)__s1,((char *)0x149149 /* "running" */));
    lVar6 = 0x50;
    if (iVar3 != 0) {
      iVar3 = strcmp((char *)__s1,((char *)0x14a0ca /* "degraded" */));
      lVar6 = (-(ulong)(iVar3 == 0) & 0xffffffffffffffec) + 0x54;
    }
  }
  RichString_writeAscii((RichString *)cast,*(wchar_t *)((long)CRT_colors + lVar6),(char *)__s1);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)0x14a0db /* " (" */));
  aVar1 = out->chstr[0].attr;
  if (aVar1 == 0xffffffff) {
    wVar5 = L'\x01';
    buffer[0] = '?';
    buffer[1] = '\0';
LAB_0014495f:
    wVar4 = CRT_colors[0x10];
  }
  else {
    wVar5 = xSnprintf(buffer,0x10,((char *)0x1474a2 /* "%u" */),aVar1);
    aVar1 = out->chstr[0].attr;
    if (aVar1 == 0) {
      wVar4 = CRT_colors[0xf];
    }
    else {
      if (aVar1 == 0xffffffff) goto LAB_0014495f;
      wVar4 = CRT_colors[0x13];
    }
  }
  RichString_appendnAscii((RichString *)cast,wVar4,buffer,wVar5);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)0x1487c2 /* "/" */));
  wVar5 = out->chstr[0].chars[1];
  if (wVar5 == L'\xffffffff') {
    buffer[0] = '?';
    buffer[1] = '\0';
    wVar4 = L'\x01';
LAB_001449a5:
    wVar5 = CRT_colors[0x10];
  }
  else {
    wVar4 = xSnprintf(buffer,0x10,((char *)0x1474a2 /* "%u" */),wVar5);
    wVar5 = out->chstr[0].chars[1];
    if (wVar5 == L'\0') {
      wVar5 = CRT_colors[0x13];
    }
    else {
      if (wVar5 == L'\xffffffff') goto LAB_001449a5;
      wVar5 = CRT_colors[0xf];
    }
  }
  RichString_appendnAscii((RichString *)cast,wVar5,buffer,wVar4);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)0x14a0d3 /* " failed) (" */));
  wVar5 = out->chstr[0].chars[2];
  if (wVar5 == L'\xffffffff') {
    wVar4 = L'\x01';
    buffer[0] = '?';
    buffer[1] = '\0';
LAB_001449e8:
    wVar5 = CRT_colors[0x10];
  }
  else {
    wVar4 = xSnprintf(buffer,0x10,((char *)0x1474a2 /* "%u" */),wVar5);
    wVar5 = out->chstr[0].chars[2];
    if (wVar5 == L'\0') {
      wVar5 = CRT_colors[0xf];
    }
    else {
      if (wVar5 == L'\xffffffff') goto LAB_001449e8;
      wVar5 = CRT_colors[0x13];
    }
  }
  RichString_appendnAscii((RichString *)cast,wVar5,buffer,wVar4);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)0x1487c2 /* "/" */));
  wVar5 = out->chstr[0].chars[0];
  if (wVar5 == L'\xffffffff') {
    wVar4 = L'\x01';
    buffer[0] = '?';
    buffer[1] = '\0';
  }
  else {
    wVar4 = xSnprintf(buffer,0x10,((char *)0x1474a2 /* "%u" */),wVar5);
    wVar5 = out->chstr[0].chars[0];
    if (wVar5 == L'\0') {
      wVar5 = CRT_colors[0x13];
      goto LAB_00144a2a;
    }
    if (wVar5 != L'\xffffffff') {
      wVar5 = CRT_colors[0xf];
      goto LAB_00144a2a;
    }
  }
  wVar5 = CRT_colors[0x10];
LAB_00144a2a:
  RichString_appendnAscii((RichString *)cast,wVar5,buffer,wVar4);
  RichString_appendAscii((RichString *)cast,CRT_colors[0xe],((char *)0x14a0de /* " jobs)" */));
  if (lVar2 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

