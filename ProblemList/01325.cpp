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
    TreeNode* removeLeafNodes(TreeNode* cur, int target) {
        if(cur -> left != nullptr) cur -> left = removeLeafNodes(cur -> left, target);
        if(cur -> right != nullptr) cur -> right = removeLeafNodes(cur -> right, target);
        return (cur -> left == nullptr && cur -> right == nullptr && cur -> val == target) ? nullptr : cur;
        
    }
};

class Solution {
private:
    bool traverse(TreeNode* cur, int target){
        if(cur == nullptr) return true;
        bool left = traverse(cur -> left, target);
        bool right = traverse(cur -> right, target);
        if(left) cur -> left = nullptr;
        if(right) cur -> right = nullptr;
        return (left && right && cur -> val == target) ? true : false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool ret = traverse(root, target);
        return ret ? nullptr : root;
    }
};