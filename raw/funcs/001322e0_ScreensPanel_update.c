/* ScreensPanel_update @ 001322e0 size 283 */

void ScreensPanel_update(ScreensPanel_ *super)

{
  wchar_t wVar1;
  Settings_4 *pSVar2;
  long lVar3;
  undefined8 *puVar4;
  char *__s1;
  int iVar5;
  ScreenSettings_3 **ppSVar6;
  char *pcVar7;
  ScreenSettings_3 **ppSVar8;
  ulong uVar9;
  long lVar10;

  pSVar2 = super->settings;
  wVar1 = ((super->super).items)->items;
  ppSVar8 = pSVar2->screens;
  pSVar2->changed = true;
  pSVar2->lastUpdate = pSVar2->lastUpdate + 1;
  uVar9 = (ulong)(wVar1 + L'\x01');
  if (uVar9 >> 0x3d == 0) {
                    /* Unresolved local var: void * data@[???] */
    ppSVar6 = realloc(ppSVar8,uVar9 * 8);
    if (ppSVar6 != (ScreenSettings_3 **)0x0) {
      pSVar2->screens = ppSVar6;
                    /* Unresolved local var: wchar_t i@[???] */
      if (wVar1 < L'\x01') {
        ppSVar8 = super->settings->screens;
      }
      else {
        lVar10 = 0;
        do {
                    /* Unresolved local var: ScreenListItem * item@[???]
                       Unresolved local var: ScreenSettings * ss@[???] */
          lVar3 = *(long *)((long)((super->super).items)->array + lVar10);
          puVar4 = *(undefined8 **)(lVar3 + 0x20);
          pcVar7 = *(char **)(lVar3 + 8);
          __s1 = (char *)*puVar4;
          if (__s1 == (char *)0x0) {
LAB_00132393:
            free(__s1);
                    /* Unresolved local var: char * data@[???] */
            pcVar7 = strdup(pcVar7);
            if (pcVar7 == (char *)0x0) goto LAB_001323fd;
            *puVar4 = pcVar7;
          }
          else {
            iVar5 = strcmp(__s1,pcVar7);
            if (iVar5 != 0) goto LAB_00132393;
          }
          ppSVar8 = super->settings->screens;
          *(undefined8 **)((long)ppSVar8 + lVar10) = puVar4;
          lVar10 = lVar10 + 8;
        } while (uVar9 * 8 - 8 != lVar10);
      }
      ppSVar8[uVar9 - 1] = (ScreenSettings_3 *)0x0;
      return;
    }
    free(ppSVar8);
  }
LAB_001323fd:
                    /* WARNING: Subroutine does not return */
  fail();
}

