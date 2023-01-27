#include <iostream>
#include <vector>
#include<queue>
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
    // BFS
    queue<TreeNode*> q;
    bool isCompleteTree(TreeNode* root) {
        q.push(root);
        bool null_ = false;
        while(!q.empty()){
            if(null_ and q.front() != nullptr) return false;
            if(q.front() == nullptr) null_ = true; 
            else{
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        return true;
    }
};