# SIH26178 — Testing & Validation

> Where the project becomes credible. Design actual experiments.

---

## 1. Test Plan

| Test | Description | What it validates |
|---|---|---|
| **Test 1** | Stable environment (no hazard) | Baseline, no false alarms |
| **Test 2** | Smoke source near one node | Local detection, fusion score |
| **Test 3** | Smoke source near multiple nodes | Mesh correlation detects genuine hazard |
| **Test 4** | False alarm source (e.g., cooking gas) | Multi-sensor fusion filters false alarm |
| **Test 5** | Network failure | Offline buffering + local alerts |
| **Test 6** | Node failure | Graceful degradation, mesh continues |
| **Test 7** | SACHET/CAP push | Alert integration works |

---

## 2. Metrics

| Metric | Target |
|---|---|
| Detection latency | Sub-minute (vs satellite revisit baseline) |
| False-positive rate | Low (on injected fault tests) |
| False-negative rate | Near-zero (fail-closed) |
| Packet loss | Low (mesh reliability) |
| Fusion accuracy | High (distinguishes fire from false alarm) |
| Correlation accuracy | High (distinguishes local vs genuine) |
| System uptime | High (graceful degradation) |

---

## 3. Validation Approach

- **Physical test rig** — smoke source (incense/smoke generator) near sensor nodes
- **Public fire/air-quality case-study data** — validate detection logic on real published events
- **Synthetic fault injection** — inject simulated hazard events, measure detection

---

## 4. Honesty

Be upfront that this is a **prototype compression** — a decision-support early-indicator, not a certified disaster-monitoring instrument. Judges respect "prototype compression" done honestly far more than a demo that implies live field data it doesn't have.
