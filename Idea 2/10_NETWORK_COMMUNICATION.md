# SIH26178 — Network Communication

> Protocol, message format, node IDs, packet structure, sync, retry, offline behavior.

---

## 1. Network Topology

```
Node A ──┐
Node B ──┼── Mesh ──► Gateway (Pi 4) ──► Local Server ──► Dashboard
Node C ──┘
Node D ──┘
```

---

## 2. Protocol

- **Mesh:** LoRa/Zigbee/Wi-Fi mesh between nodes
- **Gateway uplink:** Ethernet/Wi-Fi to Pi 4
- **Telemetry:** MQTT (paho-mqtt)
- **Broker:** mosquitto on Pi 4

---

## 3. Message Format

```json
{
  "node_id": "node_A",
  "timestamp": "2026-09-06T12:00:00Z",
  "sensor_type": "smoke",
  "value": 0.42,
  "unit": "ppm",
  "confidence": 0.95,
  "alert_level": "GREEN"
}
```

---

## 4. MQTT Topics

| Topic | Direction | Payload |
|---|---|---|
| `env/node/{id}/data` | Node → Gateway | Sensor readings |
| `env/node/{id}/status` | Node → Gateway | Heartbeat, health |
| `env/gateway/alert` | Gateway → All | Alert level |
| `env/dashboard/update` | Gateway → Dashboard | Aggregated data |
| `env/sachet/push` | Gateway → SACHET | CAP alert push |

---

## 5. Node IDs

- `node_A`, `node_B`, `node_C`, `node_D` (or numeric: `node_01`...)

---

## 6. Packet Structure

```
[Header: node_id, timestamp, seq]
[Payload: sensor readings + edge AI result]
[Checksum: CRC]
```

---

## 7. Synchronization

- Nodes timestamp locally (NTP sync when online)
- Gateway correlates timestamps across nodes
- Periodic clock sync on reconnect

---

## 8. Retry Behavior

- MQTT QoS 1 (at-least-once) for critical alerts
- QoS 0 for routine telemetry
- Local buffering + replay on reconnect

---

## 9. Offline Behavior

- Nodes run on-device edge AI locally
- Nodes buffer locally (SD/flash)
- Gateway continues edge AI locally
- Alerts fire locally (GPIO, OLED, NeoPixel)
- On reconnect: sync buffered data, reconcile timestamps
