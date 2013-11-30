public class Weapon {
    public String  weapon_name;
    public int     weight;
    public int     range;
    public int     armor_class;

    public Weapon( String n, int w, int r, int ac ) {
        weapon_name = n;
        weight      = w;
        range       = r;
        armor_class = ac;
    }

    public String toString() {
        return String.format( "%15s %6d %6d %6d", weapon_name, weight, range, armor_class ); 
    }
}
