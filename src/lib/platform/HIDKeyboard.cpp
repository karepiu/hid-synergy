//
// Created by xela on 10/1/18.
//

#include <base/Log.h>
#include "HIDKeyboard.h"

std::map<KeyID, char> HIDKeyboard::KEY_TO_USB = {
        {0x0061, 0x04}, // a
        {0x0062, 0x05}, // b
        {0x0063, 0x06}, // c
        {0x0064, 0x07}, // d
        {0x0065, 0x08}, // e
        {0x0066, 0x09}, // f
        {0x0067, 0x0a}, // g
        {0x0068, 0x0b}, // h
        {0x0069, 0x0c}, // i
        {0x006a, 0x0d}, // j
        {0x006b, 0x0e}, // k
        {0x006c, 0x0f}, // l
        {0x006d, 0x10}, // m
        {0x006e, 0x11}, // n
        {0x006f, 0x12}, // o
        {0x0070, 0x13}, // p
        {0x0071, 0x14}, // q
        {0x0072, 0x15}, // r
        {0x0073, 0x16}, // s
        {0x0074, 0x17}, // t
        {0x0075, 0x18}, // u
        {0x0076, 0x19}, // v
        {0x0077, 0x1a}, // w
        {0x0078, 0x1b}, // x
        {0x0079, 0x1c}, // y
        {0x007a, 0x1d}, // z
        {0x0031, 0x1e}, // 1
        {0x0032, 0x1f}, // 2
        {0x0033, 0x20}, // 3
        {0x0034, 0x21}, // 4
        {0x0035, 0x22}, // 5
        {0x0036, 0x23}, // 6
        {0x0037, 0x24}, // 7
        {0x0038, 0x25}, // 8
        {0x0039, 0x26}, // 9
        {0x0030, 0x27}, // 0
        {kKeyReturn, 0x28},
        {kKeyEscape, 0x29},
        {kKeyBackSpace, 0x2a},
        {kKeyTab, 0x2b},
        {0x0020, 0x2c}, // space
        {0x002d, 0x2d}, // dash
        {0x003d, 0x2e}, // equals
        {0x005b, 0x2f}, // [
        {0x005d, 0x30}, // ]
//        {"backslash", 0x31},
//        {"hash", 0x32},
//        {"number", 0x32},
//        {"semicolon", 0x33},
//        {"quote", 0x34},
//        {"backquote", 0x35},
//        {"tilde", 0x35},
//        {"comma", 0x36},
//        {"period", 0x37},
//        {"stop", 0x37},
//        {"slash", 0x38},
//        {"caps-lock", 0x39},
//        {"capslock", 0x39},
//        {"f1", 0x3a},
//        {"f2", 0x3b},
//        {"f3", 0x3c},
//        {"f4", 0x3d},
//        {"f5", 0x3e},
//        {"f6", 0x3f},
//        {"f7", 0x40},
//        {"f8", 0x41},
//        {"f9", 0x42},
//        {"f10", 0x43},
//        {"f11", 0x44},
//        {"f12", 0x45},
//        {"print", 0x46},
//        {"scroll-lock", 0x47},
//        {"scrolllock", 0x47},
//        {"pause", 0x48},
//        {"insert", 0x49},
//        {"home", 0x4a},
//        {"pageup", 0x4b},
//        {"pgup", 0x4b},
//        {"del", 0x4c},
//        {"delete", 0x4c},
//        {"end", 0x4d},
//        {"pagedown", 0x4e},
//        {"pgdown", 0x4e},
//        {"right", 0x4f},
//        {"left", 0x50},
//        {"down", 0x51},
//        {"up", 0x52},
//        {"num-lock", 0x53},
//        {"numlock", 0x53},
//        {"kp-divide", 0x54},
//        {"kp-multiply", 0x55},
//        {"kp-minus", 0x56},
//        {"kp-plus", 0x57},
//        {"kp-enter", 0x58},
//        {"kp-return", 0x58},
//        {"kp-1", 0x59},
//        {"kp-2", 0x5a},
//        {"kp-3", 0x5b},
//        {"kp-4", 0x5c},
//        {"kp-5", 0x5d},
//        {"kp-6", 0x5e},
//        {"kp-7", 0x5f},
//        {"kp-8", 0x60},
//        {"kp-9", 0x61},
//        {"kp-0", 0x62},
//        {"kp-period", 0x63},
//        {"kp-stop", 0x63},
//        {"application", 0x65},
//        {"power", 0x66},
//        {"kp-equals", 0x67},
//        {"kp-equal", 0x67},
//        {"f13", 0x68},
//        {"f14", 0x69},
//        {"f15", 0x6a},
//        {"f16", 0x6b},
//        {"f17", 0x6c},
//        {"f18", 0x6d},
//        {"f19", 0x6e},
//        {"f20", 0x6f},
//        {"f21", 0x70},
//        {"f22", 0x71},
//        {"f23", 0x72},
//        {"f24", 0x73},
//        {"execute", 0x74},
//        {"help", 0x75},
//        {"menu", 0x76},
//        {"select", 0x77},
//        {"cancel", 0x78},
//        {"redo", 0x79},
//        {"undo", 0x7a},
//        {"cut", 0x7b},
//        {"copy", 0x7c},
//        {"paste", 0x7d},
//        {"find", 0x7e},
//        {"mute", 0x7f},
};

HIDKeyboard::HIDKeyboard(
        const std::string& path) :
        HIDDevice(path, DATA_SIZE)
{

}

HIDKeyboard::~HIDKeyboard() {

}

void HIDKeyboard::pressKey(KeyID button) {
    LOG((CLOG_DEBUG "pressKey: (%d)", button));
    auto keyIter = KEY_TO_USB.find(button);
    if (keyIter == KEY_TO_USB.end()) {
        return;
    }
    char key = keyIter->second;
    for (char &pressed_key : pressed_keys) {
        if (pressed_key == 0) {
            pressed_key = key;
            updateKeys();
            return;
        }
    }
}

void HIDKeyboard::releaseKey(KeyID button) {
    LOG((CLOG_DEBUG "pressKey: (%d)", button));
    auto keyIter = KEY_TO_USB.find(button);
    if (keyIter == KEY_TO_USB.end()) {
        return;
    }
    char key = keyIter->second;
    for (char &pressed_key : pressed_keys) {
        if (pressed_key == key) {
            pressed_key = 0;
            updateKeys();
            return;
        }
    }
}

void HIDKeyboard::updateKeys() {
    m_data[0] = modifier;
    for (int i = 0; i < sizeof(pressed_keys); ++i) {
        m_data[i + 2] = pressed_keys[i];
    }
    update();
}

