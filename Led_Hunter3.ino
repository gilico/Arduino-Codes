#define BlueLed 6
#define RedLed 11
#define GreenLed 10
#define YellowLed 9
#define offLed 7

#define joyX A5
#define joyY A6

#define Arr_size 3
int i;
int k;
int valX = 0;
int valY = 0;
int ledsX[Arr_size]= {RedLed, GreenLed, offLed};
int ledsY[Arr_size]= {BlueLed, YellowLed, offLed};
bool isLedXOff[Arr_size] = {false, false , false};
bool isLedYOff[Arr_size] = {false, false, false};

int roundCnt = 0;
int turnOffHighVal = 70;
int turnOffLowVal = 30;

void setup() {
  Serial.begin(9600);
  for(int k = 0 ; k < Arr_size ; k++){ 
    pinMode(ledsX[k], OUTPUT);
    digitalWrite(ledsX[k], LOW);
    pinMode(ledsY[k], OUTPUT);
    digitalWrite(ledsY[k], LOW);
  }
}

void loop() {
  while(roundCnt < 10){
    randomSeed(analogRead(A1));
    i = random(0, 3);
    if(i == 2){
      k = random(0, 2);
    }else{
      k = random(0, 3);
    }
  
    digitalWrite(ledsX[i], HIGH);
    digitalWrite(ledsY[k], HIGH);

    while(!isLedXOff[i]){
      moveJoyXFun();
      checkXFun();
    }
  
    while(!isLedYOff[i]){
      moveJoyYFun();
      checkYFun();
    }
    
    roundCnt++;
    Serial.println(roundCnt);
    isLedXOff[i] = false;
    isLedYOff[i] = false;
    delay(1000);
  }
}


int moveJoyXFun(){
  int moveX = analogRead(joyX);
  valX = map(moveX, 0, 1023, 1, 100);
  return valX;
}


int moveJoyYFun(){
  int moveY = analogRead(joyY);
  valY = map(moveY, 0, 1023, 100, 1);
  return valY;
}


bool checkXFun(){
  int RedLedVal = digitalRead(RedLed);
  int GreenLedVal = digitalRead(GreenLed);
  
  if(RedLedVal == HIGH){
    if(valX > turnOffHighVal){
      digitalWrite(RedLed, LOW);
      isLedXOff[i] = true;
    }
  }else if(GreenLedVal == HIGH){
    if(valX < turnOffLowVal){
      digitalWrite(GreenLed, LOW);
      isLedXOff[i] = true;
    }
  }else  if(i == 2){
    isLedXOff[i] = true;
  }
  
  return isLedXOff[i];
}



bool checkYFun(){
  int BlueLedVal = digitalRead(BlueLed);
  int YellowLedVal = digitalRead(YellowLed);
  
  if(BlueLedVal == HIGH){
    if(valY > turnOffHighVal){
      digitalWrite(BlueLed, LOW);
      isLedYOff[i] = true;
    }
  }else if(YellowLedVal == HIGH){
    if(valY < turnOffLowVal){
      digitalWrite(YellowLed, LOW);
      isLedYOff[i] = true;
    }
  }else if(k == 2){
    isLedYOff[i] = true;
  }  

  return isLedYOff[i];
}
