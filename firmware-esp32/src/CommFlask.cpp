#include "CommFlask.h"
#include <WiFi.h>
#include "config.h"
#include <Arduino.h>
#include "DataStruct.h"

WiFiServer server(80);

void initWifi() {
    WiFi.softAP(ssid, password);
    server.begin();
    Serial.println("Access Point started !");
    Serial.println(WiFi.softAPIP());  // Show AP IP (always 192.168.4.1)
}

void castingData(String jsonData) {
    WiFiClient client = server.available();
    
    if (client) {
        Serial.println("Client connected!");
        Serial.println("Connected to WiFi!");
        Serial.print("ESP32 Local IP: ");
        Serial.println(WiFi.localIP());
        // Wait for client request data (optional if you want to detect a request string)
        while (client.connected()) {
            if (client.available()) {
                String request = client.readStringUntil('\n');
                Serial.println("Request: " + request);

                // You can send only when request is valid or just send anyway
                client.println(jsonData);  // Send JSON
                Serial.println("Data sent: " + jsonData);
                
                client.stop();  // Close connection
                Serial.println("Client disconnected.");
                break;
            }
        }
    }
}


