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
    int val = 0;
    void traverse(TreeNode* cur, bool left){
        if(cur -> left == nullptr && cur -> right == nullptr){ if(left) val += cur -> val; }
        else{
            if(cur -> left != nullptr) traverse(cur->left, true);
            if(cur -> right != nullptr) traverse(cur->right, false);
        }
        return;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root -> left != nullptr) traverse(root->left, true);
        if(root -> right != nullptr) traverse(root->right, false);
        return val;
    }
};