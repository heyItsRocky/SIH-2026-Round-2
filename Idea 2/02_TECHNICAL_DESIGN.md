# SIH26178 — Tech Stack

> Technology choices, difficulty, team familiarity, learning curve, integration risk.

---

## 1. Technology Stack

| Layer | Technology | Why needed | Difficulty | Team familiarity | Learning curve | Integration risk | Failure risk |
|---|---|---|---|---|---|---|---|
| **Hardware** | ESP32-C3/WROOM, Pi 4, sensors | Distributed sensing + edge processing | Med | High | Low | Low | Low |
| **Firmware** | ESP-IDF / Arduino | Sensor interface, mesh comms | Med | High | Low | Low | Low |
| **Networking** | LoRa/Zigbee/Wi-Fi mesh, MQTT | Node-to-gateway comms | Med | High | Low-Med | Med | Med |
| **Edge AI** | TFLite Micro / scikit-learn | On-device inference | Med-High | Med-Unknown | Med-High | Med | Med |
| **Backend** | Python (FastAPI) | API, data aggregation | Med | High | Low | Low | Low |
| **Database** | SQLite / InfluxDB | Time-series storage | Low | Med | Low | Low | Low |
| **Dashboard** | Web (React/Plotly) + GIS | Visualization, risk maps | Med | Med | Med | Med | Med |
| **Alert integration** | SACHET/CAP API | Feed national alert bus | Med | Low-Unknown | Med | Med-High | Med |
| **Security** | Auth, TLS, node identity | Secure comms | Low-Med | Med | Low | Low | Low |

---

## 2. Difficulty Scores

```
Intrinsic Technical Difficulty:      6/10 (sensor-only: 5/10)
Team-Adjusted Difficulty:            5-6/10 (sensor-only: 3/10)
Stack Breadth:                       High (broadest)
Team Familiarity:                    High (embedded/network) / Medium-Unknown (edge AI, SACHET)
Learning Curve:                      Medium
Integration Difficulty:              Medium-High
Debugging Difficulty:                Medium-High (CV debugging is slow)
Hardware–Software Coupling:          High
Infrastructure Requirement:          Low
External Dependency Risk:            Medium (SACHET/CAP API)
36-Hour Feasibility:                 Medium (High if scope cut to one hazard)
Failure Surface:                     Medium-High (more moving parts)
Prototype Compression:               Medium
ULTRON Compatibility:                Very High
```

---

## 3. Key Insight

The stack is the **broadest** of any candidate — the "AI-powered" framing pushes toward computer vision (flame/smoke detection), which is a real, currently-unproven skill for this team.

**There's a lower-difficulty path:** sensor-only with a lightweight fusion classifier. It's less visually dramatic but keeps the project in the "genuine problem difficulty" bucket rather than the "impressive but fragile" bucket.

**Recommendation:** Keep the sensor-only route as the default plan; treat vision as a stretch goal only if bench time allows.

---

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

---

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

---

# SIH26178 — Circuit Design

> Actual electronics documentation: pin mapping, power rails, GPIO, sensor connections.

---

## 1. ESP32-C3 Node Circuit (Fire Node)

```
ESP32-C3 Mini DevKit
    │
    ├── GPIO5 ──► SDA ──► DHT22 (temp/humidity)
    ├── GPIO6 ──► SCL ──► DHT22 (temp/humidity)
    ├── GPIO7 ──► Analog ──► MQ-2 (smoke)
    ├── GPIO9 ──► DATA ──► NeoPixel (alert)
    ├── 3V3 ────────────► Sensors VCC
    ├── GND ────────────► Sensors GND
    └── USB ────────────► Pi 4 (power + serial)
```

---

## 2. ESP32-WROOM Node Circuit (Air Quality Node)

```
ESP32-WROOM-32
    │
    ├── GPIO16 ──► TX ──► PMS5003 (PM2.5/PM10)
    ├── GPIO17 ──► RX ──► PMS5003 (PM2.5/PM10)
    ├── GPIO34 ──► Analog ──► MQ-135 (gas)
    ├── GPIO21 ──► SDA ──► DHT22 (temp/humidity)
    ├── GPIO22 ──► SCL ──► DHT22 (temp/humidity)
    ├── 3V3 ────────────► Sensors VCC
    ├── GND ────────────► Sensors GND
    └── USB ────────────► Pi 4 (power + serial)
```

---

## 3. Power Rails

| Rail | Source | Devices |
|---|---|---|
| 5V | Pi 4 USB / GPIO pin 4 | ESP32s, sensors |
| 3.3V | ESP32 regulator | Sensors, OLED |
| GND | Common ground | All |

---

## 4. Grounding & Protection

- **Shared ground** across all nodes (verify before power-on)
- **Pull-up resistors** on tripwire inputs (active-low)
- **Decoupling capacitors** on sensor power rails
- **ESD protection** on exposed sensor lines
- **Solar charging circuit** for remote deployment (future)

---

## 5. Verification Checklist

- [ ] Shared tripwire ground verified
- [ ] NeoPixel power/ground correct
- [ ] UART pin mapping correct (PMS5003)
- [ ] Sensor I2C addresses don't conflict
- [ ] Power budget within Pi 4 USB limits

---

# SIH26178 — Node Architecture

> Define exactly what one environmental node looks like.

---

## 1. Single Node Architecture

```
Sensors (smoke, temp, humidity, PM2.5, gas, water level)
    ↓
ESP32 (local processing, sampling, filtering)
    ↓
Communication (mesh: LoRa/Zigbee/Wi-Fi)
    ↓
Gateway (Pi 4)
    ↓
Edge AI + Dashboard
```

---

## 2. Node Definitions (Fire MVP)

### Node A (Pi 3A+ + ESP32-C3)
- **Role:** Fire detection
- **Sensors:** MQ-2 (smoke), DHT22 (temp/humidity)
- **Comms:** Ethernet to switch, MQTT to Pi 4
- **Alert:** Local NeoPixel

### Node B (Pi 3B + ESP32-WROOM)
- **Role:** Air quality + fire
- **Sensors:** PMS5003 (PM2.5/PM10), MQ-135 (gas), DHT22
- **Comms:** Ethernet to switch, MQTT to Pi 4
- **Alert:** Local OLED

### Node C (ESP32-C3 standalone)
- **Role:** Fire detection (redundant)
- **Sensors:** MQ-2 (smoke), DHT22 (temp/humidity)
- **Comms:** Wi-Fi mesh, MQTT to Pi 4
- **Alert:** NeoPixel

### Node D (ESP32-WROOM standalone)
- **Role:** Heat + dryness precursor
- **Sensors:** DHT22 (temp/humidity), soil moisture
- **Comms:** Wi-Fi mesh, MQTT to Pi 4
- **Alert:** OLED

---

## 3. Node Responsibilities

Each node:
1. Samples sensors at configurable rate
2. Filters noise (moving average, median filter)
3. Extracts features (mean, variance, peak)
4. Runs on-device edge AI inference (TFLite Micro)
5. Transmits only critical alerts + summarized insights
6. Buffers locally if network unavailable
7. Triggers local alert on threshold breach

---

# SIH26178 — Network Communication

> Protocol, message format, node IDs, packet structure, sync, retry, offline behavior.

---

## 1. Network Topology

```
Node A ──┐
Node B ──┼── Mesh ──► Gateway (Pi 4) ──► Local Server ──► Dashboard
Node C ──┘
Node D ──┘
```

---

## 2. Protocol

- **Mesh:** LoRa/Zigbee/Wi-Fi mesh between nodes
- **Gateway uplink:** Ethernet/Wi-Fi to Pi 4
- **Telemetry:** MQTT (paho-mqtt)
- **Broker:** mosquitto on Pi 4

---

## 3. Message Format

```json
{
  "node_id": "node_A",
  "timestamp": "2026-09-06T12:00:00Z",
  "sensor_type": "smoke",
  "value": 0.42,
  "unit": "ppm",
  "confidence": 0.95,
  "alert_level": "GREEN"
}
```

---

## 4. MQTT Topics

| Topic | Direction | Payload |
|---|---|---|
| `env/node/{id}/data` | Node → Gateway | Sensor readings |
| `env/node/{id}/status` | Node → Gateway | Heartbeat, health |
| `env/gateway/alert` | Gateway → All | Alert level |
| `env/dashboard/update` | Gateway → Dashboard | Aggregated data |
| `env/sachet/push` | Gateway → SACHET | CAP alert push |

---

## 5. Node IDs

- `node_A`, `node_B`, `node_C`, `node_D` (or numeric: `node_01`...)

---

## 6. Packet Structure

```
[Header: node_id, timestamp, seq]
[Payload: sensor readings + edge AI result]
[Checksum: CRC]
```

---

## 7. Synchronization

- Nodes timestamp locally (NTP sync when online)
- Gateway correlates timestamps across nodes
- Periodic clock sync on reconnect

---

## 8. Retry Behavior

- MQTT QoS 1 (at-least-once) for critical alerts
- QoS 0 for routine telemetry
- Local buffering + replay on reconnect

---

## 9. Offline Behavior

- Nodes run on-device edge AI locally
- Nodes buffer locally (SD/flash)
- Gateway continues edge AI locally
- Alerts fire locally (GPIO, OLED, NeoPixel)
- On reconnect: sync buffered data, reconcile timestamps

---

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

---

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

---

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

---

# SIH26178 — System Architecture

> The one master architecture.

---

## 1. Master Architecture

```
                    ┌─────────────────────────────────────────────┐
                    │            DEPLOYMENT AREA                 │
                    │                                             │
   ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐        │
   │ Node A   │  │ Node B   │  │ Node C   │  │ Node D   │        │
   │ Fire     │  │ Air Qual │  │ Fire     │  │ Heat/Dry │        │
   │ Smoke+Temp│ │ PM2.5+Gas│  │ Smoke+Temp│ │ Temp+Soil│        │
   └────┬─────┘  └────┬─────┘  └────┬─────┘  └────┬─────┘        │
        │             │             │             │              │
        └─────────────┼─────────────┼─────────────┘              │
                      │   Mesh (LoRa/Zigbee/Wi-Fi)               │
                      ▼                                          │
              ┌───────────────┐                                  │
              │   Gateway     │                                  │
              │   (Pi 4)      │                                  │
              └───────┬───────┘                                  │
                      │                                          │
        ┌─────────────┼─────────────┐                            │
        ▼             ▼             ▼                            │
┌─────────────┐ ┌─────────────┐ ┌─────────────┐                 │
│ Local       │ │ Edge AI     │ │ GPIO Alarm  │                 │
│ Storage     │ │ Anomaly     │ │ OLED/NeoPix │                 │
│ (SSD)       │ │ Detection   │ │ (on-site)   │                 │
└─────────────┘ └──────┬──────┘ └─────────────┘                 │
                       │                                         │
                       ▼                                         │
              ┌───────────────┐                                  │
              │  Dashboard    │                                  │
              │  (GIS + Risk) │                                  │
              └───────┬───────┘                                  │
                      │ (when online)                            │
                      ▼                                          │
              ┌───────────────┐                                  │
              │ SACHET/CAP    │                                  │
              │ Alert Push    │                                  │
              └───────────────┘                                  │
                    └────────────────────────────────────────────┘
```

---

## 2. Data Flow

```
Sensors → ESP32 Nodes → Mesh → Gateway (Pi 4) → Local Storage → Edge AI → Dashboard → SACHET/CAP
```

---

## 3. Key Design Principles

1. **Offline-first** — everything works without internet
2. **On-device AI** — edge inference, not cloud dependency
3. **Multi-sensor fusion** — the fire differentiator
4. **Mesh correlation** — distinguishes local vs genuine hazard
5. **SACHET/CAP integration** — feed national alert bus, not a redundant app
6. **Graceful degradation** — one sensor/node failure doesn't kill the system

---

