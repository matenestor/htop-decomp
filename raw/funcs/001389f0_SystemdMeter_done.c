/* SystemdMeter_done @ 001389f0 size 156 */

/* DWARF original prototype: void SystemdMeter_done(Meter * this) */

void SystemdMeter_done(Meter *this)

{
  int iVar1;
  long in_RCX;
  long a2;
  SystemdMeterContext_t *pSVar2;
  char *a1;
  long in_R8;
  long in_R9;
  bool bVar3;

  a1 = ((char *)0x1477b1 /* "SystemdUser" */);
  pSVar2 = &ctx_system;
  iVar1 = strcmp((char *)(this->super).klass[3].delete,((char *)0x1477b1 /* "SystemdUser" */));
  if (iVar1 == 0) {
    pSVar2 = &ctx_user;
  }
  free(pSVar2->systemState);
  pSVar2->systemState = (char *)0x0;
  if ((pSVar2->bus != (sd_bus *)0x0) && (dlopenHandle_15d830 != (void *)0x0)) {
    (*sym_sd_bus_unref)(pSVar2->bus,(long)a1,a2,in_RCX,in_R8,in_R9);
  }
  bVar3 = ctx_system.systemState == (char *)0x0;
  pSVar2->bus = (sd_bus *)0x0;
  if (((bVar3) && (ctx_user.systemState == (char *)0x0)) && (dlopenHandle_15d830 != (void *)0x0)) {
    dlclose(dlopenHandle_15d830);
    dlopenHandle_15d830 = (void *)0x0;
  }
  return;
}

