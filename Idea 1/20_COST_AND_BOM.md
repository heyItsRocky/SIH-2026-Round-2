# SIH26025 — Cost & BOM

> Actual Bill of Materials.

---

## 1. Bill of Materials

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