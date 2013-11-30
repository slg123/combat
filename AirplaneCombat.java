public class AirplaneCombat {
    public static void main( String[] args ) {
        Weapon airplane1 = new Weapon( "Mitsubishi A6M Zero",   5200, 750, 10 );
        Weapon airplane2 = new Weapon( "Focke-Wulfe 190",       8000, 450, 13 );
        Weapon airplane3 = new Weapon( "Grumman F6F Hellcat" , 10000, 550,  4 );

        System.out.println( airplane1 ); 
        System.out.println( airplane2 );
        System.out.println( airplane3 ); 

        int armor_class_array[] = new int[3];
        armor_class_array[0] = airplane1.armor_class;
        armor_class_array[1] = airplane2.armor_class;
        armor_class_array[2] = airplane3.armor_class;
 
        int lowest_armor_class = armor_class_array[0];
        for ( int i = 0; i < 3; i++ ) {
            if ( armor_class_array[i] < lowest_armor_class ) {
                lowest_armor_class = armor_class_array[i];
            }
        }

        for ( int i = 0; i < 3; i++ ) {
            if ( armor_class_array[i] == lowest_armor_class ) {
                if ( i == 0 ) {
                    System.out.printf( "The winning airplane is: %s\n", airplane1.weapon_name ); 
                } else if ( i == 1 ) {
                    System.out.printf( "The winning airplane is: %s\n", airplane2.weapon_name ); 
                } else if ( i == 2 ) {
                    System.out.printf( "The winning airplane is: %s\n", airplane3.weapon_name ); 
                }
            }
        }
        System.out.printf( "the winning airplane has armor class: %d\n", lowest_armor_class ); 
    }
}

