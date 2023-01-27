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
    int cur_sum = 0;
    int target_sum;
    bool find = false;
    void myHasPathSum(TreeNode* cur){
        if(cur->left == nullptr and cur->right == nullptr and cur_sum == target_sum){
            find = true;
            return;
        }else{
            if(cur->left != nullptr){
                cur_sum += cur->left->val;
                myHasPathSum(cur->left);
                cur_sum -= cur->left->val;
                if(find) return;
            }
            if(cur->right != nullptr){ 
                cur_sum += cur->right->val;
                myHasPathSum(cur->right);
                cur_sum -= cur->right->val;
                if(find) return;
            }
        }
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        cur_sum = root->val;
        target_sum = targetSum;
        myHasPathSum(root);
        return find;
    }

};