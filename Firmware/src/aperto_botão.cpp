int botao = GPIO X;

long tempo_ult_debouce = 0;
long delay_debouce = 10;

int est_ini_bot = 0;

bool prim_press = true;

void setup(){
    pinMode(botao, OUTPUT);
}
void loop(){
    if(digitalRead(botao) == HIGH && est_ini_bot == 0){
        if((millis() - tempo_ult_debouce) > delay_debouce){
            est_ini_bot = 1; //pressionado
            tempo_ult_debouce = millis();
        }
    }
    else{
        if(est_ini_bot == 1 && digitalRead(botao) == LOW){
            est_ini_bot = 0;
            prim_press = true;
        }
    }
    if(est_ini_bot == 1 && prim_press == true){ //botão foi pressionado uma vez
        prim_press = false;
    }
}

/*LIGA DEIGA
int botao = 2;
int LED = 10;

long tempo_ult_debouce = 0;
long delay_debouce = 10;
unsigned long tempo_fporta1 = 0;

int est_ini_bot = 0;
int estado_botao = LOW;

int prim_press = 1;

void setup(){
  Serial.begin(9600);
  pinMode(botao, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4,HIGH);
}
void loop(){
  if(digitalRead(botao) == HIGH && est_ini_bot == 0){
    if((millis() - tempo_ult_debouce) > delay_debouce){
      est_ini_bot = 1; //pressionado
      digitalWrite(LED, HIGH);
      tempo_ult_debouce = millis();
        }
    }
  else{
    if(est_ini_bot == 1 && digitalRead(botao) == LOW){
      digitalWrite(LED, LOW);
      est_ini_bot = 0;
      prim_press = 1;
        }
    }
  if(est_ini_bot == 1 && prim_press == 1){   //condição do botão pressionado 
    prim_press = 0;
    if(estado_botao==LOW){   //se estiver em estado LOW
      estado_botao=HIGH;    //mudar para estado HIGH
            }   
    else if(estado_botao==HIGH){                    //condição botão não pressionado
      estado_botao=LOW;     //mudar de estado HIGH para estado LOW
            }
        }
    if(estado_botao==HIGH){
      digitalWrite(LED, HIGH);
    }
    else if(estado_botao==LOW){
      digitalWrite(LED, LOW);
    }
    
}

*/