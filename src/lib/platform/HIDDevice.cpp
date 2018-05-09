//
// Created by xela on 5/3/18.
//

#include "base/Log.h"
#include "HIDDevice.h"

HIDDevice::HIDDevice(
        const std::string &path,
        UInt32 dataSize) :
    m_dataSize(dataSize)
{
    m_device = new std::ofstream();
    m_device->open(path, std::ofstream::binary);

    m_data = new UInt8[m_dataSize];
    std::fill(m_data, m_data + m_dataSize, 0);
}

HIDDevice::~HIDDevice()
{
    m_device->close();
    delete m_device;

    delete m_data;
}

void HIDDevice::update() {
    m_device->write((char *)m_data, m_dataSize);
}
