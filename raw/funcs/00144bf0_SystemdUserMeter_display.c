/* SystemdUserMeter_display @ 00144bf0 size 19 */

void SystemdUserMeter_display(Object *cast,RichString *out)

{
  SystemdMeterContext_t *in_RDX;

  _SystemdMeter_display((Object *)out,(RichString *)&ctx_user,in_RDX);
  return;
}

