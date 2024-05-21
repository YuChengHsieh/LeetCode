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
    int ans = 0;
    int traverse(TreeNode* cur){
        if(cur == nullptr) return 2;
        int left = traverse(cur -> left), right = traverse(cur -> right);
        
        if(left == 0 || right == 0){
            ans ++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        return traverse(root) == 0 ? ans+1 : ans;
    }
};

class Solution {
private: 
    int ans = 0;
    bool traverse(TreeNode* cur, TreeNode* parent){
        if(cur == nullptr) return true;
        bool left = traverse(cur -> left, cur);
        bool right = traverse(cur -> right, cur);
        
        if(cur -> val == 1 && left && right) return true;
        if(left && right) return false;
        ans += 1;
        if(parent) parent -> val = 1;
        return true;
    }

public:
    int minCameraCover(TreeNode* root) {
        if(!traverse(root, nullptr)) ans += 1;
        return ans;
    }
};