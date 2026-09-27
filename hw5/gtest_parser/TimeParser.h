#ifndef TIMEPARSER_H
#define TIMEPARSER_H

#define PARSE_SUCCESS           0
#define ERROR_INVALID_FORMAT   -1
#define ERROR_INVALID_HOURS    -2
#define ERROR_INVALID_MINUTES  -3
#define ERROR_INVALID_SECONDS  -4
#define ERROR_NULL_POINTER     -5

#ifdef __cplusplus
extern "C" {
#endif

int time_parse(const char *time_str);

#ifdef __cplusplus
}
#endif

#endif
