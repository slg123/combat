#!/usr/bin/env python

from weapon_class import Weapon

tank1 = Weapon( 'Sherman',   10000, 140,  5 )
tank2 = Weapon( 'Panzer',    15000, 120, 15 )
tank3 = Weapon( 'M1 Abrams', 20000, 180, 12 )

print tank1.weapon_type(), tank1.weapon_weight(), tank1.weapon_armor_class()
print tank2.weapon_type(), tank2.weapon_weight(), tank2.weapon_armor_class()
print tank3.weapon_type(), tank3.weapon_weight(), tank3.weapon_armor_class()

def get_lowest_armor_class():
    L = [ tank1.weapon_armor_class(), tank2.weapon_armor_class(), tank3.weapon_armor_class() ]
    L.sort()
    return L[0]
    
winning_armor_class = get_lowest_armor_class()
print "The winning tank has an armor class of: ", winning_armor_class

def find_tank_type_with_lowest_armor_class():
    L = [ tank1, tank2, tank3 ]
    for i in L:
        if i.weapon_armor_class() == get_lowest_armor_class():
            return i.weapon_type()

winning_tank_type = find_tank_type_with_lowest_armor_class()
print "the winning tank is: ", winning_tank_type

def get_winning_tank_weight():
    L = [ tank1, tank2, tank3 ]
    for i in L:
    if i.weapon_type() == winning_tank_type:
        return i.weapon_weight()

print "the winning tank weight is: ", get_winning_tank_weight(), " pounds"
