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
my @words = qw( metamorphosis googlymoogly prudent annotate facebook zebra plutocrat bloodaxe ); 
foreach my $i ( @words ) {
    my $index = binary_search( \@lines, $i );
    if ( $index ) {
        $word_index{ $i } = $index;    # add to hash if index exists
    } 
}

printf "%30s index\n", "word"; 
printf "%30s -----\n", "----"; 
while ( my ( $k, $v ) = each %word_index ) {
    printf "%30s %d\n", $k, $v;
}
