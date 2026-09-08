# SIH26178 — Problem Definition

> What exactly are we solving?

---

## 1. Official Problem Statement

**Title:** AI-Powered Environmental Intelligence Network

**Organization:** Qualcomm Inc
**Category:** Hardware
**Theme:** Disaster Management

**Official Description:** India faces a growing range of environmental and climate-related risks including urban flooding, river floods, cyclones, forest fires, air pollution, droughts, landslides, and extreme weather events. Government agencies such as NDMA, IMD, and ISRO already rely on centralized environmental monitoring and early warning systems, but these often lack sufficiently localized, real-time intelligence.

Design an **Environmental Intelligence Network** — a distributed system of interconnected AI-powered sensor nodes deployable across cities, rivers, forests, industrial zones, and vulnerable communities. Each node uses **local (on-device) AI inference** to continuously monitor environmental conditions and identify emerging risks such as rising water levels, forest fires/smoke, hazardous air pollution, extreme heat, landslide precursors, industrial emissions, and water quality degradation.

The sensor network should process data locally to reduce latency, minimize bandwidth, and continue operating during network outages. Only critical alerts, summarized insights, and risk assessments should be transmitted to regional control centers or disaster management authorities.

---

## 2. Actual Real-World Problem

India faces 8+ categories of environmental/climate risk simultaneously:
- Urban flooding (Monsoon 2023: Mumbai, Chennai, Hyderabad)
- River floods (Brahmaputra, Ganga basin)
- Forest fires (Uttarakhand, Himachal Pradesh annual cycles)
- Air pollution (Delhi NCR, industrial corridors)
- Extreme heat (2023: 50°C+ in Rajasthan)
- Landslides (Himachal/Kerala monsoon events)
- Industrial emissions (Bhopal-legacy awareness)
- Water quality degradation (Ganga, industrial effluent)

Current monitoring is **centralized and delayed** — IMD satellite feeds have revisit gaps, ground stations are sparse, and village/ward-level ground truth rarely exists in real-time.

---

## 3. Users

- State Disaster Management Authorities (SDMAs)
- NDMA (National Disaster Management Authority)
- IMD (India Meteorological Department)
- FSI regional offices (forest fire)
- CWC / flood forecasting authorities
- Local communities and citizens
- Industrial zone regulators

---

## 4. Current Workflow

```
Satellite imagery (periodic revisit)
    ↓
Centralized processing (IMD/ISRO servers)
    ↓
Regional alerts (hours after event onset)
    ↓
Local response (often too late for flash events)
```

**Limitation:** No village/ward-level, minutes-not-hours ground truth. Between satellite revisits and between ground-station visits, there is no continuous local intelligence.

---

## 5. Desired Outcome

A distributed network of low-cost, solar-powered, AI-enabled sensor nodes that:
- Monitor environmental conditions continuously at the local level
- Run on-device AI inference for real-time risk detection
- Operate offline during network outages
- Transmit only critical alerts and summarized insights
- Integrate with existing NDMA/SDMA alert infrastructure (SACHET/CAP)

---

## 6. In-Scope

- Distributed ESP32 sensor nodes (multi-hazard)
- Wireless mesh networking (LoRa/Zigbee/Wi-Fi)
- On-device edge AI inference (anomaly detection)
- Offline-capable operation with local buffering
- GIS risk mapping dashboard
- SACHET/CAP integration for alert delivery
- Solar-powered, low-maintenance design

---

## 7. Out-of-Scope

- **Building a new alert platform** — we feed into NDMA's existing SACHET/CAP infrastructure
- **Full-scale deployment** — prototype → pilot → scale is the path
- **Replacing IMD/ISRO satellite monitoring** — we complement between revisit cycles
- **All 8 hazard types at once** — pick one hazard as deep MVP; others as same-architecture future nodes

---

## 8. Critical Framing

> **We build the distributed sensor-to-edge layer that gives villages and wards real-time ground truth — not a replacement for IMD/ISRO satellite systems.**

**SACHET/CAP integration insight** — feed into NDMA's existing alert bus rather than building a redundant standalone app. Most teams won't find this. This is a genuine differentiator.

---

# SIH26178 — Real World Research

> Factual foundation: India's environmental risks, current monitoring, NDMA/IMD/ISRO, SACHET/CAP, actual incidents.

---

## 1. India's Environmental Risk Landscape

| Hazard | Scale | Recent Evidence |
|---|---|---|
| **Urban flooding** | High | Monsoon 2023: Mumbai, Chennai, Hyderabad |
| **River floods** | High | Brahmaputra, Ganga basin annual cycles |
| **Forest fires** | High | Uttarakhand, Himachal Pradesh annual cycles |
| **Air pollution** | Very High | Delhi NCR, industrial corridors |
| **Extreme heat** | High | 2023: 50°C+ in Rajasthan |
| **Landslides** | Med | Himachal/Kerala monsoon events |
| **Industrial emissions** | Med | Bhopal-legacy awareness |
| **Water quality degradation** | Med | Ganga, industrial effluent |

---

## 2. Current Monitoring

| System | Owner | What it does | Limitation |
|---|---|---|---|
| **IMD satellite** | IMD | Weather forecasting | Revisit gaps, not local |
| **ISRO remote sensing** | ISRO | Satellite imagery | Periodic, not real-time |
| **CWC flood forecasting** | CWC | River flood prediction | Regional, not ward-level |
| **FSI forest fire** | FSI | Fire detection | Satellite-based, delayed |
| **CPCB air quality** | CPCB | Air quality monitoring | Sparse stations |

**Gap:** No village/ward-level, minutes-not-hours ground truth.

---

## 3. SACHET / CAP Integration

- **SACHET** — NDMA's Common Alerting Protocol (CAP) compliant alert system
- **CAP** — international standard for emergency alerts (OASIS)
- **Insight:** Feed our alerts into NDMA's existing SACHET/CAP bus rather than building a redundant standalone app
- **Why it matters:** Most teams build a new alert app; we integrate with the existing national infrastructure — a genuine differentiator

---

## 4. Institutional Context

- **NDMA** — national disaster management authority, owns SACHET/CAP
- **SDMAs** — state-level disaster management authorities (our primary users)
- **IMD/ISRO** — centralized monitoring (we complement, not replace)
- **FSI** — forest fire monitoring (fire is best-evidenced gap)

---

## 5. Key Sources

- NDMA SACHET/CAP documentation
- IMD/ISRO monitoring infrastructure
- CWC flood forecasting
- FSI forest fire monitoring
- CPCB air quality network
- Monsoon 2023 flood reporting

---

# SIH26178 — Existing Solutions

> Document what already exists, how it works, its strengths/weaknesses, and what remains unsolved.

---

## 1. Solution Landscape

| Solution | What it does | How it works | Strength | Weakness | Cost | Deployment | What remains unsolved |
|---|---|---|---|---|---|---|---|
| **IMD satellite** | Weather forecasting | Satellite + models | Wide coverage | Revisit gaps, not local | High | National | Local real-time ground truth |
| **ISRO remote sensing** | Satellite imagery | Satellite interferometry | Wide coverage | Periodic, not real-time | High | National | Real-time local alarm |
| **CWC flood forecasting** | River flood prediction | Hydrological models | Regional accuracy | Not ward-level | High | River basins | Local real-time sensing |
| **FSI forest fire** | Fire detection | Satellite-based | National coverage | Delayed (satellite revisit) | High | National | Minutes-not-hours detection |
| **CPCB air quality** | Air quality monitoring | Sparse ground stations | Authoritative | Sparse, not dense | High | Cities | Dense local coverage |
| **Commercial IoT stations** | Local environmental sensing | Proprietary nodes | Local data | Expensive, not integrated | Med-High | Pilot | Low-cost, integrated, offline |
| **Academic WSN** | Environmental monitoring | Research prototypes | Proves concept | Not productized | Low | Research | Deployable product |

---

## 2. What Remains Unsolved

1. **Village/ward-level, minutes-not-hours ground truth** — nothing gives this today
2. **Low-cost, dense deployment** — commercial stations are too expensive for dense coverage
3. **Offline-capable operation** — most systems need continuous connectivity
4. **On-device AI inference** — most systems send raw data to cloud
5. **Integration with existing alert infrastructure** — most teams build redundant apps instead of feeding SACHET/CAP
6. **Multi-hazard in one network** — most systems are single-hazard

---

## 3. Our Opportunity

The gap is real and specific: **a low-cost, dense, offline-capable, on-device-AI environmental sensing network that feeds into NDMA's existing SACHET/CAP alert infrastructure** — not a redundant standalone app.

---

# SIH26178 — Gap Analysis

> What exactly are we solving that existing solutions don't solve well?

---

## 1. Gap Chain

```
Existing system: Centralized satellite + sparse ground stations
      ↓
Limitation: No village/ward-level, minutes-not-hours ground truth
      ↓
Why it matters: Flash events (floods, fires) develop faster than satellite revisit
      ↓
Our opportunity: Dense, low-cost, offline-capable local sensing layer
```

---

## 2. Specific Gaps

| Gap | Existing coverage | Our solution |
|---|---|---|
| Local real-time ground truth | No (satellite revisit gaps) | Dense local sensing |
| Minutes-not-hours detection | No (satellite delay) | On-device edge AI |
| Offline operation | No (needs connectivity) | Local buffering + edge inference |
| Low-cost dense deployment | No (expensive stations) | Cheap ESP32 nodes |
| Multi-hazard in one network | No (single-hazard systems) | Multi-hazard node types |
| Alert integration | No (redundant apps) | SACHET/CAP integration |

---

## 3. One-Sentence Differentiation

> **"Satellite monitoring is accurate but not local or real-time; we add a dense, low-cost, offline-capable local sensing layer that feeds NDMA's existing alert infrastructure."**

---

## 4. Why This Gap Is Real (Evidence)

- IMD/ISRO satellite systems have revisit gaps — not minutes-not-hours
- CWC flood forecasting is regional, not ward-level
- FSI forest fire detection is satellite-based and delayed
- CPCB air quality stations are sparse
- Commercial IoT stations are too expensive for dense deployment
- No evidence of a mature, low-cost, offline-capable, multi-hazard, SACHET-integrated product on the Indian market

---

