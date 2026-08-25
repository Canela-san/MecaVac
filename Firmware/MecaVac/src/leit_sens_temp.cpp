#include <OneWire.h> //http://www.pjrc.com/teensy/td_libs_OneWire.html
#include <DallasTemperature.h> //http://milesburton.com/Main_Page?title=Dallas_Temperature_Control_Library

/*-----( Declare Constants and Pin Numbers )-----*/
#define ONE_WIRE_BUS_PIN 15

/*-----( Declare objects )-----*/
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS_PIN);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
float temp1 = 0.0;
float temp2 = 0.0;
float temp3 = 0.0;
/*-----( Declare Variables )-----*/
// Assign the addresses of your 1-Wire temp sensors
DeviceAddress Probe01 = {0x28, 0x74, 0x22, 0x96, 0xF0, 0x1, 0x3C, 0x9D };
DeviceAddress Probe02 = {0x28, 0xE4, 0x4A, 0x96, 0xF0, 0x1, 0x3C, 0x3 };
DeviceAddress Probe03 = {0x28, 0xE8, 0x9C, 0x96, 0xF0, 0x1, 0x3C, 0xBC };


void setup()   /****** SETUP: RUNS ONCE ******/
{
    // start serial port to show results
    Serial.begin(115200);
    // Initialize the Temperature measurement library
    sensors.begin();
    // set the resolution to 12 bit (Can be 9 to 12 bits .. lower is faster)
    sensors.setResolution(Probe01, 12);
    sensors.setResolution(Probe02, 12);
    sensors.setResolution(Probe03, 12);
}

void loop(){
    delay(1000);
    Serial.println();

    // Command all devices on bus to read temperature
    sensors.requestTemperatures();

    Serial.print("Sonda 01:   ");
    printTemperature(Probe01);
    Serial.println();

    Serial.print("Sonda 02:   ");
    printTemperature(Probe02);
    Serial.println();

    Serial.print("Sonda 03:   ");
    printTemperature(Probe03);
    Serial.println();

    temp1 = sensors.getTempC(Probe01);
    temp2 = sensors.getTempC(Probe02);

    Serial.print("Media 01/02:   ");
    Serial.print(temp1*0.5 + temp2*0.5);
    Serial.println();

}

/*-----( Declare User-written Functions )-----*/
void printTemperature(DeviceAddress deviceAddress){

    float tempC = sensors.getTempC(deviceAddress);

    if (tempC == -127.00){
    Serial.print("Error getting temperature  ");
  }
    else{
    Serial.print(tempC);
  }
}
