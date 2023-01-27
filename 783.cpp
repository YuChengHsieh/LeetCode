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
    int min_dis = 10000000;
    int prev = INT_MAX;
    void traverse(TreeNode* cur){
        if(cur == nullptr) return;
        traverse(cur->left);
        if(abs(cur->val - prev) < min_dis) min_dis = abs(cur->val - prev);
        prev = cur->val;
        traverse(cur->right);

        return;
    }
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        return min_dis;
    }
};