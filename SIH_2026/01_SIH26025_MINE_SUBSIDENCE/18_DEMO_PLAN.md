# SIH26025 — Demo Plan

> Literally script the live demonstration. The judge should see the system working, not watch someone click around a dashboard.

---

## 1. Demo Script

```
0:00 → Explain the problem (30 sec)
       "Underground coal mining causes surface subsidence. Current monitoring is
        periodic manual survey — no continuous signal between visits."

0:30 → Show physical nodes (30 sec)
       "Here are our distributed sensor nodes — tilt, vibration, displacement,
        crack detection, mesh-networked to the Pi 4 gateway."

1:00 → Disturb one node (5 sec)
       Physically tilt/vibrate Node A.

1:05 → Dashboard detects movement (10 sec)
       "Node A shows deviation. But is this real ground movement or a local
        disturbance? Watch the correlation."

1:15 → Show neighboring-node comparison (15 sec)
       "Nodes B, C, D are stable. Correlation score is low. This is a LOCAL
        disturbance, not subsidence. No false alarm."

1:30 → Trigger simulated deformation (10 sec)
       Tilt multiple adjacent nodes together.

2:00 → Alert generated (30 sec)
       "Multiple adjacent nodes deviating in a correlated pattern — this is
        genuine ground movement. RED alert. GPIO alarm fires, OLED shows warning,
        SMS/email sent."

2:30 → Show offline capability (30 sec)
       "Now we disconnect the network. The system keeps monitoring locally,
        buffers data, and alerts fire on-site. On reconnect, data syncs."

3:00 → Close (30 sec)
       "Survey-based monitoring is accurate but not continuous. We add a
        continuous, local, offline layer between survey cycles."
```

---

## 2. Key Demo Principles

1. **Show the system working** — not clicking around a dashboard
2. **Demonstrate the differentiator** — mesh correlation (local vs genuine)
3. **Show offline capability** — the hidden constraint
4. **Keep it under 4 minutes** — judges have limited attention
5. **Have a fallback** — simulated sensor feed if hardware fails

---

## 3. What Judges Should Remember

> "They built a distributed mesh that distinguishes local disturbance from genuine ground movement, and it works offline."
