# SIH26025 — Detection & Alert Logic

> The actual brain: sensor readings → anomaly score → confidence → alert level.

---

## 1. Detection Pipeline

```
Sensor readings
    ↓
Noise filtering
    ↓
Node comparison (per-node baseline)
    ↓
Correlation (multi-node comparison)
    ↓
Anomaly score
    ↓
Confidence
    ↓
Alert level
```

---

## 2. Per-Node Detection

For each node:
1. Compute baseline (mean, variance over training window)
2. Compute current features (mean, variance, slope)
3. Compute deviation from baseline (Z-score)
4. Flag if deviation exceeds threshold

---

## 3. Multi-Node Correlation (the differentiator)

- Compare each node's reading against its neighbors
- If **one node** deviates but neighbors are stable → likely local disturbance (not subsidence)
- If **multiple adjacent nodes** deviate in a correlated pattern → likely genuine ground movement
- Compute a **correlation score** across the mesh

---

## 4. Anomaly Score

```
anomaly_score = w1 * per_node_deviation + w2 * mesh_correlation
```

Where:
- `w1` = weight for per-node deviation
- `w2` = weight for mesh correlation (higher weight — this is the differentiator)

---

## 5. Confidence

```
confidence = f(anomaly_score, signal_quality, node_health)
```

- Higher anomaly score → higher confidence
- Poor signal quality → lower confidence
- Node health issues → lower confidence

---

## 6. Alert Levels

| Level | Condition | Action |
|---|---|---|
| **GREEN** | Normal | No action |
| **YELLOW** | Single-node deviation, low correlation | Monitor, notify operator |
| **ORANGE** | Multi-node deviation, medium correlation | Local alert (OLED/NeoPixel), notify |
| **RED** | Multi-node deviation, high correlation | GPIO alarm, SMS/email, escalate |

---

## 7. Alert Delivery

- **Local:** GPIO alarm, OLED display, NeoPixel
- **Remote:** SMS/email/mobile app (when online)
- **Dashboard:** Alert history, risk map update
