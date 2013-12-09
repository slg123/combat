#include <iostream>
#include "weapon.h"

int do_tank_combat(); 
int do_plane_combat(); 

int main() {
    do_tank_combat(); 
    std::cout << std::endl;
    do_plane_combat();
    return 0;
}
