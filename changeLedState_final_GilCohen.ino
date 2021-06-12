#define BlueLedPin 6
#define RedLedPin 11
#define GreenLedPin 10
#define YelloLedPin 9

#define BlueBtnPin 3
#define RedBtnPin 12
#define YellowBtnPin 2
#define GreenBtnPin 4

#define BTN_NUM 4
int btns[BTN_NUM]= {BlueBtnPin,RedBtnPin,YellowBtnPin,GreenBtnPin};
int leds[BTN_NUM]= {BlueLedPin,RedLedPin,YelloLedPin,GreenLedPin};

void setup() {
  for(int k = 0 ; k < BTN_NUM ; k++){ 
    pinMode(btns[k], INPUT_PULLUP);
    pinMode(leds[k], OUTPUT);
    digitalWrite(leds[k], LOW);
  }
}

void loop() {
  for(int k = 0; k<BTN_NUM ; k++){
    if(digitalRead(leds[k])== LOW && digitalRead(btns[k]) == LOW){
      digitalWrite(leds[k],HIGH);
      while(digitalRead(btns[k])== LOW);
    } 
    delay(1);  
                         
    if(digitalRead(leds[k])== HIGH && digitalRead(btns[k]) == LOW){
      digitalWrite(leds[k],LOW);
      while(digitalRead(btns[k])== LOW);
    }
    delay(1);
  }
}

/*-----WORKS WITH NO BUGS-----
* the 'while': after the led is 'on' and the button is pushed - do nothing!
** the 'delay': so the led won't turn off immediately when it goes to the second 'if'. 
(it does'nt effects any led blinking or waiting the next state)
*** the 'while' and the 'delay' keeps the led ON without any other interference when the button is pressed.
*/
