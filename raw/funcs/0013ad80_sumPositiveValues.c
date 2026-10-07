/* sumPositiveValues @ 0013ad80 size 61 */

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

