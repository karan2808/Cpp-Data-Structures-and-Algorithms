#include <iostream>
using namespace std;

class circular_deque {
    int *q;
    int front, rear;
    int max_size;
    public:
    circular_deque (int sz = 10) {
        q = new int[sz];
        max_size = sz;
        front = rear = -1;
        memset(q, 0, sizeof(int) * max_size);
    }
    ~circular_deque() {
        delete q;
    }
    // display all elements in the deque
    void display_elements ();
    // insert at the front of the deque
    void insert_Front (int val);
    // insert at the back of the deque
    void insert_Last (int val);
    // get the first element
    int get_Front ();
    // get the last element
    int get_Rear();
    // delete the first element
    void delete_Front();
    // delete the last element
    void delete_Rear(); 
    // check if deque is full
    bool isFull();
    // check if it's empty
    bool isEmpty();
    // get the index of front or back
    int get_idx(int idx);
};

void circular_deque::display_elements(){
    for (int i = 0; i < max_size; i++) {
        cout << q[i] << " ";
    } 
    cout << endl;
}

int circular_deque::get_idx(int idx) {
    if (idx < 0) {
        return max_size + idx;
    } 
    return idx % max_size;
}

void circular_deque::insert_Front(int val) {
    // if the queue is full return false
    if (isFull()) {
        cout << "Deque is full.." << endl;
        return;
    }
    // if no elemnets in the queue, set pointers to 0
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        // decrement front
        front = get_idx(--front);
    }
    q[front] = val;
    cout << "Inserted element.." << endl;
    return;
}

void circular_deque::insert_Last(int val) {
    if (isFull()) {
        cout << "Deque is full.." << endl;
        return;
    }
    // if it's the first element, set pointers to 0
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        // increment rear
        rear = get_idx(++rear);
    }
    q[rear] = val;
    cout << "Inserted element.." << endl;
    return;
}

void circular_deque::delete_Front() {
    if (isEmpty()) {
        cout << "Deque is empty.." << endl;
        return;
    }
    // if there's only one element in the deque, reset
    if (front == rear) {
        q[front] = 0;
        front = rear = -1;
    } else {
        // else increment front
        q[front] = 0;
        front = get_idx(++front);
    }
    cout << "Element deleted from front.." << endl;
    return;
}

void circular_deque::delete_Rear() {
    if (isEmpty()) {
        cout << "Deque is empty.." << endl;
        return;
    }
    // if there's only one element in the deque, reset
    if (front == rear) {
        q[rear] = 0;
        front = rear = -1;
    } else {
        q[rear] = 0;
        // decrement rear
        rear = get_idx(--rear);
    }
    cout << "Element deleted from rear.." << endl;
    return;
}

int circular_deque::get_Front() {
    // queue is empty return -1
    return isEmpty() ? -1 : q[front];
}

int circular_deque::get_Rear() {
    return isEmpty() ? -1 : q[rear];
}

bool circular_deque::isEmpty() {
    return (rear == -1 && front == -1);
}

bool circular_deque::isFull() {
    // can have two cases, rear is at the end, or otherwise
    return (rear == max_size - 1 && front == 0) || (rear < front && front == rear + 1);
}


int main()
{
    circular_deque cdq(20);
    cdq.insert_Front(1);
    cdq.insert_Front(32);
    cdq.insert_Last(32);
    cdq.insert_Last(32);
    cdq.insert_Front(-1);
    cdq.insert_Front(2);
    cdq.display_elements();
    cdq.insert_Last(3);
    cdq.insert_Last(2);
    cdq.insert_Front(10);
    cdq.insert_Front(99);
    cdq.insert_Last(11);
    cdq.insert_Last(23);
    cdq.display_elements();
    cdq.insert_Front(1);
    cdq.insert_Front(32);
    cdq.insert_Last(32);
    cdq.insert_Last(32);
    cdq.insert_Front(-1);
    cdq.insert_Front(2);
    cdq.display_elements();
    cdq.insert_Last(3);
    cdq.insert_Last(2);
    cdq.insert_Front(10);
    cdq.insert_Front(99);
    cdq.insert_Last(11);
    cdq.insert_Last(23);
    cdq.display_elements();
    cout << "deque item from front " << cdq.get_Front() << endl;
    cout << "deque item from rear " << cdq.get_Rear() << endl;
    cdq.delete_Front();
    cdq.display_elements();
    cdq.delete_Rear();
    cdq.display_elements();
    cout << "Is the deque full? " << cdq.isFull() << endl;
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.display_elements();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.delete_Front();
    cdq.display_elements();
    return 0;
}

