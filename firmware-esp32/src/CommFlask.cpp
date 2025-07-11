#include "CommFlask.h"
#include <WiFi.h>
#include "config.h"
#include <Arduino.h>
#include "DataStruct.h"
#include "JsonManager.h"

WiFiServer server(80);

void parseRequest(String request, WiFiClient client, String currentData);

void initWifi() {
    WiFi.softAP(ssid, password);
    server.begin();
    Serial.println("Access Point started !");
    Serial.println(WiFi.softAPIP());  // Show AP IP (always 192.168.4.1)
}

void handleClient(String currentData) {
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
                request.trim();

                parseRequest(request, client, currentData);
                // You can send only when request is valid or just send anyway
                client.stop();  // Close connection
                Serial.println("Client disconnected.");
                break;
            }
        }
    }
}

void parseRequest(String request, WiFiClient client, String currentData){
    String filename;
    if (request.startsWith("GET:")){
        filename = request.substring(4);
        client.println(currentData);
    }
    else if (request.startsWith("READ:")){
        filename = request.substring(5);
        String dataRead = readJSON(filename);
        client.println(dataRead);
    }
    else if (request.startsWith("WRITE:")){
        filename = request.substring(6);
        writetoJson(filename);
        client.println("OK");
    }
    else if (request.startsWith("LIST")){
        String listofFiles = listFiles();
        client.println(listofFiles);
    }
    else if (request.startsWith("CREATE:")){
        filename = request.substring(7);
        String status = createNewFile(filename);
        client.println(status);
    }
}

