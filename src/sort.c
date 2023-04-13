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

	// Fix to prevent overflow errors.
	int mid = low + ((high - low) / 2);
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

	for (i = 1; i < n; i++) {
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

void insertion_sort(int *a, int n)
{
	int i, j, loc;
	for(i = 1; i < n; i++) {
		loc = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > loc) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = loc;
	}
}

static void merge(int *a, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = a[left + i];
	for (j = 0; j < n2; j++)
		R[j] = a[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}	
}

static void merge_sort(int *a, int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;
		merge_sort(a, left, middle);
		merge_sort(a, middle + 1, right);
		merge(a, left, middle, right);
	}
}

void merge_sort_wrapper(int *a, int n)
{
	merge_sort(a, 0, n-1 );
}
