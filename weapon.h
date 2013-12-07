
class Weapon {
    public:
        char m_weapon_name[35];
        int  m_weight;
        int  m_range;
        int  m_armor_class;
        char m_type[35]; 
        Weapon(); // default constructor
        Weapon( const char *s, int wt = 0, int rng = 0, int ac = 0 );
        ~Weapon();
        void show_attributes() const;
}; 
