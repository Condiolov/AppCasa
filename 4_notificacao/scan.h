#include <Wire.h>
String resultado_scan ="";
void scan()
{
    Wire.begin();
    byte error, address;
    int nDevices;

    nDevices = 0;
    for(address = 1; address < 127; address++ )
    {

        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            resultado_scan += String(nDevices + 1, DEC);
            resultado_scan +=" - CI endereco: 0x";

            if (address<16) resultado_scan +="0" ;

            resultado_scan += String(address, HEX); // HEX
            resultado_scan += "  ! <br> ";

            nDevices++;
        }
        else if (error==4)
        {
            resultado_scan +="Erro no endereco 0x";
            if (address<16) resultado_scan +="0";

            resultado_scan += String(address, HEX); // HEX
        }
    }
    if (nDevices == 0)
        resultado_scan += "<br><br>SEM CI!!";
    else
        resultado_scan += "<br><br> Scan completo ok!!";

    //delay(5000);           // wait 5 seconds for next scan

    server.send(200, "text/html",resultado_scan );
    resultado_scan="";
    //delay(5000);

}
