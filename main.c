#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes to allow for reordering.
help();

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
	size_t optind = { 0 };
	for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++) {
		switch (argv[optind][1]) {
		case 'bi': sort = BINARY; break;
		case 'bu': sort = BUCKET; break;
		case 'h': sort = HEAP; break;
		case 'help': help(); break;
		case 'i': sort = INSERTION; break;
		case 'l': sort = LINEAR; break;
		case 'm': sort = MERGE; break;
		case 'q': sort = QUICKSORT; break;
		case 'r': sort = RADIX; break;
		case 'se': sort = SELECTION; break;
		case 'sh': sort = SHELL; break;
		default:
			help();
		}
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

