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
void loop() 
{
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(i, LOW);
  }
  if(digitalRead(14) == HIGH && digitalRead(15) == LOW && digitalRead(16) == LOW)
  {
      digitalWrite(0, HIGH);
      Serial.println("The front door is open.");
      delay(200);
      digitalWrite(0, LOW);
  }   
  if(digitalRead(14) == LOW && digitalRead(15) == HIGH && digitalRead(16) == LOW)
  {
      digitalWrite(1, HIGH);
      Serial.println("Your mailbox is open.");
      delay(200);
      digitalWrite(1, LOW);
  }
  if(digitalRead(14) == LOW && digitalRead(15) == LOW && digitalRead(16) == HIGH)
  {
      digitalWrite(2, HIGH);
      Serial.println("The smoke alarm is on.");
      delay(200);
      digitalWrite(2, LOW);
  }
  if(digitalRead(14) == HIGH && digitalRead(15) == HIGH && digitalRead(16) == LOW)
  {
    digitalWrite(0, HIGH);
    Serial.println("The front door is open and your mailbox is open.");
    delay(200);
    digitalWrite(0, LOW);
  }
  if(digitalRead(14) == HIGH  && digitalRead(15) == LOW && digitalRead(16) == HIGH)
  {
    digitalWrite(0, HIGH);
    Serial.println("The front door is open and the smoke alarm is on.");
    delay(200);
    digitalWrite(0, LOW);
  }
  if(digitalRead(14) == LOW  &&digitalRead(15) == HIGH && digitalRead(16) == HIGH)
  {
    digitalWrite(0, HIGH);
    Serial.println("Your mailbox is open and the smoke alarm is on.");
    delay(200);
    digitalWrite(0, LOW);
  }
  if(digitalRead(14) == HIGH && digitalRead(15) == HIGH && digitalRead(16) == HIGH)
  {
    digitalWrite(0, HIGH);
    Serial.println("The front door is open, your mailbox is open, and the smoke alarm is on.");
    delay(200);
    digitalWrite(0, LOW);
  }
}
