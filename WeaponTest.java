public class WeaponTest {
    public static void main( String[] args ) {
        Weapon tank1 = new Weapon( "Sherman",    10000, 140,  4 );
        Weapon tank2 = new Weapon( "Panzer" ,    15000, 120, 15 );
        Weapon tank3 = new Weapon( "M1 Abrams" , 20000, 180, 12 );

        System.out.println( tank1 ); 
        System.out.println( tank2 );
        System.out.println( tank3 ); 
        System.out.println( tank3.armor_class ); 
    }
}

