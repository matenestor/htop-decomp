/* CPUMeter_getUiName @ 0011c4d0 size 57 */

/* DWARF original prototype: void CPUMeter_getUiName(Meter * this, char * buffer, size_t length) */

void CPUMeter_getUiName(Meter *this,char *buffer,size_t length)

{
  Object_Compare va0;

  va0 = (this->super).klass[3].compare;
  if (this->param != 0) {
    xSnprintf(buffer,length,((char *)0x14749f /* "%s %u" */),va0,this->param);
    return;
  }
  xSnprintf(buffer,length,((char *)0x147626 /* "%s" */),va0);
  return;
}

