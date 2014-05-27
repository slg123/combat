#!/usr/bin/perl

use strict;
use warnings;
use autodie;

sub binary_search {
    our ( $array, $word ) = @_;
    my ( $low, $high ) = ( 0, @$array - 1 ); 

    while ( $low <= $high ) {
        my $try = int( ( $low + $high ) / 2 ); 
        $low  = $try + 1, next if $array->[$try] lt $word;
        $high = $try - 1, next if $array->[$try] gt $word;
        return $try;
    }
    return;
}

my $file = "/usr/dict/words";
my @lines;
open my $fh, "<", $file;
while ( <$fh> ) {
    chomp;
    push @lines, $_;
}

my %word_index = ();
my %nonword_index = (); 

my @words = qw( zajfzajf metamorphosis googlymoogly zucktruck prudent annotate facebook zebra plutocrat bloodaxe ); 

foreach my $i ( @words ) {
    my $index = binary_search( \@lines, $i );
    if ( $index ) {
        $word_index{ $i } = $index;    # add to hash if index exists
    } else {
        $nonword_index{ $i } = $index;
    }
}

sub print_them {
    my $hash_ref = shift;
    printf "word                           index  \n"; 
    print "---------                    ----------\n"; 
    while ( my ( $k, $v ) = each %$hash_ref ) {
        #
        # if there's a value, print it, otherwise just print the key with no index. 
        #
        if ( $v ) {
            printf "%-30s %d\n", $k, $v;
        } else {
            printf "%-30s - no index.\n", $k;
        }
    }
    print "\n"x2; 
}

print_them( \%word_index );
print_them( \%nonword_index );

