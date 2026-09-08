# Idea 2 — SIH26050: High-Altitude Performance Optimization & Robust Design of Anti-Drone System

> SIH 2026 Round 2 · **Active** · DRDO · **Squad 2**

---

## Status

**Idea 2 is an active project.** This is the second submission for SIH 2026 Round 2, handled by Squad 2.

> 📍 **Current phase:** Planning & Deep Research — focus on `01_PROBLEM_INTELLIGENCE`, `02_DOMAIN_RESEARCH`, `03_ENVIRONMENTAL_ROBUSTNESS`, `04_SOLUTION_EXPLORATION`.

> 📌 **Decision:** Selected as an active project on 2026-09-08 (see [`00_TEAM_WORKSPACE/DECISIONS/DECISION_001_PROJECT_SELECTION.md`](../00_TEAM_WORKSPACE/DECISIONS/DECISION_001_PROJECT_SELECTION.md)). The previous second project (SIH26178) is archived under [`04_INITIAL_IDEA_RESEARCH/Rejected_Ideas/`](../../04_INITIAL_IDEA_RESEARCH/Rejected_Ideas/).

---

## Problem Statement

| Field | Value |
|---|---|
| **PS Number** | SIH26050 |
| **Organization** | DRDO |
| **Department** | Department of Defence Production / iDEX |
| **Category** | Hardware |
| **Theme** | MedTech / BioTech / HealthTech |
| **Idea Deadline** | 20 September 2026 |

---

## Problem Description

Build an anti-drone system that maintains detection, tracking, identification and neutralization performance at **high altitude** (Ladakh-type environments) where extreme cold, low pressure, dust, snow and high wind degrade standard electronics, batteries, sensors and mechanical components. The system must address **micro-radian level pointing and tracking accuracy** retention under these conditions.

---

## Proposed Solution Direction (seed)

**Hardened Stack + Adaptive Compensation** — Distributed multi-sensor anti-drone cluster (ULTRON architecture) with physical environmental hardening and real-time adaptive software compensation.

```
ULTRON Core (Pi 4 + Pi 3A+ + Pi 3B + ESP32s)
    │
    ├── RF Detection (AC600 + WN722N monitor mode)
    ├── EO/IR Tracking (USB camera + YOLOv8-nano)
    ├── Gimbal Assembly (2-axis, IMU feedback, PID control)
    └── Environmental Hardening (IP65, conformal coating, heated compartments)
```

> ⚠ This is the **initial direction** from the PS 01 analysis — NOT a locked architecture. The current phase is about exploring and comparing approaches before committing.

---

## Key Differentiators (from seed analysis)

| PS Keyword | How We Might Address It |
|---|---|
| Robust design methodologies | ULTRON hardened multi-node cluster with IP65 enclosures |
| Component selection for harsh environments | Silicone/PTFE cables, LiFePO4 batteries, TCXO oscillators |
| Compensation mechanisms | Real-time adaptive PID gain scheduling, RF auto-calibration |
| Thermal management | Heated battery compartment, conformal coating, active thermal monitoring |
| Adaptive control algorithms | Environment-aware PID + ML anomaly detection |
| Health monitoring | MQTT telemetry bus, CNN-LSTM anomaly models, predictive maintenance |
| Modelling and simulation | Cold-box test protocol, quantified degradation curves |

---

## Workspace Structure

| # | Folder | Purpose | Status |
|---|---|---|---|
| 01 | `01_PROBLEM_INTELLIGENCE/` | Problem statement deep-dive, requirements, constraints | **Seed analysis in place** |
| 02 | `02_DOMAIN_RESEARCH/` | Anti-drone domain, high-altitude environment, existing systems | Active research area |
| 03 | `03_ENVIRONMENTAL_ROBUSTNESS/` | Cold/low-pressure/dust/snow/wind effects on electronics, batteries, sensors, mechanics | Active research area |
| 04 | `04_SOLUTION_EXPLORATION/` | Multiple solution approaches, comparison, MVP definition | Active research area |
| 05 | `05_SYSTEM_ARCHITECTURE/` | *(created when architecture is locked)* | — |
| 06 | `06_PROTOTYPE/` | *(created when prototyping begins)* | — |
| 07 | `07_TESTING_VALIDATION/` | *(created when testing begins)* | — |
| 08 | `08_PRESENTATION/` | *(created when pitching begins)* | — |

---

## Hardware Compatibility (from seed analysis)

| ULTRON Component | Role in Solution | Status |
|---|---|---|
| Raspberry Pi 4B (8GB) | Central fusion engine, ML inference | Ready |
| Raspberry Pi 3A+ / 3B | Satellite sensor processing nodes | Ready |
| AC600 WiFi | RF drone detection (5 GHz scan) | Ready |
| TP-Link WN722N | Monitor mode RF fingerprinting | Ready |
| ESP32-C3 | Status display, local alerts | Ready |
| ESP32-WROOM | Hardware tripwire alerts | Ready |
| 500GB SSD | NAS logging, ML model storage | Ready |
| Ethernet Switch | Wired star backbone | Ready |

**New components needed (research before purchase):** USB camera, 2-axis gimbal (servos), MPU6050/BNO055 IMU, DS18B20 thermocouples, IP65 enclosure, silicone/PTFE cables, conformal coating, LiFePO4 cells.

---

## Current Development Status

- [x] Problem statement analysis (seed)
- [x] Solution approach analysis (4 approaches evaluated — see seed doc)
- [x] Architecture design (initial)
- [x] Hardware gap analysis (initial)
- [x] Component budget estimation (₹3,500–5,500 — see seed doc)
- [x] Timeline planning (4 weeks — see seed doc)
- [ ] Deep domain research (in progress — planning phase)
- [ ] Environmental robustness research (in progress — planning phase)
- [ ] Solution approach comparison & MVP definition
- [ ] Hardware hardening
- [ ] EO/IR detection prototype
- [ ] Gimbal + tracking
- [ ] Health monitoring ML port
- [ ] Validation testing
- [ ] Pitch deck