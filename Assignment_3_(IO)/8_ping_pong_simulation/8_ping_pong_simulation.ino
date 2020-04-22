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
int bounceCounter = 0;
int p1 = 0;
int p2 = 0;
int led;
bool game = true;
bool starting =true;

void loop() 
{
  //Start
  while(starting == true && p1 < 5 && p2 < 5)
  {
    int j = rand();
    starting = false;
    
    if(j <= (RAND_MAX / 2) )
    {
      for(led = 4; led <= 7; led++)
      {
        digitalWrite(led, HIGH);
        digitalWrite(led - 1, LOW);
        delay(500 - (bounceCounter * 50));
        delay(100);
        if(digitalRead(15) == LOW && led == 7)
        {
          Serial.println();
          Serial.print("MISS from p2");
          game = false;
          p1++;
          break;
        }
      }
      led =7;
    }
    
    if(j > (RAND_MAX / 2) )
    {
      for(led = 3; led >= 0; led--)
      {
        digitalWrite(led, HIGH);
        digitalWrite(led + 1, LOW);
        delay(500 - (bounceCounter * 50));
        delay(100);

        if(digitalRead(14) == LOW && led == 0)
        {
          Serial.println();
          Serial.print("MISS from p1");
          game = false;
          p2++;
          break;
        }
      }
      led = 0;
    }
  }
  
  
  while(starting == false && p1 < 5 && p2 < 5)
  {
    while(game == true)
    {
      if(led == 7)
      {
        for(int led = 7; led >= 0; led--)
        {
          digitalWrite(led, HIGH);
          digitalWrite(led + 1, LOW);
          
          if(bounceCounter < 10)
          {
              delay(500 - (bounceCounter * 50));
          }
          if(digitalRead(14) == HIGH && led == 0)
          {
            delay(100);
            bounceCounter++;
            Serial.println();
            Serial.print("HIT from p1");
          }
          if(digitalRead(14) == LOW && led == 0)
          {
            Serial.println();
            Serial.print("MISS from p1");
            game = false;
            p2++;
            break;
          }
          //Player incorrectly presses switch
          if(digitalRead(14) == HIGH && led > 0)
          {
            Serial.println();
            Serial.print("MISS from p1");
            game = false;
            p2++;
            break;
          }
          if(digitalRead(15) == HIGH && led < 7)
          {
            Serial.println();
            Serial.print("MISS from p2");
            game = false;
            p1++;
            break;
          }
        }
        if(game == false)
        {
          break;
        }
        led = 0;
      }
  
      if(led == 0)
      {
        for(int led = 0; led <= 7; led++)
        {
          digitalWrite(led, HIGH);
          digitalWrite(led - 1, LOW);
          
          if(bounceCounter < 10)
          {
              delay(500 - (bounceCounter * 50));
          }
          delay(100);
      
          if(digitalRead(15) == HIGH && led == 7)
          {
            delay(100);
            bounceCounter++;
            Serial.print("HIT from p2");
            Serial.println();
          }
          if(digitalRead(15) == HIGH && led == 7)
          {
            delay(100);
            bounceCounter++;
            Serial.println();
            Serial.print("HIT");
          }
          if(digitalRead(15) == LOW && led == 7)
          {
            Serial.println();
            Serial.print("MISS from p2");
            game = false;
            p1++;
            break;
          }
          //Player incorrectly presses switch
          if(digitalRead(14) == HIGH && led > 0)
          {
            Serial.println();
            Serial.print("MISS from p1");
            game = false;
            p2++;
            break;
          }
          if(digitalRead(15) == HIGH && led < 7)
          {
            Serial.println();
            Serial.print("MISS from p2");
            game = false;
            p1++;
            break;
          }
        }
        
        if(game == false)
        {
          break;
        }
        led = 7;
      }
      
    }
    Serial.println();
    Serial.println();
    Serial.println("Game Over");
    Serial.print("Player 1's score is: ");
    Serial.print(p1);
    Serial.println();
    Serial.print("Player 2's score is: ");
    Serial.print(p2);
    for(int led = 0; led <= 7; led++)
    {
      digitalWrite(led, LOW);
    }
    delay(5000);
    //New Round
    game = true;
    starting = true;
    bounceCounter = 0;
    
  
    if(p1 == 5)
    {
      for(int led = 0; led < 4; led++)
      {
        digitalWrite(led, HIGH);
      }
    }
    if(p2 == 5)
    {
      for(int led = 4; led < 8; led++)
      {
        digitalWrite(led, HIGH);
      }
    }
 
  }
}
