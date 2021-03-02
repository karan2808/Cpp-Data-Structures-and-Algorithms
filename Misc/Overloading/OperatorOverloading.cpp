/**
 * Operator Overloading: C++ provides option to overload operators. For example, we can make the operator ('+') for string
 * class to concatenate two strings. We know that this is the addition operator whose task is to add two operands. So a
 * single operator '+' when placed between integer operands, adds them and when placed between string operands, concatenates
 * them.
 */

#include <iostream>

using namespace std;

class Complex
{
private:
    int real, imaginary;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }
    // This is automatically called when '+' is used between two complex objects
    Complex operator + (Complex const &obj) {
        Complex result;
        result.real = real + obj.real;
        result.imaginary = imaginary + obj.imaginary;
        return result;
    }
    void print()
    {
        cout << real << " + i" << imaginary << endl;
    }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // an example call to the overloaded operator
    c3.print();
}