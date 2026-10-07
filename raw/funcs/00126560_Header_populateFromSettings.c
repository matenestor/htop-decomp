/* Header_populateFromSettings @ 00126560 size 848 */

/* DWARF original prototype: void Header_populateFromSettings(Header * this) */

void Header_populateFromSettings(Header *this)

{
  MeterColumnSetting *pMVar1;
  HashtableItem *pHVar2;
  byte bVar3;
  wchar_t modeIndex;
  long lVar4;
  Settings__5 *pSVar5;
  char *__s;
  Vector *this_00;
  Hashtable_2 *pHVar6;
  bool bVar7;
  int iVar8;
  char *pcVar9;
  Meter_3 *this_01;
  char *pcVar10;
  size_t __n;
  ht_key_t hVar11;
  MeterClass **ppMVar12;
  ulong uVar13;
  HashtableItem *pHVar14;
  MeterClass_3 *type;
  long in_FS_OFFSET;
  ulong local_80;
  uint param;
  char dynamic [32];

  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  pSVar5 = this->host->settings;
  Header_setLayout(this,pSVar5->hLayout);
                    /* Unresolved local var: size_t col@[???]
                       Unresolved local var: size_t H_fEC_numColumns_@[???] */
  bVar3 = HeaderLayout_layouts[this->headerLayout].columns;
  if ((ulong)bVar3 != 0) {
    uVar13 = 0;
    do {
                    /* Unresolved local var: MeterColumnSetting * colSettings@[???] */
      pMVar1 = pSVar5->hColumns + uVar13;
      Vector_prune(this->columns[uVar13]);
                    /* Unresolved local var: size_t i@[???] */
                    /* Unresolved local var: Vector * meters@[???]
                       Unresolved local var: char * paren@[???]
                       Unresolved local var: size_t nameLen@[???]
                       Unresolved local var: wchar_t ok@[???] */
      if (pMVar1->len != 0) {
        local_80 = 0;
        do {
          modeIndex = pMVar1->modes[local_80];
          __s = pMVar1->names[local_80];
          this_00 = this->columns[uVar13];
          pcVar9 = strchr(__s,0x28);
          param = 0;
          if (pcVar9 == (char *)0x0) {
            __n = strlen(__s);
LAB_001266af:
                    /* Unresolved local var: MeterClass * * type@[???] */
            ppMVar12 = Platform_meterTypes;
            type = &CPUMeter_class;
                    /* Unresolved local var: char * end@[???]
                       Unresolved local var: Settings * settings@[???]
                       Unresolved local var: DynamicIterator.conflict1 iter@[???]
                       Unresolved local var: size_t i@[???]
                       Unresolved local var: HashtableItem * walk@[???]
                       Unresolved local var: DynamicMeter * meter@[???]
                       Unresolved local var: DynamicIterator.conflict1 * iter@[???] */
            pcVar9 = ((char *)0x147826 /* "CPU" */);
            while ((iVar8 = strncmp(__s,pcVar9,__n), iVar8 != 0 || (pcVar9[__n] != '\0'))) {
              type = (MeterClass_3 *)ppMVar12[1];
              ppMVar12 = ppMVar12 + 1;
              if (type == (MeterClass_3 *)0x0) goto LAB_001266fe;
              pcVar9 = ((MeterClass *)type)->name;
            }
                    /* Unresolved local var: Meter * meter@[???] */
            this_01 = Meter_new((Machine_2 *)this->host,param,type);
            if (modeIndex != L'\0') {
              Meter_setMode((Meter *)this_01,modeIndex);
            }
                    /* Unresolved local var: Object * data@[???]
                       Unresolved local var: wchar_t i@[???] */
            Vector_set(this_00,this_00->items,this_01);
          }
          else {
            iVar8 = __isoc23_sscanf(pcVar9,((char *)0x148819 /* "(%10u)" */),&param);
            if (iVar8 != 0) {
LAB_001266a9:
              __n = (long)pcVar9 - (long)__s;
              goto LAB_001266af;
            }
            dynamic[0] = '\0';
            dynamic[1] = '\0';
            dynamic[2] = '\0';
            dynamic[3] = '\0';
            dynamic[4] = '\0';
            dynamic[5] = '\0';
            dynamic[6] = '\0';
            dynamic[7] = '\0';
            dynamic[8] = '\0';
            dynamic[9] = '\0';
            dynamic[10] = '\0';
            dynamic[0xb] = '\0';
            dynamic[0xc] = '\0';
            dynamic[0xd] = '\0';
            dynamic[0xe] = '\0';
            dynamic[0xf] = '\0';
            dynamic[0x10] = '\0';
            dynamic[0x11] = '\0';
            dynamic[0x12] = '\0';
            dynamic[0x13] = '\0';
            dynamic[0x14] = '\0';
            dynamic[0x15] = '\0';
            dynamic[0x16] = '\0';
            dynamic[0x17] = '\0';
            dynamic[0x18] = '\0';
            dynamic[0x19] = '\0';
            dynamic[0x1a] = '\0';
            dynamic[0x1b] = '\0';
            dynamic[0x1c] = '\0';
            dynamic[0x1d] = '\0';
            dynamic[0x1e] = '\0';
            dynamic[0x1f] = '\0';
            iVar8 = __isoc23_sscanf(pcVar9,((char *)0x148c03 /* "(%30s)" */),dynamic);
            if (iVar8 == 0) {
              param = 0;
              goto LAB_001266a9;
            }
            pcVar10 = strrchr(dynamic,0x29);
            if (pcVar10 != (char *)0x0) {
              *pcVar10 = '\0';
              pHVar6 = this->host->settings->dynamicMeters;
              if ((pHVar6 != (Hashtable_2 *)0x0) && (pHVar6->size != 0)) {
                pHVar14 = pHVar6->buckets;
                hVar11 = 0;
                pHVar2 = pHVar14 + pHVar6->size;
                bVar7 = false;
                do {
                  if ((pHVar14->value != (char *)0x0) &&
                     (iVar8 = strcmp(dynamic,pHVar14->value), iVar8 == 0)) {
                    hVar11 = pHVar14->key;
                    bVar7 = true;
                  }
                  pHVar14 = pHVar14 + 1;
                } while (pHVar2 != pHVar14);
                param = hVar11;
                if (bVar7) goto LAB_001266a9;
              }
            }
          }
LAB_001266fe:
          local_80 = local_80 + 1;
        } while (local_80 < pMVar1->len);
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 != bVar3);
  }
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  Header_calculateHeight(this);
  return;
}

