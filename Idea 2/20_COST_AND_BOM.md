# SIH26178 — Cost & BOM

> Actual Bill of Materials.

---

## ⚠ ZERO-BUDGET MODE (READ FIRST)

> **We have no budget to purchase sensors.** See `SIH_2026/00_MASTER/ZERO_BUDGET_STRATEGY.md`.

**Zero-budget BOM (what we actually build with):**

| Item | Cost |
|---|---|
| Raspberry Pi 4B 8GB (gateway) | ₹0 (owned) |
| Raspberry Pi 3A+ (node) | ₹0 (owned) |
| Raspberry Pi 3B+ v1.2 (node) | ₹0 (owned) |
| 2× ESP32-C3-DevKitM-1 | ₹0 (owned) |
| 1× ESP32-WROOM-32 | ₹0 (owned) |
| 5-port Ethernet switch | ₹0 (owned) |
| 1" I2C OLED | ₹0 (owned) |
| NeoPixel (C3 GPIO8) | ₹0 (owned) |
| AC600 + TL-WN722N Wi-Fi | ₹0 (owned) |
| 500GB SSD + 128GB flash | ₹0 (owned) |
| 4-port USB hub | ₹0 (owned) |
| Software sensor simulator | ₹0 (we build it) |
| **Total new spend** | **₹0** |

**Real free signals used:** CPU temperature on each Pi (real environmental temperature stream), tripwire GPIO (real event trigger).

The BOM below (with purchased sensors) is the **aspirational production version** — NOT what we build for the hackathon.

---

## 1. Bill of Materials (Aspirational / Production — NOT for hackathon)

| Component | Qty | Unit Cost | Total | Purpose | Availability | Alternative |
|---|---|---|---|---|---|---|
| ESP32-C3 DevKit | 2 | ₹300 | ₹600 | Sensor nodes | Widely available | ESP32-WROOM |
| ESP32-WROOM-32 | 2 | ₹400 | ₹800 | Sensor nodes | Widely available | ESP32-C3 |
| MQ-2 smoke sensor | 2 | ₹150 | ₹300 | Fire/smoke detection | Widely available | MQ-7 |
| DHT22 temp/humidity | 3 | ₹100 | ₹300 | Heat/humidity | Widely available | DHT11 |
| PMS5003 PM2.5/PM10 | 1 | ₹1000 | ₹1,000 | Air quality | Widely available | SDS011 |
| MQ-135 gas sensor | 1 | ₹200 | ₹200 | Air quality/industrial | Widely available | MQ-7 |
| Soil moisture sensor | 1 | ₹150 | ₹150 | Landslide precursor | Widely available | — |
| LoRa modules (SX1278) | 4 | ₹300 | ₹1,200 | Mesh comms | Widely available | Zigbee |
| OLED Display | 1 | ₹200 | ₹200 | Status display | Already owned | — |
| NeoPixel | 1 | ₹100 | ₹100 | Visual alert | Already owned | — |
| Weatherproof enclosures | 4 | ₹300 | ₹1,200 | Protection | Widely available | 3D-printed |
| Battery + solar | 4 | ₹500 | ₹2,000 | Power | Widely available | USB power |
| Wiring, connectors | — | ₹500 | ₹500 | Connections | Widely available | — |
| **Total** | | | **~₹8,550** | | | |

---

## 2. Cost Comparison

| System | Cost |
|---|---|
| **Our mesh (4 nodes)** | **~₹8,550** |
| Commercial IoT environmental station | ₹lakhs+ per station |
| IMD/ISRO satellite monitoring | National-scale, very high |
| CPCB air quality station | High per station |

---

## 3. Budget Notes

- Most components already owned (Pi 4, Pi 3s, ESP32s, OLED, NeoPixel, switch, SSD)
- New purchases: sensors (~₹1,950), LoRa (~₹1,200), enclosures/power (~₹3,200)
- Total new spend: **~₹6,000-8,550**
