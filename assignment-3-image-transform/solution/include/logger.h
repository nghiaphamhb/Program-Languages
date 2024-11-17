#ifndef LOGGER
#define LOGGER

#include <stdint.h>
#include <stdio.h>

void log_info(int code, const char* argv);
void log_success();
void print_usage(const char *program_name);
#endif 