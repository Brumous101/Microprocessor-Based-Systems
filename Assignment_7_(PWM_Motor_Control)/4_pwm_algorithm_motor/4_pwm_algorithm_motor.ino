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
  attachInterrupt(digitalPinToInterrupt(16), startPower, RISING);
  attachInterrupt(digitalPinToInterrupt(17), increasePower, RISING);
  
  Serial.println("Ready");
}

//volatile byte state = LOW;
bool flag = false;
bool ableToIncreaseFlag = false;
volatile unsigned long timeSinceLastDebounce = 0;
volatile unsigned long delayOfDebounce = 200;
int current = 245;
int counter =0;

void loop()
{
  
}
void startMotor()
{
    flag = true;
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2, LOW);
    counter = 0;
}
void stopMotor()
{
    flag = false;
    ableToIncreaseFlag = false;
    analogWrite(23,0);
    
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    counter = 0;
}
void startPower()
{
  if(flag == true)
  {
    if(ableToIncreaseFlag == false)
    {
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);
      ableToIncreaseFlag = true;
      analogWrite(23, 245);
    }
  }
}

void increasePower()
{
  if(flag == true)
  {
    if(ableToIncreaseFlag == true)
    {
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);// turned on

      if(digitalRead(17) == HIGH && ( (millis() - timeSinceLastDebounce) > delayOfDebounce))
      {
        timeSinceLastDebounce = millis();
        
        if(counter < 10)
        {
          current = current + 1;
          analogWrite(23,current);
          counter++;
          digitalWrite(5, HIGH);
        }
        else if(counter == 10)
        {
          digitalWrite(6, HIGH);//max power! 100% duty
        }
        else// counter > 10
        {
          digitalWrite(7, HIGH);//Broken
        }
      }
    }
  }
}
