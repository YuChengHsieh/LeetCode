#include <iostream>
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
private:
    int traverse(TreeNode* cur, bool left, int cnt){
        if(cur == nullptr) return cnt;
        return max(traverse(cur->left,true, left ? 1 : cnt+1),traverse(cur->right,false, left ? cnt+1 : 1));
    }
public:
    int longestZigZag(TreeNode* root) {
        return max(traverse(root,true,0),traverse(root,false,0))-1;
    }
};