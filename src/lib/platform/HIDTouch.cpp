//
// Created by xela on 8/14/18.
//

#include <base/Log.h>
#include "HIDTouch.h"

HIDTouch::HIDTouch(
        const std::string& path) :
    HIDDevice(path, DATA_SIZE)
{

}

HIDTouch::~HIDTouch() {

}

void HIDTouch::move(float xFrac, float yFrac) {

    m_data[0] = 0x02;

    auto xCoord = (UInt32) (xFrac * RESOLUTION);
    auto yCoord = (UInt32) (yFrac * RESOLUTION);

    auto xPtr = (char *)&xCoord;
    auto yPtr = (char *)&yCoord;

    LOG((CLOG_DEBUG "%u %u", xCoord, yCoord));

    m_data[1] = xPtr[0];
    m_data[2] = xPtr[1];

    m_data[3] = yPtr[0];
    m_data[4] = yPtr[1];

    LOG((CLOG_DEBUG "%u %u, %u %u", m_data[1], m_data[2], m_data[3], m_data[4]));

    update();
}
