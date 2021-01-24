#include <iostream>

using namespace std;

class CustomStack_Array
{
    int *stkArr;
    int stkSize;
    // keep a track of number of elements or top position
    int stkTop;

public:
    // constructor
    CustomStack_Array(int maxSize)
    {
        stkArr = new int[maxSize];
        stkTop = 0;
        stkSize = maxSize;
    }
    // destructor
    ~CustomStack_Array()
    {
        delete stkArr;
    }
    // push an element to the stack
    void push(int x)
    {
        if (stkTop < stkSize)
        {
            stkArr[stkTop++] = x;
        }
    }
    // pop an element from the top of the stack and return it, if empty return -1
    int pop()
    {
        if (stkTop)
        {
            // 0 based indexing
            return stkArr[--stkTop];
        }
        return -1;
    }

    // increment the bottom k elements of the stack by val
    void increment(int k, int val)
    {
        for (int i = 0; i < stkTop && i < k; i++)
        {
            stkArr[i] += val;
        }
    }

    void printElements()
    {
        for (int i = 0; i < stkTop; i++)
        {
            cout << stkArr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CustomStack_Array csa(10);
    csa.push(6);
    csa.push(66);
    csa.push(7);
    csa.push(5);
    csa.push(99);
    csa.push(8);
    csa.push(4);
    cout << "Elements in the stack are: ";
    csa.printElements();
    int x = csa.pop();
    x = csa.pop();
    x = csa.pop();
    x = csa.pop();
    cout << "Top element of stack is: " << csa.pop() << endl;
    cout << "Elements in the stack are: ";
    csa.printElements();
    return 0;
}