void setup()
{ 
  Serial.begin(9600);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //Switches
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  Serial.println("Ready");
}
int frequencyCounter1 = 0, frequencyCounter2 = 0;
void loop() 
{
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    frequencyCounter1++;
    if(frequencyCounter1 == 8)
    {
      if(digitalRead(4) == LOW)
      {
          digitalWrite(4, HIGH);
      }
      else
      {
          digitalWrite(4, LOW);
      }
      frequencyCounter1 = 0;
    }
    frequencyCounter2++;
    if(frequencyCounter2 == 12)
    {
      if(digitalRead(5) == LOW)
      {
          digitalWrite(5, HIGH);
      }
      else
      {
          digitalWrite(5, LOW);
      }
      frequencyCounter2 = 0;
    }     
    delay(5);
}
