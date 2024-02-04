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
    // check whether subtrees appears before or not
    unordered_map<string,int> hash_map;
    vector<TreeNode*> ans;
    string traversal(TreeNode* root){
        if(root == nullptr) return "#"; // # represent null ptr 
        string left = traversal(root->left);
        string right = traversal(root->right);
        string new_s = left+'_'+right+'_'+to_string(root->val);
        if(hash_map[new_s] == 1) ans.push_back(root);
        hash_map[new_s] += 1;
        return new_s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);
        return ans;
    }
};