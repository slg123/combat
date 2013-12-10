#!/usr/bin/env ruby

require 'weapon_class.rb'

def do_tank_combat

    tank1 = Weapon.set_attributes( "M1 Abrams", 15000, 130, 3  ) 
    tank2 = Weapon.set_attributes( "Panzer",    16000,  80, 14 )
    tank3 = Weapon.set_attributes( "Sherman",   10000,  90, 7  )

    weapon_arr = [ tank1, tank2, tank3 ]
    for tank in weapon_arr
        puts "#{ tank.type } #{ tank.weight } #{ tank.range } #{ tank.armor_class }"
    end

    armor_classes = [ tank1.armor_class, tank2.armor_class, tank3.armor_class ]
    armor_classes.sort
    winning_armor_class = armor_classes[0]
    puts winning_armor_class

    tanks = [ tank1, tank2, tank3 ]
    for i in tanks
        if i.armor_class == winning_armor_class
            winning_tank = i.type
            puts "winning tank: " + winning_tank
        end
    end
end

do_tank_combat

def do_plane_combat

    plane1 = Weapon.set_attributes( "Grumman F6F Hellcat", 4000, 350, 2  ) 
    plane2 = Weapon.set_attributes( "P40 Warhawk",         3000, 300, 9 )
    plane3 = Weapon.set_attributes( "Mitsubishi Zero",     2500, 400, 1  )

    weapon_arr = [ plane1, plane2, plane3 ]
    for plane in weapon_arr
        puts "#{ plane.type } #{ plane.weight } #{ plane.range } #{ plane.armor_class }"
    end

    armor_classes = [ plane1.armor_class, plane2.armor_class, plane3.armor_class ]
    armor_classes.sort
    winning_armor_class = armor_classes[0]
    puts winning_armor_class

    planes = [ plane1, plane2, plane3 ]
    for i in planes
        if i.armor_class == winning_armor_class
            winning_plane = i.type
            puts "winning plane: " + winning_plane
        end
    end
end

do_plane_combat
