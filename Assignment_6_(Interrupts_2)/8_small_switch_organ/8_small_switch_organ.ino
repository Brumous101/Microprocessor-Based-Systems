void setup() 
{
  Serial.begin(9600);
  
  //LEDS 0-7
  //Speaker 0
  pinMode(0, OUTPUT);
  
  //Switches
  pinMode(14, INPUT_PULLUP);//Switch 0
  pinMode(15, INPUT_PULLUP);//Change to "INPUT_PULLUP"
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  //We want 4 different interrupts because you would want to be able to play chords
  attachInterrupt(digitalPinToInterrupt(14), aNote, HIGH);
  attachInterrupt(digitalPinToInterrupt(15), bNote, HIGH);
  attachInterrupt(digitalPinToInterrupt(16), cNote, HIGH);
  attachInterrupt(digitalPinToInterrupt(17), dNote, HIGH);
  Serial.println("Ready");
}
volatile byte state = LOW;

void loop()
{
  
}
void aNote()
{
  if(digitalRead(14) == HIGH)
  {
    state = !state;
    digitalWrite(0,state);
    delayMicroseconds(500);
  }
}
void bNote()
{
  if(digitalRead(15) == HIGH)
  {
    state = !state;
    digitalWrite(0,state);
    delayMicroseconds(1000);
  }
}
void cNote()
{
  if(digitalRead(16) == HIGH)
  {
    state = !state;
    digitalWrite(0,state);
    delayMicroseconds(1500);
  }
}
void dNote()
{
  if(digitalRead(17) == HIGH)
  {
    state = !state;
    digitalWrite(0,state);
    delayMicroseconds(2000);
  }
}
