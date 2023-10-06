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
    void mySum(TreeNode* cur, int cur_sum, vector<int> record, int target){
        record.push_back(cur->val);
        cur_sum += cur->val;
        if(cur->left == nullptr and cur->right == nullptr){
            if(cur_sum == target) ans.push_back(record);
            return;
        }
        if(cur->left != nullptr) mySum(cur->left,cur_sum,record,target);
        if(cur->right != nullptr) mySum(cur->right,cur_sum,record,target);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root != nullptr) mySum(root,0,vector<int> (), targetSum);
        return ans;
    }
};