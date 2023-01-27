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
// Use binary search way to insert
class Solution {
public:
    TreeNode* construct_tree(vector<int>& nums, int start, int end){
        if(start>end){
            return nullptr;
        }
        int mid = start+ (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = construct_tree(nums,start,mid-1);
        root->right = construct_tree(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct_tree(nums,0,nums.size()-1);
    }
};