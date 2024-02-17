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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr) q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto cur = q.front();
                q.pop();
                if(cur -> left != nullptr) q.push(cur -> left);
                if(cur -> right != nullptr) q.push(cur -> right);
                if(i == size-1) ans.push_back(cur->val);
            }
        }
        return ans;   
    }
};