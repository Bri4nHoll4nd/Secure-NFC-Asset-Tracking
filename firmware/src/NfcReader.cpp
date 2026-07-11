#include "NfcReader.h"
#include "AppConfig.h"
#include "TagData.h"

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PN532.h>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>

Adafruit_PN532 nfc(AppConfig::SDA_PIN, AppConfig::SCL_PIN);

bool NfcReader::start() {
    Serial.println("Starting PN532 I2C test...");

    Wire.begin(AppConfig::SDA_PIN, AppConfig::SCL_PIN);

    nfc.begin();

    uint32_t versiondata = nfc.getFirmwareVersion();

    if (!versiondata) {
    Serial.println("Could not find PN532. Check wiring, power, and I2C switch mode.");
    while (true) {
        delay(1000);
        }
    }

    Serial.print("Found PN532. Firmware version: ");
    Serial.print((versiondata >> 24) & 0xFF, HEX);
    Serial.print(".");
    Serial.println((versiondata >> 16) & 0xFF, HEX);

    nfc.SAMConfig();

    Serial.println("Waiting for NFC tag...");

    return true;
}

std::optional<std::string> NfcReader::readTag() {
    uint8_t uid[7];
    uint8_t uidLength;
    std::string uidString;

    bool success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 1000);

    if (success) {
        Serial.println("Tag detected!");

        uidString = uidToString(uid, uidLength);

        Serial.print("UID length: ");
        Serial.println(uidLength);

        Serial.print("UID: ");
        Serial.println(uidString.c_str());
        
        Serial.println("Remove tag...");
        
        return uidString;
    }

    return std::nullopt;
}

bool NfcReader::writeTag() {
    uint8_t uid[7];
    uint8_t uidLength;
    std::string uidString;

    bool success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 1000);

    if (success) {
        Serial.println("Tag detected!");

        uidString = uidToString(uid, uidLength);

        Serial.print("UID length: ");
        Serial.println(uidLength);

        Serial.print("UID: ");
        Serial.println(uidString.c_str());

        //Send to backend and wait for response
        
        return true;
    }

    return false;
}

std::string NfcReader::uidToString(std::uint8_t* uid, std::uint8_t uidLength) {
    std::ostringstream output;
    output << std::hex << std::uppercase << std::setfill('0');

    for (std::uint8_t i = 0; i < uidLength; i++) {
        output << std::setw(2) << static_cast<int>(uid[i]);
    }
    
    return output.str();
}