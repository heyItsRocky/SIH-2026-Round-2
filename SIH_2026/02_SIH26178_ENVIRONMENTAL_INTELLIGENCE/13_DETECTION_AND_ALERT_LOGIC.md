# SIH26178 — Detection & Alert Logic

> The actual brain: sensor readings → anomaly score → confidence → alert level.

---

## 1. Detection Pipeline

```
Sensor readings
    ↓
Noise filtering
    ↓
Multi-sensor fusion (smoke + temp + humidity)
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

## 3. Multi-Sensor Fusion (the fire differentiator)

- MQ-2 smoke sensor cross-reacts with other gases — don't trust it alone
- Combine smoke + temperature + humidity:
  - Smoke high + temp high + humidity low → likely fire
  - Smoke high + temp normal + humidity normal → likely false alarm (other gas)
- Compute a **fusion score** across sensors

---

## 4. Multi-Node Correlation

- Compare each node's reading against its neighbors
- If **one node** deviates but neighbors are stable → likely local disturbance
- If **multiple adjacent nodes** deviate in a correlated pattern → likely genuine hazard
- Compute a **correlation score** across the mesh

---

## 5. Anomaly Score

```
anomaly_score = w1 * per_node_deviation + w2 * fusion_score + w3 * mesh_correlation
```

Where:
- `w1` = weight for per-node deviation
- `w2` = weight for multi-sensor fusion
- `w3` = weight for mesh correlation

---

## 6. Confidence

```
confidence = f(anomaly_score, signal_quality, node_health)
```

- Higher anomaly score → higher confidence
- Poor signal quality → lower confidence
- Node health issues → lower confidence

---

## 7. Alert Levels

| Level | Condition | Action |
|---|---|---|
| **GREEN** | Normal | No action |
| **YELLOW** | Single-node deviation, low fusion/correlation | Monitor, notify operator |
| **ORANGE** | Multi-node deviation, medium fusion/correlation | Local alert (OLED/NeoPixel), notify |
| **RED** | Multi-node deviation, high fusion/correlation | GPIO alarm, SACHET/CAP push, escalate |

---

## 8. Alert Delivery

- **Local:** GPIO alarm, OLED display, NeoPixel
- **Remote:** SACHET/CAP push to NDMA, SMS/email/mobile
- **Dashboard:** Alert history, risk map update
