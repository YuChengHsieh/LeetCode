#include <unordered_map>
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
    unordered_map<long int, int> cnt_map;
    int traverse(TreeNode* cur, int targetSum, long long cur_val){
        if(cur == nullptr) return 0;
        cur_val += cur -> val;
        
        int cnt = cnt_map[cur_val-targetSum];
        cnt_map[cur_val] += 1;
        cnt += traverse(cur->left, targetSum,cur_val);
        cnt += traverse(cur->right, targetSum,cur_val);
        cnt_map[cur_val] -= 1;
        return cnt;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        cnt_map[0] = 1;
        return traverse(root,targetSum,0);
    }
};