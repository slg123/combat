#!/usr/bin/env python

class Tank:
    def __init__( self, type, weight, armor_class ):
        self.type        = type
        self.weight      = weight
        self.armor_class = armor_class
    def tank_type( self ):
        return self.type
    def tank_weight( self ):
        return self.weight
    def tank_armor_class( self ):
        return self.armor_class

class Aircraft:
    def __init__( self, type, weight, range, armor_class ):
        self.type        = type
        self.weight      = weight
        self.range       = range
        self.armor_class = armor_class
    def airplane_type( self ):
        return self.type
    def airplane_weight( self ):
        return self.weight
    def airplane_range( self ):
        return self.range
    def airplane_armor_class( self ):
        return self.armor_class
