#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>

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

int main() {

    Student *p = new Student();
    p->id = 666; 

    cout << "Enter a name: "; 
    cin >> p->name; 
    cout << "Enter a foo: ";
    cin >> p->foo;
    if ( strlen(p->foo) > 10 ) {
        int l = strlen( p->foo ); 
        cout << "l is greater than 10 chars." << endl;
        cout << " no bueno. " << endl;
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
