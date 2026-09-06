# SIH26025 — Deployment & Scalability

> Prototype → pilot → scale. Cost, maintenance, connectivity, calibration.

---

## 1. Scale Path

```
3 nodes (prototype)
    ↓
100 nodes (mine pilot)
    ↓
1000 nodes (multiple mines)
```

```
Prototype (scale model)
    ↓
Mine pilot (one CIL subsidiary site)
    ↓
Multiple mines (CIL subsidiaries)
```

---

## 2. Deployment Considerations

| Factor | Prototype | Pilot | Scale |
|---|---|---|---|
| **Node density** | 3-4 nodes | 20-50 nodes | 100-1000 nodes |
| **Network** | Lab mesh | Mine-local mesh | Multi-mine mesh |
| **Maintenance** | Manual | Scheduled | Remote + scheduled |
| **Connectivity** | Lab Wi-Fi | Mine Wi-Fi/LoRa | LoRa + cellular |
| **Calibration** | Manual | Semi-automated | Automated |
| **Battery/power** | USB | Battery + solar | Solar + mains |
| **Hardware replacement** | Easy | Moderate | Logistics needed |

---

## 3. Cost Per Node (target)

| Component | Cost |
|---|---|
| ESP32-C3 | ~₹300 |
| Sensors (tilt/vibration) | ~₹300 |
| Enclosure | ~₹200 |
| Power (battery/solar) | ~₹300 |
| **Total per node** | **~₹1,100** |

Compare: InSAR/GNSS survey costs are orders of magnitude higher.

---

## 4. Institutional Owner

**CMPDI** already operates a dedicated remote-sensing/GIS/LiDAR/drone group serving Coal India subsidiaries — a named, existing organizational home for a pilot.