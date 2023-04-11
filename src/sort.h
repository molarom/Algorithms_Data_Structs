#ifndef SORT_H_
#define SORT_H_

#include <stddef.h>

typedef void (*sorter_t)(int *arr, int arr_size);

int* str_to_int(char *str, size_t *arr_len);
void linear_sort ();
void binary_sort ();
void selection_sort();
void binary_insertion_sort(int *a, int n);
void shell_sort();
void quicksort_sort();
void merge_sort();
void bucket_sort();
void radix_sort();
void heap_sort();

#endif
