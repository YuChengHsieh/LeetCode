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
    void traverse(TreeNode* cur, string s){
        
        char add_ch = char(cur -> val + 'a');
        if(cur -> left == nullptr && cur -> right == nullptr){
            ans = ans > add_ch + s ? add_ch + s : ans;
            return;
        }

        if(cur -> left != nullptr) traverse(cur -> left, add_ch + s);
        if(cur -> right != nullptr) traverse(cur -> right, add_ch + s);
        return ;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        ans = string(10000,'z');
        traverse(root,string());
        return ans;
    }
};