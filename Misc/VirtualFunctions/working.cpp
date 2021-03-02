/** Working of the virtual functions (concept of VTABLE and VPTR).
 *  1. If object of that class is created then a virtual pointer (VPTR) is inserted as a data member
 *     of the class to point to VTABLE of that class. For each new object created, a new virtual
 *     pointer is inserted as a data member of that class.
 *  2. Irrespective of object is created or not, a static array of function pointer called VTABLE where
 *     where each cell containes the address of each virtual function is contained in that class.
 *              
 *                                  address of base version of func(2) VTABLE for base class
 * 
 *  P -> | Object 1 VPTR | ->       address of derived version of func(2) VTABLE for derived class
 * 
 * Initially, we create a pointer of type base class and initialize it with the address of the derived
 * class object. When we create an object of the derived class, the compiler creates a pointer as a
 * data member of the class containing the address of VTABLE of the derived class.
 * 
 * Similar concept of Late and Early binding is used in the example below.
 */

#include <iostream>

using namespace std;

class base 
{
    public:
    void fun_1() {
        cout << "Base-1 \n";
    }
    virtual void fun_2() {cout << "Base-2 \n";}
    virtual void fun_3() {cout << "Base-3 \n";}
    virtual void fun_4() {cout << "Base-4 \n";}
};

class derived : public base
{
public:
    void fun_1() { cout << "Derived-1 \n"; }
    void fun_2() { cout << "Derived-2 \n"; }
    void fun_4(int x) { cout << "Derived-4 \n"; }
};

int main()
{
    base *p;
    derived obj1;
    p = &obj1;
    // Early binding because fun1() is non virtual in base
    p->fun_1();
    // Late binding (RTP)
    p->fun_2();
    // Late binding (RTP)
    p->fun_3();
    // Late binding (RTP)
    p->fun_4();
    // Early binding but this function call is illegal (produces error) because pointer is of base type
    // and function is of derived class
    // p->fun_4(5); ->ERROR
}