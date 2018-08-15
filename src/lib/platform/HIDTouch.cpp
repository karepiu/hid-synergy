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
    m_data[1] = (int) xFrac * RESOLUTION;
    m_data[2] = (int) yFrac * RESOLUTION;

    update();
}
