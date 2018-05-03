//
// Created by xela on 5/3/18.
//

#include "HIDKeyState.h"

HIDKeyState::HIDKeyState(
        IEventQueue* events) :
        KeyState(events)
{
    init();
}

HIDKeyState::HIDKeyState(
        IEventQueue* events, synergy::KeyMap& keyMap) :
        KeyState(events, keyMap)
{
    init();
}

HIDKeyState::~HIDKeyState()
{
    // TODO
}

void HIDKeyState::init()
{
    // TODO
}

bool HIDKeyState::fakeCtrlAltDel()
{
    return false;
}

KeyModifierMask HIDKeyState::pollActiveModifiers() const
{
    // TODO
    return 0;
}

SInt32 HIDKeyState::pollActiveGroup() const
{
    // TODO
    return 0;
}

void HIDKeyState::pollPressedKeys(IKeyState::KeyButtonSet &pressedKeys) const
{
    // TODO
}

void HIDKeyState::getKeyMap(synergy::KeyMap &keyMap)
{
    // TODO
}

void HIDKeyState::fakeKey(const KeyState::Keystroke &keystroke)
{
    // TODO
}
