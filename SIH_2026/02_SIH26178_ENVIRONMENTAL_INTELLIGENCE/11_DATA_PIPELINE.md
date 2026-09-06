# SIH26178 — Data Pipeline

> What happens to a sensor reading?

---

## 1. Pipeline

```
Sensor
    ↓
Sampling (configurable rate, e.g., 1 Hz)
    ↓
Filtering (moving average, median filter, outlier removal)
    ↓
Feature extraction (mean, variance, peak, slope)
    ↓
On-device edge AI inference (TFLite Micro)
    ↓
Transmission (only critical alerts + summarized insights)
    ↓
Storage (time-series DB on Pi 4 / SSD)
    ↓
Analysis (gateway-level anomaly detection)
    ↓
Dashboard (GIS visualization, risk maps)
    ↓
SACHET/CAP alert push (when online)
```

---

## 2. Sampling

- **Rate:** 1 Hz per sensor (configurable)
- **Window:** 10-second windows for feature extraction
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

## 5. On-Device Edge AI

- TFLite Micro on ESP32 for lightweight inference
- Anomaly detection model (threshold + statistical + correlation)
- Only critical alerts + summarized insights transmitted

---

## 6. Transmission

- MQTT QoS 1 for critical alerts
- QoS 0 for routine telemetry
- Local buffering if offline

---

## 7. Storage

- Time-series DB (InfluxDB or SQLite)
- Raw + processed data
- Historical data for ML training

---

## 8. Analysis

- Gateway-level anomaly detection on Pi 4
- Multi-node correlation
- Risk scoring

---

## 9. Dashboard

- Live risk map (GIS)
- Hotspot trends
- Severity alerts
- Node health

---

## 10. SACHET/CAP Integration

- Gateway pushes CAP-format alerts to NDMA SACHET bus
- Feeds existing national alert infrastructure (not a redundant app)
