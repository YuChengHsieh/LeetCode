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
    vector<vector<int>> ans;
    void traversal(TreeNode* cur, int level){
        if(cur == nullptr){
            return; 
        }
        if(level >= ans.size()){
            ans.push_back(vector<int>{});
        }
        ans[level].push_back(cur->val);
        traversal(cur->left,level+1);
        traversal(cur->right,level+1);
        return;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        traversal(root,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};