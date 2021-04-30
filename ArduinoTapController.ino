int prevt = 0;
int t = 0;
int threshold = 10;  // 電流の許容範囲（抵抗と調整）

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

  // LED
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
}

void loop()
{ 
    touchInterface(3, 2, 1);
    touchInterface(5, 4, 2);
    touchInterface(7, 6, 3);
    touchInterface(9, 8, 4);
    touchInterface(11, 10, 5);
    touchInterface(13, 12, 6);
}

void touchInterface(int inputPin, int outputPin, int panelNumber)
{
    char buf[50];
    t = 0;

  // パルスの立ち上げ
  digitalWrite(outputPin, HIGH);

  // 立ち上がりまでの時間計測
  while (digitalRead(inputPin)!=HIGH) t++;

  // 放電するまで待つ
  digitalWrite(outputPin, LOW);  
  delay(3);

  // ローパスフィルタ
  //t = 0.8 * prevt + 0.2 * t;
  //prevt = t;

  // LED点灯
  if( t > threshold ){
    //digitalWrite(13, HIGH);
    sprintf(buf, "%d", panelNumber);
    Serial.println(buf);
    
  } else {
    //digitalWrite(13, LOW);
  }  
}
