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
public:
    vector<vector<int>> ans;
    void traverse(TreeNode* cur,int level){
        if(cur == nullptr) return;
        if(level == ans.size()) ans.push_back(vector<int>());
        ans[level].push_back(cur->val);
        traverse(cur->left,level+1);
        traverse(cur->right,level+1);
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root,0);
        for(int i=0; i<ans.size(); i++){
            if(i%2 == 1) reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};