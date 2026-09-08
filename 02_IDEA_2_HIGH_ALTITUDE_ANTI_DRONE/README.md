# Squad 2 — SIH26050: High-Altitude Performance Optimization & Robust Design of Anti-Drone System

> SIH 2026 Round 2 · **Active** · DRDO · **Squad 2**

---

## Your Mission

**You own this workspace.** This is Squad 2's home for everything related to SIH26050 — research, design, decisions, and eventually the build.

The team lead has given you **complete freedom** over the research. There is no prescribed path, no fixed reading list, no "right answer" you must find. Your job is to go deep, question everything, and come back with the strongest possible understanding of the problem and the best solution approach.

> 💰 **Budget:** ₹3,000 allotted for this project — spend it where it adds the most credibility.

> 📍 **Current phase:** Planning & Deep Research. The idea deadline is **20 September 2026**.

> 📌 **Decision:** Selected as an active project on 2026-09-08 (see [`../00_TEAM_WORKSPACE/DECISIONS/DECISION_001_PROJECT_SELECTION.md`](../00_TEAM_WORKSPACE/DECISIONS/DECISION_001_PROJECT_SELECTION.md)). The previous second project (SIH26178) is archived under [`../04_INITIAL_IDEA_RESEARCH/Rejected_Ideas/`](../04_INITIAL_IDEA_RESEARCH/Rejected_Ideas/).

---

## The Problem (in one paragraph)

Build an anti-drone system that maintains detection, tracking, identification and neutralization performance at **high altitude** (Ladakh-type environments) where extreme cold, low pressure, dust, snow and high wind degrade standard electronics, batteries, sensors and mechanical components. The system must address **micro-radian level pointing and tracking accuracy** retention under these conditions.

**Your task:** Design and build an anti-drone system that keeps working — and keeps pointing accurately — when everything around it is trying to freeze, starve, sandblast, and shake it apart.

---

## Your Workspace Map

```
02_IDEA_2_HIGH_ALTITUDE_ANTI_DRONE/
├── README.md              ← you are here (this guide)
├── PREVIOUS_ANALYSIS/     ← everything from the earlier phase (frozen reference)
└── WORKSPACE/             ← YOUR blank canvas — starts empty, you shape it
```

That's it. Two folders:

- **`PREVIOUS_ANALYSIS/`** — the team's earlier work, archived as reference. Read it, then move on.
- **`WORKSPACE/`** — **yours.** It starts empty on purpose. Organize it however your research needs — add files, create subfolders, restructure as you go. There is no prescribed layout.

---

## The Previous Analysis (read it, then challenge it)

Everything the team produced before this restructure lives in **`PREVIOUS_ANALYSIS/`**:

| File | What it covers |
|---|---|
| `PS01_SIH26050_ANALYSIS.md` | Seed analysis: problem deep-dive, 4 solution approaches evaluated, architecture design, hardware gap analysis, component budget (₹3,500–5,500), 4-week timeline |

**How to treat it:**

- ✅ **Use it as a head start** — it contains real analysis and hard-won context (the ULTRON architecture fit, the hardware gap list, the budget reality).
- ✅ **Verify and deepen it** — every claim in there is fair game to re-check, extend, or improve in your workspace.
- ✅ **Challenge it** — if you find something wrong or outdated, say so. Record your correction in `WORKSPACE/`.
- ❌ **Don't delete or rewrite it** — it's the team's history and the basis for the decision record.

---

## What to Research (suggested starting points)

This is **your** research — these are launch questions, not a checklist. Go where the evidence takes you.

### 1. Problem & Domain Depth
- What is the actual threat landscape? (drone types, sizes, altitudes, speeds — what must an anti-drone system detect?)
- What does "micro-radian pointing accuracy" really mean, and what breaks it at high altitude?
- What are the real operating conditions in Ladakh-type environments? (temperature ranges, pressure, wind, dust, snow — find the data)
- Who are the actual users and what do they need? (DRDO, armed forces, border security)

### 2. Existing Solutions & Gap
- What anti-drone systems exist today? (commercial, military, Indian — DRDO's own systems, international systems)
- How do they perform at high altitude, and why do they degrade?
- What's the gap this project can honestly fill? (be honest — don't overclaim)

### 3. Environmental Robustness
- How do extreme cold, low pressure, dust, snow, and wind degrade electronics, batteries, sensors, and mechanics?
- Thermal management: what actually works? (heated compartments, insulation, conformal coating, component selection)
- Battery behavior at −30°C and below — what chemistry survives? (LiFePO4 vs Li-ion vs others)
- Component selection for harsh environments: cables, connectors, oscillators (TCXO), enclosures (IP ratings)

### 4. Detection, Tracking & Pointing
- RF detection, EO/IR, radar, acoustic — what are the trade-offs, and what's feasible with our hardware?
- Gimbal/pointing systems: how is micro-radian accuracy achieved and maintained?
- What can we buy within **₹3,000** that adds the most credibility? (sensors, gimbal parts, hardening materials — and what stays simulated?)

### 5. Solution Approaches
- Compare 2-3 fundamentally different solution approaches (not just variations of one)
- What's the smallest credible MVP that proves the concept?

---

## How to Work

1. **Research** — explore freely. Save what you find in `WORKSPACE/` as new files (one topic per file, meaningful names).
2. **Discuss** — bring findings back to the squad. Debate. The best idea wins, not the loudest voice.
3. **Decide** — when the squad agrees, record the decision in [`../00_TEAM_WORKSPACE/DECISIONS/`](../00_TEAM_WORKSPACE/DECISIONS/) (follow the template in `DECISION_001_PROJECT_SELECTION.md`).
4. **Document** — keep `WORKSPACE/` navigable so the next person can find things.

**Ground rules (light, but firm):**

- 📁 **One topic per file** — research files should be focused and findable.
- 🔗 **Cite your sources** — links, papers, videos. If it's not sourced, it's an opinion.
- 🗂️ **Meaningful filenames** — `thermal_management_papers.md` beats `research_final_v2.md`.
- 🧊 **Never delete research** — if something is superseded, mark it `[SUPERSEDED]` in a banner, don't delete.
- 📝 **Record decisions** — a decision that isn't recorded didn't happen.

---

## Resources at Your Disposal

| Resource | Location |
|---|---|
| Zero-budget strategy (shared reference — Squad 1's constraint) | [`../00_TEAM_WORKSPACE/SHARED_RESOURCES/ZERO_BUDGET_STRATEGY.md`](../00_TEAM_WORKSPACE/SHARED_RESOURCES/ZERO_BUDGET_STRATEGY.md) |
| Hardware capability baseline | [`../03_SHARED_TECH/HARDWARE_CAPABILITY_BASELINE.md`](../03_SHARED_TECH/HARDWARE_CAPABILITY_BASELINE.md) |
| ULTRON reference implementation | [`../03_SHARED_TECH/ULTRON/`](../03_SHARED_TECH/ULTRON/) |
| Team decision records | [`../00_TEAM_WORKSPACE/DECISIONS/`](../00_TEAM_WORKSPACE/DECISIONS/) |
| Original problem statement analysis | [`../04_INITIAL_IDEA_RESEARCH/Original_Research/`](../04_INITIAL_IDEA_RESEARCH/Original_Research/) |
| Top 13 shortlist analysis (PS 01 = this problem) | [`../04_INITIAL_IDEA_RESEARCH/Top_13_Ideas_Analysis/PS 01.md`](../04_INITIAL_IDEA_RESEARCH/Top_13_Ideas_Analysis/PS%2001.md) |
| Repo workflow & naming conventions | [`../docs/REPO_WORKFLOW.md`](../docs/REPO_WORKFLOW.md), [`../docs/NAMING_CONVENTIONS.md`](../docs/NAMING_CONVENTIONS.md) |

---

## What "Done" Looks Like for This Phase

When the research phase is complete, the squad should be able to answer:

1. What is the problem, precisely, and who suffers from it?
2. What exists today, and why is it insufficient?
3. What is our chosen solution approach, and why is it the best of the options?
4. What is the smallest credible MVP, and what does it prove?
5. What are the top risks, and how do we retire them?

When you can answer all five with evidence, you're ready for the design phase.

---

**Go explore. `WORKSPACE/` is yours.**