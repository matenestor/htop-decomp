#include "htop.h"

/* Object_isA @ 0x1207e0 */

_Bool Object_isA(Object *o,ObjectClass *klass)

{
  ObjectClass *pOVar1;

                    /* Unresolved local var: ObjectClass * type@[???] */
  if ((o != (Object *)0x0) && (pOVar1 = o->klass, pOVar1 != (ObjectClass *)0x0)) {
    do {
      if (pOVar1 == klass) {
        return true;
      }
      pOVar1 = pOVar1->extends;
    } while (pOVar1 != (ObjectClass *)0x0);
    return false;
  }
  return false;
}

