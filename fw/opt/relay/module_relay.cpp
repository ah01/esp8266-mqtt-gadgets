#include "module.h"

#include "mqtt.h"
#include "logger.h"
#include "Arduino.h"

static Logger logger("sonoff");

void module_mqtt_in(String topic, String payload)
{
    Serial.print(">>");
    Serial.print(payload);

    mqtt_publish(topic, payload);
}

void module_setup()
{
    logger.info("setup");
}

void module_loop()
{
    //Serial.println("M: Relay loop");
}
