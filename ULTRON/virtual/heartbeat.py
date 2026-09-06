import paho.mqtt.client as mqtt
import time
import sys

BROKER = "broker.emqx.io"   # change to test.mosquitto.org if Phase 0.2 chose backup
NODE = sys.argv[1] if len(sys.argv) > 1 else "pi3a-node"

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1, NODE)
client.connect(BROKER, 1883, 60)
client.loop_start()
while True:
    client.publish(f"ultron/node/{NODE}/status", "online")
    time.sleep(10)