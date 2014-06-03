#!/usr/bin/perl

use strict;
use warnings;

# array stuff
my @arr = qw( 1 2 3 4 5 );
print @arr, "\n"; 

# this is an array reference. pass array references, not the whole durned thing ( pass by reference )
my $array_ref = \@arr;

print $array_ref, "\n"; 

# you iterate over an array reference by looping over "@$ref" 
for ( @$array_ref ) {
    print $_, "\n"; 
}

# a hash
my %tank_weapons = (
    m1 => "big gun",
    m2 => "bigger gun",
    m3 => "massive gun",
);

# print the m1 element of the hash
print $tank_weapons{ "m1" }, "\n"; 

# iterate through the hash, printing each key and value
while ( my ( $k, $v ) = each %tank_weapons ) {
    print "$k $v\n";
}

# create a reference to the tank_weapons hash
my $tank_weapons_ref = \%tank_weapons;

# iterate through it - same as above... you're iterating over a hash, so use the % sign, but
# since it's a reference, you call it with "%$"
while ( my ( $k, $v ) = each %$tank_weapons_ref ) {
    print "$k $v\n"; 
}

# a subroutine
sub print_ten_digits {
    for ( my $i = 0; $i < 10; $i++ ) {
        print $i, "\n";
    }
}

# create a reference to a subroutine
my $subref = \&print_ten_digits;

# and call it with "&$"
&$subref; 

# now go read perlreftut again scott. 

