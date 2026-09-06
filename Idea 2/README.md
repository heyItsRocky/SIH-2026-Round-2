# Idea 2 — SIH26178: AI-Powered Environmental Intelligence Network

> SIH 2026 Round 2 · **Finalized** · Qualcomm Inc

---

## Status

**Idea 2 is finalized.** This is the runner-up / backup submission for SIH 2026 Round 2.

---

## Problem Statement

| Field | Value |
|---|---|
| **PS Number** | SIH26178 |
| **Organization** | Qualcomm Inc |
| **Department** | Qualcomm Inc |
| **Category** | Hardware |
| **Theme** | Disaster Management |
| **Idea Deadline** | 20 September 2026 |

---

## Problem Description

India faces a growing range of environmental and climate-related risks including urban flooding, river floods, cyclones, forest fires, air pollution, droughts, landslides, and extreme weather events. Government agencies such as NDMA, IMD, and ISRO already rely on centralized environmental monitoring and early warning systems, but these often lack sufficiently localized, real-time intelligence.

Design an **Environmental Intelligence Network** — a distributed system of interconnected AI-powered sensor nodes deployable across cities, rivers, forests, industrial zones, and vulnerable communities. Each node uses **local (on-device) AI inference** to continuously monitor environmental conditions and identify emerging risks such as rising water levels, forest fires/smoke, hazardous air pollution, extreme heat, landslide precursors, industrial emissions, and water quality degradation.

The sensor network should process data locally to reduce latency, minimize bandwidth, and continue operating during network outages. Only critical alerts, summarized insights, and risk assessments should be transmitted to regional control centers or disaster management authorities.

---

## Proposed Solution & Core Concept

**Distributed multi-hazard environmental monitoring network with on-device edge AI inference, offline-capable operation, and hybrid edge-cloud architecture.**

```
ESP32 Sensor Nodes (Distributed)          Pi 4B (Edge AI)              Cloud / Dashboard
┌──────────────────────────────┐          ┌──────────────────┐         ┌──────────────────┐
│ Node A: Water level + Rain   │          │                  │         │                  │
│ Node B: Smoke + Temp + Hum   │──LoRa/──►│ MQTT Broker      │──sync──►│ GIS Risk Map     │
│ Node C: PM2.5/PM10 + Gas     │  Zigbee  │ On-device AI     │         │ Hotspot Trends   │
│ Node D: Soil moisture + Vib  │  Mesh    │ Anomaly Detection│         │ Severity Alerts  │
│        ...                   │          │ Offline Buffering│         │ Mobile/Web       │
└──────────────────────────────┘          └──────────────────┘         │ Notifications    │
                                                                      └──────────────────┘
```

---

## Key Features

- Distributed ESP32 sensor nodes (water level, rainfall, temperature, humidity, smoke, PM2.5/PM10, gas, soil moisture, vibration)
- Wireless mesh (LoRa/Zigbee/Wi-Fi) for continuous multi-hazard monitoring
- **On-device edge AI** — real-time anomaly detection, no continuous cloud dependency
- **Hybrid edge-cloud** — edge for immediate decisions, cloud for long-term trends/forecasting
- **GIS risk mapping** — geospatial visualization of hotspots, risk trends, affected zones
- **Multi-hazard alerts** — prioritized warning levels (flood, fire, pollution, extreme weather, industrial) via mobile/web
- **Solar-powered, low-maintenance** — suitable for remote deployments

---

## Technical Approach & Architecture

- **Edge:** ESP32-C3/WROOM sensor nodes in a wireless mesh
- **Edge AI:** Pi 4B runs MQTT aggregation + on-device anomaly detection
- **Cloud:** GIS dashboard, risk mapping, alert delivery
- **Protocols:** LoRa/Zigbee/Wi-Fi mesh, MQTT telemetry
- **Scope control:** Pick **one hazard** (fire is best-evidenced gap, cheapest to sensor) as the deep MVP; address others as "same-architecture, future-node" slides

---

## Proposed Tech Stack

- **Hardware:** ESP32-C3, ESP32-WROOM, Raspberry Pi 4B, environmental sensors (smoke/heat/water-level), solar charging circuit, LoRa modules
- **Firmware:** ESP-IDF / Arduino, TFLite Micro (edge inference)
- **Backend:** Python (FastAPI), MQTT broker
- **ML:** scikit-learn / TensorFlow for anomaly detection
- **Frontend:** Web dashboard with GIS map

---

## Expected Users & Stakeholders

- State Disaster Management Authorities (SDMAs)
- FSI regional offices (forest fire)
- CWC / flood forecasting authorities
- Local communities and citizens

---

## Advantages & Challenges

**Advantages:**
- Near-literal spec match with ULTRON architecture (distributed edge nodes, offline resilience, alerting)
- Strongest architectural fit on the entire list — the platform's native use case
- **SACHET/CAP integration insight** — feed into NDMA's existing alert bus rather than building a redundant standalone app (most teams won't find this)
- Genuine, government-documented gap: nothing gives village/ward-level, minutes-not-hours ground truth

**Challenges:**
- **High competition** — flashy first-year private-sector sponsor (Qualcomm), universally-appealing framing, likely one of the most popular statements nationally
- **Sponsor Platform Expectation Risk** — Qualcomm may expect Snapdragon/Dragonwing hardware; pre-empt by framing ULTRON as the low-cost field-node layer, silicon-agnostic and portable to Dragonwing at production scale
- **Scope creep** — 3 hazard types in one PS; must deliberately narrow to one hazard MVP
- **CV skill gap** — "AI-powered" framing pushes toward computer vision (flame/smoke detection); sensor-only route is lower difficulty but less dramatic demo

---

## Detailed Documentation

This folder contains the full engineering documentation for Idea 2 (SIH26178):

| # | File | Contents |
|---|---|---|
| 01 | `01_PROBLEM_DEFINITION.md` | Problem statement, users, scope, critical framing |
| 02 | `02_REAL_WORLD_RESEARCH.md` | India's environmental risks, SACHET/CAP, NDMA/IMD/ISRO |
| 03 | `03_EXISTING_SOLUTIONS.md` | Solution landscape, what remains unsolved |
| 04 | `04_GAP_ANALYSIS.md` | The specific gap we solve |
| 05 | `05_TECH_STACK.md` | Tech choices, difficulty, learning curve |
| 06 | `06_ULTRON_HARDWARE_MAPPING.md` | Existing hardware → solution mapping |
| 07 | `07_SENSOR_SELECTION.md` | Sensor candidates, selection criteria |
| 08 | `08_CIRCUIT_DESIGN.md` | Pin mapping, power rails, GPIO |
| 09 | `09_NODE_ARCHITECTURE.md` | What one environmental node looks like |
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
| 22 | `22_RISK_ANALYSIS.md` | Risk register, Qualcomm platform expectation |
| 23 | `23_PITCH_AND_JUDGE_QA.md` | Judge questions, potential attacks |

---

## Current Development Status

- [x] Problem statement analysis
- [x] Competitive intelligence report
- [x] Solution design
- [ ] Hazard selection (fire recommended as MVP)
- [ ] Sensor selection & procurement
- [ ] Mesh network implementation
- [ ] Edge AI anomaly detection
- [ ] SACHET/CAP integration layer
- [ ] Dashboard & GIS visualization
- [ ] Testing & validation
- [ ] Pitch deck
