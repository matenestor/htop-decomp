/* Platform_getBattery @ 0013d1a0 size 345 */

void Platform_getBattery(double *percent,ACPresence *isOnAC)

{
  ACPresence AVar1;
  time_t tVar2;
  double dVar3;

  tVar2 = time((time_t *)0x0);
  AVar1 = Platform_Battery_cacheIsOnAC;
  if (tVar2 <= Platform_Battery_cacheTime + 9) {
    *percent = Platform_Battery_cachePercent;
    *isOnAC = AVar1;
    return;
  }
  if (Platform_Battery_method == CPU_METER_NICE) {
    AVar1 = procAcpiCheck();
    *isOnAC = AVar1;
    if (AVar1 == AC_ERROR) {
      *percent = NAN;
    }
    else {
      dVar3 = Platform_Battery_getProcBatInfo();
      *percent = dVar3;
      if (0.0 <= dVar3) goto LAB_0013d1df;
    }
    Platform_Battery_method = CPU_METER_NORMAL;
LAB_0013d23e:
    Platform_Battery_getSysData(percent,isOnAC);
    if (*percent < 0.0) {
      Platform_Battery_method = CPU_METER_KERNEL;
      goto LAB_0013d267;
    }
  }
  else {
LAB_0013d1df:
    if (Platform_Battery_method == CPU_METER_NORMAL) goto LAB_0013d23e;
  }
  if (Platform_Battery_method != CPU_METER_KERNEL) {
    Platform_Battery_cachePercent = *percent;
    if (Platform_Battery_cachePercent <= 100.0) {
      if (Platform_Battery_cachePercent <= 0.0) {
        Platform_Battery_cachePercent = 0.0;
      }
      Platform_Battery_cacheIsOnAC = *isOnAC;
      *percent = Platform_Battery_cachePercent;
      Platform_Battery_cacheTime = tVar2;
      return;
    }
    Platform_Battery_cacheIsOnAC = *isOnAC;
    *percent = 100.0;
    Platform_Battery_cachePercent = 100.0;
    Platform_Battery_cacheTime = tVar2;
    return;
  }
LAB_0013d267:
  *percent = NAN;
  *isOnAC = AC_ERROR;
  Platform_Battery_cacheTime = tVar2;
  Platform_Battery_cacheIsOnAC = AC_ERROR;
  Platform_Battery_cachePercent = NAN;
  return;
}

