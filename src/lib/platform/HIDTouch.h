//
// Created by xela on 8/14/18.
//

#pragma once

#include "HIDDevice.h"

class HIDTouch : public HIDDevice {
public:
    HIDTouch(const std::string& path);
    ~HIDTouch();

    void move(float xFrac, float yFrac);

private:
    static const UInt32 RESOLUTION = 65536;
    static const UInt32 DATA_SIZE = 5;
};
