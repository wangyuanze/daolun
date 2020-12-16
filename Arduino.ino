#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include<SoftwareSerial.h>

SoftwareSerial mySerial(2,3);
//iic驱动方式
U8G2_SSD1306_128X64_NONAME_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
  u8g2.begin();
}

int wea[3];
//int feels;
//int hum;
String luan;
void loop() {
 for(int i=0;i<3;i++){
  if(mySerial.peek()!='\n') {  //在没接收到回车换行的条件下
   wea[i]=(int)mySerial.read();
  }
 }
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_wqy12_t_chinese1);
    u8g2.drawStr(0, 23, "TEMP:");
    //u8g2.drawStr(20, 23, ":");
    u8g2.drawStr(70, 23, wea[0]);
    u8g2.drawStr(90, 23, "C");
    u8g2.drawStr(0,43,"FEELSLIKE:");
    u8g2.drawStr(70,43,wea[1]);
    u8g2.drawStr(90,43,"C");
    u8g2.drawStr(0,63,"HUMMIDITY:");
    u8g2.drawStr(70,63,wea[2]);
    u8g2.drawStr(90,63,"%");

  } while ( u8g2.nextPage() );
  delay(1000);
}
