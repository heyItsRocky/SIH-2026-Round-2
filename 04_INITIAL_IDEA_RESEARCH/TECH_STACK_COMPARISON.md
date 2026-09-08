# Tech Stack Comparison — SIH26025 vs SIH26178

> Compares the actual difficulty of building both ideas.
> Which one gives us the best return for the engineering complexity we have to absorb?

---

## 1. Difficulty Matrix

| Skill Area | SIH26025 | SIH26178 | Notes |
|---|---|---|---|
| AI/ML | Low-Med | Med-High | 26025: time-series anomaly detection; 26178: edge CV (if vision route) |
| Embedded | Med | Med | Both need ESP32 sensor firmware |
| Networking | Med | Med | Both need mesh + MQTT |
| Sensors | Med | Med | 26025: tilt/vibration/strain; 26178: environmental sensors |
| Edge computing | Med | Med-High | 26178 pushes toward on-device AI inference |
| Backend | Low-Med | Med | Both need MQTT broker + API |
| Frontend | Med | Med | Both need dashboard + GIS map |
| Data engineering | Med | Med | Both need data pipeline + storage |
| Security | Low-Med | Med | 26178 needs node auth, secure comms |
| Hardware | Med | Med | Both need new sensors + power |
| Integration | Med | Med-High | 26178 has more moving parts (multi-hazard) |
| Debugging | Med | Med-High | 26178 CV debugging is slow |
| Learning curve | Low-Med | Med | 26025: time-series ML; 26178: CV + alert protocols |
| 36-hour feasibility | High | Medium | 26025 narrower scope; 26178 needs scope cut |
| Failure surface | Medium | Medium-High | 26025: 4-5 components; 26178: more |

---

## 2. Summary Scores

| Metric | SIH26025 | SIH26178 |
|---|---|---|
| Intrinsic Technical Difficulty | 6/10 | 6/10 (sensor-only: 5/10) |
| Team-Adjusted Difficulty | 4/10 | 5-6/10 (sensor-only: 3/10) |
| Stack Breadth | Medium-High | High (broadest) |
| 36-Hour Feasibility | High | Medium (High if scope cut to one hazard) |

---

## 3. Key Insight

**SIH26025** has the **best difficulty-to-value ratio** — the stack is sensor → ESP32 → mesh → Pi 4 anomaly detection → alarm → dashboard, and every hop except the ML layer is something ULTRON already exercises.

**SIH26178** has the **broadest stack** — the "AI-powered" framing pushes toward computer vision (flame/smoke detection), which is a real, currently-unproven skill for this team. There's a lower-difficulty path (sensor-only with a lightweight fusion classifier), but it's less visually dramatic.

**Recommendation:** For SIH26178, keep the sensor-only route as the default plan and treat vision as a stretch goal only if bench time allows. This keeps the project in the "genuine problem difficulty" bucket rather than the "impressive but fragile" bucket.

---

## 4. Decision Input

The two problems should NOT be compared only on "which sounds better." They should be compared on:

> **Which one gives us the best return for the amount of engineering complexity we have to absorb?**

Based on this matrix, **SIH26025 gives the better return** — lower team-adjusted difficulty, narrower scope, and the same ULTRON leverage.
