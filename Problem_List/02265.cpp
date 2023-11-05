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
    int cnt = 0;
    pair<int,int>rec(TreeNode* cur){
        if (cur == nullptr) return make_pair(0,0);
        auto [left_sum, left_cnt] = rec(cur->left);
        auto [right_sum, right_cnt] = rec(cur->right);
        int cur_sum = left_sum+right_sum+cur->val;
        int cur_cnt = left_cnt+right_cnt+1;
        if( cur_sum/cur_cnt == cur->val) cnt += 1;
        return make_pair(cur_sum,cur_cnt);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> tmp = rec(root);
        return cnt;
    }
};