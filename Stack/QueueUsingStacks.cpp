#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
    stack<int> stk1;
    stack<int> stk2;
    int front;

public:
    // push an element to the back of the queue
    void push(int x)
    {
        // if the queue is empty, the new element becomes front
        if (stk1.empty())
        {
            front = x;
        }
        // empty stack 1 into stack2
        while (!stk1.empty())
        {
            int y = stk1.top();
            stk1.pop();
            stk2.push(y);
        }
        // push the num on stack 2
        stk2.push(x);
        // empty stack2 back into stack 1
        while (!stk2.empty())
        {
            int y = stk2.top();
            stk2.pop();
            stk1.push(y);
        }
    }
    // Remove and return the top element of the queue
    int pop()
    {
        front = stk1.top();
        stk1.pop();
        return front;
    }
    // get the element from the front
    int peek()
    {
        front = stk1.top();
        return front;
    }
    // returns whether queue is empty
    bool empty()
    {
        return stk1.empty();
    }

    void print_elements()
    {
        while (!stk1.empty())
        {
            int x = stk1.top();
            stk1.pop();
            stk2.push(x);
            cout << x << " ";
        }
        cout << endl;
        while (!stk2.empty())
        {
            int x = stk2.top();
            stk2.pop();
            stk1.push(x);
        }
    }
};

int main()
{
    MyQueue que;
    que.push(5);
    que.push(15);
    que.push(8);
    que.push(-1);
    que.print_elements();
    int x = que.pop();
    que.print_elements();
    cout << "Front element is " << que.peek() << endl;
    que.print_elements();
    string is_empty = que.empty() ? "Yes" : "No";
    cout << "Is the queue empty: " << is_empty << endl;
    x = que.pop();
    x = que.pop();
    x = que.pop();
    que.print_elements();
    is_empty = que.empty() ? "Yes" : "No";
    cout << "Is the queue empty: " << is_empty << endl;
    return 0;
}