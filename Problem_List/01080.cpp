#include <iostream>
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
    bool traverse(TreeNode*cur, int sum, int limit){
        sum += cur->val;
        bool left = false, right = false;
        int cnt = 0;
        if(cur->left != nullptr) left = traverse(cur->left, sum, limit);
        else cnt += 1;
        if(cur->right != nullptr) right = traverse(cur->right, sum, limit);
        else cnt += 1;
        
        // leaf node
        if(cnt == 2) return sum >= limit;
        if(!left){
            TreeNode* tmp = cur->left;
            cur->left = nullptr;
            delete tmp;
        }
        if(!right){
            TreeNode* tmp = cur->right;
            cur->right = nullptr;
            delete tmp;
        }
        return left || right;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool final = traverse(root,0,limit);
        return final? root: nullptr;
    }
};

class Solution {
private:
    bool traverse(TreeNode*cur, int sum, int limit){
        if(cur == nullptr) return false;
        sum += cur->val;
        if(cur->left == nullptr && cur->right == nullptr) return sum >= limit;
        bool left = traverse(cur->left, sum, limit);
        bool right = traverse(cur->right, sum, limit);
        
        // leaf node
        if(!left){
            TreeNode* tmp = cur->left;
            cur->left = nullptr;
            delete tmp;
        }
        if(!right){
            TreeNode* tmp = cur->right;
            cur->right = nullptr;
            delete tmp;
        }
        return left || right;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool final = traverse(root,0,limit);
        return final? root: nullptr;
    }
};