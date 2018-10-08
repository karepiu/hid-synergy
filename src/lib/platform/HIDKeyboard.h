//
// Created by xela on 10/1/18.
//

#pragma once

#include <string>
#include <core/key_types.h>
#include "HIDDevice.h"

class HIDKeyboard : public HIDDevice {
public:
    HIDKeyboard(const std::string &path);
    ~HIDKeyboard();

    void updateKey(KeyButton button, bool press);

private:
    static const UInt32 DATA_SIZE = 3;
};
