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
    int ans = 0;
    void traverse(TreeNode* cur, int largest_val){
        if(cur == nullptr) return;
        if(cur -> val >= largest_val){
            ans += 1;
            largest_val = cur->val;
        }
        traverse(cur->left, largest_val);
        traverse(cur->right, largest_val);
        return;
    }
public:
    int goodNodes(TreeNode* root) {
        traverse(root,root->val);
        return ans;
    }
};