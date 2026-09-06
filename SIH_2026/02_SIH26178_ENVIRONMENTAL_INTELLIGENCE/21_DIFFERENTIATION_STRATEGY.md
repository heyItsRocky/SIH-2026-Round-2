# SIH26178 — Differentiation Strategy

> What others will build, why that's limited, our approach, why it's better, evidence.

---

## 1. What Others Will Build

Most teams will build:
- A single-hazard sensor node with a threshold alarm
- A dashboard showing sensor readings
- Possibly a satellite-image CNN for "AI environmental monitoring"
- A standalone alert app

**They miss the SACHET/CAP integration and the multi-sensor fusion entirely.**

---

## 2. Why That Approach Is Limited

- Single-sensor thresholds can't distinguish a real fire from a false alarm (MQ-2 cross-sensitivity)
- Satellite imagery has multi-day revisit latency — can't give a village a live alarm
- No offline capability — cloud dashboard is useless without internet
- Standalone alert apps are redundant — NDMA already has SACHET/CAP
- No mesh-level correlation — the actual differentiator

---

## 3. Our Approach

**AI-Powered Environmental Intelligence Network**

- Distributed ESP32 sensor nodes in a mesh
- **Multi-sensor fusion** — combine smoke + temp + humidity to distinguish fire from false alarm
- **On-device edge AI** — real-time anomaly detection, no continuous cloud dependency
- **Mesh-level correlation** — compare nodes against neighbors
- **Offline-capable** — local buffering + edge inference
- **SACHET/CAP integration** — feed NDMA's existing alert bus, not a redundant app

---

## 4. Why It Is Better

| Dimension | Others | Us |
|---|---|---|
| Detection | Single-sensor threshold | Multi-sensor fusion |
| Latency | Satellite revisit (days) | Sub-minute local |
| Offline | No | Yes (core feature) |
| Cost | Expensive (commercial stations) | Cheap ESP32 nodes |
| Alerting | Standalone app | SACHET/CAP integration |
| Scope | Single hazard | Multi-hazard (same architecture) |

---

## 5. Evidence

- IMD/ISRO satellite systems have revisit gaps — not minutes-not-hours
- CWC flood forecasting is regional, not ward-level
- FSI forest fire detection is satellite-based and delayed
- CPCB air quality stations are sparse
- NDMA SACHET/CAP is the existing national alert infrastructure — feed it, don't replace it

---

## 6. One-Sentence Pitch

> **"Satellite monitoring is accurate but not local or real-time; we add a dense, low-cost, offline-capable local sensing layer that feeds NDMA's existing alert infrastructure."**
