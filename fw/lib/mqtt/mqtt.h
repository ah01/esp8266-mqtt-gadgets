#ifndef _mqtt_h_
#define _mqtt_h_

#include <Arduino.h>

void mqtt_setup();
void mqtt_loop();

void mqtt_publish(const char* topic, float value);
void mqtt_publish_sys(const char* topic, unsigned long value);
void mqtt_publish(String topic, String value);

extern void module_mqtt_in(String a, String b);

#endif
