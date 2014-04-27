#!/usr/bin/perl

use strict; 
use warnings;
use autodie;
my $file = "txt";
my $out  = "txt.out"; 

open my $fh, "<", $file;
open my $ofh, ">", $out;
while ( <$fh> ) {
    unless ( /^<\/default/ ) {
        if ( /<default/ ) {
            my ( $begin, $middle, $end ) = split / /; 
            $middle = "enabled";
            print "$begin $middle </default>\n";
            print $ofh "$begin $middle </default>\n"; 
        } else {
            print;
            print $ofh $_;
        }
    }
}
close $fh;
close $ofh;
