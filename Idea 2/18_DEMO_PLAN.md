# SIH26178 — Demo Plan

> Literally script the live demonstration. The judge should see the system working, not watch someone click around a dashboard.

---

## 1. Demo Script

```
0:00 → Explain the problem (30 sec)
       "India faces floods, fires, pollution, heat. Satellite monitoring is
        accurate but not local or real-time. Villages and wards have no
        minutes-not-hours ground truth."

0:30 → Show physical nodes (30 sec)
       "Here are our distributed sensor nodes — smoke, temperature, humidity,
        PM2.5, gas. Mesh-networked to the Pi 4 gateway. Each node runs
        on-device AI inference."

1:00 → Trigger smoke near one node (10 sec)
       Light incense/smoke generator near Node A.

1:10 → Dashboard detects smoke (10 sec)
       "Node A shows elevated smoke. But is this a fire or a false alarm?
        Watch the fusion score."

1:20 → Show fusion + correlation (20 sec)
       "Smoke is high, but temperature is normal and humidity is normal.
        Fusion score is low. Neighboring nodes are stable. This is a LOCAL
        disturbance, not a fire. No false alarm."

1:40 → Trigger simulated fire (10 sec)
       Smoke + heat + low humidity across multiple adjacent nodes.

2:00 → Alert generated (30 sec)
       "Multiple adjacent nodes showing correlated smoke + heat + dryness —
        this is a genuine fire signature. RED alert. GPIO alarm fires, OLED
        shows warning, SACHET/CAP push to NDMA."

2:30 → Show offline capability (30 sec)
       "Now we disconnect the network. The system keeps monitoring locally,
        runs on-device AI, buffers data, and alerts fire on-site. On
        reconnect, data syncs."

3:00 → Close (30 sec)
       "Satellite monitoring is accurate but not local or real-time. We add a
        dense, low-cost, offline-capable local sensing layer that feeds
        NDMA's existing alert infrastructure."
```

---

## 2. Key Demo Principles

1. **Show the system working** — not clicking around a dashboard
2. **Demonstrate the differentiator** — multi-sensor fusion + mesh correlation
3. **Show offline capability** — the hidden constraint
4. **Show SACHET/CAP integration** — the insight most teams miss
5. **Keep it under 4 minutes** — judges have limited attention
6. **Have a fallback** — simulated sensor feed if hardware fails

---

## 3. What Judges Should Remember

> "They built a distributed mesh that distinguishes a real fire from a false alarm using multi-sensor fusion, works offline, and feeds NDMA's existing alert infrastructure."
