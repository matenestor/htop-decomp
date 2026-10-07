#include "htop.h"

/* Generic_hostname @ 0x13af00 */

void Generic_hostname(char *buffer,size_t size)

{
  gethostname(buffer,size - 1);
  buffer[size - 1] = '\0';
  return;
}

