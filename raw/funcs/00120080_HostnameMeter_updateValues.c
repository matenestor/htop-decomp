/* HostnameMeter_updateValues @ 00120080 size 43 */

/* DWARF original prototype: void HostnameMeter_updateValues(Meter * this) */

void HostnameMeter_updateValues(Meter *this)

{
  gethostname(this->txtBuffer,0xff);
  this->txtBuffer[0xff] = '\0';
  return;
}

