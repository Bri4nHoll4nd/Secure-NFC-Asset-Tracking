#pragma once

class WiFiManager {
    public:
        void connect();
        bool isConnected() const;
};