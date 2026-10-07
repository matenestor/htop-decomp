/* Process_init @ 00122850 size 37 */

/* DWARF original prototype: void Process_init(Process * this, Machine * host) */

void Process_init(Process *this,Machine_3 *host)

{
  (this->super).host = (Machine_ *)host;
  (this->super).tag = false;
  (this->super).show = true;
  (this->super).wasShown = false;
  (this->super).showChildren = true;
  (this->super).updated = false;
  this->cmdlineBasenameEnd = L'\xffffffff';
  this->st_uid = 0xffffffff;
  return;
}

