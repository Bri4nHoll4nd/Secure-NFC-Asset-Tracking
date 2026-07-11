#pragma once

#include "WiFiManager.h"
#include "TagData.h"

class ApiManager {
    public:
        ApiManager(WiFiManager& manager);
        bool sendTagUid(std::string tagUid);
        TagWriteData getWriteData();

    private:
        WiFiManager wifiManager;
};