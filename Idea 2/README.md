# Idea 2 — SIH26232: Low-Cost IoT Blockchain Nodes for Farm-to-Fork Cold Chain

> SIH 2026 Round 2 · **Finalized** · Ministry of Food Processing Industries (MoFPI)

---

## Status

**Idea 2 is finalized.** This is the runner-up / backup submission for SIH 2026 Round 2.

---

## Problem Statement

| Field | Value |
|---|---|
| **PS Number** | SIH26232 |
| **Organization** | Ministry of Food Processing Industries (MoFPI) |
| **Category** | Hardware |
| **Theme** | Agriculture, FoodTech & Rural Development |
| **Idea Deadline** | 20 September 2026 |

---

## Problem Description

SME exporters are priced out of cold-chain compliance, and existing loggers fail in low-connectivity rural transit. The blockchain-traceability literature is unanimous that adoption fails on **cost, connectivity, and interoperability** — not ledger design.

Build low-cost IoT nodes with local cryptographic storage, energy harvesting, and opportunistic sync that survive real cellular dropouts, enabling tamper-evident farm-to-fork traceability.

---

## Proposed Solution & Core Concept

**Rugged edge-hardware engineering, with the ledger as a minor supporting detail** — not "blockchain theatre."

```
ESP32 Node (Edge)                          Pi 4B / Cloud
┌──────────────────────────────┐          ┌──────────────────┐
│ Temp/Humidity Sensor         │          │                  │
│ Local Hash-Chain (Merkle)    │──sync──► │ Verify Chain     │
│ Tamper-Evident Buffer        │  on      │ Traceability UI  │
│ Energy Harvesting (Solar)    │  reconnect│ Compliance Report│
│ Offline Logging              │          │                  │
└──────────────────────────────┘          └──────────────────┘
```

---

## Key Features

- Rugged, low-power IoT nodes with local cryptographic storage
- **Lightweight hash-chain (Merkle-style append-only log)** — satisfies "tamper-proof" without running actual blockchain infrastructure on constrained hardware
- Energy harvesting (solar) for remote/rural deployment
- Opportunistic sync on reconnect after cellular dropouts
- Tamper-evident offline buffering
- Farm-to-fork traceability compliance for SME exporters

---

## Technical Approach & Architecture

- **Edge:** ESP32 nodes with sensors + local hash-chain storage + energy harvesting
- **Sync:** Opportunistic MQTT sync on reconnect
- **Ledger:** Lightweight Merkle-style append-only log (not full blockchain)
- **Cloud:** Traceability UI, compliance reports, verification

---

## Proposed Tech Stack

- **Hardware:** ESP32-C3/WROOM, temperature/humidity sensors, solar charging circuit
- **Firmware:** ESP-IDF / Arduino
- **Ledger:** Lightweight hash-chain (Merkle-style), MQTT
- **Backend:** Python (FastAPI), MQTT broker
- **Frontend:** Traceability dashboard

---

## Expected Users & Stakeholders

- MoFPI-registered SME food exporters
- Cold-chain logistics operators
- Regulators and compliance authorities

---

## Advantages & Challenges

**Advantages:**
- Near-literal spec match with ULTRON (local crypto storage, energy harvesting, opportunistic sync)
- Fully buildable and testable with real hardware, no external data dependency
- Fastest-to-deploy alternative (smaller bureaucracy than a central ministry)
- Lower competition risk than flashy Qualcomm statements

**Challenges:**
- "Blockchain" framing invites comparison to a saturated field — must actively fight this in the pitch
- Energy-harvesting circuit is a genuinely new build
- Must foreground rugged edge-engineering, not the ledger

---

## Current Development Status

- [x] Problem statement analysis
- [x] Competitive intelligence report
- [x] Solution design
- [ ] Sensor selection & procurement
- [ ] Hash-chain implementation
- [ ] Energy harvesting circuit
- [ ] Sync & verification logic
- [ ] Traceability dashboard
- [ ] Testing & validation
- [ ] Pitch deck
