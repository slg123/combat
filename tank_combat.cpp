#include <iostream>
#include "weapon.h"

const int TANKS = 3;
int do_tank_combat() {

    using std::cout;
    using std::ios_base;

    Weapon tanks[TANKS] = {
        Weapon( "M1 Abrams", 15000, 130, 9 ), 
        Weapon( "Panzer",    12000,  80, 7 ),
        Weapon( "Sherman",   19000, 110, 3 ) 
    };

    cout << "Tanks:\n";
    for ( int i = 0; i < TANKS; i++ ) {
        tanks[i].show();
    }

    Weapon top = tanks[0];
    for ( int i = 1; i < TANKS; i++ ) {
        top = top.topval( tanks[i] );
    }
    cout << "\nWinner with highest armor class:\n";
    top.show();

    return 0;
}
