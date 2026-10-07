#include "htop.h"

/* String_freeArray @ 0x12e100 */

void String_freeArray(char **s)

{
  char *__ptr;
  char **ppcVar1;

  if (s != (char **)0x0) {
                    /* Unresolved local var: size_t i@[???] */
    __ptr = *s;
    ppcVar1 = s;
    while (__ptr != (char *)0x0) {
      ppcVar1 = ppcVar1 + 1;
      free(__ptr);
      __ptr = *ppcVar1;
    }
    free(s);
    return;
  }
  return;
}


/* fail @ 0x1300c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void fail(void)

{
  CRT_done();
                    /* WARNING: Subroutine does not return */
  abort();
}


/* xRealloc @ 0x1300e0 */

void * xRealloc(void *ptr,size_t size)

{
  void *pvVar1;

  pvVar1 = realloc(ptr,size);
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
  free(ptr);
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xMalloc @ 0x130110 */

void * xMalloc(size_t size)

{
  void *pvVar1;

  pvVar1 = malloc(size);
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xCalloc @ 0x132160 */

void * xCalloc(size_t nmemb,size_t size)

{
  undefined16 auVar1;
  undefined16 auVar2;
  void *pvVar3;

  (*(ulong *)((char *)&auVar1 + 8)) = 0;
  (*(ulong *)((char *)&auVar1 + 0)) = size;
  (*(ulong *)((char *)&auVar2 + 8)) = 0;
  (*(ulong *)((char *)&auVar2 + 0)) = nmemb;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    pvVar3 = calloc(nmemb,size);
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xReallocArray @ 0x1328c0 */

void * xReallocArray(void *ptr,size_t nmemb,size_t size)

{
  undefined16 auVar1;
  undefined16 auVar2;
  void *pvVar3;

  (*(ulong *)((char *)&auVar1 + 8)) = 0;
  (*(ulong *)((char *)&auVar1 + 0)) = size;
  (*(ulong *)((char *)&auVar2 + 8)) = 0;
  (*(ulong *)((char *)&auVar2 + 0)) = nmemb;
  if (SUB168(auVar1 * auVar2,8) == 0) {
                    /* Unresolved local var: void * data@[???] */
    pvVar3 = realloc(ptr,SUB168(auVar1 * auVar2,0));
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
    free(ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xMallocArray @ 0x132e10 */

void * xMallocArray(size_t nmemb,size_t size)

{
  undefined16 auVar1;
  undefined16 auVar2;
  void *pvVar3;

  (*(ulong *)((char *)&auVar1 + 8)) = 0;
  (*(ulong *)((char *)&auVar1 + 0)) = size;
  (*(ulong *)((char *)&auVar2 + 8)) = 0;
  (*(ulong *)((char *)&auVar2 + 0)) = nmemb;
  if (SUB168(auVar1 * auVar2,8) == 0) {
                    /* Unresolved local var: void * data@[???] */
    pvVar3 = malloc(SUB168(auVar1 * auVar2,0));
    if (pvVar3 != (void *)0x0) {
      return pvVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xReallocArrayZero @ 0x132e40 */

void * xReallocArrayZero(void *ptr,size_t prevmemb,size_t newmemb,size_t size)

{
  undefined16 auVar1;
  undefined16 auVar2;
  size_t __size;
  void *pvVar3;
  ulong uVar4;

  if (prevmemb == newmemb) {
    return ptr;
  }
  (*(ulong *)((char *)&auVar1 + 8)) = 0;
  (*(ulong *)((char *)&auVar1 + 0)) = newmemb;
                    /* Unresolved local var: void * ret@[???] */
  (*(ulong *)((char *)&auVar2 + 8)) = 0;
  (*(ulong *)((char *)&auVar2 + 0)) = size;
  __size = SUB168(auVar1 * auVar2,0);
  if (SUB168(auVar1 * auVar2,8) == 0) {
                    /* Unresolved local var: void * data@[???] */
    pvVar3 = realloc(ptr,__size);
    if (pvVar3 != (void *)0x0) {
      if (newmemb <= prevmemb) {
        return pvVar3;
      }
      uVar4 = prevmemb * size;
      if (__size <= uVar4) {
        __size = uVar4;
      }
      __memset_chk((void *)(uVar4 + (long)pvVar3),0,(newmemb - prevmemb) * size,__size - uVar4);
      return pvVar3;
    }
    free(ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* String_cat @ 0x135560 */

char * String_cat(char *s1,char *s2)

{
  size_t p2;
  size_t p2_00;
  char *p0;
  size_t __size;

  p2 = strlen(s1);
  p2_00 = strlen(s2);
  __size = p2 + p2_00 + 1;
                    /* Unresolved local var: void * data@[???] */
  p0 = malloc(__size);
  if (p0 != (char *)0x0) {
    __memcpy_chk(p0,s1,p2,__size);
    if (__size < p2) {
      __size = p2;
    }
    __memcpy_chk(p0 + p2,s2,p2_00,__size - p2);
    p0[p2 + p2_00] = '\0';
    return p0;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* String_trim @ 0x135600 */

char * String_trim(char *in)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  size_t __n;

  cVar1 = *in;
  if (1 < (byte)(cVar1 - 9U)) goto LAB_00135630;
  do {
    do {
      cVar1 = in[1];
      in = in + 1;
    } while ((byte)(cVar1 - 9U) < 2);
LAB_00135630:
  } while (cVar1 == ' ');
  sVar2 = strlen(in);
  do {
    while( true ) {
      __n = sVar2;
      if (__n == 0) goto LAB_00135665;
      cVar1 = in[__n - 1];
      sVar2 = __n - 1;
      if (cVar1 < '\v') break;
      if (cVar1 != ' ') goto LAB_00135665;
    }
  } while ('\b' < cVar1);
LAB_00135665:
                    /* Unresolved local var: char * data@[???] */
  pcVar3 = strndup(in,__n);
  if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    fail();
  }
  return pcVar3;
}


/* String_split @ 0x135680 */

char ** String_split(char *s,char sep,size_t *n)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  void *__ptr;
  char *pcVar1;
  char *pcVar2;
  void *pvVar3;
  char **ppcVar4;
  size_t sVar5;

                    /* Unresolved local var: void * data@[???] */
  __ptr = calloc(10,8);
  if (__ptr != (void *)0x0) {
    (*(size_t (*))(__fp - 0x40)) = 10;
    sVar5 = 0;
    while (pcVar1 = strchr(s,(int)sep), pcVar1 != (char *)0x0) {
                    /* Unresolved local var: char * data@[???] */
      pcVar2 = strndup(s,(long)pcVar1 - (long)s);
      if (pcVar2 == (char *)0x0) goto LAB_001357a3;
      *(char **)((long)__ptr + sVar5 * 8) = pcVar2;
      sVar5 = sVar5 + 1;
      pvVar3 = __ptr;
      if ((*(size_t (*))(__fp - 0x40)) == sVar5) {
        (*(size_t (*))(__fp - 0x40)) = (*(size_t (*))(__fp - 0x40)) + 10;
                    /* Unresolved local var: void * data@[???] */
        pvVar3 = realloc(__ptr,(*(size_t (*))(__fp - 0x40)) * 8);
        if (pvVar3 == (void *)0x0) goto LAB_0013579b;
      }
                    /* Unresolved local var: size_t size@[???] */
      s = s + ((long)pcVar1 - (long)s) + 1;
      __ptr = pvVar3;
    }
    if (*s != '\0') {
                    /* Unresolved local var: char * data@[???] */
      pcVar1 = strdup(s);
      if (pcVar1 == (char *)0x0) goto LAB_001357a3;
      *(char **)((long)__ptr + sVar5 * 8) = pcVar1;
      sVar5 = sVar5 + 1;
    }
                    /* Unresolved local var: void * data@[???] */
    ppcVar4 = realloc(__ptr,sVar5 * 8 + 8);
    if (ppcVar4 != (char **)0x0) {
      ppcVar4[sVar5] = (char *)0x0;
      if (n != (size_t *)0x0) {
        *n = sVar5;
      }
      return ppcVar4;
    }
LAB_0013579b:
    free(__ptr);
  }
LAB_001357a3:
                    /* WARNING: Subroutine does not return */
  fail();
}


/* String_contains_i @ 0x1371c0 */

_Bool String_contains_i(char *s1,char *s2,_Bool multi)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  char *pcVar1;
  char **__ptr;
  size_t sVar2;
  char **ppcVar3;
  long in_FS_OFFSET = (long)__fake_fs;
  _Bool _Var4;

  (*(long (*))(__fp - 0x40)) = *(long *)(in_FS_OFFSET + 0x28);
  if ((!multi) || (pcVar1 = strchr(s2,0x7c), pcVar1 == (char *)0x0)) {
    pcVar1 = strcasestr(s1,s2);
    _Var4 = pcVar1 != (char *)0x0;
    goto LAB_00137291;
  }
                    /* Unresolved local var: char * * needles@[???] */
  __ptr = String_split(s2,'|',&(*(size_t (*))(__fp - 0x48)));
                    /* Unresolved local var: size_t i@[???] */
  if ((*(size_t (*))(__fp - 0x48)) == 0) {
    if (__ptr != (char **)0x0) goto LAB_001372b8;
  }
  else {
    sVar2 = 0;
    do {
      pcVar1 = strcasestr(s1,__ptr[sVar2]);
      if (pcVar1 != (char *)0x0) {
                    /* Unresolved local var: size_t i@[???] */
        pcVar1 = *__ptr;
        ppcVar3 = __ptr;
        while (pcVar1 != (char *)0x0) {
          ppcVar3 = ppcVar3 + 1;
          free(pcVar1);
          pcVar1 = *ppcVar3;
        }
        free(__ptr);
        _Var4 = true;
        goto LAB_00137291;
      }
      sVar2 = sVar2 + 1;
    } while (sVar2 != (*(size_t (*))(__fp - 0x48)));
LAB_001372b8:
                    /* Unresolved local var: size_t i@[???] */
    pcVar1 = *__ptr;
    ppcVar3 = __ptr;
    while (pcVar1 != (char *)0x0) {
      ppcVar3 = ppcVar3 + 1;
      free(pcVar1);
      pcVar1 = *ppcVar3;
    }
    free(__ptr);
  }
  _Var4 = false;
LAB_00137291:
  if ((*(long (*))(__fp - 0x40)) == *(long *)(in_FS_OFFSET + 0x28)) {
    return _Var4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* String_readLine @ 0x1372f0 */

char * String_readLine(FILE *fd)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  ulong uVar4;
  ulong uVar5;
  char *__ptr;

                    /* Unresolved local var: void * data@[???] */
  pcVar2 = malloc(0x401);
  if (pcVar2 != (char *)0x0) {
    uVar4 = 0x401;
    uVar5 = 0x400;
    __ptr = pcVar2;
    while( true ) {
                    /* Unresolved local var: size_t sz@[???] */
      pcVar3 = __fgets_chk(pcVar2,uVar4,0x401,fd);
      if (pcVar3 == (char *)0x0) {
        free(__ptr);
        return (char *)0x0;
      }
                    /* Unresolved local var: char * ok@[???]
                       Unresolved local var: char * newLine@[???] */
      pcVar2 = strrchr(pcVar2,10);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
        return __ptr;
      }
      iVar1 = feof((FILE_2 *)fd);
      if (iVar1 != 0) {
        return __ptr;
      }
      uVar4 = uVar5 + 0x401;
                    /* Unresolved local var: void * data@[???] */
      pcVar3 = realloc(__ptr,uVar4);
      if (pcVar3 == (char *)0x0) break;
      pcVar2 = pcVar3 + uVar5;
      if (uVar4 < uVar5) {
        uVar4 = uVar5;
      }
      uVar4 = uVar4 - uVar5;
      uVar5 = uVar5 + 0x400;
      __ptr = pcVar3;
    }
    free(__ptr);
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* String_safeStrncpy @ 0x13a410 */

size_t String_safeStrncpy(char *dest,char *src,size_t size)

{
  size_t sVar1;

  sVar1 = 0;
  if (size != 1) {
    do {
      if (src[sVar1] == '\0') break;
      dest[sVar1] = src[sVar1];
      sVar1 = sVar1 + 1;
    } while (sVar1 != size - 1);
    dest = dest + sVar1;
  }
  *dest = '\0';
  return sVar1;
}


/* readfd_internal @ 0x13a450 */

ssize_t readfd_internal(int fd,void *buffer,size_t count)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  long lVar1;
  int *piVar2;
  ulong uVar3;
  ulong uVar4;
  size_t p3;
  ulong p2;

  if (count == 0) {
    close(fd);
    (*(long (*))(__fp - 0x40)) = -0x16;
  }
  else {
    p2 = count - 1;
    (*(long (*))(__fp - 0x40)) = 0;
    p3 = count;
    do {
                    /* Unresolved local var: ssize_t res@[???] */
      while (lVar1 = __read_chk(fd,buffer,p2,p3), lVar1 != -1) {
        if (0 < lVar1) {
          uVar3 = p3;
          if (p3 <= count) {
            uVar3 = count;
          }
          uVar4 = (lVar1 + uVar3) - p3;
          if (uVar4 < uVar3) {
            uVar4 = uVar3;
          }
          (*(long (*))(__fp - 0x40)) = (*(long (*))(__fp - 0x40)) + lVar1;
          buffer = (void *)((long)buffer + lVar1);
          p2 = p2 - lVar1;
          p3 = (p3 - (lVar1 + uVar3)) + uVar4;
        }
        if ((p2 == 0) || (lVar1 == 0)) {
          close(fd);
          *(undefined1 *)buffer = 0;
          return (*(long (*))(__fp - 0x40));
        }
      }
      piVar2 = __errno_location();
    } while (*piVar2 == 4);
    close(fd);
    *(undefined1 *)buffer = 0;
    (*(long (*))(__fp - 0x40)) = (long)-*piVar2;
  }
  return (*(long (*))(__fp - 0x40));
}


/* xReadfile @ 0x13ac50 */

ssize_t xReadfile(char *pathname,void *buffer,size_t count)

{
  int fd;
  ssize_t sVar1;
  int *piVar2;

  fd = open(pathname,0);
  if (-1 < fd) {
    sVar1 = readfd_internal(fd,buffer,count);
    return sVar1;
  }
                    /* Unresolved local var: int fd@[???] */
  piVar2 = __errno_location();
  return (long)-*piVar2;
}


/* xReadfileat @ 0x13ac90 */

ssize_t xReadfileat(openat_arg_t dirfd,char *pathname,void *buffer,size_t count)

{
  int fd;
  ssize_t sVar1;
  int *piVar2;

  fd = openat(dirfd,pathname,0);
  if (-1 < fd) {
    sVar1 = readfd_internal(fd,buffer,count);
    return sVar1;
  }
                    /* Unresolved local var: int fd@[???] */
  piVar2 = __errno_location();
  return (long)-*piVar2;
}


/* full_write @ 0x13acd0 */

ssize_t full_write(int fd,void *buf,size_t count)

{
  ssize_t sVar1;
  int *piVar2;
  ssize_t sVar3;

  if (count == 0) {
    sVar3 = 0;
  }
  else {
    sVar3 = 0;
    do {
      while( true ) {
                    /* Unresolved local var: ssize_t r@[???] */
        sVar1 = write(fd,buf,count);
        if (-1 < sVar1) break;
        piVar2 = __errno_location();
        if (*piVar2 != 4) {
          return sVar1;
        }
      }
      if (sVar1 == 0) {
        return sVar3;
      }
      sVar3 = sVar3 + sVar1;
      buf = (void *)((long)buf + sVar1);
      count = count - sVar1;
    } while (count != 0);
  }
  return sVar3;
}


/* compareRealNumbers @ 0x13ad50 */

int compareRealNumbers(double a,double b)

{
  int wVar1;

  wVar1 = (uint)(b < a) - (uint)(a < b);
  if (wVar1 == 0) {
    wVar1 = (uint)!NAN(a) - (uint)!NAN(b);
  }
  return wVar1;
}


/* sumPositiveValues @ 0x13ad80 */

double sumPositiveValues(double *array,size_t count)

{
  double *pdVar1;
  double dVar2;

                    /* Unresolved local var: size_t i@[???] */
  if (count != 0) {
    dVar2 = 0.0;
    pdVar1 = array + count;
    do {
      if (0.0 < *array) {
        dVar2 = dVar2 + *array;
      }
      array = array + 1;
    } while (array != pdVar1);
    return dVar2;
  }
  return 0.0;
}


/* xAsprintf @ 0x13cb00 */
int xAsprintf(char **strp,char *fmt,...)

{
  __builtin_va_list ap;
  int n;

  __builtin_va_start(ap,fmt);
  n = vasprintf(strp,fmt,ap);
  __builtin_va_end(ap);
  if ((n < 0) || (*strp == (char *)0x0)) {
    fail();
  }
  return n;
}

/* xSnprintf @ 0x13cbe0 */
int xSnprintf(char *buf,ulong len,char *fmt,...)

{
  __builtin_va_list ap;
  int n;

  __builtin_va_start(ap,fmt);
  n = vsnprintf(buf,len,fmt,ap);
  __builtin_va_end(ap);
  if ((n < 0) || ((ulong)(long)n >= len)) {
    fail();
  }
  return n;
}

/* xStrdup @ 0x13e040 */

char * xStrdup(char *str)

{
  char *pcVar1;

  pcVar1 = strdup(str);
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* free_and_xStrdup @ 0x13e060 */

void free_and_xStrdup(char **ptr,char *str)

{
  int iVar1;
  char *pcVar2;

  pcVar2 = *ptr;
  if ((pcVar2 != (char *)0x0) && (iVar1 = strcmp(pcVar2,str), iVar1 == 0)) {
    return;
  }
  free(pcVar2);
                    /* Unresolved local var: char * data@[???] */
  pcVar2 = strdup(str);
  if (pcVar2 != (char *)0x0) {
    *ptr = pcVar2;
    return;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}


/* xStrndup @ 0x13e0c0 */

char * xStrndup(char *str,size_t len)

{
  char *pcVar1;

  pcVar1 = strndup(str,len);
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

