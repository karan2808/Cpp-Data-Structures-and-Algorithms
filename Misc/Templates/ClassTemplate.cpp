// Simple calculator using class template. Source: https://www.programiz.com/cpp-programming/templates.
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Calculator
{
private:
    T num1, num2;

    T add()
    {
        return num1 + num2;
    }

    T sub()
    {
        return num1 - num2;
    }

    T multiply()
    {
        return num1 * num2;
    }

    T divide()
    {
        return num1 / num2;
    }

public:
    Calculator(T num1, T num2)
    {
        this->num1 = num1;
        this->num2 = num2;
    }

    void displayResult()
    {
        cout << "Number are: " << num1 << " and " << num2 << endl;
        cout << "Addition is: " << add() << endl;
        cout << "Subtraction is: " << sub() << endl;
        cout << "Product is: " << multiply() << endl;
        cout << "Division is: " << divide() << endl;
    }
};

int main()
{
    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results: " << endl;
    intCalc.displayResult();

    cout << "Float results: " << endl;
    floatCalc.displayResult();

    return 0;
}