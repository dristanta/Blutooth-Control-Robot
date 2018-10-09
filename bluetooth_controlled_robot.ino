#define m11 3    // rear motor
#define m12 4
#define m21 13   // front motor
#define m22 7
char str[2],i;
void right()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}
void left()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}
void backward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   delay(100);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}
void forward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   delay(100);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
}
void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}
void setup() 
{
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}
void loop() 
{
  while(Serial.available())
  { 
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]== 4)
    {
     Serial.println("right");
     right();
     i=0;
    }
    else if(str[i-1]==1)
    {
     Serial.println("forward");
     forward();
     i=0;
    }
    else if(str[i-1]== 2)
    {
      Serial.println("backward");
      backward();
      i=0;
    }
    
    else if(str[i-1]==3)
    {
      Serial.println("left");
      left();
      i=0;
    }
    else if(str[i-1]==5)
    {
      Serial.println("stop");
      Stop();
      i=0;
    }
    delay(100);
  }
}
