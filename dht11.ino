/*bohai university 电子信息工程 minge 温湿度读取
 *DHT11模块线路  0.96寸OLED线路
 * VCC-3.3V     GND-GND
 * DATA-UNO2    VCC-5V
 * GND-GND      SCL-UNOA5
 *                        SDA-UNOA4   
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  dht.begin();
  }

void displayTempHumid(){
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("siyu H and T");
  display.setCursor(0,10);
  display.print("Humidity:    ");
  display.print(h);
  display.print("%");
  display.setCursor(0,20);
  display.print("Temperature: ");
  display.print(t);
  display.print("'C");
  }

void loop(){
  displayTempHumid();
  display.display();
  }
