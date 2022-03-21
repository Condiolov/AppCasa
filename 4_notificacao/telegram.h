WiFiClientSecure client;

//const uint8_t fingerprint[20] = { 0xF2, 0xAD, 0x29, 0x9C, 0x34, 0x48, 0xDD, 0x8D, 0xF4, 0xCF, 0x52, 0x32, 0xF6, 0x57, 0x33, 0x68, 0x2E, 0x81, 0xC1, 0x90 }; //impressao digital da api do telegram

void telegram(String notif){
    //  Serial.println("Entrou telegram!!!");
    coracao(0);  // mostra um acesso de função demorado
    const char* host = "api.telegram.org";
    client.setFingerprint(fingerprint);
    // client.setInsecure();

    if (!client.connect(host, 443)) {
        //   Serial.println("Conexão falhou ERRO TELEGRAM");
        return;
    }

    //Serial.println(url+ notif );
    String url = "/bot" + String(token_bot)+ "/sendMessage?chat_id="+String(chat_id)+"&text="; // EDITE O ARQUIVO senha.h
    client.print(String("GET ") + url + notif + " HTTP/1.1\r\n" +
    "Host: " + host + "\r\n" +
    "User-Agent: ESP8266\r\n" +
    "Connection: close\r\n\r\n");
    while (client.connected()) {
        String line = client.readStringUntil('\n');
        if (line == "\r") {
            //     Serial.println("Recebido com Sucesso!!");
            break;
        }
    }
    String line = client.readStringUntil('\n');

    if (line.startsWith("{\"ok\":true")) {
        //     Serial.println("Registrado com Sucesso!!");
    } else {
        //     Serial.println("Não registrado");
        //     Serial.println(line);
    }

}

