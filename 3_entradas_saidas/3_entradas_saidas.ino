/*
 * 3 - EXPANSOR DE ENTRADAS E SAIDAS
 *
 * AUTOR:   Thiago Condé
 * VERSION: 1.0
 * PLACA:   ESP8266
 * EDITOR:  KATE EDITOR
 * DATA:    06/03/2022
 *
 */

#include <ESP8266WiFi.h> // responsavel conexão wifi  ESP -> WIFI
#include <ArduinoOTA.h>  // Para atualizar o ESP   Editor -> ESP
#include "../../senha.h" // REMOVA O "../../" E EDITE O "senha.h" COM NOME SENHA
#include <ESP8266WebServer.h> // torna o esp um webservior WEB -> ESP
#include <PCF8574.h> // NOTE: /Arduino/esp8266/libraries/ https://github.com/xreef/PCF8574_library


PCF8574 ci_1(0x38); // se não souber o endereço do PCF8574 use o scan
PCF8574 ci_2(0x3a);

#include "./ota.h"



int stP0, stP0ci2;

#include "./coracao.h"
#include "./servidor.h"
#include "./scan.h"// NOTE: descomente apenas se for usar o scaner de CI
void setup() {
    config_ota(); // ota.h

    pinMode(LED_BUILTIN, OUTPUT);     //  pinMode(LED_BUILTIN, OUTPUT);
    server.on("/", HTML_principal);
    server.on("/scan", scan); // NOTE: descomente apenas se for usar o scaner de CI, acesso http://ip_do_ESP/scan
    server.onNotFound(handleNotFound);
    server.begin();



    // Exemplo de SAIDA
    ci_1.pinMode(P0, OUTPUT);
    ci_1.begin();

    //Exemplo de ENTRADAS
    ci_2.pinMode(P0, INPUT);
    ci_2.begin();

}

void loop() {

    server.handleClient(); // Habilito o Servidor
    coracao(); // coracao.h
    ArduinoOTA.handle(); // Habilito o ota.h
}
