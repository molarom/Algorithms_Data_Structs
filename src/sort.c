#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "sort.h"

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
		++(*arr_len);
		arr = realloc(arr, (*arr_len * sizeof (int*)));
		//printf("token = %s arr_len = %zu\n", token, *arr_len);
		arr[*arr_len - 1] = atoi(token);
		token = strtok(NULL, ",");
	}
	
	free(tmp_str);
	return arr;
}

static int binary_search(int *a, int item, int low, int high)
{
	if (low >= high)
		return (item > a[low]) ? (low +1): low;

	int mid = low + (high - 1) / 2;
	if (a[mid] == item)
		return mid + 1;
	else if (a[mid] > item)
		return binary_search(a, item, low, mid - 1);
	else 
		return binary_search(a, item, mid + 1, high);
}

void binary_insertion_sort(int *a, int n)
{
	int i, loc, j, selected;

	for (i = 1; i < n; ++i) {
		j = i - 1;
		selected = a[i];

		loc = binary_search(a, selected, 0, j);

		while (j >= loc) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}
