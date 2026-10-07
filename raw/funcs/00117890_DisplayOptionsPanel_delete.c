/* DisplayOptionsPanel_delete @ 00117890 size 87 */

void DisplayOptionsPanel_delete(void *param_1)

{
  free(*(void **)((long)param_1 + 0x38));
  Vector_delete(*(Vector **)((long)param_1 + 0x20));
  FunctionBar_delete(*(FunctionBar **)((long)param_1 + 0x58));
  if (*(int *)((long)param_1 + 0x60) < 0x15f) {
    free(param_1);
    return;
  }
  free(*(void **)((long)param_1 + 0x68));
  free(param_1);
  return;
}

