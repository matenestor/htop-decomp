/* Machine_isCPUonline @ 0013b210 size 34 */

_Bool Machine_isCPUonline(LinuxMachine_ *super,uint id)

{
  return super->cpuData[id + 1].online;
}

