# SIH26025 — Circuit Design

> Actual electronics documentation: pin mapping, power rails, GPIO, sensor connections.

---

## 1. ESP32-C3 Node Circuit

```
ESP32-C3 Mini DevKit
    │
    ├── GPIO5 ──► SDA ──► MPU6050 (tilt)
    ├── GPIO6 ──► SCL ──► MPU6050 (tilt)
    ├── GPIO7 ──► SDA ──► ADXL345 (vibration)
    ├── GPIO8 ──► SCL ──► ADXL345 (vibration)
    ├── GPIO9 ──► DATA ──► NeoPixel (alert)
    ├── 3V3 ────────────► Sensors VCC
    ├── GND ────────────► Sensors GND
    └── USB ────────────► Pi 4 (power + serial)
```

---

## 2. ESP32-WROOM Node Circuit

```
ESP32-WROOM-32
    │
    ├── GPIO21 ──► SDA ──► Displacement sensor
    ├── GPIO22 ──► SCL ──► Displacement sensor
    ├── GPIO34 ──► Analog ──► Crack sensor
    ├── GPIO16 ──► Tripwire A (from Pi 3A+)
    ├── GPIO17 ──► Tripwire B (from Pi 3B)
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

---

## 5. Verification Checklist

- [ ] Shared tripwire ground verified
- [ ] NeoPixel power/ground correct
- [ ] UART pin mapping correct
- [ ] Sensor I2C addresses don't conflict
- [ ] Power budget within Pi 4 USB limits
