/*
 * 4 - NOTIFICAÇÕES
 *
 * AUTOR:   Thiago Condé
 * VERSION: 1.0
 * PLACA:   ESP8266
 * EDITOR:  KATE EDITOR
 * DATA:    15/03/2022
 *
 */

#include <ESP8266WiFi.h> // responsavel conexão wifi  ESP -> WIFI
#include <ArduinoOTA.h>  // Para atualizar o ESP   Editor -> ESP
#include "../../senha.h" // REMOVA O "../../" E EDITE O "senha.h" COM NOME SENHA
#include <ESP8266WebServer.h> // torna o esp um webservior WEB -> ESP
#include <PCF8574.h> // NOTE: /Arduino/esp8266/libraries/ https://github.com/xreef/PCF8574_library
#include <WiFiClientSecure.h> //NOVIDADE: ESP cliente -> telegram

PCF8574 ci_1(0x38); // se não souber o endereço do PCF8574 use o scan
PCF8574 ci_2(0x3a);

#include "./ota.h"



int stP0, stP0ci2, stP4, stP5;
String status = "";
unsigned long data_carta, data_campainha;
int st_carta, st_campainha;

#include "./coracao.h" //NOVIDADE // funcionalidade de travar o coração
#include "./servidor.h"
//#include "./scan.h"// NOTE: descomente apenas se for usar o scaner de CI
#include "./telegram.h" //NOVIDADE
#include "./notificacao.h" //NOVIDADE

void setup() {
    config_ota(); // ota.h

    pinMode(LED_BUILTIN, OUTPUT);     //  pinMode(LED_BUILTIN, OUTPUT);
    server.on("/", HTML_principal);
    //  server.on("/scan", scan); // NOTE: descomente apenas se for usar o scaner de CI, acesso http://ip_do_ESP/scan
    server.onNotFound(handleNotFound);
    server.begin();

    tone(PIN_D5, 660);
    delay(100);
    noTone(PIN_D5);

    // Ci 1
    ci_1.pinMode(P0, OUTPUT);
    ci_1.pinMode(P4, INPUT);
    ci_1.pinMode(P5, INPUT);
    ci_1.begin();

    //Ci 2
    ci_2.pinMode(P0, INPUT);
    ci_2.begin();

}

void loop() {


    notificacao(); // campainha notifica telegram ->  telegram.h

    server.handleClient(); // ativa o modo servidor -> servidor.h

    coracao(); // led piscante indica o funcionamento -> coracao.h

    ArduinoOTA.handle(); // permite o envio do binario via ip -> ota.h



}
