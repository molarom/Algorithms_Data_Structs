# Simple Sorter

This is a simple program that will read in a comma separated list of numbers, and sort them with a number of sorting algorithms the user may choose.

## Usage

```
Usage: sorter [OPTION...] <list of integers>
Sorts a comma separated list of integers using various sorting algorithms, logs
time and memory usage over the lifecycle of the sort.

 Sorting Options:
  -b, --binary               Insertion sort aided by binary search.
  -i, --insertion            Sorts data with a insertion algorithm.
  -m, --merge                Sorts data with a merge algorithm.
  -q, --quicksort            Sorts data with a quicksort algorithm.
  -r, --radix                Sorts data with a radix algorithm.
  -s, --selection            Sorts data with a selection algorithm.

 Input Options:
      --in-file=FILE         Read list from file.

 Output Options:
  -o, --out-file=FILE        Write output to a file. (Default stdout)

 Informational Options:
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

Mandatory or optional arguments to long options are also mandatory or optional
for any corresponding short options.
```

**NOTE:** If you select multiple sort options, only the last sort method will be executed.

## Testing
This repository ships with a Perl script to generate a file for testing purposes.

To generate the test file: 
```
perl generate_list.pl
```

This will generate 100,000 random integers from 1-100,000 within a file named `numbers.txt`.

Pass this file to the binary to examine the outputs.
```
./sorter [OPTION..] --infile=numbers.txt
```

# Building

Building has only been tested on Debian 12 (Kernel v6.1.0).

```
make
```

The final binary will be placed within the `build/` directory.

# Limitations 

Float comparisons have not been implemented yet.
