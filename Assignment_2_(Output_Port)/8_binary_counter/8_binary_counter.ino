void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {
  int leftOver;
  
  for(int i = 0; i < 256; i++)
  {
    leftOver = i;
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(100);
    
    if(leftOver >= 128)
    {
      leftOver = leftOver - 128;
      digitalWrite(7, HIGH);
    }
    if(leftOver >= 64)
    {
      leftOver = leftOver - 64;
      digitalWrite(6, HIGH);
    }
    if(leftOver >= 32)
    {
      leftOver = leftOver - 32;
      digitalWrite(5, HIGH);
    }
    if(leftOver >= 16)
    {
      leftOver = leftOver - 16;
      digitalWrite(4, HIGH);
    }
    if(leftOver >= 8)
    {
      leftOver = leftOver - 8;
      digitalWrite(3, HIGH);
    }
    if(leftOver >= 4)
    {
      leftOver = leftOver - 4;
      digitalWrite(2, HIGH);
    }
    if(leftOver >= 2)
    {
      leftOver = leftOver - 2;
      digitalWrite(1, HIGH);
    }
    if(leftOver >= 1)
    {
      leftOver = leftOver - 1;
      digitalWrite(0, HIGH);
    }
    delay(400);
  }
    
}
