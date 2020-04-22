// Create an IntervalTimer object 
IntervalTimer myTimer1;
IntervalTimer myTimer2;
IntervalTimer myTimer3;
IntervalTimer myTimer4;


void setup() 
{
  Serial.begin(9600);
  myTimer1.begin(blinkLED1,  500000);  // blinkLED to run every 0.5 seconds
  myTimer2.begin(blinkLED2, 1000000);  // blinkLED to run every 1 seconds
  myTimer3.begin(blinkLED3, 5000000);  // blinkLED to run every 5 seconds
  myTimer4.begin(blinkLED4, 10000000);  // blinkLED to run every 10 seconds
  
  //LEDS 0-7
  //Speaker 0
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

// The interrupt will blink the LED, and keep
// track of how many times it has blinked.
int ledState1 = LOW;
int ledState2 = LOW;
int ledState3 = LOW;
int ledState4 = LOW;
volatile unsigned long blinkCount = 0; // use volatile for shared variables

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

void blinkLED2() 
{
  if (ledState2 == LOW) 
  {
    ledState2 = HIGH;
  } 
  else 
  {
    ledState2 = LOW;
  }
  digitalWrite(1, ledState2);
}
void blinkLED3() 
{
  if (ledState3 == LOW) 
  {
    ledState3 = HIGH;
  } 
  else 
  {
    ledState3 = LOW;
  }
  digitalWrite(2, ledState3);
}
void blinkLED4() 
{
  if (ledState4 == LOW) 
  {
    ledState4 = HIGH;
  } 
  else 
  {
    ledState4 = LOW;
  }
  digitalWrite(3, ledState4);
}

void loop() 
{
  delay(100);
}
