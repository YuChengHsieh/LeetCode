#include <iostream>
#include <vector>
#include<unordered_map>
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
    vector<int> ans;
    void traversal(TreeNode* cur){
        if(cur == nullptr){
            return;
        }
        ans.push_back(cur->val);
        preorderTraversal(cur->left);
        preorderTraversal(cur->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        traversal(root);
        return ans;
    }
};