#pragma once

#include <array>
#include <cstdint>

struct TagWriteData {
    std::string tagId;
    std::string tagVersion;
    std::string tagSignature;
};

struct TagReadData {
    std::string tagUid;
    std::string tagId;
    std::string tagVersion;
    std::string tagSignature;
};

struct TagUidData {
    std::uint8_t tagUid[7] = {0};
    std::uint8_t tagUidLength = 0;
};