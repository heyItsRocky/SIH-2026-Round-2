# ZERO-BUDGET STRATEGY

> **Constraint:** No budget to purchase extra parts or sensors.
> **Response:** Build the entire distributed intelligence network for real; simulate only the physical sensor transducers.

---

## 1. The Core Insight

We have **no dedicated environmental/geotechnical sensors** (no MPU6050, DHT22, MQ-2, PMS5003, ultrasonic, soil moisture, LoRa, GPS). But we have a **complete, working distributed compute mesh**:

| Device | Role |
|---|---|
| Raspberry Pi 4B 8GB | Gateway, edge AI, MQTT broker, dashboard |
| Raspberry Pi 3A+ | Distributed node |
| Raspberry Pi 3B+ v1.2 | Distributed node |
| 2× ESP32-C3-DevKitM-1 | Sensor-interface / alert controller (NeoPixel on GPIO8) |
| 1× ESP32-WROOM-32 | Tripwire / alert controller |
| 5-port Ethernet switch | Mesh backbone |
| 1" I2C OLED | On-site alert display |
| NeoPixel | Visual alert |
| AC600 + TL-WN722N Wi-Fi | Wireless uplink |
| 500GB SSD + 128GB flash | Storage |
| 4-port USB hub | USB expansion |

**The strategy:** The mesh, MQTT pipeline, edge AI, dashboard, GIS, and alerting are ALL real and functional. Only the physical sensor transducers are **software-simulated** — because we had no budget for them.

---

## 2. What Is REAL vs SIMULATED

| Layer | Status |
|---|---|
| Distributed mesh (Pis + ESP32s on switch) | **REAL** |
| MQTT telemetry pipeline | **REAL** |
| Edge AI anomaly detection (Pi 4) | **REAL** |
| Multi-node correlation | **REAL** |
| Dashboard + GIS risk map | **REAL** |
| Alerting (OLED, NeoPixel, GPIO, SACHET-sim) | **REAL** |
| Offline buffering + sync | **REAL** |
| Physical sensor transducers | **SIMULATED** (software) |

---

## 3. Real Signals We Can Extract for FREE

Even without dedicated sensors, we get genuine telemetry from existing hardware:

| Signal | Source | How | Use |
|---|---|---|---|
| **CPU temperature** | Each Pi | `vcgencmd measure_temp` | Real continuous "temperature" stream — thermal/health monitoring (SIH26025, SIH26050) |
| **Tripwire GPIO** | Pi 3A+ GPIO17 / Pi 3B+ GPIO21 → ESP32-WROOM | Physical break detection | Real digital "event"/"crack" trigger (SIH26025) |
| **ESP32 internal temp** | ESP32 | `temperature_sensor` API | Crude real temperature |
| **CPU/network load** | Each Pi | `top`, `/proc/loadavg` | Proxy "activity" signal |
| **NeoPixel / OLED** | ESP32-C3 | Output | REAL alert rendering |

---

## 4. The Sensor Simulator (the "transducer" layer)

A **high-fidelity software sensor simulator** generates realistic streams for any hazard:

- **SIH26025:** tilt, vibration, displacement, crack — with realistic noise, drift, and correlated multi-node deformation events
- **SIH26050:** thermal (cold-soak/heat), vibration, RF signal strength, gimbal/IMU telemetry — with realistic high-altitude environmental signatures

The simulator:
- Emits MQTT messages in the exact same format as a real sensor node
- Supports scripted scenarios (single-node disturbance vs multi-node deformation)
- Runs on the Pi nodes, feeding the REAL pipeline
- Is a **drop-in replacement** — plug in a real sensor and nothing else changes

---

## 5. Why This Is a STRONG Pitch (not a weakness)

1. **The hard part is real.** The distributed mesh, edge AI, correlation, dashboard, and alerting are genuinely built and working.
2. **Honest framing.** "We had no budget for physical transducers, so we built a high-fidelity simulator. The entire intelligence network is real and sensor-agnostic — plug in any transducer and it works."
3. **Reliable demo.** The simulator lets us script ANY scenario precisely — no flaky hardware to embarrass us on stage.
4. **Sensor-agnostic architecture.** This is a genuine engineering virtue, not a workaround.
5. **Prototype compression done right.** Judges respect honest scope compression far more than a demo that implies hardware it doesn't have.

---

## 6. Updated BOM (Zero New Purchases)

| Item | Cost |
|---|---|
| All existing hardware (Pis, ESP32s, switch, OLED, NeoPixel, storage) | ₹0 (owned) |
| Software sensor simulator | ₹0 (we build it) |
| **Total new spend** | **₹0** |

---

## 7. Demo Narrative

> "We built the complete distributed environmental/mine-intelligence network — real mesh, real edge AI, real dashboard, real alerting. The only thing we couldn't buy was the physical sensor transducers, so we built a high-fidelity simulator that feeds the real pipeline. The architecture is sensor-agnostic: connect any transducer and it works identically."

---

## 8. What This Means for Both Ideas

Both SIH26025 and SIH26050 use the **identical zero-budget architecture**:
- Real distributed mesh (Pis + ESP32s)
- Real MQTT + edge AI + correlation + dashboard + alerting
- Simulated transducers via the sensor simulator
- Real free signals (CPU temp, tripwire GPIO) where they add credibility

The differentiators remain unchanged:
- **SIH26025:** mesh-level deformation correlation (local vs genuine)
- **SIH26050:** environmental hardening + adaptive compensation (thermal/RF/gimbal telemetry, health monitoring)

> **Note:** The previous second project (SIH26178 — Environmental Intelligence) used this same architecture. Its research is archived under `04_INITIAL_IDEA_RESEARCH/Rejected_Ideas/SIH26178_Environmental_Intelligence/` and its insights (sensor-agnostic design, SACHET/CAP integration) remain reusable.
