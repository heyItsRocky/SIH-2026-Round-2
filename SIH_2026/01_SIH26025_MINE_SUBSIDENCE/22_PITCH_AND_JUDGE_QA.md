# SIH26025 — Pitch & Judge Q&A

> Everything the judges could attack. Prepare answers in advance.

---

## 1. Critical Questions & Answers

### Q: "Are you actually predicting collapse?"
**A:** "No. We are building an early anomaly detection network — a continuous, local monitoring layer that detects deformation patterns between survey cycles. This is a decision-support early-indicator, not a certified structural-safety instrument. We explicitly frame it as complementing, not replacing, existing InSAR/GNSS survey systems."

### Q: "Why not just use one sensor?"
**A:** "A single-sensor threshold alarm cannot distinguish between a local disturbance and genuine ground movement. The sponsor's own PS text explicitly asks for 'relative distance between nodes changing over time' — mesh-level deformation correlation. Our system compares each node against its neighbors to filter false alarms."

### Q: "Why Raspberry Pi?"
**A:** "The Pi 4 is our gateway and edge-AI platform. The actual sensor nodes are ESP32s — the Pi isn't deployed in the field, it's the aggregation point. The architecture is silicon-agnostic and could run on any Linux SBC."

### Q: "Why not LoRa?"
**A:** "We support multiple mesh protocols — LoRa, Zigbee, or Wi-Fi — depending on deployment. Our architecture is protocol-agnostic at the mesh layer. The intelligence is in the correlation logic, not the transport."

### Q: "What happens if a sensor fails?"
**A:** "The system degrades gracefully. A failed sensor is flagged, and the remaining nodes continue monitoring. Mesh correlation is still computed from available nodes. We show this in the demo — disconnect one node, system continues."

### Q: "How do you validate without real mines?"
**A:** "We use a physical scale-model rig with embedded sensors to simulate ground movement. We validate the prediction/alerting logic on public InSAR case-study data. We are upfront that this is a prototype compression — not a certified safety instrument."

### Q: "How is this different from Goafwarn?"
**A:** "Goafwarn is a proprietary, expensive system not broadly available to Coal India's contractors. We build a low-cost, open, scalable alternative that uses commercially available ESP32/Pi hardware and can be deployed at scale across multiple coalfields."

---

## 2. Potential Attacks

| Attack | Defense |
|---|---|
| "Your sensors aren't validated against real geology" | We are a decision-support early-indicator, not a certified safety instrument |
| "Isn't this just InSAR with extra steps?" | InSAR is periodic and site-selected; we are continuous and local |
| "Why not just deploy more GNSS stations?" | Cost-per-node comparison — our solution is orders of magnitude cheaper |
| "How is this different from existing academic WSN papers?" | We are building a deployable product with AI-scored correlation, not a research prototype |
| "What about DGMS certification?" | Future work — flag as a roadmap item, don't overclaim compliance |

---

## 3. Key Framing

> "We built a decision-support early-indicator layer, not a validated geoscience prediction model. That honesty reads as more credible under judge questioning than an overclaimed pitch."