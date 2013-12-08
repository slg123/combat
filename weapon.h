#ifndef WEAPON_H_
#define WEAPON_H_

class Weapon {
    private:
        char m_weapon_type[30];
        int  m_weight;
        int  m_range;
        int  m_armor_class;
    public:
        Weapon();
        Weapon( const char *weapon_type, int w = 0, int r = 0, int ac = 0 );
        ~Weapon();
        void show() const;
        const Weapon &topval( const Weapon &w ) const;
};

#endif


