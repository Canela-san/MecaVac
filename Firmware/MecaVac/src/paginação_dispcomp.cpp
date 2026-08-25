#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);   //endereço "adaptador" I2C

bool estado_1 = true;
bool estado_234 = false;
bool estado_5 = false;
bool estado_69 = false;
bool estado_7 = false;
bool estado_8 = false;
bool estado_10 = false;
bool estado_11 = false;
bool estado_12 = false;
bool estado_lang = false;
bool estado_unitC = false;
bool estado_unitF = false;
bool estado_beepON = false;
bool estado_beepOFF = false;
bool estado_disp12 = false;
bool estado_disp24 = false;
bool estado_year = false;
bool estado_month = false;
bool estado_hour = false;
bool estado_period = false;
bool estado_periodLeft = false;
bool estado_save = false;

void setup(){
  lcd.init();
  lcd.backlight();
}

void loop(){
  if (estado_1 == true){
    estado_1 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>"); //trocar por nº série do SD -> EEPROM
    lcd.setCursor(0, 2);
    lcd.print("       V1.0.0       "); //trocar por versão
    lcd.setCursor(0, 3);
    lcd.print("    INITIALIZING    ");  
  }
  if (estado_234 == true){
    estado_234 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>"); //trocar por nº série do SD -> EEPROM
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  //talvez trocar por (15, 2) se não cehagr no final da linha
    lcd.print(hora);
    lcd.setCursor(17,2);   //talvez trocar por (17, 2) se não cehagr no final da linha
    lcd.print(":");
    lcd.setCursor(18,2);   //talvez trocar por (18, 2) se não cehagr no final da linha
    lcd.print(minuto);
    
  }
  if (estado_5 == true){
    estado_5 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>"); //trocar por nº série do SD -> EEPROM
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  //talvez trocar por (15, 2) se não cehagr no final da linha
    lcd.print(hora);
    lcd.setCursor(17,2);   //talvez trocar por (17, 2) se não cehagr no final da linha
    lcd.print(":");
    lcd.setCursor(18,2);   //talvez trocar por (18, 2) se não cehagr no final da linha
    lcd.print(minuto);
  }
  if (estado_69 == true){
    estado_69 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("HAPPY PET VET & SHOP"); //trocar por mensagem recebida pelo servidor
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  //talvez trocar por (15, 2) se não cehagr no final da linha
    lcd.print(hora);
    lcd.setCursor(17,2);   //talvez trocar por (17, 2) se não cehagr no final da linha
    lcd.print(":");
    lcd.setCursor(18,2);   //talvez trocar por (18, 2) se não cehagr no final da linha
    lcd.print(minuto);
  }
  if (estado_7 == true){
    estado_7 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>"); //trocar por nº série do SD -> EEPROM
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  //talvez trocar por (15, 2) se não cehagr no final da linha
    lcd.print(hora);
    lcd.setCursor(17,2);   //talvez trocar por (17, 2) se não cehagr no final da linha
    lcd.print(":");
    lcd.setCursor(18,2);   //talvez trocar por (18, 2) se não cehagr no final da linha
    lcd.print(minuto);
  }
  if (estado_8 == true){
    estado_8 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("HAPPY PET VET & SHOP"); //trocar por mensagem recebida pelo servidor
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  //talvez trocar por (15, 2) se não cehagr no final da linha
    lcd.print(hora);
    lcd.setCursor(17,2);   //talvez trocar por (17, 2) se não cehagr no final da linha
    lcd.print(":");
    lcd.setCursor(18,2);   //talvez trocar por (18, 2) se não cehagr no final da linha
    lcd.print(minuto);
  }
  if (estado_10 == true){
    estado_10 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("HAPPY PET VET & SHOP"); //trocar por mensagem recebida pelo servidor
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  //talvez trocar por (15, 2) se não cehagr no final da linha
    lcd.print(hora);
    lcd.setCursor(17,2);   //talvez trocar por (17, 2) se não cehagr no final da linha
    lcd.print(":");
    lcd.setCursor(18,2);   //talvez trocar por (18, 2) se não cehagr no final da linha
    lcd.print(minuto);
  }
  if (estado_11 == true){
    estado_11 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>"); //trocar por nº série do SD -> EEPROM
    lcd.setCursor(0, 2);
    lcd.print("       V1.0.0       "); //trocar por versão
    lcd.setCursor(0, 3);
    lcd.print("      UPGRADING     ");
  }
  if (estado_12 == true){
    estado_12 = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 2);
    lcd.print("HARDWARE ERROR 0x100");
    lcd.setCursor(0, 3);
    lcd.print("  CALL FOR SERVICE  ");
  }

  //ESTADOS CONFIGURAÇÂO

  if (estado_lang == true){
    estado_lang = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("SELECT LANGUAGE");
  } 
  if (estado_unitC == true){
    estado_unit = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("TEMPERATURE DISPLAY:");
    lcd.setCursor(0, 3);
    lcd.print("<-  [C]   -   F   ->");
  }
  if (estado_unitF == true){
    estado_unit = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("TEMPERATURE DISPLAY:");
    lcd.setCursor(0, 3);
    lcd.print("<-   C   -   [F]  ->");
  }
  if (estado_beepON == true){
    estado_beep = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("NAVIGATION BEEP");
    lcd.setCursor(0, 3);
    lcd.print("<-  [ON]  -  OFF  ->");
  }
  if (estado_beepOFF == true){
    estado_beep = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("NAVIGATION BEEP");
    lcd.setCursor(0, 3);
    lcd.print("<-  ON  -  [OFF]  ->");
  }
  if (estado_disp12 == true){
    estado_disp = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("TIME DISPLAY");
    lcd.setCursor(0, 3);
    lcd.print("<-  [12]  -  24   ->");
  }
  if (estado_disp24 == true){
    estado_disp = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("TIME DISPLAY");
    lcd.setCursor(0, 3);
    lcd.print("<-   12  -  [24]  ->");
  }
  if (estado_year == true){
    estado_year = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("        YEAR        "); //bug no display (posicão(2,2))
  }
  if (estado_month == true){
    estado_month = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("       MONTH        ");
  }
  if (estado_hour == true){
    estado_hour = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("        HOUR        ");
  }
  if (estado_period == true){
    estado_period = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("CLEAN FILTER PERIOD");
  }
  if (estado_periodLeft == true){
    estado_periodLeft = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("DAYS TO FILTER CLEAN");
    lcd.setCursor(0, 3);
    lcd.print("04 DAYS"); //trocar por periodo real na lógica
    lcd.setCursor(16, 3);
    lcd.print("RESET");
  }
  if (estado_save == true){
    estado_save = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 2);
    lcd.print("       Saved        ");
  }
}

void set_allStateF(bool b,bool c,bool d,bool e,bool f,bool g,bool h,bool i,bool j,bool k,bool l,bool m,bool n,bool o,bool p,bool q,bool r,bool s,bool t,bool u,bool v){  // adicionar outros estados e usar quando chamar os estados
  
  b = false;
  c = false;
  d = false;
  e = false;
  f = false;
  g = false;
  h = false;
  i = false;
  j = false;
  k = false;
  l = false;
  m = false;
  n = false;
  o = false;
  p = false;
  q = false;
  r = false;
  s = false;
  t = false;
  u = false;
  v = false;
}