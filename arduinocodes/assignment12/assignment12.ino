


const int PB = 2; 
const int RED = 6;
const int GREEN = 7;
const int WHITE = 8;
int led = 5;
int newled = 0;


void setup()
{
  // init PB as input
  pinMode(PB, INPUT);
  // init serial port
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(WHITE, OUTPUT);
}

void loop()
{
    if (digitalRead(PB) == LOW){  // key pressed
  newled = led++;
      
    }
  
    if (newled == 6)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(WHITE, LOW);
    delay (500);
        
  }
 if (newled == 7)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(WHITE, LOW);
   delay (500);
     
  }
 if (newled == 8)
  {
  
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(WHITE, HIGH);
   delay (500);
      
  } 
 if (newled == 9)
  {
  
  
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(WHITE, HIGH);
   delay (500);
   
  } 
  
  if (newled == 10)
  {
    delay (3000);
  
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(WHITE, LOW);
   delay (500);
   newled = 0;
   
  } 
  
}
