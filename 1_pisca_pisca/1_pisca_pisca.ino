#include <ESP8266WiFi.h> // responsavel pela conexão wifi
#include <ArduinoOTA.h>  // responsavel por subir o binario

#include "../../senha.h" // REMOVA O "../../" E EDITE O "senha.h" COM NOME SENHA
//#include "senha.h"
#include "pisca.h"
#include "ota.h"


void setup() {
    config_ota(); // ota.h
    pinMode(LED_PISCA, OUTPUT);     //  pinMode(LED_BUILTIN, OUTPUT);
    // se acabou a luz, se o ESP reiniciou.
}

void loop() {

    pisca(); //pisca.h
    ArduinoOTA.handle(); // ota.h
}
