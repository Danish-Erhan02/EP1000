const int PB=2;
const int R=6;
const int Y=7;
const int W=8;

unsigned long prevT=0;  // last checked time
unsigned long interval=500;
int state=0;  // state 0 at start

void setup() {
  // put your setup code here, to run once:
  pinMode(PB, INPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(W, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PB) == LOW){  // button pressed
    delay(25);  // for switch debounce
    while (digitalRead(PB) == LOW); // wait for key release
    prevT = millis();   // prevT = current time
    state++; // go to next state
    if (state == 5) // states 0, 1, 2, 3, 4 only, reset after 4
      state = 0;
  }

  // introduce delay
  while (millis() - prevT < interval);  // wait for interval before proceeding
  
  // take action based on current state
  switch (state){
    case 0: // turn off all LEDs
    delay(3000);
      digitalWrite(R, LOW);
      digitalWrite(Y, LOW);
      digitalWrite(W, LOW);
      break;
    case 1: // turn on red LED
      digitalWrite(R, HIGH);
      break;
    case 2: // turn on yellow LED
      digitalWrite(R, LOW);
      digitalWrite(Y, HIGH);
      break;
    case 3: // turn on white LED
      digitalWrite(Y, LOW);
      digitalWrite(W, HIGH);
      break;
    case 4: // turn on 3 LEDs
      digitalWrite(R, HIGH);
      digitalWrite(Y, HIGH);
      break;
  }
}
