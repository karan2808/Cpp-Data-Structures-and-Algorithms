#include <iostream>
using namespace std;

class circular_queue
{
    int *que_buff;
    int front, back;
    int MAX_SIZE;

public:
    circular_queue(int buff_size = 20)
    {
        MAX_SIZE = buff_size;
        // initialize the buffer with max size
        que_buff = new int[MAX_SIZE];
        // intial positions of the pointer when queue is empty
        front = back = -1;
        // set all values to 0
        memset(que_buff, 0, sizeof(int) * MAX_SIZE);
    }
    ~circular_queue()
    {
        delete que_buff;
    }
    // display all elements
    void display_elements();
    // enque a val
    void enque(int val);
    // get the last element
    int deque();
    // check if queue is empty
    bool isEmpty();
};

// enque an element to the queue
void circular_queue::enque(int item)
{
    // check if queue is full
    if ((back + 1) % MAX_SIZE == front)
    {
        cout << "Queue Full" << endl;
        return;
    }
    // increment the back pointer
    back = (back + 1) % MAX_SIZE;
    // put the element in the queue
    que_buff[back] = item;
    // if first element, increment front
    if (front == -1)
        front = 0;
}

// deque an element
int circular_queue::deque()
{
    // check if queue is empty
    if (front == -1)
    {
        cout << "Queue Empty" << endl;
        return -1;
    }
    // get front element
    int data = que_buff[front];
    // set front to 0 so the element is popped
    que_buff[front] = 0;
    // if all the elements are removed, reset
    if (front == back)
    {
        back = -1;
        front = -1;
    }
    else
    {
        // increment front
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}

// display all the elements in the queue
void circular_queue::display_elements()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << que_buff[i] << " ";
    }
    cout << endl;
}

bool circular_queue::isEmpty()
{
    if (front == -1 && back == -1)
    {
        cout << "Queue is empty" << endl;
        return true;
    }
    return false;
}

int main()
{
    circular_queue cq(20);
    cq.enque(1);
    cq.enque(2);
    cq.enque(3);
    cq.enque(4);
    cq.display_elements();
    cq.enque(9);
    cq.enque(-1);
    cq.enque(0);
    cout << "deque item" << cq.deque() << endl;
    int j = cq.deque();
    cq.display_elements();
    cq.enque(9);
    cq.enque(-1);
    cq.enque(0);
    cq.enque(19);
    cq.enque(-21);
    cq.enque(40);
    cq.enque(9);
    cq.enque(-1);
    cq.enque(99);
    cq.enque(19);
    cq.enque(-21);
    cq.enque(40);
    j = cq.deque();
    cq.display_elements();
    return 0;
}