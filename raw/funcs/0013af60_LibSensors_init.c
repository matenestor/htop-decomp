/* LibSensors_init @ 0013af60 size 446 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

wchar_t LibSensors_init(void)

{
  wchar_t wVar1;
  char *pcVar2;
  char *pcVar3;
  long in_RCX;
  long in_RDX;
  long a2;
  long in_RSI;
  long in_R8;
  long in_R9;

  if (dlopenHandle != (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0013af70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    wVar1 = (*sym_sensors_init)((FILE *)0x0,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
    return wVar1;
  }
  dlopenHandle = dlopen(((char *)0x149920 /* "libsensors.so" */),1);
  if (((dlopenHandle != (void *)0x0) ||
      (dlopenHandle = dlopen(((char *)0x14992e /* "libsensors.so.5" */),1), dlopenHandle != (void *)0x0)) ||
     (dlopenHandle = dlopen(((char *)0x14993e /* "libsensors.so.4" */),1), dlopenHandle != (void *)0x0)) {
    dlerror();
    sym_sensors_init = dlsym(dlopenHandle,((char *)0x1499b7 /* "sensors_init" */));
    if (((((sym_sensors_init != (_func_wchar_t_FILE_ptr *)0x0) &&
          (pcVar2 = dlerror(), pcVar2 == (char *)0x0)) &&
         ((sym_sensors_cleanup = dlsym(dlopenHandle,((char *)0x14994e /* "sensors_cleanup" */)),
          sym_sensors_cleanup != (_func_void *)0x0 &&
          ((pcVar2 = dlerror(), pcVar2 == (char *)0x0 &&
           (sym_sensors_get_detected_chips = dlsym(dlopenHandle,((char *)0x14995e /* "sensors_get_detected_chips" */)),
           sym_sensors_get_detected_chips !=
           (_func_sensors_chip_name_ptr_sensors_chip_name_ptr_wchar_t_ptr *)0x0)))))) &&
        (pcVar2 = dlerror(), pcVar2 == (char *)0x0)) &&
       ((((sym_sensors_get_features = dlsym(dlopenHandle,((char *)0x149979 /* "sensors_get_features" */)),
          sym_sensors_get_features !=
          (_func_sensors_feature_ptr_sensors_chip_name_ptr_wchar_t_ptr *)0x0 &&
          (pcVar2 = dlerror(), pcVar2 == (char *)0x0)) &&
         (sym_sensors_get_subfeature = dlsym(dlopenHandle,((char *)0x14998e /* "sensors_get_subfeature" */)),
         sym_sensors_get_subfeature !=
         (_func_sensors_subfeature_ptr_sensors_chip_name_ptr_sensors_feature_ptr_sensors_subfeature_type
          *)0x0)) && (pcVar2 = dlerror(), pcVar2 == (char *)0x0)))) {
      pcVar2 = ((char *)0x1499a5 /* "sensors_get_value" */);
      sym_sensors_get_value = dlsym(dlopenHandle,((char *)0x1499a5 /* "sensors_get_value" */));
      if ((sym_sensors_get_value != (_func_wchar_t_sensors_chip_name_ptr_wchar_t_double_ptr *)0x0)
         && (pcVar3 = dlerror(), pcVar3 == (char *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0013b0bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        wVar1 = (*sym_sensors_init)((FILE *)0x0,(long)pcVar2,a2,in_RCX,in_R8,in_R9);
        return wVar1;
      }
    }
    if (dlopenHandle != (void *)0x0) {
      dlclose(dlopenHandle);
      dlopenHandle = (void *)0x0;
    }
  }
  return L'\xffffffff';
}

