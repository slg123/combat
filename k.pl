#!/usr/bin/perl

use strict;
use warnings;

chomp( my $num = <STDIN> );

if ( $num !~ /\d+/ ) {
    print "need a number\n";
    exit -1;
}

while ( $num != 0 ) {
    if ( $num % 2 == 0 ) {
        print "$num\n";
    }
    $num--; 
}
