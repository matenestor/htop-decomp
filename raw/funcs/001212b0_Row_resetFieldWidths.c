/* Row_resetFieldWidths @ 001212b0 size 90 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Row_resetFieldWidths(void)

{
  size_t sVar1;
  char **ppcVar2;
  uint8_t *puVar3;

                    /* Unresolved local var: size_t i@[???] */
  puVar3 = Row_fieldWidths;
  ppcVar2 = &Process_fields[0].title;
  do {
                    /* Unresolved local var: size_t len@[???] */
    if (*(_Bool *)((long)ppcVar2 + 0x16) != false) {
      sVar1 = strlen(*ppcVar2);
      *puVar3 = (uint8_t)sVar1;
    }
    ppcVar2 = ppcVar2 + 4;
    puVar3 = puVar3 + 1;
  } while (ppcVar2 != MetersMovingKeys + 1);
  return;
}

