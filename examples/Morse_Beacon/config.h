// Set this to your message in ALL CAPS, between double quotation marks ("..."). Supported characters:
// ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.,?'!/()&:;=+-_"$@
// If you use a double quote in your message, prefix it with a backslash \"like this.\"
// Unsupported characters will not be transmitted and may result in gaps in timing.
#define MESSAGE "KJ7RRV/B"

// Morse code speed in WPM
#define SPEED 18

// Pin to send on
#define PIN A0

// Change HIGH to LOW for an active-on-low relay
#define TX_ON HIGH

// Length of the unmodulated test carrier in milliseconds
#define TEST_LENGTH 15000

// Length of the pause between the test carrier and the identification in ms
#define AFTER_TEST_PAUSE 1000

// Length of the pause between cycles in ms
#define AFTER_ID 30000
