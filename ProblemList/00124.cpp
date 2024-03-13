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
    pair<int,int> traverse(TreeNode* cur){
        if(cur == nullptr) return {INT_MIN,0};
        auto [left_sum, left_val] = traverse(cur -> left);
        auto [right_sum, right_val] = traverse(cur -> right); 
        return {max(max(left_sum,right_sum),cur -> val + left_val + right_val), max(max(left_val,right_val)+ cur -> val, 0)};

    }
public:
    int maxPathSum(TreeNode* root) {
        return traverse(root).first;
    }
};