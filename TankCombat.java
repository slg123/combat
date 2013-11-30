public class TankCombat {
    public static void main( String[] args ) {
        Weapon tank1 = new Weapon( "Sherman",    10000, 140, 20 );
        Weapon tank2 = new Weapon( "Panzer" ,    15000, 120, 13 );
        Weapon tank3 = new Weapon( "M1 Abrams" , 20000, 180,  3 );

        System.out.println( tank1 ); 
        System.out.println( tank2 );
        System.out.println( tank3 ); 
        System.out.println( tank3.armor_class ); 

        int armor_class_array[] = new int[3];
        armor_class_array[0] = tank1.armor_class;
        armor_class_array[1] = tank2.armor_class;
        armor_class_array[2] = tank3.armor_class;
 
        int lowest_armor_class = armor_class_array[0];
        for ( int i = 0; i < 3; i++ ) {
            if ( armor_class_array[i] < lowest_armor_class ) {
                lowest_armor_class = armor_class_array[i];
            }
        }

        for ( int i = 0; i < 3; i++ ) {
            if ( armor_class_array[i] == lowest_armor_class ) {
                if ( i == 0 ) {
                    System.out.printf( "The winning tank is: %s\n", tank1.weapon_name ); 
                } else if ( i == 1 ) {
                    System.out.printf( "The winning tank is: %s\n", tank2.weapon_name ); 
                } else if ( i == 2 ) {
                    System.out.printf( "The winning tank is: %s\n", tank3.weapon_name ); 
                }
            }
        }
        System.out.printf( "the winning tank has armor class: %d\n", lowest_armor_class ); 
    }
}

