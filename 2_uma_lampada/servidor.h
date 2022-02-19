void ver_estados(){
    stL1 = digitalRead(L1); // 0 ou 1
    stL2 = digitalRead(L2); // 0 ou 1

}

void seta_estados(){

    for (uint8_t i = 0; i < server.args(); i++) {

        if (server.argName(i) == "L1"){
            //stL1 = digitalRead(L1);
            stL1 = !stL1;
            digitalWrite(L1, stL1);

        }
        if (server.argName(i) == "LED2"){
            //stL1 = digitalRead(L1);
            stL2 = !stL2;
            digitalWrite(L2, stL2);

        }

    }

}


void HTML_principal() {

    ver_estados(); // le o estado antes de alterar 1
    seta_estados(); // altera os estados 0
   // ver_estados(); // le o estado antes de exibir 0

    String code = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'/><meta charset='utf-8'><style>body{display:block;justify-content:center;align-items:center;}h2{font-size:20;text-align:center;}#st2{background-color:#01af52;}#st1{background-color:#0a1d9c;}#st0{background-color:#dcdcdc;}a{width:80%; color:white;font-size:50;padding:14px 10%;margin-bottom:10px;text-align:center;text-decoration:none;display:inline-block;}</style><title>Controle de casa</title></head><body><div id='main'><h2>Bem vindo ao Controle!!</h2>";
    code += "<a id='st" +  String(stL1) + "' href='?L1'>LED1</a>";
    code += "<a id='st" +  String(stL2) + "' href='?LED2'>LED2</a>";



    code += "<br></div></body></html>";
    server.send(200, "text/html",code );

}


void handleNotFound() {
    //ver_estados();
    String message = "Pagina Nao Existe!!\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";
    for (uint8_t i = 0; i < server.args(); i++) {
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";

    }


    server.send(404, "text/plain", message);
}
