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

// similar to 105.cpp
class Solution {
public:
    unordered_map<int,int> inorder_map;
    vector<int> postorder_vec;
    int p_idx;
    TreeNode* my_buildTree(int p_start, int p_end){
        // end condition
        if(p_start > p_end) return nullptr;
        int in_pos = inorder_map[postorder_vec[p_idx]];
        TreeNode* root = new TreeNode(postorder_vec[p_idx]);
        p_idx -= 1;
        // right first
        root->right = my_buildTree(in_pos+1,p_end);
        root->left = my_buildTree(p_start,in_pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_vec = postorder;
        // from back to start 
        p_idx = postorder.size()-1;
        for(int i=0; i<inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        return my_buildTree(0,postorder.size()-1);
    }
};