int RSF = 5;    //right side motor rotate forward
int RSR = 6;    //right side motor rotate reverse

int LSF = 9;    //left side motor rotate forward
int LSR = 10;   //left side motor rotate reverse

int S1 = A0;    //IR sensor most right side
int S2 = A1;    //IR sensor 2nd most right side
int S3 = A2;    //IR sensor 2nd most left side
int S4 = A3;    //IR sensor most left side

int SF = 140;
int SHT = 200;
int SFT = 255;
int SFB = 120;

int TD = 10;     
int TDT = 50;

void setup()
{
 pinMode(RSF, OUTPUT);
 pinMode(RSR, OUTPUT);
 
 pinMode(LSF, OUTPUT);
 pinMode(LSR, OUTPUT);
 
 pinMode(S1, INPUT);
 pinMode(S2, INPUT);
 pinMode(S3, INPUT);
 pinMode(S4, INPUT);

 Serial.begin(9600);

 delay(3000);
 
}

void loop()
{
  if((digitalRead(S1) == 0)&&(digitalRead(S2) == 0)&&(digitalRead(S3) == 0)&&(digitalRead(S4) == 0))
  {
    backward();
    Serial.println("Stop...");
  }

  else if((digitalRead(S1) == 0)&&(digitalRead(S2) == 1)&&(digitalRead(S3) == 1)&&(digitalRead(S4) == 0))
  {
    forward();
    Serial.println("Forward...");
  }

  else if((digitalRead(S1) == 0)&&(digitalRead(S2) == 1)&&(digitalRead(S3) == 1)&&(digitalRead(S4) == 1))
  {
    turnLeft90();
    Serial.println("Turning Left 90 degree angle...");
  }
  
  else if((digitalRead(S1) == 1)&&(digitalRead(S2) == 1)&&(digitalRead(S3) == 1)&&(digitalRead(S4) == 0))
  {
    turnRight90();
    Serial.println("Turning Right 90 degree angle...");
  }

  else if((digitalRead(S1) == 0)&&(digitalRead(S2) == 0)&&(digitalRead(S3) == 1)&&(digitalRead(S4) == 1))
  {
    turnLeft45();
    Serial.println("Turning Left 45 degree angle...");
  }
  
  else if((digitalRead(S1) == 1)&&(digitalRead(S2) == 1)&&(digitalRead(S3) == 0)&&(digitalRead(S4) == 0))
  {
    turnRight45();
    Serial.println("Turning Right 45 degree angle...");
  }

  else if((digitalRead(S1) == 0)&&(digitalRead(S2) == 0)&&(digitalRead(S3) == 0)&&(digitalRead(S4) == 1))
  {
    turnLeft45();
    Serial.println("Turning Left 45 degree angle...");
  }
  
  else if((digitalRead(S1) == 1)&&(digitalRead(S2) == 0)&&(digitalRead(S3) == 0)&&(digitalRead(S4) == 0))
  {
    turnRight45();
    Serial.println("Turning Right 45 degree angle...");
  }

  else if((digitalRead(S1) == 0)&&(digitalRead(S2) == 0)&&(digitalRead(S3) == 1)&&(digitalRead(S4) == 0))
  {
    forward();
    Serial.println("Forward...");
  }
  
  else if((digitalRead(S1) == 0)&&(digitalRead(S2) == 1)&&(digitalRead(S3) == 0)&&(digitalRead(S4) == 0))
  {
    forward();
    Serial.println("Forward...");
  }

  else if((digitalRead(S1) == 1)&&(digitalRead(S2) == 1)&&(digitalRead(S3) == 1)&&(digitalRead(S4) == 1))
  {
    forward();
    Serial.println("Forward...");
  }
}

void stop(){
 analogWrite(RSF, 0);
 analogWrite(RSR, 0);
 
 analogWrite(LSF, 0);
 analogWrite(LSR, 0);  
}

void forward(){
 analogWrite(RSF, SF);
 analogWrite(RSR, 0);
 
 analogWrite(LSF, SF);
 analogWrite(LSR, 0); 

 delay(TD);
}

void backward(){
 analogWrite(RSF, 0);
 analogWrite(RSR, SF);
 
 analogWrite(LSF, 0);
 analogWrite(LSR, SF); 
 
 delay(200);
}

void turnRight90(){
 analogWrite(RSF, 0);
 analogWrite(RSR, SFB);
 
 analogWrite(LSF, SFT);
 analogWrite(LSR, 0);
 
 delay(TDT);
}

void turnRight45(){
 analogWrite(RSF, 0);
 analogWrite(RSR, 0);
 
 analogWrite(LSF, SHT);
 analogWrite(LSR, 0); 
 
 delay(TD);
}

void turnLeft90(){
 analogWrite(RSF, SFT);
 analogWrite(RSR, 0);
 
 analogWrite(LSF, 0);
 analogWrite(LSR, SFB); 
 
 delay(TDT);
}

void turnLeft45(){
 analogWrite(RSF, SHT);
 analogWrite(RSR, 0);
 
 analogWrite(LSF, 0);
 analogWrite(LSR, 0); 
 
 delay(TD);
}
