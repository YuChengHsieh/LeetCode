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
    private:
        TreeNode* ans;
        int cnt;
        int traverse(TreeNode* cur, int depth){
            if(cur == nullptr) return 0;
            int sum = cur -> left == nullptr && cur -> right == nullptr && depth == 1? 1 :
                traverse(cur -> left, depth-1) + traverse(cur -> right, depth-1);
            if(cnt == sum){
                ans = cur;
                cnt = -1;
            }
            return sum;
        }
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            // level-order traversal
            int depth = 0;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int sz = q.size();
                cnt = sz;
                for(int i=0; i<sz; i++){
                    auto cur = q.front();
                    q.pop();
                    if(cur -> left) q.push(cur -> left);
                    if(cur -> right) q.push(cur -> right);
                }
                depth ++;
            }
    
            traverse(root,depth);
            return ans == nullptr ? root: ans;
        }
    };