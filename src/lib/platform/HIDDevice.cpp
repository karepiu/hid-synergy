//
// Created by xela on 5/3/18.
//

#include "base/Log.h"
#include "core/XScreen.h"
#include "HIDDevice.h"

#include <unistd.h>
#include <fcntl.h>

HIDDevice::HIDDevice(
        const std::string &path,
        UInt32 dataSize) :
    m_dataSize(dataSize)
{
    if ((m_fd = open(path.c_str(), O_RDWR, 0666)) == -1) {
        throw XScreenOpenFailure("failed to open HID device");
    }

    m_data = new char[m_dataSize];
    LOG((CLOG_DEBUG "initial: %d %d %d %d", m_data[0], m_data[1], m_data[2], dataSize));

    memset(m_data, 0, m_dataSize);
}

HIDDevice::~HIDDevice()
{
    close(m_fd);
    delete m_data;
}

void HIDDevice::update() {
    LOG((CLOG_DEBUG "updating: %d %d %d", m_data[0], m_data[1], m_data[2]));

    if (write(m_fd, m_data, m_dataSize) != m_dataSize) {
        throw std::runtime_error("failed to write to HID device");
    }
}
