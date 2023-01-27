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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr and q == nullptr){
            return true;
        }else if((p != nullptr and q == nullptr) or (p == nullptr and q != nullptr)){
            return false;
        }else{
            bool ret_left = isSameTree(p->left,q->left);
            bool ret_right = isSameTree(p->right,q->right);
            return ret_left and ret_right and p->val == q->val;
        }
    }
};