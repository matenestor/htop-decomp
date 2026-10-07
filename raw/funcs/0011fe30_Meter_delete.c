/* Meter_delete @ 0011fe30 size 79 */

void Meter_delete(Meter_ *cast)

{
  Object_Display p_Var1;
  long in_RCX;
  long in_RDX;
  RichString *in_RSI;
  long in_R8;
  long in_R9;

  if (cast != (Meter_ *)0x0) {
    p_Var1 = (cast->super).klass[1].display;
    if (p_Var1 != (Object_Display)0x0) {
      (*p_Var1)(&cast->super,in_RSI,in_RDX,in_RCX,in_R8,in_R9);
    }
    free((cast->drawData).values);
    free(cast->caption);
    free(cast->values);
    free(cast);
    return;
  }
  return;
}

