// Create an IntervalTimer object 
IntervalTimer myTimer1;


void setup() 
{
  Serial.begin(9600);
  myTimer1.begin(blinkLED1,  0003030);  // blinkLED at 330Hz
  
  //LED 0
  //Speaker 0
  pinMode(0, OUTPUT);
}

// The interrupt will blink the LED, and keep
// track of how many times it has blinked.
int ledState1 = LOW;

// functions called by IntervalTimer should be short, run as quickly as
// possible, and should avoid calling other functions if possible.
void blinkLED1() 
{
  if (ledState1 == LOW) 
  {
    ledState1 = HIGH;
  } 
  else 
  {
    ledState1 = LOW;
  }
  digitalWrite(0, ledState1);
}


void loop() 
{
  delay(100);
}
