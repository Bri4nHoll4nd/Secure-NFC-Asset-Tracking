#pragma once

#include <array>
#include <cstdint>

struct TagData {
    std::array<uint8_t, 10> uid{};
    uint8_t length = 0;
};