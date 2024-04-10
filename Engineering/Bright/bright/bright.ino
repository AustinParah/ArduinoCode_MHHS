// written by Austin Parah, April 10, 2024
// goal: "everything and nothing, nothing and everything" -- lincolin 2024
// nano FQBN: arduino:avr:nano 
// Digital 2 - LED
// Aanalog 1 - potentiomiter

int LedPin = 5;
int poten = A3; // for arduino realated reasons if you want an analog pin you need to do A<number>

void setup(){
  pinMode(LedPin, OUTPUT);
  //pinMode(potentiomiter, INPUT);
}

int brightness;

void loop(){
  brightness = map(analogRead(poten), 0, 1023, 0, 255);
  analogWrite(LedPin, brightness); // works via PWM so you can do analog output on digital pins
}
