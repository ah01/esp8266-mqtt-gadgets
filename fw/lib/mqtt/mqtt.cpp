#include "mqtt.h"

#define MQTT_KEEPALIVE 30

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <logger.h>

const char* mqtt_server = "mqtt.sh.cvut.cz";

#define MQTT_TOPIC_PREFIX "/adam/";

#define MQTT_USER NULL
#define MQTT_PASS NULL

#define MQTT_LIVE_TOPIC "online"

static unsigned int mqtt_prefix_len;

WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);

void callback(char* topic, byte* payload, unsigned int length) {

    CORE_LOGV("MQTT message ", topic);

    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }

    Serial.println();

  if (strlen(topic) <= mqtt_prefix_len) {
      return;
  }

  char* x = topic + mqtt_prefix_len;

  String s = String(x);
  String p = String();

  p.reserve(length + 1);

  for(unsigned int i = 0; i < length; i++)
  {
      Serial.print(i);
      Serial.print(" ");
      Serial.println(payload[i], DEC);

      p += (char)payload[i];
  }

  p.setCharAt(length, 0);

  Serial.println(s);
  Serial.println(p);

  module_mqtt_in(s,p);
}

void reconnect() {

    while (!mqtt.connected()) {

        CORE_LOG("MQTT Attempting connection");

        // Create a random client ID
        String clientId = "ESP8266Client-";
        clientId += String(random(0xffff), HEX);

        String willTopic = MQTT_TOPIC_PREFIX;
        willTopic += ESP.getChipId();
        willTopic += "/$status";

        // Attempt to connect
        // boolean connect(const char* id, const char* user, const char* pass, const char* willTopic, uint8_t willQos, boolean willRetain, const char* willMessage);
        if (mqtt.connect(clientId.c_str(), MQTT_USER, MQTT_PASS, willTopic.c_str(), MQTTQOS0, true, "offline")) {
            CORE_LOG("MQTT Connected");

            mqtt.publish(willTopic.c_str(), "online", true);



            String inTopic = MQTT_TOPIC_PREFIX;
            inTopic += ESP.getChipId();
            inTopic += "/in/#";

            mqtt.subscribe(inTopic.c_str());
            mqtt_prefix_len = inTopic.length() - 1;
            Serial.print("Subs ");
            Serial.println(inTopic);

        } else {
            Serial.print("failed, rc=");
            Serial.print(mqtt.state());
            Serial.println(" try again in 5 seconds");

            // TODO make this non-blocking
            delay(5000);
        }
    }
}


void mqtt_setup()
{
    //lo.info("MQTT server", mqtt_server);

    mqtt.setServer(mqtt_server, 1883);
    mqtt.setCallback(callback);
}

unsigned long uptime_message_time = 0;

const int uptime_message_interval = 1000;

void mqtt_loop()
{
    if (!mqtt.connected()) {
        reconnect();
    }

    mqtt.loop();

    if (millis() - uptime_message_time > uptime_message_interval)
    {
        uptime_message_time = millis();

        mqtt_publish_sys("$uptime", (unsigned long)uptime_message_time / 1000);
        mqtt_publish_sys("$heap", ESP.getFreeHeap());
    }
}


void mqtt_publish(const char* topic, float value)
{
    String t = MQTT_TOPIC_PREFIX;
    t += ESP.getChipId();
    t += "/out/";
    t += topic;

    String p = String(value);

    mqtt.publish(t.c_str(), p.c_str());

    yield();
}

void mqtt_publish_sys(const char* topic, unsigned long value)
{
    String t = MQTT_TOPIC_PREFIX;
    t += ESP.getChipId();
    t += "/";
    t += topic;

    String p = String(value);

    mqtt.publish(t.c_str(), p.c_str());

    yield();
}

void mqtt_publish(String topic, String value)
{
    String t = MQTT_TOPIC_PREFIX;
    t += ESP.getChipId();
    t += "/out/";
    t += topic;

    mqtt.publish(t.c_str(), value.c_str());

    yield();
}
