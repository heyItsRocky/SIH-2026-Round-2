import paho.mqtt.client as mqtt

BROKER = "broker.emqx.io"   # change to test.mosquitto.org if Phase 0.2 chose backup

def on_message(client, userdata, msg):
    payload = msg.payload.decode()
    print(f"[TRIPWIRE] {msg.topic} -> {payload}", flush=True)
    if payload == "TRIPPED":
        client.publish("ultron/status", "RED")
    else:
        client.publish("ultron/status", "GREEN")

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, "pi4-host")
client.on_message = on_message
client.connect(BROKER, 1883, 60)
client.subscribe("ultron/tripwire/#")
print("pi4-host brain online", flush=True)
client.loop_forever()