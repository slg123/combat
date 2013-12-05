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
    const int TANKS = 3;
    Weapon tanks[TANKS] = {
        Weapon( "M1 Abrams", 15000, 130, 9 ),
        Weapon( "Panzer",    12000,  80, 7 ),
        Weapon( "Sherman",   19000, 110, 3 )
    };

    // show all tank attributes
    for ( int i = 0; i < TANKS; i++ ) {
        tanks[i].show_attributes(); 
    }

    // get minimum tank armor class
    int min = tanks[1].armor_class;
    for ( int i = 0; i < TANKS; i++ ) {
        if ( tanks[i].armor_class <= min ) {
            min = tanks[i].armor_class;
        }
    }
    cout << "lowest armor class: " << min << endl;

    // get the winning tank name - tank with the lowest armor class
    for ( int i = 0; i < TANKS; i++ ) {
        if ( tanks[i].armor_class == min ) {
            if ( i == 0 ) {
                cout << "the winning tank is: " << tanks[i].weapon_name << endl;
            } else if ( i == 1 ) {
                cout << "the winning tank is: " << tanks[i].weapon_name << endl;
            } else if ( i == 2 ) {
                cout << "the winning tank is: " << tanks[i].weapon_name << endl;
            }
        }
    }
    return 0;
}
