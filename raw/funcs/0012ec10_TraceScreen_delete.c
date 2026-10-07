/* TraceScreen_delete @ 0012ec10 size 228 */

void TraceScreen_delete(TraceScreen_ *cast)

{
  Panel *__ptr;
  IncSet *__ptr_00;
  __pid_t _Var1;
  int *piVar2;

  if (0 < cast->child) {
    kill(cast->child,0xf);
    do {
      _Var1 = waitpid(cast->child,(int *)0x0,0);
      if (_Var1 != -1) break;
      piVar2 = __errno_location();
    } while (*piVar2 == 4);
  }
  if ((FILE_2 *)cast->strace != (FILE_2 *)0x0) {
    fclose((FILE_2 *)cast->strace);
  }
  halfdelay(*CRT_delay);
  __ptr = (cast->super).display;
                    /* Unresolved local var: Panel * super@[???]
                       Unresolved local var: AvailableColumnsPanel * this@[???] */
  free(__ptr->eventHandlerState);
  Vector_delete(__ptr->items);
  FunctionBar_delete(__ptr->defaultBar);
  if (L'Ş' < (__ptr->header).chlen) {
    free((__ptr->header).chptr);
  }
  free(__ptr);
  __ptr_00 = (cast->super).inc;
  FunctionBar_delete(__ptr_00->modes[0].bar);
  FunctionBar_delete(__ptr_00->modes[1].bar);
  free(__ptr_00);
  Vector_delete((cast->super).lines);
  free(cast);
  return;
}

