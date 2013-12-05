#include <iostream>
#include <cstring>
#include "weapon.h"

using std::cout;
using std::endl;

void do_tank_combat();
void do_plane_combat();

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

    do_tank_combat();
    cout << endl;
    do_plane_combat();

    return 0;
}

void do_tank_combat() {

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
}

void do_plane_combat() {

    const int PLANES = 3;
    Weapon planes[PLANES] = {
        Weapon( "Mitsubishi Zero",     2500, 300, 4 ),
        Weapon( "P51 Mustang",         3500, 460, 8 ),
        Weapon( "Grumman F6F Hellcat", 4500, 325, 1 )
    };

    for ( int i = 0; i < PLANES; i++ ) {
        planes[i].show_attributes();
    }

    // get minimum plane armor class
    int min = planes[1].armor_class;
    for ( int i = 0; i < PLANES; i++ ) {
        if ( planes[i].armor_class <= min ) {
            min = planes[i].armor_class;
        }
    }
    cout << "lowest armor class: " << min << endl;

    for ( int i = 0; i < PLANES; i++ ) {
        if ( planes[i].armor_class == min ) {
            if ( i == 0 ) {
                cout << "the winning plane is: " << planes[i].weapon_name << endl;
            } else if ( i == 1 ) {
                cout << "the winning plane is: " << planes[i].weapon_name << endl;
            } else if ( i == 2 ) {
                cout << "the winning plane is: " << planes[i].weapon_name << endl;
            }
        }
    }
}
