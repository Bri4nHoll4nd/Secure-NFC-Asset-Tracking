#pragma once

#include <cstdint>

namespace AppConfig {
    constexpr int SDA_PIN = 8;
    constexpr int SCL_PIN = 9;

    constexpr uint8_t ID_BLOCK = 4;
    constexpr uint8_t VERSION_BLOCK = 5;
    constexpr uint8_t SIGNATURE_BLOCK = 6;

    constexpr char SSID[] = "Privat 11";
    constexpr char PASSWORD[] = "90118621";

    constexpr char API_BASE_URL[] = "http://192.168.87.47:5201/api";

    inline uint8_t DEFAULT_KEY_A[6] = {
        0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF
    };

    inline uint8_t DEFAULT_KEY_B[6] = {
        0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF
    };
}