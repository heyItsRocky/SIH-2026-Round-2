import paho.mqtt.client as mqtt
import time

BROKER = "broker.emqx.io"
results = {}

def on_status(client, userdata, msg):
    results["status"] = msg.payload.decode()
    print(f"[TEST] received ultron/status = {results['status']}", flush=True)

def on_trip(client, userdata, msg):
    results["trip"] = f"{msg.topic} = {msg.payload.decode()}"
    print(f"[TEST] received {results['trip']}", flush=True)

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, "ultron-test")
client.message_callback_add("ultron/tripwire/#", on_trip)
client.on_message = on_status
client.connect(BROKER, 1883, 60)
client.subscribe("ultron/status")
client.subscribe("ultron/tripwire/#")
client.loop_start()
time.sleep(2)

print("[TEST] publishing tripwire A = TRIPPED", flush=True)
client.publish("ultron/tripwire/A", "TRIPPED")
time.sleep(3)
red_seen = results.get("status") == "RED"

print("[TEST] publishing tripwire A = CLEAR", flush=True)
client.publish("ultron/tripwire/A", "CLEAR")
time.sleep(3)

client.loop_stop()
client.disconnect()

ok = red_seen
print(f"\n[TEST] RESULT: {'PASS' if ok else 'FAIL'} (expected RED after TRIPPED, got {results.get('status')})", flush=True)