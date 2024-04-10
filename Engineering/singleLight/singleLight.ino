// written by Austin Parah -- April 10, 2024
// your standard coppypasta:
// goal: "everything and nothing, nothing and everything" -- lincolin 2024
// nano FQBN: arduino:avr:nano 
// CMD: arduino-cli board attach -p /dev/ttyUSB0 -b arduino:avr:nano
// arduino-cli upload

const int LedPin = 3;
const int RedColorPin = 5;
const int BlueColorPin = 6;
const int GreenColorPin = 7; // will be using PWM so pin # important

void setColor(int RCV, int GCV, int BCV);
void smoothColortransition(int[] color1, int[] color2);

void setup(){
  pinMode(RedColorPin, OUTPUT);
  pinMode(BlueColorPin, OUTPUT);
  pinMode(GreenColorPin, OUTPUT);

  //smoothColortransition({0,0,0}, {255,255,255});
}

void loop(){
  delay(1000);

}

void smoothColortransition(int[] color1, int[] color2){
  while( color1[0]!=color2[0] && color1[1]!=color2[1] && color1[2]!=color2[2] ){
    color1[0] = color1[0] + pow(color1[0]-color2[0], 0); // get pos or neg change then step by 1(using ^0 on the result) 
    color1[1] = color1[1] + pow(color1[1]-color2[1], 0);
    color1[2] = color1[2] + pow(color1[2]-color2[2], 0);

    setColor(color1[0], color1[1], color1[2]);
  }
}

void setColor(int RCV, int GCV, int BCV){
  analogWrite(RedColorPin, RCV);
  analogWrite(BlueColorPin, BCV);
  analogWrite(GreenColorPin, GCV);
}

