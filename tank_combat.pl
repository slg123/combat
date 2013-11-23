#!/usr/bin/perl

package Tank;

use strict;
use warnings;
use Carp;

sub new {
    my $class = shift;
    my $self  = { @_ };
    croak "bad arguments" unless defined $self->{type} and defined $self->{weight} and defined $self->{armor_class}; 
    return bless $self, $class; 
}

sub tank_object {
    my $self = shift;
    return "$self->{type} $self->{weight} $self->{armor_class}";
}

package main;

my $tank1 = Tank->new( type => "Sherman",   weight => 10000, armor_class =>  5 );
my $tank2 = Tank->new( type => "Panzer",    weight => 15000, armor_class => 15 );
my $tank3 = Tank->new( type => "M1 Abrams", weight => 20000, armor_class => 12 );

sub get_lowest_armor_class {
    my @armor_classes; 
    for ( $tank1, $tank2, $tank3 ) { 
        push @armor_classes, $_->{ armor_class };
    }
    my @sorted = sort { $a <=> $b } @armor_classes;
    return $sorted[0];  
}

sub find_tank_with_lowest_armor_class {
    my @tanks;
    for ( $tank1, $tank2, $tank3 ) {
        if ( $_->{ armor_class } == get_lowest_armor_class() ) {
            return $_->{ type };
        }
    }
}

my $winning_tank_type = find_tank_with_lowest_armor_class(); 
sub get_winning_tank_weight {
    for ( $tank1, $tank2, $tank3 ) {
        if ( $_->{ type } eq $winning_tank_type ) {
            return $_->{ weight };
        }
    }
}

print $tank1->tank_object,  "\n";
print $tank2->tank_object,  "\n";
print $tank3->tank_object,  "\n";
my $winning_tank = find_tank_with_lowest_armor_class(); 
my $winning_tank_weight = get_winning_tank_weight(); 
print "winning tank is: $winning_tank\n"; 
print "winning tank weight is: $winning_tank_weight\n"; 
