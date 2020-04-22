void setup() 
{
  Serial.begin(9600);
  
  //LEDS 0-7
  //Speaker 0
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  //Switches
  pinMode(14, INPUT_PULLUP);//Switch 0
  pinMode(15, INPUT_PULLUP);//Change to "INPUT_PULLUP"
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(14), blink, RISING);
  attachInterrupt(digitalPinToInterrupt(15), timesPressed, RISING);
  Serial.println("Ready");
}

volatile byte state = LOW;
volatile unsigned int blinkCount = 0;
volatile unsigned long timeSinceLastDebounce =0;
volatile unsigned long delayOfDebounce =1000;//How long of holding a switch down before it counts as a second debounce
bool flag = false;

void loop() 
{
  unsigned int blinkCopy = 0;
  noInterrupts();
  blinkCopy = blinkCount;
  interrupts();

  if(flag == true)
  {
    Serial.print("blinkCount = ");
    Serial.println(blinkCopy);
    for(unsigned int i =0; i < blinkCopy; i++)
    {
      digitalWrite(7, HIGH);
      delayMicroseconds(500000);
      digitalWrite(7, LOW);
      delayMicroseconds(500000);
    }
    flag = false;
    noInterrupts();
    blinkCount = 0;
    blinkCopy = blinkCount;
    interrupts();
  }
}

void blink() 
{
  if( (millis() - timeSinceLastDebounce) > delayOfDebounce)
  {
    timeSinceLastDebounce = millis();
    state = !state;  
    digitalWrite(0, state);
    blinkCount++;
  }
}

void timesPressed()
{
  flag = true;
}
