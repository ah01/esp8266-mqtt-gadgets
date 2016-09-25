#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <PubSubClient.h>

#include <mqtt.h>
#include <logger.h>
#include "module.h"

// -----------------------------------------------------------------------------

WiFiManager wifiManager;

void setup()
{
    Serial.begin(115200);

    LOG("setup begin");

    wifiManager.autoConnect();

    LOGV("Local IP", WiFi.localIP());

    mqtt_setup();
    module_setup();

    LOG("setup done");
}

void loop()
{
    mqtt_loop();
    module_loop();
}
