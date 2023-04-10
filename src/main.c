#include <argp.h>
#include <argz.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

const char *argp_program_version = "Sorter v0.1";
static char doc[] = "Sorts a comma separated list of integers using various sorting algorithms, \
logs time and memory usage over the lifecycle of the sort.";
static char args_doc[] = "<list of integers>";
static struct argp_option options[] = {
	{0,				 0, 0, 0, "Sorting Options:", 1},
	{"binary",		'b', 0, 0, "Sorts data with a binary algorithm."},
	{"insertion",	'i', 0, 0, "Sorts data with a insertion algorithm."},
	{"linear",		'l', 0, 0, "Sorts data with a linear algorithm."},
	{"merge",		'm', 0, 0, "Sorts data with a merge algorithm."},
	{"quicksort",	'q', 0, 0, "Sorts data with a quicksort algorithm."},
	{"radix",		'r', 0, 0, "Sorts data with a radix algorithm."},
	{"selection",	's', 0, 0, "Sorts data with a selection algorithm."},
	{0,				 0, 0, 0, "Output Options:", -8},
	{"output",		'o', "FILE", 0, "Write output to a file. (Default stdout)"},
	{0,				 0, 0, 0, "Informational Options:", -1},
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
	bool save_out;
	char out_file[64];
	char *argz;
	size_t argz_len;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *a = state->input;
	switch (key) {
	case 'b': 
		a->sort = BINARY_SORT;
		printf("Selected Binary_sort\n");
		break;
	case 'i': a->sort = INSERTION_SORT; break;
	case 'l': a->sort = LINEAR_SORT; break;
	case 'm': a->sort = MERGE_SORT; break;
	case 'o': 
		a->save_out = true; 
		strncpy(a->out_file, arg, sizeof a->out_file);
		printf("Output file = %s\n", a->out_file);
		break;
	case 'q': a->sort = QUICKSORT; break;
	case 'r': a->sort =	RADIX_SORT; break;
	case 's': a->sort = SELECTION_SORT; break;
	case ARGP_KEY_ARG:
		argz_add(&a->argz, &a->argz_len, arg);
		break;
	case ARGP_KEY_INIT:
		a->argz = 0;
		a->argz_len = 0;
		break;
	case ARGP_KEY_END:
		{
		size_t count = argz_count(a->argz, a->argz_len);
		if (count > 2)
			argp_failure(state, 1, 0, "too many arguments");
		else if (count < 1)
			argp_failure(state, 1, 0, "too few arguments");
		}
		break;
	default: return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char	**argv)
{
	const char *prev = NULL;
	char *word;

	struct arguments args;

	if (argp_parse(&argp, argc, argv, 0, 0, &args) != 0) {
		fprintf(stderr, "Unable to parse arguments.");
		exit(EXIT_FAILURE);
	}

	while ((word = argz_next(args.argz, args.argz_len, prev))) {
		prev = word;
	}
	printf("\n");
	free(args.argz);

	return 0;
}

