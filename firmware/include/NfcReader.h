#pragma once

#include "TagData.h"
#include <optional>
#include <string>

class NfcReader {
    public:
        //Initialize PN532
        bool start();

        //Read tag data and store it
        std::optional<TagData> readTag();
};