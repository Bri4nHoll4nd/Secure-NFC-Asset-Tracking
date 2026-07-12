#pragma once

#include "WiFiManager.h"
#include "TagData.h"

#include <optional>

class ApiManager {
    public:
        ApiManager(WiFiManager& manager);
        bool sendTagUid(std::string tagUid);
        std::optional<TagWriteData> getWriteData();

    private:
        WiFiManager wifiManager;
};