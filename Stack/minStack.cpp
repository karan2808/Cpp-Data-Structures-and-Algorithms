#include <iostream>
#include <stack>

using namespace std;
class MinStack
{
    stack<int> regStack;
    stack<int> minStack;

public:
    // push an element to the stack
    void push(int x)
    {
        // if the min stack is empty or if we find a new minimum
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
        // push the elements on the regular stack
        regStack.push(x);
    }
    // pop the top element from the stack
    void pop()
    {
        // if the element to be popped is also the min element
        if (minStack.top() == regStack.top())
            minStack.pop();
        regStack.pop();
    }
    // get the top of the stack
    int top()
    {
        return regStack.top();
    }
    // get min
    int get_min()
    {
        return minStack.top();
    }

    // print all the elements in the normal stack
    void printReg()
    {
        stack<int> temp;
        while (!regStack.empty())
        {
            int x = regStack.top();
            temp.push(x);
            regStack.pop();
            cout << x << " ";
        }
        cout << endl;
        while (!temp.empty())
        {
            int x = temp.top();
            temp.pop();
            regStack.push(x);
        }
    }

    // print all the elements in the minimum stack
    void printMin()
    {
        stack<int> temp;
        while (!minStack.empty())
        {
            int x = minStack.top();
            temp.push(x);
            minStack.pop();
            cout << x << " ";
        }
        cout << endl;
        while (!temp.empty())
        {
            int x = temp.top();
            temp.pop();
            minStack.push(x);
        }
    }
};

int main()
{
    MinStack new_stack;
    new_stack.push(1);
    new_stack.push(-1);
    new_stack.push(100);
    new_stack.push(-1);
    cout << "The elements of regular stack are ";
    new_stack.printReg();
    cout << "The elements of min stack are ";
    new_stack.printMin();
    new_stack.push(50);
    new_stack.push(-10);
    new_stack.push(10);
    new_stack.push(-61);
    cout << "The elements of regular stack are ";
    new_stack.printReg();
    cout << "The elements of min stack are ";
    new_stack.printMin();
    new_stack.pop();
    new_stack.pop();
    new_stack.pop();
    new_stack.pop();
    new_stack.pop();
    new_stack.pop();
    cout << "The elements of regular stack are ";
    new_stack.printReg();
    cout << "The elements of min stack are ";
    new_stack.printMin();
    cout << "Stack top is " << new_stack.top() << endl;
    return 0;
}