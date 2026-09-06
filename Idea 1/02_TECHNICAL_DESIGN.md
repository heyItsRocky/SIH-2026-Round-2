# SIH26025 — Tech Stack

> Technology choices, difficulty, team familiarity, learning curve, integration risk.

---

## 1. Technology Stack

| Layer | Technology | Why needed | Difficulty | Team familiarity | Learning curve | Integration risk | Failure risk |
|---|---|---|---|---|---|---|---|
| **Hardware** | ESP32-C3/WROOM, Pi 4, sensors | Distributed sensing + edge processing | Med | High | Low | Low | Low |
| **Firmware** | ESP-IDF / Arduino | Sensor interface, mesh comms | Med | High | Low | Low | Low |
| **Networking** | LoRa/Zigbee/Wi-Fi mesh, MQTT | Node-to-gateway comms | Med | High | Low-Med | Med | Med |
| **Backend** | Python (FastAPI) | API, data aggregation | Low-Med | High | Low | Low | Low |
| **Database** | SQLite / InfluxDB | Time-series storage | Low | Med | Low | Low | Low |
| **Dashboard** | Web (React/Plotly) + GIS | Visualization, risk maps | Med | Med | Med | Med | Med |
| **AI/ML** | scikit-learn / TensorFlow | Anomaly detection | Med | Med-Unknown | Med | Med | Med |
| **Security** | Auth, TLS, node identity | Secure comms | Low-Med | Med | Low | Low | Low |
| **Monitoring** | MQTT telemetry, health checks | System health | Low | High | Low | Low | Low |

---

## 2. Difficulty Scores

```
Intrinsic Technical Difficulty:      6/10
Team-Adjusted Difficulty:            4/10
Stack Breadth:                       Medium-High
Team Familiarity:                    High (embedded/network) / Medium-Unknown (time-series ML)
Learning Curve:                      Low-Medium
Integration Difficulty:              Medium
Debugging Difficulty:                Medium
Hardware–Software Coupling:          High
Infrastructure Requirement:          Low
External Dependency Risk:            Low
36-Hour Feasibility:                 High
Failure Surface:                     Medium (4–5 independent components)
Prototype Compression:               High
ULTRON Compatibility:                Very High
```

---

## 3. Key Insight

Every hop except the ML layer is something ULTRON's existing bill of materials already exercises. The one genuinely new skill is time-series anomaly detection — and it doesn't need to be sophisticated: a threshold/statistical-drift model or a small autoencoder is defensible.

**Genuine difficulty or tool-newness?** Mostly genuine. Getting a believable, low-noise signal out of cheap sensors and turning it into a trustworthy alert is a real engineering problem, not a "we don't know this library" problem.

---

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

> ⚠ **ZERO-BUDGET MODE:** We add **nothing** — no new sensors. See `master files/ZERO_BUDGET_STRATEGY.md`.

**For the hackathon (₹0):** The transducer layer is **software-simulated**. We use the existing mesh + real free signals:
- **Tripwire GPIO** (Pi 3A+ GPIO17 / Pi 3B+ GPIO21 → ESP32-WROOM) = real physical crack/event trigger
- **CPU temperature** on each Pi = real telemetry stream
- **NeoPixel + OLED** = real alert rendering

**Aspirational / production (future, if budget allows):**

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

---

# SIH26025 — Sensor Selection

> Which physical measurement actually represents the phenomenon we're trying to detect?

---

## ⚠ ZERO-BUDGET MODE (READ FIRST)

> **We have no budget to purchase sensors.** See `master files/ZERO_BUDGET_STRATEGY.md` for the full plan.

**What this means for SIH26025:**
- The **distributed mesh, MQTT pipeline, edge AI, correlation, dashboard, and alerting are all REAL** (built on existing Pis + ESP32s).
- The **physical transducers (tilt/vibration/displacement/crack sensors) are SIMULATED** via a high-fidelity software sensor simulator.
- We extract **real free signals** where they add credibility:
  - **Tripwire GPIO** (Pi 3A+ GPIO17 / Pi 3B+ GPIO21 → ESP32-WROOM) = a real physical "crack/event" trigger
  - **CPU temperature** on each Pi = a real continuous telemetry stream
- The simulator emits MQTT in the exact same format as a real sensor node — it's a **drop-in replacement**. Plug in a real transducer later and nothing else changes.

**Demo framing:** "We built the complete distributed subsidence-intelligence network for real. The transducer layer is simulated because we had no budget — but the mesh, edge AI, correlation, and alerting are fully functional and sensor-agnostic."

---

---

## 1. Sensor Candidates

| Sensor | Measures | Accuracy | Cost | Interface | Why use? | Risks |
|---|---|---|---|---|---|---|
| **MPU6050** | Tilt, acceleration, gyro | Good | ~₹150 | I2C | Ground tilt detection | Drift over time |
| **BNO055** | Tilt, orientation (fused) | Excellent | ~₹400 | I2C | High-accuracy tilt | Higher cost |
| **ADXL345** | Vibration, acceleration | Good | ~₹200 | I2C/SPI | Ground vibration | Noise |
| **SW-420** | Vibration (threshold) | Basic | ~₹50 | Digital | Simple vibration trigger | No analog data |
| **Potentiometer/strain gauge** | Displacement/stretch | Good | ~₹200 | Analog | Node-to-node distance | Calibration |
| **Crack sensor (resistive)** | Crack initiation | Basic | ~₹100 | Analog | Early crack detection | False positives |
| **GPS (NEO-6M)** | Node position | Good | ~₹300 | UART | Node positioning | Indoor/underground no signal |
| **DHT22** | Temp/humidity | Good | ~₹100 | Digital | Environmental context | Slow updates |

---

## 2. Selection Criteria

The important question is not "what sensors can we buy" but:

> **Which physical measurement actually represents the phenomenon we're trying to detect?**

For subsidence (ground sinking), the key signals are:
- **Tilt** — ground tilting as it deforms
- **Vibration** — unusual vibration signatures before failure
- **Displacement** — change in relative distance between nodes
- **Crack initiation** — early surface cracking

---

## 3. Recommended Sensor Set (per node)

| Node | Sensors | Purpose |
|---|---|---|
| Node A | MPU6050 (tilt) + ADXL345 (vibration) | Tilt + vibration monitoring |
| Node B | Potentiometer (displacement) + crack sensor | Displacement + crack detection |
| Node C | MPU6050 (tilt) + GPS | Tilt + positioning |
| Node D | ADXL345 (vibration) + crack sensor | Vibration + crack detection |

---

## 4. Calibration & Noise

- Cheap sensors have drift and noise — plan for calibration
- Use a physical scale-model rig to validate sensor behavior
- Multi-node correlation helps distinguish local disturbance from genuine ground movement

---

# SIH26025 — Circuit Design

> Actual electronics documentation: pin mapping, power rails, GPIO, sensor connections.

---

## 1. ESP32-C3 Node Circuit

```
ESP32-C3 Mini DevKit
    │
    ├── GPIO5 ──► SDA ──► MPU6050 (tilt)
    ├── GPIO6 ──► SCL ──► MPU6050 (tilt)
    ├── GPIO7 ──► SDA ──► ADXL345 (vibration)
    ├── GPIO8 ──► SCL ──► ADXL345 (vibration)
    ├── GPIO9 ──► DATA ──► NeoPixel (alert)
    ├── 3V3 ────────────► Sensors VCC
    ├── GND ────────────► Sensors GND
    └── USB ────────────► Pi 4 (power + serial)
```

---

## 2. ESP32-WROOM Node Circuit

```
ESP32-WROOM-32
    │
    ├── GPIO21 ──► SDA ──► Displacement sensor
    ├── GPIO22 ──► SCL ──► Displacement sensor
    ├── GPIO34 ──► Analog ──► Crack sensor
    ├── GPIO16 ──► Tripwire A (from Pi 3A+)
    ├── GPIO17 ──► Tripwire B (from Pi 3B)
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

---

## 5. Verification Checklist

- [ ] Shared tripwire ground verified
- [ ] NeoPixel power/ground correct
- [ ] UART pin mapping correct
- [ ] Sensor I2C addresses don't conflict
- [ ] Power budget within Pi 4 USB limits

---

# SIH26025 — Node Architecture

> Define exactly what one mine node looks like.

---

## 1. Single Node Architecture

```
Sensors (tilt, vibration, displacement, crack)
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

## 2. Node Definitions

### Node 1 (Pi 3A+ + ESP32-C3)
- **Role:** Tilt + vibration monitoring
- **Sensors:** MPU6050 (tilt), ADXL345 (vibration)
- **Comms:** Ethernet to switch, MQTT to Pi 4
- **Alert:** Local NeoPixel

### Node 2 (Pi 3B + ESP32-WROOM)
- **Role:** Displacement + crack monitoring
- **Sensors:** Potentiometer (displacement), crack sensor
- **Comms:** Ethernet to switch, MQTT to Pi 4
- **Alert:** Local OLED

### Node 3 (ESP32-C3 standalone)
- **Role:** Tilt + positioning
- **Sensors:** MPU6050 (tilt), GPS
- **Comms:** Wi-Fi mesh, MQTT to Pi 4
- **Alert:** NeoPixel

### Node 4 (ESP32-WROOM standalone)
- **Role:** Vibration + crack monitoring
- **Sensors:** ADXL345 (vibration), crack sensor
- **Comms:** Wi-Fi mesh, MQTT to Pi 4
- **Alert:** OLED

---

## 3. Node Responsibilities

Each node:
1. Samples sensors at configurable rate
2. Filters noise (moving average, median filter)
3. Extracts features (mean, variance, peak)
4. Transmits to gateway via MQTT
5. Buffers locally if network unavailable
6. Triggers local alert on threshold breach

---

# SIH26025 — Network Communication

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
  "sensor_type": "tilt",
  "value": 0.42,
  "unit": "degrees",
  "confidence": 0.95
}
```

---

## 4. MQTT Topics

| Topic | Direction | Payload |
|---|---|---|
| `mine/node/{id}/data` | Node → Gateway | Sensor readings |
| `mine/node/{id}/status` | Node → Gateway | Heartbeat, health |
| `mine/gateway/alert` | Gateway → All | Alert level |
| `mine/dashboard/update` | Gateway → Dashboard | Aggregated data |

---

## 5. Node IDs

- `node_A`, `node_B`, `node_C`, `node_D` (or numeric: `node_01`...)

---

## 6. Packet Structure

```
[Header: node_id, timestamp, seq]
[Payload: sensor readings]
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

- Nodes buffer locally (SD/flash)
- Gateway continues edge AI locally
- Alerts fire locally (GPIO, OLED, NeoPixel)
- On reconnect: sync buffered data, reconcile timestamps

---

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

---

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

---

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

---

# SIH26025 — System Architecture

> The one master architecture.

---

## 1. Master Architecture

```
                    ┌─────────────────────────────────────────────┐
                    │              MINE SURFACE                   │
                    │                                             │
   ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐        │
   │ Node A   │  │ Node B   │  │ Node C   │  │ Node D   │        │
   │ Tilt+Vib │  │ Disp+Crack│ │ Tilt+GPS │  │ Vib+Crack│        │
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
              └───────────────┘                                  │
                       │                                         │
                       ▼ (when online)                           │
              ┌───────────────┐                                  │
              │  Cloud Sync   │                                  │
              │  SMS/Email    │                                  │
              └───────────────┘                                  │
                    └────────────────────────────────────────────┘
```

---

## 2. Data Flow

```
Sensors → ESP32 Nodes → Mesh → Gateway (Pi 4) → Local Storage → Edge AI → Dashboard → Alert
```

---

## 3. Key Design Principles

1. **Offline-first** — everything works without internet
2. **Local alerting** — GPIO/OLED/NeoPixel fire on-site
3. **Mesh correlation** — the differentiator
4. **Graceful degradation** — one sensor/node failure doesn't kill the system
5. **Honest framing** — early anomaly detection, not validated geoscience

---

