#include <WiFi.h>
#include <PubSubClient.h>

#define TRIP_A 16
#define TRIP_B 17

WiFiClient espClient;
PubSubClient mqtt(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(TRIP_A, INPUT_PULLUP);
  pinMode(TRIP_B, INPUT_PULLUP);

  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) delay(100);

  mqtt.setServer("broker.emqx.io", 1883);
}

void loop() {
  if (!mqtt.connected()) {
    if (mqtt.connect("ultron-wroom")) mqtt.publish("ultron/tripwire/status", "online");
  }
  mqtt.loop();

  static bool lastA = HIGH, lastB = HIGH;
  bool a = digitalRead(TRIP_A);
  bool b = digitalRead(TRIP_B);

  if (a != lastA) {
    mqtt.publish("ultron/tripwire/A", a == LOW ? "TRIPPED" : "CLEAR");
    Serial.printf("Tripwire A: %s\n", a == LOW ? "TRIPPED" : "CLEAR");
    lastA = a;
  }
  if (b != lastB) {
    mqtt.publish("ultron/tripwire/B", b == LOW ? "TRIPPED" : "CLEAR");
    Serial.printf("Tripwire B: %s\n", b == LOW ? "TRIPPED" : "CLEAR");
    lastB = b;
  }
}