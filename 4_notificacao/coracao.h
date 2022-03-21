#define LED_BUILTIN 2 // NOTE: Led padrao da placa 16 ou 2
unsigned long tempoCoracao; // Variavel responsavel por controlar o led
//byte travar_coracao = 0;

void coracao(bool travar_coracao = true){


    if (millis() - tempoCoracao < 2000) { // tempo do led desligado
        digitalWrite(LED_BUILTIN, HIGH);
    }else
        digitalWrite(LED_BUILTIN, LOW);

    if(travar_coracao){
        if (millis() - tempoCoracao > 2050)// tempo do led ligado
            tempoCoracao = millis();
        }else
             digitalWrite(LED_BUILTIN, LOW);
}

