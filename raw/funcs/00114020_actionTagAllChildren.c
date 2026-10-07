/* actionTagAllChildren @ 00114020 size 51 */

Htop_Reaction actionTagAllChildren(State_2 *st)

{
  MainPanel__2 *panel;
  Vector *pVVar1;
  Row *parent;

  panel = st->mainPanel;
  pVVar1 = (panel->super).items;
  if ((L'\0' < pVVar1->items) &&
     (parent = (Row *)pVVar1->array[(panel->super).selected], parent != (Row *)0x0)) {
    tagAllChildren(&panel->super,parent);
    return HTOP_OK;
  }
  return HTOP_OK;
}

