# SIH26178 — Pitch & Judge Q&A

> Everything the judges could attack. Prepare answers in advance.

---

## 1. Critical Questions & Answers

### Q: "Why not just use IMD/ISRO satellite data?"
**A:** "Satellite monitoring is accurate but not local or real-time — it has multi-day revisit gaps. Our network gives village/ward-level, minutes-not-hours ground truth between satellite revisits. We complement, not replace, IMD/ISRO systems."

### Q: "Why not build a new alert app?"
**A:** "NDMA already has SACHET/CAP — the national Common Alerting Protocol infrastructure. Building a redundant standalone app is wasteful and won't be adopted. We feed our alerts into the existing SACHET/CAP bus. Most teams won't find this."

### Q: "Why Qualcomm hardware isn't in your stack?"
**A:** "Our ESP32/Pi stack is the low-cost field-node layer — the cost-optimized tier for dense deployment. The architecture is silicon-agnostic and portable to Snapdragon/Dragonwing at production scale. We're not competing with Qualcomm silicon; we're building the field tier that feeds it."

### Q: "Why not use computer vision for fire detection?"
**A:** "Vision is a stretch goal. Our sensor-only route uses multi-sensor fusion — combining smoke, temperature, and humidity to distinguish a real fire from a false alarm. It's lower difficulty, more robust, and honest. Vision adds drama but also fragility."

### Q: "How do you handle MQ-2 cross-sensitivity?"
**A:** "We don't trust the smoke sensor alone. We fuse smoke + temperature + humidity: smoke high + temp high + humidity low → likely fire; smoke high + temp normal + humidity normal → likely false alarm (other gas). This is the multi-sensor fusion differentiator."

### Q: "What happens if a sensor fails?"
**A:** "The system degrades gracefully. A failed sensor is flagged, and the remaining nodes continue monitoring. Mesh correlation is still computed from available nodes. We show this in the demo — disconnect one node, system continues."

### Q: "How do you validate without real field data?"
**A:** "We use a physical test rig with a smoke source (incense/smoke generator) to simulate hazards. We validate the detection logic on public fire/air-quality case-study data. We are upfront that this is a prototype compression — not a certified disaster-monitoring instrument."

---

## 2. Potential Attacks

| Attack | Defense |
|---|---|
| "Your sensors aren't validated against real disasters" | We are a decision-support early-indicator, not a certified instrument |
| "Isn't this just IMD with extra steps?" | IMD is satellite-based and regional; we are local and real-time |
| "Why not just deploy more commercial stations?" | Cost-per-node comparison — our solution is orders of magnitude cheaper |
| "How is this different from existing IoT monitoring?" | Multi-sensor fusion + mesh correlation + SACHET/CAP integration |
| "What about SACHET/CAP API access?" | We build a CAP-format simulator for demo; real integration is roadmap |
| "Why not cover all 8 hazards?" | One-hazard MVP (fire) is the deep, credible build; others are same-architecture future nodes |

---

## 3. Key Framing

> "We built a decision-support early-indicator layer that feeds NDMA's existing alert infrastructure — not a redundant standalone app. That honesty and integration insight reads as more credible under judge questioning than an overclaimed pitch."
