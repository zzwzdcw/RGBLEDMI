#define BLINKER_WIFI
#define BLINKER_MIOT_LIGHT
#include <Blinker.h>

//  G D8  GPIO15      模组上的R跟G标反了依程序为主
//  R D7  GPIO13
//  B D6  GPIO12

char auth[] = "sky";
char ssid[] = "ssid";
char pswd[] = "pswd";

//新建组件对象

//基本变量定义
const int G = 15;   int r = 0;
const int R = 13;   int g = 0;
const int B = 12;   int b = 0;



//开关选项
void miotPowerState(const String & state)
{
  if (state == BLINKER_CMD_ON) {
    r = 511;
    g = 511;
    b = 511;
          analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
    Serial.println("LED ON");
    Blinker.delay(100); 
  }
  else if (state == BLINKER_CMD_OFF) {

    r = 0;
    g = 0;
    b = 0;
      analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
    Serial.println("LED OFF"); 
    Blinker.delay(100);
  }
}

void miotMode(uint8_t mode)
{
  if (mode == BLINKER_CMD_MIOT_DAY) {
    
    r = 1023;
    g = 1023;
    b = 1023;
      analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
    Serial.println("DAY ON");
    Blinker.delay(100);
  }
  else if (mode == BLINKER_CMD_MIOT_NIGHT) {    //夜间
     r = 400;
    g = 400;
    b = 400;
      analogWrite(R,r);
  analogWrite(G, g);
  analogWrite(B, b);
    Serial.println("NIGHT ON");
    Blinker.delay(100);
  }
  else if (mode == BLINKER_CMD_MIOT_COLOR) {    //彩光
  r=0;
  g=0;
  b=0;
while(r<1020){

  r=r+10;
  //g=g+5;
  Blinker.delay(5);
  Serial.print("r:     ");
  Serial.print(r);
  Serial.print("g:    ");
  Serial.println(g);
  Blinker.delay(10);
  analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
}

  }
  else if (mode == BLINKER_CMD_MIOT_WARMTH) {   //温馨
    r = 1023;
    g = 512;
      analogWrite(R, r);
  analogWrite(G, g);
  analogWrite(B, b);
    Serial.println("WARMTH ON");
  }
  else if (mode == BLINKER_CMD_MIOT_TV) {       //
    // Your mode function
  }
  else if (mode == BLINKER_CMD_MIOT_READING) {
    // Your mode function
  }
  else if (mode == BLINKER_CMD_MIOT_COMPUTER) {
    // Your mode function
  }

  // wsMode = mode;

  BlinkerMIOT.mode(mode);
//  BlinkerMIOT.print();
}

void setup() {
  Serial.begin(9600);  
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Blinker.begin(auth, ssid, pswd);
  BlinkerMIOT.attachPowerState(miotPowerState);
  BlinkerMIOT.attachMode(miotMode);
      Serial.println("OK!!");

}
void loop() {
  Blinker.run();

}
