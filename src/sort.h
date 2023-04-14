#ifndef SORT_H_
#define SORT_H_

typedef void (*sorter_t)(int *arr, int arr_size);

void binary_insertion_sort(int *a, int n);
void insertion_sort(int *a, int n);
void merge_sort_wrapper(int *a, int n);
void quick_sort_wrapper(int *a, int n);
void selection_sort();
void bucket_sort();
void radix_sort();
void heap_sort();

#endif
