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
    int maxDepth_2(TreeNode* cur, int depth){
        if(cur == nullptr) return depth-1;
        return max(maxDepth_2(cur->left,depth+1),maxDepth_2(cur->right,depth+1));
    }
    int maxDepth(TreeNode* root) {
        return maxDepth_2(root,1);
    }
};