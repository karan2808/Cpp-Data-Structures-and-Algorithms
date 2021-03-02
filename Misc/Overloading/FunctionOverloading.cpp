/**
 * When there are multiple functions with same name but different parameters then these 
 * functions are said to be overloaded. Functions can be overloaded by change in number
 * arguments or/and change in type of arguments.
 */

#include <iostream>

using namespace std;

class Overload {
    public:
    // function with 1 parameter 
    void func(int x) {
        cout << "Value of x is " << x << endl;
    }
    // function with different type of parameter
    void func(double x) {
        cout << "Value of x is " << x << endl;
    }
    // function with same name and 2 int params
    void func(int x, int y) {
        cout << "Value of x and y is " << x << ", " << y << endl; 
    }
};

int main() {
    Overload ov1;
    // Function depends on the parameters
    ov1.func(7);
    // The second 'func' is called
    ov1.func(9.132);
    // The third 'func' is called 
    ov1.func(85, 64);
    return 0;
}