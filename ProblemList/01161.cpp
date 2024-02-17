#include <queue>
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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int max_sum = INT_MIN, max_level = 0, level = 1;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                if(cur -> left != nullptr) q.push(cur -> left);
                if(cur -> right != nullptr) q.push(cur -> right);
                q.pop();
                sum += cur -> val;
            }
            if(sum > max_sum){
                max_sum = sum;
                max_level = level;
            }
            level += 1;
        }
        return max_level;
    }
};