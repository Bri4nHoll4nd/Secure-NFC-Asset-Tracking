#pragma once

#include "TagData.h"
#include "ApiManager.h"

#include <optional>
#include <string>

class NfcReader {
    public:
        //Initialize PN532
        bool start();

        //Read tag data and store it
        std::optional<std::string> readTag();

        //Write tag data
        bool writeTag();

    private:
        std::string uidToString(std::uint8_t* uid, std::uint8_t uidLength);
};