# SIH26178 — Node Architecture

> Define exactly what one environmental node looks like.

---

## 1. Single Node Architecture

```
Sensors (smoke, temp, humidity, PM2.5, gas, water level)
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

## 2. Node Definitions (Fire MVP)

### Node A (Pi 3A+ + ESP32-C3)
- **Role:** Fire detection
- **Sensors:** MQ-2 (smoke), DHT22 (temp/humidity)
- **Comms:** Ethernet to switch, MQTT to Pi 4
- **Alert:** Local NeoPixel

### Node B (Pi 3B + ESP32-WROOM)
- **Role:** Air quality + fire
- **Sensors:** PMS5003 (PM2.5/PM10), MQ-135 (gas), DHT22
- **Comms:** Ethernet to switch, MQTT to Pi 4
- **Alert:** Local OLED

### Node C (ESP32-C3 standalone)
- **Role:** Fire detection (redundant)
- **Sensors:** MQ-2 (smoke), DHT22 (temp/humidity)
- **Comms:** Wi-Fi mesh, MQTT to Pi 4
- **Alert:** NeoPixel

### Node D (ESP32-WROOM standalone)
- **Role:** Heat + dryness precursor
- **Sensors:** DHT22 (temp/humidity), soil moisture
- **Comms:** Wi-Fi mesh, MQTT to Pi 4
- **Alert:** OLED

---

## 3. Node Responsibilities

Each node:
1. Samples sensors at configurable rate
2. Filters noise (moving average, median filter)
3. Extracts features (mean, variance, peak)
4. Runs on-device edge AI inference (TFLite Micro)
5. Transmits only critical alerts + summarized insights
6. Buffers locally if network unavailable
7. Triggers local alert on threshold breach
