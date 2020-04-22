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
  if(digitalRead(14) == HIGH)
  {
    digitalWrite(0, HIGH);
    delay(200); 
  }   
  if(digitalRead(15) == HIGH)
  {
    digitalWrite(1, HIGH);
    delay(200); 
  }
  if(digitalRead(16) == HIGH)
  {
    digitalWrite(2, HIGH);
    delay(200); 
  }
  if(digitalRead(17) == HIGH)
  {
    digitalWrite(3, HIGH);
    delay(200); 
  }
}
