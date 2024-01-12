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
private:
    int ans = 0;
    void traverse(TreeNode* cur, int low, int high){
        if(cur == nullptr) return;
        if(cur -> val >= low && cur -> val <= high){
            ans += cur ->val;
            traverse(cur->left,low,high);
            traverse(cur->right,low,high);
        }else if(cur ->val < low) traverse(cur->right,low,high);
        else traverse(cur->left,low,high);
        return;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        traverse(root,low,high);
        return ans;
    }
};