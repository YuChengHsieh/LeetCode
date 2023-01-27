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
    void invert(TreeNode* cur){
        if(cur->left != nullptr) invert(cur->left);
        if(cur->right != nullptr) invert(cur->right);
        cout << cur->val << ' ';
        TreeNode* tmp = cur->right;
        cur->right = cur->left;
        cur->left = tmp;
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root != nullptr){
            invert(root);
        }
        return root;
    }
};