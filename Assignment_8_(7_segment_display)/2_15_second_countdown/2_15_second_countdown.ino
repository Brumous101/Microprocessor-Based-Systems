IntervalTimer myTimer;
//right red
const int ledPin = LED_BUILTIN;  // the pin with a LED

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(14), startCountdown, RISING);
}


int ledState = LOW;
volatile unsigned long counter = 0; // use volatile for shared variables

void startCountdown()
{
  myTimer.begin(countdown, 1000);
}
void countdown() 
{
  if (counter == 0) 
  {
    //Make display "F"
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 1) 
  {
    //Make display "E"
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 2) 
  {
    //Make display "D"
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 3) 
  {
    //Make display "C"
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 4) 
  {
    //Make display "B"
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 5) 
  {
    //Make display "A"
    digitalWrite(0,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 6) 
  {
    //Make display "9"
    digitalWrite(0,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 7) 
  {
    //Make display "8"
    digitalWrite(0,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 8) 
  {
    //Make display "7"
    digitalWrite(0,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 9) 
  {
    //Make display "6"
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 10) 
  {
    //Make display "5"
    digitalWrite(0,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 11) 
  {
    //Make display "4"
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 12) 
  {
    //Make display "3"
    digitalWrite(0,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 13) 
  {
    //Make display "2"
    digitalWrite(0,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 14) 
  {
    //Make display "1"
    digitalWrite(0,LOW);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    counter++;
    delayMicroseconds(1000000);
  } 
  if (counter == 15) 
  {
    //Make display "0"
    digitalWrite(0,HIGH);
    digitalWrite(1,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
  } 
  counter = 0;
  delayMicroseconds(1000000);
}

void loop() 
{
}
