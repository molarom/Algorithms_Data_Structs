use strict;
use warnings;
use 5.010;

my $n = 100000;

open (my $fh, ">", "numbers.txt");

for (my $i = 0; $i <= $n; $i++) {
   print $fh 1 + int rand($n); 
   print $fh ",";
}

close($fh);
