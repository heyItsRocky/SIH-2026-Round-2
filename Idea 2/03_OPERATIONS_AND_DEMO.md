# SIH26178 — Failure Modes

> What can go wrong, and what does the system do?

---

## 1. Failure Mode Analysis

| Failure | What happens | System response | Severity |
|---|---|---|---|
| **Sensor fails** | No data from one sensor | Flag node degraded; use neighbors for correlation | Med |
| **Node dies** | No data from one node | Flag node offline; mesh continues | Med |
| **Network disappears** | No mesh connectivity | Local buffering; local alerts still fire | Low |
| **Power disappears** | Node loses power | Battery backup; graceful shutdown | Med |
| **False positive** | Alert when no real hazard | Multi-sensor fusion + correlation reduces this | Med |
| **False negative** | Miss real hazard | Multiple sensors + correlation reduces this | High |
| **Gateway fails** | Pi 4 down | Nodes buffer locally; alerts fire locally | Med |
| **Storage corruption** | Data loss | Redundant storage; periodic backup | Med |
| **SACHET/CAP API down** | Alert push fails | Local alerts still fire; retry on reconnect | Med |
| **Outdoor conditions** | Rain/dust/sun damage | Weatherproof enclosure; solar power | Med |

---

## 2. Graceful Degradation Path

```
All systems normal
    ↓
One sensor fails → flag degraded, use neighbors
    ↓
One node dies → flag offline, mesh continues
    ↓
Network down → local buffering + local alerts
    ↓
Gateway down → nodes buffer + local alerts
    ↓
SACHET down → local alerts + retry on reconnect
    ↓
Total failure → battery backup, graceful shutdown
```

---

## 3. Demo Safety

- Build a **simulated sensor feed** as fallback so one flaky smoke sensor doesn't take down the whole live demo
- This is the single most likely thing to embarrass you on stage
- Outdoor conditions are unpredictable — test indoors with a smoke source (incense/smoke generator)

---

# SIH26178 — Security & Reliability

> Authentication, data integrity, node identity, communication security, tamper detection, fail-safe.

---

## 1. Security

| Concern | Approach |
|---|---|
| **Node authentication** | Unique node ID + shared secret / TLS client cert |
| **Communication security** | TLS for MQTT, encrypted mesh |
| **Data integrity** | Checksums, sequence numbers, tamper-evident logging |
| **Node identity** | Hardware ID burned at provisioning |
| **Tamper detection** | Physical tamper switch, alert on removal |
| **Firmware updates** | Signed firmware, OTA with verification |
| **Alert authenticity** | Signed CAP alerts to prevent spoofed warnings |

---

## 2. Reliability

| Concern | Approach |
|---|---|
| **Data backup** | Redundant storage (SSD + flash), periodic backup |
| **Fail-safe behavior** | On gateway failure, nodes buffer + alert locally |
| **Power resilience** | Battery backup, solar charging, low-power modes |
| **Watchdog** | Hardware watchdog on ESP32, auto-restart |
| **Health monitoring** | Heartbeat telemetry, node health dashboard |
| **Weatherproofing** | Enclosures rated for outdoor deployment |

---

## 3. Fail-Safe Principle

> **Fail-closed:** if the system can't confirm safety, it should alert (not stay silent).

This is critical for a disaster-monitoring system — a false alarm is better than a missed event.

---

# SIH26178 — Testing & Validation

> Where the project becomes credible. Design actual experiments.

---

## 1. Test Plan

| Test | Description | What it validates |
|---|---|---|
| **Test 1** | Stable environment (no hazard) | Baseline, no false alarms |
| **Test 2** | Smoke source near one node | Local detection, fusion score |
| **Test 3** | Smoke source near multiple nodes | Mesh correlation detects genuine hazard |
| **Test 4** | False alarm source (e.g., cooking gas) | Multi-sensor fusion filters false alarm |
| **Test 5** | Network failure | Offline buffering + local alerts |
| **Test 6** | Node failure | Graceful degradation, mesh continues |
| **Test 7** | SACHET/CAP push | Alert integration works |

---

## 2. Metrics

| Metric | Target |
|---|---|
| Detection latency | Sub-minute (vs satellite revisit baseline) |
| False-positive rate | Low (on injected fault tests) |
| False-negative rate | Near-zero (fail-closed) |
| Packet loss | Low (mesh reliability) |
| Fusion accuracy | High (distinguishes fire from false alarm) |
| Correlation accuracy | High (distinguishes local vs genuine) |
| System uptime | High (graceful degradation) |

---

## 3. Validation Approach

- **Physical test rig** — smoke source (incense/smoke generator) near sensor nodes
- **Public fire/air-quality case-study data** — validate detection logic on real published events
- **Synthetic fault injection** — inject simulated hazard events, measure detection

---

## 4. Honesty

Be upfront that this is a **prototype compression** — a decision-support early-indicator, not a certified disaster-monitoring instrument. Judges respect "prototype compression" done honestly far more than a demo that implies live field data it doesn't have.

---

# SIH26178 — Demo Plan

> Literally script the live demonstration. The judge should see the system working, not watch someone click around a dashboard.

---

## ⚠ ZERO-BUDGET DEMO (READ FIRST)

> **No budget for physical sensors.** The demo uses the **software sensor simulator as the PRIMARY transducer layer** — this is a feature, not a fallback. See `master files/ZERO_BUDGET_STRATEGY.md`.

**What the judge sees:**
- **REAL** distributed mesh (Pi 3A+, Pi 3B+, Pi 4, ESP32s on the switch)
- **REAL** MQTT pipeline + edge AI + multi-sensor fusion + correlation + dashboard + alerting
- **SIMULATED** transducer layer (smoke/temp/humidity/PM2.5/water level) via the sensor simulator
- **REAL** free signals: CPU temperature on each Pi (real environmental temperature stream), tripwire GPIO

**Demo framing:** "We built the complete distributed environmental-intelligence network for real. The transducer layer is simulated because we had no budget — but the mesh, edge AI, multi-sensor fusion, and alerting are fully functional and sensor-agnostic. Plug in any transducer and it works identically."

The script below uses the simulator to trigger precise scenarios (single-node smoke vs multi-node fire signature) — reliable and repeatable on stage.

---

## 1. Demo Script

```
0:00 → Explain the problem (30 sec)
       "India faces floods, fires, pollution, heat. Satellite monitoring is
        accurate but not local or real-time. Villages and wards have no
        minutes-not-hours ground truth."

0:30 → Show physical nodes (30 sec)
       "Here are our distributed sensor nodes — smoke, temperature, humidity,
        PM2.5, gas. Mesh-networked to the Pi 4 gateway. Each node runs
        on-device AI inference."

1:00 → Trigger smoke near one node (10 sec)
       Light incense/smoke generator near Node A.

1:10 → Dashboard detects smoke (10 sec)
       "Node A shows elevated smoke. But is this a fire or a false alarm?
        Watch the fusion score."

1:20 → Show fusion + correlation (20 sec)
       "Smoke is high, but temperature is normal and humidity is normal.
        Fusion score is low. Neighboring nodes are stable. This is a LOCAL
        disturbance, not a fire. No false alarm."

1:40 → Trigger simulated fire (10 sec)
       Smoke + heat + low humidity across multiple adjacent nodes.

2:00 → Alert generated (30 sec)
       "Multiple adjacent nodes showing correlated smoke + heat + dryness —
        this is a genuine fire signature. RED alert. GPIO alarm fires, OLED
        shows warning, SACHET/CAP push to NDMA."

2:30 → Show offline capability (30 sec)
       "Now we disconnect the network. The system keeps monitoring locally,
        runs on-device AI, buffers data, and alerts fire on-site. On
        reconnect, data syncs."

3:00 → Close (30 sec)
       "Satellite monitoring is accurate but not local or real-time. We add a
        dense, low-cost, offline-capable local sensing layer that feeds
        NDMA's existing alert infrastructure."
```

---

## 2. Key Demo Principles

1. **Show the system working** — not clicking around a dashboard
2. **Demonstrate the differentiator** — multi-sensor fusion + mesh correlation
3. **Show offline capability** — the hidden constraint
4. **Show SACHET/CAP integration** — the insight most teams miss
5. **Keep it under 4 minutes** — judges have limited attention
6. **Have a fallback** — simulated sensor feed if hardware fails

---

## 3. What Judges Should Remember

> "They built a distributed mesh that distinguishes a real fire from a false alarm using multi-sensor fusion, works offline, and feeds NDMA's existing alert infrastructure."

---

# SIH26178 — Deployment & Scalability

> Prototype → pilot → scale. Cost, maintenance, connectivity, calibration.

---

## 1. Scale Path

```
4 nodes (prototype)
    ↓
100 nodes (city/forest pilot)
    ↓
1000 nodes (multi-region)
```

```
Prototype (lab)
    ↓
City/forest pilot (one SDMA region)
    ↓
Multi-region (multiple SDMAs)
```

---

## 2. Deployment Considerations

| Factor | Prototype | Pilot | Scale |
|---|---|---|---|
| **Node density** | 4 nodes | 20-50 nodes | 100-1000 nodes |
| **Network** | Lab mesh | City/forest mesh | Multi-region mesh |
| **Maintenance** | Manual | Scheduled | Remote + scheduled |
| **Connectivity** | Lab Wi-Fi | LoRa + cellular | LoRa + cellular |
| **Calibration** | Manual | Semi-automated | Automated |
| **Battery/power** | USB | Battery + solar | Solar + mains |
| **Hardware replacement** | Easy | Moderate | Logistics needed |

---

## 3. Cost Per Node (target)

| Component | Cost |
|---|---|
| ESP32-C3 | ~₹300 |
| Sensors (smoke/temp/humidity) | ~₹350 |
| Enclosure (weatherproof) | ~₹300 |
| Power (battery + solar) | ~₹500 |
| **Total per node** | **~₹1,450** |

Compare: commercial IoT environmental stations cost orders of magnitude more.

---

## 4. Institutional Owner

**SDMAs** (State Disaster Management Authorities) are the primary users. **NDMA** owns the SACHET/CAP alert infrastructure we feed into. **FSI** is the forest-fire institutional owner for the fire MVP.

---

# SIH26178 — Cost & BOM

> Actual Bill of Materials.

---

## ⚠ ZERO-BUDGET MODE (READ FIRST)

> **We have no budget to purchase sensors.** See `master files/ZERO_BUDGET_STRATEGY.md`.

**Zero-budget BOM (what we actually build with):**

| Item | Cost |
|---|---|
| Raspberry Pi 4B 8GB (gateway) | ₹0 (owned) |
| Raspberry Pi 3A+ (node) | ₹0 (owned) |
| Raspberry Pi 3B+ v1.2 (node) | ₹0 (owned) |
| 2× ESP32-C3-DevKitM-1 | ₹0 (owned) |
| 1× ESP32-WROOM-32 | ₹0 (owned) |
| 5-port Ethernet switch | ₹0 (owned) |
| 1" I2C OLED | ₹0 (owned) |
| NeoPixel (C3 GPIO8) | ₹0 (owned) |
| AC600 + TL-WN722N Wi-Fi | ₹0 (owned) |
| 500GB SSD + 128GB flash | ₹0 (owned) |
| 4-port USB hub | ₹0 (owned) |
| Software sensor simulator | ₹0 (we build it) |
| **Total new spend** | **₹0** |

**Real free signals used:** CPU temperature on each Pi (real environmental temperature stream), tripwire GPIO (real event trigger).

The BOM below (with purchased sensors) is the **aspirational production version** — NOT what we build for the hackathon.

---

## 1. Bill of Materials (Aspirational / Production — NOT for hackathon)

| Component | Qty | Unit Cost | Total | Purpose | Availability | Alternative |
|---|---|---|---|---|---|---|
| ESP32-C3 DevKit | 2 | ₹300 | ₹600 | Sensor nodes | Widely available | ESP32-WROOM |
| ESP32-WROOM-32 | 2 | ₹400 | ₹800 | Sensor nodes | Widely available | ESP32-C3 |
| MQ-2 smoke sensor | 2 | ₹150 | ₹300 | Fire/smoke detection | Widely available | MQ-7 |
| DHT22 temp/humidity | 3 | ₹100 | ₹300 | Heat/humidity | Widely available | DHT11 |
| PMS5003 PM2.5/PM10 | 1 | ₹1000 | ₹1,000 | Air quality | Widely available | SDS011 |
| MQ-135 gas sensor | 1 | ₹200 | ₹200 | Air quality/industrial | Widely available | MQ-7 |
| Soil moisture sensor | 1 | ₹150 | ₹150 | Landslide precursor | Widely available | — |
| LoRa modules (SX1278) | 4 | ₹300 | ₹1,200 | Mesh comms | Widely available | Zigbee |
| OLED Display | 1 | ₹200 | ₹200 | Status display | Already owned | — |
| NeoPixel | 1 | ₹100 | ₹100 | Visual alert | Already owned | — |
| Weatherproof enclosures | 4 | ₹300 | ₹1,200 | Protection | Widely available | 3D-printed |
| Battery + solar | 4 | ₹500 | ₹2,000 | Power | Widely available | USB power |
| Wiring, connectors | — | ₹500 | ₹500 | Connections | Widely available | — |
| **Total** | | | **~₹8,550** | | | |

---

## 2. Cost Comparison

| System | Cost |
|---|---|
| **Our mesh (4 nodes)** | **~₹8,550** |
| Commercial IoT environmental station | ₹lakhs+ per station |
| IMD/ISRO satellite monitoring | National-scale, very high |
| CPCB air quality station | High per station |

---

## 3. Budget Notes

- Most components already owned (Pi 4, Pi 3s, ESP32s, OLED, NeoPixel, switch, SSD)
- New purchases: sensors (~₹1,950), LoRa (~₹1,200), enclosures/power (~₹3,200)
- Total new spend: **~₹6,000-8,550**

---

# SIH26178 — Differentiation Strategy

> What others will build, why that's limited, our approach, why it's better, evidence.

---

## 1. What Others Will Build

Most teams will build:
- A single-hazard sensor node with a threshold alarm
- A dashboard showing sensor readings
- Possibly a satellite-image CNN for "AI environmental monitoring"
- A standalone alert app

**They miss the SACHET/CAP integration and the multi-sensor fusion entirely.**

---

## 2. Why That Approach Is Limited

- Single-sensor thresholds can't distinguish a real fire from a false alarm (MQ-2 cross-sensitivity)
- Satellite imagery has multi-day revisit latency — can't give a village a live alarm
- No offline capability — cloud dashboard is useless without internet
- Standalone alert apps are redundant — NDMA already has SACHET/CAP
- No mesh-level correlation — the actual differentiator

---

## 3. Our Approach

**AI-Powered Environmental Intelligence Network**

- Distributed ESP32 sensor nodes in a mesh
- **Multi-sensor fusion** — combine smoke + temp + humidity to distinguish fire from false alarm
- **On-device edge AI** — real-time anomaly detection, no continuous cloud dependency
- **Mesh-level correlation** — compare nodes against neighbors
- **Offline-capable** — local buffering + edge inference
- **SACHET/CAP integration** — feed NDMA's existing alert bus, not a redundant app

---

## 4. Why It Is Better

| Dimension | Others | Us |
|---|---|---|
| Detection | Single-sensor threshold | Multi-sensor fusion |
| Latency | Satellite revisit (days) | Sub-minute local |
| Offline | No | Yes (core feature) |
| Cost | Expensive (commercial stations) | Cheap ESP32 nodes |
| Alerting | Standalone app | SACHET/CAP integration |
| Scope | Single hazard | Multi-hazard (same architecture) |

---

## 5. Evidence

- IMD/ISRO satellite systems have revisit gaps — not minutes-not-hours
- CWC flood forecasting is regional, not ward-level
- FSI forest fire detection is satellite-based and delayed
- CPCB air quality stations are sparse
- NDMA SACHET/CAP is the existing national alert infrastructure — feed it, don't replace it

---

## 6. One-Sentence Pitch

> **"Satellite monitoring is accurate but not local or real-time; we add a dense, low-cost, offline-capable local sensing layer that feeds NDMA's existing alert infrastructure."**

---

