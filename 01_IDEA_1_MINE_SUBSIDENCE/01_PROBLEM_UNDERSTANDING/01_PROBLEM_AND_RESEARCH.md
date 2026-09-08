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

---

# SIH26025 — Real World Research

> Factual foundation: mine subsidence, monitoring practices, Coal India, DGMS, existing methods, actual incidents.

---

## 1. Mine Subsidence in India

- **Bord-and-pillar mining** (~80% of Indian underground coal extraction) creates surface and roof collapse risk over old workings
- **DGMS** (Directorate General of Mines Safety) issued a 2020 technical circular mandating real-time slope-stability monitoring at mines
- **Slope Stability Radar (SSR)** exists for **opencast** pit-wall monitoring — but does NOT address bord-and-pillar underground subsidence
- **Lalmatia collapse (Dec 2016)** — Coal India/ECL opencast collapse killed 18+ people
- **DGMS parliamentary records** — 25-30 fatal accidents/year in underground coal mines from roof falls and subsidence-type failures
- **Coal India safety record** — 135 accidents/37 deaths in a single reported year

---

## 2. Current Monitoring Methods

| Method | Accuracy | Continuous? | Real-time? | Infrastructure |
|---|---|---|---|---|
| InSAR satellite interferometry | High | No (multi-day revisit) | No | Satellite infrastructure |
| GNSS survey points | High | No (periodic) | No | Ground stations |
| Total-station leveling | High | No (periodic) | No | Surveyor visits |
| Slope Stability Radar (opencast only) | High | Yes | Yes | Expensive, opencast only |

**Gap:** Between survey cycles, there is **no live signal** for underground subsidence.

---

## 3. Existing Solutions

| Solution | What it does | Strength | Weakness |
|---|---|---|---|
| CSIR "Goafwarn" | Proprietary embedded-sensor goaf early warning | Fielded, "no global competitor" | Not open/cheap/available to contractors at scale |
| CSIR-CIMFR research | Vibrating-wire/micro-seismic roof-fall prediction | Research-grade | Not productized |
| Academic WSN (NIT-K, IIT-ISM) | Zigbee/WSN geotechnical monitoring | Proves concept | Not deployed at scale |
| High-end fiber-optic/microseismic | Lab-grade subsidence sensing | Accurate | Expensive, not at India's cost point |

---

## 4. Institutional Context

- **CMPDI** already operates a dedicated remote-sensing/GIS/LiDAR/drone group serving Coal India subsidiaries — a named institutional owner for a pilot
- **DGMS** mandates monitoring — regulatory tailwind
- **Coal India** has real mine sites and a real safety budget

---

## 5. Environmental Conditions

- Dust, vibration, moisture
- No reliable internet underground
- Remote locations
- Harsh industrial environment

---

## 6. Key Sources

- DGMS slope-monitoring circular / Ministry of Coal PIB release
- Subsidence monitoring techniques (Indian scenario) — academia.edu
- CMPDI remote sensing/GIS function — cmpdi.co.in
- Lok Sabha records (DGMS data, 2012-2015)
- Lalmatia collapse reporting

---

# SIH26025 — Existing Solutions

> Document what already exists, how it works, its strengths/weaknesses, and what remains unsolved.

---

## 1. Solution Landscape

| Solution | What it does | How it works | Strength | Weakness | Cost | Deployment | What remains unsolved |
|---|---|---|---|---|---|---|---|
| **CSIR "Goafwarn"** | Goaf (fall of ground) early warning | Proprietary embedded sensors | Fielded, "no global competitor" | Not open/cheap/available broadly | High | Limited | Open, low-cost, scalable version |
| **Slope Stability Radar (SSR)** | Opencast pit-wall monitoring | Radar interferometry | Accurate, continuous | Opencast only; expensive | Very high | Opencast mines | Underground subsidence |
| **InSAR satellite** | Surface deformation mapping | Satellite interferometry | Wide coverage | Multi-day revisit; not real-time | High | Regional | Real-time local alarm |
| **GNSS survey points** | Point deformation tracking | Satellite positioning | Accurate | Periodic; not continuous | Med | Selected sites | Continuous coverage |
| **Total-station leveling** | Surface level measurement | Surveyor visits | Accurate | Periodic; manual | Med | Selected sites | Continuous coverage |
| **Academic WSN (NIT-K, IIT-ISM)** | Zigbee/WSN geotech monitoring | Wireless sensor mesh | Proves concept | Not productized | Low | Research | Deployable product |
| **Fiber-optic/microseismic** | Lab-grade subsidence sensing | Optical/microseismic | Accurate | Expensive, lab-grade | Very high | Research | India cost point |

---

## 2. What Remains Unsolved

1. **Continuous, real-time** underground subsidence monitoring (not periodic survey)
2. **Low-cost** solution deployable at scale (not expensive lab-grade)
3. **Open/available** (not proprietary like Goafwarn)
4. **Offline-capable** (works without reliable internet underground)
5. **Mesh-level correlation** (not just single-sensor thresholds)
6. **AI-scored early warning** (not just threshold alarms)

---

## 3. Our Opportunity

The gap is real and specific: **a deployable, AI-scored, low-cost, real-time early-warning mesh for underground subsidence** — not commoditized, not open, not available to Coal India's contractors at scale.

---

# SIH26025 — Gap Analysis

> What exactly are we solving that existing solutions don't solve well?

---

## 1. Gap Chain

```
Existing system: Periodic manual survey + post-facto damage assessment
      ↓
Limitation: No continuous ground-truth feed between survey cycles
      ↓
Why it matters: Warning only exists AFTER a surveyor visits; critical ground failure happens between visits
      ↓
Our opportunity: Continuous, local, offline-capable monitoring layer between survey cycles
```

---

## 2. Specific Gaps

| Gap | Existing coverage | Our solution |
|---|---|---|
| Continuous real-time monitoring | No (periodic survey) | Continuous mesh sensing |
| Local edge alarm | No (cloud dashboard only) | GPIO alarm + OLED/NeoPixel on-site |
| Offline operation | No (needs internet) | Local buffering + periodic sync |
| Mesh-level correlation | No (single-sensor thresholds) | Multi-node deformation correlation |
| Low-cost scalable | No (expensive InSAR/GNSS/SSR) | Cheap ESP32 nodes |
| AI-scored early warning | No (manual assessment) | Edge AI anomaly detection |

---

## 3. One-Sentence Differentiation

> **"Survey-based monitoring (InSAR/GNSS/total-station) is accurate but not continuous; we add a continuous, local, offline layer between survey cycles."**

---

## 4. Why This Gap Is Real (Evidence)

- DGMS mandates slope monitoring (2020 circular) — regulatory tailwind
- SSR exists only for opencast pits — underground subsidence unaddressed
- CSIR Goafwarn is proprietary and not broadly available
- Academic WSN papers prove concept but aren't productized
- No evidence of a mature, DGMS-certified, low-cost, real-time underground-subsidence product on the Indian market

---

