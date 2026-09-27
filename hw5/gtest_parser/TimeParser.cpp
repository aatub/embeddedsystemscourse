#include "TimeParser.h"
#include <cstring>
#include <cctype>
#include <cstdlib>

int time_parse(const char *time_str) {
    if (time_str == nullptr) return ERROR_NULL_POINTER;
    if (std::strlen(time_str) != 6) return ERROR_INVALID_FORMAT;
    for (int i = 0; i < 6; i++) {
        if (!std::isdigit(static_cast<unsigned char>(time_str[i]))) {
            return ERROR_INVALID_FORMAT;
        }
    }

    char h_str[3] = { time_str[0], time_str[1], '\0' };
    char m_str[3] = { time_str[2], time_str[3], '\0' };
    char s_str[3] = { time_str[4], time_str[5], '\0' };
    int hours = std::atoi(h_str);
    int minutes = std::atoi(m_str);
    int seconds = std::atoi(s_str);

    if (hours < 0 || hours > 23) return ERROR_INVALID_HOURS;
    if (minutes < 0 || minutes > 59) return ERROR_INVALID_MINUTES;
    if (seconds < 0 || seconds > 59) return ERROR_INVALID_SECONDS;

    return (minutes * 60) + seconds;
}
