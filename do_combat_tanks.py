#!/usr/bin/env python

from weaponry import Tank

tank1 = Tank( 'Sherman', 10000, 5 )
tank2 = Tank( 'Panzer', 15000, 15 )
tank3 = Tank( 'M1 Abrams', 20000, 12 )

print tank1.tank_type(), tank1.tank_weight(), tank1.tank_armor_class()
print tank2.tank_type(), tank2.tank_weight(), tank2.tank_armor_class()
print tank3.tank_type(), tank3.tank_weight(), tank3.tank_armor_class()

def do_combat():

    def get_lowest_armor_class():
        L = [ tank1.tank_armor_class(), tank2.tank_armor_class(), tank3.tank_armor_class() ]
        L.sort()
        return L[0]
    
    winning_armor_class = get_lowest_armor_class()
    print "The winning tank has an armor class of: ", winning_armor_class

    def find_tank_type_with_lowest_armor_class():
        L = [ tank1, tank2, tank3 ]
        for i in L:
            if i.tank_armor_class() == get_lowest_armor_class():
                return i.tank_type()

    winning_tank_type = find_tank_type_with_lowest_armor_class()
    print "the winning tank is: ", winning_tank_type

    def get_winning_tank_weight():
        L = [ tank1, tank2, tank3 ]
        for i in L:
            if i.tank_type() == winning_tank_type:
                return i.tank_weight()

    print "the winning tank weight is: ", get_winning_tank_weight(), " pounds"

do_combat()
