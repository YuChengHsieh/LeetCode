#include <string>
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
    string ans;
    void preorder(TreeNode* cur){
        if(cur == nullptr) return;
        // leaf node
        ans += to_string(cur->val);
        if(cur->left == nullptr && cur->right == nullptr) return;
        
        ans += '(';
        preorder(cur -> left);
        ans += ')';
        if(cur->right != nullptr){
            ans += '(';
            preorder(cur -> right);
            ans += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        preorder(root);
        return ans;
    }
};