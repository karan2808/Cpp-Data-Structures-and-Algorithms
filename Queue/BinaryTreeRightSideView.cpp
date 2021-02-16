#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition of a binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        // use a queue for bfs
        queue<TreeNode*> Q;
        Q.push(root);
        // while queue is not empty keep traversing level by level
        while (!Q.empty()) {
            int sz = Q.size();
            int count = 0;
            for (int i = 0; i < sz; i++) {
                TreeNode* temp = Q.front();
                Q.pop();
                // push the first element in result
                if (count == 0) {
                    result.push_back(temp->val);
                }
                if (temp->right) {
                    Q.push(temp->right);
                }
                if (temp->left) {
                    Q.push(temp->left);
                }
                count++;
            }
        }
        return result;
    }
};

void printVec(vector<int> nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->right->left = new TreeNode(4);
    root->right->left->right = new TreeNode(7);
    Solution mySol;
    cout << "The right side view of the given tree is ";
    printVec(mySol.rightSideView(root));
    return 0;
}