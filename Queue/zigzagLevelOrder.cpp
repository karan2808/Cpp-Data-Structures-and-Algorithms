#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode () {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode (int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
    TreeNode (int val, TreeNode* left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

class Solution {
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        // use a queue for bfs
        queue<TreeNode*> Queue;
        // push the roor onto queue
        Queue.push(root);
        // keep a flag to indicate traversal direction
        bool flag = true;
        while (!Queue.empty()) {
            // get the queue size
            int sz = Queue.size();
            // store the current level
            vector<int> currentLevel;
            for (int i = 0; i < sz; i++) {
                // the front of the queue is the first node in level order traversal
                TreeNode* curr = Queue.front();
                Queue.pop();
                currentLevel.push_back(curr->val);
                // push the left and right nodes of the current node, this will be the second layer 
                if (curr->left) Queue.push(curr->left);
                if (curr->right) Queue.push(curr->right);
            }
            // if flag is set, reverse the order of elements
            if (flag) {
                reverse(currentLevel.begin(), currentLevel.end());
                result.push_back(currentLevel);
                flag = false;
            } else {
                result.push_back(currentLevel);
                flag = true;
            }
        }
        return result;
    }
};

void printVec(vector<vector<int>> levels)
{
    for (vector<int> level: levels) {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    TreeNode *root = new TreeNode(5, new TreeNode(3), new TreeNode(6));
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->right->right = new TreeNode(8, new TreeNode(7), new TreeNode(8));
    root->right->right->left->left = new TreeNode(6);
    root->right->right->left->right = new TreeNode(8);
    Solution mySol;
    vector<vector<int>> result = mySol.zigzagLevelOrder(root);
    printVec(result);
    return 0;
};