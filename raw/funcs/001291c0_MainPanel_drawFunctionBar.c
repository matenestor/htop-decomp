/* MainPanel_drawFunctionBar @ 001291c0 size 96 */

void MainPanel_drawFunctionBar(MainPanel_ *super,_Bool hideFunctionBar)

{
  if ((!hideFunctionBar) || (((IncSet *)super->inc)->active != (IncMode *)0x0)) {
    IncSet_drawBar((IncSet *)super->inc,CRT_colors[2]);
    if (super->state->pauseUpdate != false) {
                    /* Unresolved local var: MainPanel * this@[???] */
      FunctionBar_append(((char *)0x148882 /* "PAUSED" */),CRT_colors[6]);
      return;
    }
  }
  return;
}

