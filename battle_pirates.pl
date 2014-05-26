#!/usr/bin/perl

# noodling with battle pirates stats
# warning - this is a highly addictive game. 

use strict;
use warnings;

my %weapon_type = (
    'ripper cannon III' =>
        {
            tech              => 'forsaken',
            range             => 38,
            damage            => 130,
            'building damage' => 227, 
            salvo             => 3,
            'reload time'     => 1.50,
            accuracy          => 70,
            'weapon type'     => 'cannon',
            'damage type'     => 'ballistic',
            weight            => '104 tons',
        },
    'ripper cannon IV' =>
        {
            tech              => 'forsaken',
            range             => 38,
            damage            => 234,
            'building damage' => 409, 
            salvo             => 3,
            'reload time'     => 1.50,
            accuracy          => 60,
            'weapon type'     => 'cannon',
            'damage type'     => 'ballistic',
            weight            => '249 tons',
        },
);

my %hull_type = ( 
    'gunboat' =>
        {
            tech               => 'forsaken',
            armor_points       => 10,
            max_weight         => '31 tons',
            weapon_slots       => 1, 
            armor_slots        => 1,
            special_slots      => 0,
            cargo              => '19,676 tons',
            evade_bonus        => '+33.0%',
            map_speed          => 50,
            combat_speed       => 22,
            turn_speed         => 60,
            underwater_weapons => 'yes',
            air_weapons        => 'no',
            repair_modifier    => '25%',
            quantity           => 0,
        },
    'skirmisher' => 
        {
            tech               => 'forsaken',
            armor_points       => 27,
            max_weight         => '82 tons',
            weapon_slots       => 1, 
            armor_slots        => 1,
            special_slots      => 0,
            cargo              => '39,353 tons',
            evade_bonus        => '+25.0%',
            map_speed          => 43,
            combat_speed       => 20,
            turn_speed         => 47,
            underwater_weapons => 'yes',
            air_weapons        => 'no',
            repair_modifier    => '25%',
            quantity           => 0,

        },
    'longship' =>
        {
            tech               => 'forsaken',
            armor_points       => 72,
            max_weight         => '216 tons',
            weapon_slots       => 2, 
            armor_slots        => 2,
            special_slots      => 1,
            cargo              => '78,705 tons',
            evade_bonus        => '+20.0%',
            map_speed          => 37,
            combat_speed       => 16,
            turn_speed         => 36,
            underwater_weapons => 'yes',
            air_weapons        => 'no',
            repair_modifier    => '50%',
            quantity           => 0,
        },
    'marauder' =>
        {
            tech               => 'forsaken',
            armor_points       => 190,
            max_weight         => '570 tons',
            weapon_slots       => 3, 
            armor_slots        => 2,
            special_slots      => 1,
            cargo              => '94,446 tons',
            evade_bonus        => '+10.0%',
            map_speed          => 32,
            combat_speed       => 14,
            turn_speed         => 21,
            underwater_weapons => 'no',
            air_weapons        => 'no',
            repair_modifier    => '50%',
            quantity           => 0,
        },
    'predator submarine' =>
        {
            tech               => 'forsaken',
            armor_points       => 120,
            max_weight         => '416 tons',
            weapon_slots       => 2, 
            armor_slots        => 1,
            special_slots      => 1,
            cargo              => '2,500 tons',
            map_speed          => 27,
            combat_speed       => 12,
            turn_speed         => 25,
            underwater_weapons => 'yes',
            air_weapons        => 'no',
            repair_modifier    => '300%',
            quantity           => 0,
        },
    'battle barge' =>
        {
            tech               => 'forsaken',
            armor_points       => 466,
            max_weight         => '1,397 tons',
            weapon_slots       => 4, 
            armor_slots        => 2,
            special_slots      => 2,
            cargo              => '113,335 tons',
            map_speed          => 27,
            combat_speed       => 12,
            turn_speed         => 15,
            underwater_weapons => 'no',
            air_weapons        => 'no',
            repair_modifier    => '75%',
            quantity           => 18,
        },
    'arbiter' =>
        { 
            tech               => 'forsaken',
            armor_points       => 562,
            max_weight         => '12,000 tons',
            weapon_slots       => 1, 
            armor_slots        => 2,
            special_slots      => 2,
            cargo              => '145,000 tons',
            evade_bonus        => '+10.0%',
            map_speed          => 30,
            combat_speed       => 12,
            turn_speed         => 15,
            underwater_weapons => 'yes',
            air_weapons        => 'no',
            repair_modifier    => '75%',
            quantity           => 0,
        },
    'leviathan' =>
        {
            tech               => 'forsaken',
            armor_points       => 1074,
            max_weight         => '3,222 tons',
            weapon_slots       => 5, 
            armor_slots        => 3,
            special_slots      => 2,
            cargo              => '374,006 tons',
            map_speed          => 23,
            combat_speed       => 10,
            turn_speed         => 10,
            underwater_weapons => 'no',
            air_weapons        => 'no',
            repair_modifier    => '75%',
            quantity           => 0,
        },
    'sea wolf' =>
        {
            tech               => 'forsaken',
            armor_points       => 550,
            max_weight         => '2,300 tons',
            weapon_slots       => 5, 
            armor_slots        => 1,
            special_slots      => 3,
            cargo              => '195,000 tons',
            map_speed          => 30,
            combat_speed       => 14,
            turn_speed         => 20,
            underwater_weapons => 'no',
            air_weapons        => 'no',
            quantity           => 2,
        },
    'stalker submarine' => 
        {
            tech               => 'forsaken',
            armor_points       => 250,
            max_weight         => '2,200 tons',
            weapon_slots       => 4, 
            armor_slots        => 2,
            special_slots      => 2,
            cargo              => '10,000 tons',
            sonar_range        => 50,
            map_speed          => 20,
            combat_speed       => 9,
            turn_speed         => 20,
            underwater_weapons => 'yes',
            air_weapons        => 'no',
            repair_modifier    => '200%',
            quantity           => 0,
        },
    'floating fortress' =>
        {
            tech               => 'forsaken',
            armor_points       => 2317,
            max_weight         => '6,951 tons',
            weapon_slots       => 6, 
            armor_slots        => 3,
            special_slots      => 2,
            cargo              => '1,122,018 tons',
            map_speed          => 20,
            combat_speed       => 8,
            turn_speed         => 5,
            underwater_weapons => 'no',
            air_weapons        => 'yes',
            repair_modifier    => '75%',
            quantity           => 0,
        },
    'sea scorpion' =>
        {
            tech               => 'forsaken',
            armor_points       => 750,
            max_weight         => '4,500 tons',
            weapon_slots       => 7, 
            armor_slots        => 1,
            special_slots      => 3,
            cargo              => '395,000 tons',
            map_speed          => 27,
            combat_speed       => 12,
            turn_speed         => 13,
            underwater_weapons => 'no',
            air_weapons        => 'no',
            quantity           => 0,
        },
    'hammerhead' =>
        {
            tech               => 'forsaken',
            armor_points       => 2400,
            max_weight         => '7,500 tons',
            weapon_slots       => 6, 
            armor_slots        => 3,
            special_slots      => 2,
            cargo              => '1,000,000 tons',
            map_speed          => 23,
            combat_speed       => 10,
            turn_speed         => 5,
            underwater_weapons => 'no',
            air_weapons        => 'no',
            repair_modifier    => '75%',
            quantity           => 0,
        },
);

my @attributes = qw( tech armor_points max_weight weapon_slots armor_slots special_slots 
                     cargo evade_bonus sonar_range map_speed combat_speed turn_speed 
                     underwater_weapons air_weapons repair_modifier quantity ); 

my @hulls;
while ( my ( $key, $value ) = each %hull_type ) {
    push @hulls, $key; 
}

sub show_all_hull_stats {
    for my $hull ( @hulls ) {
        print "\n\n*** $hull *** \n\n";
        for my $attr ( @attributes ) {
            if ( defined $hull_type{ $hull }{ $attr } ) {
                printf "%-20s: %-20s\n", $attr, $hull_type{ $hull }{ $attr }, if defined $attr; 
            }
        }
    }
}
show_all_hull_stats(); 

sub print_some_stats {
    print "\n\n"; 
    printf "hammerhead armor points: %s\n",  $hull_type{ 'hammerhead' }{ 'armor_points' };
    printf "hammerhead weapon slots: %s\n",  $hull_type{ 'hammerhead' }{ 'weapon_slots' };
    printf "arbiter armor points: %s\n", $hull_type{ 'arbiter' }{ 'armor_points' };
    printf "arbiter weapon slots: %s\n", $hull_type{ 'arbiter' }{ 'weapon_slots' };
    printf "battle barge armor points: %s\n", $hull_type{ 'battle barge' }{ 'armor_points' };
    printf "battle barge weapon slots: %s\n", $hull_type{ 'battle barge' }{ 'weapon_slots' };

    printf "ripper cannon III damage: %s\n", $weapon_type{ 'ripper cannon III' }{ 'damage' };
    printf "ripper cannon III building damage: %s\n", $weapon_type{ 'ripper cannon III' }{ 'building damage' };
    printf "ripper cannon IV damage: %s\n", $weapon_type{ 'ripper cannon IV' }{ 'damage' };
    printf "ripper cannon IV building damage: %s\n", $weapon_type{ 'ripper cannon IV' }{ 'building damage' };
}

print_some_stats(); 

sub lookup_hull_stats {
    my $hull = shift;
    print "\n\nstats for $hull: \n\n"; 
    for my $attr ( @attributes ) {
        if ( defined $hull_type{ $hull }{ $attr } ) {
            printf "%-20s: %-20s\n", $attr, $hull_type{ $hull }{ $attr }, if defined $attr; 
        }
    }
}

lookup_hull_stats( 'hammerhead' ); 



