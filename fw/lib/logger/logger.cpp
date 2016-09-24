#include "logger.h"

#include <Arduino.h>

Logger::Logger(const char * name)
{
    this->name = name;
}

void Logger::info(const char *msg)
{
    LOGGER_STREAM.print("I: ");
    LOGGER_STREAM.println(msg);
}
