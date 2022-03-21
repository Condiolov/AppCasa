ESP8266WebServer server(80);


void ver_estados(){
    //delay(10);
    stP0ci2 = ci_2.digitalRead(P0,true);

   // delay(100);
    stP0 = !ci_1.digitalRead(P0); // read P0 // stP0 = !digitalRead(P0)
}

void seta_estados(){
    for (uint8_t i = 0; i < server.args(); i++) {

        if (server.argName(i) == "P0"){
            ci_1.digitalWrite(P0,stP0);

        }


    }
}


void HTML_principal() {


    ver_estados(); // le o estado antes de alterar
    seta_estados(); // altera os estados
    ver_estados(); // le o estado antes de exibir



    String code = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'/><meta charset='utf-8'><style>body{display:block;justify-content:center;align-items:center;}h2{font-size:20;text-align:center; color:#000;}#st2{background-color:#01af52;}#st1{background-color:#0a1d9c;}#st0{background-color:#dcdcdc;}a{width:80%; color:#fff;font-size:50;padding:14px 10%;margin-bottom:10px;text-align:center;text-decoration:none;display:inline-block;}</style><title>Controle de casa</title></head><body><div id='main'><a href='/'><h2>Bem vindo ao Controle!!</h2></a>";
    code += "<a id='st" +  String(stP0) + "' href='?P0'>LAMPADA</a>";

    code += "<br> stP0ci2:" +  String(stP0ci2) + "<br>";

    code += "<br></div></body></html>";
    server.send(200, "text/html",code );


}


void handleNotFound() {
    //ver_estados();
    String message = "File nnot  Found\n\n";
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
