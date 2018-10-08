//
// Created by xela on 10/1/18.
//

#include <base/Log.h>
#include "HIDKeyboard.h"

HIDKeyboard::HIDKeyboard(
        const std::string& path) :
        HIDDevice(path, DATA_SIZE)
{

}

HIDKeyboard::~HIDKeyboard() {

}

void HIDKeyboard::updateKey(KeyButton button, bool press) {
    LOG((CLOG_DEBUG "updateKey: (%d %d)", button, press));
}
