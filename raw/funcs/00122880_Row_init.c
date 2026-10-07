/* Row_init @ 00122880 size 20 */

/* DWARF original prototype: void Row_init(Row * this, Machine * host) */

void Row_init(Row *this,Machine_2 *host)

{
  this->host = (Machine_ *)host;
  this->tag = false;
  this->show = true;
  this->wasShown = false;
  this->showChildren = true;
  this->updated = false;
  return;
}

