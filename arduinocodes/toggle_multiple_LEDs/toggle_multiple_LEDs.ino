// toggle_nodebounce.ino
// toggle LED with switch without debouncing

const int SW = 4;
const int WHITE = 10;
const int GREEN = 9;
const int YELLOW = 8;

int state = 0;          // we start at state 0
int RSTATE = LOW;      // original state of the LEDs
int GSTATE = LOW;
int YSTATE = LOW; 


// variables used for timing
long timeOfLastDebounce = 0;      // holds last reading of millis()
long debounceTime = 250;          // debounceTime

void setup() {
  pinMode(SW, INPUT_PULLUP);      // using internal pullup
  pinMode(WHITE,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
}

void loop() {
   int reading = digitalRead(SW);    // read the switch
   unsigned long currentTime = millis(); // make currentTime millis()

    if (reading == LOW){
      
       if ( (currentTime - timeOfLastDebounce) > debounceTime){
        state++;
        timeOfLastDebounce = currentTime;
        }
        
     }


switch(state){
  case 1:
        digitalWrite(WHITE,HIGH);
        break;
  case 2:
        digitalWrite(WHITE,LOW);
        break;
  case 3:
        digitalWrite(GREEN,HIGH);
        break;
  case 4:
        digitalWrite(GREEN,LOW);
        break;
  case 5:
        digitalWrite(YELLOW,HIGH);
        break;
  case 6:
        digitalWrite(YELLOW,LOW);
        break;
  case 7:
        digitalWrite(WHITE,HIGH);
        digitalWrite(GREEN,HIGH );
        digitalWrite(YELLOW,HIGH);
        break;
  case 8:
        digitalWrite(WHITE,LOW);
        digitalWrite(GREEN,LOW );
        digitalWrite(YELLOW,LOW);
        state = 0;
        break;

  }

     
}
