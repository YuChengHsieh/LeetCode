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
    bool balance=true;
    int my_isBalanced(TreeNode* cur,int height){
        if(cur==nullptr) return height;
        int left_height = my_isBalanced(cur->left,height+1);
        int right_height = my_isBalanced(cur->right,height+1);
        // cout << cur->val << left_height << right_height << endl;
        if(abs(left_height-right_height)>1) balance=false;
        return max(left_height,right_height);
    }
    bool isBalanced(TreeNode* root) {
        my_isBalanced(root,0);
        return balance;
    }
};