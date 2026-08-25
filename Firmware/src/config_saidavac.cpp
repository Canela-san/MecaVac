int input = 34;
int leitura = 0;

void setup(){
    pinMode(input,INPUT);
    Serial.begin(115200);
}

void loop(){
    leitura = analogRead(input);
    Serial.println(leitura);
    delay(500);
}