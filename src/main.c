#include <argp.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "sort.h"

const char *argp_program_version = "Sorter v0.1";
static char doc[] = "Sorts a comma separated list of integers using various sorting algorithms, \
logs time and memory usage over the lifecycle of the sort.";
static char args_doc[] = "<list of integers>";
static struct argp_option options[] = {
	{"binary",		'b', 0, 0, "Sorts data with a binary algorithm."},
	{"insertion",	'i', 0, 0, "Sorts data with a insertion algorithm."},
	{"linear",		'l', 0, 0, "Sorts data with a linear algorithm."},
	{"merge",		'm', 0, 0, "Sorts data with a merge algorithm."},
	{"quicksort",	'q', 0, 0, "Sorts data with a quicksort algorithm."},
	{"radix",		'r', 0, 0, "Sorts data with a radix algorithm."},
	{"selection",	's', 0, 0, "Sorts data with a selection algorithm."},
	{"output",		'o', "FILE", 0, "Write output to a file. (Default stdout)"},
	{ 0 }
};

struct arguments {
	enum {	
		BINARY_SORT, 
		INSERTION_SORT, 
		LINEAR_SORT,
		MERGE_SORT,
		QUICKSORT,
		RADIX_SORT,
		SELECTION_SORT
	} sort;
	bool file_out;
	char out_filename[64];
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state->input;
	switch (key) {
	case 'b': 
		arguments->sort = BINARY_SORT;
		printf("Selected Binary_sort\n");
		break;
	case 'i': arguments->sort = INSERTION_SORT; break;
	case 'l': arguments->sort = LINEAR_SORT; break;
	case 'm': arguments->sort = MERGE_SORT; break;
	case 'o': 
		arguments->file_out = true; 
		strncpy(arguments->out_filename, arg, sizeof arguments->out_filename);
		printf("Output file = %s\n", arguments->out_filename);
		break;
	case 'q': arguments->sort = QUICKSORT; break;
	case 'r': arguments->sort =	RADIX_SORT; break;
	case 's': arguments->sort = SELECTION_SORT; break;
	case ARGP_KEY_ARG: return 0;
	default: return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char** argv)
{
	struct arguments args;

	argp_parse(&argp, argc, argv, 0, 0, &args);

	return 0;
}

