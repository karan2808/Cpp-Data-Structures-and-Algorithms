#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        if (!head)
            return {};
        // store the result in a vector
        vector<int> result{};
        // index value pair
        stack<pair<int, int>> stk;
        int curIdx = 0;
        while (head)
        {   
            // while there are elements on stack and top value is less than current head value
            while (!stk.empty() && stk.top().second < head->val)
            {
                // at the index given by stack top value, put the head value
                result[stk.top().first] = head->val;
                // remove the top element from the stack, since we have found the next element for it
                stk.pop();
            }
            // push the index value pair 
            stk.push({curIdx++, head->val});
            // push 0 to populate the vector, in case a next greater element is not found, we set the value to 0
            result.push_back(0);
            // go to next node
            head = head->next;
        }
        return result;
    }
};

void printVec(vector<int> values)
{
    for (int val : values)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    ListNode *root = new ListNode(2);
    root->next = new ListNode(1);
    root->next->next = new ListNode(5);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next = new ListNode(2);
    root->next->next->next->next->next->next = new ListNode(6);
    Solution mySol;
    vector<int> values;
    values = mySol.nextLargerNodes(root);
    cout << "The next larger nodes for each node in the linked list is: ";
    printVec(values);
    return 0;
}