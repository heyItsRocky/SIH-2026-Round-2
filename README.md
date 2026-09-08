# SIH 2026 Round 2 — Team Workspace

> Smart India Hackathon 2026 · Round 2 · Team workspace
> **Idea deadline: 20 September 2026**

---

## What This Repo Is

This is the team's **central workspace and single source of truth** for both active projects — research, planning, architecture, technical decisions, documentation, hardware planning, development, testing, validation, and presentations.

We are currently in the **Planning + Deep Research phase**. We are NOT rushing into implementation — the immediate focus is understanding both problems deeply, researching the domains, exploring solution approaches, and defining realistic MVPs.

**Start here:** [`00_CURRENT_STATUS.md`](./00_CURRENT_STATUS.md) — where the team is right now and what's next.

---

## Active Projects

| # | Project | PS | Sponsor | Squad |
|---|---|---|---|---|
| 1 | [Mine Subsidence Monitoring](./01_IDEA_1_MINE_SUBSIDENCE/README.md) | SIH26025 | Ministry of Coal / Coal India | Squad 1 (3 members) |
| 2 | [High-Altitude Anti-Drone System](./02_IDEA_2_HIGH_ALTITUDE_ANTI_DRONE/README.md) | SIH26050 | DRDO | Squad 2 (3 members) |

One team, two squads. Members may collaborate across projects when needed. See [`00_TEAM_WORKSPACE/TEAM_STRUCTURE.md`](./00_TEAM_WORKSPACE/TEAM_STRUCTURE.md).

---

## Repository Structure

```
SIH-2026-Round-2/
│
├── README.md                          ← you are here
├── 00_CURRENT_STATUS.md               ← current phase, objectives, rules
│
├── 00_TEAM_WORKSPACE/                 ← team-level workspace
│   ├── TEAM_STRUCTURE.md              ← squads, roles, collaboration
│   ├── MEETING_NOTES/                 ← meeting notes
│   ├── DECISIONS/                     ← decision records (DECISION_001, ...)
│   └── SHARED_RESOURCES/              ← team-wide strategy & methodology
│
├── 01_IDEA_1_MINE_SUBSIDENCE/         ← ACTIVE · SIH26025 (Squad 1)
│   ├── README.md
│   ├── 01_PROBLEM_UNDERSTANDING/
│   ├── 02_RESEARCH/
│   ├── 03_SOLUTION_DESIGN/
│   ├── 06_TESTING_VALIDATION/
│   └── 07_PRESENTATION/
│
├── 02_IDEA_2_HIGH_ALTITUDE_ANTI_DRONE/ ← ACTIVE · SIH26050 (Squad 2)
│   ├── README.md
│   ├── 01_PROBLEM_INTELLIGENCE/
│   ├── 02_DOMAIN_RESEARCH/
│   ├── 03_ENVIRONMENTAL_ROBUSTNESS/
│   └── 04_SOLUTION_EXPLORATION/
│
├── 03_SHARED_TECH/                    ← shared technology & hardware
│   ├── HARDWARE_CAPABILITY_BASELINE.md
│   └── ULTRON/                        ← the hardware cluster (circuit, virtual, wokwi)
│
├── 04_INITIAL_IDEA_RESEARCH/          ← historical research archive
│   ├── Top_13_Ideas_Analysis/         ← shortlist analysis (PS 01–13)
│   ├── Rejected_Ideas/                ← previously considered projects
│   └── Original_Research/             ← 233-PS pool, master analysis, explorer
│
└── docs/                              ← collaboration docs
    ├── CONTRIBUTING.md
    ├── REPO_WORKFLOW.md
    └── NAMING_CONVENTIONS.md
```

---

## ⚠ Zero-Budget Strategy (read first)

**We have no budget to purchase extra parts or sensors.** The plan:

- **REAL:** distributed mesh (Pi 4 + Pi 3A+ + Pi 3B+ + ESP32s), MQTT pipeline, edge AI anomaly detection, multi-node correlation, dashboard/GIS, alerting (OLED/NeoPixel/GPIO), offline buffering
- **SIMULATED:** physical sensor transducers (tilt/smoke/PM2.5/etc.) via a high-fidelity software sensor simulator — a drop-in replacement, sensor-agnostic architecture
- **FREE real signals:** CPU temperature on each Pi (`vcgencmd`), tripwire GPIO as a physical event trigger

Full plan: [`00_TEAM_WORKSPACE/SHARED_RESOURCES/ZERO_BUDGET_STRATEGY.md`](./00_TEAM_WORKSPACE/SHARED_RESOURCES/ZERO_BUDGET_STRATEGY.md)

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

Full baseline: [`03_SHARED_TECH/HARDWARE_CAPABILITY_BASELINE.md`](./03_SHARED_TECH/HARDWARE_CAPABILITY_BASELINE.md)

---

## How to Work in This Repo

1. Read [`00_CURRENT_STATUS.md`](./00_CURRENT_STATUS.md) to know where the team is.
2. Find your project workspace (`01_...` or `02_...`) and its README.
3. Follow the workflow in [`docs/REPO_WORKFLOW.md`](./docs/REPO_WORKFLOW.md).
4. Record important decisions in [`00_TEAM_WORKSPACE/DECISIONS/`](./00_TEAM_WORKSPACE/DECISIONS/).
5. Follow [`docs/CONTRIBUTING.md`](./docs/CONTRIBUTING.md) and [`docs/NAMING_CONVENTIONS.md`](./docs/NAMING_CONVENTIONS.md).

---

## Progress

| Milestone | Status |
|---|---|
| Problem statement pool analysis (233 PS) | ✅ |
| Shortlist analysis (PS 01–13) | ✅ |
| Project selection (Idea 1 = SIH26025, Idea 2 = SIH26050) | ✅ |
| Idea 1 engineering docs | ✅ |
| Idea 2 seed research (from PS 01 analysis) | ✅ |
| Zero-budget strategy | ✅ |
| Deep research — Idea 1 (problem, domain, approaches) | 🔜 next |
| Deep research — Idea 2 (problem, domain, robustness, approaches) | 🔜 next |
| MVP definition for both projects | ⬜ |
| Implementation | ⬜ |
| Testing & validation | ⬜ |
| Demo + pitch deck | ⬜ |