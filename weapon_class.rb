
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
