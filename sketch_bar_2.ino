// Define the number of LEDs in the bar
const int numLEDs = 8;  // We have 8 LEDs
int ledPins[numLEDs] = {16, 17, 18, 19, 21, 22, 26, 27};  // Pin numbers for LEDs

void setup() {
  Serial.begin(9600); 
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);  // Set each LED pin as an OUTPUT
  }
}

void blinka_port(int port) {
  digitalWrite(port, HIGH);  // Turn the LED on (HIGH is the voltage level)
  delay(1000);               
  digitalWrite(port, LOW);   // Turn the LED off by making the voltage LOW
  delay(1000);
}

void displayBinary(int number) {
  Serial.print("Displaying: ");
  Serial.println(number, BIN);  // Print the number in binary form

  for (int i = 0; i < numLEDs; i++) {
    if (number & (1 << i)) {
      digitalWrite(ledPins[i], HIGH);  
    } else {
      digitalWrite(ledPins[i], LOW);   
    }
  }
}

void loop() {
  // Loop through numbers 1 to 256
  for (int i = 1; i <= 256; i++) {
    displayBinary(i); 
    blinka_port(ledPins[0]); 
    delay(1000); 
  }
}
