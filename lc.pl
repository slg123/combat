#!/usr/bin/perl

use strict;
use warnings;

my @coin_sizes = qw( 10 10 10 10 9 10 10 10 10 ); 

sub get_weight_total {
    my @arr = @_; 
    my $total = 0; 
    for ( @arr ) {
        $total += $_;
    }
    return $total;
}

my @pile1;
my @pile2;
my @pile3;

sub make_three_piles {
    my @big_pile = @_; 
    my $i = 0; 
    for ( @big_pile ) {
        if ( $i >= 0 && $i < 3 ) {
            push @pile1, $big_pile[$i];
        }
        if ( $i >= 3 && $i < 6 ) {
            push @pile2, $big_pile[$i];
        }
        if ( $i >= 6 && $i < 9 ) {
            push @pile3, $big_pile[$i];
        }
        $i++;
    }
}
make_three_piles( @coin_sizes ); 

my $pile1_weight = get_weight_total( @pile1 ); 
my $pile2_weight = get_weight_total( @pile2 ); 
my $pile3_weight = get_weight_total( @pile3 ); 

print "total pile weight: \n";
print get_weight_total( @coin_sizes ), "\n"; 

print "weight of piles separated into three piles of three coins: \n"; 
print "$pile1_weight $pile2_weight $pile3_weight\n"; 

sub get_lightest_pile {

    my $lowest_weight = 10000;  # initially something bigger than our array values
    for my $i ( $pile1_weight, $pile2_weight, $pile3_weight ) {
        if ( $i < $lowest_weight ) {
            $lowest_weight = $i;
        }
    }

    my $pile_counter = 0;
    for my $i ( $pile1_weight, $pile2_weight, $pile3_weight ) {
        $pile_counter++; 
        if ( $i == $lowest_weight ) {
            my $lightest_pile = $pile_counter; 
            return $lowest_weight, $lightest_pile;
        }
    }
}

my ( $lowest_weight, $lightest_pile ) = get_lightest_pile(); 
print "lightest pile is pile: $lightest_pile\n"; 
print "the weight of that pile is: $lowest_weight\n";
print "take two coins from that pile. if those two coins balance, then the coin off of the beam is the light one,\n";
print "otherwise it's the higher coin on the scale.\n"; 




