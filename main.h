#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int switch_num(va_list arg, char symbol, int length);
int switch_char(va_list arg, char symbol, int length);
int print_char(va_list, int *);
int print_string(va_list, int *, char);
int print_num(va_list, int *, char);
char *num_converter(unsigned int, unsigned int *);
char *hex_converter(unsigned int, unsigned int *, char);
int count_digits(unsigned int, unsigned int *);
int out_num(char *, int, int *);
char *bnten(int, char, unsigned int *);
void rev_string(char *, int);
char *rot13(char *, int);

#endif
