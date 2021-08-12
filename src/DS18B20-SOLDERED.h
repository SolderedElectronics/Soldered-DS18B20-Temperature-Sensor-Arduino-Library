/**
 **************************************************
 *
 * @file        Generic-easyC-SOLDERED.h
 * @brief       Header file for DS18B20 Sensor control.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     @ soldered.com, Robert Peric
 ***************************************************/

#ifndef _DS18B20_H
#define _DS18B20_H

#include "Arduino.h"
#include "libs/Arduino-Temperature-Control-Library/DallasTemperature.h"
#include "libs/OneWire/OneWire.h"


class DS18B20 : public DallasTemperature
{
  public:
    using DallasTemperature::DallasTemperature;


  protected:
  private:
    int pin;
};

#endif
