/** The diamond problem:
 * 
 * The diamond problem occurs when two superclasses of a class have a common base class.
 * If classes Student and Faculty inherit from class Person, and a class TA inherits from
 * classes Student and Faculty, the attributes of class Person are passed to the class TA
 * twice. 
 * 
 * Both constuctors and destructors of the class will be called twice. The solution to this
 * problem is to use virtual functions. Faculty and Student class may be made virtual base
 * classes to avoid two copies of 'Person' in 'TA' class. 
 */

#include <iostream>

using namespace std;

class Person
{
public:
    Person(int x)
    {
        cout << "Person::Person(int) " << endl;
        cout << "--------" << endl;
    }
};

class Faculty : public Person
{
public:
    Faculty(int x) : Person(x)
    {
        cout << "Faculty::Faculty(int) called" << endl;
        cout << "+++++++++" << endl;
    }
};

class Student : public Person
{
public:
    Student(int x) : Person(x)
    {
        cout << "Student::Student(int) called" << endl;
        cout << "//////////" << endl;
    }
};

class TA: public Faculty, public Student
{
    public:
    TA(int x) : Student(x), Faculty(x) 
    {
        cout << "TA::TA(int) called" << endl;
        cout << "**********" << endl;
    }
};

int main()
{
    TA ta1(30);
}