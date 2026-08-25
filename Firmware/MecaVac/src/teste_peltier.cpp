#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int peltier = 16; //The N-Channel MOSFET is on digital pin 3
int canal = 0;
int resolucao = 12;
int freq = 1000;
int power = 0; //Power level fro 0 to 99%
int peltier_level = map(power, 0, 99, 0, 255); //This is a value from 0 to 255 that actually controls the MOSFET

void setup(){
    pinMode(peltier, OUTPUT);
    ledcSetup(canal, freq, resolucao);
    ledcAttachPin(peltier, canal);
    Serial.begin(115200);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
  }
    display.clearDisplay();
}

void loop(){
    char option;

    if(Serial.available() > 0){
        option = Serial.read();
    if(option == '+')
        power += 1;
    else if(option == '-')
        power -= 1;

    if(power > 99) power = 99;
    if(power < 0) power = 0;

    peltier_level = map(power, 0, 99, 0, 255);
}

    Serial.print("Power = ");
    Serial.print(power  );
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 20);
    display.print("Power = ");
    display.println(power);
    display.display();
    

    Serial.print("   Voltagem = ");
    Serial.println((float)peltier_level/1241.2);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 40);
    display.print("Voltagem = ");
    display.println((float)peltier_level/1241.2);
    display.display();
    

    ledcWrite(canal, peltier_level); //Write this new value out to the port
    delay(100);
    display.clearDisplay();
}

