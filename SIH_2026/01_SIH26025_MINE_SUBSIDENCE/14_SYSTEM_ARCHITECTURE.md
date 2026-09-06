# SIH26025 — System Architecture

> The one master architecture.

---

## 1. Master Architecture

```
                    ┌─────────────────────────────────────────────┐
                    │              MINE SURFACE                   │
                    │                                             │
   ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐        │
   │ Node A   │  │ Node B   │  │ Node C   │  │ Node D   │        │
   │ Tilt+Vib │  │ Disp+Crack│ │ Tilt+GPS │  │ Vib+Crack│        │
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
              └───────────────┘                                  │
                       │                                         │
                       ▼ (when online)                           │
              ┌───────────────┐                                  │
              │  Cloud Sync   │                                  │
              │  SMS/Email    │                                  │
              └───────────────┘                                  │
                    └────────────────────────────────────────────┘
```

---

## 2. Data Flow

```
Sensors → ESP32 Nodes → Mesh → Gateway (Pi 4) → Local Storage → Edge AI → Dashboard → Alert
```

---

## 3. Key Design Principles

1. **Offline-first** — everything works without internet
2. **Local alerting** — GPIO/OLED/NeoPixel fire on-site
3. **Mesh correlation** — the differentiator
4. **Graceful degradation** — one sensor/node failure doesn't kill the system
5. **Honest framing** — early anomaly detection, not validated geoscience
