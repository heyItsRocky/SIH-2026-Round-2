# SIH26178 — ULTRON Hardware Mapping

> Bridge between existing hardware and this specific problem.

---

## 1. Hardware Mapping

| ULTRON Component | Role in Solution | Status |
|---|---|---|
| Raspberry Pi 4 (8GB) | Gateway, edge AI, MQTT broker, anomaly detection | Ready |
| Raspberry Pi 3A+ | Distributed edge node (local collection) | Ready |
| Raspberry Pi 3B | Distributed edge node (local collection) | Ready |
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
    ├── Ethernet ──► Pi 3A+ (Node A: water level + rain)
    │                   └── ESP32 + sensors
    │
    ├── Ethernet ──► Pi 3B (Node B: smoke + temp + humidity)
    │                   └── ESP32 + sensors
    │
    ├── USB ──► ESP32-C3 (Node C: PM2.5/PM10 + gas)
    │
    └── GPIO ──► Physical alarm trigger
```

---

## 3. What We Add

> ⚠ **ZERO-BUDGET MODE:** We add **nothing** — no new sensors. See `SIH_2026/00_MASTER/ZERO_BUDGET_STRATEGY.md`.

**For the hackathon (₹0):** The transducer layer is **software-simulated**. We use the existing mesh + real free signals:
- **CPU temperature** on each Pi (`vcgencmd measure_temp`) = a REAL environmental temperature stream
- **Tripwire GPIO** = real event trigger
- **NeoPixel + OLED** = real alert rendering

**Aspirational / production (future, if budget allows):**

| Component | Purpose | Cost |
|---|---|---|
| Water level sensor (ultrasonic) | Flood detection | ~₹300-500 |
| Rain gauge | Rainfall measurement | ~₹200-400 |
| Smoke sensor (MQ-2) | Fire/smoke detection | ~₹100-200 |
| Temperature/humidity (DHT22) | Heat/humidity monitoring | ~₹100 |
| PM2.5/PM10 sensor (PMS5003) | Air quality | ~₹800-1200 |
| Gas sensor (MQ-135) | Air quality / industrial | ~₹150-300 |
| Soil moisture sensor | Landslide precursor | ~₹100-200 |
| Vibration sensor | Landslide precursor | ~₹100-200 |
| LoRa modules (SX1278) | Long-range mesh | ~₹300-500 |

---

## 4. Why ULTRON Is a Genuine Advantage

This is the **strongest architectural fit on the entire list** — the platform's native use case. Distributed edge nodes, offline resilience, alerting — exactly what ULTRON already exercises.

**Sponsor platform note:** Qualcomm may expect Snapdragon/Dragonwing hardware. Pre-empt by framing ULTRON as the low-cost field-node layer, silicon-agnostic and portable to Dragonwing at production scale.
