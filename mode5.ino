#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// WiFi credentials
const char* ssid = "LAPTOP-OBJVKBNE 8211";
const char* password = "123456789";

// MQTT Server
const char* mqtt_server = "192.168.197.66";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (200) // Adjusted for JSON data
char msg[MSG_BUFFER_SIZE];

// Digital pins
const int digitalPin1 = D0;
const int digitalPin2 = D5;
const int digitalPin3 = D4;
const int digitalPin4 = D7;
const int digitalPin5 = D3;

// LED Pin
const int ledPin = D6; // Assign an appropriate pin for the LED

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  if (strcmp(topic, "ledControl") == 0) {
      if ((char)payload[0] == '1') {
          digitalWrite(ledPin, HIGH); // Turn the LED on
      } else {
          digitalWrite(ledPin, LOW);  // Turn the LED off
      }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe("ledControl");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(digitalPin1, INPUT);
  pinMode(digitalPin2, INPUT);
  pinMode(digitalPin3, INPUT);
  pinMode(digitalPin4, INPUT);
  pinMode(digitalPin5, INPUT);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

    val1 = digitalRead(digitalPin1);
    val2 = digitalRead(digitalPin2);
    val3 = digitalRead(digitalPin3);
    val4 = digitalRead(digitalPin4);
    val5 = digitalRead(digitalPin5);

    StaticJsonDocument<200> jsonDoc;
    jsonDoc["val1"] = val1;
    jsonDoc["val2"] = val2;
    jsonDoc["val3"] = val3;
    jsonDoc["val4"] = val4;
    jsonDoc["val5"] = val5;

    serializeJson(jsonDoc, msg);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("sensors", msg);
  }
}
