#define LED_PISCA 15 //D4(2) ou D0(16) ou D8(15) colocando led

void pisca (){

  digitalWrite(LED_PISCA, LOW);
  delay(1000);

  digitalWrite(LED_PISCA, HIGH);
  delay(1000);

}
