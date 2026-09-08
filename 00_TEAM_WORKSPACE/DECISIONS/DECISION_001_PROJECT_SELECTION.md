# DECISION_001 — Project Selection

- **Date:** 2026-09-08
- **Status:** Decided

## Decision

The team will actively work on **two projects**:

1. **SIH26025 — AI-Enabled Mine Subsidence Monitoring & Early Warning** (Ministry of Coal / Coal India) → Squad 1
2. **SIH26050 — High Altitude Performance Optimization and Robust Design of Anti-Drone System** (DRDO) → Squad 2

The previously finalized second project, **SIH26178 — AI-Powered Environmental Intelligence Network** (Qualcomm), is **set aside** and archived under `04_INITIAL_IDEA_RESEARCH/Rejected_Ideas/SIH26178_Environmental_Intelligence/`.

## Context

The team had previously finalized SIH26025 (Idea 1) and SIH26178 (Idea 2) as the two submissions. After further team discussion, the second project was re-evaluated. SIH26050 was the **#1 ranked idea** in the team's own Top 13 analysis (scored 4.4/5 overall) and was set aside only during the earlier finalization round. The team decided to return to it as the active second project.

## Options Considered

| Option | Description |
|---|---|
| **SIH26050 — High-Altitude Anti-Drone System (DRDO)** | Hardened multi-sensor anti-drone cluster for high-altitude deployment. Ranked #1 in Top 13 analysis (4.4/5). Strong ULTRON hardware match, high innovation potential. |
| **SIH26178 — Environmental Intelligence Network (Qualcomm)** | Distributed multi-hazard environmental monitoring with edge AI. Strong architectural fit, but high competition and Qualcomm platform-expectation risk (documented in the original comparison). |
| Other Top 13 candidates (SIH26157, SIH26153, SIH26155, etc.) | Evaluated in the Top 13 analysis; not selected for the same reasons documented there. |

## Why This Decision

- **SIH26050 was the team's top-ranked idea** from the start (4.4/5 — highest in the shortlist).
- **Existing ULTRON hardware maps directly** to the anti-drone solution (RF detection via AC600/WN722N, EO/IR tracking, distributed processing, MQTT health monitoring).
- **High innovation potential** — the PS explicitly asks for robust design methodologies, compensation mechanisms, and adaptive control, which align with the team's edge-AI and distributed-systems strengths.
- **SIH26178's known risks** (high competition nationally, Qualcomm platform expectations, scope creep across 3 hazard types) made it the weaker second pick despite its architectural fit.
- The team remains **one team** — SIH26178 research is preserved in the archive and its insights (SACHET/CAP integration, sensor-agnostic architecture) remain reusable.

## Consequences

- Squad 2 now owns the SIH26050 workspace (`02_IDEA_2_HIGH_ALTITUDE_ANTI_DRONE/`), seeded from the PS 01 analysis.
- SIH26178 documentation is preserved as historical research in `04_INITIAL_IDEA_RESEARCH/Rejected_Ideas/` — not deleted.
- The zero-budget strategy now applies to both active projects (sensor simulation where transducers are unavailable).
- Follow-up: deep research for SIH26050 (domain, environmental robustness, solution exploration) is now the priority for Squad 2.
- Follow-up: hardware gap analysis for SIH26050 (USB camera, gimbal, IMU, thermocouples, IP65 enclosure) — see `02_IDEA_2_HIGH_ALTITUDE_ANTI_DRONE/01_PROBLEM_INTELLIGENCE/PS01_SIH26050_ANALYSIS.md`.