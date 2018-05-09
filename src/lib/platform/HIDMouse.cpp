//
// Created by xela on 5/3/18.
//

#include "HIDMouse.h"

HIDMouse::HIDMouse(
        const std::string& path) :
    HIDDevice(path, DATA_SIZE)
{

}

HIDMouse::~HIDMouse() {

}

void HIDMouse::updateButton(ButtonID button, bool press) {

    UInt8 mask;

    switch (button){
    case kButtonLeft:
        mask = 0x01;
        break;

    case kButtonRight:
        mask = 0x02;
        break;

    case kButtonMiddle:
        mask = 0x04;
        break;

    default:
        mask = 0x00;

    }

    // Check if the button needs to be toggled
    if (m_data[0] & mask != press) {
        m_data[0] ^= mask;
    }

    update();
}
