
#include "SSD1306Wire.h"

/* 设置oled屏幕的相关信息 */
const int I2C_ADDR = 0x3c;              // oled屏幕的I2c地址
#define SDA_PIN 4                       // SDA引脚，默认gpio4(D2)
#define SCL_PIN 5                       // SCL引脚，默认gpio5(D1)

/* 新建一个oled屏幕对象，需要输入IIC地址，SDA和SCL引脚号 */
SSD1306Wire oled(I2C_ADDR, SDA_PIN, SCL_PIN);


void setup() {
  /* 1. 初始化串口通讯波特率为115200*/
  Serial.begin(115200);

  /* 2. oled屏幕初始化 */
  oled.init();
  oled.flipScreenVertically();        // 设置屏幕翻转
  oled.setContrast(255);              // 设置屏幕亮度
  drawRect();                         // 测试屏幕显示
  oled.clear(); oled.display();       // 清除屏幕
}

void loop() {
  oled.setFont(ArialMT_Plain_24);     // 设置字体
  oled.drawString(0, 0, "HelloWorld!");     // 将要显示的文字写入缓存
  oled.display();                     // 将缓存里的文字在屏幕上显示
  digitalWrite(LED_BUILTIN, LOW);     // Turn the LED on
  delay(300);
  digitalWrite(LED_BUILTIN, HIGH);    // Turn the LED off
  delay(500);
}

void drawRect(void) {
  for (int16_t i=0; i<oled.getHeight()/2; i+=2) {
    oled.drawRect(i, i, oled.getWidth()-2*i, oled.getHeight()-2*i);
    oled.display();
    delay(50);
  }
}
