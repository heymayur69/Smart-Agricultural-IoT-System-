#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "wifi-username";      // Your WiFi name
const char* password = "wifi-password";  // Your WiFi password

WiFiClient client;

// Replace with your ThingSpeak channel number
unsigned long ChannelNo = 123456;        

// ThingSpeak Write API Key
const char* API_Key = "02BHJL8138761";   

void setup() {
  Serial.begin(9600);

  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);

  WiFi.disconnect();
  delay(100);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Wait for WiFi Connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("NodeMCU connected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(client);
}

void loop() {
  // Writing to 3 fields
  ThingSpeak.writeField(ChannelNo, 1, digitalRead(D1), API_Key);
  ThingSpeak.writeField(ChannelNo, 2, digitalRead(D2), API_Key);
  ThingSpeak.writeField(ChannelNo, 3, digitalRead(D3), API_Key);

  Serial.println("Data sent to ThingSpeak...");
  delay(15000);  // ThingSpeak requires ~15 seconds between updates
}
