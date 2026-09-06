# Top 10 Ideas Analysis

> SIH 2026 Round 2 — Shortlisted Problem Statements

---

## 1. Overview

This folder contains the analysis of the top 10 shortlisted SIH 2026 problem statements evaluated against our team's hardware capabilities (SENTINEL 2.0 / ULTRON cluster) and software expertise. Each problem statement is assessed for hardware compatibility, technical complexity, innovation potential, and SIH scoring potential.

The 10 problem statements were selected from the full pool of 226 based on:
- Direct compatibility with existing hardware (Raspberry Pi 4B, ESP32-C3, ESP32-WROOM, sensors)
- Team expertise in cybersecurity, IoT, edge computing, and ML
- Innovation potential and feasibility within the hackathon timeline

---

## 2. Quick Comparison Table

| Rank | PS# | Problem Statement | Core Idea | Key Features | Advantages | Disadvantages | Difficulty | SIH Potential |
|------|-----|-------------------|-----------|--------------|------------|---------------|------------|---------------|
| 1 | SIH26050 | High Altitude Anti-Drone System (DRDO) | Hardened multi-sensor anti-drone cluster for high-altitude deployment | RF+EO detection, gimbal tracking, adaptive compensation, health monitoring | Existing ULTRON hardware, strong PS alignment, demonstrable results | Tight timeline, hardware hardening complexity | High | High |
| 2 | SIH26157 | SOC Assessment Tool (NTRO) | Automated SOC maturity assessment platform | Suricata IDS integration, compliance scoring, threat detection metrics | Direct Arsenal tool integration, cybersecurity focus | Software-heavy, less hardware differentiation | Medium | High |
| 3 | SIH26153 | Network Attack Forecasting (NTRO) | ML-based network attack prediction from traffic data | Traffic analysis, anomaly detection, predictive scoring | MQTT telemetry pipeline, SENTINEL risk engine transferable | Requires network traffic datasets, ML training | Medium | High |
| 4 | SIH26155 | Network Security Compliance Auditor (NTRO) | Multi-vendor network security compliance checking | Automated compliance scanning, vendor-specific rule sets | Suricata + SigmaOptimizer fit, edge-deployable | Complex compliance rule sets, multi-vendor support | Medium | High |
| 5 | SIH26178 | Environmental Monitoring Network (Qualcomm) | IoT-based environmental sensor network with edge AI | ESP32 sensor nodes, Pi edge processing, MQTT mesh | Near-perfect hardware match (7/10 components), IoT expertise | Needs environmental sensors (not in inventory) | Low | Medium |
| 6 | SIH26180 | Smart Farming Assistant (Qualcomm) | AI-powered crop analysis and farming recommendations | Camera-based crop analysis, soil sensor integration, farmer dashboard | Pi 4B edge AI, ESP32 sensor interface, OLED display | Needs camera and soil sensors, agriculture domain knowledge | Low | Medium |
| 7 | SIH26145 | Cyber Threat Detection in Unidirectional IP Traffic (NTRO) | Real-time cyber threat detection in network traffic | Unidirectional traffic analysis, threat classification, alert system | Suricata + CanaryPiE + SigmaOptimizer, core Sentinel function | Unidirectional traffic constraint, specific dataset needed | Medium | High |
| 8 | SIH26105 | Cyber Risk Quantification Platform (AICTE) | Quantify organizational cyber risk in real-time | Risk scoring, vulnerability assessment, investment optimization | Suricata + Azazel-Edge, risk engine from Sentinel | Needs enterprise network access, complex metrics | Medium | Medium |
| 9 | SIH26039 | Underground Mine Safety (Jharkhand) | AI-powered mine safety monitoring and rescue system | Gas detection, personnel tracking, emergency alerts | Pi 4B + ESP32-C3 + MQTT, partial hardware match | Needs gas sensors (CH4, CO, O2), mining domain | Medium | Medium |
| 10 | SIH26040 | Smart Water Purification (Jharkhand) | Water quality monitoring and purification control | pH, turbidity, TDS sensing, purification automation | Pi 4B + ESP32-C3 + OLED + MQTT, partial match | Needs water quality sensors, not in inventory | Low | Medium |

---

## 3. Individual Idea Summaries

### Idea 1 — High Altitude Anti-Drone System (SIH26050)

- **Core Concept:** Build a hardened, distributed anti-drone system using the ULTRON cluster that maintains performance at high altitude through physical hardening and adaptive software compensation.
- **Key Features:** Multi-sensor RF+EO detection, 2-axis gimbal tracking, real-time adaptive PID compensation, environmental hardening (IP65, conformal coating), cold-box validation protocol.
- **Advantages:** Existing ULTRON hardware, directly answers PS requirements, fault-tolerant distributed architecture, quantified validation methodology.
- **Disadvantages:** 25-day timeline is tight, hardware hardening complexity, RF jamming legally restricted for demo, demo failure risk.
- **Technical Complexity:** High
- **Innovation Potential:** High
- **SIH Potential:** High

### Idea 2 — SOC Assessment Tool (SIH26157)

- **Core Concept:** Automated Security Operations Center maturity assessment platform using Suricata IDS, threat detection metrics, and compliance scoring.
- **Key Features:** Suricata integration, Sigma rule matching, SOC maturity scoring, threat detection dashboard.
- **Advantages:** Direct Arsenal tool integration (SELKS, Suricata, Azazel-Edge), cybersecurity domain expertise, edge-deployable.
- **Disadvantages:** Software-heavy, less hardware differentiation from other teams, needs enterprise SOC datasets.
- **Technical Complexity:** Medium
- **Innovation Potential:** Medium
- **SIH Potential:** High

### Idea 3 — Network Attack Forecasting (SIH26153)

- **Core Concept:** ML-based network attack prediction system that forecasts attacks from traffic patterns using anomaly detection models.
- **Key Features:** Network traffic analysis, ML-based anomaly detection, attack prediction scoring, real-time alerting.
- **Advantages:** MQTT telemetry pipeline from Sentinel, risk engine transferable, Traceeshark/YAMAGoya integration possible.
- **Disadvantages:** Requires large network traffic datasets for training, ML model accuracy depends on data quality.
- **Technical Complexity:** Medium
- **Innovation Potential:** High
- **SIH Potential:** High

### Idea 4 — Network Security Compliance Auditor (SIH26155)

- **Core Concept:** Multi-vendor network security compliance checking platform that automatically audits configurations against security standards.
- **Key Features:** Automated compliance scanning, vendor-specific rule sets, compliance report generation, vulnerability identification.
- **Advantages:** Suricata + SigmaOptimizer fit naturally, edge-deployable, compliance frameworks are well-defined.
- **Disadvantages:** Complex multi-vendor support, compliance rule sets are extensive, needs access to real network configs.
- **Technical Complexity:** Medium
- **Innovation Potential:** Medium
- **SIH Potential:** High

### Idea 5 — Environmental Monitoring Network (SIH26178)

- **Core Concept:** IoT-based environmental sensor network using ESP32 nodes for distributed monitoring with edge AI on Raspberry Pi.
- **Key Features:** ESP32-C3 sensor nodes, Pi 4B edge AI processing, MQTT mesh communication, NeoPixel visual alerts.
- **Advantages:** Near-perfect hardware match (7/10 SENTINEL components), IoT expertise from Sentinel 2.0, scalable architecture.
- **Disadvantages:** Needs environmental sensors (temperature, humidity, air quality) not in current inventory, agriculture/environment domain knowledge needed.
- **Technical Complexity:** Low
- **Innovation Potential:** Medium
- **SIH Potential:** Medium

### Idea 6 — Smart Farming Assistant (SIH26180)

- **Core Concept:** AI-powered crop analysis and farming recommendation system using camera-based disease detection and soil sensor data.
- **Key Features:** Camera-based crop analysis, soil sensor integration, farmer-facing dashboard, irrigation alerts.
- **Advantages:** Pi 4B edge AI for crop analysis, ESP32 sensor interface, OLED display for farmer UI, NeoPixel irrigation alerts.
- **Disadvantages:** Needs camera module and soil sensors (not in inventory), agriculture domain knowledge required.
- **Technical Complexity:** Low
- **Innovation Potential:** Medium
- **SIH Potential:** Medium

### Idea 7 — Cyber Threat Detection in Unidirectional IP Traffic (SIH26145)

- **Core Concept:** Real-time cyber threat detection system specifically designed for unidirectional IP traffic flows.
- **Key Features:** Unidirectional traffic analysis, real-time threat classification, automated alerting, traffic logging.
- **Advantages:** Core Sentinel function (network monitoring), Suricata + CanaryPiE + SigmaOptimizer integration, well-defined problem.
- **Disadvantages:** Unidirectional traffic constraint is unusual, needs specific dataset for validation, may be too narrow.
- **Technical Complexity:** Medium
- **Innovation Potential:** Medium
- **SIH Potential:** High

### Idea 8 — Cyber Risk Quantification Platform (SIH26105)

- **Core Concept:** Real-time organizational cyber risk quantification and investment optimization platform.
- **Key Features:** Risk scoring, vulnerability assessment, investment optimization, real-time risk dashboard.
- **Advantages:** Suricata + Azazel-Edge integration, risk engine from Sentinel transferable, well-defined metrics.
- **Disadvantages:** Needs enterprise network access for realistic data, complex risk metrics, competitive problem statement.
- **Technical Complexity:** Medium
- **Innovation Potential:** Medium
- **SIH Potential:** Medium

### Idea 9 — Underground Mine Safety (SIH26039)

- **Core Concept:** AI-powered underground mine safety monitoring system with gas detection, personnel tracking, and emergency alerts.
- **Key Features:** Gas detection (CH4, CO, O2), personnel tracking, emergency beacon system, rescue communication.
- **Advantages:** Pi 4B + ESP32-C3 + MQTT partial match, ESP32-WROOM as WiFi AP for rescue comms, critical safety application.
- **Disadvantages:** Needs gas sensors (MQ-4, MQ-7, O2 sensor), mining domain expertise, enclosed environment challenges.
- **Technical Complexity:** Medium
- **Innovation Potential:** Medium
- **SIH Potential:** Medium

### Idea 10 — Smart Water Purification (SIH26040)

- **Core Concept:** Smart water purification and quality monitoring system for rural and mining-affected areas.
- **Key Features:** pH/turbidity/TDS sensing, purification control, water quality dashboard, contamination alerts.
- **Advantages:** Pi 4B + ESP32-C3 + OLED + MQTT partial match, critical public health application, scalable to rural deployment.
- **Disadvantages:** Needs water quality sensors (not in inventory), water treatment domain knowledge, purification hardware.
- **Technical Complexity:** Low
- **Innovation Potential:** Medium
- **SIH Potential:** Medium

---

## 4. Selection Criteria

Problems were ranked using these weighted criteria:

| Criterion | Weight | Description |
|-----------|--------|-------------|
| **Hardware Compatibility** | 30% | How well existing SENTINEL/ULTRON hardware fits |
| **Technical Feasibility** | 25% | Can it be built in the hackathon timeline |
| **Innovation Potential** | 20% | Novelty and differentiation from other teams |
| **PS Alignment** | 15% | How well the solution maps to the problem statement |
| **Team Expertise** | 10% | Domain knowledge and skill match |

---

## 5. File Index

| File | Problem Statement |
|------|-------------------|
| [PS 01.md](./PS%2001.md) | SIH26050 — High Altitude Anti-Drone System (DRDO) |
| [PS 02.md](./PS%2002.md) | SIH26157 — SOC Assessment Tool (NTRO) |
| [PS 03.md](./PS%2003.md) | SIH26153 — Network Attack Forecasting (NTRO) |
| [PS 04.md](./PS%2004.md) | SIH26155 — Network Security Compliance Auditor (NTRO) |
| [PS 05.md](./PS%2005.md) | SIH26178 — Environmental Monitoring Network (Qualcomm) |
| [PS 06.md](./PS%2006.md) | SIH26180 — Smart Farming Assistant (Qualcomm) |
| [PS 07.md](./PS%2007.md) | SIH26145 — Cyber Threat Detection in Unidirectional IP Traffic (NTRO) |
| [PS 08.md](./PS%2008.md) | SIH26105 — Cyber Risk Quantification Platform (AICTE) |
| [PS 09.md](./PS%2009.md) | SIH26039 — Underground Mine Safety (Jharkhand) |
| [PS 10.md](./PS%2010.md) | SIH26040 — Smart Water Purification (Jharkhand) |
| [PS 11.md](./PS%2011.md) | SIH26172 — Low Latency Voice Activator for Edge Devices (ISRO) |
