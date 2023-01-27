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
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    void inorder_traversal(TreeNode* cur){
        if(cur == nullptr){
            return ;
        }
        inorder_traversal(cur->left);
        // try to find first value and second value to swap (think as an array)
        if(prev != nullptr and prev->val > cur->val){
            if(first == nullptr){
                first = prev;
            }
            second = cur;
        }
        prev = cur;
        inorder_traversal(cur->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        inorder_traversal(root);
        int tmp_val = first->val;
        first->val = second->val;
        second->val = tmp_val;
    }
};