/* Per-core CPU usage history over the last minute, drawn as one line graph with a line per core.
   Replaces the momentary per-core bars of the multi-CPU meters (see src/CPUMeter.c). */
#pragma once

#define CPUHISTORY_SPAN_MS 60000
#define CPUHISTORY_CAPACITY 600  /* 60 s at the shortest refresh delay (0.1 s) */
#define CPUHISTORY_PLOT_ROWS 6   /* graph rows; one more row holds the legend */
#define CPUHISTORY_HEIGHT (CPUHISTORY_PLOT_ROWS + 1)

typedef struct CPUHistorySample_ {
  uint64_t ms;   /* Machine monotonicMs of the scan */
  double pct;    /* 0..100, negative when the core is offline */
} CPUHistorySample;

typedef struct CPUHistoryRing_ {
  CPUHistorySample samples[CPUHISTORY_CAPACITY];
  uint head;     /* index of the oldest sample */
  uint count;
} CPUHistoryRing;

/* one history for all cores, shared by the multi-CPU meters */
typedef struct CPUHistory_ {
  uint cores;
  CPUHistoryRing *rings;
  int users;       /* meters holding it */
  int leftMeters;  /* LeftCPUs* meters: they draw the graph over the full header width */
} CPUHistory;

/* meterData of the multi-CPU meters: CPUMeterData plus the history */
typedef struct CPUHistoryMeterData_ {
  uint cpus;
  Meter **meters;
  CPUHistory *history;
} CPUHistoryMeterData;

CPUHistory *CPUHistory_acquire(uint cores);
void CPUHistory_release(CPUHistory *this);
/* usage of one core sub-meter after its updateValues: sum of its positive values, max 100 */
double CPUHistory_meterPercent(const Meter *core);
void CPUHistory_record(CPUHistory *this, uint core, uint64_t nowMs, double pct);
/* graph of all cores, CPUHISTORY_HEIGHT rows from y */
void CPUHistory_drawGraph(const CPUHistory *this, const Machine *host, int x, int y, int w);
