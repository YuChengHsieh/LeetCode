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
    vector<int> ans;
    void rec(TreeNode* cur, int layer){
        if(cur == nullptr) return;
        if(layer >= ans.size()) ans.push_back(cur->val);
        else ans[layer] = max(ans[layer],cur->val);
        rec(cur->left, layer+1);
        rec(cur->right, layer+1);
        return;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        rec(root,0);
        return ans;
    }
};