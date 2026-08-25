int luz_interna = 15;
int RGBverde = 26;
int RGBvermelho = 25;
int sens_porta1 = 14;
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
long delay_alarme = 3000;
unsigned long tempo_alarme = 0; 
unsigned long tempo_atual = 0;

void setup() {
  
    pinMode(sens_porta1, INPUT);
    pinMode(luz_interna, OUTPUT);
    pinMode(alarme, OUTPUT);
    pinMode(RGBverde, OUTPUT);
    pinMode(RGBvermelho, OUTPUT);
    pinMode(botao_AP, INPUT);
    Serial.begin(9600);
}

void loop() {
  
    tempo_atual = millis();
    if (analogRead(sens_porta1) < 4000 && est_ini_por1 == 0){  //detecção abertura porta 1
        if ((millis() - tempo_ult_debouce1) > delay_debouce1){
            est_ini_por1 = 1; // aberta
            tempo_ult_debouce1 = millis();
        }
    }
    else{
        if (est_ini_por1 == 1 && analogRead(sens_porta1) > 4000){
            est_ini_por1 = 0; // fechada
            prim_press2 = 1;
            prim_press4 = 1;
        }
    }

    if (analogRead(sens_porta1) > 4000 && est_ini_por4 == 0){  //detecção fechamento porta 1
        if ((millis() - tempo_ult_debouce4) > delay_debouce4){
            est_ini_por4 = 1; // fechada
            tempo_ult_debouce4 = millis();
        }
    }
    else{
        if (est_ini_por4 == 1 && analogRead(sens_porta1) < 4000){
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
    //Serial.println(digitalRead(botao_AP));
    Serial.println(analogRead(botao_AP));
}
