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
    int ans;
    pair<int,int> traverse(TreeNode* cur){
        if(cur == nullptr) return make_pair(INT_MIN,INT_MAX);
        auto ret_left =  traverse(cur->left);
        auto ret_right =  traverse(cur->right);
        int max_val = max(cur->val, max(ret_left.first,ret_right.first));
        int min_val = min(cur->val, min(ret_left.second,ret_right.second));
        if(abs(cur->val - max_val) > ans) ans = abs(cur->val - max_val);
        if(abs(cur->val - min_val) > ans) ans = abs(cur->val - min_val);
        // cout << cur -> val << ' ' << max_val << ' ' << min_val << endl;
        return make_pair(max_val,min_val);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        auto tmp = traverse(root);
        return ans;
    }
};