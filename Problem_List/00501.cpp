#include <unordered_map>
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
    unordered_map<int,int> cnt;
    int max;
    void rec(TreeNode* cur){
        if(cur == nullptr) return;
        cnt[cur->val] += 1;
        if(cnt[cur->val] > max) max = cnt[cur->val];
        rec(cur->left);
        rec(cur->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        max = 0;
        rec(root);
        for(auto &i: cnt){
            if(i.second == max) ans.push_back(i.first);
        }
        return ans;
    }
};