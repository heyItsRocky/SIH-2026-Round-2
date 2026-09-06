# SIH26025 — Gap Analysis

> What exactly are we solving that existing solutions don't solve well?

---

## 1. Gap Chain

```
Existing system: Periodic manual survey + post-facto damage assessment
      ↓
Limitation: No continuous ground-truth feed between survey cycles
      ↓
Why it matters: Warning only exists AFTER a surveyor visits; critical ground failure happens between visits
      ↓
Our opportunity: Continuous, local, offline-capable monitoring layer between survey cycles
```

---

## 2. Specific Gaps

| Gap | Existing coverage | Our solution |
|---|---|---|
| Continuous real-time monitoring | No (periodic survey) | Continuous mesh sensing |
| Local edge alarm | No (cloud dashboard only) | GPIO alarm + OLED/NeoPixel on-site |
| Offline operation | No (needs internet) | Local buffering + periodic sync |
| Mesh-level correlation | No (single-sensor thresholds) | Multi-node deformation correlation |
| Low-cost scalable | No (expensive InSAR/GNSS/SSR) | Cheap ESP32 nodes |
| AI-scored early warning | No (manual assessment) | Edge AI anomaly detection |

---

## 3. One-Sentence Differentiation

> **"Survey-based monitoring (InSAR/GNSS/total-station) is accurate but not continuous; we add a continuous, local, offline layer between survey cycles."**

---

## 4. Why This Gap Is Real (Evidence)

- DGMS mandates slope monitoring (2020 circular) — regulatory tailwind
- SSR exists only for opencast pits — underground subsidence unaddressed
- CSIR Goafwarn is proprietary and not broadly available
- Academic WSN papers prove concept but aren't productized
- No evidence of a mature, DGMS-certified, low-cost, real-time underground-subsidence product on the Indian market
