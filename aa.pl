#!/usr/bin/perl
use strict; 
use warnings;
use autodie;
my $file = "txt";
open my $fh, "<", $file;
while ( <$fh> ) {
    unless ( /^<\/default/ ) {
        if ( /<default/ ) {
            my ( $begin, $middle, $end ) = split / /; 
            $middle = "enabled";
            print "$begin $middle </default>\n";
        } else {
            print;
        }
    }
}
