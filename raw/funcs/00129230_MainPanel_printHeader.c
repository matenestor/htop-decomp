/* MainPanel_printHeader @ 00129230 size 26 */

void MainPanel_printHeader(MainPanel_ *super)

{
  Table_printHeader(super->state->host->settings,&(super->super).header);
  return;
}

