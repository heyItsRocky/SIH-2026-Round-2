# SIH26178 — Sensor Selection

> Which physical measurement actually represents the phenomenon we're trying to detect?

---

## ⚠ ZERO-BUDGET MODE (READ FIRST)

> **We have no budget to purchase sensors.** See `SIH_2026/00_MASTER/ZERO_BUDGET_STRATEGY.md` for the full plan.

**What this means for SIH26178:**
- The **distributed mesh, MQTT pipeline, edge AI, fusion, correlation, dashboard, and alerting are all REAL** (built on existing Pis + ESP32s).
- The **physical transducers (smoke/temp/humidity/PM2.5/water level) are SIMULATED** via a high-fidelity software sensor simulator.
- We extract **real free signals** where they add credibility:
  - **CPU temperature** on each Pi (`vcgencmd measure_temp`) = a REAL continuous temperature stream — genuinely usable as an environmental "temperature" signal
  - **Tripwire GPIO** = a real digital event trigger
- The simulator emits MQTT in the exact same format as a real sensor node — it's a **drop-in replacement**. Plug in a real transducer later and nothing else changes.

**Demo framing:** "We built the complete distributed environmental-intelligence network for real. The transducer layer is simulated because we had no budget — but the mesh, edge AI, multi-sensor fusion, and alerting are fully functional and sensor-agnostic."

---

## 1. Sensor Candidates (Aspirational / Production)

| Sensor | Measures | Accuracy | Cost | Interface | Why use? | Risks |
|---|---|---|---|---|---|---|
| **Ultrasonic water level** | Water level | Good | ~₹400 | I2C/UART | Flood detection | Range limits |
| **Rain gauge (tipping bucket)** | Rainfall | Good | ~₹300 | Digital | Rainfall measurement | Calibration |
| **MQ-2 smoke sensor** | Smoke/gas | Basic | ~₹150 | Analog | Fire/smoke detection | Cross-sensitivity |
| **DHT22** | Temp/humidity | Good | ~₹100 | Digital | Heat/humidity | Slow updates |
| **PMS5003** | PM2.5/PM10 | Excellent | ~₹1000 | UART | Air quality | Higher cost |
| **MQ-135** | Air quality gas | Basic | ~₹200 | Analog | Industrial emissions | Cross-sensitivity |
| **Soil moisture** | Soil moisture | Good | ~₹150 | Analog | Landslide precursor | Corrosion |
| **Vibration (ADXL345)** | Ground vibration | Good | ~₹200 | I2C/SPI | Landslide precursor | Noise |
| **GPS (NEO-6M)** | Node position | Good | ~₹300 | UART | Node positioning | Indoor no signal |

---

## 2. Selection Criteria

The important question is not "what sensors can we buy" but:

> **Which physical measurement actually represents the phenomenon we're trying to detect?**

For the recommended **fire MVP**:
- **Smoke** — MQ-2 detects smoke particles
- **Temperature** — DHT22 detects heat rise
- **Humidity** — DHT22 detects dryness (fire precursor)

For **flood** (alternative MVP):
- **Water level** — ultrasonic sensor
- **Rainfall** — tipping bucket rain gauge

---

## 3. Recommended Sensor Set (Fire MVP)

| Node | Sensors | Purpose |
|---|---|---|
| Node A | MQ-2 (smoke) + DHT22 (temp/hum) | Fire detection |
| Node B | MQ-2 (smoke) + DHT22 (temp/hum) | Fire detection (redundant) |
| Node C | PMS5003 (PM2.5) + MQ-135 (gas) | Air quality + fire |
| Node D | DHT22 (temp/hum) + soil moisture | Heat + dryness precursor |

---

## 4. Calibration & Noise

- Cheap sensors have drift and cross-sensitivity — plan for calibration
- MQ-2 smoke sensor cross-reacts with other gases — use multi-sensor fusion
- Multi-node correlation helps distinguish genuine hazard from local disturbance
- Use a physical test rig to validate sensor behavior
