#!/usr/bin/perl

use strict;
use warnings;

my $args = @ARGV;

if ( !$args ) {
    print "usage: ./tri.pl [start] [end]\n"; 
    print "   ex: ./tri.pl 12373 12376\n"; 
} 

my $start = $ARGV[0]; 
my $end   = $ARGV[1]; 

for ( my $i = $start; $i < $end; $i++ ) {
    my $j = generate_triangle_number( $i ); 
    my $k = get_factor_count( $j ); 
    print "$i : $j : $k\n"; 

    if ( $k > 500 ) {
        print "FOUND!! -> $j is divisible by more than 500 numbers.\n"; 
        exit;
    }
}

sub generate_triangle_number {
    my $i = shift;
    my $n = 0; 
    for ( my $j = $i; $j > 0; $j-- ) {
        $n += $j;
    }
    return $n;
}

sub get_factor_count {
    my $n = shift;
    my $count = 0;
    for ( my $i = 1; $i <= $n; $i++ ) {
        if ( $n % $i == 0 ) {
            $count++;
        }
    }
    return $count;
}
