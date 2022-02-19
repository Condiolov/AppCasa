#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include "../../senha.h" // REMOVA O "../../" E EDITE O "senha.h" COM NOME SENHA
#include <ESP8266WebServer.h>
//#include "./pisca.h"
#include "ota.h"  //Responsavel por habilitar o recebimento de binario


ESP8266WebServer server(80); //porta web padrao

int stL1 = 0;
int stL2 = 1;


int L1 = 13; // NOTE: Algumas porta são acionadas ao iniciar o esp, isso pode ser ruim pra uma automação!!
int L2 = 15;

#include "coracao.h"
#include "servidor.h"

void setup() {
    config_ota(); // ota.h

    pinMode(LED_BUILTIN, OUTPUT);     //  pinMode(LED_BUILTIN, OUTPUT);
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);


    // pagina web principal da placa
    server.on("/", HTML_principal);
    server.onNotFound(handleNotFound);
    server.begin();
}

void loop() {
    ArduinoOTA.handle(); // ota.h
    coracao(); //coracao.h
    server.handleClient();

}
