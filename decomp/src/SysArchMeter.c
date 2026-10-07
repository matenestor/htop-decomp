#include "htop.h"

/* SysArchMeter_updateValues @ 0x12d9d0 */

/* DWARF original prototype: void SysArchMeter_updateValues(Meter * this) */

void SysArchMeter_updateValues(Meter *this)

{
  char *pcVar1;
  long lVar2;

  if (string == (char *)0x0) {
    if (loaded_data_1_lto_priv_0 == '\0') {
      Generic_uname();
      lVar2 = 0;
      string = &savedString_0_lto_priv_0;
      do {
        if ((&savedString_0_lto_priv_0)[lVar2] == '\0') break;
        this->txtBuffer[lVar2] = (&savedString_0_lto_priv_0)[lVar2];
        lVar2 = lVar2 + 1;
      } while (lVar2 != 0xff);
      this->txtBuffer[lVar2] = '\0';
      return;
    }
    string = &savedString_0_lto_priv_0;
  }
  pcVar1 = string;
                    /* Unresolved local var: size_t i@[???] */
  lVar2 = 0;
  do {
    if (pcVar1[lVar2] == '\0') break;
    this->txtBuffer[lVar2] = pcVar1[lVar2];
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0xff);
  this->txtBuffer[lVar2] = '\0';
  return;
}

