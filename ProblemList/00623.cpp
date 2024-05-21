#include <queue>
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // BFS
        if(depth == 1){
            TreeNode* new_root = new TreeNode(val);
            new_root -> left = root;
            return new_root;
        }
        queue<TreeNode*> q;
        q.push(root);
        for(int i=0; i<depth-2; i++){
            int sz = q.size();
            for(int j=0; j<sz; j++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur -> left != nullptr) q.push(cur -> left);
                if(cur -> right != nullptr) q.push(cur -> right);
            }
        }

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            TreeNode* newnl = new TreeNode(val);
            TreeNode* tmpl = cur -> left;
            cur -> left = newnl;
            newnl -> left = tmpl;
        
            TreeNode* newnr = new TreeNode(val);
            TreeNode* tmpr = cur -> right;
            cur -> right = newnr;
            newnr -> right = tmpr;
            
        }
        return root;
    }
};