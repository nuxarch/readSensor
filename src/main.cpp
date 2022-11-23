#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal.h>
#define PIN_POT     A2

uint16_t hasil_konversi;
unsigned long nilai_TPS;
String message1, message2;
LiquidCrystal lcd(9, 8, 13, 12, 11, 10); // LCD Shield
void setup() {
  Serial.begin(115200);
  lcd.begin(16,2);
  lcd.clear();
}

void loop() {
  hasil_konversi = analogRead(PIN_POT);
  nilai_TPS = map(hasil_konversi, 0, 1023, 0, 100);
  message1 = "TPS: "+String(nilai_TPS);
  message2 = "dat:"+String(hasil_konversi);
  // Serial.println("TPS : data digital :"+String(hasil_konversi)+", data "+String(nilai_TPS)+"%");
  Serial.println(message1+", "+message2);
  lcd.setCursor(0,0);
  lcd.println(message1);
  lcd.setCursor(0,1);
  lcd.println(message2);
  delay(200);
}