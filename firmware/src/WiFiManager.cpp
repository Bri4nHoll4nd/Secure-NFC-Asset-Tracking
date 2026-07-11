#include "WiFiManager.h"
#include "AppConfig.h"

#include <Arduino.h>
#include <WiFi.h>

void WiFiManager::connect() {
    Serial.println("Starting WiFi test...");

    WiFi.mode(WIFI_STA);
    WiFi.begin(AppConfig::SSID, AppConfig::PASSWORD);

    Serial.print("Connecting");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected!");
    Serial.print("ESP32 IP address: ");
    Serial.println(WiFi.localIP());
}

bool WiFiManager::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}