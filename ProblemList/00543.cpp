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

// pair return function 
class Solution {
private:
    pair<int,int> traverse(TreeNode* cur){
        if(cur == nullptr) return {0,0};
        auto left_val = traverse(cur -> left), right_val = traverse(cur -> right);
        return {max(max(left_val.first, right_val.first),left_val.second+right_val.second),max(left_val.second,right_val.second)+1};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return traverse(root).first;
    }
};

class Solution {
private:
    int a = INT_MAX;
    int max_val = 0;
    int traverse(TreeNode* cur){
        if(cur == nullptr) return 0;
        int left_val = traverse(cur -> left), right_val = traverse(cur -> right);
        max_val = max(max_val, left_val+right_val);
        return max(left_val,right_val)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto _ = traverse(root);
        return max_val;
    }
};