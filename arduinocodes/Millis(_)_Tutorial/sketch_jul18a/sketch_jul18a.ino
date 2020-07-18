
const unsigned long eventInterval=3000; // delay between currentTime and previousTime
unsigned long previousTime=0;

void setup() {
  Serial.begin(9600); //initialize Serial moniter
}


void loop() {
unsigned long currentTime = millis(); // make currentTime millis()

if (currentTime - previousTime >= eventInterval){ // if currentTime - previousTime >= 1000
  Serial.println("Skrrr Skrrr Pew"); // Print out messsege on serial monitor 
  previousTime = currentTime; // Updates  previousTime with currentTime
}

}
