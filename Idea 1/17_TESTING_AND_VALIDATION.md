# SIH26025 — Testing & Validation

> Where the project becomes credible. Design actual experiments.

---

## 1. Test Plan

| Test | Description | What it validates |
|---|---|---|
| **Test 1** | Stable mine simulation (no disturbance) | Baseline, no false alarms |
| **Test 2** | One-node disturbance | Local detection, no false mesh alarm |
| **Test 3** | Multi-node deformation | Mesh correlation detects genuine movement |
| **Test 4** | Noisy sensor | Filtering works, no false alarm |
| **Test 5** | Network failure | Offline buffering + local alerts |
| **Test 6** | Node failure | Graceful degradation, mesh continues |

---

## 2. Metrics

| Metric | Target |
|---|---|
| Detection latency | Sub-minute (vs weekly survey-cycle baseline) |
| False-positive rate | Low (on injected fault tests) |
| False-negative rate | Near-zero (fail-closed) |
| Packet loss | Low (mesh reliability) |
| Correlation accuracy | High (distinguishes local vs genuine) |
| System uptime | High (graceful degradation) |

---

## 3. Validation Approach

- **Physical scale-model rig** — motorized platform tilting a sensor node to simulate ground movement
- **Public InSAR case-study data** — validate prediction/alerting logic on real published subsidence events
- **Synthetic fault injection** — inject simulated deformation events, measure detection

---

## 4. Honesty

Be upfront that this is a **decision-support early-indicator**, not a certified structural-safety instrument. Judges respect "prototype compression" done honestly far more than a demo that implies live mine data it doesn't have.
