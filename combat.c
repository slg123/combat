#include <stdio.h>
#include <string.h>

int do_tank_combat( void );
int do_aircraft_combat( void ); 

struct weapon_info { 
    char   name[30];
    int      weight;
    int armor_class;
};

int main( void ) {

    do_tank_combat();
    printf("\n\n"); 
    do_aircraft_combat(); 

    return 0;
}

int do_tank_combat( void ) {

    struct weapon_info tank1 = { 0 }; 
    strcpy( tank1.name, "Sherman" ); 
    tank1.weight = 10000;
    tank1.armor_class = 5;

    struct weapon_info tank2 = { 0 };
    strcpy( tank2.name, "Panzer" ); 
    tank2.weight = 15000;
    tank2.armor_class = 15;

    struct weapon_info tank3 = { 0 };
    strcpy( tank3.name, "M1 Abrams" ); 
    tank3.weight = 20000;
    tank3.armor_class = 12;

    int tank_armor_classes[3] = { tank1.armor_class, tank2.armor_class, tank3.armor_class };
    int min = tank_armor_classes[0]; 
    for ( int i = 0; i < 3; i++ ) {
        if ( tank_armor_classes[i] < min ) {
            min = tank_armor_classes[i];
        }

    }

    /* get the winning tank name */ 
    for ( int i = 0; i < 3; i++ ) {
        if ( tank_armor_classes[i] == min ) {
            if ( i == 0 ) {
                printf("The winning tank is: %s\n", tank1.name ); 
            } else if ( i == 1 ) {
                printf("The winning tank is: %s\n", tank2.name ); 
            } else if ( i == 2 ) {
                printf("The winning tank is: %s\n", tank3.name ); 
            }
        }
    }

    printf("%s %d %d\n", tank1.name, tank1.weight, tank1.armor_class ); 
    printf("%s %d %d\n", tank2.name, tank2.weight, tank2.armor_class ); 
    printf("%s %d %d\n", tank3.name, tank3.weight, tank3.armor_class ); 
    printf("the winning tank has an armor class of %d\n", min); 



    return 0;
}

int do_aircraft_combat( void ) {

    struct weapon_info aircraft1 = { 0 }; 
    strcpy( aircraft1.name, "Mitsubishi A6M Zero" ); 
    aircraft1.weight = 5200;
    aircraft1.armor_class = 10;

    struct weapon_info aircraft2 = { 0 };
    strcpy( aircraft2.name, "Focke-Wulfe 190" ); 
    aircraft2.weight = 8000;
    aircraft2.armor_class = 13;

    struct weapon_info aircraft3 = { 0 };
    strcpy( aircraft3.name, "Grumman F6F Hellcat" ); 
    aircraft3.weight = 10000;
    aircraft3.armor_class = 4;

    int aircraft_armor_classes[3] = { aircraft1.armor_class, aircraft2.armor_class, aircraft3.armor_class };
    int min = aircraft_armor_classes[0]; 
    for ( int i = 0; i < 3; i++ ) {
        if ( aircraft_armor_classes[i] < min ) {
            min = aircraft_armor_classes[i];
        }
    }

    /* get the winning aircraft name */ 
    for ( int i = 0; i < 3; i++ ) {
        if ( aircraft_armor_classes[i] == min ) {
            if ( i == 0 ) {
                printf("The winning aircraft is: %s\n", aircraft1.name ); 
            } else if ( i == 1 ) {
                printf("The winning aircraft is: %s\n", aircraft2.name ); 
            } else if ( i == 2 ) {
                printf("The winning aircraft is: %s\n", aircraft3.name ); 
            }
        }
    }


    printf("%s %d %d\n", aircraft1.name, aircraft1.weight, aircraft1.armor_class ); 
    printf("%s %d %d\n", aircraft2.name, aircraft2.weight, aircraft2.armor_class ); 
    printf("%s %d %d\n", aircraft3.name, aircraft3.weight, aircraft3.armor_class ); 
    printf("the winning aircraft has an armor class of %d\n", min); 

    return 0;
}


