#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
    queue<int> q;

public:
    // push element onto stack
    void push(int x)
    {
        q.push(x);
        // rotate the queue, get element x in front
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    // get the element from top of the stack
    int pop()
    {
        int top_val = q.front();
        q.pop();
        return top_val;
    }
    // get the top element
    int top()
    {
        return q.front();
    }
    // check if stack is empty
    bool empty()
    {
        return q.empty();
    }
    // print elements in the stack
    void print_elements()
    {
        queue<int> temp;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            temp.push(x);
            cout << x << " ";
        }
        q = temp;
        cout << endl;
    }
};

int main()
{
    MyStack q_stack;
    q_stack.push(40);
    q_stack.push(1);
    q_stack.push(-1);
    q_stack.push(8);
    q_stack.push(9);
    q_stack.push(-88);
    q_stack.push(4400);
    q_stack.push(-369);
    cout << "The elements of the stack are ";
    q_stack.print_elements();
    q_stack.pop();
    q_stack.pop();
    q_stack.pop();
    q_stack.pop();
    q_stack.pop();
    q_stack.pop();
    cout << "The elements of the stack are ";
    q_stack.print_elements();
    return 0;
}