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

static Logger lo("main");

void setup()
{
    Serial.begin(115200);
    lo.info("Setup begin");

    wifiManager.autoConnect();

    //log_info("Connected");
    //log_info("Local IP", WiFi.localIP());

    mqtt_setup();

    module_setup();
}

void loop()
{
    mqtt_loop();

//    mqtt_in("", "");

    module_loop();
}
