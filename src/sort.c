#include "sort.h"

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
	merge_sort(a, 0, n - 1);
}

static void swap(int *a, int *b)
{
	int t = *a;
	*b = t;
}

static int partition(int *a, int lo, int hi)
{
	int pivot = a[hi];

	int i = (lo - 1);

	for (int j = lo; j < hi; j++) {
		if (a[j] <= pivot) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	
	swap(&a[i + 1], &a[hi]);

	return(i + 1);
}

static void quick_sort(int *a, int lo, int hi)
{
	if (lo < hi) {
		int pivot = partition(a, lo, hi);
		quick_sort(a, lo, pivot - 1); 
		quick_sort(a, pivot + 1, hi);
	}
}

void quick_sort_wrapper(int *a, int n)
{
	quick_sort(a, 0, n - 1);
}
