//
// Created by xela on 5/3/18.
//

#pragma once

#include "common/basic_types.h"
#include "fstream"
#include "string"

class HIDDevice {
public:
    HIDDevice(const std::string& path, UInt32 dataSize);
    virtual ~HIDDevice();

protected:
    UInt32 m_dataSize;
    UInt8* m_data;
    void update();

private:
    std::ofstream* m_device;
};
