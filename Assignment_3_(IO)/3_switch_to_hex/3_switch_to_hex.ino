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
  int counter = 0;
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(i, LOW);
  }
  while(digitalRead(0) == LOW || digitalRead(1) == LOW || digitalRead(2) == LOW || digitalRead(3) == LOW)
  {
    if(digitalRead(14) == HIGH)
    {
      if(digitalRead(0) == LOW)
      {
        counter = counter + 1;
        digitalWrite(0, HIGH);
        Serial.println(counter, HEX);
      }
    }   
    if(digitalRead(15) == HIGH)
    {
      if(digitalRead(1) == LOW)
      {
        counter = counter + 2;
        digitalWrite(1, HIGH);
        Serial.println(counter, HEX);
      }
    }
    if(digitalRead(16) == HIGH)
    {
      if(digitalRead(2) == LOW)
      {
        counter = counter + 4;
        digitalWrite(2, HIGH);
        Serial.println(counter, HEX);
      }
    }
    if(digitalRead(17) == HIGH)
    {
      if(digitalRead(3) == LOW)
      {
        counter = counter + 8;
        digitalWrite(3, HIGH);
        Serial.println(counter, HEX);
      }
    }
    delay(200);
  }
}
