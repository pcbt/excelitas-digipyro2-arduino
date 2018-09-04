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
  Serial.begin(9600);
   pinMode(2,OUTPUT);
   pinMode(13,INPUT);
   pinMode(12,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int i=1;
   if(i){
           Serial.println("Writing to register");
           _delay_ms(1000);
           writeregval(2,0x00304D10);
           i=0;
        }
        while(1){
          int movement = digitalRead(13);
          if(movement){
            Serial.println(movement);
            Serial.println("movement");
            pinMode(13,OUTPUT);
            digitalWrite(13,LOW);
            digitalWrite(12,HIGH);
            _delay_ms(2000);
            pinMode(13,INPUT);
            digitalWrite(12,LOW);
            
            
            }
        }
}

