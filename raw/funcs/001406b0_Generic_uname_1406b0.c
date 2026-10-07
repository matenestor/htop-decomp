/* Generic_uname_1406b0 @ 001406b0 size 39 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * Generic_uname_1406b0(void)

{
  if (loaded_data_1_lto_priv_0 != '\0') {
    return &savedString_0_lto_priv_0;
  }
  Generic_uname();
  return &savedString_0_lto_priv_0;
}

