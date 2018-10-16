#include "PMS3003.h"

PMS3003 pms3003;

void setup()
{
    Serial.begin(9600);
    pms3003.begin();
}

void loop()
{
    PM pm = pms3003.read();

    if (pm.at10 == -1)
    {
        Serial.println("Read failed!");
    }
    else
    {
        Serial.print("CF=1, PM1.0=");
        Serial.print(pm.cf10);
        Serial.println(" ug/m3");

        Serial.print("CF=1, PM2.5=");
        Serial.print(pm.cf25);
        Serial.println(" ug/m3");

        Serial.print("CF=1, PM10=");
        Serial.print(pm.cf100);
        Serial.println(" ug/m3");

        Serial.print("Atmosphere, PM1.0=");
        Serial.print(pm.at10);
        Serial.println(" ug/m3");

        Serial.print("Atmosphere, PM2.5=");
        Serial.print(pm.at25);
        Serial.println(" ug/m3");

        Serial.print("Atmosphere, PM10=");
        Serial.print(pm.at100);
        Serial.println(" ug/m3");

        Serial.println();
    }
    delay(5000);
}
