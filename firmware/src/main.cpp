#include <Arduino.h>
#include "NfcReader.h"
#include "WiFiManager.h"
#include "ApiManager.h"

WiFiManager wifiManager;
NfcReader nfcReader;
ApiManager apiManager(wifiManager);

void setup() {
  Serial.begin(115200);
  delay(1000);

  wifiManager.connect();
  nfcReader.start();
}

void loop() {
  auto tag = nfcReader.readTag();

  if (tag.has_value()) {
    apiManager.sendTagUid(tag.value());
  }
  
  delay(2000);
}
