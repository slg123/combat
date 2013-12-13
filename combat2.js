var weapons = {
    "tank1": {
        type: "Sherman",
        weight: 10000,
        range: 130,
        armor_class: 15
    },

    "tank2": {
        type: "M1 Abrams", 
        weight: 20000,
        range: 130,
        armor_class: 3
    },

    "tank3": {
        type: "Tiger",
        weight: 14000,
        range: 120,
        armor_class: 7
    },

    "plane1": {
        type: "P51-D Mustang",
        weight: 3000,
        range: 450,
        armor_class: 12
    },

    "plane2": {
        type: "Grumman F6F Hellcat",
        weight: 5000,
        range: 340,
        armor_class: 2
    },

    "plane3": {
        type: "Focke-Wulfe 190",
        weight: 4500,
        range: 300,
        armor_class: 7
    }
}

function getLowestTankArmorClass() {
    var tank_array = [ weapons.tank1.armor_class, weapons.tank2.armor_class, weapons.tank3.armor_class ];
    tank_array.sort( function( a, b ) {
        return a - b;
    });
    var lowest = tank_array[0];
    return lowest;
}

function getWinningTank() {
    var lowest = getLowestTankArmorClass();
    if ( lowest == weapons.tank1.armor_class ) {
        return weapons.tank1.type;
    } else if ( lowest == weapons.tank2.armor_class ) {
        return weapons.tank2.type;
    } else if ( lowest == weapons.tank3.armor_class ) {
        return weapons.tank3.type;
    }
}

document.writeln(); 
document.writeln( 'the winning tank armor class is: ' + getLowestTankArmorClass() ); 
document.writeln( 'the winning tank is: ' + getWinningTank() ); 

function getLowestPlaneArmorClass() {
    var plane_array = [ weapons.plane1.armor_class, weapons.plane2.armor_class, weapons.plane3.armor_class ];
    plane_array.sort( function( a, b ) {
        return a - b;
    });
    var lowest = plane_array[0];
    return lowest;
}

function getWinningPlane() {
    var lowest = getLowestPlaneArmorClass();
    if ( lowest == weapons.plane1.armor_class ) {
        return weapons.plane1.type;
    } else if ( lowest == weapons.plane2.armor_class ) {
        return weapons.plane2.type;
    } else if ( lowest == weapons.plane3.armor_class ) {
        return weapons.plane3.type;
    }
}

document.writeln( 'the winning plane armor class is: ' + getLowestPlaneArmorClass() ); 
document.writeln( 'the winning plane is: ' + getWinningPlane() ); 

