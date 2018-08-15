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

    m_data[1] = xCoord >> 8;
    m_data[2] = xCoord & 127;

    m_data[3] = yCoord >> 8;
    m_data[4] = yCoord & 127;

    update();
}
