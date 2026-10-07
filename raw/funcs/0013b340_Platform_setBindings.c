/* Platform_setBindings @ 0013b340 size 68 */

void Platform_setBindings(Htop_Action_2 *keys)

{
  keys[0x69] = Platform_actionSetIOPriority;
  keys[0x7b] = Platform_actionLowerAutogroupPriority;
  keys[0x7d] = Platform_actionHigherAutogroupPriority;
  keys[0x11b] = Platform_actionLowerAutogroupPriority;
  keys[0x11c] = Platform_actionHigherAutogroupPriority;
  return;
}

