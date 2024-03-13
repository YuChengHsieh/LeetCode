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
    TreeNode* traverse(TreeNode* cur){
        if(cur == nullptr) return nullptr;
        TreeNode* left = traverse(cur -> left);
        TreeNode* right = traverse(cur -> right);
        TreeNode* tmp = cur -> right;
        cur -> left = nullptr;
        if(left != nullptr){
            cur -> right = left;
            while(left -> right != nullptr){
                left = left -> right;
            }
            if(tmp != nullptr) left -> right = tmp;
        } 
        return cur;
    }
public:
    void flatten(TreeNode* root) {
        auto _ = traverse(root);
    }
};