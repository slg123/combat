#include <iostream>

using namespace std;
int doStringSearch( char name[], char text[], char hits[] ); 

int main()
{
    char text[] = "text with the string Scott in it";
    char name[] = "Scott";
    char hits[] = {};
    doStringSearch( name, text, hits );
    return 0;
}

int doStringSearch( char name[], char text[], char hits[] ) 
{
    int name_length = ( sizeof( name ) / sizeof( char ) );
    int text_length = ( sizeof( text ) / sizeof( char ) );

    int i, j, k;
    k = 0;
    for ( i = 0; i < text_length; i++ ) {
        if ( text[i] == name[0] ) {
            for ( j = i; j < name_length; j++ ) {
                hits[k] = text[j];
                ++k;
            }
        }
    }

    for ( i = 0; i < name_length; i++ ) {
        cout << hits[i];
    }
    cout << endl;
    return 0;
}
