# SIH26025 — Differentiation Strategy

> What others will build, why that's limited, our approach, why it's better, evidence.

---

## 1. What Others Will Build

Most teams will build:
- A single-node tilt/vibration sensor with a threshold alarm
- A dashboard showing sensor readings
- Possibly a satellite-image CNN for "AI slope monitoring"

**They miss the mesh aspect entirely.**

---

## 2. Why That Approach Is Limited

- Single-sensor thresholds can't distinguish local disturbance from genuine ground movement
- Satellite imagery has multi-day revisit latency — can't give a mine control room a live alarm
- No offline capability — cloud dashboard is useless without internet
- No mesh-level deformation correlation — the actual differentiator the sponsor names

---

## 3. Our Approach

**Wireless Surface Mesh Network for Real-Time Subsidence Detection**

- Distributed ESP32 sensor nodes in a mesh
- **Mesh-level deformation correlation** — compare nodes against neighbors
- Edge AI anomaly detection on Pi 4 (offline-capable)
- Local GPIO/OLED/NeoPixel alerting
- Offline buffering + periodic cloud sync

---

## 4. Why It Is Better

| Dimension | Others | Us |
|---|---|---|
| Detection | Single-sensor threshold | Mesh correlation |
| Latency | Satellite revisit (days) | Sub-minute local |
| Offline | No | Yes (core feature) |
| Cost | Expensive (InSAR/GNSS) | Cheap ESP32 nodes |
| Alerting | Cloud dashboard | Local + remote |

---

## 5. Evidence

- DGMS mandates slope monitoring (2020 circular) — regulatory tailwind
- SSR exists only for opencast pits — underground subsidence unaddressed
- CSIR Goafwarn is proprietary and not broadly available
- The PS text itself names "relative distance between nodes" as the differentiator

---

## 6. One-Sentence Pitch

> **"Survey-based monitoring is accurate but not continuous; we add a continuous, local, offline mesh layer between survey cycles."**