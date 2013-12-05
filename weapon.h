
class Weapon {
    public:
        char weapon_name[35];
        int weight;
        int range;
        int armor_class;
        Weapon(); // default constructor
        Weapon( const char *s, int wt = 0, int rng = 0, int ac = 0 );
        ~Weapon();
        void show_attributes();
}; 
