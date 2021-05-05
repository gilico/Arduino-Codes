#define BlueLed 6
#define RedLed 11
#define GreenLed 10
#define YellowLed 9
#define NoLed 50

#define joyX A5
#define joyY A6
#define Arr_size 5

int i;
int k;
int leds[Arr_size]=      {RedLed,   GreenLed,  NoLed,  BlueLed, YellowLed};
bool isLedOff[Arr_size] = {true,    true,    true,   true,    true};
bool isJoyValGood = false;

int roundCnt = 0;
int maxRound = 10;
int turnOffHighVal = 90;
int turnOffLowVal = 10;

void setup() {
  Serial.begin(9600);
  for(int j = 0 ; j < Arr_size ; j++){ 
    pinMode(leds[j], OUTPUT);
    digitalWrite(leds[j], LOW);
  }
}

void loop() {
  while(roundCnt < maxRound){
    randomSeed(analogRead(A1));
    i = random(0, 3);
    if(i == 2){
      k = random(3, 5);
    }else{
      k = random(2, 5);
    }
    digitalWrite(leds[i], HIGH);
    digitalWrite(leds[k], HIGH);
    isLedOff[i] = false;
    isLedOff[k] = false;
    
    while(!isLedOff[i] || !isLedOff[k]){
      checkXFun();
      checkYFun();
    }
    
    roundCnt++;
    Serial.println(roundCnt);
    delay(1000);
  }
}

bool checkXFun(){
  int moveX = analogRead(joyX);
  int valX = map(moveX, 0, 1023, 1, 100);
  isJoyValGood = false;
    
  if(!isLedOff[0] && valX > turnOffHighVal){
    isJoyValGood = true;
  }else if(!isLedOff[1] && valX < turnOffLowVal){
    isJoyValGood = true;
  }else  if(i == 2){
    isJoyValGood = true;;
  }
  
  if(isJoyValGood){
    digitalWrite(leds[i], LOW);
    isLedOff[i] = true;
  }
  isJoyValGood = false;
}

bool checkYFun(){
  int moveY = analogRead(joyY);
  int valY = map(moveY, 0, 1023, 100, 1);
  isJoyValGood = false;
    
  if(!isLedOff[3] && valY > turnOffHighVal){
    isJoyValGood = true;
  }else if(!isLedOff[4] && valY < turnOffLowVal){
    isJoyValGood = true;
  }else if(k == 2){
    isJoyValGood = true;
  }
  
  if(isJoyValGood){
    digitalWrite(leds[k], LOW);
    isLedOff[k] = true;
  }
  isJoyValGood = false;
}
