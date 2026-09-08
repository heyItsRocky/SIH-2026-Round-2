# Squad 1 — SIH26025: AI-Enabled Mine Subsidence Monitoring & Early Warning

> SIH 2026 Round 2 · **Active** · Ministry of Coal / Coal India Limited · **Squad 1**

---

## Your Mission

**You own this workspace.** This is Squad 1's home for everything related to SIH26025 — research, design, decisions, and eventually the build.

The team lead has given you **complete freedom** over the research. There is no prescribed path, no fixed reading list, no "right answer" you must find. Your job is to go deep, question everything, and come back with the strongest possible understanding of the problem and the best solution approach.

> ⚠ **ZERO-BUDGET MODE:** No budget for new sensors. The distributed mesh, edge AI, correlation, dashboard, and alerting are built for real on existing hardware; only the physical transducers are software-simulated. See [`../00_TEAM_WORKSPACE/SHARED_RESOURCES/ZERO_BUDGET_STRATEGY.md`](../00_TEAM_WORKSPACE/SHARED_RESOURCES/ZERO_BUDGET_STRATEGY.md).

> 📍 **Current phase:** Planning & Deep Research. The idea deadline is **20 September 2026**.

---

## The Problem (in one paragraph)

Surface subsidence caused by underground coal mining poses significant risks to nearby communities, public infrastructure, agricultural land, forest areas, and the surrounding environment. India currently relies on conventional field observations, periodic surveys, and post-facto damage assessments — which fail to provide timely warning before critical ground failure.

**Your task:** Build an AI-enabled, low-cost, real-time subsidence monitoring platform based on a **localized wireless surface mesh sensor network** deployed above underground mine panels, with AI/ML anomaly detection, subsidence prediction, GIS visualization, and automated early warning alerts.

---

## Your Workspace Map

```
01_IDEA_1_MINE_SUBSIDENCE/
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
| `01_PROBLEM_AND_RESEARCH.md` | Problem definition, real-world research, existing solutions, gap analysis |
| `02_TECHNICAL_DESIGN.md` | Tech stack, hardware mapping, sensor selection, node architecture, network, data pipeline, AI/ML strategy |
| `03_OPERATIONS_AND_DEMO.md` | Failure modes, security/reliability, testing, demo plan, cost/BOM |
| `04_PITCH_AND_QA.md` | Pitch framing, judge Q&A, potential attacks |
| `SIH26025-...pptx` | Pitch deck from the earlier phase |

**How to treat it:**

- ✅ **Use it as a head start** — it contains real research and hard-won context (e.g., the mesh-correlation constraint, the DGMS accident evidence).
- ✅ **Verify and deepen it** — every claim in there is fair game to re-check, extend, or improve in your workspace.
- ✅ **Challenge it** — if you find something wrong or outdated, say so. Record your correction in `WORKSPACE/`.
- ❌ **Don't delete or rewrite it** — it's the team's history and the basis for the decision record.

---

## What to Research (suggested starting points)

This is **your** research — these are launch questions, not a checklist. Go where the evidence takes you.

### 1. Problem & Domain Depth
- How does underground coal mining actually cause surface subsidence? (mechanisms, timelines, failure modes)
- What does the current monitoring landscape look like in India? (DGMS, CMPDI, CIL subsidiaries — what do they actually use today?)
- What are the real-world consequences and documented incidents? (find the evidence — accident records, news, academic papers)
- Who are the actual users and what do they need? (mine operators, planners, regulators, communities)

### 2. Existing Solutions & Gap
- What commercial/academic/government systems already exist for subsidence monitoring?
- What do they cost, and why haven't they been deployed at scale in Indian coal mines?
- What's the gap this project can honestly fill? (be honest — don't overclaim)

### 3. Sensor & Hardware Technology
- Tilt, vibration, displacement, crack detection — what sensors exist, what do they cost, what are their limits?
- What can we do with **zero budget**? (simulated transducers, existing hardware, free signals)
- Mesh networking: LoRa vs Zigbee vs Wi-Fi — trade-offs for this use case

### 4. AI/ML Approach
- Anomaly detection on time-series sensor data — what actually works?
- Subsidence prediction — what's realistic vs overclaimed?
- Edge inference on Pi 4B / ESP32 — what's feasible?

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
- 🗂️ **Meaningful filenames** — `sensor_comparison.md` beats `research_final_v2.md`.
- 🧊 **Never delete research** — if something is superseded, mark it `[SUPERSEDED]` in a banner, don't delete.
- 📝 **Record decisions** — a decision that isn't recorded didn't happen.

---

## Resources at Your Disposal

| Resource | Location |
|---|---|
| Zero-budget strategy (read this first) | [`../00_TEAM_WORKSPACE/SHARED_RESOURCES/ZERO_BUDGET_STRATEGY.md`](../00_TEAM_WORKSPACE/SHARED_RESOURCES/ZERO_BUDGET_STRATEGY.md) |
| Hardware capability baseline | [`../03_SHARED_TECH/HARDWARE_CAPABILITY_BASELINE.md`](../03_SHARED_TECH/HARDWARE_CAPABILITY_BASELINE.md) |
| ULTRON reference implementation | [`../03_SHARED_TECH/ULTRON/`](../03_SHARED_TECH/ULTRON/) |
| Team decision records | [`../00_TEAM_WORKSPACE/DECISIONS/`](../00_TEAM_WORKSPACE/DECISIONS/) |
| Original problem statement analysis | [`../04_INITIAL_IDEA_RESEARCH/Original_Research/`](../04_INITIAL_IDEA_RESEARCH/Original_Research/) |
| Top 13 shortlist analysis (PS 12 = this problem) | [`../04_INITIAL_IDEA_RESEARCH/Top_13_Ideas_Analysis/PS 12.md`](../04_INITIAL_IDEA_RESEARCH/Top_13_Ideas_Analysis/PS%2012.md) |
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