#include <iostream>
using namespace std;

//Base Class Person
class Person {
protected:
    //data member
    string name;

public:
    //member functions
    void get_name() {
        cout << "Enter Name:\t";
        cin >> name;
    }

    void put_name() {
        cout << name;
    }

    //Pure Virtual member functions
    virtual void get_data() = 0;
    virtual bool is_outstanding() = 0;
};


//Derived Classes Student & Professor
class Student : public Person {
private:
    //data member
    float gpa;

public:
    //overridden virtual functions
    void get_data() {
        get_name();
        cout << "Enter GPA:\t";
        cin >> gpa;
    }

    bool is_outstanding() {
        if (gpa > 7) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Professor : public Person {
private:
    //data member
    int published;

public:
    //overridden virtual functions
    void get_data() {
        get_name();
        cout << "Enter # of Publications:\t";
        cin >> published;
    }

    bool is_outstanding() {
        if (published > 100) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{
    int i;
    Student s1, s2, s3;
    Professor p1, p2, p3;
    Person* arr[6] = {&s1, &s2, &s3, &p1, &p2, &p3};

    for (i = 0; i < 6; i++) {
        arr[i]->get_data();
    }

    for (i = 0; i < 6; i++) {
        if (i < 4) {
            cout << "\n\nStudent:\t";
        }
        else {
            cout << "\n\nProfessor:\t";
        }

        arr[i]->put_name();
        if (arr[i]->is_outstanding() == true) {
            cout << "\nThis person is outstanding!";
        }
    }
}