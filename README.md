# SIH 2026 Round 2 — Workspace

> Smart India Hackathon 2026 · Round 2 preparation workspace
> **Idea deadline: 20 September 2026**

---

## What This Repo Is

End-to-end preparation for SIH 2026 Round 2: from the full pool of 233 problem statements → shortlist of 13 → top 2 finalized ideas → complete engineering documentation for both, built on our existing **ULTRON hardware cluster** (Raspberry Pi + ESP32 mesh).

**Final decision:** two finalized submissions, both Hardware-category Disaster Management problems:

| Rank | Idea | PS | Sponsor | Problem |
|---|---|---|---|---|
| 🥇 | [Idea 1](./Idea%201/README.md) | SIH26025 | Ministry of Coal / Coal India | AI-enabled real-time mine subsidence monitoring & early warning |
| 🥈 | [Idea 2](./Idea%202/README.md) | SIH26178 | Qualcomm Inc | AI-powered environmental intelligence network |

---

## Repository Structure

```
SIH-2026-Round-2/
├── README.md                          ← you are here
│
├── Idea 1/                            ← FINALIZED · SIH26025 Mine Subsidence (primary)
│   ├── README.md                      ← overview, problem, solution, status
│   ├── 01_PROBLEM_AND_RESEARCH.md     ← problem def, research, existing solutions, gap
│   ├── 02_TECHNICAL_DESIGN.md         ← stack, hardware, sensors, circuit, network, AI
│   ├── 03_OPERATIONS_AND_DEMO.md      ← failure modes, testing, demo, cost, differentiation
│   └── 04_PITCH_AND_QA.md             ← pitch framing + judge Q&A
│
├── Idea 2/                            ← FINALIZED · SIH26178 Environmental Intelligence (backup)
│   ├── README.md                      ← overview, problem, solution, status
│   ├── 01_PROBLEM_AND_RESEARCH.md     ← problem def, research, existing solutions, gap
│   ├── 02_TECHNICAL_DESIGN.md         ← stack, hardware, sensors, circuit, network, AI
│   ├── 03_OPERATIONS_AND_DEMO.md      ← failure modes, testing, demo, cost, differentiation
│   └── 04_PITCH_AND_QA.md             ← risk analysis + pitch framing + judge Q&A
│
├── master files/                       ← the decision layer
│   ├── 01_SIH_Problem_Selection_Framework.md
│   ├── 02_SIH_2026_Problem_Analysis.md
│   ├── 03_TOP_2_COMPARISON.md
│   ├── 04_FINAL_DECISION_MATRIX.md
│   ├── 05_FINAL_PROBLEM_SELECTION.md
│   ├── HARDWARE_CAPABILITY_BASELINE.md
│   ├── TECH_STACK_COMPARISON.md
│   └── ZERO_BUDGET_STRATEGY.md        ← ⚠ read this first (no budget for sensors)
│
├── Top 13 Ideas Analysis/              ← shortlist analysis (PS 01–13)
│   └── README.md                       ← comparison table + selection criteria
│
├── ULTRON/                             ← our hardware cluster
│   ├── ULTRON_Circuit_Diagram.jpeg
│   ├── ULTRON_Circuit_Documentation.md ← full wiring reference
│   ├── ULTRON_Single_Plug_Power_Plan.md
│   └── virtual/                        ← MQTT brain/heartbeat/test + Wokwi sketches
│
├── All SIH 2026 Problem Statements.md  ← full problem statement dump (233 PS)
├── SIH 2026 Problem Statements List.md ← searchable list
└── SIH-2026-Problem-Statement-Explorer.html ← interactive browser
```

---

## ⚠ Zero-Budget Strategy (read first)

**We have no budget to purchase extra parts or sensors.** The plan:

- **REAL:** distributed mesh (Pi 4 + Pi 3A+ + Pi 3B+ + ESP32s), MQTT pipeline, edge AI anomaly detection, multi-node correlation, dashboard/GIS, alerting (OLED/NeoPixel/GPIO), offline buffering
- **SIMULATED:** physical sensor transducers (tilt/smoke/PM2.5/etc.) via a high-fidelity software sensor simulator — a drop-in replacement, sensor-agnostic architecture
- **FREE real signals:** CPU temperature on each Pi (`vcgencmd`), tripwire GPIO as a physical event trigger

Full plan: [`master files/ZERO_BUDGET_STRATEGY.md`](./master%20files/ZERO_BUDGET_STRATEGY.md)

---

## Hardware Baseline (ULTRON cluster)

| Device | Role |
|---|---|
| Raspberry Pi 4B 8GB | Gateway, edge AI, MQTT broker, dashboard |
| Raspberry Pi 3A+ | Distributed node |
| Raspberry Pi 3B+ v1.2 | Distributed node |
| 2× ESP32-C3-DevKitM-1 | Sensor interface / alert controller (NeoPixel on GPIO8) |
| 1× ESP32-WROOM-32 | Tripwire / alert controller |
| 5-port Ethernet switch | Mesh backbone |
| 1" I2C OLED + NeoPixel | On-site alerting |
| AC600 + TL-WN722N Wi-Fi | Wireless uplink |
| 500GB SSD + 128GB flash | Storage |

Full baseline: [`master files/HARDWARE_CAPABILITY_BASELINE.md`](./master%20files/HARDWARE_CAPABILITY_BASELINE.md)

---

## Progress

| Milestone | Status |
|---|---|
| Problem statement pool analysis (233 PS) | ✅ |
| Shortlist analysis (PS 01–13) | ✅ |
| Final selection (Idea 1 = SIH26025, Idea 2 = SIH26178) | ✅ |
| Engineering docs for both ideas | ✅ |
| Zero-budget strategy | ✅ |
| Sensor simulator + MQTT pipeline code | 🔜 next |
| Mesh network implementation | ⬜ |
| Edge AI anomaly detection | ⬜ |
| Dashboard & GIS visualization | ⬜ |
| Demo + pitch deck | ⬜ |