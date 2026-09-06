# Hardware Capability Baseline

> Actual team inventory, independent of either problem.
> Prevents repeatedly rewriting the same hardware facts in every project folder.

---

## 1. What We Own

| Component | Model / Spec | Qty | Role |
|---|---|---|---|
| Raspberry Pi 4 | 8GB | 1 | Central host, edge AI, MQTT broker |
| Raspberry Pi 3A+ | 1GB | 1 | Distributed edge node |
| Raspberry Pi 3B | 1GB | 1 | Distributed edge node |
| ESP32-WROOM-32 | Classic, 520KB SRAM | 1 | Sensor interface, mesh relay |
| ESP32-C3-DevKitM-1 | 160KB SRAM, NeoPixel on GPIO8 | 1 | Sensor interface, status light |
| Ethernet Switch | 5-port (TP-Link LS1005) | 1 | Network backbone |
| OLED Display | 1" I2C | 1 | Status display |
| NeoPixel LED | GPIO8 | 1 | Visual alert |
| WiFi Adapter | TP-Link AC600 | 1 | Wireless interface |
| WiFi Adapter | TP-Link TL-WN722N | 1 | Monitor-mode capable |
| SSD | 500GB USB 3.0 | 1 | NAS storage, ML models |
| USB Flash | 128GB | 1 | Removable storage |
| USB Flash | 32GB ×2 | 2 | Evidence vault + scripts |
| Cooling Fan | 5V | 1 | Pi 4 cooling |
| Power | AC adapters, Y-splitter | — | Power distribution |

---

## 2. What We Know (Proven Skills)

- Linux / Raspberry Pi OS administration
- ESP32 / C++ firmware (ESP-IDF, Arduino)
- GPIO signaling, tripwire logic
- Wired / Wi-Fi networking
- OLED / NeoPixel driving
- MQTT telemetry (paho-mqtt)
- Basic Python backend

---

## 3. What We Can Build

- Distributed edge node mesh
- Sensor interface + data collection
- Local edge processing
- MQTT-based telemetry pipeline
- Physical alerting (GPIO, OLED, NeoPixel)
- Offline data buffering + sync

---

## 4. What We Need to Buy (per problem)

### SIH26025 (Mine Subsidence)
- Tilt/inclination sensors (MPU6050/BNO055)
- Vibration sensors
- Displacement/stretch sensors
- Crack detection sensors
- Optional GPS module
- LoRa modules (if LoRa mesh)

### SIH26178 (Environmental Intelligence)
- Environmental sensors (water level, PM2.5/PM10, smoke, gas, soil moisture)
- Solar charging circuit
- LoRa modules (if LoRa mesh)

---

## 5. What We Can Reuse

- All ULTRON hardware (Pi 4, Pi 3s, ESP32s, switch, OLED, NeoPixel, WiFi, SSD)
- MQTT pipeline
- Edge AI inference capability (Pi 4)
- Offline buffering architecture

---

## 6. What We Cannot Realistically Build

- Certified structural-safety instruments (DGMS certification)
- Defense-grade environmental test chambers
- Hyperspectral cameras
- Precision MEMS calibration equipment
- Full-size CNN on constrained hardware (use quantized/TFLite)
