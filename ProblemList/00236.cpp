#include <queue>
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // BFS
        queue<pair<TreeNode*,int>> que;
        que.push(make_pair(root,1));
        bool p_appear = false, q_appear = false; 
        unordered_map<TreeNode*,TreeNode*> parent_map;

        int depth_p,depth_q;
        while(!que.empty()){
            auto ret = que.front();
            que.pop();
            TreeNode* cur = ret.first; int depth = ret.second;
            if(cur == p){
                p_appear = true;
                depth_p = depth;
            } 
            else if(cur == q){
                q_appear = true;
                depth_q = depth;
            } 
            if(p_appear && q_appear) break;

            if(cur -> left != nullptr){
                parent_map[cur->left] = cur;
                que.push(make_pair(cur->left,depth+1));
            }
            if(cur -> right != nullptr){
                parent_map[cur->right] = cur;
                que.push(make_pair(cur->right,depth+1));
            }
        }

        TreeNode* upper_node, *lower_node;
        int upper_depth, lower_depth;
        if(depth_q > depth_p){
            upper_node = p;
            upper_depth = depth_p;
            lower_node = q;
            lower_depth = depth_q;
        }else{
            upper_node = q;
            upper_depth = depth_q;
            lower_node = p;
            lower_depth = depth_p;
        }
        while(lower_depth != upper_depth){
            lower_depth -= 1;
            lower_node = parent_map[lower_node];
        }

        while(upper_node != lower_node){
            upper_node = parent_map[upper_node];
            lower_node = parent_map[lower_node];
        }
        return upper_node;
    }
};