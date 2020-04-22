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
  char character = 122;
  
  while(character >= 'a')
  {
    if(digitalRead(14) == HIGH)
    {
        digitalWrite(0, HIGH);
        Serial.println(character);
        character--;
        delay(800);
        digitalWrite(0, LOW);
    }   
    if(digitalRead(15) == HIGH)
    {
        digitalWrite(1, HIGH);
        Serial.println(character);
        character--;
        delay(600);
        digitalWrite(1, LOW);
    }
    if(digitalRead(16) == HIGH)
    {
        digitalWrite(2, HIGH);
        Serial.println(character);
        character--;
        delay(400);
        digitalWrite(2, LOW);
    }
    if(digitalRead(17) == HIGH)
    {
        digitalWrite(3, HIGH);
        Serial.println(character);
        character--;
        delay(200);
        digitalWrite(3, LOW);
    }
  }
}
