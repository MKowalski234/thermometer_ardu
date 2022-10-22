#include <LM35.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 16);

LM35 temp(A0);
float C;
void setup()
{
  lcd.init();         
  lcd.init();
  lcd.backlight();
  pinMode(A0, INPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Temp is -");
  Serial.print(temp.cel());
  Serial.println(" C - ");
  C = temp.cel();
  lcd.setCursor(0,0);
  lcd.print("Temp is");
  lcd.setCursor(0,1);
  lcd.print(C);
  if(float(C)>=30)
  {
    digitalWrite(8,1);
    delay(1000);
  }
  delay(1000);
}
