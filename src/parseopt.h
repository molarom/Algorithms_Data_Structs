#ifndef PARSEOPT_H
#define PARSEOPT_H
#include <stddef.h>

extern struct argp sorter_argp;

typedef struct {
	enum {	
		BINARY_SORT, 
		INSERTION_SORT, 
		LINEAR_SORT,
		MERGE_SORT,
		QUICKSORT,
		RADIX_SORT,
		SELECTION_SORT
	} sort;
	bool read_file;
	bool save_out;
	char in_file[64];
	char out_file[64];
	char *argz;
	size_t argz_len;
} sorter_args;

#endif
