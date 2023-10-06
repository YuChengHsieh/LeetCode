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
    int minimum_depth = 1000000;
    void min(TreeNode* cur,int depth){
        if(cur->left == nullptr and cur->right == nullptr and depth < minimum_depth){
            minimum_depth = depth;
            return;
        }
        if(cur->left != nullptr) min(cur->left,depth+1);
        if(cur->right != nullptr) min(cur->right,depth+1);
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        min(root,1);
        return minimum_depth;
    }
};