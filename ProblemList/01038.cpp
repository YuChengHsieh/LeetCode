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
    int traverse(TreeNode* cur, int val){
        if(cur == nullptr) return val;
        int right = traverse(cur -> right, val);
        cur -> val += right;
        int left = traverse(cur -> left, cur -> val);
        return left;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root,0);
        return root;
    }
};

class Solution {
public:
    int prefix = 0;
    TreeNode* bstToGst(TreeNode* cur) {
        if(cur != nullptr){
            bstToGst(cur -> right);
            prefix += cur -> val;
            cur -> val = prefix;
            bstToGst(cur -> left);
        }
        return cur;
    }
};