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
    TreeNode* deleteNode(TreeNode* cur, int key) {
        if(cur){
            if(cur -> val < key ) cur -> right = deleteNode(cur->right, key);
            else if(cur -> val > key ) cur -> left = deleteNode(cur->left, key);
            else{
                if(cur -> left == nullptr && cur -> right == nullptr) return nullptr; 
                else if(cur -> right == nullptr) return cur -> left;
                else if(cur -> left == nullptr) return cur -> right;
                else{
                    TreeNode* tmp_node = cur -> left;
                    while(tmp_node -> right != nullptr) tmp_node = tmp_node -> right;
                    cur -> val = tmp_node -> val;
                    cur -> left = deleteNode(cur->left, tmp_node -> val);
                }
            }
        }
        return cur;
    }
};