#ifndef PRINTING
#define PRINTING
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
int print_char(char c);
int _printf(const char *format, ...);
int _len(const char *str);
void print_str(char *str);
int print_number(int num);
#endif

