/* Meter_new @ 00123520 size 203 */

Meter_3 * Meter_new(Machine_2 *host,uint param,MeterClass_3 *type)

{
  double dVar1;
  byte bVar2;
  code *pcVar3;
  Meter_3 *this;
  char *pcVar4;
  double *pdVar5;
  long in_RCX;
  long a2;
  long a1;
  long in_R8;
  long in_R9;

                    /* Unresolved local var: void * data@[???] */
  a1 = 0x178;
  this = calloc(1,0x178);
  if (this != (Meter_3 *)0x0) {
    bVar2 = type->maxItems;
    (this->super).klass = &type->super;
    this->h = L'\x01';
    this->param = param;
    this->host = host;
    this->curItems = bVar2;
    this->curAttributes = (wchar_t *)0x0;
    pdVar5 = (double *)0x0;
    if (bVar2 != 0) {
                    /* Unresolved local var: void * data@[???] */
      a1 = 8;
      pdVar5 = calloc((ulong)bVar2,8);
      if (pdVar5 == (double *)0x0) goto LAB_001235ef;
    }
    dVar1 = type->total;
    this->values = pdVar5;
                    /* Unresolved local var: char * data@[???] */
    pcVar4 = type->caption;
    this->total = dVar1;
    pcVar4 = strdup(pcVar4);
    if (pcVar4 != (char *)0x0) {
      this->caption = pcVar4;
      pcVar3 = (this->super).klass[1].extends;
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)((long)this,a1,a2,in_RCX,in_R8,in_R9);
      }
      Meter_setMode((Meter *)this,type->defaultMode);
      return this;
    }
  }
LAB_001235ef:
                    /* WARNING: Subroutine does not return */
  fail();
}

