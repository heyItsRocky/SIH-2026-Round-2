# SIH26178 — Gap Analysis

> What exactly are we solving that existing solutions don't solve well?

---

## 1. Gap Chain

```
Existing system: Centralized satellite + sparse ground stations
      ↓
Limitation: No village/ward-level, minutes-not-hours ground truth
      ↓
Why it matters: Flash events (floods, fires) develop faster than satellite revisit
      ↓
Our opportunity: Dense, low-cost, offline-capable local sensing layer
```

---

## 2. Specific Gaps

| Gap | Existing coverage | Our solution |
|---|---|---|
| Local real-time ground truth | No (satellite revisit gaps) | Dense local sensing |
| Minutes-not-hours detection | No (satellite delay) | On-device edge AI |
| Offline operation | No (needs connectivity) | Local buffering + edge inference |
| Low-cost dense deployment | No (expensive stations) | Cheap ESP32 nodes |
| Multi-hazard in one network | No (single-hazard systems) | Multi-hazard node types |
| Alert integration | No (redundant apps) | SACHET/CAP integration |

---

## 3. One-Sentence Differentiation

> **"Satellite monitoring is accurate but not local or real-time; we add a dense, low-cost, offline-capable local sensing layer that feeds NDMA's existing alert infrastructure."**

---

## 4. Why This Gap Is Real (Evidence)

- IMD/ISRO satellite systems have revisit gaps — not minutes-not-hours
- CWC flood forecasting is regional, not ward-level
- FSI forest fire detection is satellite-based and delayed
- CPCB air quality stations are sparse
- Commercial IoT stations are too expensive for dense deployment
- No evidence of a mature, low-cost, offline-capable, multi-hazard, SACHET-integrated product on the Indian market
