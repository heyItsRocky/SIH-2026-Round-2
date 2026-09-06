# SIH26025 — Failure Modes

> What can go wrong, and what does the system do?

---

## 1. Failure Mode Analysis

| Failure | What happens | System response | Severity |
|---|---|---|---|
| **Sensor fails** | No data from one sensor | Flag node degraded; use neighbors for correlation | Med |
| **Node dies** | No data from one node | Flag node offline; mesh continues | Med |
| **Network disappears** | No mesh connectivity | Local buffering; local alerts still fire | Low |
| **Power disappears** | Node loses power | Battery backup; graceful shutdown | Med |
| **False positive** | Alert when no real movement | Correlation reduces this; operator can dismiss | Med |
| **False negative** | Miss real movement | Multiple sensors + correlation reduces this | High |
| **Gateway fails** | Pi 4 down | Nodes buffer locally; alerts fire locally | Med |
| **Storage corruption** | Data loss | Redundant storage; periodic backup | Med |

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
Total failure → battery backup, graceful shutdown
```

---

## 3. Demo Safety

- Build a **simulated sensor feed** as fallback so one flaky accelerometer doesn't take down the whole live demo
- This is the single most likely thing to embarrass you on stage

---

# SIH26025 — Security & Reliability

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

---

## 2. Reliability

| Concern | Approach |
|---|---|
| **Data backup** | Redundant storage (SSD + flash), periodic backup |
| **Fail-safe behavior** | On gateway failure, nodes buffer + alert locally |
| **Power resilience** | Battery backup, low-power modes |
| **Watchdog** | Hardware watchdog on ESP32, auto-restart |
| **Health monitoring** | Heartbeat telemetry, node health dashboard |

---

## 3. Fail-Safe Principle

> **Fail-closed:** if the system can't confirm safety, it should alert (not stay silent).

This is critical for a safety-monitoring system — a false alarm is better than a missed event.

---

# SIH26025 — Testing & Validation

> Where the project becomes credible. Design actual experiments.

---

## 1. Test Plan

| Test | Description | What it validates |
|---|---|---|
| **Test 1** | Stable mine simulation (no disturbance) | Baseline, no false alarms |
| **Test 2** | One-node disturbance | Local detection, no false mesh alarm |
| **Test 3** | Multi-node deformation | Mesh correlation detects genuine movement |
| **Test 4** | Noisy sensor | Filtering works, no false alarm |
| **Test 5** | Network failure | Offline buffering + local alerts |
| **Test 6** | Node failure | Graceful degradation, mesh continues |

---

## 2. Metrics

| Metric | Target |
|---|---|
| Detection latency | Sub-minute (vs weekly survey-cycle baseline) |
| False-positive rate | Low (on injected fault tests) |
| False-negative rate | Near-zero (fail-closed) |
| Packet loss | Low (mesh reliability) |
| Correlation accuracy | High (distinguishes local vs genuine) |
| System uptime | High (graceful degradation) |

---

## 3. Validation Approach

- **Physical scale-model rig** — motorized platform tilting a sensor node to simulate ground movement
- **Public InSAR case-study data** — validate prediction/alerting logic on real published subsidence events
- **Synthetic fault injection** — inject simulated deformation events, measure detection

---

## 4. Honesty

Be upfront that this is a **decision-support early-indicator**, not a certified structural-safety instrument. Judges respect "prototype compression" done honestly far more than a demo that implies live mine data it doesn't have.

---

# SIH26025 — Demo Plan

> Literally script the live demonstration. The judge should see the system working, not watch someone click around a dashboard.

---

## ⚠ ZERO-BUDGET DEMO (READ FIRST)

> **No budget for physical sensors.** The demo uses the **software sensor simulator as the PRIMARY transducer layer** — this is a feature, not a fallback. See `SIH_2026/00_MASTER/ZERO_BUDGET_STRATEGY.md`.

**What the judge sees:**
- **REAL** distributed mesh (Pi 3A+, Pi 3B+, Pi 4, ESP32s on the switch)
- **REAL** MQTT pipeline + edge AI + mesh correlation + dashboard + alerting
- **SIMULATED** transducer layer (tilt/vibration/displacement/crack) via the sensor simulator
- **REAL** free signals: tripwire GPIO as a physical crack trigger, CPU temp as telemetry

**Demo framing:** "We built the complete distributed subsidence-intelligence network for real. The transducer layer is simulated because we had no budget — but the mesh, edge AI, correlation, and alerting are fully functional and sensor-agnostic. Plug in any transducer and it works identically."

The script below uses the simulator to trigger precise scenarios (single-node disturbance vs multi-node deformation) — reliable and repeatable on stage.

---

## 1. Demo Script

```
0:00 → Explain the problem (30 sec)
       "Underground coal mining causes surface subsidence. Current monitoring is
        periodic manual survey — no continuous signal between visits."

0:30 → Show physical nodes (30 sec)
       "Here are our distributed sensor nodes — tilt, vibration, displacement,
        crack detection, mesh-networked to the Pi 4 gateway."

1:00 → Disturb one node (5 sec)
       Physically tilt/vibrate Node A.

1:05 → Dashboard detects movement (10 sec)
       "Node A shows deviation. But is this real ground movement or a local
        disturbance? Watch the correlation."

1:15 → Show neighboring-node comparison (15 sec)
       "Nodes B, C, D are stable. Correlation score is low. This is a LOCAL
        disturbance, not subsidence. No false alarm."

1:30 → Trigger simulated deformation (10 sec)
       Tilt multiple adjacent nodes together.

2:00 → Alert generated (30 sec)
       "Multiple adjacent nodes deviating in a correlated pattern — this is
        genuine ground movement. RED alert. GPIO alarm fires, OLED shows warning,
        SMS/email sent."

2:30 → Show offline capability (30 sec)
       "Now we disconnect the network. The system keeps monitoring locally,
        buffers data, and alerts fire on-site. On reconnect, data syncs."

3:00 → Close (30 sec)
       "Survey-based monitoring is accurate but not continuous. We add a
        continuous, local, offline layer between survey cycles."
```

---

## 2. Key Demo Principles

1. **Show the system working** — not clicking around a dashboard
2. **Demonstrate the differentiator** — mesh correlation (local vs genuine)
3. **Show offline capability** — the hidden constraint
4. **Keep it under 4 minutes** — judges have limited attention
5. **Have a fallback** — simulated sensor feed if hardware fails

---

## 3. What Judges Should Remember

> "They built a distributed mesh that distinguishes local disturbance from genuine ground movement, and it works offline."

---

# SIH26025 — Deployment & Scalability

> Prototype → pilot → scale. Cost, maintenance, connectivity, calibration.

---

## 1. Scale Path

```
3 nodes (prototype)
    ↓
100 nodes (mine pilot)
    ↓
1000 nodes (multiple mines)
```

```
Prototype (scale model)
    ↓
Mine pilot (one CIL subsidiary site)
    ↓
Multiple mines (CIL subsidiaries)
```

---

## 2. Deployment Considerations

| Factor | Prototype | Pilot | Scale |
|---|---|---|---|
| **Node density** | 3-4 nodes | 20-50 nodes | 100-1000 nodes |
| **Network** | Lab mesh | Mine-local mesh | Multi-mine mesh |
| **Maintenance** | Manual | Scheduled | Remote + scheduled |
| **Connectivity** | Lab Wi-Fi | Mine Wi-Fi/LoRa | LoRa + cellular |
| **Calibration** | Manual | Semi-automated | Automated |
| **Battery/power** | USB | Battery + solar | Solar + mains |
| **Hardware replacement** | Easy | Moderate | Logistics needed |

---

## 3. Cost Per Node (target)

| Component | Cost |
|---|---|
| ESP32-C3 | ~₹300 |
| Sensors (tilt/vibration) | ~₹300 |
| Enclosure | ~₹200 |
| Power (battery/solar) | ~₹300 |
| **Total per node** | **~₹1,100** |

Compare: InSAR/GNSS survey costs are orders of magnitude higher.

---

## 4. Institutional Owner

**CMPDI** already operates a dedicated remote-sensing/GIS/LiDAR/drone group serving Coal India subsidiaries — a named, existing organizational home for a pilot.
---

# SIH26025 — Cost & BOM

> Actual Bill of Materials.

---

## ⚠ ZERO-BUDGET MODE (READ FIRST)

> **We have no budget to purchase sensors.** See `SIH_2026/00_MASTER/ZERO_BUDGET_STRATEGY.md`.

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

**Real free signals used:** tripwire GPIO (physical crack/event trigger), CPU temperature (real telemetry stream).

The BOM below (with purchased sensors) is the **aspirational production version** — NOT what we build for the hackathon.

---

## 1. Bill of Materials (Aspirational / Production — NOT for hackathon)

| Component | Qty | Unit Cost | Total | Purpose | Availability | Alternative |
|---|---|---|---|---|---|---|
| ESP32-C3 DevKit | 2 | ₹300 | ₹600 | Sensor nodes | Widely available | ESP32-WROOM |
| ESP32-WROOM-32 | 2 | ₹400 | ₹800 | Sensor nodes | Widely available | ESP32-C3 |
| MPU6050 (tilt) | 2 | ₹150 | ₹300 | Tilt detection | Widely available | BNO055 |
| ADXL345 (vibration) | 2 | ₹200 | ₹400 | Vibration detection | Widely available | SW-420 |
| Potentiometer (displacement) | 1 | ₹100 | ₹100 | Displacement | Widely available | Strain gauge |
| Crack sensor | 2 | ₹100 | ₹200 | Crack detection | Widely available | Resistive |
| GPS (NEO-6M) | 1 | ₹300 | ₹300 | Positioning | Widely available | — |
| LoRa modules (SX1278) | 4 | ₹300 | ₹1,200 | Mesh comms | Widely available | Zigbee |
| OLED Display | 1 | ₹200 | ₹200 | Status display | Already owned | — |
| NeoPixel | 1 | ₹100 | ₹100 | Visual alert | Already owned | — |
| Enclosures | 4 | ₹200 | ₹800 | Protection | Widely available | 3D-printed |
| Battery + solar | 4 | ₹300 | ₹1,200 | Power | Widely available | USB power |
| Wiring, connectors | — | ₹500 | ₹500 | Connections | Widely available | — |
| **Total** | | | **~₹6,700** | | | |

---

## 2. Cost Comparison

| System | Cost |
|---|---|
| **Our mesh (4 nodes)** | **~₹6,700** |
| InSAR/GNSS survey | Orders of magnitude higher |
| Slope Stability Radar | Very high (₹lakhs+) |
| CSIR Goafwarn | Proprietary, not broadly available |

---

## 3. Budget Notes

- Most components already owned (Pi 4, Pi 3s, ESP32s, OLED, NeoPixel, switch, SSD)
- New purchases: sensors (~₹1,300), LoRa (~₹1,200), enclosures/power (~₹2,000)
- Total new spend: **~₹4,500-6,700**
---

# SIH26025 — Differentiation Strategy

> What others will build, why that's limited, our approach, why it's better, evidence.

---

## 1. What Others Will Build

Most teams will build:
- A single-node tilt/vibration sensor with a threshold alarm
- A dashboard showing sensor readings
- Possibly a satellite-image CNN for "AI slope monitoring"

**They miss the mesh aspect entirely.**

---

## 2. Why That Approach Is Limited

- Single-sensor thresholds can't distinguish local disturbance from genuine ground movement
- Satellite imagery has multi-day revisit latency — can't give a mine control room a live alarm
- No offline capability — cloud dashboard is useless without internet
- No mesh-level deformation correlation — the actual differentiator the sponsor names

---

## 3. Our Approach

**Wireless Surface Mesh Network for Real-Time Subsidence Detection**

- Distributed ESP32 sensor nodes in a mesh
- **Mesh-level deformation correlation** — compare nodes against neighbors
- Edge AI anomaly detection on Pi 4 (offline-capable)
- Local GPIO/OLED/NeoPixel alerting
- Offline buffering + periodic cloud sync

---

## 4. Why It Is Better

| Dimension | Others | Us |
|---|---|---|
| Detection | Single-sensor threshold | Mesh correlation |
| Latency | Satellite revisit (days) | Sub-minute local |
| Offline | No | Yes (core feature) |
| Cost | Expensive (InSAR/GNSS) | Cheap ESP32 nodes |
| Alerting | Cloud dashboard | Local + remote |

---

## 5. Evidence

- DGMS mandates slope monitoring (2020 circular) — regulatory tailwind
- SSR exists only for opencast pits — underground subsidence unaddressed
- CSIR Goafwarn is proprietary and not broadly available
- The PS text itself names "relative distance between nodes" as the differentiator

---

## 6. One-Sentence Pitch

> **"Survey-based monitoring is accurate but not continuous; we add a continuous, local, offline mesh layer between survey cycles."**
---

