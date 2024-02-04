#include <iostream>
#include <vector>
using namespace std;

// quite similar to 100.cpp, just traverse another way(p traverse left first, q traverse right first)

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
    bool traverse(TreeNode* left, TreeNode* right){
        if(left == nullptr and right == nullptr){
            return true;
        }else if((left == nullptr and right != nullptr) or (left != nullptr and right== nullptr)){
            return false;
        }
        else{
            bool ret1 = traverse(left->left,right->right);
            bool ret2 = traverse(left->right,right->left);
            return ret1 and ret2 and left->val == right->val;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return traverse(root,root);
    }
};