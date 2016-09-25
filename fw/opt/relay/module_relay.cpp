#include "module.h"

#include "mqtt.h"
#include "logger.h"
#include "Arduino.h"


void module_mqtt_in(String topic, String payload)
{
    Serial.print(">>");
    Serial.print(payload);

    mqtt_publish(topic, payload);
}

void module_setup()
{
    
}

void module_loop()
{
    //Serial.println("M: Relay loop");
}
