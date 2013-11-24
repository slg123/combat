#!/usr/bin/env python

class Weapon:
    def __init__( self, type, weight, range, armor_class ):
        self.type        = type
        self.weight      = weight
        self.range       = range
        self.armor_class = armor_class
    def weapon_type( self ):
        return self.type
    def weapon_weight( self ):
        return self.weight
    def weapon_range( self ):
        return self.range
    def weapon_armor_class( self ):
        return self.armor_class

