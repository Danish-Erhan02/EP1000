int buttonState = 0;
const int RED = 13;
const int YELLOW = 12;
const int GREEN = 11;
void setup()
{
  pinMode(7, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{
  // read the state of the push button
  buttonState = digitalRead(7);
  // check if the push button is pressed
  if (buttonState == HIGH) {
    delay(2000);
    digitalWrite(GREEN, LOW);
    delay (500);
    digitalWrite(YELLOW, HIGH);
    delay(1000);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    delay (8500);
    digitalWrite(RED, LOW);
   
    
  } else {
    digitalWrite(GREEN, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
