function Weapon (type) {
    this.type        = type;
    this.weight      = 0;
    this.range       = 0;
    this.armor_class = 0;
}

Weapon.prototype.getWeaponInfo = function() {
        return this.type + ' ' + this.weight + ' ' + this.range + ' ' + this.armor_class;
};

var tank1 = new Weapon( 'Sherman' );
tank1.weight      = 10000;
tank1.range       = 130;
tank1.armor_class = 15;

var tank2 = new Weapon( 'M1 Abrams' );
tank2.weight      = 20000;
tank2.range       = 200;
tank2.armor_class = 3;

var tank3 = new Weapon( 'Tiger' ); 
tank3.weight      = 14000;
tank3.range       = 120;
tank3.armor_class = 7;

var out1 = tank1.getWeaponInfo();
var out2 = tank2.getWeaponInfo();
var out3 = tank3.getWeaponInfo(); 

function getLowestArmorClass() {
    var tank_array = [ tank1.armor_class, tank2.armor_class, tank3.armor_class ];
    tank_array.sort( function( a, b ) {
        return a - b;
    });
    var lowest = tank_array[0];
    return lowest;
}

//var lowest_armor_class = getLowestArmorClass();
//function findTankWithLowestArmorClass() {
//    let tank_array = [ tank1, tank2, tank3 ];
//    for ( let i of tank_array ) {
//        document.write( "DEBUG: " + i.armor_class ); 
//        if ( i.armor_class == lowest_armor_class ) {
//            return i.type;
//        }
//    }
//}

document.writeln(); 
document.write( out1 ); 
document.writeln(); 
document.write( out2 ); 
document.writeln(); 
document.write( out3 ); 
document.writeln(); 
document.write( 'the winning armor class is: ' + getLowestArmorClass() ); 
document.writeln();
var winning_tank = findTankWithLowestArmorClass(); 
document.write( 'the winning tank is: ' + winning_tank ); 
