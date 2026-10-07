/* Generic_hostname @ 0013af00 size 37 */

void Generic_hostname(char *buffer,size_t size)

{
  gethostname(buffer,size - 1);
  buffer[size - 1] = '\0';
  return;
}

