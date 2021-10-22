const int threshold = 25;  // 電流の許容範囲（抵抗と調整）

void setup()
{
  Serial.begin(9600);
    
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

  pinMode(4, OUTPUT);
  pinMode(5, INPUT);

  pinMode(6, OUTPUT);
  pinMode(7, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, INPUT);

  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
}

void loop()
{ 
    touch(3, 2, 1);
    touch(5, 4, 2);
    touch(7, 6, 3);
    touch(9, 8, 4);
    touch(11, 10, 5);
    touch(13, 12, 6);
}

void touch(int inputPin, int outputPin, int panelNumber)
{
  int t = 0;
  
  // パルスの立ち上げ
  digitalWrite(outputPin, HIGH);

  // 立ち上がりまでの時間計測
  while (digitalRead(inputPin)!=HIGH) t++;

  // 放電するまで待つ
  digitalWrite(outputPin, LOW);
  delay(3);

  if( t > threshold )
    Serial.println(panelNumber);
}
