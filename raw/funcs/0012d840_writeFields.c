/* writeFields @ 0012d840 size 360 */

void writeFields(FILE *fd,ProcessField *fields,Hashtable_2 *columns,_Bool byName,char separator)

{
  ht_key_t hVar1;
  HashtableItem *pHVar2;
  ulong uVar3;
  HashtableItem *pHVar4;
  ulong uVar5;
  undefined *va0;
  ulong uVar6;
  void *va1;
  char *va1_00;

                    /* Unresolved local var: char * sep@[???]
                       Unresolved local var: uint i@[???] */
  hVar1 = *fields;
  if (hVar1 != 0) {
    uVar3 = 0;
    va0 = &DAT_00149c0c;
    do {
      if ((int)hVar1 < 0x84) {
        if (byName) {
                    /* Unresolved local var: char * pName@[???] */
          if ((int)hVar1 < 0) {
            va1_00 = (char *)0x0;
          }
          else {
            va1_00 = Process_fields[(int)hVar1].name;
          }
          __fprintf_chk(fd,2,((char *)0x147643 /* "%s%s" */),va0,va1_00);
        }
        else {
LAB_0012d891:
          __fprintf_chk(fd,2,((char *)0x148c18 /* "%s%d" */),va0,hVar1 - 1);
        }
      }
      else {
        if (!byName) goto LAB_0012d891;
                    /* Unresolved local var: _Bool enabled@[???]
                       Unresolved local var: char * pName@[???]
                       Unresolved local var: DynamicColumn * column@[???]
                       Unresolved local var: size_t index@[???]
                       Unresolved local var: size_t probe@[???]
                       Unresolved local var: void * res@[???] */
        pHVar2 = columns->buckets;
        uVar5 = (ulong)(long)(int)hVar1 % columns->size;
        pHVar4 = pHVar2 + uVar5;
        va1 = pHVar4->value;
        if (va1 != (void *)0x0) {
          uVar6 = 0;
          do {
            if (hVar1 == pHVar4->key) {
              if (*(char *)((long)va1 + 0x3c) != '\0') {
                __fprintf_chk(fd,2,((char *)0x148c0a /* "%sDynamic(%s)" */),va0,va1);
              }
              break;
            }
            if (pHVar4->probe < uVar6) break;
            uVar5 = uVar5 + 1;
            if (columns->size == uVar5) {
              uVar5 = 0;
              pHVar4 = pHVar2;
            }
            else {
              pHVar4 = pHVar2 + uVar5;
            }
            va1 = pHVar4->value;
            uVar6 = uVar6 + 1;
          } while (va1 != (void *)0x0);
        }
      }
      uVar3 = (ulong)((int)uVar3 + 1);
      va0 = &DAT_001470dd;
      hVar1 = fields[uVar3];
    } while (hVar1 != 0);
  }
  fputc((int)separator,(FILE_2 *)fd);
  return;
}

