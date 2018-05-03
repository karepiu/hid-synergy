//
// Created by xela on 5/1/18.
//

#include "base/Log.h"
#include "base/TMethodEventJob.h"
#include "HIDScreen.h"

HIDScreen::HIDScreen(
        const std::string & mouseDevice,
        const std::string & keyboardDevice,
        IEventQueue *events) :
    PlatformScreen(events),
    m_mouseDevice(mouseDevice),
    m_keyboardDevice(keyboardDevice),
    m_events(events),
    m_keyState(nullptr)
{
    // TODO

    m_keyState = new HIDKeyState(events, m_keyMap);

    // install event handlers
    m_events->adoptHandler(Event::kSystem, m_events->getSystemTarget(),
                           new TMethodEventJob<HIDScreen>(this,
                               &HIDScreen::handleSystemEvent));

    LOG((CLOG_DEBUG "HIDScreen constructed"));

}

HIDScreen::~HIDScreen()
{
    // TODO
    delete m_keyState;

    m_events->removeHandler(Event::kSystem, m_events->getSystemTarget());
}

void *HIDScreen::getEventTarget() const
{
    return const_cast<HIDScreen*>(this);
}

bool HIDScreen::getClipboard(ClipboardID id, IClipboard *) const
{
    // Not supported
    return false;
}

void HIDScreen::getShape(SInt32 &x, SInt32 &y, SInt32 &w, SInt32 &h) const
{
    // TODO
}

void HIDScreen::getCursorPos(SInt32 &x, SInt32 &y) const
{
    // TODO
}

void HIDScreen::reconfigure(UInt32 /*unused*/)
{
    // Not supported
}

void HIDScreen::warpCursor(SInt32 /*unused*/, SInt32 /*unused*/)
{
    // Not supported
}

UInt32 HIDScreen::registerHotKey(KeyID /*unused*/, KeyModifierMask /*unused*/)
{
    // Not supported
    return 0;
}

void HIDScreen::unregisterHotKey(UInt32 /*unused*/)
{
    // Not supported
}

void HIDScreen::fakeInputBegin()
{
    // Not supported
}

void HIDScreen::fakeInputEnd()
{
    // Not supported
}

SInt32 HIDScreen::getJumpZoneSize() const
{
    // Not supported
    return 0;
}

bool HIDScreen::isAnyMouseButtonDown(UInt32 &buttonID) const
{
    // Not supported
    return false;
}

void HIDScreen::getCursorCenter(SInt32 &x, SInt32 &y) const
{
    // Not supported
}

void HIDScreen::fakeMouseButton(ButtonID button, bool press)
{
    // TODO
}

void HIDScreen::fakeMouseMove(SInt32 x, SInt32 y)
{
    // TODO
}

void HIDScreen::fakeMouseRelativeMove(SInt32 dx, SInt32 dy) const
{
    // TODO
}

void HIDScreen::fakeMouseWheel(SInt32 xDelta, SInt32 yDelta) const
{
    // TODO
}

void HIDScreen::enable()
{
    // TODO
}

void HIDScreen::disable()
{
    // TODO
}

void HIDScreen::enter()
{
    // TODO
}

bool HIDScreen::leave()
{
    // TODO
    return true;
}

bool HIDScreen::setClipboard(ClipboardID, const IClipboard *)
{
    // Not supported
    return false;
}

void HIDScreen::checkClipboards()
{
    // Not supported
}

void HIDScreen::openScreensaver(bool /*unused*/)
{
    // Not supported
}

void HIDScreen::closeScreensaver()
{
    // Not supported
}

void HIDScreen::screensaver(bool /*unused*/)
{
    // Not supported
}

void HIDScreen::resetOptions()
{
    // TODO
}

void HIDScreen::setOptions(const OptionsList &options)
{
    // TODO
}

void HIDScreen::setSequenceNumber(UInt32)
{
    // TODO
}

bool HIDScreen::isPrimary() const
{
    return false;
}

void HIDScreen::handleSystemEvent(const Event &, void *)
{
    // TODO
}

void HIDScreen::updateButtons()
{
    // TODO
}

IKeyState *HIDScreen::getKeyState() const
{
    return m_keyState;
}
