/* Settings_readMeters @ 001357b0 size 116 */

/* DWARF original prototype: void Settings_readMeters(Settings * this, char * line, uint column) */

void Settings_readMeters(Settings *this,char *line,uint column)

{
  char *s;
  char **ppcVar1;
  ulong uVar2;

                    /* Unresolved local var: char * trim@[???]
                       Unresolved local var: char * * ids@[???] */
  s = String_trim(line);
  ppcVar1 = String_split(s,' ',(size_t *)0x0);
  free(s);
  uVar2 = (ulong)column;
  if ((ulong)HeaderLayout_layouts[this->hLayout].columns - 1 <= uVar2) {
    uVar2 = (ulong)(HeaderLayout_layouts[this->hLayout].columns - 1);
  }
  this->hColumns[uVar2].names = ppcVar1;
  return;
}

