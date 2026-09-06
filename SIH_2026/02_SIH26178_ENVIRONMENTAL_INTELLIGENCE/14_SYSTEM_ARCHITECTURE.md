# SIH26178 — System Architecture

> The one master architecture.

---

## 1. Master Architecture

```
                    ┌─────────────────────────────────────────────┐
                    │            DEPLOYMENT AREA                 │
                    │                                             │
   ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐        │
   │ Node A   │  │ Node B   │  │ Node C   │  │ Node D   │        │
   │ Fire     │  │ Air Qual │  │ Fire     │  │ Heat/Dry │        │
   │ Smoke+Temp│ │ PM2.5+Gas│  │ Smoke+Temp│ │ Temp+Soil│        │
   └────┬─────┘  └────┬─────┘  └────┬─────┘  └────┬─────┘        │
        │             │             │             │              │
        └─────────────┼─────────────┼─────────────┘              │
                      │   Mesh (LoRa/Zigbee/Wi-Fi)               │
                      ▼                                          │
              ┌───────────────┐                                  │
              │   Gateway     │                                  │
              │   (Pi 4)      │                                  │
              └───────┬───────┘                                  │
                      │                                          │
        ┌─────────────┼─────────────┐                            │
        ▼             ▼             ▼                            │
┌─────────────┐ ┌─────────────┐ ┌─────────────┐                 │
│ Local       │ │ Edge AI     │ │ GPIO Alarm  │                 │
│ Storage     │ │ Anomaly     │ │ OLED/NeoPix │                 │
│ (SSD)       │ │ Detection   │ │ (on-site)   │                 │
└─────────────┘ └──────┬──────┘ └─────────────┘                 │
                       │                                         │
                       ▼                                         │
              ┌───────────────┐                                  │
              │  Dashboard    │                                  │
              │  (GIS + Risk) │                                  │
              └───────┬───────┘                                  │
                      │ (when online)                            │
                      ▼                                          │
              ┌───────────────┐                                  │
              │ SACHET/CAP    │                                  │
              │ Alert Push    │                                  │
              └───────────────┘                                  │
                    └────────────────────────────────────────────┘
```

---

## 2. Data Flow

```
Sensors → ESP32 Nodes → Mesh → Gateway (Pi 4) → Local Storage → Edge AI → Dashboard → SACHET/CAP
```

---

## 3. Key Design Principles

1. **Offline-first** — everything works without internet
2. **On-device AI** — edge inference, not cloud dependency
3. **Multi-sensor fusion** — the fire differentiator
4. **Mesh correlation** — distinguishes local vs genuine hazard
5. **SACHET/CAP integration** — feed national alert bus, not a redundant app
6. **Graceful degradation** — one sensor/node failure doesn't kill the system
