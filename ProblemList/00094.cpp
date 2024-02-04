#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector <int> ans;
    void rec_traverse(TreeNode* cur){
        if(cur == nullptr){
            return;
        }
        rec_traverse(cur->left);
        ans.push_back(cur->val);
        rec_traverse(cur->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        rec_traverse(root);
        return ans;
    }
};
