#include <iostream>
#include <cstring>
#include "weapon.h"

using std::cout;
using std::endl;

/* default constructor */
Weapon::Weapon() {
    std::strcpy( weapon_name, "no name" );
    weight = 0;
    range = 0;
    armor_class = 0;
}

Weapon::Weapon( const char *nm, int wt, int rng, int ac ) {
    std::strncpy( weapon_name, nm, 34 );
    weapon_name[34] = '\0';
    weight = wt;
    range = rng;
    armor_class = ac;
}

Weapon::~Weapon() {
}

void Weapon::show_attributes() const {
    cout << weapon_name << ' ' << weight << ' ' << range << ' ' << armor_class << endl;
}

int main() {

    Weapon tank1( "M1 Abrams", 15000, 130,  9 ); 
    Weapon tank2( "Panzer",    12000,  80,  7 ); 
    Weapon tank3( "Sherman",   15000, 110,  3 ); 

    int armor_classes[3] = { tank1.armor_class, tank2.armor_class, tank3.armor_class };

    tank1.show_attributes();
    tank2.show_attributes();
    tank3.show_attributes();

    int min = tank1.armor_class;
    for ( int i = 0; i < 3; i++ ) {
        if ( armor_classes[i] <= min ) {
            min = armor_classes[i];
        }
    }

    cout << "lowest armor class: " << min << endl;

    /* get the winning tank name - the tank with the lowest armor class */
    for ( int i = 0; i < 3; i++ ) {
        if ( armor_classes[i] == min ) {
            if ( i == 0 ) {
                cout << "the winning tank is: " << tank1.weapon_name << endl;
            } else if ( i == 1 ) {
                cout << "the winning tank is: " << tank2.weapon_name << endl;
            } else if ( i == 2 ) {
                cout << "the winning tank is: " << tank3.weapon_name << endl;
            }
        }
    }
    return 0;
}
