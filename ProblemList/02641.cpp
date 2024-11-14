#include <vector>
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
    vector<int> level;
    void traverse(TreeNode* cur, int l){
        if(cur == nullptr) return;
        level[l] += cur -> val;
        traverse(cur -> left, l+1);
        traverse(cur -> right, l+1);
        return;
    }

    int traverse2(TreeNode* cur, int l){
        if(cur == nullptr) return 0;
        int val = traverse2(cur -> left, l+1) + traverse2(cur -> right, l+1);
        if(cur -> left != nullptr) cur -> left -> val = level[l+1] - val; 
        if(cur -> right != nullptr) cur -> right -> val = level[l+1] - val; 
        return cur -> val;
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        level.resize(100000,0);
        traverse(root,0);
        auto _ = traverse2(root,0);
        root -> val = 0;
        return root;
    }
};