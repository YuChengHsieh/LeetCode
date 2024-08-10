#include <map>
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
    TreeNode* traverse(int val, map<pair<int,bool>,int>& mp){
        TreeNode* cur = new TreeNode(val);
        cur -> left = mp.count({val,true}) ? traverse(mp[{val,true}],mp) : nullptr;
        cur -> right = mp.count({val,false}) ? traverse(mp[{val,false}],mp) : nullptr;
        return cur;
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<pair<int,bool>,int> mp;
        map<int,int> parent;
        for(int i=0; i<descriptions.size(); i++){
            mp[{descriptions[i][0],descriptions[i][2]}] = descriptions[i][1];
            parent[descriptions[i][1]] = descriptions[i][0];
        }

        int root_node = descriptions[0][0];
        while(parent.count(root_node)){
            root_node = parent[root_node];
        }

        TreeNode* root = traverse(root_node,mp);
        return root;
    }
};