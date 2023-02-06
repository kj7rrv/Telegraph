# Telegraph

Arduino library for automatically sending Morse code signals. Manual control,
speed adjustments, and use of active-on-low relays are supported.

## Usage

Check the example sketches, especially `Telegraph_Demo`, for more information.

## Setup

To create a `Telegraph` object, use the code:

    Telegraph telegraphName(pinNumber, speedInWordsPerMinute, HIGH);

(Use `LOW` instead of `HIGH` for an active-on-low relay. If you're using a
relay and aren't sure whether it's active-on-low or not, just try it with
`HIGH`; if your relay is active-on-low, keying will be opposite of what is
expected.)

## Sending messages

To send a message in Morse code, run this:

    telegraphName.send("MESSAGE");

The following characters can be used in messages:

    ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.,?'!/()&:;=+-_"$@

Lowercase letters are supported. Unsupported characters will not be
transmitted, but may cause gaps in timing.

## Adjusting speed

To change the transmission speed after creating the `Telegraph`, run:

    telegraphName.wpm = 25;

## Manual control

To manually turn the pin on and off, just use these commands:

    telegraphName.on();
    telegraphName.off();
