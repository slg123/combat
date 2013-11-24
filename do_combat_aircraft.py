#!/usr/bin/env python

from weaponry import Aircraft

airplane1 = Aircraft( 'Mitsubishi A6M Zero', 5200, 750, 10 )
airplane2 = Aircraft( 'Focke-Wulfe 190', 8000, 450, 13 )
airplane3 = Aircraft( 'Grumman F6F Hellcat', 10000, 550, 4 )

print airplane1.airplane_type(), airplane1.airplane_weight(), airplane1.airplane_range(), airplane1.airplane_armor_class()
print airplane2.airplane_type(), airplane2.airplane_weight(), airplane2.airplane_range(), airplane2.airplane_armor_class()
print airplane3.airplane_type(), airplane3.airplane_weight(), airplane3.airplane_range(), airplane3.airplane_armor_class()

def do_combat():

    def get_lowest_airplane_armor_class():
        L = [ airplane1.airplane_armor_class(), airplane2.airplane_armor_class(), airplane3.airplane_armor_class() ]
        L.sort()
        return L[0]
    
    winning_airplane_armor_class = get_lowest_airplane_armor_class()
    print "The winning airplane has an armor class of: ", winning_airplane_armor_class

    def find_airplane_type_with_lowest_airplane_armor_class():
        L = [ airplane1, airplane2, airplane3 ]
        for i in L:
            if i.airplane_armor_class() == get_lowest_airplane_armor_class():
                return i.airplane_type()

    winning_airplane_type = find_airplane_type_with_lowest_airplane_armor_class()
    print "the winning airplane is: ", winning_airplane_type

    def get_winning_airplane_weight():
        L = [ airplane1, airplane2, airplane3 ]
        for i in L:
            if i.airplane_type() == winning_airplane_type:
                return i.airplane_weight()

    print "the winning airplane weight is: ", get_winning_airplane_weight(), " pounds"

    def get_winning_airplane_range():
        L = [ airplane1, airplane2, airplane3 ]
        for i in L:
            if i.airplane_type() == winning_airplane_type:
                return i.airplane_range()

    print "the ", winning_airplane_type, "has a cruising range of ", get_winning_airplane_range(), "nautical miles."

do_combat()
