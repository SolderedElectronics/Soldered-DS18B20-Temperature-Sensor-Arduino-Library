/**
 **************************************************
 *
 * @file        MultibusSimple.ino
 * @brief       This example shows simple multibus control
 *
 *
 *
 * @authors     @ soldered.com, Robert Peric
 * @link        www.solde.red/101203
 ***************************************************/


#include "DS18B20-SOLDERED.h"

OneWire ds18x20[] = {3, 7};
const int oneWireCount = sizeof(ds18x20) / sizeof(OneWire);
DS18B20 sensor[oneWireCount];

void setup(void)
{
    // start serial port
    Serial.begin(9600);
    Serial.println("Multiple Bus Control Library Simple Demo");
    Serial.print("============Ready with ");
    Serial.print(oneWireCount);
    Serial.println(" Sensors================");

    // Start up the library on all defined bus-wires
    DeviceAddress deviceAddress;
    for (int i = 0; i < oneWireCount; i++)
    {
        ;
        sensor[i].setOneWire(&ds18x20[i]);
        sensor[i].begin();
        if (sensor[i].getAddress(deviceAddress, 0))
            sensor[i].setResolution(deviceAddress, 12);
    }
}

void loop(void)
{
    // call sensors.requestTemperatures() to issue a global temperature
    // request to all devices on the bus
    Serial.print("Requesting temperatures...");
    for (int i = 0; i < oneWireCount; i++)
    {
        sensor[i].requestTemperatures();
    }
    Serial.println("DONE");

    delay(1000);
    for (int i = 0; i < oneWireCount; i++)
    {
        float temperature = sensor[i].getTempCByIndex(0);
        Serial.print("Temperature for the sensor ");
        Serial.print(i);
        Serial.print(" is ");
        Serial.println(temperature);
    }
    Serial.println();
}