# SIH26178 — Tech Stack

> Technology choices, difficulty, team familiarity, learning curve, integration risk.

---

## 1. Technology Stack

| Layer | Technology | Why needed | Difficulty | Team familiarity | Learning curve | Integration risk | Failure risk |
|---|---|---|---|---|---|---|---|
| **Hardware** | ESP32-C3/WROOM, Pi 4, sensors | Distributed sensing + edge processing | Med | High | Low | Low | Low |
| **Firmware** | ESP-IDF / Arduino | Sensor interface, mesh comms | Med | High | Low | Low | Low |
| **Networking** | LoRa/Zigbee/Wi-Fi mesh, MQTT | Node-to-gateway comms | Med | High | Low-Med | Med | Med |
| **Edge AI** | TFLite Micro / scikit-learn | On-device inference | Med-High | Med-Unknown | Med-High | Med | Med |
| **Backend** | Python (FastAPI) | API, data aggregation | Med | High | Low | Low | Low |
| **Database** | SQLite / InfluxDB | Time-series storage | Low | Med | Low | Low | Low |
| **Dashboard** | Web (React/Plotly) + GIS | Visualization, risk maps | Med | Med | Med | Med | Med |
| **Alert integration** | SACHET/CAP API | Feed national alert bus | Med | Low-Unknown | Med | Med-High | Med |
| **Security** | Auth, TLS, node identity | Secure comms | Low-Med | Med | Low | Low | Low |

---

## 2. Difficulty Scores

```
Intrinsic Technical Difficulty:      6/10 (sensor-only: 5/10)
Team-Adjusted Difficulty:            5-6/10 (sensor-only: 3/10)
Stack Breadth:                       High (broadest)
Team Familiarity:                    High (embedded/network) / Medium-Unknown (edge AI, SACHET)
Learning Curve:                      Medium
Integration Difficulty:              Medium-High
Debugging Difficulty:                Medium-High (CV debugging is slow)
Hardware–Software Coupling:          High
Infrastructure Requirement:          Low
External Dependency Risk:            Medium (SACHET/CAP API)
36-Hour Feasibility:                 Medium (High if scope cut to one hazard)
Failure Surface:                     Medium-High (more moving parts)
Prototype Compression:               Medium
ULTRON Compatibility:                Very High
```

---

## 3. Key Insight

The stack is the **broadest** of any candidate — the "AI-powered" framing pushes toward computer vision (flame/smoke detection), which is a real, currently-unproven skill for this team.

**There's a lower-difficulty path:** sensor-only with a lightweight fusion classifier. It's less visually dramatic but keeps the project in the "genuine problem difficulty" bucket rather than the "impressive but fragile" bucket.

**Recommendation:** Keep the sensor-only route as the default plan; treat vision as a stretch goal only if bench time allows.
