//
// Created by xela on 5/3/18.
//

#pragma once

#include "core/KeyState.h"

class HIDKeyState : public KeyState {
public:
    HIDKeyState(IEventQueue* events);
    HIDKeyState(IEventQueue* events, synergy::KeyMap& keyMap);
    ~HIDKeyState();

    // IKeyState overrides
    virtual bool        fakeCtrlAltDel();
    virtual KeyModifierMask pollActiveModifiers() const;
    virtual SInt32      pollActiveGroup() const;
    virtual void        pollPressedKeys(KeyButtonSet& pressedKeys) const;

protected:
    // KeyState overrides
    virtual void        getKeyMap(synergy::KeyMap& keyMap);
    virtual void        fakeKey(const Keystroke& keystroke);

private:
    void                init();
};

