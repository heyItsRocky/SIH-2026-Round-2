# SIH26025 — Sensor Selection

> Which physical measurement actually represents the phenomenon we're trying to detect?

---

## 1. Sensor Candidates

| Sensor | Measures | Accuracy | Cost | Interface | Why use? | Risks |
|---|---|---|---|---|---|---|
| **MPU6050** | Tilt, acceleration, gyro | Good | ~₹150 | I2C | Ground tilt detection | Drift over time |
| **BNO055** | Tilt, orientation (fused) | Excellent | ~₹400 | I2C | High-accuracy tilt | Higher cost |
| **ADXL345** | Vibration, acceleration | Good | ~₹200 | I2C/SPI | Ground vibration | Noise |
| **SW-420** | Vibration (threshold) | Basic | ~₹50 | Digital | Simple vibration trigger | No analog data |
| **Potentiometer/strain gauge** | Displacement/stretch | Good | ~₹200 | Analog | Node-to-node distance | Calibration |
| **Crack sensor (resistive)** | Crack initiation | Basic | ~₹100 | Analog | Early crack detection | False positives |
| **GPS (NEO-6M)** | Node position | Good | ~₹300 | UART | Node positioning | Indoor/underground no signal |
| **DHT22** | Temp/humidity | Good | ~₹100 | Digital | Environmental context | Slow updates |

---

## 2. Selection Criteria

The important question is not "what sensors can we buy" but:

> **Which physical measurement actually represents the phenomenon we're trying to detect?**

For subsidence (ground sinking), the key signals are:
- **Tilt** — ground tilting as it deforms
- **Vibration** — unusual vibration signatures before failure
- **Displacement** — change in relative distance between nodes
- **Crack initiation** — early surface cracking

---

## 3. Recommended Sensor Set (per node)

| Node | Sensors | Purpose |
|---|---|---|
| Node A | MPU6050 (tilt) + ADXL345 (vibration) | Tilt + vibration monitoring |
| Node B | Potentiometer (displacement) + crack sensor | Displacement + crack detection |
| Node C | MPU6050 (tilt) + GPS | Tilt + positioning |
| Node D | ADXL345 (vibration) + crack sensor | Vibration + crack detection |

---

## 4. Calibration & Noise

- Cheap sensors have drift and noise — plan for calibration
- Use a physical scale-model rig to validate sensor behavior
- Multi-node correlation helps distinguish local disturbance from genuine ground movement
