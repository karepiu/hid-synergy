# HID Synergy

This is a fork of the open source core component of Synergy, a keyboard
and mouse sharing tool.
For compilation and configuration, check
[the main repo](https://github.com/symless/synergy-core).

One current limitation of Synergy is the relatively powerful control it
needs to control the mouse and keyboard. For this reason, operating
systems like Android and Chrome OS will likely never support Synergy
directly.

However, by employing the use of a programmable HID (such as a
[Raspberry Pi Zero W](https://www.raspberrypi.org/products/raspberry-pi-zero-w/)),
Synergy can be used on pretty much any device that supports USB devices.

## Raspberry Pi Zero W Setup

To setup the Raspberry Pi Zero W to act as a USB device, follow the
guide found at https://www.aidanwoods.com/blog/building-a-wifi-enabled-usb-rubber-ducky/,
with its [corresponding repo](https://github.com/aidantwoods/RPi0w-keyboard).
In particular, [this issue](https://github.com/aidantwoods/RPi0w-keyboard/issues/1)
contains a necessary workaround.

HID Synergy requires three USB devices, a mouse, a keyboard, and a
digitzer (for absolute mouse functionality), so use
[this repos hid.sh] instead of the one from the tutorial.

## Usage

After compiling Synergy on the Raspberry Pi Zero W, there is a single
new option for use with the client:

```[--hid <mouse> <keyboard> <digitizer> <width> height>]```

The mouse, keyboard and digitzer arguments correspond to the HID file
path for each. For the `hid.sh` above, these should be `/dev/hidg0`,
`/dev/hidg1` and `/dev/hidg2` in order.

The width and height arguments describe the width and height of the
desired client screen. Modifying these values while maintaining the
same aspect ratio will change how quickly the mouse will move on the
client device.

## Licenses/Contributors etc. 

This project is based on:

Alex Vanyo - https://github.com/alexvanyo/hid-synergy
Johannes Berg - https://git.sipsolutions.net/usbhid-synergy.git/

Thank you both. 



