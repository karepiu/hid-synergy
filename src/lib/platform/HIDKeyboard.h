//
// Created by xela on 10/1/18.
//

#pragma once

#include <string>
#include <core/key_types.h>
#include <map>
#include "HIDDevice.h"

class HIDKeyboard : public HIDDevice {
public:
    HIDKeyboard(const std::string &path);
    ~HIDKeyboard();

    void pressKey(KeyID button);
    void releaseKey(KeyID button);
    void updateKeys();

private:
    std::map<KeyID, char> m_keyToUSBMap;
    char m_modifier = 0;
    char* m_pressedKeys;
    static const UInt32 DATA_SIZE = 8;
};
