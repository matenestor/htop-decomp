#include "htop.h"

/* stands in for %fs: so the stack-protector reads in decompiled code work */
long __fake_fs[16];
