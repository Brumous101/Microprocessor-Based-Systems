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
  for(int i= 0; i < 4; i++)
  {
    int j =7;
    digitalWrite(i, HIGH);
    digitalWrite(j-i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
    digitalWrite(j-i, LOW);
  }  
  for(int i = 3; i >= 0; i--)
  {
    int j =7;
    digitalWrite(i, LOW);
    digitalWrite(i-1, HIGH);
    digitalWrite(j-i, LOW);
    digitalWrite(j-i+1, HIGH);
    delay(500);
  }
}
