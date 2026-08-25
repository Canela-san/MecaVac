String versao = "V1.0.0";
bool reset = false;
bool flag_liga = true;

// Variáveis servidor ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include <DNSServer.h> 
#include <ESPAsyncWebServer.h>
#include <ESPAsyncWiFiManager.h>   
#include <WiFi.h>

AsyncWebServer server(80); //Cria os objetos dos servidores
DNSServer dns;
unsigned long temp_wifi = 0;
int wifi_flag = 1;

int conectado = 0;
// Cartão SD |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include "FS.h"
#include "SD.h"
#include "SPI.h"

// Variáveis botões + portas |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int luz_interna = 25;
int RGBverde = 17;
int RGBvermelho = 16;
int sens_porta1 = 14;
int est_ini_por1 = 0;
int est_ini_por2 = 0;
int est_ini_por4 = 0;
int est_ini_bot = 0;
int prim_press = 1;
int prim_press2 = 1;
int prim_press3 = 1;
int prim_press4 = 1;
int estado_botao = LOW;
int estado_luz = LOW;
int alarme_tocando = LOW;
int alarme = 33;
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
unsigned long temp_set = 0;

// Variáveis controle de temepratura |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#include <OneWire.h>
#include <DallasTemperature.h>
unsigned long tempo_anteriorT = 0;
const unsigned long tempo_temp = 30000;
float ideal = 6.0;


#define ONE_WIRE_BUS_PIN 26  // declarar o pino de entrada dos sensores

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS_PIN);

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

int peltier = 4;  // The N-Channel MOSFET is on digital pin 3
int canal = 0;
int resolucao = 8;
int freq = 5000;                                 
int peltier_level = 0;  // This is a value from 0 to 255 that actually controls the MOSFET

// Variáveis saída de vacinas |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int sinal_vac = 357;  // editar GPiO
int saida_vac = 0;
int leitura = 4;
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
bool prim8 = true;

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

int ultima = 0;
int flag_presave = 1;
int release = 0;
int prim_config = 1;
int prim_sim = LOW;
int prim_sim2 = LOW;
int bot_dir = 32;
int bot_esq = 27;
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

int entrada_energ = 35;
int leitura_energ = 0;
bool prim_leit = true;
unsigned long tempo_anteriorE = 0;
const unsigned long tempo_energ = 100;

// Falha peltier |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int sens_energ1 = 12;
int sens_energ2 = 13;

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void setup() {

  //SERVIDOR: Código 10 (Boot normal)
  //SERVIDOR: Código 70, dado 40 (Liga -> ler se ter arquivo no SD -> Queda de energia servidor)

  pinMode(leitura, INPUT);
  pinMode(sens_porta1, INPUT);
  //pinMode(sens_porta2, INPUT);
  pinMode(luz_interna, OUTPUT);
  pinMode(alarme, OUTPUT);
  pinMode(peltier, OUTPUT);
  pinMode(RGBverde, OUTPUT);
  pinMode(RGBvermelho, OUTPUT);
  pinMode(entrada_energ, INPUT);
  pinMode(bot_dir, INPUT);
  pinMode(bot_esq, INPUT);
  pinMode(sens_energ1, INPUT);
  pinMode(sens_energ2, INPUT);
  Serial.begin(115200);

  Wire.begin();

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  int seg = bcdToDec(Wire.read());
  int min = bcdToDec(Wire.read());
  int hor = bcdToDec(Wire.read() & 0b111111);  // Formato 24 horas
  int diasem = bcdToDec(Wire.read());        // 0-6 -> Domingo - Sábado
  int di = bcdToDec(Wire.read());
  int me = bcdToDec(Wire.read());
  int an = bcdToDec(Wire.read());

  setDateTime(seg, min, hor, diasem, di, me, an);

  // initialize the Temperature measurement library
  sensors.begin();
  // set the resolution to 12 bit (Can be 9 to 12 bits .. lower is faster)
  sensors.setResolution(Probe01, 12);
  sensors.setResolution(Probe02, 12);
  sensors.setResolution(Probe03, 12);
  ledcSetup(canal, freq, resolucao);   // descomentar para ESP
  ledcAttachPin(peltier, canal);       // descomentar para ESP

  lcd.init();
  lcd.backlight();

  if(!SD.begin()){
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
    return;
  }
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void loop() {
  Serial.println(conectado);
  tempo_atual = millis();

// Wifi |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  if(wifi_flag == 1){
    wifi_flag = 0;
    AsyncWiFiManager manager(&server, &dns); //Cria o objeto do gerenciador
    manager.setTimeout(60); //timeout após 5 min (testar e chamar na hora certa)
    Serial.println(); // Imprime o endereço de IP que teremos que entrar no navegador
    manager.resetSettings(); //Reseta as configurações do gerenciador
    manager.autoConnect("Chiller"); //Cria o ponto de acesso com o nome RefriVac 
    Serial.println("Conectado"); //Imprime a mensagem de confirmação
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  }

  temp_wifi = tempo_atual;
  if(millis() == temp_wifi + 1000){
    temp_wifi = 0;
    if (WiFi.status() == WL_CONNECTED){
      conectado = 1;
    }
    else{
      conectado = 0;
    }
  }

// Controle botões/portas/alarme ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  if (analogRead(sens_porta1) < 1000 && est_ini_por1 == 0){  //detecção abertura porta 1
    if ((millis() - tempo_ult_debouce1) > delay_debouce1){
      est_ini_por1 = 1; // aberta

      //SERVIDOR: Código 51 (Abre -> Servidor)

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

  if (analogRead(sens_porta1) > 1000 && est_ini_por4 == 0){  //detecção fechamento porta 1
    if ((millis() - tempo_ult_debouce4) > delay_debouce4){
      est_ini_por4 = 1; // fechada

      //SERVIDOR: Código 51 (Fecha -> Servidor)

      tempo_ult_debouce4 = millis();
    }
  }
  else{
    if (est_ini_por4 == 1 && analogRead(sens_porta1) < 1000){
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

  if((estado_botaoE == HIGH || estado_botaoD == HIGH) && config == false){    //controle luz interna -> alterna estado da luz
    if(alarme_tocando == HIGH){
      alarme_tocando = LOW;
    }
    else{
      if(estado_luz == HIGH){
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

  //sinal_vac = analogRead(leitura); DESCOMENTAR PRA PORTA CERTA -> Pode dar problema com PWM do peltier

  if (sinal_vac < 158) {  // VALORES A SEREM EDITADOS NA VERSÂO FiNAL
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

  //SERVIDOR: Código 60 (Sempre que sair -> SD -> Servidor)

  //Serial.println(sinal_vac);

  if (sinal_vac != 0 && prim_acion == true) {  // acima de 0 pela primeira vez
    prim_acion = false;
  }
  // envio ao servidor
  if (prim_acion == false) {
  }
  if (sinal_vac == 0) {  // QUE?
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
    if (temp1 == -127.00) {
      Serial.println("Erro obtendo temperatura no sensor 1");
    }
    if (temp2 == -127.00) {
      Serial.println("Erro obtendo temperatura no sensor 2");
    }
    if (temp3 == -127.00) {
      Serial.println("Erro obtendo temperatura no sensor 3");
    }
    tempo_anteriorT = tempo_atual;
  }

  if(media_tempC <= ideal - 2.0){
    peltier_level = 0;
  }
  if(media_tempC > ideal - 2.0 && media_tempC <= ideal){
    peltier_level = 70; 
  }
  if(media_tempC > ideal && media_tempC <= ideal + 2.0){
    peltier_level = 127; 
  }
  if(media_tempC > ideal + 2.0){
    peltier_level = 255; 
  }

  ledcWrite(canal, peltier_level);  // Write this new value out to the port // descomentar para ESP

  // Falha peltier |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  //Serial.println(analogRead(sens_energ1));

  // Queda de energia ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

  if (tempo_atual - tempo_anteriorE >= tempo_energ) {   //Tá com um delay pequeno pra bugar menos o código (se n funcionar só tirar ou diminuir na variável tempo_energ)
    leitura_energ = analogRead(entrada_energ);  //Atualiza valor da leitura
    if (leitura_energ > 1100) {  //Valor (1100) poder ser alterado conforme necessário, de 0 a 4095 de acordo com os testes (idealmente, quanto mais alto possível sem leitura falsa)
      prim_leit = true;  //Mantém o flag true
    }
    if (leitura_energ < 1100 && prim_leit == true) {  //Valor (1100) também pode ser alterado
      prim_leit = false;  //Flag off para não ler duas vezes
      writeFile(SD, "/log_energia.txt", "Acabou a energia");  //Tá sem data e hora no log pq queria que tivesse menos chance de dar erro por enquanto
      Serial.println("ACABOU ENERGIA");   
    }
    tempo_anteriorE = tempo_atual;  //Reseta delay
  }
  //Serial.println(leitura_energ);  //(apagar após calibração)

  //SERVIDOR: Código 70, dado 40 (Caiu energia -> SD)

  // Obtenção hora/dia do RTC ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  int seg = bcdToDec(Wire.read());
  int min = bcdToDec(Wire.read());
  int hor = bcdToDec(Wire.read() & 0b111111);  // Formato 24 horas
  int diasem = bcdToDec(Wire.read());        // 0-6 -> Domingo - Sábado
  int di = bcdToDec(Wire.read());
  int me = bcdToDec(Wire.read());
  int an = bcdToDec(Wire.read());

  // Lógica display ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
  //if(ler primeira passagem de corrente no sensor){
  
  if(flag_liga == true){
    tempo_inicializacao = tempo_atual;
    estado_1 = true;
    if(millis() > 5000){  //apaga tela de inicialização nos primeiros 5s depois ativação dispositivo
      flag_liga = false;
      estado_1 = false;
      sensors.requestTemperatures();
      temp1 = sensors.getTempC(Probe01);
      temp2 = sensors.getTempC(Probe02);
      temp3 = sensors.getTempC(Probe03);
      temp3F = (temp3 * (9/5)) + 32.0;
      media_tempC = temp1 * 0.5 + temp2 * 0.5;
      media_tempF = (media_tempC * (9/5)) + 32.0;
      lcd.clear();
    }
  }
  //}

  if(est_ini_por1 == 1 && config == false && estado_1 == false){ //aciona tela 8 se a porta estiver aberta, com maior prioridade sobre outras mensagens
    if(prim8 == true){
      lcd.clear();
    }
    prim8 = false;
    estado_8 = true;
  }
  else{
    estado_8 = false;
    prim8 = true;
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

  if(conectado == true && millis() - tempo_inicializacao > 305000 && estado_1 == false && estado_8 == false && (media_tempC < 2.0 || media_tempC > 8.0)){ //aciona tela 69A se a conecção não for estabelecida em até 5 minutos
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

  if(conectado == false && millis() - tempo_inicializacao > 305000 && estado_1 == false && estado_8 == false && (media_tempC < 2.0 || media_tempC > 8.0)){ //aciona tela 79A se a conecção não for estabelecida em até 5 minutos
    estado_79A = true;
  }
  else{
    estado_79A = false;
  }

  if(analogRead(bot_dir) > 1000 && est_ini_botD == 0){  //detecção aperto botão à direita do display
    if((millis() - tempo_ult_debouceD) > delay_debouceD){
      est_ini_botD = 1; //pressionado
      tempo_ult_debouceD = millis();
    }
  }
  else if(analogRead(bot_dir) <= 1000 && est_ini_botD == 1){
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
  
  if(analogRead(bot_esq) > 1000 && est_ini_botE == 0){  //detecção aperto botão à esquerda do display
    if((millis() - tempo_ult_debouceE) > delay_debouceE){
      est_ini_botE = 1; //pressionado
      tempo_ult_debouceE = millis();
    }
  }
  else if(analogRead(bot_esq) <= 1000 && est_ini_botE == 1){
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
      if(estado_year == true){
        ultima = 1;
      }
      if(estado_botaoE == HIGH){
        if(estado_year == true){
          estado_year = false;
          lcd.clear();
          ultima = 2;
          estado_month = true;
        }
        else if(estado_month == true){
          estado_month = false;
          ultima = 3;
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
        if (temp_set + 700 >= millis()){
          if(ultima == 1){
            --an;
          }
          if(ultima == 2){
            --me;
          }
          if(ultima == 3){
            --di;
          }
          setDateTime(seg, min, hor, diasem, di, me, an);
        }
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
      if(estado_hour == true){
        ultima = 4;
      }
      if(estado_botaoE == HIGH){
        if(estado_hour == true){
          estado_hour = false;
          ultima = 5;
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
        if (temp_set + 700 >= millis()){
          if(ultima == 4){
            --hor;
          }
          if(ultima == 5){
            --min;
          }
          setDateTime(seg, min, hor, diasem, di, me, an);
        }
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
  // Paginação display |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
  
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
    if(hor < 10){
      lcd.setCursor(15,2);
      lcd.print(" ");
      lcd.setCursor(16, 2);  
      lcd.print(hor);
    }
    else{
      lcd.setCursor(15, 2);  
      lcd.print(hor);
    }
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(min >= 10){
      lcd.setCursor(18,2);   
      lcd.print(min);
    }
    else{
      lcd.setCursor(18,2);   
      lcd.print("0");
      lcd.setCursor(19,2);   
      lcd.print(min);
    }
    scrollMessage(3, "CONNECT TO ME (SSID: CHILLER) AND SELECT A WIFI CONNECTION (AP IP: 192.168.4.1)", 500, 20);
    
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
    lcd.print("XXXXXXXXXXXXXXXXXXXX"); 
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    if(hor < 10){
      lcd.setCursor(15,2);
      lcd.print(" ");
      lcd.setCursor(16, 2);  
      lcd.print(hor);
    }
    else{
      lcd.setCursor(15, 2);  
      lcd.print(hor);
    }
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(min >= 10){
      lcd.setCursor(18,2);   
      lcd.print(min);
    }
    else{
      lcd.setCursor(18,2);   
      lcd.print("0");
      lcd.setCursor(19,2);   
      lcd.print(min);
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
    lcd.print("XXXXXXXXXXXXXXXXXXXX"); 
    lcd.setCursor(0, 2);
    if(uni_Celc == true) {
      lcd.print(media_tempC);
    }
    else{
      lcd.print(media_tempF);
    }
    if(hor < 10){
      lcd.setCursor(15,2);
      lcd.print(" ");
      lcd.setCursor(16, 2);  
      lcd.print(hor);
    }
    else{
      lcd.setCursor(15, 2);  
      lcd.print(hor);
    }
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(min >= 10){
      lcd.setCursor(18,2);   
      lcd.print(min);
    }
    else{
      lcd.setCursor(18,2);   
      lcd.print("0");
      lcd.setCursor(19,2);   
      lcd.print(min);
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
    if(hor < 10){
      lcd.setCursor(15,2);
      lcd.print(" ");
      lcd.setCursor(16, 2);  
      lcd.print(hor);
    }
    else{
      lcd.setCursor(15, 2);  
      lcd.print(hor);
    }
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(min >= 10){
      lcd.setCursor(18,2);   
      lcd.print(min);
    }
    else{
      lcd.setCursor(18,2);   
      lcd.print("0");
      lcd.setCursor(19,2);   
      lcd.print(min);
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
    if(hor < 10){
      lcd.setCursor(15,2);
      lcd.print(" ");
      lcd.setCursor(16, 2);  
      lcd.print(hor);
    }
    else{
      lcd.setCursor(15, 2);  
      lcd.print(hor);
    }
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(min >= 10){
      lcd.setCursor(18,2);   
      lcd.print(min);
    }
    else{
      lcd.setCursor(18,2);   
      lcd.print("0");
      lcd.setCursor(19,2);   
      lcd.print(min);
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
    if(hor < 10){
      lcd.setCursor(15,2);
      lcd.print(" ");
      lcd.setCursor(16, 2);  
      lcd.print(hor);
    }
    else{
      lcd.setCursor(15, 2);  
      lcd.print(hor);
    }
    lcd.setCursor(17,2);   
    lcd.print(":");
    if(min >= 10){
      lcd.setCursor(18,2);   
      lcd.print(min);
    }
    else{
      lcd.setCursor(18,2);   
      lcd.print("0");
      lcd.setCursor(19,2);   
      lcd.print(min);
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
    if (an < 10){
      lcd.setCursor(10,3);
      lcd.print("0");
      lcd.setCursor(11,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(an);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    else{
      lcd.setCursor(10,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(an);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH){
      ++an;
      if (an == 100){
        an = 1;
      } 
      setDateTime(seg, min, hor, diasem, di, me, an);
      temp_set = millis();
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
    if (me < 10){
      lcd.setCursor(9,3);
      lcd.print(" ");
      lcd.setCursor(10,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(me);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    else{
      lcd.setCursor(9,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(me);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH){
      ++me;
      if (me == 13){
        me = 1;
      } 
      setDateTime(seg, min, hor, diasem, di, me, an);
      temp_set = millis();
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
    if (di < 10){
      lcd.setCursor(9,3);
      lcd.print(" ");
      lcd.setCursor(10,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(di);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    else{
      lcd.setCursor(9,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(di);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH){
      ++di;
      if (di == 32){
        di = 1;
      } 
      setDateTime(seg, min, hor, diasem, di, me, an);
      temp_set = millis();
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
    if(hor < 10){
      lcd.setCursor(8,3);
      lcd.print(" ");
      lcd.setCursor(9,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(hor);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    else{
      lcd.setCursor(8,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(hor);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    lcd.setCursor(10,3);
    lcd.print(":");
    lcd.setCursor(11,3);
    lcd.print(min);
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH){
      ++hor;
      if (hor == 24){
        hor = 0;
      }
      setDateTime(seg, min, hor, diasem, di, me, an); 
      temp_set = millis();
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
    if(hor < 10){
      lcd.setCursor(9, 3);  
      lcd.print(hor);
    }
    else{
      lcd.setCursor(8, 3);  
      lcd.print(hor);
    }
    lcd.setCursor(10,3);
    lcd.print(":");
    if(min < 10){
      lcd.setCursor(11,3);
      lcd.print("0");
      lcd.setCursor(12,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(min);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    else{
      lcd.setCursor(11,3);
      if (millis() - blinkTime > 2000) {
        lcd.print(min);
        blinkTime = millis();
      }
      if (millis() - blinkTime > 1000) {
        lcd.print(placeHolder);
      }
    }
    lcd.setCursor(18,3);
    lcd.print("->");
    if (estado_botaoD == HIGH){
      ++min;
      if (min == 60){
        min = 0;
      } 
      setDateTime(seg, min, hor, diasem, di, me, an);
      temp_set = millis();
    }
  }
  if (estado_saved == true){
    //estado_saved = false;
    temp_iniRefresh = tempo_atual;
    if(millis() == temp_iniRefresh + temp_refresh){
      temp_iniRefresh = 0;
    }
    lcd.setCursor(0, 0);
    lcd.print("NOBIVAC SmartChiller");
    lcd.setCursor(0, 2);
    lcd.print("       Saved        ");
  }
  // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
}

//SERVIDOR: Retorno: data e horário para setar

void setDateTime(int a,int b,int c,int d,int e,int f,int g) {

  byte segundo = a;   // 0-59
  byte minuto = b;    // 0-59
  byte hora = c;      // 0-23
  byte diasemana = d;  // 1-7
  byte dia = e;       // 1-31
  byte mes = f;        // 1-12
  byte ano = g;       // 0-99

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

void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  for (int i=0; i < totalColumns; i++) {
    message = " " + message;
    if(analogRead(sens_porta1) < 1000 || analogRead(bot_esq) > 1000 || analogRead(bot_dir) > 1000){
      break;
    }  
  } 
  message = message + " "; 
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(delayTime);
    if(analogRead(sens_porta1) < 1000 || analogRead(bot_esq) > 1000 || analogRead(bot_dir) > 1000){
      break;
    }  
  }
}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.print(message)){
        Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}