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
    int ans;
    int left;
    void inorder(TreeNode* cur){
        if(cur == nullptr) return;
        inorder(cur->left);
        left -= 1;
        if(left == 0){
            left = INT_MAX;
            ans = cur -> val;
        }
        if(left == INT_MAX) return;
        inorder(cur->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        left = k;
        inorder(root);
        return ans;
    }
};