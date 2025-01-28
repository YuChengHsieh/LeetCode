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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// space complexity o(1)
class Solution {
private:
    void traverse(int level, TreeNode* left, TreeNode* right){
        if(left == nullptr) return;
        if(level%2){
            int tmp_val = left -> val;
            left -> val = right -> val;
            right -> val = tmp_val;
        }
        traverse(level+1, left->left, right->right);
        traverse(level+1, left->right, right->left);
        return;
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverse(1,root -> left, root -> right);
        return root;
    }
};

// space complexity o(n/2) ~= o(n)
class Solution {
private:
    vector<vector<TreeNode*>> vec;
    void traverse(int level, TreeNode* cur){
        if(cur == nullptr) return;
        if(level%2){
            if(level/2 == vec.size()) vec.push_back({});
            vec[level/2].push_back(cur);
        }
        traverse(level+1, cur->left);
        traverse(level+1, cur->right);
        return;
    }

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverse(0,root);

        for(int i=0; i<vec.size(); i++){
            int n = 1 << (2*i + 1);
            for(int j=0; j<n/2; j++){
                int tmp_val = vec[i][n-j-1] -> val;
                vec[i][n-j-1] -> val = vec[i][j] -> val;
                vec[i][j] -> val = tmp_val;
            }
        }
        return root;
    }
}; 