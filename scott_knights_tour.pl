#!/usr/bin/perl

use strict;
use warnings;

sub show_possible_moves {
    my @knight_moves = (
            [ -1,  2 ], 
            [ -1, -2 ],
            [  1,  2 ],
            [  1, -2 ],
            [ -2,  1 ],
            [ -2, -1 ],
            [  2,  1 ],
            [  2, -1 ],
    );    

    my $count = 0; 
    for ( @knight_moves ) {
        print "$knight_moves[$count][0] \t $knight_moves[$count][1]  \n";
        $count++;
    }
}
show_possible_moves(); 

sub place_knight {
    my $square = shift;
    my ( $x, $y ) = from_algebraic( $square ); 
    return( $x, $y ); 
}

sub from_algebraic {
    my $algebraic = shift;
    my ( $x, $y ) = split( '', $algebraic );  
    $x = 1 if $x eq "a";
    $x = 2 if $x eq "b";
    $x = 3 if $x eq "c";
    $x = 4 if $x eq "d";
    $x = 5 if $x eq "e";
    $x = 6 if $x eq "f";
    $x = 7 if $x eq "g";
    $x = 8 if $x eq "h";
    return ( $x, $y ); 
}

sub draw_board {
    my ( $x, $y ) = place_knight( "e4" ); 
    print "DEBUG: ".$x." ".$y."\n"; 
    for ( my $i = 1; $i < 9; $i++ ) { 
        for ( my $j = 1; $j <= 9; $j++ ) {
            if ( $j == 9 ) {
                print "\n";
            } else {
                print "[ ]"; 
            }
        }
    }
}
draw_board();
