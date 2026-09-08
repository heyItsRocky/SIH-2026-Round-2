# 03_SHARED_TECH — Shared Technology & Hardware

> Technology and hardware shared by both active projects. Maintained jointly by both squads.

## Contents

| Item | What it is | Status |
|---|---|---|
| [`HARDWARE_CAPABILITY_BASELINE.md`](./HARDWARE_CAPABILITY_BASELINE.md) | The team's actual hardware inventory (independent of either project) | **Live** — update when inventory changes |
| [`ULTRON/`](./ULTRON/) | The ULTRON hardware cluster: circuit diagram, wiring reference, power plan, MQTT virtual code, Wokwi sketches | **Live** — the physical cluster both projects build on |

## Shared Concepts (create folders only when there's real content)

The following concepts are shared across both projects. Folders will be created here as content accumulates — do NOT create empty folders:

- **MQTT** — telemetry pipeline (currently implemented inside `ULTRON/virtual/`)
- **Edge computing** — Pi 4 edge AI, anomaly detection
- **Device management** — node health, offline buffering, sync
- **Dashboard components** — GIS maps, alerting UI
- **ULTRON** — the hardware cluster itself

## Rules

- **Project-specific hardware/software** goes in the project workspace, NOT here.
- **Shared infrastructure** (used by both projects) goes here.
- Changes that affect both projects should be discussed before implementation.