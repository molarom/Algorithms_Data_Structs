#ifndef PARSING_H
#define PARSING_H

#include <stddef.h>

int* str_to_int(char *str, size_t *arr_len);
int* file_to_int(char *f_open, size_t *arr_len);

#endif
