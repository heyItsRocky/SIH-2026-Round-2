# SIH26025 — Cost & BOM

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

**Real free signals used:** tripwire GPIO (physical crack/event trigger), CPU temperature (real telemetry stream).

The BOM below (with purchased sensors) is the **aspirational production version** — NOT what we build for the hackathon.

---

## 1. Bill of Materials (Aspirational / Production — NOT for hackathon)

| Component | Qty | Unit Cost | Total | Purpose | Availability | Alternative |
|---|---|---|---|---|---|---|
| ESP32-C3 DevKit | 2 | ₹300 | ₹600 | Sensor nodes | Widely available | ESP32-WROOM |
| ESP32-WROOM-32 | 2 | ₹400 | ₹800 | Sensor nodes | Widely available | ESP32-C3 |
| MPU6050 (tilt) | 2 | ₹150 | ₹300 | Tilt detection | Widely available | BNO055 |
| ADXL345 (vibration) | 2 | ₹200 | ₹400 | Vibration detection | Widely available | SW-420 |
| Potentiometer (displacement) | 1 | ₹100 | ₹100 | Displacement | Widely available | Strain gauge |
| Crack sensor | 2 | ₹100 | ₹200 | Crack detection | Widely available | Resistive |
| GPS (NEO-6M) | 1 | ₹300 | ₹300 | Positioning | Widely available | — |
| LoRa modules (SX1278) | 4 | ₹300 | ₹1,200 | Mesh comms | Widely available | Zigbee |
| OLED Display | 1 | ₹200 | ₹200 | Status display | Already owned | — |
| NeoPixel | 1 | ₹100 | ₹100 | Visual alert | Already owned | — |
| Enclosures | 4 | ₹200 | ₹800 | Protection | Widely available | 3D-printed |
| Battery + solar | 4 | ₹300 | ₹1,200 | Power | Widely available | USB power |
| Wiring, connectors | — | ₹500 | ₹500 | Connections | Widely available | — |
| **Total** | | | **~₹6,700** | | | |

---

## 2. Cost Comparison

| System | Cost |
|---|---|
| **Our mesh (4 nodes)** | **~₹6,700** |
| InSAR/GNSS survey | Orders of magnitude higher |
| Slope Stability Radar | Very high (₹lakhs+) |
| CSIR Goafwarn | Proprietary, not broadly available |

---

## 3. Budget Notes

- Most components already owned (Pi 4, Pi 3s, ESP32s, OLED, NeoPixel, switch, SSD)
- New purchases: sensors (~₹1,300), LoRa (~₹1,200), enclosures/power (~₹2,000)
- Total new spend: **~₹4,500-6,700**