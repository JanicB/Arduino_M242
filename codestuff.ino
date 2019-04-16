// set button pin constants
const int BUTTON_PINS[] = {2, 3, 4, 5};

// set LED pin constants
const int LED_PINS[] = {13, 12, 11, 10};

// Secret code
const int code[] = {3, 1, 3, 1, 0};
// how many buttons were pressed in the correct order / at what position of the code we currently are
int solved = 0;

// current value of each button
// LOW = button isn't being pressed | HIGH = button is being pressed
boolean buttonsPressed[] = {LOW, LOW, LOW, LOW};

void setup() {
  for(int i = 0; i < 4; i++) {
    // initialize the LED pins as output
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
    // initialize the button pins as input
    pinMode(BUTTON_PINS[i], INPUT);
  }
}

void loop() {
  if(solved < 5) {
    for(int i = 0; i < 4; i++) {
      buttonToLight(i);
    }
  } else {
    for(int i = 0; i < 4; i++) {
      digitalWrite(LED_PINS[i], HIGH);
    }
  }
}

void buttonToLight(int index) {
  // button is being pressed and was previously not
  if (debounceButton(buttonsPressed[index], BUTTON_PINS[index]) == HIGH && buttonsPressed[index] == LOW) {
    // checks if the correct button was pressed
    if(index == code[solved]) {
      solved++;
    } else {
      solved = 0;
    }
    buttonsPressed[index] = HIGH;
    // turn LED on
    digitalWrite(LED_PINS[index], HIGH);
    
  } else if(debounceButton(buttonsPressed[index], BUTTON_PINS[index]) == LOW && buttonsPressed[index] == HIGH) {
    buttonsPressed[index] = LOW;
    // turn LED off
    digitalWrite(LED_PINS[index], LOW);
  }
}

// reads the buttonstate after a brief delay to avoid missreadings
boolean debounceButton(boolean state, int buttonPin) {
  boolean stateNow = digitalRead(buttonPin);
  if(state != stateNow) {
    delay(10);
    stateNow = digitalRead(buttonPin);
  }
  return stateNow;
}
