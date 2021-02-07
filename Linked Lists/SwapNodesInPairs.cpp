#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *flip(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        if (!head->next)
        {
            return NULL;
        }
        else
        {
            // current node is head nodes next
            // head->current
            ListNode *B = head->next;
            // flip the current nodes next
            // head->current->(flip...)
            ListNode *C = flip(B->next);
            // current nodes next is head
            // head<-current
            B->next = head;
            // heads next is flipped nodes
            // current->head->(flip...)
            head->next = C;
            return B;
        }
    }

public:
    ListNode *swapPairs(ListNode *head)
    {
        return flip(head);
    }
};

int main()
{
    Solution mySol;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(4);
    root->next->next = new ListNode(5);
    root->next->next->next = new ListNode(6);
    root->next->next->next->next = new ListNode(8);
    root->next->next->next->next->next = new ListNode(9);

    ListNode *finalRoot = mySol.flip(root);
    while (finalRoot)
    {
        cout << finalRoot->val << " " << endl;
        finalRoot = finalRoot->next;
    }
    return 0;
}
