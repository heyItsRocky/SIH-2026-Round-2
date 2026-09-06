# SIH26178 — Deployment & Scalability

> Prototype → pilot → scale. Cost, maintenance, connectivity, calibration.

---

## 1. Scale Path

```
4 nodes (prototype)
    ↓
100 nodes (city/forest pilot)
    ↓
1000 nodes (multi-region)
```

```
Prototype (lab)
    ↓
City/forest pilot (one SDMA region)
    ↓
Multi-region (multiple SDMAs)
```

---

## 2. Deployment Considerations

| Factor | Prototype | Pilot | Scale |
|---|---|---|---|
| **Node density** | 4 nodes | 20-50 nodes | 100-1000 nodes |
| **Network** | Lab mesh | City/forest mesh | Multi-region mesh |
| **Maintenance** | Manual | Scheduled | Remote + scheduled |
| **Connectivity** | Lab Wi-Fi | LoRa + cellular | LoRa + cellular |
| **Calibration** | Manual | Semi-automated | Automated |
| **Battery/power** | USB | Battery + solar | Solar + mains |
| **Hardware replacement** | Easy | Moderate | Logistics needed |

---

## 3. Cost Per Node (target)

| Component | Cost |
|---|---|
| ESP32-C3 | ~₹300 |
| Sensors (smoke/temp/humidity) | ~₹350 |
| Enclosure (weatherproof) | ~₹300 |
| Power (battery + solar) | ~₹500 |
| **Total per node** | **~₹1,450** |

Compare: commercial IoT environmental stations cost orders of magnitude more.

---

## 4. Institutional Owner

**SDMAs** (State Disaster Management Authorities) are the primary users. **NDMA** owns the SACHET/CAP alert infrastructure we feed into. **FSI** is the forest-fire institutional owner for the fire MVP.
