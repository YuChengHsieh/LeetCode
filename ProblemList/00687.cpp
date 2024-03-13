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
    pair<int, int> traverse(TreeNode* cur){
        if(cur == nullptr) return {0,0};
        int cur_max = 0, cur_depth = 1;
        auto [left_max, left_depth] = traverse(cur -> left);
        auto [right_max, right_depth] = traverse(cur -> right);
        if(left_depth != 0){
            if(cur -> val == cur -> left -> val){
                cur_max += left_depth;
                cur_depth = max(cur_depth,left_depth+1);
            } 
        }
        if(right_depth != 0){
            if(cur -> val == cur -> right -> val){
                cur_max += right_depth;
                cur_depth = max(cur_depth,right_depth+1);
            } 
        }
        return {max(cur_max,max(right_max,left_max)),cur_depth};
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        return traverse(root).first;
    }
};