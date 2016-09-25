#ifndef _logger_h_
#define _logger_h_

//#include <Arduino.h>

#define LOGGER_STREAM Serial

#define LOG(txt) \
    LOGGER_STREAM.print("M: ");\
    LOGGER_STREAM.println(txt);

#define LOGV(txt, value) \
    LOGGER_STREAM.print("M: ");\
    LOGGER_STREAM.print(txt);\
    LOGGER_STREAM.print(" ");\
    LOGGER_STREAM.println(value);


#define CORE_LOG(txt) \
    LOGGER_STREAM.print("C: ");\
    LOGGER_STREAM.println(txt);

#define CORE_LOGV(txt, value) \
    LOGGER_STREAM.print("C: ");\
    LOGGER_STREAM.print(txt);\
    LOGGER_STREAM.print(" ");\
    LOGGER_STREAM.println(value);

#endif
