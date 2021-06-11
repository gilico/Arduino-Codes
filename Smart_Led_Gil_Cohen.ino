#define GreenLed 6
#define potzPin A0

#define RedBtn 12
#define YellowBtn 2
#define GreenBtn 4

#define ArrSize 3
int btns[ArrSize] = {GreenBtn, YellowBtn, RedBtn};
int ledVal = 0;
long interval = 0;

void setup() {
  Serial.begin(9600);
  pinMode(GreenLed, OUTPUT);
  digitalWrite(GreenLed, LOW);
  for(int i = 0; i < ArrSize; i++){
    pinMode(btns[i], INPUT_PULLUP);
  }
}

void loop() {
  if(analogRead(potzPin) > 400){
    analogWrite(GreenLed, LedValFun());   
    interval = AddToInterval();
    if((millis() >= interval) || digitalRead(RedBtn) == LOW) TurnOffLed();
  }else TurnOffLed();
}

int LedValFun(){
  if(digitalRead(GreenBtn) == LOW) ledVal = 255;
  if(digitalRead(YellowBtn) == LOW) ledVal = 255 / 4;
  
  return ledVal;
}

long AddToInterval(){
  if(digitalRead(GreenBtn) == LOW || digitalRead(YellowBtn) == LOW) 
    interval = millis() + 5000;
    
  return interval;
}

void TurnOffLed(){
  digitalWrite(GreenLed, LOW);
  ledVal = 0;
}
