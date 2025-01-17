#ifndef PRINTING
#define PRINTING
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
int print_char(char c);
int _printf(const char *format, ...);
int print_str(char *str);
int print_number(int num);
int check_format0(char specifier, va_list args);
int check_format(char specifier, va_list args);
int print_binary(unsigned int n);
int print_unsig(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
#endif
