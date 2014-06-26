#!/usr/bin/perl

use strict;
use warnings;

my $table = {
    "john" => [ 47, "brown", 186 ],
    "mary" => [ 37, "green", 110 ],
    "bill" => [ 27, "blue",  210 ],
};

sub print_people {
    my @people = qw( john mary bill );
    for ( @people ) {
        foreach my $i ( 0 .. 2 ) {
            print $_, " ".@$table{ "$_" }->[$i], "\n"; 
        }
        print "\n"; 
    }
}
print_people();

my $oldmary = @$table{"mary"}->[2];

@$table{"mary"}->[2] = 135;

my $newmary = @$table{"mary"}->[2];

print_people(); 

if ( $newmary > $oldmary ) {
    my $diff = $newmary - $oldmary;
    print "mary gained $diff pounds.\n";
}

