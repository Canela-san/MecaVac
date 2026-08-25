String versao = "V1.0.0";
bool reset = false;
// Variáveis servidor ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
/*
#include <DNSServer.h> 
#include <ESPAsyncWebServer.h>
#include <ESPAsyncWiFiManager.h>   
#include <WiFi.h>

AsyncWebServer server(80); //Cria os objetos dos servidores
DNSServer dns;
bool conectado = false;
unsigned long temp_wifi = 0;
*/
// Variáveis botões + portas |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int luz_interna = 15;
int RGBverde = 26;
int RGBvermelho = 25;
int sens_porta1 = A3;
int est_ini_por1 = 0;
int est_ini_por2 = 0;
int est_ini_por4 = 0;
int est_ini_bot = 0;
int botao_AP = 32;
int prim_press = 1;
int prim_press2 = 1;
int prim_press3 = 1;
int prim_press4 = 1;
int estado_botao = LOW;
int estado_luz = LOW;
int alarme_tocando = LOW;
int alarme = 13;
int estado_verde = HIGH;
int estado_vermelho = LOW;
long tempo_ult_debouce1 = 10; //mudar para ajustar
long tempo_ult_debouce2 = 10; //mudar para ajustar
long tempo_ult_debouce3 = 10; //mudar para ajustar
long tempo_ult_debouce4 = 10; //mudar para ajustar
long delay_debouce1 = 0;
long delay_debouce2 = 0;
long delay_debouce3 = 0;
long delay_debouce4 = 0;
long delay_alarme = 10000;
unsigned long tempo_alarme = 0; 
unsigned long tempo_atual = 0;

// Variáveis RTC||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#define DS1307_ADDRESS 0x68
byte zero = 0x00;

// Variáveis controle de temepratura |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include <OneWire.h>
#include <DallasTemperature.h>
unsigned long tempo_anteriorT = 0;
const unsigned long tempo_temp = 30000;
float ideal = 6.0;


#define ONE_WiRE_BUS_PiN 8  // declarar o pino de entrada dos sensores

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WiRE_BUS_PiN);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
float temp1 = 0.0;
float temp2 = 0.0;
float temp3 = 0.0;
float temp3F = 0.0;
float media_tempC = 0.0;
float media_tempF = 0.0;
bool uni_Celc = true;


// Assign the addresses of your 1-Wire temp sensors
DeviceAddress Probe01 = { 0x28, 0x74, 0x22, 0x96, 0xF0, 0x1, 0x3C, 0x9D };
DeviceAddress Probe02 = { 0x28, 0xE4, 0x4A, 0x96, 0xF0, 0x1, 0x3C, 0x3 };
DeviceAddress Probe03 = { 0x28, 0xE8, 0x9C, 0x96, 0xF0, 0x1, 0x3C, 0xBC };

// Variáveis peltier |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include <Wire.h>

int peltier = 161;  // The N-Channel MOSFET is on digital pin 3
int canal = 0;
int resolucao = 12;
int freq = 10000;
int power = 0;                                  // Power level fro 0 to 99%
int peltier_level = map(power, 0, 99, 0, 255);  // This is a value from 0 to 255 that actually controls the MOSFET

// Variáveis saída de vacinas |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int sinal_vac = 0;  // editar GPiO
int saida_vac = 0;
int leitura = 341;
bool prim_acion = true;

// Variáveis display ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);   //endereço "adaptador" i2C

bool estado_1 = false;
bool estado_234 = false;
bool estado_69 = false;
bool estado_69A = false;
bool estado_79 = false;
bool estado_79A = false;
bool estado_8 = false;
bool estado_year = false;
bool estado_month = false;
bool estado_day = false;
bool estado_hour = false;
bool estado_min = false;
bool estado_saved = false;
bool config = false;
bool trava_millis = false;
bool config1 = true;
bool config2 = true;

unsigned long temp_presave = 0;
unsigned long temp_saved = 0;
unsigned long temp_iniPress = 0;
unsigned long temp_iniPress2 = 0;
unsigned long temp_iniRefresh = 0;
unsigned long temp_refresh = 200;
unsigned long temp_config = 0;
unsigned long temp_reset = 0;
unsigned long temp_pag = 0;
unsigned long temp_debugp = 0;
unsigned long blinkTime = 0;
String placeHolder = "  ";

int flag_presave = 1;
int release = 0;
int prim_config = 1;
int prim_sim = LOW;
int prim_sim2 = LOW;
int bot_dir = A0;
int bot_esq = A1;
int est_ini_botD = 0;
int est_ini_botE = 0;
int prim_pressD = 1;
int prim_pressE = 1;
int tempo_ult_debouceD = 10;
int tempo_ult_debouceE = 10;
int delay_debouceD = 0;
int delay_debouceE = 0;
int estado_botaoD = LOW;
int estado_botaoE = LOW;
unsigned long tempo_inicializacao = 0;

// Controle queda de energia ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int entrada_energ = 131;
int leitura_energ = 0;
bool prim_leit = true;
unsigned long tempo_anteriorE = 0;
const unsigned long tempo_energ = 100;

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void setup() {
  pinMode(leitura, INPUT);
  pinMode(sens_porta1, INPUT);
  //pinMode(sens_porta2, iNPUT);
  pinMode(luz_interna, OUTPUT);
  pinMode(alarme, OUTPUT);
  pinMode(peltier, OUTPUT);
  pinMode(botao_AP, INPUT);
  pinMode(RGBverde, OUTPUT);
  pinMode(RGBvermelho, OUTPUT);
  pinMode(entrada_energ, INPUT);
  pinMode(bot_dir, INPUT);
  pinMode(bot_esq, INPUT);
  Serial.begin(115200);
/*
  AsyncWiFiManager manager(&server, &dns); //Cria o objeto do gerenciador
  Serial.println(); // Imprime o endereço de IP que teremos que entrar no navegador
  manager.resetSettings(); //Reseta as configurações do gerenciador
  manager.autoConnect("Chiller"); //Cria o ponto de acesso com o nome RefriVac 
  Serial.println("Conectado"); //Imprime a mensagem de confirmação
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
*/
  Wire.begin();
  setDateTime();

  // initialize the Temperature measurement library
  sensors.begin();
  // set the resolution to 12 bit (Can be 9 to 12 bits .. lower is faster)
  sensors.setResolution(Probe01, 12);
  sensors.setResolution(Probe02, 12);
  sensors.setResolution(Probe03, 12);
  //ledcSetup(canal, freq, resolucao);   // descomentar para ESP
  //ledcAttachPin(peltier, canal);       // descomentar para ESP

  lcd.init();
  lcd.backlight();
  //set_allStateF(estado_234,estado_5,estado_69,estado_7,estado_8,estado_10,estado_11,estado_12,estado_lang,estado_unit,estado_beep,estado_disp,estado_year,estado_month,estado_hour,estado_period,estado_periodLeft,estado_save);
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void loop() {
    
  tempo_atual = millis();

// Wifi |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
/*
  temp_wifi = tempo_atual;
  if(millis() == temp_wifi + 1000){
    temp_wifi = 0;
    if (WiFi.status() == WL_CONNECTED){
      conectado = true;
    }
    else{
      conectado = false;
    }
    Serial.println(conectado);
  }
*/
// Controle botões/portas/alarme ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  if (analogRead(sens_porta1) < 500 && est_ini_por1 == 0){  //detecção abertura porta 1
    if ((millis() - tempo_ult_debouce1) > delay_debouce1){
      est_ini_por1 = 1; // aberta
      tempo_ult_debouce1 = millis();
    }
  }
  else{
    if (est_ini_por1 == 1 && analogRead(sens_porta1) > 500){
      est_ini_por1 = 0; // fechada
      prim_press2 = 1;
      prim_press4 = 1;
    }
  }

  if (analogRead(sens_porta1) > 500 && est_ini_por4 == 0){  //detecção fechamento porta 1
    if ((millis() - tempo_ult_debouce4) > delay_debouce4){
      est_ini_por4 = 1; // fechada
      tempo_ult_debouce4 = millis();
    }
  }
  else{
    if (est_ini_por4 == 1 && analogRead(sens_porta1) < 500){
      est_ini_por4 = 0; // aberta
      prim_press3 = 1;
    }
  }
    
  if(est_ini_por1 == 1 && prim_press2 == 1){ 
    prim_press4 = 1; 
    prim_press2 = 0;
    estado_luz = HIGH;  // primeira leitura de porta aberta -> estado_luz = HIGH
    tempo_alarme = tempo_atual;
    estado_verde = HIGH;
    estado_vermelho = HIGH;
  }
  if (est_ini_por1 == 1){
    if (tempo_atual >= tempo_alarme + delay_alarme && prim_press4 == 1){
      prim_press4 = 0;
      alarme_tocando = HIGH;
    }
  }
    
  if(est_ini_por1 == 0 && prim_press3 == 1){
    prim_press3 = 0;
    estado_luz = LOW;  // primeira leitura de porta fechada -> estado_luz = LOW
    estado_vermelho = LOW;
    estado_verde = HIGH;
    alarme_tocando = LOW;
  }

  if(analogRead(botao_AP) > 3000 && est_ini_bot == 0){  //detecção aperto botão alarme/luz
    if((millis() - tempo_ult_debouce3) > delay_debouce3){
      est_ini_bot = 1; //pressionado
      tempo_ult_debouce3 = millis();
    }
  }
  else if(analogRead(botao_AP) <= 3000 && est_ini_bot == 1){
    if(est_ini_bot == 1 && digitalRead(botao_AP) == LOW){
      est_ini_bot = 0; //não pressionado
      prim_press = 1;
    }
  }

  if(est_ini_bot == 1 && prim_press == 1){   //primeiro pressionamento botão
    prim_press = 0;
    estado_botao = HIGH;
  }
  else{
    estado_botao = LOW;
  }

  if(estado_botao == HIGH){    //controle luz interna -> alterna estado da luz
    if(alarme_tocando == HIGH){
      alarme_tocando = LOW;
    }
    else{
      if(estado_luz == LOW){
        estado_luz = HIGH;
      }
      else{
        estado_luz = LOW;
      }
    }
  }

  if(estado_luz == HIGH){
    digitalWrite(luz_interna, HIGH);
  }
  else{
     digitalWrite(luz_interna, LOW);
  }
  if(alarme_tocando == HIGH){
    digitalWrite(alarme, HIGH);
  }
  else{
    digitalWrite(alarme, LOW);
  }
  if (estado_verde == HIGH){
    digitalWrite(RGBverde, HIGH);
  }
  else{
    digitalWrite(RGBverde, LOW);
  }
  if (estado_vermelho == HIGH){
    digitalWrite(RGBvermelho, HIGH);
  }
  else{
    digitalWrite(RGBvermelho, LOW);
  }
    
  // Controle saída de vacinas |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  sinal_vac = analogRead(leitura);

  if (sinal_vac < 158) {  // VALORES A SEREM EDiTADOS NA VERSÂO FiNAL
    saida_vac = 15;
  } else if ((sinal_vac >= 158) && (sinal_vac < 178)) {
    saida_vac = 14;
  } else if ((sinal_vac >= 178) && (sinal_vac < 210)) {
    saida_vac = 13;
  } else if ((sinal_vac >= 210) && (sinal_vac < 240)) {
    saida_vac = 12;
  } else if ((sinal_vac >= 240) && (sinal_vac < 260)) {
    saida_vac = 11;
  } else if ((sinal_vac >= 260) && (sinal_vac < 300)) {
    saida_vac = 10;
  } else if ((sinal_vac >= 300) && (sinal_vac < 350)) {
    saida_vac = 9;
  } else if ((sinal_vac >= 350) && (sinal_vac < 400)) {
    saida_vac = 8;
  } else if ((sinal_vac >= 410) && (sinal_vac < 500)) {
    saida_vac = 7;
  } else if ((sinal_vac >= 500) && (sinal_vac < 600)) {
    saida_vac = 6;
  } else if ((sinal_vac >= 600) && (sinal_vac < 750)) {
    saida_vac = 5;
  } else if ((sinal_vac >= 750) && (sinal_vac < 1000)) {
    saida_vac = 4;
  } else if ((sinal_vac >= 1000) && (sinal_vac < 1500)) {
    saida_vac = 3;
  } else if ((sinal_vac >= 1500) && (sinal_vac < 2500)) {
    saida_vac = 2;
  } else {
    saida_vac = 1;
  }

  //Serial.println(sinal_vac);

  if (sinal_vac != 0 && prim_acion == true) {  // acima de 0 pela primeira vez
    prim_acion = false;
  }
  // envio ao servidor
  if (prim_acion == false) {
  }
  if (sinal_vac == 0) {
    prim_acion = true;
  }

  // Controle de temperatura peltier |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  if (tempo_atual - tempo_anteriorT >= tempo_temp) {
    sensors.requestTemperatures();
    temp1 = sensors.getTempC(Probe01);
    temp2 = sensors.getTempC(Probe02);
    temp3 = sensors.getTempC(Probe03);
    temp3F = (temp3 * (9/5)) + 32.0;
    media_tempC = temp1 * 0.5 + temp2 * 0.5;
    media_tempF = (media_tempC * (9/5)) + 32.0;
    Serial.print("Media temp = ");
    Serial.println(media_tempC);

    if ((ideal < media_tempC + 1.0)) {
      power = power + 5;  // editar pra valor percentual ideal conforme experimentos
    } else if ((ideal < media_tempC + 2.0) && (ideal >= media_tempC + 1.0)) {
      power = power + 10;  // editar pra valor percentual ideal conforme experimentos
    } else if ((ideal >= media_tempC + 2.0)) {
      power = 100;
    } else {
      power = 0;
    }
    if (power > 99)
      power = 99;
    if (power < 0)
      power = 0;

    if (temp1 == -127.00) {
      Serial.println("Erro obtendo temperatura no sensor 1");
    }
    if (temp2 == -127.00) {
      Serial.println("Erro obtendo temperatura no sensor 2");
    }
    if (temp3 == -127.00) {
      Serial.println("Erro obtendo temperatura no sensor 3");
    }
    peltier_level = map(power, 0, 99, 0, 255);
    //ledcWrite(canal, peltier_level);  // Write this new value out to the port // descomentar para ESP
    tempo_anteriorT = tempo_atual;
  }
  // Queda de energia ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
/*
  if (tempo_atual - tempo_anteriorE >= tempo_energ) {
    leitura_energ = analogRead(entrada_energ);
    if (leitura_energ > 1100) {  // Testar o envio único de log
      prim_leit = true;
    }
    if (leitura_energ < 1100 && prim_leit == true) {  // Valores certos?
      prim_leit = false;
      Serial.println("ACABOU ENERGIA");  // Trocar por enviar ao servidor
    }
    if (prim_acion == false) {
    }
    tempo_anteriorE = tempo_atual;
  }
*/
  // Obtenção hora/dia do RTC ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  int segundo = bcdToDec(Wire.read());
  int minuto = bcdToDec(Wire.read());
  int hora = bcdToDec(Wire.read() & 0b111111);  // Formato 24 horas
  int diasemana = bcdToDec(Wire.read());        // 0-6 -> Domingo - Sábado
  int dia = bcdToDec(Wire.read());
  int mes = bcdToDec(Wire.read());
  int ano = bcdToDec(Wire.read());

  // Exibe a data e hora. Ex.:   3/12/13 19:00:00
  // Serial.print(dia);
  // Serial.print("/");
  // Serial.print(mes);
  // Serial.print("/");
  // Serial.print(ano);
  // Serial.print(" ");
  // Serial.print(hora);
  // Serial.print(":");
  // Serial.print(minuto);
  // Serial.print(":");
  // Serial.println(segundo);

  // Lógica display |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  /*if(ler primeira passagem de corrente no sensor){
    tempo_inicializacao = tempo_atual;
    if(millis() - tempo_inicializacao < 5000){  //aciona tela de inicialização nos primeiros 5s desde ativação dispositivo
      estado_1 = true;
    }
    else{
      estado_1 = false;
    }
  }
  
  if(conectado == false && estado_1 == false && estado_8 == false && 2.0 < media_tempC < 8.0 && millis() - tempo_inicializacao < 305000){ //aciona tela 234 e processos por até 5 minutos
    estado_234 = true;
  }
  else{
    estado_234 = false;
  }
  
  if(conectado == true && millis() - tempo_inicializacao > 305000 && estado_1 == false && estado_8 == false && media_tempC > 2.0 && media_tempC < 8.0){ //aciona tela 69 se a conecção não for estabelecida em até 5 minutos
    estado_69 = true;
  }
  else{
    estado_69 = false;
  }

  if(conectado == true && millis() - tempo_inicializacao > 305000 && estado_1 == false && estado_8 == false && media_tempC < 2.0 || media_tempC > 8.0){ //aciona tela 69A se a conecção não for estabelecida em até 5 minutos
    estado_69A = true;
  }
  else{
    estado_69A = false;
  }
  
  if(conectado == false && millis() - tempo_inicializacao > 305000 && estado_1 == false && estado_8 == false && media_tempC > 2.0 && media_tempC < 8.0){ //aciona tela 79 se a conecção não for estabelecida em até 5 minutos
    estado_79 = true;
  }
  else{
    estado_79 = false;
  }

  if(conectado == false && millis() - tempo_inicializacao > 305000 && estado_1 == false && estado_8 == false && media_tempC < 2.0 || media_tempC > 8.0){ //aciona tela 79A se a conecção não for estabelecida em até 5 minutos
    estado_79A = true;
  }
  else{
    estado_79A = false;
  }
*/
  if(est_ini_por1 == 1 && config == false){ //aciona tela 8 se a porta estiver aberta, com maior prioridade sobre outras mensagens
    estado_8 = true;
  }
  else{
    estado_8 = false;
  }

  if(analogRead(bot_dir) > 500 && est_ini_botD == 0){  //detecção aperto botão à direita do display
    if((millis() - tempo_ult_debouceD) > delay_debouceD){
      est_ini_botD = 1; //pressionado
      tempo_ult_debouceD = millis();
    }
  }
  else if(analogRead(bot_dir) <= 500 && est_ini_botD == 1){
    if(est_ini_botD == 1 && digitalRead(bot_dir) == LOW){
      est_ini_botD = 0; //não pressionado
      prim_pressD = 1;
    }
  }

  if(est_ini_botD == 1 && prim_pressD == 1){   //primeiro pressionamento botão
    prim_pressD = 0;
    estado_botaoD = HIGH;
  }
  else{
    estado_botaoD = LOW;
  }
  
  if(analogRead(bot_esq) > 500 && est_ini_botE == 0){  //detecção aperto botão à esquerda do display
    if((millis() - tempo_ult_debouceE) > delay_debouceE){
      est_ini_botE = 1; //pressionado
      tempo_ult_debouceE = millis();
    }
  }
  else if(analogRead(bot_esq) <= 500 && est_ini_botE == 1){
    if(est_ini_botE == 1 && digitalRead(bot_esq) == LOW){
      est_ini_botE = 0; //não pressionado
      prim_pressE = 1;
    }
  }

  if(est_ini_botE == 1 && prim_pressE == 1){  //primeiro pressionamento botão
    prim_pressE = 0;
    estado_botaoE = HIGH;
  }
  else{
    estado_botaoE = LOW;
  }

  if(est_ini_botD == 1 && est_ini_botE == 1 && prim_sim == LOW && config == false){
    temp_iniPress = tempo_atual;
    prim_sim = HIGH;
  }
  if(tempo_atual >= temp_iniPress + 3000 && config == false && tempo_atual != 3000 && est_ini_botE == 1 && est_ini_botD == 1){
    prim_config = 1;
    config = true;
    prim_sim = LOW;
  }
  if(tempo_atual >= temp_iniPress2 + 30000 && est_ini_botE == 1 && est_ini_botD == 1){
    reset = 1;
    prim_sim2 = LOW;
  }
  if (est_ini_botE == 0 || est_ini_botD == 0){
    temp_iniPress = 0;
    prim_sim = LOW;
    temp_iniPress2 = millis();
  }

  Serial.println(temp_presave);

  if(config == true){
    estado_1 = false;
    estado_234 = false;
    estado_69 = false;
    estado_69A = false;
    estado_79 = false;
    estado_79A = false;
    estado_8 = false;
    if (prim_config == 1){
      lcd.clear();
      estado_year = true;
    }
    prim_config = 0;

    if(estado_year == true || estado_month == true || estado_day == true){
      if (flag_presave == 1){
        temp_presave = millis();
        flag_presave = 0;
      }
      if(estado_botaoE == HIGH){
        if(estado_year == true){
          estado_year = false;
          lcd.clear();
          estado_month = true;
        }
        else if(estado_month == true){
          estado_month = false;
          lcd.clear();
          estado_day = true;
        }
        else if(estado_day == true){
          estado_day = false;
          lcd.clear();
          estado_year = true;
        }
      }
      if(millis() >= temp_presave + 1500 && est_ini_botD == 1 && est_ini_botE == 1){
        flag_presave = 1;
        temp_presave = 0;
        estado_year = false;
        estado_month = false;
        estado_day = false;
        lcd.clear();
        estado_saved = true;
        trava_millis = true;
        temp_saved = millis();
        config2 = false;
        config1 = true;
      }
    }
    if(millis() >= temp_saved + 1000 && config1 == true){
      estado_year = false;
      estado_month = false;
      estado_day = false;
      trava_millis = false;
      estado_saved = false;
      lcd.clear();
      estado_hour = true;
    }

    if(estado_hour == true || estado_min == true){
      if (flag_presave == 1){
        temp_presave = millis();
        flag_presave = 0;
      }
      if(estado_botaoE == HIGH){
        if(estado_hour == true){
          estado_hour = false;
          lcd.clear();
          estado_min = true;
        }
        else if(estado_min == true){
          estado_min = false;
          lcd.clear();
          estado_hour = true;
        }
      }
      if(millis() >= temp_presave + 1500 && est_ini_botD == 1 && est_ini_botE == 1){
        flag_presave = 1;
        temp_presave = 0;
        estado_hour = false;
        estado_min = false;
        lcd.clear();
        estado_saved = true;
        trava_millis = true;
        temp_saved = millis();
        config1 = false;
        config2 = true;
      }
    }
    if(millis() >= temp_saved + 1000 && config2 == true){
      estado_hour = false;
      estado_min = false;
      trava_millis = false;
      estado_saved = false;
      lcd.clear();
      config = false;
    }
  }
  if (trava_millis == false){
    temp_saved = millis();
  }
  // Paginação display ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  if (estado_1 == true){
    //lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>");
    lcd.setCursor(7, 2);
    lcd.print(versao); 
    lcd.setCursor(0, 3);
    lcd.print("    INITIALIZING    ");  
  }
  if (estado_234 == true){
    //estado_234 = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>"); 
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  
    lcd.print(hora);
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(minuto >= 10){
    lcd.setCursor(18,2);   
    lcd.print(minuto);
    }
    else{
    lcd.setCursor(18,2);   
    lcd.print("0");
    lcd.setCursor(19,2);   
    lcd.print(minuto);
    }
    scrollMessage(3, "CONNECT TO ME (SSID: CHILLER) AND SELECT A WiFi CONNECTION (AP IP: 192.168.4.1)", 250, 20);
    
  }
  if (estado_69 == true){
    //estado_69 = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("XXXXXXXXXXXXXXXXXXXX"); //bug no primeiro X
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  
    lcd.print(hora);
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(minuto >= 10){
    lcd.setCursor(18,2);   
    lcd.print(minuto);
    }
    else{
    lcd.setCursor(18,2);   
    lcd.print("0");
    lcd.setCursor(19,2);   
    lcd.print(minuto);
    }
    lcd.setCursor(0, 3);
    lcd.print("ONLINE        NORMAL");
  }
  if (estado_69A == true){
    //estado_69 = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("XXXXXXXXXXXXXXXXXXXX"); // bug no primeiro X
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  
    lcd.print(hora);
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(minuto >= 10){
    lcd.setCursor(18,2);   
    lcd.print(minuto);
    }
    else{
    lcd.setCursor(18,2);   
    lcd.print("0");
    lcd.setCursor(19,2);   
    lcd.print(minuto);
    }
    lcd.setCursor(0, 3);
    lcd.print("ONLINE    NOT NORMAL");
  }
  if (estado_79 == true){
    //estado_79 = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>"); 
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  
    lcd.print(hora);
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(minuto >= 10){
    lcd.setCursor(18,2);   
    lcd.print(minuto);
    }
    else{
    lcd.setCursor(18,2);   
    lcd.print("0");
    lcd.setCursor(19,2);   
    lcd.print(minuto);
    }
    lcd.setCursor(0, 3);
    lcd.print("OFFLINE       NORMAL");
  }
  if (estado_79A == true){
    //estado_79 = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("<<< - 00000000 - >>>"); 
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  
    lcd.print(hora);
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(minuto >= 10){
    lcd.setCursor(18,2);   
    lcd.print(minuto);
    }
    else{
    lcd.setCursor(18,2);   
    lcd.print("0");
    lcd.setCursor(19,2);   
    lcd.print(minuto);
    }
    lcd.setCursor(0, 3);
    lcd.print("OFFLINE   NOT NORMAL");
  }
  if (estado_8 == true){
    //estado_8 = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("XXXXXXXXXXXXXXXXXXXX"); //bug no primeiro X
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    lcd.setCursor(15, 2);  
    lcd.print(hora);
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(minuto >= 10){
    lcd.setCursor(18,2);   
    lcd.print(minuto);
    }
    else{
    lcd.setCursor(18,2);   
    lcd.print("0");
    lcd.setCursor(19,2);   
    lcd.print(minuto);
    }
    lcd.setCursor(0, 3);
    lcd.print("DOOR OPEN");
  } 
  if (estado_year == true){
    //estado_year = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("        YEAR        ");
    lcd.setCursor(0,3);
    lcd.print("<-");
    lcd.setCursor(8,3);
    lcd.print("20");
    lcd.setCursor(10,3);
    if (millis() - blinkTime > 2000) {
      lcd.print(ano);
      blinkTime = millis();
    }
    if (millis() - blinkTime > 1000) {
      lcd.print(placeHolder);
    }
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH && est_ini_botE == 0){
      ++ano;
      if (ano == 100){
        ano = 1;
      } 
    }
    
  }
  if (estado_month == true){
    //estado_month = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("       MONTH        ");
    lcd.setCursor(0,3);
    lcd.print("<-");
    lcd.setCursor(8,3);
    if (millis() - blinkTime > 2000) {
      lcd.print(mes);
      blinkTime = millis();
    }
    if (millis() - blinkTime > 1000) {
      lcd.print(placeHolder);
    }
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH && est_ini_botE == 0){
      ++mes;
      if (mes == 13){
        mes = 1;
      } 
    }
  }
  if (estado_day == true){
    //estado_day = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("        DAY         ");
    lcd.setCursor(0,3);
    lcd.print("<-");
    lcd.setCursor(8,3);
    if (millis() - blinkTime > 2000) {
      lcd.print(dia);
      blinkTime = millis();
    }
    if (millis() - blinkTime > 1000) {
      lcd.print(placeHolder);
    }
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH && est_ini_botE == 0){
      ++dia;
      if (dia == 32){
        dia = 1;
      } 
    }
  }
  if (estado_hour == true){
    //estado_hour = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("        HOUR        ");
    lcd.setCursor(0,3);
    lcd.print("<-");
    lcd.setCursor(8,3);
    if (millis() - blinkTime > 2000) {
      lcd.print(hora);
      blinkTime = millis();
    }
    if (millis() - blinkTime > 1000) {
      lcd.print(placeHolder);
    }
    lcd.setCursor(10,3);
    lcd.print(":");
    lcd.setCursor(11,3);
    lcd.print(minuto);
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH && est_ini_botE == 0){
      ++hora;
      if (hora == 24){
        hora = 0;
      } 
    }
  }
  if (estado_min == true){
    //estado_min = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 1);
    lcd.print("Configuration");
    lcd.setCursor(0, 2);
    lcd.print("       MINUTE       ");
    lcd.setCursor(0,3);
    lcd.print("<-");
    lcd.setCursor(8,3);
    lcd.print(hora);
    lcd.setCursor(10,3);
    lcd.print(":");
    lcd.setCursor(11,3);
    if (millis() - blinkTime > 2000) {
      lcd.print(minuto);
      blinkTime = millis();
    }
    if (millis() - blinkTime > 1000) {
      lcd.print(placeHolder);
    }
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH && est_ini_botE == 0){
      ++minuto;
      if (minuto == 60){
        minuto = 0;
      } 
    }
  }
  if (estado_saved == true){
    //estado_saved = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      lcd.clear();
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 2);
    lcd.print("       Saved        ");
  }
  // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
}
void setDateTime() {

  byte segundo = 0;   // 0-59
  byte minuto = 0;    // 0-59
  byte hora = 20;      // 0-23
  byte diasemana = 1;  // 1-7
  byte dia = 1;       // 1-31
  byte mes = 1;        // 1-12
  byte ano = 22;       // 0-99

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

byte decToBcd(byte val) {
  // Conversão de decimal para bário
  return ((val / 10 * 16) + (val % 10));
}
byte bcdToDec(byte val) {
  // Conversão de binário para decimal
  return ((val / 16 * 10) + (val % 16));
}

void set_allStateF(bool c,bool d,bool e,bool f,bool g,bool h,bool i){  // adicionar outros estados e usar quando chamar os estados
  c = false;
  d = false;
  e = false;
  f = false;
  g = false;
  h = false;
  i = false;
}

void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  for (int i=0; i < totalColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(delayTime);
  }
}
