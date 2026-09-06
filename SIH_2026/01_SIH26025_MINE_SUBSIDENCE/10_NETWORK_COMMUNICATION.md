# SIH26025 — Network Communication

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
  "sensor_type": "tilt",
  "value": 0.42,
  "unit": "degrees",
  "confidence": 0.95
}
```

---

## 4. MQTT Topics

| Topic | Direction | Payload |
|---|---|---|
| `mine/node/{id}/data` | Node → Gateway | Sensor readings |
| `mine/node/{id}/status` | Node → Gateway | Heartbeat, health |
| `mine/gateway/alert` | Gateway → All | Alert level |
| `mine/dashboard/update` | Gateway → Dashboard | Aggregated data |

---

## 5. Node IDs

- `node_A`, `node_B`, `node_C`, `node_D` (or numeric: `node_01`...)

---

## 6. Packet Structure

```
[Header: node_id, timestamp, seq]
[Payload: sensor readings]
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

- Nodes buffer locally (SD/flash)
- Gateway continues edge AI locally
- Alerts fire locally (GPIO, OLED, NeoPixel)
- On reconnect: sync buffered data, reconcile timestamps
