#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // keep two heads, and a pointer to point to the node to remove
        ListNode* head1 = list1, *head2 = list2;
        ListNode* removeHead;
        // go till node b
        while(b > 0) {
            // if node a has been reached, store the current head
            if (a > 0) {
                removeHead = list1;
            }
            // keep traversing, until node b has been reached
            list1 = list1->next;
            b--;
            a--;
        }
        // go to the end of list 2
        while (list2->next != nullptr) {
            list2 = list2->next;
        }
        // link the two lists
        removeHead->next = head2;
        list2->next = list1->next;
        return head1;
    }
};

int main() {
    Solution mySol;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(4);
    root->next->next = new ListNode(5);
    root->next->next->next = new ListNode(6);
    root->next->next->next->next = new ListNode(8);
    root->next->next->next->next->next = new ListNode(9);
    ListNode *root1 = new ListNode(18);
    root1->next = new ListNode(44);
    root1->next->next = new ListNode(-1);
    root1->next->next->next = new ListNode(-8);
    root1->next->next->next->next = new ListNode(-9);
    root1->next->next->next->next->next = new ListNode(22);
    ListNode* newRoot = mySol.mergeInBetween(root, 2, 5, root1);
    while (newRoot) {
        cout << newRoot->val << " ";
        newRoot = newRoot->next;
    }
    cout << endl;
    return 0;
}
