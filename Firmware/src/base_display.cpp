#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
 
LiquidCrystal_I2C lcd(0x3F,20,4);   //endereço "adaptador" I2C

void setup(){
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("********************");
    lcd.setCursor(0, 1);
    lcd.print("DISPLAY 20X4 COM I2C");
    lcd.setCursor(0, 2);
    lcd.print("********************");
}
 
void loop(){
    
}