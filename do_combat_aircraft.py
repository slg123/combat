#!/usr/bin/env python

from weapon_class import Weapon

airplane1 = Weapon( 'Mitsubishi A6M Zero',  5200, 750, 10 )
airplane2 = Weapon( 'Focke-Wulfe 190',      8000, 450, 13 )
airplane3 = Weapon( 'Grumman F6F Hellcat', 10000, 550,  4 )

print airplane1.weapon_type(), airplane1.weapon_weight(), airplane1.weapon_range(), airplane1.weapon_armor_class()
print airplane2.weapon_type(), airplane2.weapon_weight(), airplane2.weapon_range(), airplane2.weapon_armor_class()
print airplane3.weapon_type(), airplane3.weapon_weight(), airplane3.weapon_range(), airplane3.weapon_armor_class()

def do_combat():

    def get_lowest_armor_class():
        L = [ airplane1.weapon_armor_class(), airplane2.weapon_armor_class(), airplane3.weapon_armor_class() ]
        L.sort()
        return L[0]
    
    print "The winning airplane has an armor class of: ", get_lowest_armor_class()

    def find_airplane_type_with_lowest_armor_class():
        L = [ airplane1, airplane2, airplane3 ]
        for i in L:
            if i.weapon_armor_class() == get_lowest_armor_class():
                return i.weapon_type()

    winning_airplane_type = find_airplane_type_with_lowest_armor_class()
    print "the winning airplane is: ", winning_airplane_type

    def get_winning_airplane_weight():
        L = [ airplane1, airplane2, airplane3 ]
        for i in L:
            if i.weapon_type() == winning_airplane_type:
                return i.weapon_weight()

    print "the winning airplane weight is: ", get_winning_airplane_weight(), " pounds"

    def get_winning_airplane_range():
        L = [ airplane1, airplane2, airplane3 ]
        for i in L:
            if i.weapon_type() == winning_airplane_type:
                return i.weapon_range()

    print "the ", winning_airplane_type, "has a cruising range of ", get_winning_airplane_range(), "nautical miles."

do_combat()
