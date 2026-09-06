#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>

#define OLED_SDA 5
#define OLED_SCL 6
#define NEO_PIN  8

Adafruit_SSD1306 display(128, 64, &Wire, -1);
Adafruit_NeoPixel pixels(1, NEO_PIN, NEO_GRB + NEO_KHZ800);
WiFiClient espClient;
PubSubClient mqtt(espClient);

void callback(char* topic, byte* payload, unsigned int len) {
  String msg;
  for (int i = 0; i < len; i++) msg += (char)payload[i];

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(topic);
  display.println(msg);
  display.display();

  if (msg == "RED")         pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  else if (msg == "GREEN")  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();
}

void setup() {
  Serial.begin(115200);
  Wire.begin(OLED_SDA, OLED_SCL);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.println("ULTRON C3");
  display.display();
  pixels.begin();

  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) delay(100);

  mqtt.setServer("broker.emqx.io", 1883);
  mqtt.setCallback(callback);
}

void loop() {
  if (!mqtt.connected()) {
    if (mqtt.connect("ultron-c3")) mqtt.subscribe("ultron/status");
  }
  mqtt.loop();
}