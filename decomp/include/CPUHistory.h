/* Per-core CPU usage history over the last minute, drawn as one heatmap row per core.
   Replaces the momentary per-core bars of the multi-CPU meters (see src/CPUMeter.c). */
#pragma once

#define CPUHISTORY_SPAN_MS 60000
#define CPUHISTORY_CAPACITY 600  /* 60 s at the shortest refresh delay (0.1 s) */

typedef struct CPUHistorySample_ {
  uint64_t ms;   /* Machine monotonicMs of the scan */
  double pct;    /* 0..100, negative when the core is offline */
} CPUHistorySample;

typedef struct CPUHistoryRing_ {
  CPUHistorySample samples[CPUHISTORY_CAPACITY];
  uint head;     /* index of the oldest sample */
  uint count;
} CPUHistoryRing;

typedef struct CPUHistory_ {
  uint cores;
  CPUHistoryRing *rings;
} CPUHistory;

/* meterData of the multi-CPU meters: CPUMeterData plus the history */
typedef struct CPUHistoryMeterData_ {
  uint cpus;
  Meter **meters;
  CPUHistory *history;
} CPUHistoryMeterData;

CPUHistory *CPUHistory_new(uint cores);
void CPUHistory_delete(CPUHistory *this);
/* usage of one core sub-meter after its updateValues: sum of its positive values, max 100 */
double CPUHistory_meterPercent(const Meter *core);
void CPUHistory_record(CPUHistory *this, uint core, uint64_t nowMs, double pct);
void CPUHistory_drawRow(const CPUHistory *this, uint core, const Meter *meter, uint64_t nowMs, int x, int y, int w);
