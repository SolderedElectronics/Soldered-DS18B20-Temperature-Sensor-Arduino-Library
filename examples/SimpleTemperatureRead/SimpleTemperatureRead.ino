/**
 **************************************************
 *
 * @file        SimpleTemperatureRead.ino
 * @brief       This example shows simple temperature read from DS18B20 sensor
 *
 *
 *
 * @authors     @ soldered.com, Robert Peric
 * @link        www.solde.red/101203
 ***************************************************/

// Include our library
#include "DS18B20-SOLDERED.h"

// Data wire is plugged into port 11 on the controler
#define ONE_WIRE_BUS 11

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference
DS18B20 sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
    // start serial port
    Serial.begin(9600);
    Serial.println("Temperature IC Control Library Demo");

    // Start up the library
    sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{
    // call sensors.requestTemperatures() to issue a global temperature
    // request to all devices on the bus
    Serial.print("Requesting temperatures...");
    sensors.requestTemperatures(); // Send the command to get temperatures
    Serial.println("DONE");
    // After we got the temperatures, we can print them here.
    // We use the function ByIndex, and as an example get the temperature from the first sensor only.
    float tempC = sensors.getTempCByIndex(0);

    // Check if reading was successful
    if (tempC != DEVICE_DISCONNECTED_C)
    {
        Serial.print("Temperature for the device 1 (index 0) is: ");
        Serial.println(tempC);
    }
    else
    {
        Serial.println("Error: Could not read temperature data");
    }
}