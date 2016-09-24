#ifndef _logger_h_
#define _logger_h_

//#include <Arduino.h>

#define LOGGER_STREAM Serial
//#define LOGGER_PREFIX "LOG "

/*
void inline log_info(const char *text)
{
    #ifdef LOGGER_PREFIX
        LOGGER_STREAM.print(LOGGER_PREFIX);
    #endif
    LOGGER_STREAM.print("<info> ");
    LOGGER_STREAM.println(text);
}

void inline log_info(const char *text, const char *value)
{
    #ifdef LOGGER_PREFIX
        LOGGER_STREAM.print(LOGGER_PREFIX);
    #endif
    LOGGER_STREAM.print("<info> ");
    LOGGER_STREAM.println(text);
    LOGGER_STREAM.print(" ");
    LOGGER_STREAM.println(value);
}

void inline log_info(const char *text, int value)
{
    #ifdef LOGGER_PREFIX
        LOGGER_STREAM.print(LOGGER_PREFIX);
    #endif
    LOGGER_STREAM.print("<info> ");
    LOGGER_STREAM.println(text);
    LOGGER_STREAM.print(" ");
    LOGGER_STREAM.println(value);
}
*/

class Logger {

private:
    const char* name;

public:

    Logger(const char * name);

    //void error(const char* msg);
    void info(const char* msg);
    
};



#endif
