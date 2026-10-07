/* Action_setBindings @ 00115c90 size 813 */

void Action_setBindings(Htop_Action_2 *keys)

{
  keys[0x46] = Action_follow;
  keys[0x68] = actionHelp;
  keys[0x2a] = actionExpandOrCollapseAllBranches;
  keys[0x2b] = actionExpandOrCollapse;
  keys[0x43] = actionSetup;
  keys[0x2e] = actionSetSortColumn;
  keys[0x2f] = actionIncSearch;
  keys[0x20] = actionTag;
  keys[0x3e] = actionSetSortColumn;
  keys[0x3f] = actionHelp;
  keys[0x109] = actionHelp;
  keys[0x10a] = actionSetup;
  keys[0x2c] = actionSetSortColumn;
  keys[0x2d] = actionExpandOrCollapse;
  keys[0x48] = actionToggleUserlandThreads;
  keys[0x49] = actionInvertSortOrder;
  keys[0x23] = actionToggleHideMeters;
  keys[0x4d] = actionSortByMemory;
  keys[0x4e] = actionSortByPID;
  keys[0x4b] = actionToggleKernelThreads;
  keys[0x4f] = actionToggleRunningInContainer;
  keys[0x50] = actionSortByCPU;
  keys[0xc] = actionRedraw;
  keys[0x55] = actionUntagAll;
  keys[0x53] = actionSetup;
  keys[0x54] = actionSortByTime;
  keys[0x61] = actionSetAffinity;
  keys[0x59] = actionSetSchedPolicy;
  keys[0x5a] = actionTogglePauseUpdate;
  keys[0x7f] = actionCollapseIntoParent;
  keys[0x5b] = actionLowerPriority;
  keys[0x5c] = actionIncFilter;
  keys[99] = actionTagAllChildren;
  keys[0x6b] = actionKill;
  keys[0x6c] = actionLsof;
  keys[0x65] = actionShowEnvScreen;
  keys[0x6d] = actionToggleMergedCommand;
  keys[0x70] = actionToggleProgramPath;
  keys[0x71] = actionQuit;
  keys[0x75] = actionFilterByUser;
  keys[0x73] = actionStrace;
  keys[0x74] = actionToggleTreeView;
  keys[0x5d] = actionHigherPriority;
  keys[0x3c] = actionSetSortColumn;
  keys[0x3d] = actionExpandOrCollapse;
  keys[0x77] = actionShowCommandScreen;
  keys[0x78] = actionShowLocks;
  keys[0x10b] = actionIncSearch;
  keys[0x10c] = actionIncFilter;
  keys[0x11a] = actionExpandCollapseOrSortColumn;
  keys[0x10d] = actionToggleTreeView;
  keys[0x10e] = actionSetSortColumn;
  keys[9] = actionNextScreen;
  keys[0x10f] = actionHigherPriority;
  keys[0x110] = actionLowerPriority;
  keys[0x111] = actionKill;
  keys[0x112] = actionQuit;
  keys[0x128] = actionExpandOrCollapse;
  keys[0x129] = actionPrevScreen;
  return;
}

