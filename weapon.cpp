#include <iostream>
#include <cstring>
#include "weapon.h"

Weapon::Weapon() {
    m_weapon_type = "no name"; 
    m_weight      = 0;
    m_range       = 0;
    m_armor_class = 0;
}

Weapon::Weapon( const char *wt, int w, int r, int ac ) {
    m_weapon_type = wt; 
    m_weight      = w;
    m_range       = r;
    m_armor_class = ac;
}

Weapon::~Weapon() {
}

void Weapon::show() const {
    using std::cout;
    using std::endl;
    cout << m_weapon_type << ' ' << m_weight << ' ' << m_range << ' ' << m_armor_class << endl;
}

const Weapon &Weapon::topval( const Weapon &w ) const {
    if ( w.m_armor_class > m_armor_class ) {
        return w;
    } else {
        return *this;
    }
}
