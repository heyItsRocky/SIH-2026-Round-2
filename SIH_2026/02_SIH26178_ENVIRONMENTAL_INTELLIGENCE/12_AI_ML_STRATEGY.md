# SIH26178 — AI/ML Strategy

> Do not automatically make this "deep learning." Investigate what is actually necessary.

---

## 1. Candidate Approaches

| Approach | Description | Complexity | When to use |
|---|---|---|---|
| **Thresholding** | Alert when sensor exceeds threshold | Low | Simple, baseline |
| **Statistical anomaly detection** | Z-score, moving average deviation | Low-Med | Detects drift from normal |
| **Multi-sensor fusion** | Combine smoke + temp + humidity | Med | Distinguishes fire from false alarm |
| **Multi-node correlation** | Compare nodes against each other | Med | Distinguishes local vs genuine hazard |
| **ML models** | Isolation Forest, autoencoder | Med | Unsupervised anomaly detection |
| **Computer vision** | Flame/smoke detection (camera) | High | Visually dramatic, but unproven skill |

---

## 2. Recommendation

**Start with a hybrid approach (sensor-only route):**
1. **Per-node thresholding** — immediate local alarm on extreme values
2. **Multi-sensor fusion** — combine smoke + temp + humidity to distinguish fire from false alarm (MQ-2 cross-sensitivity)
3. **Multi-node correlation** — compare each node against neighbors to distinguish local disturbance from genuine hazard

**Treat computer vision as a stretch goal** only if bench time allows. It's visually dramatic but a real, currently-unproven skill for this team.

---

## 3. Why Not Deep Learning / CV First?

- CV needs labeled image data — we don't have real fire/smoke footage
- A threshold/statistical/fusion model is defensible and honest
- The differentiator is **multi-sensor fusion + mesh correlation + SACHET integration**, not model sophistication
- Judges respect "we built the right tool for the problem" over "we used a neural net"

---

## 4. Validation

- Physical test rig with smoke source (e.g., incense/smoke generator)
- Inject simulated hazard events
- Measure detection latency, false-positive rate, correlation accuracy
- Use public fire/air-quality case-study data for credibility
