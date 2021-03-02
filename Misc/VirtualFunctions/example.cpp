#include <iostream>

using namespace std;

class base
{
public:
    virtual void print()
    {
        cout << "Print base class " << endl;
    }
    void show()
    {
        cout << "Show base class " << endl;
    }
};

class derived : public base
{
public:
    void print()
    {
        cout << "Print derived class " << endl;
    }
    void show()
    {
        cout << "Show derived class " << endl;
    }
};

int main()
{
    base *bptr;
    derived d;
    bptr = &d;
    // virtual function binded at runtime
    bptr->print();
    // Non-virtual function, binded at compile time
    bptr->show();
}

/** Runtime polymorphism is achieved only through a pointer (or reference) of base class type.
 * Also, a base class pointer can point to the objects of base class as well as to the objects of derived class. 
 * In above code, base class pinter 'bptr' contains the address of object 'd' of derived class.
 * Late binding (Runtime) is done in accordance with the content of pointer (i.e location pointed to by pointer)
 * Early binding (Compile time) is done accoring to the type of the pointer, since print() function is declared 
 * with virtual keyword so it will be bound at run time (output is print derived class as pointer is pointing to object
 * of the derived class) and show () is non virtual so it will be bound at compile time (output is show base class as pointer
 * is of type base).
 * 
 * Virtual keyword is not needed in the derived class, the functions get automatically overriden.
 */