#include <argp.h>
#include <argz.h>
#include <stdbool.h>
#include <string.h>

#include "parseopt.h"

const char *argp_program_version = "Sorter v0.1";
static char doc[] = "Sorts a comma separated list of integers using various sorting algorithms, \
logs time and memory usage over the lifecycle of the sort.";
static char args_doc[] = "<list of integers>";
static struct argp_option options[] = {
	{0,				 0, 0, 0, "Sorting Options:", 1},
	{"binary",		'b', 0, 0, "Insertion sort aided by binary search."},
	{"insertion",	'i', 0, 0, "Sorts data with a insertion algorithm."},
	{"merge",		'm', 0, 0, "Sorts data with a merge algorithm."},
	{"quicksort",	'q', 0, 0, "Sorts data with a quicksort algorithm."},
	{"radix",		'r', 0, 0, "Sorts data with a radix algorithm."},
	{"selection",	's', 0, 0, "Sorts data with a selection algorithm."},
	{0,				 0, 0, 0, "Input Options:", -9},
	{"infile",		 599, "FILE", 0, "Read list from file. Must contain comma separated list with no spaces."},
	{0,				 0, 0, 0, "Output Options:", -8},
	{"output",		'o', "FILE", 0, "Write output to a file. (Default stdout)"},
	{0,				 0, 0, 0, "Informational Options:", -1},
	{0}
};

static int parse_opt(int key, char *arg, struct argp_state *state)
{
	sorter_args_t *a = state->input;
	switch (key) {
	case 'b': 
		a->sort = BINARY_SORT;
		break;
	case 'i': 
		a->sort = INSERTION_SORT;
		printf("insertion sort\n");
		break;
	case 'l': 
		a->sort = LINEAR_SORT;
		break;
	case 'm': 
		a->sort = MERGE_SORT;
		break;
	case 'o': 
		a->save_out = true; 
		strncpy(a->out_file, arg, sizeof a->out_file);
		break;
	case 'q':
		a->sort = QUICKSORT;
		break;
	case 'r':
		a->sort = RADIX_SORT;
		break;
	case 's': 
		a->sort = SELECTION_SORT;
		break;
	case 599:
		a->read_file = true; 
		strncpy(a->in_file, arg, sizeof a->in_file);
		break;
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
		if (count > 1)
			argp_failure(state, 1, 0, "only one list of integers may be provided");
		else if ((count == 1) && (a->save_out == true))
			argp_failure(state, 1, 0, "can only read from file or from stdin, not both");
		else if ((count < 1) && (a->save_out == false))
			argp_failure(state, 1, 0, "a list of integers must be provided");
		}
		break;
	default: return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

struct argp sorter_argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

