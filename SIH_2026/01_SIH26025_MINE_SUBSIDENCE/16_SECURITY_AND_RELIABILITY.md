# SIH26025 — Security & Reliability

> Authentication, data integrity, node identity, communication security, tamper detection, fail-safe.

---

## 1. Security

| Concern | Approach |
|---|---|
| **Node authentication** | Unique node ID + shared secret / TLS client cert |
| **Communication security** | TLS for MQTT, encrypted mesh |
| **Data integrity** | Checksums, sequence numbers, tamper-evident logging |
| **Node identity** | Hardware ID burned at provisioning |
| **Tamper detection** | Physical tamper switch, alert on removal |
| **Firmware updates** | Signed firmware, OTA with verification |

---

## 2. Reliability

| Concern | Approach |
|---|---|
| **Data backup** | Redundant storage (SSD + flash), periodic backup |
| **Fail-safe behavior** | On gateway failure, nodes buffer + alert locally |
| **Power resilience** | Battery backup, low-power modes |
| **Watchdog** | Hardware watchdog on ESP32, auto-restart |
| **Health monitoring** | Heartbeat telemetry, node health dashboard |

---

## 3. Fail-Safe Principle

> **Fail-closed:** if the system can't confirm safety, it should alert (not stay silent).

This is critical for a safety-monitoring system — a false alarm is better than a missed event.
