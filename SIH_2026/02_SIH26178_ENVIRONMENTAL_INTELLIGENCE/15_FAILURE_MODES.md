# SIH26178 — Failure Modes

> What can go wrong, and what does the system do?

---

## 1. Failure Mode Analysis

| Failure | What happens | System response | Severity |
|---|---|---|---|
| **Sensor fails** | No data from one sensor | Flag node degraded; use neighbors for correlation | Med |
| **Node dies** | No data from one node | Flag node offline; mesh continues | Med |
| **Network disappears** | No mesh connectivity | Local buffering; local alerts still fire | Low |
| **Power disappears** | Node loses power | Battery backup; graceful shutdown | Med |
| **False positive** | Alert when no real hazard | Multi-sensor fusion + correlation reduces this | Med |
| **False negative** | Miss real hazard | Multiple sensors + correlation reduces this | High |
| **Gateway fails** | Pi 4 down | Nodes buffer locally; alerts fire locally | Med |
| **Storage corruption** | Data loss | Redundant storage; periodic backup | Med |
| **SACHET/CAP API down** | Alert push fails | Local alerts still fire; retry on reconnect | Med |
| **Outdoor conditions** | Rain/dust/sun damage | Weatherproof enclosure; solar power | Med |

---

## 2. Graceful Degradation Path

```
All systems normal
    ↓
One sensor fails → flag degraded, use neighbors
    ↓
One node dies → flag offline, mesh continues
    ↓
Network down → local buffering + local alerts
    ↓
Gateway down → nodes buffer + local alerts
    ↓
SACHET down → local alerts + retry on reconnect
    ↓
Total failure → battery backup, graceful shutdown
```

---

## 3. Demo Safety

- Build a **simulated sensor feed** as fallback so one flaky smoke sensor doesn't take down the whole live demo
- This is the single most likely thing to embarrass you on stage
- Outdoor conditions are unpredictable — test indoors with a smoke source (incense/smoke generator)
