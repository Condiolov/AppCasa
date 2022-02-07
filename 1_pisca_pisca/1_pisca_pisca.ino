#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "./senha.h"
#include "./pisca.h"
#include "./ota.h"


void setup() {
    config_ota(); // ota.h
    pinMode(LED_PISCA, OUTPUT);     //  pinMode(LED_BUILTIN, OUTPUT);
    // se acabou a luz, se o ESP reiniciou.
}

void loop() {
    
    pisca(); //pisca.h
    ArduinoOTA.handle(); // ota.h
}
