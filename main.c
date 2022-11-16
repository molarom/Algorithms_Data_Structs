#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

// Prototypes to allow for reordering.
help();

// Function pointers for sorting algorithms.
typedef void (*sorter)(int []);

sorter sort_algorithms[10] = {
	&linear_sort,
	&binary_sort,
	&selection_sort,
	&insertion_sort,
	&shell_sort,
	&quicksort_sort,
	&merge_sort,
	&bucket_sort,
	&radix_sort,
	&heap_sort
};

int main(int argc, char** argv)
{
	// Enum to define sorting algos.
	enum {
		LINEAR,
		BINARY,
		SELECTION,
		INSERTION,
		SHELL,
		QUICKSORT,
		MERGE,
		BUCKET,
		RADIX,
		HEAP
	} sort = LINEAR;

	// Parse our cmdline args.
	size_t optind = 1;
	if (argc < 2) {
		help();
	}

	if (strcmp(argv[optind], "-bi") == 0) { 
		sort = BINARY;
		printf("%s", argv[optind]);
	} else if (strcmp(argv[optind], "-bu") == 0) { 
		sort = BUCKET; 
	} else if (strcmp(argv[optind], "-h") == 0) {
		sort = HEAP; 
	} else if (strcmp(argv[optind], "-i") == 0) { 
		sort = INSERTION; 
	} else if (strcmp(argv[optind], "-l") == 0) {
		sort = LINEAR; 
	} else if (strcmp(argv[optind], "-m") == 0) { 
		sort = MERGE; 
	} else if (strcmp(argv[optind], "-q") == 0) { 
		sort = QUICKSORT; 
	} else if (strcmp(argv[optind], "-r") == 0) { 
		sort = RADIX; 
	} else if (strcmp(argv[optind], "-se") == 0) { 
		sort = SELECTION; 
	} else if (strcmp(argv[optind], "-sh") == 0) { 
		sort = SHELL; 
	} else if (strcmp(argv[optind], "-help") == 0) { 
		help(); 
	} else {
		help();
	}


	return 0;
}

// Quick help message, displays a quick usage message and options available.
help() 
{
	fprintf(stderr, "\nThis program sorts a list based on a selected sorting algorithm.\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "Usage: sorter.exe -[SORTING OPTION] [list...]\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "OPTIONS\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "-help : Displays this help message.\n");
	fprintf(stderr, "-bi   : Sorts inputed data with a binary sorting algorithm.\n");
	fprintf(stderr, "-bu   : Sorts inputed data with a bucket sorting algorithm.\n");
	fprintf(stderr, "-h    : Sorts inputed data with a heap sorting algorithm.\n");
	fprintf(stderr, "-i    : Sorts inputed data with a insertion sorting algorithm.\n");
	fprintf(stderr, "-l    : Sorts inputed data with a linear sorting algorithm.\n");
	fprintf(stderr, "-m    : Sorts inputed data with a merge sorting algorithm.\n");
	fprintf(stderr, "-q    : Sorts inputed data with a quicksort sorting algorithm.\n");
	fprintf(stderr, "-r    : Sorts inputed data with a radix sorting algorithm.\n");
	fprintf(stderr, "-se   : Sorts inputed data with a selection sorting algorithm.\n");
	fprintf(stderr, "-sh   : Sorts inputed data with a shell sorting algorithm.\n");

	exit(EXIT_FAILURE);
}

