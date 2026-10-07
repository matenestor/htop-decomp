/* Machine_delete @ 0013b1c0 size 66 */

void Machine_delete(LinuxMachine_ *super)

{
  Table_4 *pTVar1;
  long in_RCX;
  long in_RDX;
  long in_RSI;
  long in_R8;
  long in_R9;

  pTVar1 = (super->super).processTable;
  (*((pTVar1->super).klass)->delete)(&pTVar1->super,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
  free((super->super).tables);
  free(super->cpuData);
  free(super);
  return;
}

