/* CGroup_filterContainer_internal @ 00139c70 size 1173 */

/* WARNING: Type propagation algorithm not settling */

_Bool CGroup_filterContainer_internal(char *cgroup,StrBuf_state *s,StrBuf_putc_t w)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  _Bool _Var4;
  int iVar5;
  byte *__s1;
  byte *pbVar6;
  byte *pbVar7;
  ulong uVar8;
  long extraout_RDX;
  char *pcVar9;
  char *extraout_RDX_00;
  long extraout_RDX_01;
  long extraout_RDX_02;
  long extraout_RDX_03;
  long extraout_RDX_04;
  long lVar10;
  long extraout_RDX_05;
  char *extraout_RDX_06;
  long in_R8;
  long in_R9;
  byte *pbVar11;
  byte *pbVar12;
  ulong uVar13;

  uVar8 = (ulong)(byte)*cgroup;
  if (*cgroup == 0) {
    return true;
  }
  do {
                    /* Unresolved local var: char * labelStart@[???]
                       Unresolved local var: char * nextSlash@[???]
                       Unresolved local var: size_t labelLen@[???] */
    if ((char)uVar8 == '/') {
      if (*cgroup != 0x2f) {
        if (*cgroup == 0) {
          return true;
        }
        goto LAB_00139c9e;
      }
      do {
        pbVar7 = (byte *)(cgroup + 1);
        uVar8 = (ulong)*pbVar7;
        __s1 = (byte *)(cgroup + 1);
        cgroup = (char *)__s1;
      } while (*pbVar7 == 0x2f);
    }
    else {
LAB_00139c9e:
      __s1 = (byte *)strchrnul(cgroup,0x2f);
      uVar13 = (long)__s1 - (long)cgroup;
      if (uVar13 < 0xd) {
        bVar3 = *__s1;
        uVar8 = (ulong)bVar3;
        if (uVar13 == 0xb) {
          iVar5 = strncmp(cgroup,((char *)0x149830 /* "lxc.payload" */),0xb);
          uVar8 = (ulong)bVar3;
          pbVar7 = __s1;
          bVar2 = bVar3;
          if (iVar5 == 0) {
            while (bVar2 == 0x2f) {
              pbVar7 = pbVar7 + 1;
              bVar2 = *pbVar7;
            }
            pbVar11 = (byte *)strchrnul((char *)pbVar7,0x2f);
            if (0 < (long)pbVar11 - (long)pbVar7) {
              pcVar9 = ((char *)0x149886 /* "/lxc:" */);
              lVar10 = extraout_RDX_01;
              while (cVar1 = *pcVar9, pbVar6 = pbVar7, cVar1 != '\0') {
                pcVar9 = pcVar9 + 1;
                _Var4 = (*w)(s,cVar1,lVar10,uVar8,in_R8,in_R9);
                lVar10 = extraout_RDX_04;
                if (!_Var4) {
                  return false;
                }
              }
              do {
                pbVar12 = pbVar6 + 1;
                _Var4 = (*w)(s,*pbVar6,lVar10,uVar8,in_R8,in_R9);
                if (!_Var4) {
                  return false;
                }
                lVar10 = extraout_RDX_05;
                __s1 = pbVar11;
                pbVar6 = pbVar12;
              } while (pbVar7 + (((long)pbVar11 - (long)pbVar7) - (long)pbVar12) != (byte *)0x0);
              goto LAB_00139d0a;
            }
            uVar8 = (ulong)bVar3;
          }
        }
      }
      else {
        iVar5 = strncmp(cgroup,((char *)0x14980a /* "lxc.payload." */),0xc);
        if (iVar5 == 0) {
          pcVar9 = ((char *)0x149886 /* "/lxc:" */);
          lVar10 = extraout_RDX;
          while (cVar1 = *pcVar9, cVar1 != '\0') {
            pcVar9 = pcVar9 + 1;
            _Var4 = (*w)(s,cVar1,lVar10,uVar8,in_R8,in_R9);
            lVar10 = extraout_RDX_02;
            if (!_Var4) {
              return false;
            }
          }
          pbVar7 = (byte *)(cgroup + 0xc);
          do {
            pbVar11 = pbVar7 + 1;
            _Var4 = (*w)(s,*pbVar7,lVar10,uVar8,in_R8,in_R9);
            if (!_Var4) {
              return false;
            }
            lVar10 = extraout_RDX_03;
            pbVar7 = pbVar11;
          } while ((byte *)(cgroup + (uVar13 - (long)pbVar11)) != (byte *)0x0);
        }
        else {
          uVar8 = uVar13 - 6;
          pbVar7 = (byte *)(cgroup + uVar8);
          iVar5 = strncmp((char *)pbVar7,((char *)0x14984b /* ".scope" */),6);
          if (iVar5 == 0) {
                    /* Unresolved local var: size_t scopeNameLen@[???] */
            if (uVar8 < 9) {
              if (uVar8 != 8) goto LAB_00139d0a;
            }
            else {
              iVar5 = strncmp(cgroup,((char *)0x149852 /* "machine-" */),8);
              if (iVar5 == 0) {
                    /* Unresolved local var: size_t machineScopeNameLen@[???]
                       Unresolved local var: _Bool is_monitor@[???] */
                iVar5 = strncmp((char *)__s1,((char *)0x14985b /* "/supervisor" */),0xb);
                if (iVar5 != 0) {
                  pcVar9 = ((char *)0x14988c /* "/snc:" */);
                  while (cVar1 = *pcVar9, cVar1 != '\0') {
                    pcVar9 = pcVar9 + 1;
                    _Var4 = (*w)(s,cVar1,(long)pcVar9,uVar8,in_R8,in_R9);
                    if (!_Var4) {
                      return false;
                    }
                  }
                  pbVar7 = (byte *)(cgroup + 8);
                  do {
                    bVar3 = *pbVar7;
                    pbVar7 = pbVar7 + 1;
                    _Var4 = (*w)(s,bVar3,(long)pbVar7,uVar8,in_R8,in_R9);
                    if (!_Var4) {
                      return false;
                    }
                  } while ((byte *)(cgroup + uVar13 + (-6 - (long)pbVar7)) != (byte *)0x0);
                  iVar5 = strncmp((char *)__s1,((char *)0x14985b /* "/supervisor" */),0xb);
                  if (iVar5 != 0) {
                    iVar5 = strncmp((char *)__s1,((char *)0x149867 /* "/payload" */),8);
                    if (iVar5 == 0) {
                      uVar8 = (ulong)__s1[8];
                      __s1 = __s1 + 8;
                      goto LAB_00139d0d;
                    }
                    goto LAB_00139d0a;
                  }
                }
                uVar8 = (ulong)__s1[0xb];
                __s1 = __s1 + 0xb;
                goto LAB_00139d0d;
              }
            }
            iVar5 = strncmp(cgroup,((char *)0x149876 /* "libpod-" */),7);
            if (iVar5 == 0) {
                    /* Unresolved local var: char * nextDot@[???] */
              pbVar11 = (byte *)(cgroup + 7);
              pbVar6 = (byte *)strchrnul((char *)pbVar11,0x2e);
              pcVar9 = ((char *)0x149892 /* "/pod:" */);
              while (cVar1 = *pcVar9, cVar1 != '\0') {
                pcVar9 = pcVar9 + 1;
                _Var4 = (*w)(s,cVar1,(long)pcVar9,uVar8,in_R8,in_R9);
                if (!_Var4) {
                  return false;
                }
              }
              if (pbVar6 <= pbVar7) {
                pbVar7 = pbVar6;
              }
              pbVar7 = pbVar7 + -(long)pbVar11;
              pbVar6 = (byte *)0xc;
              pbVar12 = (byte *)0xc;
              if ((long)pbVar7 < 0xd) {
                pbVar6 = pbVar7;
                pbVar12 = pbVar7;
              }
              while (pbVar6 != (byte *)0x0) {
                pbVar6 = pbVar11 + 1;
                _Var4 = (*w)(s,*pbVar11,(long)pcVar9,(long)pbVar7,in_R8,in_R9);
                if (!_Var4) {
                  return false;
                }
                pbVar11 = pbVar6;
                pcVar9 = extraout_RDX_06;
                pbVar6 = (byte *)(cgroup + (long)(pbVar12 + (7 - (long)pbVar6)));
              }
            }
            else {
              iVar5 = strncmp(cgroup,((char *)0x14987e /* "docker-" */),7);
              if (iVar5 == 0) {
                    /* Unresolved local var: char * nextDot@[???] */
                pbVar11 = (byte *)(cgroup + 7);
                pbVar6 = (byte *)strchrnul((char *)pbVar11,0x2e);
                pcVar9 = ((char *)0x1497cb /* "!docker:" */);
                while (cVar1 = *pcVar9, cVar1 != '\0') {
                  pcVar9 = pcVar9 + 1;
                  _Var4 = (*w)(s,cVar1,(long)pcVar9,uVar8,in_R8,in_R9);
                  if (!_Var4) {
                    return false;
                  }
                }
                if (pbVar6 <= pbVar7) {
                  pbVar7 = pbVar6;
                }
                pbVar7 = pbVar7 + -(long)pbVar11;
                pbVar6 = (byte *)0xc;
                pbVar12 = (byte *)0xc;
                if ((long)pbVar7 < 0xd) {
                  pbVar6 = pbVar7;
                  pbVar12 = pbVar7;
                }
                while (pbVar6 != (byte *)0x0) {
                  pbVar6 = pbVar11 + 1;
                  _Var4 = (*w)(s,*pbVar11,(long)pcVar9,(long)pbVar7,in_R8,in_R9);
                  if (!_Var4) {
                    return false;
                  }
                  pbVar11 = pbVar6;
                  pcVar9 = extraout_RDX_00;
                  pbVar6 = (byte *)(cgroup + (long)(pbVar12 + (7 - (long)pbVar6)));
                }
              }
            }
          }
        }
LAB_00139d0a:
        uVar8 = (ulong)*__s1;
      }
    }
LAB_00139d0d:
    cgroup = (char *)__s1;
    if ((char)uVar8 == '\0') {
      return true;
    }
  } while( true );
}

