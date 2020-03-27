void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}
    
void loop() {
  for(int i= 0; i < 8; i++)
  {
    for(int j = 0; j< i; j++)
    {
      digitalWrite(j, LOW);
    }
    digitalWrite(i, HIGH);
    delay(1000);
  }
  
  for(int i= 6; i > 0; i--)
  {
    for(int j = 7; j> i; j--)
    {
      digitalWrite(j, LOW);
    }
    digitalWrite(i, HIGH);
    delay(1000);
  }
  digitalWrite(1, LOW);
}
