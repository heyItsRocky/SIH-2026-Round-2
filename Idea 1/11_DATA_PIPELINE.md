# SIH26025 — Data Pipeline

> What happens to a sensor reading?

---

## 1. Pipeline

```
Sensor
    ↓
Sampling (configurable rate, e.g., 10 Hz)
    ↓
Filtering (moving average, median filter, outlier removal)
    ↓
Feature extraction (mean, variance, peak, slope)
    ↓
Transmission (MQTT to gateway)
    ↓
Storage (time-series DB on Pi 4 / SSD)
    ↓
Analysis (edge AI anomaly detection)
    ↓
Dashboard (GIS visualization, risk maps)
```

---

## 2. Sampling

- **Rate:** 10 Hz per sensor (configurable)
- **Window:** 1-second windows for feature extraction
- **Buffer:** Local ring buffer on node

---

## 3. Filtering

- Moving average (smooth noise)
- Median filter (remove spikes)
- Outlier removal (sensor glitches)

---

## 4. Feature Extraction

Per window:
- Mean
- Variance
- Peak-to-peak
- Slope (rate of change)
- Zero-crossing rate (vibration)

---

## 5. Transmission

- MQTT QoS 1 for critical data
- Batch transmission to reduce overhead
- Local buffering if offline

---

## 6. Storage

- Time-series DB (InfluxDB or SQLite)
- Raw + processed data
- Historical data for ML training

---

## 7. Analysis

- Edge AI anomaly detection on Pi 4
- Multi-node correlation
- Risk scoring

---

## 8. Dashboard

- Live deformation map (GIS)
- Risk zones
- Alert history
- Node health
