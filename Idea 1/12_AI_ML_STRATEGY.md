# SIH26025 — AI/ML Strategy

> Do not automatically make this "deep learning." Investigate what is actually necessary.

---

## 1. Candidate Approaches

| Approach | Description | Complexity | When to use |
|---|---|---|---|
| **Thresholding** | Alert when sensor exceeds threshold | Low | Simple, baseline |
| **Statistical anomaly detection** | Z-score, moving average deviation | Low-Med | Detects drift from normal |
| **Time-series analysis** | ARIMA, exponential smoothing | Med | Trend detection |
| **Multi-node correlation** | Compare nodes against each other | Med | Distinguishes local vs genuine movement |
| **ML models** | Isolation Forest, autoencoder | Med | Unsupervised anomaly detection |
| **Hybrid** | Threshold + statistical + correlation | Med | Robust, defensible |

---

## 2. Recommendation

**Start with a hybrid approach:**
1. **Per-node thresholding** — immediate local alarm on extreme values
2. **Statistical drift detection** — Z-score / moving-average deviation for slow deformation
3. **Multi-node correlation** — the key differentiator: compare each node against neighbors to distinguish local disturbance from genuine ground movement

**Add ML later if needed:** Isolation Forest or a small autoencoder for unsupervised anomaly detection.

---

## 3. Why Not Deep Learning First?

- Deep learning needs lots of labeled data — we don't have real mine data
- A threshold/statistical model is defensible and honest
- The differentiator is **mesh correlation**, not model sophistication
- Judges respect "we built the right tool for the problem" over "we used a neural net"

---

## 4. Validation

- Physical scale-model rig with embedded sensors
- Inject simulated deformation events
- Measure detection latency, false-positive rate, correlation accuracy
- Use public InSAR case-study data for credibility
