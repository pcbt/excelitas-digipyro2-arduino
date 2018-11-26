//#include <MemoryFree.h>;
//#include <pgmStrToRAM.h>; // not needed for new way. but good to have for reference.

//serial pin Uno 2, atmega2560 board 12
//dl pin Uno 13, atmega2560 board 53

#define SERIAL 12
#define DL 53
#define LED 25


void writeregval(int pin1,unsigned long regval){
  int i;
  int _pin1=pin1;
  unsigned long _regval=regval;
  unsigned char nextbit;
  unsigned long regmask = 0x1000000;
  pinMode(_pin1,OUTPUT);
  digitalWrite(_pin1,LOW);
  for(i=0;i < 25;i++){
    nextbit = (_regval&regmask)!=0;
    regmask >>=1;
    digitalWrite(_pin1,LOW);
    digitalWrite(_pin1,HIGH);
    
    if(nextbit){
      digitalWrite(_pin1,HIGH);
      Serial.print("1");}
    else{
      digitalWrite(_pin1,LOW);
      Serial.print("0");}
    _delay_us(100);
  }
  Serial.print("\ndone\n");
  digitalWrite(_pin1,LOW);
  _delay_us(600);
}

void setup() {
  Serial.begin(115200);
   pinMode(SERIAL,OUTPUT);
   pinMode(DL,INPUT);
   pinMode(LED,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int i=1;
   if(i){
           Serial.println("Writing to register");
           _delay_ms(1000);
           writeregval(SERIAL,0x00304D10);
           i=0;
        }
        while(1){
          int movement = digitalRead(DL);
          if(movement){
            Serial.println(movement);
            Serial.println("movement");
            //Serial.println(getPSTR("Old way to force String to Flash"));
            //Serial.println(F("New way to force String to Flash"));
            //Serial.println(F("Free RAM = "));
            //Serial.println(freeMemory(), DEC);  // print how much RAM is available.
            pinMode(DL,OUTPUT);
            digitalWrite(DL,LOW);
            digitalWrite(LED,HIGH);
            _delay_ms(2000);
            pinMode(DL,INPUT);
            digitalWrite(LED,LOW);
            
            
            }
        }
}

