/* Machine_done @ 00121030 size 46 */

/* DWARF original prototype: void Machine_done(Machine * this) */

void Machine_done(Machine *this)

{
  long in_RCX;
  long in_RDX;
  long in_RSI;
  long in_R8;
  long in_R9;

  (*((this->processTable->super).klass)->delete)
            (&this->processTable->super,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
  free(this->tables);
  return;
}

