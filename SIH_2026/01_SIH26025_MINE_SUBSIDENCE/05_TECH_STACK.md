# SIH26025 — Tech Stack

> Technology choices, difficulty, team familiarity, learning curve, integration risk.

---

## 1. Technology Stack

| Layer | Technology | Why needed | Difficulty | Team familiarity | Learning curve | Integration risk | Failure risk |
|---|---|---|---|---|---|---|---|
| **Hardware** | ESP32-C3/WROOM, Pi 4, sensors | Distributed sensing + edge processing | Med | High | Low | Low | Low |
| **Firmware** | ESP-IDF / Arduino | Sensor interface, mesh comms | Med | High | Low | Low | Low |
| **Networking** | LoRa/Zigbee/Wi-Fi mesh, MQTT | Node-to-gateway comms | Med | High | Low-Med | Med | Med |
| **Backend** | Python (FastAPI) | API, data aggregation | Low-Med | High | Low | Low | Low |
| **Database** | SQLite / InfluxDB | Time-series storage | Low | Med | Low | Low | Low |
| **Dashboard** | Web (React/Plotly) + GIS | Visualization, risk maps | Med | Med | Med | Med | Med |
| **AI/ML** | scikit-learn / TensorFlow | Anomaly detection | Med | Med-Unknown | Med | Med | Med |
| **Security** | Auth, TLS, node identity | Secure comms | Low-Med | Med | Low | Low | Low |
| **Monitoring** | MQTT telemetry, health checks | System health | Low | High | Low | Low | Low |

---

## 2. Difficulty Scores

```
Intrinsic Technical Difficulty:      6/10
Team-Adjusted Difficulty:            4/10
Stack Breadth:                       Medium-High
Team Familiarity:                    High (embedded/network) / Medium-Unknown (time-series ML)
Learning Curve:                      Low-Medium
Integration Difficulty:              Medium
Debugging Difficulty:                Medium
Hardware–Software Coupling:          High
Infrastructure Requirement:          Low
External Dependency Risk:            Low
36-Hour Feasibility:                 High
Failure Surface:                     Medium (4–5 independent components)
Prototype Compression:               High
ULTRON Compatibility:                Very High
```

---

## 3. Key Insight

Every hop except the ML layer is something ULTRON's existing bill of materials already exercises. The one genuinely new skill is time-series anomaly detection — and it doesn't need to be sophisticated: a threshold/statistical-drift model or a small autoencoder is defensible.

**Genuine difficulty or tool-newness?** Mostly genuine. Getting a believable, low-noise signal out of cheap sensors and turning it into a trustworthy alert is a real engineering problem, not a "we don't know this library" problem.
