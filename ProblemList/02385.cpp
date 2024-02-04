#include <unordered_map>
#include <unordered_set>
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
private:
    unordered_map<TreeNode*,TreeNode*> dict;
    TreeNode* start_node;
    unordered_set<TreeNode*> visited;
    void traverse(TreeNode*cur, int start){
        if(cur == nullptr) return;
        if(cur -> right != nullptr) dict[cur -> right] = cur;
        if(cur -> left != nullptr) dict[cur -> left] = cur;
        if(cur->val == start) start_node = cur;
        traverse(cur->left,start);
        traverse(cur->right,start);
        return;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        dict[root] = nullptr;
        traverse(root,start);
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(start_node,0));
        visited.insert(start_node);
        int mins = -1;
        while(!q.empty()){
            auto out = q.front();
            q.pop();
            TreeNode* cur = out.first;
            mins = out.second;
            if(cur->left != nullptr && !visited.count(cur->left)){
                visited.insert(cur->left);
                q.push(make_pair(cur->left,mins+1));
            }
            if(cur->right != nullptr && !visited.count(cur->right)){
                visited.insert(cur->right);
                q.push(make_pair(cur->right,mins+1));
            }
            if(dict[cur] != nullptr && !visited.count(dict[cur])){
                visited.insert(dict[cur]);
                q.push(make_pair(dict[cur],mins+1));
            }
        }
        return mins;
    }
};