#include "module.h"

#include "mqtt.h"
#include "logger.h"
#include "Arduino.h"

void module_mqtt_in(String topic, String payload)
{
}

void module_setup()
{
    Serial.println("M: Relay setup");
}

void module_loop()
{
    Serial.println("M: Relay loop");
}
