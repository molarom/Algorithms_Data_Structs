#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "helpers.h"

static void stripchr(char* restrict s, char c) {
	int j, n = strlen(s);
	for (int i = j = 0; i < n; i++) {
		if (s[i] != c)
		    s[j++] = s[i];
	} 
	s[j] = '\0';
}

// Int arr is malloc'd, caller's responsibility to free.
int* str_to_int(char *str, size_t *arr_len) 
{
	// Remove any whitespace.
	char *tmp_str = strdup(str);
	stripchr(tmp_str, ' ');

	// Set up for realloc.
	int *arr = (int*) calloc(0, sizeof (int*));

	char *token = strtok(tmp_str, ",");
	while (token != NULL) {
		(*arr_len)++;
		arr = realloc(arr, (*arr_len * sizeof (int*)));
		arr[*arr_len - 1] = atoi(token);
		token = strtok(NULL, ",");
	}
	
	free(tmp_str);
	return arr;
}

int* file_to_int(char *f_open, size_t *arr_len)
{
    FILE *fp;

    fp = fopen(f_open, "rb");

    if (fp == NULL) {
        fprintf(stderr, "[%s:%d] Unable to read file: %s\n", __FILE__, __LINE__, f_open);
		exit(EXIT_FAILURE);
	}	

    int str_len = 0;
    char* str = {0};

	fseek(fp, 0, SEEK_END);
	str_len = ftell(fp);
	str = malloc(str_len);

	fseek(fp, 0, SEEK_SET);
	if (!str) {
        fprintf(stderr, "[%s:%d] Unable to allocate buffer: *str\n", __FILE__, __LINE__);
	} else {
		fread(str, 1, str_len, fp);
	}

    fclose(fp);

    int *arr;
    arr = str_to_int(str, arr_len); 

    free(str);
    return arr;
}
