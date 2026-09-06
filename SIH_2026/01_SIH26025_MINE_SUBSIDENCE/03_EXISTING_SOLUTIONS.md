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
