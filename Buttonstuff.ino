// set button pin constants
const int BUTTON_PINS[] = {2, 3, 4, 5};

// set LED pin constants
const int LED_PINS[] = {13, 12, 11, 10};

void setup() {
  for(int i = 0; i < 4; i++) {
    // initialize the LED pins as output
    pinMode(LED_PINS[i], OUTPUT);
    // initialize the button pins as input
    pinMode(BUTTON_PINS[i], INPUT);
  }
}

void loop() {
  for(int i = 0; i < 4; i++) {
    buttonToLight(BUTTON_PINS[i], LED_PINS[i]);
  }
}

void buttonToLight(int buttonPin, int ledPin) {
  // checks the state of the given button
  int buttonState = digitalRead(buttonPin);
  // HIGH => button is pressed
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
