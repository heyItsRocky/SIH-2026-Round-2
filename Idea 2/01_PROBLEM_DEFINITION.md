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
