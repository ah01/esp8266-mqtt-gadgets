#ifndef _logger_h_
#define _logger_h_

//#include <Arduino.h>

#define LOGGER_STREAM Serial

#define LOG(txt) \
    LOGGER_STREAM.print("L: ");\
    LOGGER_STREAM.println(txt);

#define LOGV(txt, value) \
    LOGGER_STREAM.print("L: ");\
    LOGGER_STREAM.print(txt);\
    LOGGER_STREAM.print(" ");\
    LOGGER_STREAM.println(value);

#endif
