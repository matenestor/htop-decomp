/* Panel_onKey @ 001221b0 size 583 */

/* DWARF original prototype: _Bool Panel_onKey(Panel * this, wchar_t key) */

_Bool Panel_onKey(Panel *this,wchar_t key)

{
  wchar_t wVar1;
  wchar_t wVar2;
  wchar_t wVar3;
  wchar_t wVar4;
  byte bVar5;
  wchar_t wVar6;
  uint uVar7;

  wVar6 = CRT_scrollWheelVAmount;
  wVar1 = this->items->items;
  if (L'ħ' < key) {
    if (key == L'œ') {
      wVar4 = this->h;
      uVar7 = (uint)(L'\0' < (this->header).chlen);
      wVar6 = uVar7 - wVar4;
    }
    else {
      if (key == L'Ũ') {
        this->selected = wVar1 + L'\xffffffff';
        if (L'\0' < wVar1) {
          return true;
        }
        goto LAB_001222a1;
      }
      if (key != L'Œ') {
        return false;
      }
      wVar4 = this->h;
      uVar7 = (uint)(L'\0' < (this->header).chlen);
      wVar6 = wVar4 - uVar7;
    }
    wVar3 = this->selected + wVar6;
    this->selected = wVar3;
LAB_0012226d:
    wVar4 = (wVar1 - wVar4) - uVar7;
    if (wVar4 < L'\0') {
      wVar4 = L'\0';
    }
    wVar6 = wVar6 + this->scrollV;
LAB_0012227d:
    if (wVar6 < L'\0') {
      wVar6 = L'\0';
    }
    this->needsRedraw = true;
    if (wVar6 < wVar4) {
      wVar4 = wVar6;
    }
    bVar5 = (byte)((uint)wVar3 >> 0x1f);
    this->scrollV = wVar4;
    goto LAB_00122294;
  }
  if (key < L'Ă') {
    if (key < L'%') {
      switch(key) {
      case L'\x01':
        goto switchD_0012220e_caseD_1;
      case L'\x02':
        goto switchD_001221e7_caseD_104;
      default:
        goto switchD_001221e7_caseD_107;
      case L'\x05':
      case L'$':
        wVar6 = this->selectedLen - this->w;
        if (wVar6 < L'\0') {
          wVar6 = L'\0';
        }
        this->scrollH = wVar6;
        goto LAB_001222e1;
      case L'\x06':
        goto switchD_001221e7_caseD_105;
      case L'\x0e':
        goto switchD_001221e7_caseD_102;
      case L'\x10':
        goto switchD_001221e7_caseD_103;
      }
    }
    if (key != L'^') {
switchD_001221e7_caseD_107:
      return false;
    }
switchD_0012220e_caseD_1:
    this->scrollH = L'\0';
LAB_001222e1:
    wVar3 = this->selected;
    this->needsRedraw = true;
    bVar5 = (byte)((uint)wVar3 >> 0x1f);
  }
  else {
    switch(key) {
    case L'Ă':
switchD_001221e7_caseD_102:
      wVar3 = this->selected + L'\x01';
      this->selected = wVar3;
      bVar5 = (byte)((uint)wVar3 >> 0x1f);
      break;
    case L'ă':
switchD_001221e7_caseD_103:
      wVar3 = this->selected + L'\xffffffff';
      this->selected = wVar3;
      bVar5 = (byte)((uint)wVar3 >> 0x1f);
      break;
    case L'Ą':
switchD_001221e7_caseD_104:
      wVar3 = this->selected;
      bVar5 = (byte)((uint)wVar3 >> 0x1f);
      if (L'\0' < this->scrollH) {
        this->needsRedraw = true;
        wVar6 = CRT_scrollHAmount;
        if (CRT_scrollHAmount < L'\0') {
          wVar6 = L'\0';
        }
        this->scrollH = this->scrollH - wVar6;
      }
      break;
    case L'ą':
switchD_001221e7_caseD_105:
      this->scrollH = this->scrollH + CRT_scrollHAmount;
      goto LAB_001222e1;
    case L'Ć':
      this->selected = L'\0';
      bVar5 = 0;
      wVar3 = L'\0';
      break;
    default:
      goto switchD_001221e7_caseD_107;
    case L'Ħ':
      wVar4 = (this->header).chlen;
      wVar3 = this->selected - CRT_scrollWheelVAmount;
      this->selected = wVar3;
      wVar4 = (wVar1 - this->h) - (uint)(L'\0' < wVar4);
      if (wVar4 < L'\0') {
        wVar4 = L'\0';
      }
      wVar6 = this->scrollV - wVar6;
      goto LAB_0012227d;
    case L'ħ':
      wVar2 = (this->header).chlen;
      wVar4 = this->h;
      wVar3 = this->selected + CRT_scrollWheelVAmount;
      this->selected = wVar3;
      uVar7 = (uint)(L'\0' < wVar2);
      goto LAB_0012226d;
    }
  }
LAB_00122294:
  if ((wVar1 != L'\0') && (bVar5 == 0)) {
    if (wVar3 < wVar1) {
      return true;
    }
    this->needsRedraw = true;
    this->selected = wVar1 + L'\xffffffff';
    return true;
  }
LAB_001222a1:
  this->selected = L'\0';
  this->needsRedraw = true;
  return true;
}

