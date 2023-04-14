# Simple Sorter

This is a simple program that will read in a comma separated list of numbers, and sort them with a number of sorting algorithms the user may choose.

## Usage

This program makes use of the Argp library, so some standard command-line options are provided.

Ex:
```
./sorter --usage
./sorter --version
```

For a full list of options:
```
./sorter --help
```

## Testing
This repository ships with a Perl script to generate a file for testing purposes.

To generate the test file: 
```
perl generate_list.pl
```

This will generate 100,000 random integers from 1-100,000 within a file named `numbers.txt`.

# Building

Building has only been tested on Debian 12 (Kernel v6.1.0).

```
make
```

# Limitations 

Float comparisons have not been implemented yet.
