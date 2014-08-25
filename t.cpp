#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define NAME_SIZE 50
#define FOO_SIZE 10

class Person {
  public:
    int id;
    char name[NAME_SIZE]; 
    char foo[FOO_SIZE];
    void aboutMe() {
        cout << "I am a person." << endl;
    }
};

class Student : public Person {
  public:
    void aboutMe() {
        cout << "I am a student." << endl;
    }
};

class IntergalacticBattleship {
  public:
    char name[NAME_SIZE]; 
    void fartThruTheGalaxy( char name[] ) {
        cout << name << endl; 
        cout << "We are tearing ass all over the galaxy!" << endl;
    }
    IntergalacticBattleship(); 
    ~IntergalacticBattleship(); // dtor
};
    
IntergalacticBattleship::~IntergalacticBattleship() {
    IntergalacticBattleship *igb1, *igb2, *igb3;
    delete igb1;
    delete igb2;
    delete igb3;
}

int main() {

    IntergalacticBattleship *igb1, *igb2, *igb3;

    char name[NAME_SIZE] = "Ignignot"; 
    char oname[NAME_SIZE] = "Urr"; 

    igb1->fartThruTheGalaxy( name ); 
    igb1->fartThruTheGalaxy( oname ); 
    igb2->fartThruTheGalaxy( name ); 
    igb2->fartThruTheGalaxy( oname ); 
    igb3->fartThruTheGalaxy( name ); 
    igb3->fartThruTheGalaxy( oname ); 

    Student *p = new Student();
    p->id = 92; 

    cout << "Enter a name: "; 
    cin >> p->name; 
    cout << "Enter a foo: ";
    cin >> p->foo;
    if ( strlen(p->foo) > 10 ) {
        cout << p->foo << "greater than 10 chars." << endl;
        exit( EXIT_FAILURE );
    }
    cout << p->id << endl; 
    cout << p->name << endl; 
    cout << p->foo << endl; 
    p->aboutMe(); 

    delete p;

    Person *n = new Person();
    n->id = 93;
    cout << n->id << endl; 
    n->aboutMe();

    delete n;

    return 0;
}
