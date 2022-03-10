#define LED_BUILTIN 2 // NOTE: Led padrao da placa 16 ou 2
unsigned long tempoCoracao; // Variavel responsavel por controlar o led

void coracao(){

    if (millis() - tempoCoracao < 2000) { // tempo do led desligado
        digitalWrite(LED_BUILTIN, HIGH);
    }else
        digitalWrite(LED_BUILTIN, LOW);


    if (millis() - tempoCoracao > 2100)// tempo do led ligado
        tempoCoracao = millis();
}
