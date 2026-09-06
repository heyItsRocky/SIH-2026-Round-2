# SIH26178 — Existing Solutions

> Document what already exists, how it works, its strengths/weaknesses, and what remains unsolved.

---

## 1. Solution Landscape

| Solution | What it does | How it works | Strength | Weakness | Cost | Deployment | What remains unsolved |
|---|---|---|---|---|---|---|---|
| **IMD satellite** | Weather forecasting | Satellite + models | Wide coverage | Revisit gaps, not local | High | National | Local real-time ground truth |
| **ISRO remote sensing** | Satellite imagery | Satellite interferometry | Wide coverage | Periodic, not real-time | High | National | Real-time local alarm |
| **CWC flood forecasting** | River flood prediction | Hydrological models | Regional accuracy | Not ward-level | High | River basins | Local real-time sensing |
| **FSI forest fire** | Fire detection | Satellite-based | National coverage | Delayed (satellite revisit) | High | National | Minutes-not-hours detection |
| **CPCB air quality** | Air quality monitoring | Sparse ground stations | Authoritative | Sparse, not dense | High | Cities | Dense local coverage |
| **Commercial IoT stations** | Local environmental sensing | Proprietary nodes | Local data | Expensive, not integrated | Med-High | Pilot | Low-cost, integrated, offline |
| **Academic WSN** | Environmental monitoring | Research prototypes | Proves concept | Not productized | Low | Research | Deployable product |

---

## 2. What Remains Unsolved

1. **Village/ward-level, minutes-not-hours ground truth** — nothing gives this today
2. **Low-cost, dense deployment** — commercial stations are too expensive for dense coverage
3. **Offline-capable operation** — most systems need continuous connectivity
4. **On-device AI inference** — most systems send raw data to cloud
5. **Integration with existing alert infrastructure** — most teams build redundant apps instead of feeding SACHET/CAP
6. **Multi-hazard in one network** — most systems are single-hazard

---

## 3. Our Opportunity

The gap is real and specific: **a low-cost, dense, offline-capable, on-device-AI environmental sensing network that feeds into NDMA's existing SACHET/CAP alert infrastructure** — not a redundant standalone app.
