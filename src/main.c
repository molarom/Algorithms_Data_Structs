#include <argp.h>
#include <argz.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

#include "sort.h"
#include "parsing.h"
#include "parseopt.h"

sorter_t sort_method[7] = {
	&binary_insertion_sort,
	&insertion_sort,
	&merge_sort_wrapper
};

long get_mem_usage() {
	struct rusage memusage;
	getrusage(RUSAGE_SELF,&memusage);
	return memusage.ru_maxrss;
}

int main(int argc, char	**argv)
{
	sorter_args_t args;

	if (argp_parse(&sorter_argp, argc, argv, 0, 0, &args) != 0) {
		fprintf(stderr, "Unable to parse arguments.");
		exit(EXIT_FAILURE);
	}

	size_t int_len = 0;
	int * int_arr;
	if (args.read_file == false) {
		int_arr = str_to_int(args.argz, &int_len);
	} else {
		int_arr = file_to_int(args.in_file, &int_len);
	}

	time_t begin, end;
	time(&begin);

	sort_method[args.sort](int_arr, int_len);

	time(&end);
	time_t elapsed = end - begin;

	printf("Sorted array: \n");
	for(size_t i = 0; i < int_len; i++)
		printf("%d ", int_arr[i]);
	printf("\n");

	long memory = get_mem_usage() / 1024;
	
	printf("Maximum possible memory usage: %ld kb\n", memory);
	printf("Total time elapsed: %ld seconds.\n", elapsed);

	// argz and int_arr are malloc'd behind the scenes.
	free(args.argz);
	free(int_arr);
	return 0;
}

