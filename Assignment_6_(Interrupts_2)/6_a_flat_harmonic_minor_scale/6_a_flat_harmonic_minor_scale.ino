IntervalTimer myTimer1;
void setup() 
{
  Serial.begin(9600);
  pinMode(0, OUTPUT);
  myTimer1.begin(note, 4545);//220hz
}
volatile byte state = LOW;
volatile unsigned long durationOfNote = 1000;
volatile unsigned long timeCounter=0;
volatile unsigned int noteCounter = 0;

void loop() 
{
  
}

void note() 
{
  state = !state;
  digitalWrite(0, state);
  
    if( noteCounter == 0 && (millis() > timeCounter + durationOfNote) )
    {
      noteCounter++;
      delayMicroseconds(500000);
      timeCounter = timeCounter + durationOfNote + 500;//1.5 seconds 
      myTimer1.update(4290);   
    }
    if(noteCounter == 1 && millis() > timeCounter + durationOfNote)//greater than 2.5 seconds
    {
      myTimer1.update(3822);
      noteCounter++;
      delayMicroseconds(500000);
      timeCounter = timeCounter + durationOfNote + 500;//3 seconds    
    }
    if(noteCounter == 2 && millis() > timeCounter + durationOfNote)
    {
      myTimer1.update(3607);
      noteCounter++;
      delayMicroseconds(500000);
      timeCounter = timeCounter + durationOfNote + 500;//4.5 seconds  
    }
    if(noteCounter == 3 && millis() > timeCounter + durationOfNote)
    {
      myTimer1.update(3214);
      noteCounter++;
      delayMicroseconds(500000);
      timeCounter = timeCounter + durationOfNote + 500;//6 seconds  
    }
    if(noteCounter == 4 && millis() > timeCounter + durationOfNote)
    {
      myTimer1.update(2863);
      noteCounter++;
      delayMicroseconds(500000);
      timeCounter = timeCounter + durationOfNote + 500;//7.5 seconds  
    }
    if(noteCounter == 5 && millis() > timeCounter + durationOfNote)
    {
      myTimer1.update(2511);
      noteCounter++;
      delayMicroseconds(500000);
      timeCounter = timeCounter + durationOfNote + 500;//9 seconds  
    }
    if(noteCounter == 6 && millis() > timeCounter + durationOfNote)
    {
      myTimer1.update(2409);
      noteCounter++;
      delayMicroseconds(500000);
      timeCounter = timeCounter + durationOfNote + 500;//10.5 seconds  
    }
    if(noteCounter == 7 && millis() > timeCounter + durationOfNote)
    {
      myTimer1.update(2272);
      noteCounter = 0;
      delayMicroseconds(500000);
      timeCounter = timeCounter + durationOfNote + 500;//10.5 seconds  
    }
}
