const char charMsg[] = "www.instructables.com - DJ Sadeepa";
// Number of milliseconds to pause after message (0 = no pause):
unsigned const msgPauseTime = 2000;
// Controls the message scroll speed in ms (lower = faster):
const int scrollSpeed = 100;

// List of supported characters and index into corresponding character definitions array
const byte charSet[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&'()*+-,.~:;<>?@[]/\\=_";
// Character definitions (8 bytes per character)
const byte charDef[] = {
  0,0,0,0,0,0,0,0,                // Space symbol (must be the first character in this array)
  // Upper case letters:
  24,60,102,126,102,102,102,0,    // A
  124,102,102,124,102,102,124,0,  // B
  60,102,96,96,96,102,60,0,       // C
  120,108,102,102,102,108,120,0,  // D
  126,96,96,120,96,96,126,0,      // E
  126,96,96,120,96,96,96,0,       // F
  60,102,96,110,102,102,60,0,     // G
  102,102,102,126,102,102,102,0,  // H
  60,24,24,24,24,24,60,0,         // I
  30,12,12,12,12,108,56,0,        // J
  102,108,120,112,120,108,102,0,  // K
  96,96,96,96,96,96,126,0,        // L
  99,119,127,107,99,99,99,0,      // M
  102,118,126,126,110,102,102,0,  // N
  60,102,102,102,102,102,60,0,    // O
  124,102,102,124,96,96,96,0,     // P
  60,102,102,102,102,60,14,0,     // Q
  124,102,102,124,120,108,102,0,  // R
  60,102,96,60,6,102,60,0,        // S
  126,24,24,24,24,24,24,0,        // T
  102,102,102,102,102,102,60,0,   // U
  102,102,102,102,102,60,24,0,    // V
  99,99,99,107,127,119,99,0,      // W
  102,102,60,24,60,102,102,0,     // X
  102,102,102,60,24,24,24,0,      // Y
  126,6,12,24,48,96,126,0,        // Z
  // Lower case letters:
  0,0,60,6,62,102,62,0,           // a
  0,96,96,124,102,102,124,0,      // b
  0,0,60,96,96,96,60,0,           // c
  0,6,6,62,102,102,62,0,          // d
  0,0,60,102,126,96,60,0,         // e
  0,14,24,62,24,24,24,0,          // f
  0,0,62,102,102,62,6,124,        // g
  0,96,96,124,102,102,102,0,      // h
  0,24,0,56,24,24,60,0,           // i
  0,6,0,6,6,6,6,60,               // j
  0,96,96,108,120,108,102,0,      // k
  0,56,24,24,24,24,60,0,          // l
  0,0,102,127,127,107,99,0,       // m
  0,0,124,102,102,102,102,0,      // n
  0,0,60,102,102,102,60,0,        // o
  0,0,124,102,102,124,96,96,      // p
  0,0,62,102,102,62,6,6,          // q
  0,0,124,102,96,96,96,0,         // r
  0,0,62,96,60,6,124,0,           // s
  0,24,126,24,24,24,14,0,         // t
  0,0,102,102,102,102,62,0,       // u
  0,0,102,102,102,60,24,0,        // v
  0,0,99,107,127,62,54,0,         // w
  0,0,102,60,24,60,102,0,         // x
  0,0,102,102,102,62,12,120,      // y
  0,0,126,12,24,48,126,0,         // z
  // Numbers
  60,102,110,118,102,102,60,0,    // 0
  24,24,56,24,24,24,126,0,        // 1
  60,102,6,12,48,96,126,0,        // 2
  60,102,6,28,6,102,60,0,         // 3
  6,14,30,102,127,6,6,0,          // 4
  126,96,124,6,6,102,60,0,        // 5
  60,102,96,124,102,102,60,0,     // 6
  126,102,12,24,24,24,24,0,       // 7
  60,102,102,60,102,102,60,0,     // 8
  60,102,102,62,6,102,60,0,       // 9
  // Characters and symbols
  24,24,24,24,0,0,24,0,           // !
  102,102,255,102,255,102,102,0,  // #
  24,62,96,60,6,124,24,0,         // $
  98,102,12,24,48,102,70,0,       // %
  60,102,60,56,103,102,63,0,      // &
  6,12,24,0,0,0,0,0,              // '
  12,24,48,48,48,24,12,0,         // (
  48,24,12,12,12,24,48,0,         // )
  0,102,60,255,60,102,0,0,        // *
  0,24,24,126,24,24,0,0,          // +
  0,0,0,126,0,0,0,0,              // -
  0,0,0,0,0,24,24,48,             // ,
  0,0,0,0,0,24,24,0,              // .
  60,66,165,129,165,153,66,60,    // "Smiley face" replaces the tilde (~) character
  0,0,24,0,0,24,0,0,              // :
  0,0,24,0,0,24,24,48,            // ;
  14,24,48,96,48,24,14,0,         // <
  112,24,12,6,12,24,112,0,        // >
  60,102,6,12,24,0,24,0,          // ?
  60,102,110,110,96,98,60,0,      // @
  60,48,48,48,48,48,60,0,         // [
  60,12,12,12,12,12,60,0,         // ]
  0,3,6,12,24,48,96,0,            // /
  0,96,48,24,12,6,3,0,            // \
  0,0,126,0,126,0,0,0,            // =
  0,0,0,0,0,0,0,255               // _
};
const int colPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9};        // LED matrix columns are assigned to digital pins
const int clockPin = 10;          // Connects to 4017 decade counter clock pin 14
const int resetPin = 11;          // Connects to 4017 decade counter reset pin 15

unsigned long thisMs = 0;         // Elapsed time in ms that Arduino has been running
unsigned long lastMs;             // Interval since the message was last scrolled one column
unsigned long pauseStart;         // Elapsed time in ms since end-of-message pause was started
int msgIdx = 0;                   // Keeps track of the message character current being scrolled
byte charBuffer[16];              // Scroll "window" consists of portions of current and next character
int bufferIdx = 0;                // Keeps track of scrolling (after 8 columns, fetch next character)
boolean pauseDisplay = false;     // Determines when scrolling should be paused

void setup() {
  for (int i = 0; i < 8; i++)
    pinMode(colPins[i], OUTPUT);  // LED matrix columns are controlled by 8 digital pins
  pinMode(clockPin, OUTPUT);      // Clock pin on 4017 decade counter advances to the next row
  pinMode(resetPin, OUTPUT);      // Reset pin on 4017 decade counter is triggered after 8 rows
  initialize();                   // Prepare to start displaying banner message
}

void loop() {
  thisMs = millis();              // Get current time
  if (thisMs - lastMs > scrollSpeed) {  // Time to scroll yet?
    lastMs = thisMs;              // Yes, so save current time value
    if (pauseDisplay == true) {   // Don't scroll if we're at the end of the message
      if (thisMs - pauseStart > msgPauseTime)  // Has the pause time elapsed?
      initialize();               // Yes, so get ready to display the banner message again
    }
    else
      scrollDisplay();            // We're not at the end of the message, so scroll away!
  }
  // Activate the LED matrix pixels corresponding with matching bits in the respective rows 
  // and columns of the scroll buffer.  Boolean algebra is used to rotate the display 90
  // degrees to the right, to match the orientation with the orientation of the breadboard/pcb.
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++)
      if (charBuffer[7 - x] >> (7 - y) & 1)
        digitalWrite(colPins[x], HIGH);  // Activate LED momentarily
    for (int x = 0; x < 8; x++)
      digitalWrite(colPins[x], LOW);     // Turn off column LEDs before advancing to next row
    digitalWrite(clockPin, HIGH);        // Instruct the 4017 to advance to the next row
    digitalWrite(clockPin, LOW);         // on the LED matrix
  }
  digitalWrite(resetPin, HIGH);          // We're only using 8 of the 10 outputs, so start over
  digitalWrite(resetPin, LOW);           // after all rows have been scanned
}

void initialize() {
  // Prepare to start displaying banner message
    for (int i = 0; i < 8; i++)
      charBuffer[i] = 0;         // Clear scrolling buffer prior to displaying the message
    msgIdx = 0;                  // Reset pointer to first character in the message
    fetchChar();                 // Read first character in message and prepare to scroll it
    pauseDisplay = false;        // No need to pause, since we're starting over again
}

void fetchChar() {
  int foundVal = 0;
  // Check to see whether we've reached the end of the null-terminated message character string
  if (charMsg[msgIdx] == 0) {
    msgIdx = 0;
    pauseDisplay = true;
    pauseStart = thisMs;
  }
  // For each character in the message, make sure there is a matching character definition
  for (int i = 0; i < 89; i++)
    if (charMsg[msgIdx] == charSet[i])
      foundVal = i;
  msgIdx++;
  // Load the scroll buffer with the newly-found character (or blank, if none was found)
  for (int i = 0; i < 8; i++) {
    charBuffer[i + 8] = charDef[foundVal * 8 + i];
  }
}

void scrollDisplay() {
  // Scroll the current message character one column to the left
  for (int x = 0; x < 8; x++) {
    charBuffer[x] = charBuffer[x] << 1;
    if (charBuffer[x + 8] & 128)
      charBuffer[x] = charBuffer[x] | 1;
    charBuffer[x + 8] = charBuffer[x + 8] << 1;
  }
  // After 8 columns have been scrolled, fetch the next character
  bufferIdx++;
  if (bufferIdx > 7) {
    bufferIdx = 0;
    fetchChar();
  }
}

