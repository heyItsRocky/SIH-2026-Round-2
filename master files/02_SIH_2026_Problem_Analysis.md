# SIH 2026 Problem Analysis

> The evidence layer — what we found during the broad search of all 233 problem statements.
> This document represents the research findings and should NOT be constantly modified as opinions change.

---

## 1. Scope

All 233 official SIH 2026 problem statements (SIH26001–SIH26233) were screened against:
- Organization seriousness
- Data accessibility
- ULTRON structural fit
- Technical feasibility
- Competition density

---

## 2. Initial Filtering Results

### 2.1 Wholesale Eliminations

| Cluster | Count | Why eliminated |
|---|---|---|
| AICTE "Student Innovation" generic themes (#193–226) | 44 | Category labels, not problem statements; no institutional buyer |
| NTRO cyber-forensics / SOC / crypto-audit (#145,148–150,153,155–157,159–160,164,151–152) | ~15 | Classified data, live SOC environments, deep specialization |
| ISRO deep space-tech (#166,170,174) | ~5 | Mission-specific data, hardware test environments |
| DRDO defense-hardware (#49,50,52,98) | 4 | Defense-spec components, environmental test chambers, munitions |
| MoES heavy NWP/oceanography (#66–86) | ~18 | Supercomputer-scale compute, proprietary IMD data |
| Metrology/compliance test rigs (#29,30) | 2 | Certified lab equipment |
| Chemistry/pharma (#46,48) | 2 | Regulatory compliance, food-process engineering |
| Quantum computing (Egreen Quanta #137–141) | 5 | "Quantum-inspired" on classical hardware = decoration |
| Autodesk design exercises (#114,116) | 2 | CAD modeling, not system-building |
| Generic chatbot/portal cluster | ~10 | Convergence risk near-total |

**Result:** ~105–110 of 233 eliminated outright or to bottom tier.

### 2.2 Top 20 (post-filter, pre-deep-dive)

| # | PS ID | Problem | Org | PQ | CD | UF | DS | Archetype |
|---|---|---|---|---|---|---|---|---|
| 1 | SIH26025 | Mine subsidence monitoring | Ministry of Coal | H | M | H | H | Sleeper / Hardware-Native |
| 2 | SIH26008 | Conveyor belt rupture | Ministry of Steel | H | M | H | M | Team-Fit Monster |
| 3 | SIH26178 | Environmental intelligence network | Qualcomm | H | M | H | H | Hardware-Native |
| 4 | SIH26039 | Underground mine safety | Jharkhand | H | H | H | L-M | Crowded Giant — demote |
| 5 | SIH26001 | Landslide early warning | MDoNER | H | M-H | M | M | Sleeper, category-mismatch |
| 6 | SIH26144 | Micro-barometer infrasound | NTRO | M | L | L | M | Technical Beast — wrong team |
| 7 | SIH26007 | Mine vehicle fog safety | Ministry of Steel | H | M | M | M | Technical Beast, high HW risk |
| 8 | SIH26064 | Seafloor metal detection | MoES | M | L | M | M | Moonshot |
| 9 | SIH26177 | Autonomous SAR drone | Qualcomm | H | H | L | M | Crowded Giant |
| 10 | SIH26179 | Retail intelligence | Qualcomm | M | M | M | M | Integration Play |
| 11 | SIH26180 | Smart farming assistant | Qualcomm | H | H | M | L | Crowded Giant |
| 12 | SIH26017 | Land-acquisition analytics | Rural Dev | M-H | L | L | M | Workflow Killer |
| 13 | SIH26102 | MPLAD fraud detection | MoSPI | M | L | L | M | Evidence Winner |
| 14 | SIH26073 | AWS anomaly detection | MoES | M | L | H | M | Sleeper |
| 15 | SIH26187 | Border CCTV analytics | MHA | H | H | M | L | Crowded Giant |
| 16 | SIH26192 | Flash flood prediction | MHA | H | M | M | M | Overlaps #3/#5 |
| 17 | SIH26123 | AMR fleet coordination | BEL | M | M | M | M | Integration Play |
| 18 | SIH26118 | H2S dosimeter wristband | MRPL | M | L | L | M | Niche Technical Beast |
| 19 | SIH26233 | Hyperspectral contamination | MoFPI | M | L | L | H | Technical Beast, wrong team |
| 20 | SIH26232 | IoT blockchain cold-chain nodes | MoFPI | M | M | M | M | Integration Play |

---

## 3. Key Research Findings

1. **Conveyor belt rupture (SIH26008)** — mature, heavily patented field; edge-AI vision rip detection already published with field results. Partial saturation.
2. **Mine subsidence (SIH26025)** — real, government-tracked fatality stream; CSIR "Goafwarn" proprietary; no open low-cost real-time product. Genuine gap.
3. **Blockchain traceability (SIH26232)** — oversaturated concept; real unsolved part is rugged edge hardware, not the ledger.
4. **Qualcomm statements (SIH26177–181)** — likely expect Snapdragon/Dragonwing hardware; unresolved sponsor-platform risk.
5. **SIH deployment process** — slow and inconsistent by government's own admission; every deployment path should be read against this baseline.

---

## 4. Final Top 3 (from competitive intelligence)

| Rank | PS ID | Problem | Why |
|---|---|---|---|
| 1 | SIH26025 | Mine subsidence monitoring | Best severity, lowest competition-to-quality, hidden constraint in PS text, least sponsor risk |
| 2 | SIH26178 | Environmental intelligence network | Strongest architectural fit, but high competition + Qualcomm platform risk |
| 3 | SIH26232 | Farm-to-fork cold-chain nodes | Safer, lower-glamour, fastest-to-deploy alternative |

---

## 5. Sources

See the full competitive intelligence report (Section H) for the complete source list.
