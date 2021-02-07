#include <iostream>
#include <vector>

using namespace std;

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
    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        while (l1 && l2)
        {
            // check for the smaller valued node and add it to current linked list
            if (l1->val < l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1)
            head->next = l1;
        if (l2)
            head->next = l2;
        return temp->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int interval = 1;
        int lenList = lists.size();
        if (lenList == 0)
        {
            return NULL;
        }
        // iteratively keep merging the adjacent list nodes
        while (interval < lenList)
        {
            for (int i = 0; i < lenList - interval; i += 2 * interval)
            {
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
};

int main() {
    Solution mySol;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(4);
    root->next->next = new ListNode(5);
    ListNode *root2 = new ListNode(1);
    root2->next = new ListNode(3);
    root2->next = new ListNode(4);
    ListNode  *root3 = new ListNode(2);
    root3->next = new ListNode(6);
    vector<ListNode*> l;
    l.push_back(root);
    l.push_back(root2);
    l.push_back(root3);
    ListNode *finalRoot = mySol.mergeKLists(l);
    while (finalRoot) {
        cout << finalRoot->val << " " << endl;
        finalRoot = finalRoot->next;
    }
    return 0;
}