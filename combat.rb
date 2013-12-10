#!/usr/bin/env ruby

class Weapon
    attr_accessor :type, :weight, :range, :armor_class

    def Weapon.set_attributes( tp="null", wt=0, rg=0, ac=0 )
        w = Weapon.new
        w.type        = tp
        w.weight      = wt
        w.range       = rg
        w.armor_class = ac
        return w
    end
end

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
        puts winning_tank
    end
end

