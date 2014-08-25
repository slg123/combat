#!/usr/bin/perl

# By considering the terms in the Fibonacci sequence 
# whose values do not exceed four million, find the 
# sum of the even-valued terms.

# http://projecteuler.net/problem=002

use strict;
use warnings;

my @even_fibs = (); 

sub fibs {

    my $upto    = shift;
    my $curnum  = 1; 
    my $prevnum = 1;
    my $sum     = 0;

    while ( $sum < $upto ) {
        $sum = $curnum + $prevnum;
        $prevnum = $curnum;
        $curnum = $sum;
        if ( $sum % 2 == 0 ) {
            push @even_fibs, $sum; 
        }
    }
}

fibs( 4000000 ); 

our $total = 0; 
for ( @even_fibs ) {
    $total += $_; 
}
print "total: $total\n";


