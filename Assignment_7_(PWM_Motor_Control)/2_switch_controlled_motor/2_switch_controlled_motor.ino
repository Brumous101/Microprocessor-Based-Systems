void setup() 
{
  Serial.begin(9600);
  
  //LEDS 0-7
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT); 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //Motor on this
  pinMode(23, OUTPUT);
  
  //Switches
  pinMode(14, INPUT_PULLUP);//Switch 0
  pinMode(15, INPUT_PULLUP);//Switch 1
  pinMode(16, INPUT_PULLUP);//Switch 2
  pinMode(17, INPUT_PULLUP);//Switch 3
  
  attachInterrupt(digitalPinToInterrupt(14), startMotor, RISING);
  attachInterrupt(digitalPinToInterrupt(15), stopMotor, RISING);
  attachInterrupt(digitalPinToInterrupt(16), maxPower, RISING);
  attachInterrupt(digitalPinToInterrupt(17), minimumPower, RISING);
  
  Serial.println("Ready");
}

//volatile byte state = LOW;
bool flag = false;
bool maxToMinFlag = false;
//unsigned long val = 11000;//stops at 10500

void loop()
{
  
}
void startMotor()
{
    flag = true;
    analogWrite(0,255);
    analogWrite(1,0);
}
void stopMotor()
{
    flag = false;
    maxToMinFlag = false;
    analogWrite(23,0);
    
    analogWrite(0,0);
    analogWrite(1,255);
    analogWrite(2,0);
    analogWrite(3,0);
}
void maxPower()
{
  if(flag == true)
  {
    if(maxToMinFlag == false)
    {
      analogWrite(3, 0);
      analogWrite(2, 255);
      maxToMinFlag = true;
      analogWrite(23, 255);
    }
  }
}
void minimumPower()
{
  if(flag == true)
  {
    if(maxToMinFlag == true)
    {
      analogWrite(2, 0);
      analogWrite(3,255);
      
      for(int i = 255; i > 230; i--)
      {
        analogWrite(23,i);
        delayMicroseconds(500000);
      }
      
      analogWrite(3,0);
      maxToMinFlag = false;
    }
  }
}
