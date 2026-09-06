# SIH26178 — Circuit Design

> Actual electronics documentation: pin mapping, power rails, GPIO, sensor connections.

---

## 1. ESP32-C3 Node Circuit (Fire Node)

```
ESP32-C3 Mini DevKit
    │
    ├── GPIO5 ──► SDA ──► DHT22 (temp/humidity)
    ├── GPIO6 ──► SCL ──► DHT22 (temp/humidity)
    ├── GPIO7 ──► Analog ──► MQ-2 (smoke)
    ├── GPIO9 ──► DATA ──► NeoPixel (alert)
    ├── 3V3 ────────────► Sensors VCC
    ├── GND ────────────► Sensors GND
    └── USB ────────────► Pi 4 (power + serial)
```

---

## 2. ESP32-WROOM Node Circuit (Air Quality Node)

```
ESP32-WROOM-32
    │
    ├── GPIO16 ──► TX ──► PMS5003 (PM2.5/PM10)
    ├── GPIO17 ──► RX ──► PMS5003 (PM2.5/PM10)
    ├── GPIO34 ──► Analog ──► MQ-135 (gas)
    ├── GPIO21 ──► SDA ──► DHT22 (temp/humidity)
    ├── GPIO22 ──► SCL ──► DHT22 (temp/humidity)
    ├── 3V3 ────────────► Sensors VCC
    ├── GND ────────────► Sensors GND
    └── USB ────────────► Pi 4 (power + serial)
```

---

## 3. Power Rails

| Rail | Source | Devices |
|---|---|---|
| 5V | Pi 4 USB / GPIO pin 4 | ESP32s, sensors |
| 3.3V | ESP32 regulator | Sensors, OLED |
| GND | Common ground | All |

---

## 4. Grounding & Protection

- **Shared ground** across all nodes (verify before power-on)
- **Pull-up resistors** on tripwire inputs (active-low)
- **Decoupling capacitors** on sensor power rails
- **ESD protection** on exposed sensor lines
- **Solar charging circuit** for remote deployment (future)

---

## 5. Verification Checklist

- [ ] Shared tripwire ground verified
- [ ] NeoPixel power/ground correct
- [ ] UART pin mapping correct (PMS5003)
- [ ] Sensor I2C addresses don't conflict
- [ ] Power budget within Pi 4 USB limits
