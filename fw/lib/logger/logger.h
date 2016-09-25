#ifndef _logger_h_
#define _logger_h_

#include <Arduino.h>

const char LOGGER_CORE_PREFIX[] PROGMEM = "C: ";
const char LOGGER_MODULE_PREFIX[] PROGMEM = "M: ";

#define LOGGER_STREAM Serial

// --- Logger for MODULES ---

#define LOG(txt) \
    LOGGER_STREAM.print(FPSTR(LOGGER_CORE_PREFIX));\
    LOGGER_STREAM.println(F(txt));

#define LOGV(txt, value) \
    LOGGER_STREAM.print(FPSTR(LOGGER_CORE_PREFIX));\
    LOGGER_STREAM.print(F(txt));\
    LOGGER_STREAM.print(F(" "));\
    LOGGER_STREAM.println(value);

// --- Logger for CORE ---

#define CORE_LOG(txt) \
    LOGGER_STREAM.print(FPSTR(LOGGER_MODULE_PREFIX));\
    LOGGER_STREAM.println(F(txt));

#define CORE_LOGV(txt, value) \
    LOGGER_STREAM.print(FPSTR(LOGGER_MODULE_PREFIX));\
    LOGGER_STREAM.print(F(txt));\
    LOGGER_STREAM.print(F(" "));\
    LOGGER_STREAM.println(value);

#endif
