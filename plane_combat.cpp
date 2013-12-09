#include <iostream>
#include "weapon.h"

const int PLANES = 3; 
int do_plane_combat() {

    using std::cout;
    using std::ios_base;

    Weapon planes[PLANES] = {
        Weapon( "Grumman F6F Hellcat", 4500, 300, 3 ), 
        Weapon( "Mitsubishi A6M Zero", 2500, 460, 7 ),
        Weapon( "P51-D Mustang",       3500, 400, 9 ) 
    };

    cout << "Planes:\n";
    for ( int i = 0; i < PLANES; i++ ) {
        planes[i].show();
    }

    Weapon top = planes[0];
    for ( int i = 1; i < PLANES; i++ ) {
        top = top.topval( planes[i] );
    }
    cout << "\nWinner with highest armor class:\n";
    top.show();

    return 0;
}
