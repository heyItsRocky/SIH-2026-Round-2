# FINAL Decision Matrix

> Engineering-based comparison — not "which sounds better," but "what can we actually build, demonstrate, and prove?"
> This file comes later, once both projects are researched deeply.

---

## 1. Scenario-Based Comparison

### Scenario A: No Internet

| | SIH26025 | SIH26178 |
|---|---|---|
| **What happens?** | Local mesh continues; Pi 4 runs edge anomaly detection; GPIO alarm + OLED/NeoPixel alert locally | Edge nodes continue local inference; local alerts fire; buffered data syncs on reconnect |
| **Can we demo?** | Yes — offline is a core feature | Yes — offline is a core feature |
| **Risk** | Low | Low |

### Scenario B: One Sensor Fails

| | SIH26025 | SIH26178 |
|---|---|---|
| **What happens?** | Mesh correlation detects anomaly from neighbors; degraded node flagged | Other nodes continue; missing data flagged; local alert still fires |
| **Can we demo?** | Yes — show graceful degradation | Yes — show graceful degradation |
| **Risk** | Medium (need graceful-degradation path) | Medium |

### Scenario C: Need Live Demo

| | SIH26025 | SIH26178 |
|---|---|---|
| **What do we show?** | Physical scale model with embedded sensors; disturb one node → dashboard correlates vs neighbors → alarm | Field-node kit; simulate hazard → edge AI detects → local alert → simulated SACHET push |
| **Visual impact** | High — judges see physical movement trigger alarm | High — judges see hazard detection + offline operation |
| **Risk** | Medium (physical rig must work reliably) | Medium (outdoor conditions unpredictable) |

### Scenario D: Judge Asks for Measurable Improvement

| | SIH26025 | SIH26178 |
|---|---|---|
| **What do we measure?** | Time-to-alert vs survey-cycle baseline; false-positive rate on injected faults; cost/node vs InSAR/GNSS | Detection latency vs satellite revisit time; node cost vs commercial station; offline uptime |
| **Can we prove it?** | Yes — with physical model + public case-study data | Yes — with public data + own hardware |
| **Risk** | Medium (sensor calibration credibility) | Medium |

---

## 2. Buildability Assessment

| Question | SIH26025 | SIH26178 |
|---|---|---|
| What can we actually build? | Distributed tilt/vibration mesh + edge anomaly detection + local alarm | Distributed multi-hazard sensor mesh + edge AI + offline buffering |
| What can we demonstrate? | Physical model with real-time alarm | Field-node kit with hazard detection + offline operation |
| What could fail? | Sensor calibration, false positives, physical rig | CV skill gap (if vision route), outdoor unpredictability |
| What can we prove? | Time-to-alert, false-positive rate, mesh correlation | Detection latency, offline uptime, cost/node |

---

## 3. Decision Inputs (to be filled after deep research)

- [ ] SIH26025 full PDF read — confirm live-sensing vs analytics
- [ ] SIH26178 Qualcomm hardware expectation — confirmed or not
- [ ] Team ML/CV bench strength — assessed
- [ ] Prototype feasibility — both tested
- [ ] Risk comparison — completed

---

## 4. Final Decision

**To be filled once all inputs are gathered.**
