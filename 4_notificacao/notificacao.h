unsigned long tempoBaseCAMP =0;
unsigned long tempoPressCAMP = 0; // Variável responsavel por controlar o Erro Bounce (Apenas 1 comando)
int tocarSom = 0;

int stPIN_D4 = 0; // tempo para estabilizar e minimizar o efeito bouncing
int stPIN_D5 = 0; // tempo para estabilizar e minimizar o efeito bouncing

int tempoErro = 30; // 1000 tempo para estabilizar e minimizar o efeito bouncing
const int PIN_D5 = 14; //D5 sirene

void campainha (){
    stP4 = ci_1.digitalRead(P4); // vejo o estado da campainha

    // if (digitalRead(PIN_D5)) { //quando liga o botão 3.3v no pino D8
    if ((stP4 == 1) && (tocarSom == 0)){
        stPIN_D4=1; // marca que foi precionado!
        tempoPressCAMP = millis(); // Reinicia a temporização que valida um unico comando!!
        Serial.print("P4 ");
    }
    // detectar apenas um comando!!
    if (((millis() - tempoPressCAMP) >= tempoErro) && stPIN_D4) {
        //Serial.println("Campanhia");
        tocarSom=1; // função de fazer o led pisca, detalhe sem dalay!!
        tempoBaseCAMP = millis();
        stPIN_D4 = 0; // zera o estado para uma nova chamada
    }

    if(tocarSom == 1){
        if (millis() - tempoBaseCAMP < 1000)
            tone(PIN_D5, 660);
        else  if (millis() - tempoBaseCAMP < 1000+1000)
            tone(PIN_D5, 550);
        else  if (millis() - tempoBaseCAMP < 1000+1000+1000)
            tone(PIN_D5, 440);
        else  if (millis() - tempoBaseCAMP > 1000+1000+1000+500){
            noTone(PIN_D5);
            tocarSom = 0;
            data_campainha =  millis();
            st_campainha = 2;
            telegram("🔔 -> Campainha tocou !!");
            status +=  ",\"campainha\":[" + String(data_campainha) + ",2]";
        }
    }
}

void carta(){
    stP5 = ci_1.digitalRead(P5); // verifico se chegou carta

    if ((stP5 == 1) && (tocarSom == 0)){
        stPIN_D5=1; // marca que foi precionado!
        tempoPressCAMP = millis(); // Reinicia a temporização que valida um unico comando!!
       // Serial.print("P5 ");
    }
    // detectar apenas um comando!!
    if (((millis() - tempoPressCAMP) >= tempoErro) && stPIN_D5) {
        //Serial.println("Campanhia");
        tocarSom=2; // função de fazer o led pisca, detalhe sem dalay!!
        tempoBaseCAMP = millis();
        stPIN_D5 = 0; // zera o estado para uma nova chamada
    }

    if(tocarSom == 2){
        if (millis() - tempoBaseCAMP < 200)
            tone(PIN_D5, 1000);
        else  if (millis() - tempoBaseCAMP < 200+100)
            noTone(PIN_D5);
        else  if (millis() - tempoBaseCAMP < 200+100+200)
            tone(PIN_D5, 1000);
        else  if (millis() - tempoBaseCAMP > 200+100+200+200)
        {
            noTone(PIN_D5);
            tocarSom = 0;
             data_carta =  millis();
             st_carta = 2;
            status +=  ",\"carta\":[" + String(millis()) + ",2]";
            telegram("📩 -> Chegou Carta !!");

        }
    }

}

void notificacao(){
    carta();
    campainha();

}
