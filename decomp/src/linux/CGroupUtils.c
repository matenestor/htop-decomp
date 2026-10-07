#include "htop.h"

/* StrBuf_putc_count @ 0x1388e0 */

_Bool StrBuf_putc_count(StrBuf_state *p,char c)

{
  p->pos = p->pos + 1;
  return true;
}


/* StrBuf_putc_write @ 0x1388f0 */

_Bool StrBuf_putc_write(StrBuf_state *p,char c)

{
  ulong uVar1;
  bool bVar2;

  uVar1 = p->pos;
  bVar2 = uVar1 < p->size;
  if (bVar2) {
    p->buf[uVar1] = c;
    p->pos = p->pos + 1;
  }
  return bVar2;
}


/* CGroup_filterName_internal @ 0x1391c0 */

/* WARNING: Type propagation algorithm not settling */

_Bool CGroup_filterName_internal(char *cgroup,StrBuf_state *s,StrBuf_putc_t w)

{
  undefined1 __frame[0xc8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x88;
  char cVar1;
  bool bVar2;
  char cVar3;
  _Bool _Var4;
  int iVar5;
  StrBuf_putc_t __s1;
  StrBuf_putc_t p_Var6;
  StrBuf_putc_t in_RCX;
  StrBuf_putc_t p_Var7;
  long extraout_RDX;
  long extraout_RDX_00;
  code *extraout_RDX_01;
  code *extraout_RDX_02;
  StrBuf_putc_t extraout_RDX_03;
  long extraout_RDX_04;
  long extraout_RDX_05;
  StrBuf_putc_t extraout_RDX_06;
  StrBuf_putc_t extraout_RDX_07;
  StrBuf_putc_t extraout_RDX_08;
  StrBuf_putc_t extraout_RDX_09;
  long extraout_RDX_10;
  long extraout_RDX_11;
  StrBuf_putc_t extraout_RDX_12;
  StrBuf_putc_t a2;
  long extraout_RDX_13;
  long extraout_RDX_14;
  StrBuf_putc_t p_Var8;
  StrBuf_putc_t extraout_RDX_15;
  StrBuf_putc_t extraout_RDX_16;
  long extraout_RDX_17;
  StrBuf_putc_t extraout_RDX_18;
  StrBuf_putc_t extraout_RDX_19;
  code *pcVar9;
  StrBuf_putc_t extraout_RDX_20;
  long lVar10;
  StrBuf_putc_t extraout_RDX_21;
  StrBuf_putc_t extraout_RDX_22;
  long extraout_RDX_23;
  StrBuf_putc_t extraout_RDX_24;
  long extraout_RDX_25;
  char *pcVar11;
  StrBuf_putc_t extraout_RDX_26;
  long extraout_RDX_27;
  StrBuf_putc_t extraout_RDX_28;
  long extraout_RDX_29;
  long in_R8;
  long in_R9;
  StrBuf_putc_t p_Var12;
  StrBuf_putc_t p_Var13;
  code *pcVar14;

  cVar3 = (char)*cgroup;
  p_Var8 = w;
  if (cVar3 == (char)0x0) {
    return true;
  }
LAB_001391e5:
                    /* Unresolved local var: char * labelStart@[???]
                       Unresolved local var: char * nextSlash@[???]
                       Unresolved local var: size_t labelLen@[???] */
  p_Var7 = (StrBuf_putc_t)cgroup;
  if (cVar3 != (char)0x2f) {
LAB_001391ed:
    __s1 = (StrBuf_putc_t)strchrnul((char *)p_Var7,0x2f);
    p_Var12 = __s1 + -(long)p_Var7;
    p_Var13 = p_Var7;
    if (p_Var12 == (StrBuf_putc_t)0xc) {
      iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_system_slice_001497d4 /* "system.slice" */),0xc);
      if (iVar5 != 0) {
LAB_0013923d:
        (*(code *(*))(__fp - 0x40)) = p_Var12 + -6;
        iVar5 = strncmp((char *)(p_Var7 + (long)(*(code *(*))(__fp - 0x40))),((char *)(long)(__sec_rodata + 0x27f1) /* ".slice" */),6);
        lVar10 = extraout_RDX_00;
        if (iVar5 != 0) goto LAB_00139650;
LAB_00139262:
                    /* Unresolved local var: size_t sliceNameLen@[???] */
        _Var4 = (*(code *)(w))(s,'[',lVar10,(long)in_RCX,in_R8,in_R9);
        pcVar9 = extraout_RDX_01;
        p_Var8 = p_Var7;
        if (!_Var4) {
          return false;
        }
        do {
          p_Var13 = p_Var8 + 1;
          _Var4 = (*(code *)(w))(s,(char)*(uchar *)p_Var8,(long)pcVar9,(long)in_RCX,in_R8,in_R9);
          if (!_Var4) {
            return false;
          }
          pcVar9 = extraout_RDX_02;
          p_Var8 = p_Var13;
        } while (p_Var7 + ((long)(*(code *(*))(__fp - 0x40)) - (long)p_Var13) != (StrBuf_putc_t)0x0);
        goto LAB_00139590;
      }
      pcVar11 = ((char *)(long)&DAT_0014979a /* "[S]" */);
      lVar10 = extraout_RDX_04;
      while (cVar1 = *pcVar11, cVar1 != '\0') {
        pcVar11 = pcVar11 + 1;
        _Var4 = (*(code *)(w))(s,cVar1,lVar10,(long)in_RCX,in_R8,in_R9);
        lVar10 = extraout_RDX_05;
        if (!_Var4) {
          return false;
        }
      }
      iVar5 = strncmp((char *)__s1,((char *)(long)&s__system__001497e1 /* "/system-" */),8);
      p_Var8 = extraout_RDX_06;
      if (iVar5 != 0) goto LAB_001393a2;
      cgroup = strchrnul((char *)(__s1 + 1),0x2f);
      cVar3 = (char)*cgroup;
      p_Var8 = extraout_RDX_07;
      goto LAB_001392e0;
    }
    if (p_Var12 == (StrBuf_putc_t)0xd) {
      iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_machine_slice_001497ea /* "machine.slice" */),0xd);
      if (iVar5 == 0) {
        pcVar11 = ((char *)(long)&DAT_0014979e /* "[M]" */);
        p_Var8 = extraout_RDX_08;
        while (cVar1 = *pcVar11, cVar1 != '\0') {
          pcVar11 = pcVar11 + 1;
          _Var4 = (*(code *)(w))(s,cVar1,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
          p_Var8 = extraout_RDX_09;
          if (!_Var4) {
            return false;
          }
        }
        goto LAB_001393a2;
      }
      iVar5 = strncmp((char *)(p_Var7 + 7),((char *)(long)(__sec_rodata + 0x27f1) /* ".slice" */),6);
      if (iVar5 == 0) {
        (*(code *(*))(__fp - 0x40)) = (code *)0x7;
        lVar10 = extraout_RDX_10;
        goto LAB_00139262;
      }
LAB_001393cd:
      iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_lxc_payload__0014980a /* "lxc.payload." */),0xc);
      if (iVar5 == 0) {
        pcVar11 = ((char *)(long)&DAT_001497a6 /* "[lxc:" */);
        while (cVar1 = *pcVar11, cVar1 != '\0') {
                    /* Unresolved local var: size_t cgroupNameLen@[???] */
          pcVar11 = pcVar11 + 1;
          _Var4 = (*(code *)(w))(s,cVar1,(long)pcVar11,(long)in_RCX,in_R8,in_R9);
          if (!_Var4) {
            return false;
          }
        }
        pcVar9 = p_Var7 + 0xc;
        do {
          cVar3 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          _Var4 = (*(code *)(w))(s,(char)cVar3,(long)pcVar9,(long)in_RCX,in_R8,in_R9);
          if (!_Var4) {
            return false;
          }
        } while (p_Var7 + ((long)p_Var12 - (long)pcVar9) != (StrBuf_putc_t)0x0);
      }
      else {
        iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_lxc_monitor__00149817 /* "lxc.monitor." */),0xc);
        if (iVar5 != 0) goto LAB_00139650;
        pcVar11 = ((char *)(long)&DAT_001497ac /* "[LXC:" */);
        while (cVar1 = *pcVar11, cVar1 != '\0') {
          pcVar11 = pcVar11 + 1;
          _Var4 = (*(code *)(w))(s,cVar1,(long)pcVar11,(long)in_RCX,in_R8,in_R9);
          if (!_Var4) {
            return false;
          }
        }
        pcVar9 = p_Var7 + 0xc;
        do {
          cVar3 = *pcVar9;
          pcVar9 = pcVar9 + 1;
          _Var4 = (*(code *)(w))(s,(char)cVar3,(long)pcVar9,(long)in_RCX,in_R8,in_R9);
          if (!_Var4) {
            return false;
          }
        } while (p_Var7 + ((long)p_Var12 - (long)pcVar9) != (StrBuf_putc_t)0x0);
      }
LAB_00139590:
                    /* Unresolved local var: size_t cgroupNameLen@[???] */
      _Var4 = (*(code *)(w))(s,']',(long)pcVar9,(long)in_RCX,in_R8,in_R9);
      if (!_Var4) {
        return false;
      }
      cVar3 = *(uchar *)__s1;
      p_Var8 = extraout_RDX_15;
      cgroup = (char *)__s1;
      goto LAB_001392e0;
    }
    if (p_Var12 == (StrBuf_putc_t)0xa) {
      iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_user_slice_001497f8 /* "user.slice" */),10);
      if (iVar5 != 0) goto LAB_0013923d;
      pcVar11 = ((char *)(long)&DAT_001497a2 /* "[U]" */);
      lVar10 = extraout_RDX;
      while (cVar1 = *pcVar11, cVar1 != '\0') {
                    /* Unresolved local var: char * userSliceSlash@[???]
                       Unresolved local var: char * sliceSpec@[???]
                       Unresolved local var: size_t sliceNameLen@[???] */
        pcVar11 = pcVar11 + 1;
        _Var4 = (*(code *)(w))(s,cVar1,lVar10,(long)in_RCX,in_R8,in_R9);
        lVar10 = extraout_RDX_11;
        if (!_Var4) {
          return false;
        }
      }
      iVar5 = strncmp((char *)__s1,((char *)(long)&s__user__00149803 /* "/user-" */),6);
      p_Var8 = extraout_RDX_12;
      if (iVar5 != 0) goto LAB_001393a2;
      pcVar9 = __s1 + 6;
      cgroup = strchrnul((char *)pcVar9,0x2f);
      in_RCX = (StrBuf_putc_t)(cgroup + -6);
      iVar5 = strncmp((char *)in_RCX,((char *)(long)(__sec_rodata + 0x27f1) /* ".slice" */),6);
      p_Var8 = a2;
      if (iVar5 != 0) goto LAB_001393a2;
      p_Var7 = in_RCX + -(long)pcVar9;
      s->pos = s->pos - 1;
      in_RCX = p_Var7;
      _Var4 = (*(code *)(w))(s,':',(long)a2,(long)p_Var7,in_R8,in_R9);
      lVar10 = extraout_RDX_13;
      p_Var8 = p_Var7;
      if (!_Var4) {
        return false;
      }
      while (p_Var8 != (StrBuf_putc_t)0x0) {
        pcVar14 = pcVar9 + 1;
        _Var4 = (*(code *)(w))(s,(char)*pcVar9,lVar10,(long)in_RCX,in_R8,in_R9);
        if (!_Var4) {
          return false;
        }
        pcVar9 = pcVar14;
        lVar10 = extraout_RDX_14;
        p_Var8 = __s1 + (6 - (long)pcVar14) + (long)p_Var7;
      }
      _Var4 = (*(code *)(w))(s,']',lVar10,(long)in_RCX,in_R8,in_R9);
      p_Var8 = extraout_RDX_16;
      if (!_Var4) {
        return false;
      }
      goto LAB_001392d8;
    }
    p_Var8 = p_Var7;
    p_Var6 = p_Var12;
    if (p_Var12 < (StrBuf_putc_t)0x7) goto joined_r0x00139460;
    (*(code *(*))(__fp - 0x40)) = p_Var12 + -6;
    iVar5 = strncmp((char *)(p_Var7 + (long)(*(code *(*))(__fp - 0x40))),((char *)(long)(__sec_rodata + 0x27f1) /* ".slice" */),6);
    lVar10 = extraout_RDX_27;
    if (iVar5 == 0) goto LAB_00139262;
    if ((StrBuf_putc_t)0xc < p_Var12) goto LAB_001393cd;
    if (p_Var12 == (StrBuf_putc_t)0xb) {
      iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_lxc_monitor_00149824 /* "lxc.monitor" */),0xb);
      if (iVar5 == 0) {
        bVar2 = true;
      }
      else {
        iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_lxc_payload_00149830 /* "lxc.payload" */),0xb);
        if (iVar5 != 0) goto LAB_00139650;
        bVar2 = false;
      }
                    /* Unresolved local var: _Bool isMonitor@[???] */
      cVar3 = *(uchar *)__s1;
      p_Var8 = __s1;
      while (cVar3 == (char)0x2f) {
        p_Var8 = p_Var8 + 1;
        cVar3 = *(uchar *)p_Var8;
      }
      cgroup = strchrnul((char *)p_Var8,0x2f);
      if (0 < (long)cgroup - (long)p_Var8) {
        pcVar11 = ((char *)(long)&DAT_001497ac /* "[LXC:" */);
        if (!bVar2) {
          pcVar11 = ((char *)(long)&DAT_001497a6 /* "[lxc:" */);
        }
        while (cVar1 = *pcVar11, p_Var7 = p_Var8, cVar1 != '\0') {
          pcVar11 = pcVar11 + 1;
          _Var4 = (*(code *)(w))(s,cVar1,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
          if (!_Var4) {
            return false;
          }
        }
        do {
          p_Var13 = p_Var7 + 1;
          _Var4 = (*(code *)(w))(s,(char)*(uchar *)p_Var7,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
          if (!_Var4) {
            return false;
          }
          p_Var7 = p_Var13;
        } while (p_Var8 + (((long)cgroup - (long)p_Var8) - (long)p_Var13) != (StrBuf_putc_t)0x0);
        _Var4 = (*(code *)(w))(s,']',(long)p_Var8,(long)in_RCX,in_R8,in_R9);
        if (!_Var4) {
          return false;
        }
        cVar3 = (char)*cgroup;
        p_Var8 = extraout_RDX_28;
        goto LAB_001392e0;
      }
LAB_00139650:
      iVar5 = strncmp((char *)(p_Var7 + (long)(p_Var12 + -8)),((char *)(long)&s__service_0014983c /* ".service" */),8);
      if (iVar5 != 0) {
        pcVar9 = p_Var12 + -6;
        p_Var6 = p_Var7 + (long)pcVar9;
        iVar5 = strncmp((char *)p_Var6,((char *)(long)&s__scope_0014984b /* ".scope" */),6);
        if (iVar5 == 0) {
                    /* Unresolved local var: size_t scopeNameLen@[???] */
          if (pcVar9 < (code *)0x9) {
            lVar10 = extraout_RDX_17;
            if ((code *)0x5 < pcVar9) {
              iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_snap__00149870 /* "snap." */),5);
              if (iVar5 == 0) goto LAB_0013975c;
              lVar10 = extraout_RDX_23;
              if (pcVar9 == (code *)0x8) goto LAB_00139927;
            }
LAB_001398c4:
            _Var4 = (*(code *)(w))(s,'!',lVar10,(long)in_RCX,in_R8,in_R9);
            p_Var8 = extraout_RDX_21;
            if (!_Var4) {
              return false;
            }
            do {
              p_Var6 = p_Var13 + 1;
              _Var4 = (*(code *)(w))(s,(char)*(uchar *)p_Var13,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
              if (!_Var4) {
                return false;
              }
              p_Var8 = extraout_RDX_22;
              p_Var13 = p_Var6;
            } while (p_Var7 + (long)(p_Var12 + (-6 - (long)p_Var6)) != (StrBuf_putc_t)0x0);
          }
          else {
            iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_machine__00149852 /* "machine-" */),8);
            if (iVar5 == 0) {
                    /* Unresolved local var: size_t machineScopeNameLen@[???]
                       Unresolved local var: _Bool is_monitor@[???] */
              iVar5 = strncmp((char *)__s1,((char *)(long)&s__supervisor_0014985b /* "/supervisor" */),0xb);
              pcVar11 = ((char *)(long)&s__SNC__001497b2 /* "[SNC:" */);
              if (iVar5 != 0) {
                pcVar11 = ((char *)(long)&DAT_001497b8 /* "[snc:" */);
              }
              while (cVar1 = *pcVar11, cVar1 != '\0') {
                pcVar11 = pcVar11 + 1;
                _Var4 = (*(code *)(w))(s,cVar1,(long)pcVar11,(long)in_RCX,in_R8,in_R9);
                if (!_Var4) {
                  return false;
                }
              }
              pcVar9 = p_Var7 + 8;
              do {
                cVar3 = *pcVar9;
                pcVar9 = pcVar9 + 1;
                _Var4 = (*(code *)(w))(s,(char)cVar3,(long)pcVar9,(long)in_RCX,in_R8,in_R9);
                if (!_Var4) {
                  return false;
                }
              } while (p_Var7 + (long)(p_Var12 + (-6 - (long)pcVar9)) != (StrBuf_putc_t)0x0);
              _Var4 = (*(code *)(w))(s,']',(long)pcVar9,(long)in_RCX,in_R8,in_R9);
              if (!_Var4) {
                return false;
              }
              iVar5 = strncmp((char *)__s1,((char *)(long)&s__supervisor_0014985b /* "/supervisor" */),0xb);
              if (iVar5 == 0) {
                cVar3 = ((char *)__s1)[0xb];
                cgroup = (char *)(__s1 + 0xb);
                p_Var8 = extraout_RDX_20;
              }
              else {
                iVar5 = strncmp((char *)__s1,((char *)(long)&s__payload_00149867 /* "/payload" */),8);
                p_Var8 = extraout_RDX_26;
                if (iVar5 != 0) goto LAB_001393a2;
                cVar3 = ((char *)__s1)[8];
                cgroup = (char *)(__s1 + 8);
              }
              goto LAB_001392e0;
            }
            iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_snap__00149870 /* "snap." */),5);
            if (iVar5 != 0) {
LAB_00139927:
              iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_libpod__00149876 /* "libpod-" */),7);
              if (iVar5 == 0) {
                    /* Unresolved local var: char * nextDot@[???] */
                pcVar9 = p_Var7 + 7;
                p_Var13 = (StrBuf_putc_t)strchrnul((char *)pcVar9,0x2e);
                p_Var8 = (StrBuf_putc_t)&DAT_001497c5;
                while (cVar1 = (char)*(uchar *)p_Var8, cVar1 != '\0') {
                  p_Var8 = p_Var8 + 1;
                  _Var4 = (*(code *)(w))(s,cVar1,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
                  if (!_Var4) {
                    return false;
                  }
                }
                if (p_Var13 <= p_Var6) {
                  p_Var6 = p_Var13;
                }
                in_RCX = p_Var6 + -(long)pcVar9;
                p_Var13 = (StrBuf_putc_t)0xc;
                p_Var12 = (StrBuf_putc_t)0xc;
                if ((long)in_RCX < 0xd) {
                  p_Var13 = in_RCX;
                  p_Var12 = in_RCX;
                }
                while (p_Var13 != (StrBuf_putc_t)0x0) {
                  pcVar14 = pcVar9 + 1;
                  _Var4 = (*(code *)(w))(s,(char)*pcVar9,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
                  if (!_Var4) {
                    return false;
                  }
                  pcVar9 = pcVar14;
                  p_Var8 = extraout_RDX_24;
                  p_Var13 = p_Var7 + (7 - (long)pcVar14) + (long)p_Var12;
                }
              }
              else {
                iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_docker__0014987e /* "docker-" */),7);
                lVar10 = extraout_RDX_25;
                if (iVar5 != 0) goto LAB_001398c4;
                    /* Unresolved local var: char * nextDot@[???] */
                pcVar9 = p_Var7 + 7;
                p_Var8 = (StrBuf_putc_t)strchrnul((char *)pcVar9,0x2e);
                pcVar11 = ((char *)(long)&s__docker__001497cb /* "!docker:" */);
                while (cVar1 = *pcVar11, cVar1 != '\0') {
                  pcVar11 = pcVar11 + 1;
                  _Var4 = (*(code *)(w))(s,cVar1,(long)pcVar11,(long)in_RCX,in_R8,in_R9);
                  if (!_Var4) {
                    return false;
                  }
                }
                if (p_Var8 <= p_Var6) {
                  p_Var6 = p_Var8;
                }
                p_Var6 = p_Var6 + -(long)pcVar9;
                p_Var8 = p_Var6;
                if (0xc < (long)p_Var6) {
                  p_Var6 = (StrBuf_putc_t)0xc;
                  p_Var8 = p_Var6;
                }
                while (p_Var6 != (StrBuf_putc_t)0x0) {
                  _Var4 = (*(code *)(w))(s,(char)*pcVar9,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
                  if (!_Var4) {
                    return false;
                  }
                  p_Var6 = p_Var7 + (7 - (long)(pcVar9 + 1)) + (long)p_Var8;
                  pcVar9 = pcVar9 + 1;
                }
              }
              goto LAB_001393a2;
            }
LAB_0013975c:
                    /* Unresolved local var: char * nextDot@[???] */
            pcVar9 = p_Var7 + 5;
            p_Var13 = (StrBuf_putc_t)strchrnul((char *)pcVar9,0x2e);
            p_Var8 = (StrBuf_putc_t)&DAT_001497be;
            while (cVar1 = (char)*(uchar *)p_Var8, cVar1 != '\0') {
              p_Var8 = p_Var8 + 1;
              _Var4 = (*(code *)(w))(s,cVar1,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
              if (!_Var4) {
                return false;
              }
            }
            if (p_Var13 <= p_Var6) {
              p_Var6 = p_Var13;
            }
            pcVar14 = pcVar9;
            in_RCX = p_Var13;
            p_Var13 = p_Var6 + -(long)pcVar9;
            while (p_Var13 != (StrBuf_putc_t)0x0) {
              _Var4 = (*(code *)(w))(s,(char)*pcVar14,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
              if (!_Var4) {
                return false;
              }
              p_Var13 = p_Var7 + (long)(p_Var6 + -(long)pcVar9 + (5 - (long)(pcVar14 + 1)));
              pcVar14 = pcVar14 + 1;
              p_Var8 = extraout_RDX_19;
            }
          }
          goto LAB_001393a2;
        }
        goto LAB_00139563;
      }
                    /* Unresolved local var: size_t serviceNameLen@[???] */
      iVar5 = strncmp((char *)p_Var7,((char *)(long)&s_user__00149845 /* "user@" */),5);
      if (iVar5 != 0) goto LAB_001396da;
      if (*(uchar *)__s1 != (_func__Bool_StrBuf_state_ptr_char)0x2f) goto LAB_00139ace;
      do {
        cVar3 = ((char *)__s1)[1];
        cgroup = (char *)(__s1 + 1);
        p_Var8 = extraout_RDX_18;
        __s1 = (StrBuf_putc_t)cgroup;
      } while (cVar3 == (char)0x2f);
      goto LAB_001392e0;
    }
    if (p_Var12 == (StrBuf_putc_t)0x9) goto LAB_00139650;
    iVar5 = strncmp((char *)(p_Var7 + (long)(*(code *(*))(__fp - 0x40))),((char *)(long)&s__scope_0014984b /* ".scope" */),6);
    lVar10 = extraout_RDX_29;
    if (iVar5 == 0) goto LAB_001398c4;
LAB_00139563:
    do {
      p_Var8 = p_Var13 + 1;
      _Var4 = (*(code *)(w))(s,(char)*(uchar *)p_Var13,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
      if (!_Var4) {
        return false;
      }
      p_Var6 = p_Var7 + ((long)p_Var12 - (long)p_Var8);
joined_r0x00139460:
      p_Var13 = p_Var8;
    } while (p_Var6 != (StrBuf_putc_t)0x0);
    goto LAB_001393a2;
  }
  for (; *cgroup == '/'; cgroup = cgroup + 1) {
  }
  _Var4 = (*(code *)(w))(s,'/',(long)p_Var8,(long)in_RCX,in_R8,in_R9);
  p_Var8 = extraout_RDX_03;
  if (!_Var4) {
    return false;
  }
LAB_001392d8:
  cVar3 = (char)*cgroup;
  goto LAB_001392e0;
LAB_001396da:
  do {
    p_Var8 = p_Var13 + 1;
    _Var4 = (*(code *)(w))(s,(char)*(uchar *)p_Var13,(long)p_Var8,(long)in_RCX,in_R8,in_R9);
    if (!_Var4) {
      return false;
    }
    p_Var13 = p_Var8;
  } while (p_Var7 + (long)(p_Var12 + (-8 - (long)p_Var8)) != (StrBuf_putc_t)0x0);
LAB_001393a2:
  cVar3 = *(uchar *)__s1;
  cgroup = (char *)__s1;
LAB_001392e0:
  if (cVar3 == (char)0x0) {
    return true;
  }
  goto LAB_001391e5;
LAB_00139ace:
  p_Var7 = __s1;
  if (*(uchar *)__s1 == (_func__Bool_StrBuf_state_ptr_char)0x0) {
    return true;
  }
  goto LAB_001391ed;
}


/* CGroup_filterContainer_internal @ 0x139c70 */

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
          iVar5 = strncmp(cgroup,((char *)(long)&s_lxc_payload_00149830 /* "lxc.payload" */),0xb);
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
              pcVar9 = ((char *)(long)&DAT_00149886 /* "/lxc:" */);
              lVar10 = extraout_RDX_01;
              while (cVar1 = *pcVar9, pbVar6 = pbVar7, cVar1 != '\0') {
                pcVar9 = pcVar9 + 1;
                _Var4 = (*(code *)(w))(s,cVar1,lVar10,uVar8,in_R8,in_R9);
                lVar10 = extraout_RDX_04;
                if (!_Var4) {
                  return false;
                }
              }
              do {
                pbVar12 = pbVar6 + 1;
                _Var4 = (*(code *)(w))(s,*pbVar6,lVar10,uVar8,in_R8,in_R9);
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
        iVar5 = strncmp(cgroup,((char *)(long)&s_lxc_payload__0014980a /* "lxc.payload." */),0xc);
        if (iVar5 == 0) {
          pcVar9 = ((char *)(long)&DAT_00149886 /* "/lxc:" */);
          lVar10 = extraout_RDX;
          while (cVar1 = *pcVar9, cVar1 != '\0') {
            pcVar9 = pcVar9 + 1;
            _Var4 = (*(code *)(w))(s,cVar1,lVar10,uVar8,in_R8,in_R9);
            lVar10 = extraout_RDX_02;
            if (!_Var4) {
              return false;
            }
          }
          pbVar7 = (byte *)(cgroup + 0xc);
          do {
            pbVar11 = pbVar7 + 1;
            _Var4 = (*(code *)(w))(s,*pbVar7,lVar10,uVar8,in_R8,in_R9);
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
          iVar5 = strncmp((char *)pbVar7,((char *)(long)&s__scope_0014984b /* ".scope" */),6);
          if (iVar5 == 0) {
                    /* Unresolved local var: size_t scopeNameLen@[???] */
            if (uVar8 < 9) {
              if (uVar8 != 8) goto LAB_00139d0a;
            }
            else {
              iVar5 = strncmp(cgroup,((char *)(long)&s_machine__00149852 /* "machine-" */),8);
              if (iVar5 == 0) {
                    /* Unresolved local var: size_t machineScopeNameLen@[???]
                       Unresolved local var: _Bool is_monitor@[???] */
                iVar5 = strncmp((char *)__s1,((char *)(long)&s__supervisor_0014985b /* "/supervisor" */),0xb);
                if (iVar5 != 0) {
                  pcVar9 = ((char *)(long)&DAT_0014988c /* "/snc:" */);
                  while (cVar1 = *pcVar9, cVar1 != '\0') {
                    pcVar9 = pcVar9 + 1;
                    _Var4 = (*(code *)(w))(s,cVar1,(long)pcVar9,uVar8,in_R8,in_R9);
                    if (!_Var4) {
                      return false;
                    }
                  }
                  pbVar7 = (byte *)(cgroup + 8);
                  do {
                    bVar3 = *pbVar7;
                    pbVar7 = pbVar7 + 1;
                    _Var4 = (*(code *)(w))(s,bVar3,(long)pbVar7,uVar8,in_R8,in_R9);
                    if (!_Var4) {
                      return false;
                    }
                  } while ((byte *)(cgroup + uVar13 + (-6 - (long)pbVar7)) != (byte *)0x0);
                  iVar5 = strncmp((char *)__s1,((char *)(long)&s__supervisor_0014985b /* "/supervisor" */),0xb);
                  if (iVar5 != 0) {
                    iVar5 = strncmp((char *)__s1,((char *)(long)&s__payload_00149867 /* "/payload" */),8);
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
            iVar5 = strncmp(cgroup,((char *)(long)&s_libpod__00149876 /* "libpod-" */),7);
            if (iVar5 == 0) {
                    /* Unresolved local var: char * nextDot@[???] */
              pbVar11 = (byte *)(cgroup + 7);
              pbVar6 = (byte *)strchrnul((char *)pbVar11,0x2e);
              pcVar9 = ((char *)(long)&DAT_00149892 /* "/pod:" */);
              while (cVar1 = *pcVar9, cVar1 != '\0') {
                pcVar9 = pcVar9 + 1;
                _Var4 = (*(code *)(w))(s,cVar1,(long)pcVar9,uVar8,in_R8,in_R9);
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
                _Var4 = (*(code *)(w))(s,*pbVar11,(long)pcVar9,(long)pbVar7,in_R8,in_R9);
                if (!_Var4) {
                  return false;
                }
                pbVar11 = pbVar6;
                pcVar9 = extraout_RDX_06;
                pbVar6 = (byte *)(cgroup + (long)(pbVar12 + (7 - (long)pbVar6)));
              }
            }
            else {
              iVar5 = strncmp(cgroup,((char *)(long)&s_docker__0014987e /* "docker-" */),7);
              if (iVar5 == 0) {
                    /* Unresolved local var: char * nextDot@[???] */
                pbVar11 = (byte *)(cgroup + 7);
                pbVar6 = (byte *)strchrnul((char *)pbVar11,0x2e);
                pcVar9 = ((char *)(long)&s__docker__001497cb /* "!docker:" */);
                while (cVar1 = *pcVar9, cVar1 != '\0') {
                  pcVar9 = pcVar9 + 1;
                  _Var4 = (*(code *)(w))(s,cVar1,(long)pcVar9,uVar8,in_R8,in_R9);
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
                  _Var4 = (*(code *)(w))(s,*pbVar11,(long)pcVar9,(long)pbVar7,in_R8,in_R9);
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


/* CGroup_filterName @ 0x13e0e0 */

char * CGroup_filterName(char *cgroup)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long lVar1;
  size_t sVar2;
  _Bool _Var3;
  char *pcVar4;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  (*(StrBuf_state (*))(__fp - 0x48)).buf = (char *)0x0;
  (*(StrBuf_state (*))(__fp - 0x48)).size = 0;
  (*(StrBuf_state (*))(__fp - 0x48)).pos = 0;
  _Var3 = CGroup_filterName_internal(cgroup,&(*(StrBuf_state (*))(__fp - 0x48)),StrBuf_putc_count);
  if (_Var3) {
    sVar2 = (*(StrBuf_state (*))(__fp - 0x48)).pos;
                    /* Unresolved local var: void * data@[???] */
    pcVar4 = calloc((*(StrBuf_state (*))(__fp - 0x48)).pos + 1,1);
    if (pcVar4 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      fail();
    }
    (*(StrBuf_state (*))(__fp - 0x48)).pos = 0;
    (*(StrBuf_state (*))(__fp - 0x48)).size = sVar2;
    (*(StrBuf_state (*))(__fp - 0x48)).buf = pcVar4;
    _Var3 = CGroup_filterName_internal(cgroup,&(*(StrBuf_state (*))(__fp - 0x48)),StrBuf_putc_write);
    if (_Var3) {
      (*(StrBuf_state (*))(__fp - 0x48)).buf[(*(StrBuf_state (*))(__fp - 0x48)).size] = '\0';
      pcVar4 = (*(StrBuf_state (*))(__fp - 0x48)).buf;
      goto LAB_0013e177;
    }
    free((*(StrBuf_state (*))(__fp - 0x48)).buf);
  }
  pcVar4 = (char *)0x0;
LAB_0013e177:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


/* CGroup_filterContainer @ 0x13e1c0 */

char * CGroup_filterContainer(char *cgroup)

{
  undefined1 __frame[0xd8] __attribute__((aligned(16)));
  undefined1 *__fp = __frame + 0x98;
  long lVar1;
  size_t sVar2;
  _Bool _Var3;
  char *pcVar4;
  long in_FS_OFFSET = (long)__fake_fs;

  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  (*(StrBuf_state (*))(__fp - 0x48)).buf = (char *)0x0;
  (*(StrBuf_state (*))(__fp - 0x48)).size = 0;
  (*(StrBuf_state (*))(__fp - 0x48)).pos = 0;
  _Var3 = CGroup_filterContainer_internal(cgroup,&(*(StrBuf_state (*))(__fp - 0x48)),StrBuf_putc_count);
  if (_Var3) {
    sVar2 = (*(StrBuf_state (*))(__fp - 0x48)).pos;
    if ((*(StrBuf_state (*))(__fp - 0x48)).pos == 0) {
                    /* Unresolved local var: char * data@[???] */
      pcVar4 = strdup(((char *)(long)(__sec_rodata + 0x17c2) /* "/" */));
      if (pcVar4 == (char *)0x0) goto LAB_0013e291;
      goto LAB_0013e261;
    }
                    /* Unresolved local var: void * data@[???] */
    pcVar4 = calloc((*(StrBuf_state (*))(__fp - 0x48)).pos + 1,1);
    if (pcVar4 == (char *)0x0) {
LAB_0013e291:
                    /* WARNING: Subroutine does not return */
      fail();
    }
    (*(StrBuf_state (*))(__fp - 0x48)).pos = 0;
    (*(StrBuf_state (*))(__fp - 0x48)).size = sVar2;
    (*(StrBuf_state (*))(__fp - 0x48)).buf = pcVar4;
    _Var3 = CGroup_filterContainer_internal(cgroup,&(*(StrBuf_state (*))(__fp - 0x48)),StrBuf_putc_write);
    if (_Var3) {
      (*(StrBuf_state (*))(__fp - 0x48)).buf[(*(StrBuf_state (*))(__fp - 0x48)).size] = '\0';
      pcVar4 = (*(StrBuf_state (*))(__fp - 0x48)).buf;
      goto LAB_0013e261;
    }
    free((*(StrBuf_state (*))(__fp - 0x48)).buf);
  }
  pcVar4 = (char *)0x0;
LAB_0013e261:
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pcVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

