# SIH26025 — Node Architecture

> Define exactly what one mine node looks like.

---

## 1. Single Node Architecture

```
Sensors (tilt, vibration, displacement, crack)
    ↓
ESP32 (local processing, sampling, filtering)
    ↓
Communication (mesh: LoRa/Zigbee/Wi-Fi)
    ↓
Gateway (Pi 4)
    ↓
Edge AI + Dashboard
```

---

## 2. Node Definitions

### Node 1 (Pi 3A+ + ESP32-C3)
- **Role:** Tilt + vibration monitoring
- **Sensors:** MPU6050 (tilt), ADXL345 (vibration)
- **Comms:** Ethernet to switch, MQTT to Pi 4
- **Alert:** Local NeoPixel

### Node 2 (Pi 3B + ESP32-WROOM)
- **Role:** Displacement + crack monitoring
- **Sensors:** Potentiometer (displacement), crack sensor
- **Comms:** Ethernet to switch, MQTT to Pi 4
- **Alert:** Local OLED

### Node 3 (ESP32-C3 standalone)
- **Role:** Tilt + positioning
- **Sensors:** MPU6050 (tilt), GPS
- **Comms:** Wi-Fi mesh, MQTT to Pi 4
- **Alert:** NeoPixel

### Node 4 (ESP32-WROOM standalone)
- **Role:** Vibration + crack monitoring
- **Sensors:** ADXL345 (vibration), crack sensor
- **Comms:** Wi-Fi mesh, MQTT to Pi 4
- **Alert:** OLED

---

## 3. Node Responsibilities

Each node:
1. Samples sensors at configurable rate
2. Filters noise (moving average, median filter)
3. Extracts features (mean, variance, peak)
4. Transmits to gateway via MQTT
5. Buffers locally if network unavailable
6. Triggers local alert on threshold breach
