/* DisplayOptionsPanel_eventHandler @ 0011f5f0 size 433 */

HandlerResult DisplayOptionsPanel_eventHandler(DisplayOptionsPanel_ *super,wchar_t ch)

{
  uint64_t *puVar1;
  int iVar2;
  Vector *pVVar3;
  wchar_t *pwVar4;
  byte *pbVar5;
  Settings_4 *pSVar6;
  Header_4 *this;
  wchar_t wVar7;
  wchar_t wVar8;
  NumberItem *this_00;

  pVVar3 = (super->super).items;
  this_00 = (NumberItem *)0x0;
  if (L'\0' < pVVar3->items) {
    this_00 = (NumberItem *)pVVar3->array[(super->super).selected];
  }
  if (ch < L'.') {
    if (ch < L'\n') {
      return IGNORED;
    }
    switch(ch) {
    case L'\n':
    case L'\r':
    case L' ':
      goto switchD_0011f636_caseD_a;
    default:
      goto LAB_0011f645;
    case L'+':
      if (*(int *)&(this_00->super).super.klass[1].extends != 2) {
        return IGNORED;
      }
      NumberItem_increase(this_00);
      break;
    case L'-':
      if (*(int *)&(this_00->super).super.klass[1].extends != 2) {
        return IGNORED;
      }
      pwVar4 = this_00->ref;
      wVar7 = this_00->max;
      if (pwVar4 == (wchar_t *)0x0) {
        wVar8 = this_00->value + L'\xffffffff';
        if ((wVar8 <= wVar7) && (wVar7 = this_00->min, this_00->min <= wVar8)) {
          wVar7 = wVar8;
        }
        this_00->value = wVar7;
      }
      else {
        wVar8 = *pwVar4 + L'\xffffffff';
        if (wVar7 < wVar8) {
          *pwVar4 = wVar7;
        }
        else {
          wVar7 = this_00->min;
          if (this_00->min <= wVar8) {
            wVar7 = wVar8;
          }
          *pwVar4 = wVar7;
        }
      }
    }
  }
  else {
    if (((ch != L'ŗ') && (ch != L'ƙ')) && (ch != L'Ĩ')) {
      return IGNORED;
    }
switchD_0011f636_caseD_a:
    iVar2 = *(int *)&(this_00->super).super.klass[1].extends;
    if (iVar2 == 1) {
      pbVar5 = (byte *)this_00->text;
      if (pbVar5 == (byte *)0x0) {
        *(byte *)&this_00->ref = *(byte *)&this_00->ref ^ 1;
      }
      else {
        *pbVar5 = *pbVar5 ^ 1;
      }
    }
    else {
      if (iVar2 != 2) {
LAB_0011f645:
        return IGNORED;
      }
      pwVar4 = this_00->ref;
      if (pwVar4 == (wchar_t *)0x0) {
        if (this_00->value < this_00->max) {
          this_00->value = this_00->value + L'\x01';
        }
        else {
          this_00->value = this_00->min;
        }
      }
      else if (*pwVar4 < this_00->max) {
        *pwVar4 = *pwVar4 + L'\x01';
      }
      else {
        *pwVar4 = this_00->min;
      }
    }
  }
                    /* Unresolved local var: Header * header@[???] */
  pSVar6 = super->settings;
  puVar1 = &pSVar6->lastUpdate;
  *puVar1 = *puVar1 + 1;
  pSVar6->changed = true;
  this = super->scr->header;
  Header_calculateHeight((Header *)this);
  Header_reinit((Header *)this);
  Header_updateData((Header *)this);
  Header_draw((Header *)this);
  ScreenManager_resize((ScreenManager *)super->scr);
  return HANDLED;
}

