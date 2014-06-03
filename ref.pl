#!/usr/bin/perl

# ref crap

use strict;
use warnings;

my @arr = qw( 1 2 3 4 5 );
print @arr, "\n"; 
my $array_ref = \@arr;

print $array_ref, "\n"; 

for ( @$array_ref ) {
    print $_, "\n"; 
}

my %tank_weapons = (
    m1 => "big gun",
    m2 => "bigger gun",
    m3 => "massive gun",
);

print $tank_weapons{ "m1" }, "\n"; 

while ( my ( $k, $v ) = each %tank_weapons ) {
    print "$k $v\n";
}

my $tank_weapons_ref = \%tank_weapons;

while ( my ( $k, $v ) = each %$tank_weapons_ref ) {
    print "$k $v\n"; 
}

sub print_ten_digits {
    for ( my $i = 0; $i < 10; $i++ ) {
        print $i, "\n";
    }
}

my $subref = \&print_ten_digits;

&$subref; 

