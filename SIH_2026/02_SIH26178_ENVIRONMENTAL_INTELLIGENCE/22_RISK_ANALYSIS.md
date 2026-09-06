# SIH26178 — Risk Analysis

> What could go wrong, and how do we mitigate it?

---

## 1. Risk Register

| Risk | Likelihood | Impact | Mitigation |
|---|---|---|---|
| **High competition** | High | High | Differentiate on SACHET/CAP integration + multi-sensor fusion + offline capability |
| **Qualcomm platform expectation** | Med | High | Frame ULTRON as low-cost field-node layer, silicon-agnostic, portable to Dragonwing at production scale |
| **Scope creep (3 hazard types)** | High | Med | Pick ONE hazard (fire) as deep MVP; others as same-architecture future-node slides |
| **CV skill gap** | Med | Med | Keep sensor-only route as default; treat vision as stretch goal only |
| **Outdoor unpredictability** | Med | Med | Test indoors with smoke source; weatherproof enclosures |
| **SACHET/CAP API access** | Med | Med | Build a CAP-format simulator for demo; real integration is roadmap |
| **Sensor false positives** | Med | Med | Multi-sensor fusion + mesh correlation |
| **Demo hardware failure** | Med | High | Simulated sensor feed fallback |

---

## 2. Risk Mitigation Summary

1. **Competition** → SACHET/CAP integration is the differentiator most teams miss
2. **Qualcomm expectation** → silicon-agnostic framing, portable to Dragonwing
3. **Scope creep** → one-hazard MVP (fire), others as slides
4. **CV skill gap** → sensor-only route as default
5. **Demo failure** → simulated feed fallback

---

## 3. Key Risk: Qualcomm Platform Expectation

Qualcomm may expect Snapdragon/Dragonwing hardware. Pre-empt by:
- Framing ULTRON as the **low-cost field-node layer**
- Emphasizing **silicon-agnostic** architecture
- Showing **portability to Dragonwing** at production scale
- Positioning our ESP32/Pi stack as the cost-optimized field tier, not a competitor to Qualcomm silicon
