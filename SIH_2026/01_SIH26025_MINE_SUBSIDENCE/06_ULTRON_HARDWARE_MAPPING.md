# SIH26025 — ULTRON Hardware Mapping

> Bridge between existing hardware and this specific problem.

---

## 1. Hardware Mapping

| ULTRON Component | Role in Solution | Status |
|---|---|---|
| Raspberry Pi 4 (8GB) | Gateway, edge AI, MQTT broker, anomaly detection | Ready |
| Raspberry Pi 3A+ | Distributed mine node (local collection) | Ready |
| Raspberry Pi 3B | Distributed mine node (local collection) | Ready |
| ESP32-C3 | Sensor interface, status light | Ready |
| ESP32-WROOM-32 | Sensor interface, mesh relay | Ready |
| Ethernet Switch | Reliable local backbone | Ready |
| OLED Display | On-site status display | Ready |
| NeoPixel | Visual alert on anomaly | Ready |
| WiFi (AC600 / WN722N) | Mesh / uplink connectivity | Ready |
| 500GB SSD | Offline data buffering, ML models | Ready |
| GPIO Tripwire | Physical alarm trigger | Ready |
| MQTT Pipeline | Telemetry, alert delivery | Ready |

---

## 2. Architecture Mapping

```
Pi 4 (Gateway + Edge AI)
    │
    ├── Ethernet ──► Pi 3A+ (Mine Node A)
    │                   └── ESP32 + Tilt/Vibration sensors
    │
    ├── Ethernet ──► Pi 3B (Mine Node B)
    │                   └── ESP32 + Displacement/Crack sensors
    │
    ├── USB ──► ESP32-C3 (Sensor interface + NeoPixel alert)
    │
    └── GPIO ──► Physical alarm trigger
```

---

## 3. What We Add

| Component | Purpose | Cost |
|---|---|---|
| Tilt/inclination sensors (MPU6050/BNO055) | Ground tilt detection | ~₹150-300 |
| Vibration sensors | Ground vibration detection | ~₹100-200 |
| Displacement/stretch sensors | Node-to-node distance change | ~₹200-400 |
| Crack detection sensors | Early crack initiation | ~₹100-300 |
| Optional GPS module | Node positioning | ~₹200-400 |
| LoRa modules (if LoRa mesh) | Long-range mesh | ~₹300-500 |

---

## 4. Why ULTRON Is a Genuine Advantage

This is the textbook "Physical-to-Digital Loop" — not a hardware costume bolted onto a software idea. The distributed Pi/ESP32 mesh with local GPIO alerting is exactly what the problem's "offline and edge advantage" requires.
