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
    vector<TreeNode*> rec_generate(int start, int end){
        vector<TreeNode*> sub_trees;
        if(start > end){
            sub_trees.push_back(nullptr);
            return sub_trees;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left_subtrees = rec_generate(start,i-1);
            vector<TreeNode*> right_subtrees = rec_generate(i+1,end);

            // add root to different pairs of left & right subtrees
            for(int j=0; j<left_subtrees.size(); j++){
                for(int k=0; k<right_subtrees.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left_subtrees[j];
                    root->right = right_subtrees[k];
                    sub_trees.push_back(root);
                }
            }
        }
        return sub_trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        return rec_generate(1,n);
    }
};