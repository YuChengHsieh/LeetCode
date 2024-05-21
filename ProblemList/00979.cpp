#include <cmath>
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
    int traverse(TreeNode* cur, TreeNode* parent){
        if(cur == nullptr) return 0;
        int left = traverse(cur -> left, cur);
        int right = traverse(cur -> right, cur);
        if(parent) parent -> val += cur -> val - 1;
        return left + right + abs(cur -> val - 1);
    }
public:
    int distributeCoins(TreeNode* root) {
        return traverse(root, nullptr);
    }
};