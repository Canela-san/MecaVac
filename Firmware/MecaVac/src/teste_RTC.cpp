#include "Wire.h"
#define DS1307_ADDRESS 0x68
byte zero = 0x00;


void setup(){
  Wire.begin();
  Serial.begin(9600);
setDateTime();            //Necessário configurar na função "setDateTime()"
}

void loop(){
  printDate();
  delay(1000);
}

void setDateTime(){

  byte segundo =      00;  //0-59
  byte minuto =        00;  //0-59
  byte hora =           19;  //0-23
  byte diasemana =    2;  //1-7
  byte dia =               3;  //1-31
  byte mes =            12; //1-12
  byte ano  =            13; //0-99

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); 

  Wire.write(decToBcd(segundo));
  Wire.write(decToBcd(minuto));
  Wire.write(decToBcd(hora));
  Wire.write(decToBcd(diasemana));
  Wire.write(decToBcd(dia));
  Wire.write(decToBcd(mes));
  Wire.write(decToBcd(ano));

  Wire.write(zero); 

  Wire.endTransmission();

}

byte decToBcd(byte val){
// Conversão de decimal para binário
  return ( (val/10*16) + (val%10) );
}

byte bcdToDec(byte val)  {
// Conversão de binário para decimal
  return ( (val/16*10) + (val%16) );
}

void printDate(){

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  int segundo = bcdToDec(Wire.read());
  int minuto = bcdToDec(Wire.read());
  int hora = bcdToDec(Wire.read() & 0b111111);    //Formato 24 horas
  int diasemana = bcdToDec(Wire.read());             //0-6 -> Domingo - Sábado
  int dia = bcdToDec(Wire.read());
  int mes = bcdToDec(Wire.read());
  int ano = bcdToDec(Wire.read());

//Exibe a data e hora. Ex.:   3/12/13 19:00:00
  
  Serial.print(dia);
  Serial.print("/");
  Serial.print(mes);
  Serial.print("/");
  Serial.print(ano);
  Serial.print(" ");
  Serial.print(hora);
  Serial.print(":");
  Serial.print(minuto);
  Serial.print(":");
  Serial.println(segundo);

}