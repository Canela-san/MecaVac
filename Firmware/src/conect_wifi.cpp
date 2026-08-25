#include <DNSServer.h> 
#include <ESPAsyncWebServer.h>
#include <ESPAsyncWiFiManager.h>   
#include <WiFi.h>
 
AsyncWebServer server(80); //Cria os objetos dos servidores
DNSServer dns;

void setup() {
  AsyncWiFiManager manager(&server, &dns); //Cria o objeto do gerenciador
  Serial.begin(115200); //Inicia o monitor serial
  Serial.println(); // Imprime o endereço de IP que teremos que entrar no navegador
  manager.resetSettings(); //Reseta as configurações do gerenciador
  manager.autoConnect("SmartChiller"); //Cria o ponto de acesso com o nome RefriVac 
  Serial.println("Conectado"); //Imprime a mensagem de confirmação
}
 
void loop() {

//if (WiFi.status() != WL_CONNECTED) { //Verifica se existe alguma conexão
//  WiFi.disconnect();  //Caso negativo, confirma a desconexão
//  WiFi.reconnect(); //Tenta uma reconexão
}//}