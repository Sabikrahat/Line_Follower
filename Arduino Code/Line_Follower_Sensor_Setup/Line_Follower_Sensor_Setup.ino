int RSF = 5;    //right side motor rotate forward
int RSR = 6;    //right side motor rotate reverse

int LSF = 9;    //left side motor rotate forward
int LSR = 10;   //left side motor rotate reverse

int S1 = A0;    //IR sensor most right side
int S2 = A1;    //IR sensor 2nd most right side
int S3 = A2;    //IR sensor 2nd most left side
int S4 = A3;    //IR sensor most left side

int SF = 120;
int SHT = 200;
int SFT = 255;

int TD = 10;

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
  //Serial.print("Sensor most right side : ");
  Serial.print(digitalRead(S1));
  
 // Serial.print("Sensor 2nd most right side : ");
  Serial.print(digitalRead(S2));
  
//  Serial.print("Sensor 2nd most leftt side : ");
  Serial.print(digitalRead(S3));
  
 // Serial.print("Sensor most left side : ");
  Serial.println(digitalRead(S4));

 // Serial.println("\n\n\n\n");

  //delay(2000);
}
