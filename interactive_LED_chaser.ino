
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ledDelay;
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2;


void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPin[i], OUTPUT);
  } 
  changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potPin);
  if((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }  
}

void changeLED() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPin[i], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH);
  currentLED += direction;
  
  if (currentLED == 9) {direction = -1;}
  if (currentLED == 0) {direction = 1;}
}
