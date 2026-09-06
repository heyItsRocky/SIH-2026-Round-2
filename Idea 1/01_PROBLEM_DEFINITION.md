# SIH26025 — Problem Definition

> What exactly are we solving?

---

## 1. Official Problem Statement

**Title:** Development of an AI-enabled Low Cost Real Time Mine Subsidence Monitoring, Prediction and Early Warning System for Underground Coal Mines in India

**Organization:** Ministry of Coal / Coal India Limited
**Category:** Hardware
**Theme:** Disaster Management

**Official Description:** Surface subsidence caused by underground coal mining poses significant risks to nearby communities, public infrastructure, agricultural land, forest areas, and the surrounding environment. India currently relies on conventional field observations, periodic surveys, and post-facto damage assessments — which fail to provide timely warning before critical ground failure.

Build an AI-enabled, low-cost, real-time subsidence monitoring platform based on a **localized wireless surface mesh sensor network** deployed above underground mine panels, with AI/ML anomaly detection, subsidence prediction, GIS visualization, and automated early warning alerts.

---

## 2. Actual Real-World Problem

Underground coal mining (especially bord-and-pillar, ~80% of Indian extraction) causes surface subsidence — ground sinking that threatens:
- Nearby communities
- Public infrastructure (roads, buildings, utilities)
- Agricultural land
- Forest areas
- The surrounding environment

Current monitoring is **periodic and manual** — surveyors visit sites on a schedule, and damage is only assessed after it happens. There is **no continuous ground-truth feed** between survey cycles.

---

## 3. Users

- Coal India Limited subsidiaries (CIL, ECL, BCCL, etc.)
- Mine operators, planners, and regulators
- DGMS (Directorate General of Mines Safety)
- CMPDI (Central Mine Planning & Design Institute)
- Nearby communities and public infrastructure owners

---

## 4. Current Workflow

```
Periodic field survey (total-station leveling, GNSS points)
        ↓
InSAR satellite interferometry (multi-day revisit)
        ↓
Post-facto damage assessment
        ↓
Warning only AFTER critical ground failure
```

**Limitation:** No continuous, real-time, local signal between survey cycles.

---

## 5. Desired Outcome

A continuous, local, offline-capable monitoring layer that:
- Detects early signs of ground movement in real time
- Correlates deformation across multiple nodes (mesh-level)
- Generates automated early warning alerts
- Operates without reliable internet (underground/remote environment)
- Is low-cost, scalable, and deployable across Indian coalfields

---

## 6. In-Scope

- Distributed wireless mesh sensor network (tilt, vibration, displacement, crack)
- Edge AI anomaly detection + subsidence zone prediction
- GIS visualization of live deformation maps and risk zones
- Automated early warning alerts (SMS/email/mobile)
- Offline capability with periodic cloud sync
- Physical scale-model demo for validation

---

## 7. Out-of-Scope

- **Certified structural-safety instrument** (DGMS certification is future work)
- **Geotechnical prediction of actual cave-ins** (we build early anomaly detection, not validated geoscience)
- Full-scale mine deployment (prototype → pilot is the path)
- Replacing InSAR/GNSS/survey systems (we complement them between cycles)

---

## 8. Critical Framing

> **We build an early anomaly/deformation detection network — NOT a validated "AI subsidence prediction" model.**

This distinction is critical for judge credibility. Overclaiming geotechnical prediction invites challenge from mining-engineering-literate judges. Honest framing reads as more credible, not less.
