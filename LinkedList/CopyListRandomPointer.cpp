#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a linked list node
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int val)
    {
        this->val = val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // if no head return
        if (!head)
            return NULL;
        // map from original to new node
        unordered_map<Node *, Node *> NodeMap;
        Node *temp = head;
        // fill the node map
        while (temp)
        {
            NodeMap[temp] = new Node(temp->val);
            temp = temp->next;
        }
        // set temp to head
        temp = head;
        while (temp)
        {
            cout << temp->val << endl;
            // set the next and random pointers
            NodeMap[temp]->next = temp->next ? NodeMap[temp->next] : NULL;
            NodeMap[temp]->random = temp->random ? NodeMap[temp->random] : NULL;
            temp = temp->next;
        }
        // return new head
        return NodeMap[head];
    }
};

int main()
{
    Node *head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(9);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(-1);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;
    head->next->next->next->random = head->next->next->next->next;
    Solution mySol;
    Node *newHead = mySol.copyRandomList(head);
    string isCopy = (newHead != head) ? "Yes" : "No";
    cout << head << endl;
    cout << newHead << endl;
    cout << "Was the linked list copied? " << isCopy << endl;
    return 0;
}