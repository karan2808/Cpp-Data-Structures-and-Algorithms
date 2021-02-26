#include <iostream>
#include <unordered_map>

using namespace std;

// Definition of a node
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
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

        while (temp)
        {
            NodeMap[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        // go through the nodes again and set next node and random node
        while (temp)
        {
            NodeMap[temp]->next = temp->next ? NodeMap[temp->next] : NULL;
            NodeMap[temp]->random = temp->random ? NodeMap[temp->random] : NULL;
            temp = temp->next;
        }
        return NodeMap[head];
    }
};

int main()
{
    Node *root = new Node(5);
    root->random = new Node(7);
    root->next = new Node(6);
    root->next->random = new Node(8);
    root->next->next = root->random;
    Solution mySol;
    string isEq = mySol.copyRandomList(root) == root ? "yes" : "no";
    cout << isEq << endl;
}