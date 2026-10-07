/* actionSetup @ 0011a860 size 340 */

Htop_Reaction actionSetup(State_2 *st)

{
  Machine *host;
  Header_4 *header;
  Settings__2 *pSVar1;
  ScreenManager *this;
  Vector *pVVar2;
  Object **ppOVar3;

                    /* Unresolved local var: Settings * settings@[???]
                       Unresolved local var: ScreenManager * scr@[???] */
  host = st->host;
  header = (Header_4 *)st->header;
                    /* Unresolved local var: ScreenManager * this@[???]
                       Unresolved local var: void * data@[???] */
  pSVar1 = host->settings;
  this = malloc(0x48);
  if (this != (ScreenManager *)0x0) {
                    /* Unresolved local var: Vector * this@[???]
                       Unresolved local var: void * data@[???] */
    this->x1 = L'\0';
    this->y1 = L'\0';
    this->x2 = L'\0';
    this->y2 = L'\xffffffff';
    pVVar2 = malloc(0x28);
    if (pVVar2 != (Vector *)0x0) {
      pVVar2->growthRate = L'\n';
                    /* Unresolved local var: void * data@[???] */
      ppOVar3 = calloc(10,8);
      if (ppOVar3 != (Object **)0x0) {
        pVVar2->array = ppOVar3;
        pVVar2->arraySize = L'\n';
        pVVar2->type = &Panel_class.super;
        pVVar2->owner = true;
        pVVar2->items = L'\0';
        pVVar2->dirty_index = L'\xffffffff';
        pVVar2->dirty_count = L'\0';
        this->panels = pVVar2;
        this->panelCount = L'\0';
        this->state = st;
        this->allowFocusChange = true;
        this->header = (Header_2 *)header;
        this->host = host;
        CategoriesPanel_new((ScreenManager_3 *)this,header,(Machine_2 *)host);
        ScreenManager_run(this,(Panel **)0x0,(wchar_t *)0x0,((char *)0x1473fb /* "Setup" */));
        Vector_delete(this->panels);
        free(this);
        if (pSVar1->changed != false) {
          if (pSVar1->enableMouse == false) {
            mousemask(0,(ulong *)0x0);
          }
          else {
            mousemask(0x210001,(ulong *)0x0);
          }
          Header_writeBackToSettings((Header *)st->header);
        }
        return HTOP_RESIZE;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  fail();
}

