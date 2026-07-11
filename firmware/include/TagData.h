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