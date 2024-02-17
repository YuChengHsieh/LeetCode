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
    TreeNode* ans = nullptr;
    int target;
    bool find = false;

    void traverse(TreeNode* cur){
        if(cur == nullptr) return;
        if(cur -> val == target){
            ans = cur;
            find = true;
        }
        if(!find) traverse(cur -> left);
        if(!find) traverse(cur -> right);
        return;
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        target = val;
        traverse(root);
        return ans;
    }
};