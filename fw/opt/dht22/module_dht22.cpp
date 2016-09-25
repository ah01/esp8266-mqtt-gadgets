#include "module.h"

#include "Arduino.h"
#include "logger.h"
#include "DHT.h"
#include "mqtt.h"

#define DHTPIN 2

#ifndef DHTTYPE
    #define DHTTYPE DHT11
#endif

#define BTNPIN 0

DHT dht(DHTPIN, DHTTYPE);

unsigned long time = 0;
unsigned long interval = 10;

void module_mqtt_in(String topic, String payload)
{
    if (topic != "interval")
    {
        return;
    }

    long i = payload.toInt();

    LOGV("Interval", i);

    if (i <= 0 || i > 3600)
    {
        LOG("Interval out of range");
        mqtt_publish("error", "Interval out of range (1 - 3600)");
        return;
    }

    interval = i;

    mqtt_publish("interval", i);
}

void module_setup()
{
    LOG("DHT22 setup");

    dht.begin();
}


void module_loop()
{
    if (millis() - time < interval * 1000) {
        return;
    }

    time = millis();

    LOG("M: DHT22 loop");

    float h = dht.readHumidity();
    yield();

    float t = dht.readTemperature();
    yield();

    if (isnan(h) || isnan(t)) {
        LOG("Failed to read from DHT sensor!");
        return;
    }

    Serial.print(t);
    Serial.print("; ");
    Serial.println(h);

    mqtt_publish("temperature", t);
    mqtt_publish("humidity", h);
}
