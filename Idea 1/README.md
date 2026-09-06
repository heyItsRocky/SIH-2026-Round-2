# Idea 1 — SIH26025: AI-Enabled Mine Subsidence Monitoring & Early Warning

> SIH 2026 Round 2 · **Finalized** · Ministry of Coal / Coal India Limited

---

## Status

**Idea 1 is finalized.** This is the primary submission for SIH 2026 Round 2.

---

## Problem Statement

| Field | Value |
|---|---|
| **PS Number** | SIH26025 |
| **Organization** | Ministry of Coal |
| **Department** | Coal India Limited |
| **Category** | Hardware |
| **Theme** | Disaster Management |
| **Idea Deadline** | 20 September 2026 |

---

## Problem Description

Surface subsidence caused by underground coal mining poses significant risks to nearby communities, public infrastructure, agricultural land, forest areas, and the surrounding environment. India currently relies on conventional field observations, periodic surveys, and post-facto damage assessments — which fail to provide timely warning before critical ground failure.

Build an AI-enabled, low-cost, real-time subsidence monitoring platform based on a **localized wireless surface mesh sensor network** deployed above underground mine panels, with AI/ML anomaly detection, subsidence prediction, GIS visualization, and automated early warning alerts.

---

## Proposed Solution & Core Concept

**Wireless Surface Mesh Network for Real-Time Subsidence Detection** — the unique innovation hook that differentiates this from generic AI proposals.

```
ESP32 Sensor Nodes (Surface Mesh)          Pi 4B (Edge AI)              Cloud / Dashboard
┌──────────────────────────────┐          ┌──────────────────┐         ┌──────────────────┐
│ Node A: Tilt + Vibration     │          │                  │         │                  │
│ Node B: Displacement + Crack │──LoRa/──►│ MQTT Broker      │──sync──►│ GIS Deformation  │
│ Node C: Tilt + GPS           │  Zigbee  │ AI/ML Anomaly    │         │ Map + Risk Zones │
│ Node D: Vibration + Crack    │  Mesh    │ Detection        │         │ SMS/Email/Mobile │
│        ...                   │          │ Subsidence       │         │ Alerts           │
└──────────────────────────────┘          │ Prediction       │         │ Operator         │
                                          └──────────────────┘         │ Dashboard        │
                                                                      └──────────────────┘
```

---

## Key Features

- Distributed ESP32 sensor nodes (tilt, vibration, displacement, crack detection)
- Wireless mesh (LoRa/Zigbee/Wi-Fi) for continuous micro-ground-movement monitoring
- **Mesh-level deformation correlation** between nodes (the hidden constraint most teams miss)
- AI/ML anomaly detection + subsidence zone prediction on Pi 4B
- GIS visualization of live deformation maps and risk zones
- Automated SMS/email/mobile app alerts
- Offline capability with periodic cloud sync

---

## Technical Approach & Architecture

- **Edge:** ESP32-C3/WROOM sensor nodes in a wireless mesh over the mine panel
- **Edge AI:** Pi 4B runs MQTT aggregation + AI/ML anomaly detection
- **Cloud:** GIS dashboard, risk mapping, alert delivery
- **Protocols:** LoRa/Zigbee/Wi-Fi mesh, MQTT telemetry

---

## Proposed Tech Stack

- **Hardware:** ESP32-C3, ESP32-WROOM, Raspberry Pi 4B, tilt/vibration/strain sensors, LoRa modules
- **Firmware:** ESP-IDF / Arduino, TFLite Micro (edge inference)
- **Backend:** Python (FastAPI), MQTT broker
- **ML:** scikit-learn / TensorFlow for anomaly detection
- **Frontend:** Web dashboard with GIS map

---

## Expected Users & Stakeholders

- Coal India Limited subsidiaries (CIL, ECL, BCCL, etc.)
- Mine operators, planners, and regulators
- Nearby communities and public infrastructure owners

---

## Advantages & Challenges

**Advantages:**
- Near-literal spec match with ULTRON architecture (Pi/ESP32 mesh, Wi-Fi, offline+sync)
- Best-evidenced severity (confirmed fatal accident stream, DGMS records)
- Lowest competition-to-quality ratio (unglamorous domain filters out casual teams)
- Hidden constraint (mesh correlation) is stated in the PS text itself

**Challenges:**
- Must frame honestly as "early anomaly/deformation detection network," not overclaimed "AI subsidence prediction"
- Needs tilt/vibration/strain sensors (not in inventory)
- Judges with mining-engineering literacy may challenge prediction claims

---

## Detailed Documentation

This folder contains the full engineering documentation for Idea 1 (SIH26025):

| # | File | Contents |
|---|---|---|
| 01 | `01_PROBLEM_DEFINITION.md` | Problem statement, users, scope, critical framing |
| 02 | `02_REAL_WORLD_RESEARCH.md` | Mine subsidence facts, DGMS, Coal India, incidents |
| 03 | `03_EXISTING_SOLUTIONS.md` | Solution landscape, what remains unsolved |
| 04 | `04_GAP_ANALYSIS.md` | The specific gap we solve |
| 05 | `05_TECH_STACK.md` | Tech choices, difficulty, learning curve |
| 06 | `06_ULTRON_HARDWARE_MAPPING.md` | Existing hardware → solution mapping |
| 07 | `07_SENSOR_SELECTION.md` | Sensor candidates, selection criteria |
| 08 | `08_CIRCUIT_DESIGN.md` | Pin mapping, power rails, GPIO |
| 09 | `09_NODE_ARCHITECTURE.md` | What one mine node looks like |
| 10 | `10_NETWORK_COMMUNICATION.md` | Protocol, MQTT topics, offline behavior |
| 11 | `11_DATA_PIPELINE.md` | Sensor reading → dashboard flow |
| 12 | `12_AI_ML_STRATEGY.md` | Anomaly detection approach |
| 13 | `13_DETECTION_AND_ALERT_LOGIC.md` | Anomaly score, confidence, alert levels |
| 14 | `14_SYSTEM_ARCHITECTURE.md` | Master architecture diagram |
| 15 | `15_FAILURE_MODES.md` | What can go wrong, graceful degradation |
| 16 | `16_SECURITY_AND_RELIABILITY.md` | Auth, integrity, fail-safe |
| 17 | `17_TESTING_AND_VALIDATION.md` | Test plan, metrics, validation |
| 18 | `18_DEMO_PLAN.md` | Scripted live demonstration |
| 19 | `19_DEPLOYMENT_AND_SCALABILITY.md` | Prototype → pilot → scale |
| 20 | `20_COST_AND_BOM.md` | Bill of materials, cost comparison |
| 21 | `21_DIFFERENTIATION_STRATEGY.md` | What others build, why we're better |
| 22 | `22_PITCH_AND_JUDGE_QA.md` | Judge questions, potential attacks |

---

## Current Development Status

- [x] Problem statement analysis
- [x] Competitive intelligence report
- [x] Solution design
- [ ] Sensor selection & procurement
- [ ] Mesh network implementation
- [ ] Edge AI anomaly detection
- [ ] Dashboard & GIS visualization
- [ ] Testing & validation
- [ ] Pitch deck
